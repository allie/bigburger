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

#define MAX_PARTS 40

#define MIN_X -400
#define MAX_X 400

#define BLINK_PERIOD 1

extern NUContData controller[1];

static Object bottom_bun;
static Object top_bun;

static Part current_part;
static Part parts[MAX_PARTS];

static bool logo_shown = FALSE;
static bool press_start_shown = FALSE;
static u32 part_count = 0;
static double elapsed = 0;
static double blink_timer = 0;

static double hue;
static Hsv bg_hsv;
static Rgb bg_rgb;

static void draw_hud() {
  if (logo_shown) {
    popup_draw();
  }

  img_set_colour(255, 255, 255, 255);

  if (press_start_shown) {
    img_draw(press_start_img, SCREEN_W / 2 - press_start_img.width / 2, 190);
  }
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

  // Reset the bg colour
  bg_hsv.h = hue = 194;
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

  // Show the logo
  popup_init();
}

void title_update(double dt) {
  elapsed += dt;

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

  if (elapsed > 0.5 && !logo_shown) {
    popup_show(POPUP_TITLE, POPUP_TITLE_Y,  POPUP_TITLE_ANIM_DURATION, POPUP_VISIBLE_FOREVER);
    logo_shown = TRUE;
  }

  hue += dt * 10;
  if (hue >= 255) {
    hue -= 255;
  };
  bg_hsv.h = (u8)hue;
  bg_rgb = hsv_to_rgb(bg_hsv);

  popup_update(dt);
}

void title_draw() {
  int i;

  MVP* mvpp = &mvp[task_num];
  glistp = &glist[task_num][0];

  graphics_init_RCP();
  graphics_clear(bg_rgb.r, bg_rgb.g, bg_rgb.b);

  camera_look(mvpp);

  // Draw things
  // Bottom bun - only draw if there aren't many parts on the stack
  // if (part_count < 20) {
  //   graphics_draw_object(&bottom_bun, bun_Cube_mesh, FALSE);
  // }

  // // Placed parts
  // if (part_count < 20) {
  //   for (i = 0; i < part_count; i++) {
  //     draw_part(&parts[i]);
  //   }
  // } else {
  //   for (i = part_count - 20; i < part_count; i++) {
  //     draw_part(&parts[i]);
  //   }
  // }

  // // Current part
  // if (!bun_placed) {
  //   draw_part(&current_part);
  // }

  // // Top bun, if placed
  // if (bun_placed) {
  //   graphics_draw_object(&top_bun, bun_Cube_mesh, FALSE);
  // }

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
