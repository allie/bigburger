#include <nusys.h>
#include <math.h>
#include "common.h"
#include "game.h"
#include "graphics.h"
#include "camera.h"
#include "easing.h"
#include "object.h"
#include "part.h"
#include "colour.h"
#include "img.h"
#include "popup.h"
#include "number.h"
#include "gamestate.h"
#include "assets.h"

#define MAX_PARTS 1001
#define PART_QUEUE_LENGTH 3

#define SPATULA_BASE_Y 80
#define SPATULA_BASE_X 350
#define SPATULA_ROT_X_MAX 90
#define SPATULA_ANIM_DURATION 0.4

#define MIN_X -700
#define MAX_X 700

#define PART_BASE_SPEED 600
#define LEVEL_SPEED_INCREASE 10

#define MAX_CENTRE_OF_MASS 220

#define SWEET_SPOT_RANGE 30
#define BUN_RANGE 220

#define HUD_PADDING_Y 8

#define SCORE_GREAT 1000
#define SCORE_GOOD 500
#define SCORE_CENTRE_BONUS 500

#define STARTING_LIVES 3

#define SHRINK_ANIM_DURATION 0.05
#define GROW_ANIM_DURATION 0.1

#define SECONDARY_PART_WINDOW 0.3

// Globals
extern NUContData controller[1];

static bool paused = FALSE;
static bool show_debug_console = FALSE;

static Object bottom_bun;
static Object top_bun;
static Object spatula;

static Part current_part;
Part parts[MAX_PARTS];
static Part part_queue[PART_QUEUE_LENGTH];

u64 score = 0;
static u32 lives = STARTING_LIVES;
u32 part_count = 0;
static u32 current_y = 0;
static f32 centre_of_mass = 0;
static bool bun_placed = FALSE;
static bool in_sweet_spot = FALSE;
static bool can_place_secondary_part = FALSE;

static EasingF camera_y;
static EasingF spatula_anim;
static EasingF shrink_anim;
static EasingF grow_anim;

static Hsv bg_hsv;
Rgb bg_rgb;

// Represents a point in the difficulty curve
typedef struct {
  int start;
  int end;
  double base_speed;
  double level_speed_increase;
} Difficulty;

static Difficulty difficulty_curve[] = {
  { 1,   99,   600, 10 }, // Moderate speed increase from 1-99
  { 100, 199, 1600, 12 }, // Slightly increase speedup at 100
  { 200, 399,  800, 20 }, // Slowdown at level 200 with rapid speedup
  { 300, 399, 2800, 10 }, // Chill out a bit after 300. 2800 is pretty fast already!
  { 400, 499, 3800, 5  }, // Decelerate some more
  { 500, 0,   4300, 2  }  // Final deceleration. If you reach level 1000, speed would be 5300
};

static int current_difficulty = 0;

// Get the current part speed by applying the difficulty curve to the current level
static double get_current_speed() {
  return difficulty_curve[current_difficulty].base_speed +
    ((part_count - difficulty_curve[current_difficulty].start + 1) *
    difficulty_curve[current_difficulty].level_speed_increase);
}

// Draw the HUD
static void draw_hud() {
  int x;

  // Set the image colour to white with full alpha
  img_set_colour(255, 255, 255, 255);

  // "SCORE" text
  img_draw(score_img, SAFE_AREA_H, SAFE_AREA_V);
  // Score value
  number_draw_0_padded(score, 1, SAFE_AREA_H, 31);

  // "LEVEL" text
  img_draw(level_img, SAFE_AREA_H, 58);
  // Current level value
  number_draw(
    part_count + 1,
    SAFE_AREA_H,
    72
  );

  // "NEXT UP" text
  img_draw(next_up_img, SCREEN_W - SAFE_AREA_H - next_up_img.width, SAFE_AREA_V);

  // Upcoming piece backgrounds
  img_draw(
    next_big_img,
    SCREEN_W - SAFE_AREA_H - next_big_img.width,
    31
  );
  img_draw(
    next_small_img,
    SCREEN_W - SAFE_AREA_H - next_small_img.width,
    67
  );

  // Next upcoming piece
  switch (part_queue[2].ingredient) {
    case MEAT:
      img_draw(meat_big_img, SCREEN_W - SAFE_AREA_H - next_big_img.width, 31);
      break;
    case CHEESE:
      img_draw(cheese_big_img, SCREEN_W - SAFE_AREA_H - next_big_img.width, 31);
      break;
    case LETTUCE:
      img_draw(lettuce_big_img, SCREEN_W - SAFE_AREA_H - next_big_img.width, 31);
      break;
    case TOMATO:
      img_draw(tomato_big_img, SCREEN_W - SAFE_AREA_H - next_big_img.width, 31);
      break;
    case ONION:
      img_draw(onion_big_img, SCREEN_W - SAFE_AREA_H - next_big_img.width, 31);
      break;
    default:
      break;
  }

  // Upcoming piece after the next one
  switch (part_queue[1].ingredient) {
    case MEAT:
      img_draw(meat_small_img, SCREEN_W - SAFE_AREA_H - next_small_img.width, 67);
      break;
    case CHEESE:
      img_draw(cheese_small_img, SCREEN_W - SAFE_AREA_H - next_small_img.width, 67);
      break;
    case LETTUCE:
      img_draw(lettuce_small_img, SCREEN_W - SAFE_AREA_H - next_small_img.width, 67);
      break;
    case TOMATO:
      img_draw(tomato_small_img, SCREEN_W - SAFE_AREA_H - next_small_img.width, 67);
      break;
    case ONION:
      img_draw(onion_small_img, SCREEN_W - SAFE_AREA_H - next_small_img.width, 67);
      break;
    default:
      break;
  }

  // Draw dpad
  img_draw(dpad_img, 35, 171);

  // Draw A button
  img_draw(a_button_img, 247, 177);

  // Draw spatula icon over A button
  img_draw(spatula_img, 253, 168);

  // Draw popups
  popup_draw();
}

// Generate the next random burger part.
// Doesn't allow the next part to be a dupe of any of the parts in the queue.
static Part get_next_part() {
  Part part;
  int i;
  bool retry;

  part.x = 0;

  do {
    retry = FALSE;
    part.ingredient = rand() % TOTAL_PARTS;
    for (i = 0; i < PART_QUEUE_LENGTH; i++) {
      if (part_queue[i].ingredient == part.ingredient) {
        retry = TRUE;
        break;
      }
    }
  } while (retry);

  switch (part.ingredient) {
    case MEAT:
      part.height = 40;
      part.size = 400;
      part.mass = 1;
      break;
    case CHEESE:
      part.height = 20;
      part.size = 386;
      part.mass = 0.5f;
      break;
    case LETTUCE:
      part.height = 44;
      part.size = 400;
      part.mass = 0.25f;
      break;
    case ONION:
      part.height = 20;
      part.size = 352;
      part.mass = 0.5f;
      break;
    case TOMATO:
      part.height = 20;
      part.size = 352;
      part.mass = 0.5f;
      break;
    default:
      break;
  }

  vec3f_set(part.obj.pos, 0, 0, 0);
  vec3f_set(part.obj.rot, 0, 0, 0);
  vec3f_set(part.obj.vel, 0, 0, 0);
  part.obj.scale = 1;

  return part;
}

static void update_part_queue() {
  int i;

  // Pop the current part off the queue
  current_part = part_queue[2];

  // Move ingredients forward in the queue
  part_queue[2] = part_queue[1];
  part_queue[1] = part_queue[0];

  // Generate a new ingredient at the end of the queue
  part_queue[0].ingredient = -1;
  part_queue[0] = get_next_part();
}

static void init_current_part() {
  current_part.obj.pos.x = MAX_X;
  if (rand() % 2 == 0) {
    current_part.obj.pos.x *= -1;
  }

  current_part.obj.vel.x = get_current_speed();
  if (current_part.obj.pos.x > 0) {
    current_part.obj.vel.x *= -1;
  }

  if (current_part.ingredient == LETTUCE) {
    // If the current part is lettuce, only rotate it to specific angles
    // so that the shading stands out
    current_part.obj.rot.y = rand() % 80 - 40;
  } else {
    // Otherwise, any angle goes
    current_part.obj.rot.y = rand() % 360;
  }
}

static f32 calc_centre_of_mass() {
  f32 top;
  f32 total_mass;
  int i;

  for (i = 0; i < part_count; i++) {
    top += parts[i].mass * parts[i].obj.pos.x;
    total_mass += parts[i].mass;
  }

  if (total_mass == 0) {
    return 0;
  }

  return top / total_mass;
}

static void place_bun() {
  current_y += current_part.height;
  top_bun.pos.y = current_y;
  bun_placed = TRUE;
}

static void place_current_part() {
  float dist = part_count > 0 ?
    fabs(current_part.obj.pos.x - parts[part_count - 1].obj.pos.x) :
    fabs(current_part.obj.pos.x);
  float dist_from_centre = fabs(current_part.obj.pos.x);

  float max_safe_dist = part_count > 0 ? parts[part_count - 1].size / 2 : BUN_RANGE;

  // Update current_y
  float camera_raise = current_part.height;
  current_y += camera_raise;

  // Stop current_part from moving
  current_part.obj.vel.x = 0;

  // Start easing camera elevation up
  easing_init(camera_y, &camera.pos.y, 0.2, camera.pos.y, CAMERA_BASE_Y + current_y, easing_linear_f);
  easing_play(camera_y);

  // Start spatula animation
  spatula.pos.x = current_part.obj.pos.x + SPATULA_BASE_X;
  easing_init(spatula_anim, &spatula.rot.x, SPATULA_ANIM_DURATION, 0, SPATULA_ROT_X_MAX, easing_linear_f);
  easing_play(spatula_anim);

  // Update random part queue
  parts[part_count++] = current_part;

  // Update difficulty level
  if (
    difficulty_curve[current_difficulty].end != 0 &&
    difficulty_curve[current_difficulty].end < part_count + 1
  ) {
    current_difficulty++;
  }

  // Update the background colour
  bg_hsv.h--;
  // Every 100 levels, dramatically change the colour
  if ((part_count + 1) % 100 == 0) {
    bg_hsv.h -= 127;
  }
  bg_rgb = hsv_to_rgb(bg_hsv);

  // If this was a sweet spot hit, popup great
  if (in_sweet_spot) {
    popup_show(POPUP_GREAT, POPUP_JUDGE_Y, POPUP_JUDGE_ANIM_DURATION, POPUP_JUDGE_VISIBLE_DURATION);
    score += SCORE_GREAT;
  } else {
    // Check for a miss
    if (dist >= max_safe_dist) {
      popup_show(POPUP_MISS, POPUP_JUDGE_Y,  POPUP_JUDGE_ANIM_DURATION, POPUP_JUDGE_VISIBLE_DURATION);
      lives--;
      part_count--;
      current_y -= camera_raise;
      current_part.obj.pos.y = current_y;
      // Cancel the camera raise animation
      camera_y.playing = FALSE;
    } else {
      // Just good.
      popup_show(POPUP_GOOD, POPUP_JUDGE_Y,  POPUP_JUDGE_ANIM_DURATION, POPUP_JUDGE_VISIBLE_DURATION);
      score += SCORE_GOOD;
    }
  }

  // Add some extra points for keeping the stack near the centre of the screen
  if (dist < max_safe_dist) {
    score += (((MAX_X / 2) - dist_from_centre) / (MAX_X / 2)) * SCORE_CENTRE_BONUS;
  }
}

static void spawn_next_part() {
  // End secondary ingredient window
  can_place_secondary_part = FALSE;

  // Advance the part queue
  update_part_queue();

  // Move current_part to the correct elevation
  current_part.obj.pos.y = current_y;

  // Set the speed and position of the new current_part
  init_current_part();

  // Start animation to grow the placed part back to its original size, if it shrunk
  if ((int)(parts[part_count - 1].obj.scale) < 1) {
    easing_init(
      grow_anim,
      &parts[part_count - 1].obj.scale,
      (1 - parts[part_count - 1].obj.scale) * GROW_ANIM_DURATION,
      parts[part_count - 1].obj.scale,
      1,
      easing_linear_f
    );
    easing_play(grow_anim);
  }

  // Reset the scale for the current part and stop the shrink animation
  current_part.obj.scale = 1;
  shrink_anim.playing = FALSE;

  // Move up the spatula
  spatula.pos.y = current_y + SPATULA_BASE_Y;
}

static void update_current_part(double dt) {
  current_part.obj.pos.x += current_part.obj.vel.x * dt;
  if (current_part.obj.pos.x >= MAX_X) {
    current_part.obj.pos.x = MAX_X;
  }
  if (current_part.obj.pos.x <= MIN_X) {
    current_part.obj.pos.x = MIN_X;
  }
  if (current_part.obj.pos.x >= MAX_X || current_part.obj.pos.x <= MIN_X) {
    current_part.obj.vel.x *= -1;
    easing_init(shrink_anim, &current_part.obj.scale, SHRINK_ANIM_DURATION, current_part.obj.scale, current_part.obj.scale - 0.2, easing_linear_f);
    easing_play(shrink_anim);
  }

  // If the current part's scale has shrunk to 0, it's an automatic miss
  if (fabs(current_part.obj.scale) <= EPSILON) {
    popup_show(POPUP_MISS, POPUP_JUDGE_Y,  POPUP_JUDGE_ANIM_DURATION, POPUP_JUDGE_VISIBLE_DURATION);
    lives--;
    update_part_queue();
    init_current_part();
    current_part.obj.scale = 1;
    current_part.obj.pos.y = current_y;
    return;
  }

  // Keep track of whether the part is in the sweet spot
  if (part_count > 0) {
    if (fabs(current_part.obj.pos.x - parts[part_count - 1].obj.pos.x) < SWEET_SPOT_RANGE) {
      in_sweet_spot = TRUE;
    } else {
      in_sweet_spot = FALSE;
    }
  } else {
    if (fabs(current_part.obj.pos.x) < SWEET_SPOT_RANGE) {
      in_sweet_spot = TRUE;
    } else {
      in_sweet_spot = FALSE;
    }
  }
}

void game_init(void) {
  int i;

  // Reset some variables
  score = 0;
  lives = STARTING_LIVES;
  part_count = 0;
  current_y = 0;
  centre_of_mass = 0;
  bun_placed = FALSE;
  camera_y.playing = FALSE;
  spatula_anim.playing = FALSE;
  can_place_secondary_part = FALSE;
  current_difficulty = 0;

  // Reset the bg colour
  bg_hsv.h = 194;
  bg_hsv.s = 255;
  bg_hsv.v = 180;
  bg_rgb = hsv_to_rgb(bg_hsv);

  // Initialize camera
  camera_init();
  camera.pos.y = CAMERA_BASE_Y;

  // Clear out random part queue
  for (i = 0; i < PART_QUEUE_LENGTH; i++) {
    part_queue[i].ingredient = -1;
  }

  // Fill up the random part queue
  for (i = 0; i < PART_QUEUE_LENGTH; i++) {
    part_queue[i] = get_next_part();
  }

  // Set up the current part
  update_part_queue();
  init_current_part();

  // Initialize objects
  vec3f_set(bottom_bun.pos, 0, 0, 0);
  vec3f_set(bottom_bun.rot, 0, rand() % 360, 0);
  vec3f_set(bottom_bun.vel, 0, 0, 0);
  bottom_bun.scale = 1;

  vec3f_set(top_bun.pos, 0, 0, 0);
  vec3f_set(top_bun.rot, 180, rand() % 360, 0);
  vec3f_set(top_bun.vel, 0, 0, 0);
  top_bun.scale = 1;

  vec3f_set(spatula.pos, SPATULA_BASE_X + current_part.x, SPATULA_BASE_Y, 650);
  vec3f_set(spatula.rot, SPATULA_ROT_X_MAX, 30, 0);
  vec3f_set(spatula.vel, 0, 0, 0);
  spatula.scale = 0.5;

  // Initialize popups
  popup_init();
}

void game_update(double dt) {
#ifdef __DEBUG__
  if (controller[0].trigger & Z_TRIG) {
    show_debug_console = !show_debug_console;
  }
#endif

  // Check for a pause button press
  if (controller[0].trigger & START_BUTTON) {
    // paused = !paused;
    game_init();
  }

  if (bun_placed) {
    return;
  }

  if (!can_place_secondary_part && controller[0].trigger & A_BUTTON) {
    place_current_part();
    can_place_secondary_part = TRUE;
    timer_run_callback(
      spawn_next_part,
      NULL,
      SECONDARY_PART_WINDOW - (SECONDARY_PART_WINDOW * ((part_count) / (MAX_PARTS - 1)))
    );
  }

  if (controller[0].trigger & B_BUTTON) {
    place_bun();
  }

  if (camera_y.playing) {
    easing_update(camera_y, dt);
  }

  if (spatula_anim.playing) {
    easing_update(spatula_anim, dt);
  }

  if (shrink_anim.playing) {
    easing_update(shrink_anim, dt);
  }

  if (grow_anim.playing) {
    easing_update(grow_anim, dt);
  }

  update_current_part(dt);

  // Update the HUD
  popup_update(dt);

  // Check if the game is lost
  if (lives == 0) {
    // Go to the results screen if so
    gamestate_replace(GAMESTATE_RESULT, FALSE, TRUE);
  }
}

static void draw_part(Part* part) {
  switch (part->ingredient) {
    case MEAT:
      graphics_draw_object(&(part->obj), patty_Cube_mesh, FALSE);
      break;

    case CHEESE:
      graphics_draw_object(&(part->obj), cheese_Cube_mesh, FALSE);
      break;

    case LETTUCE:
      graphics_draw_object(&(part->obj), lettuce_Cube_mesh, FALSE);
      break;

    case ONION:
      graphics_draw_object(&(part->obj), onion_Cube_mesh, FALSE);
      break;

    case TOMATO:
      graphics_draw_object(&(part->obj), tomato_Cube_mesh, FALSE);
      break;
  }
}

void game_draw(void) {
  int i;

  MVP* mvpp = &mvp[task_num];
  glistp = &glist[task_num][0];

  graphics_init_RCP();
  graphics_clear(bg_rgb.r, bg_rgb.g, bg_rgb.b);

  camera_look(mvpp);

  // Draw things
  // Bottom bun - only draw if there aren't many parts on the stack
  if (part_count < 20) {
    graphics_draw_object(&bottom_bun, bun_Cube_mesh, FALSE);
  }

  // Placed parts
  if (part_count < 20) {
    for (i = 0; i < part_count; i++) {
      draw_part(&parts[i]);
    }
  } else {
    for (i = part_count - 20; i < part_count; i++) {
      draw_part(&parts[i]);
    }
  }

  // Current part
  if (!bun_placed && !can_place_secondary_part) {
    draw_part(&current_part);
  }

  // Top bun, if placed
  if (bun_placed) {
    graphics_draw_object(&top_bun, bun_Cube_mesh, FALSE);
  }

  // Spatula
  if (spatula_anim.playing && !bun_placed) {
    graphics_draw_object(&spatula, spatula_Plane_mesh, FALSE);
  }

  // Draw the HUD on top of everything else
  img_start();
  draw_hud();
  img_end();

  gDPFullSync(glistp++);
  gSPEndDisplayList(glistp++);

  nuGfxTaskStart(
    &glist[task_num][0],
    (s32)(glistp - glist[task_num]) * sizeof(Gfx),
    NU_GFX_UCODE_F3DEX,
    NU_SC_SWAPBUFFER
  );

#ifdef __DEBUG__
  if (show_debug_console) {
    nuDebConClear(0);
    nuDebConWindowSize(0, 5, 5);
    nuDebConTextPos(0, 0, 0);
    nuDebConTextColor(0, NU_DEB_CON_TEXT_WHITE);
    // nuDebConCPuts(0, console);
    nuDebConDisp(NU_SC_SWAPBUFFER);
  }
#endif

  task_num++;
  task_num %= MAX_TASKS;
}

void game_destroy() {

}
