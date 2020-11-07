#include <nusys.h>
#include <math.h>
#include "common.h"
#include "title.h"
#include "graphics.h"
#include "camera.h"
#include "easing.h"
#include "object.h"
#include "part.h"
#include "colour.h"
#include "img.h"
#include "popup.h"
#include "number.h"
#include "assets.h"

#define MAX_PARTS 20

#define MIN_X -800
#define MAX_X 800
#define MAX_Y 800

#define BLINK_PERIOD 1

#define STACK_START_TIME 0.1
#define STACK_SPEED 10000
#define STACK_SPIN_SPEED 20

#define LOGO_START_TIME 2.0
#define START_BLINKING_TIME 1.5

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
static int stopping_point;
static float current_y = 0;

static float burger_rot = 0;
static Mtx burger_rot_mtx;

static double hue;
static Hsv bg_hsv;
static Rgb bg_rgb;

static EasingF camera_y;
static EasingF bun_drop;

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

  img_set_colour(255, 255, 255, 255);

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

    // Ease the camera up to the correct Y
    easing_init(camera_y, &camera.pos.y, 0.05, camera.pos.y, CAMERA_BASE_Y + current_y, easing_linear_f);
    easing_play(camera_y);

    // Advance the bg colour wheel
    bg_hsv.h++;
    hue = bg_hsv.h;
    bg_rgb = hsv_to_rgb(bg_hsv);
  }
}

void title_update(double dt) {
  int i;

  elapsed += dt;

  if (elapsed >= START_BLINKING_TIME) {
    if (press_start_shown) {
      blink_timer -= dt;
      if (blink_timer <= 0) {
        press_start_shown = FALSE;
      }
    } else {
      blink_timer += dt;
      if (blink_timer >= BLINK_PERIOD) {
        press_start_shown = TRUE;
      }
    }
  }

  if (elapsed >= LOGO_START_TIME && !logo_shown) {
    popup_show(POPUP_TITLE, POPUP_TITLE_Y,  POPUP_TITLE_ANIM_DURATION, POPUP_VISIBLE_FOREVER);
    logo_shown = TRUE;
  }

  if (elapsed >= STACK_START_TIME && part_count < MAX_PARTS) {
    update_current_part(dt);
  }

  if (camera_y.playing) {
    easing_update(camera_y, dt);
  }

  if (bun_drop.playing) {
    easing_update(bun_drop, dt);
    if (!bun_drop.playing) {
      bun_placed = TRUE;
    }
  }

  if (part_count == MAX_PARTS && !bun_placed && !bun_drop.playing) {
    easing_init(bun_drop, &top_bun.pos.y, BUN_DROP_DURATION, MAX_Y, current_y, easing_linear_f);
    easing_play(bun_drop);
    top_bun.pos.x = get_stopping_point();
  }

  if (part_count == MAX_PARTS) {
    hue += dt * 10;
    if (hue >= 255) {
      hue -= 255;
    };
    bg_hsv.h = (u8)hue;
    bg_rgb = hsv_to_rgb(bg_hsv);
  }

  if (bun_placed) {
    burger_rot += STACK_SPIN_SPEED * dt;
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

  // Top bun, if placed
  if (bun_placed || bun_drop.playing) {
    graphics_draw_object(&top_bun, bun_Cube_mesh, FALSE);
  }

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
