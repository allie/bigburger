#include <nusys.h>
#include <math.h>
#include "common.h"
#include "title.h"
#include "graphics.h"
#include "camera.h"
#include "animation.h"
#include "object.h"
#include "part.h"
#include "colour.h"
#include "img.h"
#include "popup.h"
#include "number.h"
#include "gamestate.h"
#include "assets.h"

#define MAX_PARTS 20

#define MIN_X -800
#define MAX_X 800
#define MAX_Y 800.0f

#define BLINK_PERIOD 1

#define STACK_START_TIME 0.1
#define STACK_SPEED 10000
#define STACK_SPIN_SPEED 20

#define LOGO_START_TIME 2.0
#define START_BLINKING_TIME 2.0

#define BUN_DROP_DURATION 0.1

extern NUContData controller[1];

static Object bottom_bun;
static Object top_bun;

static Part current_part;
static Part parts[MAX_PARTS];

static bool logo_shown = FALSE;
static bool press_start_shown = FALSE;
static bool bun_placed = FALSE;
static u32 part_count = 0;
static double elapsed = 0;
static double blink_timer = 0;
static double press_start_opa = 0.0;
static int stopping_point;
static float current_y = 0;

static float burger_rot = 0;
static Mtx burger_rot_mtx;

static double hue;
static Hsv bg_hsv;
static Rgb bg_rgb;

static int intro_anim = -1;
static AnimationStatus intro_anim_status;

static int bg_colour_anim = -1;
static int press_start_opa_anim = -1;

static float heights[] = {
  40, // meat
  20, // cheese
  44, // lettuce
  20, // onion
  20 // tomato
};

static void draw_hud() {
  if (logo_shown) {
    popup_draw();
  }

  img_set_colour(255, 255, 255, (u8)press_start_opa);

  if (press_start_shown) {
    img_draw(press_start_img, SCREEN_W / 2 - press_start_img.width / 2, 190);
  }
}

static inline int get_stopping_point() {
  return rand() % 30;
}

void title_init() {
  // Init camera
  camera_init();

  // Reset variables
  part_count = 0;
  elapsed = 0;
  blink_timer = 0;
  logo_shown = FALSE;
  press_start_shown = FALSE;
  bun_placed = FALSE;
  current_y = 0;
  burger_rot = 0;

  // Reset the bg colour
  bg_hsv.h = hue = 90;
  bg_hsv.s = 255;
  bg_hsv.v = 180;
  bg_rgb = hsv_to_rgb(bg_hsv);

  // Initialize objects
  vec3f_set(bottom_bun.pos, 0, 0, 0);
  vec3f_set(bottom_bun.rot, 0, rand() % 360, 0);
  vec3f_set(bottom_bun.vel, 0, 0, 0);
  bottom_bun.scale = 1;

  vec3f_set(top_bun.pos, 0, 0, 0);
  vec3f_set(top_bun.rot, 180, rand() % 360, 0);
  vec3f_set(top_bun.vel, 0, 0, 0);
  top_bun.scale = 1;

  vec3f_set(current_part.obj.pos, MIN_X, 0, 0);
  vec3f_set(current_part.obj.rot, 0, 0, 0);
  vec3f_set(current_part.obj.vel, STACK_SPEED, 0, 0);
  current_part.obj.scale = 1;

  // Randomize the stopping point for the first part
  stopping_point = get_stopping_point();

  // Initialize and play the intro animation
  intro_anim = animation_create(
    0, TRUE, 4,
    animate_value(
      1, ANIM_FLOAT, &camera.pos.z,
      2.0, 1000.0f, 600.0f, EASE_QUAD_OUT
    ),
    animate_value(
      2, ANIM_FLOAT, &camera.pos.y,
      1.0, 400.0f, 700.0f, EASE_SIN_IN,
      1.0, 700.0f, 1000.0f, EASE_QUAD_OUT
    ),
    animate_value(
      3, ANIM_FLOAT, &burger_rot,
      0.8, 0.0f, -180.0f, EASE_QUAD_IN_OUT,
      0.8, -180.0f, 180.0f, EASE_QUAD_IN_OUT,
      0.4, 180.0f, 0.0f, EASE_CIRC_IN_OUT
    ),
    animate_value(
      2, ANIM_FLOAT, &top_bun.pos.y,
      1.5, 3000.0f, 3000.0f, EASE_LINEAR,
      0.5, 3000.0f, 600.0f, EASE_QUINT_IN_OUT
    )
  );
  animation_play(intro_anim);

  // Initialize and play the bg colour animation
  bg_colour_anim = animation_create(
    0, TRUE, 1,
    animate_value(
      1, ANIM_DOUBLE, &hue,
      2.0, 255.0, 720.0, EASE_LINEAR
    )
  );
  animation_play(bg_colour_anim);

  // Initialize the press start opacity animation
  press_start_opa_anim = animation_create(
    -1, FALSE, 1,
    animate_value(
      3, ANIM_DOUBLE, &press_start_opa,
      0.4, 0.0, 255.0, EASE_QUAD_OUT,
      2.0, 255.0, 255.0, EASE_LINEAR,
      0.4, 255.0, 0.0, EASE_QUINT_IN
    )
  );

  // Show the logo
  popup_init();
}

static void update_current_part(double dt) {
  current_part.obj.pos.x += current_part.obj.vel.x * dt;

  if ((current_part.obj.vel.x > 0 && current_part.obj.pos.x >= -stopping_point) ||
      (current_part.obj.vel.x < 0 && current_part.obj.pos.x <= stopping_point)) {
    // Move current_y up
    current_y += heights[current_part.ingredient];

    // Position the part being placed where it's intended to stop
    current_part.obj.pos.x = current_part.obj.vel.x < 0 ? stopping_point : -stopping_point;

    // Copy the current part to the stack
    parts[part_count++] = current_part;

    // Reinitialize current_part
    // Position on the other size of the screen
    current_part.obj.pos.x = current_part.obj.vel.x < 0 ? MIN_X : MAX_X;
    // Invert the velocity so it goes the other way
    current_part.obj.vel.x *= -1;
    // Move it up to current_y
    current_part.obj.pos.y = current_y;
    // Randomize the ingredient
    current_part.ingredient = rand() % 5;
    // Randomize the angle
    if (current_part.ingredient == LETTUCE) {
      // If the current part is lettuce, only rotate it to specific angles
      // so that the shading stands out
      current_part.obj.rot.y = rand() % 80 - 40;
    } else {
      // Otherwise, any angle goes
      current_part.obj.rot.y = rand() % 360;
    }

    // Generate a new stopping point
    stopping_point = get_stopping_point();

    // Advance the bg colour wheel
    bg_hsv.h++;
    hue = bg_hsv.h;
    bg_rgb = hsv_to_rgb(bg_hsv);
  }
}

void title_update(double dt) {
  int i;

  // If start is pressed, advance to the game
  if (controller[0].trigger & START_BUTTON) {
    gamestate_replace(GAMESTATE_GAME, TRUE, TRUE);
  }

  elapsed += dt;

  if (elapsed >= START_BLINKING_TIME && !press_start_shown) {
    press_start_shown = TRUE;
    animation_play(press_start_opa_anim);
  }

  // Get intro animation status
  intro_anim_status = animation_status(intro_anim);

  if (elapsed >= LOGO_START_TIME && !logo_shown) {
    popup_show(POPUP_TITLE, POPUP_TITLE_Y,  POPUP_TITLE_ANIM_DURATION, POPUP_VISIBLE_FOREVER);
    logo_shown = TRUE;
  }

  if (elapsed >= STACK_START_TIME && part_count < MAX_PARTS) {
    update_current_part(dt);
  }

  if (part_count == MAX_PARTS && !bun_placed && !intro_anim_status.playing) {
    bun_placed = TRUE;
  }

  bg_hsv.h = (u8)hue;
  bg_rgb = hsv_to_rgb(bg_hsv);

  if (bun_placed) {
    burger_rot -= STACK_SPIN_SPEED * dt;
  }

  popup_update(dt);
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

void title_draw() {
  int i;

  MVP* mvpp = &mvp[task_num];
  glistp = &glist[task_num][0];

  graphics_init_RCP();
  graphics_clear(bg_rgb.r, bg_rgb.g, bg_rgb.b);

  camera_look(mvpp);

  guRotate(&burger_rot_mtx, burger_rot, 0, 1, 0);
  gSPMatrix(
    glistp++,
    OS_K0_TO_PHYSICAL(&burger_rot_mtx),
    G_MTX_MODELVIEW | G_MTX_PUSH | G_MTX_MUL
  );

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
  if (!bun_placed) {
    draw_part(&current_part);
  }

  // Top bun
  graphics_draw_object(&top_bun, bun_Cube_mesh, FALSE);

  gSPPopMatrix(glistp++, G_MTX_MODELVIEW);

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

  task_num++;
  task_num %= MAX_TASKS;
}

void title_destroy() {
  animation_destroy_all();
  camera.pos.y = 0;
}
