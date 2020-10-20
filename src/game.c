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

#include "models/bun.h"
#include "models/patty.h"
#include "models/cheese.h"
#include "models/lettuce.h"
#include "models/tomato.h"
#include "models/onion.h"
#include "models/spatula.h"

#define CAMERA_BASE_Y 300
#define MAX_PARTS 500
#define PART_QUEUE_LENGTH 3

#define SPATULA_BASE_Y 80
#define SPATULA_BASE_X 350
#define SPATULA_ROT_X_MAX 90
#define SPATULA_ANIM_DURATION 0.4

#define MIN_X -400
#define MAX_X 400

#define PART_BASE_SPEED 800
#define PART_SPEED_VARIANCE 1000

extern NUContData controller[1];

static bool paused = FALSE;
static bool show_debug_console = FALSE;

static Object bottom_bun;
static Object top_bun;
static Object spatula;

static Part current_part;
static Part parts[MAX_PARTS];
static Part part_queue[PART_QUEUE_LENGTH];

static u32 part_count = 0;
static u32 current_y = 0;
static bool bun_placed = FALSE;

static EasingF camera_y;
static EasingF spatula_anim;

static Hsv bg_hsv;
static Rgb bg_rgb;

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
      part.size = 320;
      part.mass = 0.5f;
      break;
    case LETTUCE:
      part.height = 44;
      part.size = 400;
      part.mass = 0.25f;
      break;
    case ONION:
      part.height = 20;
      part.size = 246;
      part.mass = 0.5f;
      break;
    case TOMATO:
      part.height = 20;
      part.size = 246;
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

static void randomize_current_part() {
  current_part.obj.pos.x = (rand() % (MAX_X - (current_part.size / 2))) + (current_part.size);
  if (rand() % 2 == 0) {
    current_part.obj.pos.x *= -1;
  }

  current_part.obj.vel.x = (rand() % PART_SPEED_VARIANCE) + PART_BASE_SPEED;
  if (current_part.obj.pos.x > 0) {
    current_part.obj.vel.x *= -1;
  }
}

static void place_current_part() {
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
  update_part_queue();

  // Move current_part to the correct elevation
  current_part.obj.pos.y = current_y;

  // Set the speed and position of the new current_part
  randomize_current_part();

  // Move up the spatula
  spatula.pos.y = current_y + SPATULA_BASE_Y;

  // Update the background colour
  bg_hsv.h--;
  bg_rgb = hsv_to_rgb(bg_hsv);
}

static void place_bun() {
  current_y += current_part.height;
  top_bun.pos.y = current_y;
  bun_placed = TRUE;
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
}

void game_init(void) {
  int i;

  // Reset some variables
  part_count = 0;
  current_y = 0;
  bun_placed = FALSE;

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
  randomize_current_part();

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
  draw_part(&current_part);

  // Top bun, if placed
  if (bun_placed) {
    graphics_draw_object(&top_bun, bun_Cube_mesh, FALSE);
  }

  // Spatula
  if (spatula_anim.playing) {
    graphics_draw_object(&spatula, spatula_Plane_mesh, FALSE);
  }

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
