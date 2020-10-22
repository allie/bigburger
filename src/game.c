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

#include "models/bun.h"
#include "models/patty.h"
#include "models/cheese.h"
#include "models/lettuce.h"
#include "models/tomato.h"
#include "models/onion.h"
#include "models/spatula.h"

#include "textures/level.h"
#include "textures/next_up.h"
#include "textures/next_big.h"
#include "textures/next_small.h"

#define MAX_PARTS 500
#define PART_QUEUE_LENGTH 3

#define SPATULA_BASE_Y 80
#define SPATULA_BASE_X 350
#define SPATULA_ROT_X_MAX 90
#define SPATULA_ANIM_DURATION 0.4

#define MIN_X -400
#define MAX_X 400

#define PART_BASE_SPEED 500
#define LEVEL_SPEED_INCREASE 10

#define MAX_CENTRE_OF_MASS 220

#define SWEET_SPOT_RANGE 30
#define BUN_RANGE 220

#define HUD_PADDING_Y 8

#define SCORE_GREAT 1000
#define SCORE_GOOD 500

extern NUContData controller[1];

static bool paused = FALSE;
static bool show_debug_console = FALSE;

static Object bottom_bun;
static Object top_bun;
static Object spatula;

static Part current_part;
static Part parts[MAX_PARTS];
static Part part_queue[PART_QUEUE_LENGTH];

static u64 score = 0;
static u32 part_count = 0;
static u32 current_y = 0;
static f32 centre_of_mass = 0;
static bool bun_placed = FALSE;
static bool in_sweet_spot = FALSE;

static EasingF camera_y;
static EasingF spatula_anim;

static Hsv bg_hsv;
static Rgb bg_rgb;

// Draw the HUD
static void draw_hud() {
  int x;

  // Set the image colour to white with full alpha
  img_set_colour(255, 255, 255, 255);

  // "LEVEL" text
  img_draw(level_img, SAFE_AREA_H, SAFE_AREA_V);
  // Current level value
  number_draw(
    part_count + 1,
    SAFE_AREA_H,
    SAFE_AREA_V + next_up_img.height + HUD_PADDING_Y
  );

  // "NEXT UP" text
  img_draw(next_up_img, SCREEN_W - SAFE_AREA_H - next_up_img.width, SAFE_AREA_V);

  // Upcoming piece backgrounds
  img_draw(
    next_big_img,
    SCREEN_W - SAFE_AREA_H - next_big_img.width,
    SAFE_AREA_V + next_up_img.height + HUD_PADDING_Y
  );
  img_draw(
    next_small_img,
    SCREEN_W - SAFE_AREA_H - next_small_img.width,
    SAFE_AREA_V + next_up_img.height + next_big_img.height + HUD_PADDING_Y * 2
  );

  // Score
  number_draw_0_padded(score, 1, NUMBER_ALIGN_CENTRE, SAFE_AREA_V);

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
  vec3f_set(part.obj.rot, 0, rand() % 360, 0);
  vec3f_set(part.obj.vel, 0, 0, 0);
  part.obj.scale = 1;

  return part;
}

static void update_part_queue() {
  int i;

  current_part = part_queue[PART_QUEUE_LENGTH - 1];

  for (i = 0; i < PART_QUEUE_LENGTH; i++) {
    if (i + 1 <= PART_QUEUE_LENGTH - 1) {
      part_queue[i + 1] = part_queue[i];
    }
  }
  part_queue[0].ingredient = -1;
  part_queue[0] = get_next_part();
}

static void init_current_part() {
  current_part.obj.pos.x = (rand() % (MAX_X - (current_part.size / 2))) + (current_part.size);
  if (rand() % 2 == 0) {
    current_part.obj.pos.x *= -1;
  }

  current_part.obj.vel.x = PART_BASE_SPEED + part_count * LEVEL_SPEED_INCREASE;
  if (current_part.obj.pos.x > 0) {
    current_part.obj.vel.x *= -1;
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

  float max_safe_dist = part_count > 0 ? parts[part_count - 1].size / 2 : BUN_RANGE;

  // Update current_y
  current_y += current_part.height;

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

  // Advance the part queue
  update_part_queue();

  // Move current_part to the correct elevation
  current_part.obj.pos.y = current_y;

  // Set the speed and position of the new current_part
  init_current_part();

  // Move up the spatula
  spatula.pos.y = current_y + SPATULA_BASE_Y;

  // Update the background colour
  bg_hsv.h--;
  bg_rgb = hsv_to_rgb(bg_hsv);

  // If this was a sweet spot hit, popup great
  if (in_sweet_spot) {
    popup_show(POPUP_GREAT);
    score += SCORE_GREAT;
  } else {
    if (dist >= max_safe_dist) {
      popup_show(POPUP_MISS);
    } else {
      popup_show(POPUP_GOOD);
      score += SCORE_GOOD;
    }
  }
}

static void update_current_part(double dt) {
  current_part.obj.pos.x += current_part.obj.vel.x * dt;
  if (current_part.obj.pos.x >= MAX_X) {
    current_part.obj.pos.x = MAX_X;
    current_part.obj.vel.x *= -1;
  }
  if (current_part.obj.pos.x <= MIN_X) {
    current_part.obj.pos.x = MIN_X;
    current_part.obj.vel.x *= -1;
  }

  // Grow the piece for a brief moment when it passes the sweet spot
  // This code is kind of a mess...
  if (part_count > 0) {
    if (fabs(current_part.obj.pos.x - parts[part_count - 1].obj.pos.x) < SWEET_SPOT_RANGE) {
      in_sweet_spot = TRUE;
      // current_part.obj.scale = 1.1;
    } else {
      in_sweet_spot = FALSE;
      // current_part.obj.scale = 1;
    }
  } else {
    if (fabs(current_part.obj.pos.x) < SWEET_SPOT_RANGE) {
      in_sweet_spot = TRUE;
      // current_part.obj.scale = 1.1;
    } else {
      in_sweet_spot = FALSE;
      // current_part.obj.scale = 1;
    }
  }
}

void game_init(void) {
  int i;

  // Reset some variables
  score = 0;
  part_count = 0;
  current_y = 0;
  centre_of_mass = 0;
  bun_placed = FALSE;
  camera_y.playing = FALSE;

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

  if (controller[0].trigger & A_BUTTON) {
    place_current_part();
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

  update_current_part(dt);

  // Update the HUD
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
  if (!bun_placed) {
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
    // Write some text
    // nuDebConCPuts(0, "");
    nuDebConDispEX2(NU_SC_NOSWAPBUFFER);
  }
#endif

  task_num++;
  task_num %= MAX_TASKS;
}
