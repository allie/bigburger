#include <nusys.h>
#include <math.h>
#include "common.h"
#include "game.h"
#include "graphics.h"
#include "camera.h"
#include "object.h"
#include "plane.h"
#include "collision.h"
#include "brick.h"
#include "paddle.h"
#include "ball.h"
#include "level.h"

#include "models/stage.h"
#include "models/paddle.h"
#include "models/ball.h"
#include "models/brick.h"

#include "levels/stage0.h"

#define ROT_VELOCITY 1.0f
#define CAMERA_MOVE_SCALE 0.25
#define NUM_LEVELS 1

extern NUContData controller[1];

static Object stage;
static Object ball;

static Paddle paddle;

static LevelData* level_data[] = {
  &stage0
};
static Level level;
static int current_level = 0;

static bool paused = TRUE;
static bool live = TRUE;

// Check each wall for collision with the ball.
// If there is a collision, move the ball to the collision point and return a new next_pos.
// In this event, collision needs to be checked again with the new next_pos, in case another
// collision occurs.
static bool handle_collision_walls(Vec3f next_pos, float dist, Vec3f* new_next_pos) {
  bool intersection = FALSE;
  Vec3f hit;
  float time, dist_after_hit;

  // Check up to 3 walls, depending on the direction the ball is travelling.
  // For instance, if the ball is travelling in the -X direction, there is no need to check
  // the right wall, as it's only possible for the ball to hit the left wall when travelling left.
  // Additionally, collision checking is skipped if the next position is still within level bounds.

  // Check left wall
  if (ball.vel.x < 0 &&
      next_pos.x <= level.bounds[SIDE_LEFT] + BALL_R &&
      moving_sphere_plane_intersect(BALL_R, ball.pos, next_pos, level.walls[SIDE_LEFT], &hit, &time)) {
    // Flip x direction
    ball.vel.x *= -1;
    intersection = TRUE;
  }
  // Check right wall
  if (ball.vel.x > 0 &&
      next_pos.x >= level.bounds[SIDE_RIGHT] - BALL_R &&
      !intersection &&
      moving_sphere_plane_intersect(BALL_R, ball.pos, next_pos, level.walls[SIDE_RIGHT], &hit, &time)) {
    // Flip x direction
    ball.vel.x *= -1;
    intersection = TRUE;
  }
  // Check top wall
  if (ball.vel.y > 0 &&
      next_pos.y >= level.bounds[SIDE_TOP] - BALL_R &&
      !intersection &&
      moving_sphere_plane_intersect(BALL_R, ball.pos, next_pos, level.walls[SIDE_TOP], &hit, &time)) {
    // Flip y direction
    ball.vel.y *= -1;
    intersection = TRUE;
  }
  // Check bottom wall
  if (ball.vel.y < 0 &&
      next_pos.y <= level.bounds[SIDE_BOTTOM] + BALL_R &&
      !intersection &&
      moving_sphere_plane_intersect(BALL_R, ball.pos, next_pos, level.walls[SIDE_BOTTOM], &hit, &time)) {
    // Flip y direction
    ball.vel.y *= -1;
    intersection = TRUE;
  }
  // Check back wall
  if (ball.vel.z < 0 &&
      next_pos.z <= level.bounds[SIDE_BACK] + BALL_R &&
      !intersection &&
      moving_sphere_plane_intersect(BALL_R, ball.pos, next_pos, level.walls[SIDE_BACK], &hit, &time)) {
    // Flip z direction
    ball.vel.z *= -1;
    intersection = TRUE;
  }
  // Check front wall
  if (ball.vel.z > 0 &&
      next_pos.z >= level.bounds[SIDE_FRONT] - BALL_R &&
      !intersection &&
      moving_sphere_plane_intersect(BALL_R, ball.pos, next_pos, level.walls[SIDE_FRONT], &hit, &time)) {
    // Check if the intersection point lies within the bounds of the paddle
    if (hit.x >= paddle.obj.pos.x - PADDLE_R - BALL_R && hit.x <= paddle.obj.pos.x + PADDLE_R + BALL_R &&
        hit.y >= paddle.obj.pos.y - PADDLE_R - BALL_R && hit.y <= paddle.obj.pos.y + PADDLE_R + BALL_R) {
      // If so, set the ball's direction to a brand new angle based on its position relative to the paddle's centre
      vec3f_set(
        ball.vel,
        -(hit.x - paddle.obj.pos.x) / PADDLE_R,
        -(hit.y - paddle.obj.pos.y) / PADDLE_R,
        -ball.vel.z
      );
      intersection = TRUE;
      // Calculate the hit animation rotation for this hit
      vec3f_set(
        paddle.hit_rot,
        (-(hit.y - paddle.obj.pos.y) / PADDLE_R) * PADDLE_HIT_ANIM_INTENSITY,
        ((hit.x - paddle.obj.pos.x) / PADDLE_R) * PADDLE_HIT_ANIM_INTENSITY,
        0
      );
      // If the A button is held on this frame, hold the ball
      if (controller[0].button & A_BUTTON) {
        paddle.held = TRUE;
        vec3f_set(
          paddle.hold_pos,
          hit.x - paddle.obj.pos.x,
          hit.y - paddle.obj.pos.y,
          hit.z - paddle.obj.pos.z
        );
        *new_next_pos = hit;
        return FALSE;
      }
      // Otherwise, start the hit animation
      else {
        paddle.hit_anim_timer = PADDLE_HIT_ANIM_DURATION;
      }
    }
    // If the ball doesn't hit the paddle but still intersects with the front wall, it's an out
    // For now, just respawn the ball
    else {
      live = FALSE;
      return FALSE;
    }
  }

  if (intersection) {
    // Move the ball to the intersection point
    ball.pos = hit;

    // Calculate the portion of the ball's movement that occurs after collision
    dist_after_hit = (1.0f - time) * dist;

    // Return the new next position so further testing can be done
    // between the point of intersection and the new next position
    vec3f_set(
      *new_next_pos,
      ball.pos.x + ball.vel.x * dist_after_hit,
      ball.pos.y + ball.vel.y * dist_after_hit,
      ball.pos.z + ball.vel.z * dist_after_hit
    );

    return TRUE;
  }

  // In the event that there is no collision at all, just return the original next_pos
  return FALSE;
}

// Check each brick for collision with the ball.
// If there is a collision, move the ball to the collision point and return a new next_pos.
// In this event, collision needs to be checked again with the new next_pos, in case another
// collision occurs.
static bool handle_collision_bricks(Vec3f next_pos, float dist, Vec3f* new_next_pos) {
  bool intersection = FALSE;
  Vec3f hit;
  float time, dist_after_hit;
  int i;

  for (i = 0; i < level.num_bricks; i++) {
    // Check the distance from the ball to the cube and see if it's worth doing collision detection
    float dist_to_brick = sqrtf(
      pow(level.bricks[i].obj.pos.x - ball.pos.x, 2) +
      pow(level.bricks[i].obj.pos.y - ball.pos.y, 2) +
      pow(level.bricks[i].obj.pos.z - ball.pos.z, 2)
    ) - BALL_R - BRICK_CR;

    if (dist_to_brick - dist >= 0) {
      continue;
    }

    // Don't check dead bricks
    if (level.bricks[i].lives == 0) {
      continue;
    }

    // Check three sides of the brick, depending on the ball's velocity
    // Check front face if travelling away from the camera
    if (ball.vel.z < 0 &&
        moving_sphere_quad_intersect(
          BALL_R, ball.pos, next_pos,
          level.bricks[i].front[0], level.bricks[i].front[1], level.bricks[i].front[2], level.bricks[i].front[3],
          &hit, &time
        )) {
      if (level.bricks[i].lives > 1) {
        ball.vel.z *= -1;
        intersection = TRUE;
      } else {
        // Don't report a hit if the brick dies
        brick_kill_contiguous(&level.bricks[i]);
        return FALSE;
      }
    }

    // Check left face if travelling right
    if (ball.vel.x > 0 &&
        !intersection &&
        moving_sphere_quad_intersect(
          BALL_R, ball.pos, next_pos,
          level.bricks[i].left[0], level.bricks[i].left[1], level.bricks[i].left[2], level.bricks[i].left[3],
          &hit, &time
        )) {
      if (level.bricks[i].lives > 1) {
        ball.vel.x *= -1;
        intersection = TRUE;
      } else {
        brick_kill_contiguous(&level.bricks[i]);
        return FALSE;
      }
    }

    // Check right face if travelling left
    if (ball.vel.x < 0 &&
        !intersection &&
        moving_sphere_quad_intersect(
          BALL_R, ball.pos, next_pos,
          level.bricks[i].right[0], level.bricks[i].right[1], level.bricks[i].right[2], level.bricks[i].right[3],
          &hit, &time
        )) {
      if (level.bricks[i].lives > 1) {
        ball.vel.x *= -1;
        intersection = TRUE;
      } else {
        brick_kill_contiguous(&level.bricks[i]);
        return FALSE;
      }
    }

    // Check top face if travelling down
    if (ball.vel.y < 0 &&
        !intersection &&
        moving_sphere_quad_intersect(
          BALL_R, ball.pos, next_pos,
          level.bricks[i].top[0], level.bricks[i].top[1], level.bricks[i].top[2], level.bricks[i].top[3],
          &hit, &time
        )) {
      if (level.bricks[i].lives > 1) {
        ball.vel.y *= -1;
        intersection = TRUE;
      } else {
        brick_kill_contiguous(&level.bricks[i]);
        return FALSE;
      }
    }

    // Check bottom face if travelling up
    if (ball.vel.y > 0 &&
        !intersection &&
        moving_sphere_quad_intersect(
          BALL_R, ball.pos, next_pos,
          level.bricks[i].bottom[0], level.bricks[i].bottom[1], level.bricks[i].bottom[2], level.bricks[i].bottom[3],
          &hit, &time
        )) {
      if (level.bricks[i].lives > 1) {
        ball.vel.y *= -1;
        intersection = TRUE;
      } else {
        brick_kill_contiguous(&level.bricks[i]);
        return FALSE;
      }
    }

    // Check back face if travelling towards from the camera
    if (ball.vel.z > 0 &&
        !intersection &&
        moving_sphere_quad_intersect(
          BALL_R, ball.pos, next_pos,
          level.bricks[i].back[0], level.bricks[i].back[1], level.bricks[i].back[2], level.bricks[i].back[3],
          &hit, &time
        )) {
      if (level.bricks[i].lives > 1) {
        ball.vel.z *= -1;
        intersection = TRUE;
      } else {
        brick_kill_contiguous(&level.bricks[i]);
        return FALSE;
      }
    }

    // If there was an intersection with any face of this brick,
    // start the hit animation timer
    if (intersection) {
      level.bricks[i].lives--;
      level.bricks[i].hit_anim_timer = BRICK_HIT_ANIM_DURATION;
      break;
    }
  }

  if (intersection) {
    // Move the ball to the intersection point
    vec3f_copy(ball.pos, hit);

    // Calculate the portion of the ball's movement that occurs after collision
    dist_after_hit = (1.0f - time) * dist;

    // Return the new next position so further testing can be done
    // between the point of intersection and the new next position
    vec3f_set(
      *new_next_pos,
      ball.pos.x + ball.vel.x * dist_after_hit,
      ball.pos.y + ball.vel.y * dist_after_hit,
      ball.pos.z + ball.vel.z * dist_after_hit
    );

    return TRUE;
  }

  // In the event that there is no collision at all, just return the original next_pos
  return FALSE;
}

static void update_camera(double dt) {
  Vec2f rot = {
    -(paddle.obj.pos.x / paddle.max_x) * 5,
    -(paddle.obj.pos.y / paddle.max_y) * 5
  };
  camera_rotate_to(rot);
  camera.pos.x = paddle.obj.pos.x * CAMERA_MOVE_SCALE;
  camera.pos.y = paddle.obj.pos.y * CAMERA_MOVE_SCALE;
}

static void update_ball(double dt) {
  int i, j;
  bool hit;
  bool brick_hit;
  Vec3f move;
  Vec3f next_pos, new_next_pos;
  double dist = BALL_BASE_VELOCITY * dt;

  // Project the next ball position
  move.x = ball.vel.x * dist;
  move.y = ball.vel.y * dist;
  move.z = ball.vel.z * dist;
  next_pos.x = ball.pos.x + move.x;
  next_pos.y = ball.pos.y + move.y;
  next_pos.z = ball.pos.z + move.z;

  // Start collision detection
  do {
    // Check for a collision with the bricks first
    hit = handle_collision_bricks(next_pos, dist, &new_next_pos);

    // If there's no collision with the bricks, check for collision with the walls
    if (!hit) {
      hit = handle_collision_walls(next_pos, dist, &new_next_pos);
    }

    // If there is ultimately a collision in this iteration, move the ball to its corrected position
    if (hit) {
      next_pos = new_next_pos;
    }
  } while (hit); // Iterate until there are no more collisions to resolve this update

  // If the ball is still live, move it to its corrected new position
  if (live) {
    // Skip this if the ball is being held by the paddle
    if (!paddle.held) {
      ball.pos = next_pos;
    }
  }
  // Otherwise, respawn the ball
  else {
    vec3f_set(ball.pos, 0, 0, UNIT_SIZE);
    vec3f_set(ball.vel, 0, 0, level.start_vel);
    live = TRUE;
  }
}

void game_init(void) {
  // Load level data
  level = level_load(level_data[current_level]);

  // Initialize stage
  vec3f_set(stage.pos, 0, 0, 0);
  vec3f_set(stage.rot, 0, 0, 0);
  vec3f_set(stage.vel, 0, 0, 0);
  stage.scale = level.width;

  // Initialize paddle
  paddle_init(&paddle, &level);

  // Initialize ball
  vec3f_set(ball.pos, 0, 0, 450);
  vec3f_set(ball.rot, 0, 0, 0);
  vec3f_set(ball.vel, 0, 0, level.start_vel);
  ball.scale = 1;

  // Initialize camera
  camera_init();
}

void game_update(double dt) {
  int i;

  // Check for a pause button press
  if (controller[0].trigger & START_BUTTON) {
    paused = !paused;
  }

  if (paused) {
    return;
  }

  paddle_update(&paddle, &level, dt);

  // Check if the ball is held
  if (paddle.held) {
    // Position the ball relative to the paddle
    ball.pos = paddle.hold_pos;
    vec3f_add(ball.pos, paddle.obj.pos);
    // Check for A button release
    if (!(controller[0].button & A_BUTTON)) {
      paddle.held = FALSE;
      paddle.hit_anim_timer = PADDLE_HIT_ANIM_DURATION;
    }
  } else {
    update_ball(dt);
  }

  update_camera(dt);

  // Update bricks
  for (i = 0; i < level.num_bricks; i++) {
    brick_update(&level.bricks[i], dt);
  }
}

void game_draw(void) {
  int i;
  MVP* mvpp = &mvp[task_num];
  glistp = &glist[task_num][0];

  graphics_init_RCP();
  graphics_clear(0, 0, 0);

  camera_look(mvpp);

  // Draw opaque objects first
  // Begin with the bricks
  for (i = 0; i < level.num_bricks; i++) {
    switch (level.bricks[i].lives) {
      case 3:
        graphics_draw_textured_object(&(level.bricks[i].obj), brick_Cube_mesh_green, FALSE);
        break;
      case 2:
        graphics_draw_textured_object(&(level.bricks[i].obj), brick_Cube_mesh_orange, FALSE);
        break;
      case 1:
        graphics_draw_textured_object(&(level.bricks[i].obj), brick_Cube_mesh_pink, FALSE);
        break;
      case 0:
        if (level.bricks[i].death_anim_timer > 0) {
          graphics_draw_textured_object(&(level.bricks[i].obj), brick_Cube_mesh_pink, FALSE);
        }
        break;
      default:
        break;
    }
  }

  // Draw the stage
  // graphics_draw_object(&stage, stage_opa_Cube_mesh, FALSE);
  graphics_draw_object(&stage, stage_Cube_mesh, FALSE);

  // Draw the ball
  graphics_draw_object(&ball, ball_Icosphere_mesh, FALSE);

  // Transparent objects drawn last
  graphics_draw_object(&paddle.obj, paddle_Cube_mesh, TRUE);

  gDPFullSync(glistp++);
  gSPEndDisplayList(glistp++);

  nuGfxTaskStart(
    &glist[task_num][0],
    (s32)(glistp - glist[task_num]) * sizeof(Gfx),
    NU_GFX_UCODE_F3DEX,
    NU_SC_SWAPBUFFER
  );

  task_num++;
  task_num %= MAX_TASKS;
}
