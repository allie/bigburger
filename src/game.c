#include <nusys.h>
#include <math.h>
#include "common.h"
#include "game.h"
#include "graphics.h"
#include "camera.h"
#include "object.h"

#include "models/bun.h"
#include "models/patty.h"
#include "models/cheese.h"
#include "models/lettuce.h"

#define CAMERA_BASE_Y 300
#define MAX_PARTS 500
#define PART_HEIGHT 40

extern NUContData controller[1];

static bool paused = TRUE;

static Object bottom_bun;
static Object top_bun;

static int part_count = 3;
static Object parts[MAX_PARTS];

void game_init(void) {
  int i;

  // Initialize camera
  camera_init();

  // Initialize objects
  vec3f_set(bottom_bun.pos, 0, 0, 0);
  vec3f_set(bottom_bun.rot, 0, frand(360), 0);
  vec3f_set(bottom_bun.vel, 0, 0, 0);
  bottom_bun.scale = 1;

  for (i = 0; i < part_count; i++) {
    vec3f_set(parts[i].pos, 0, i * PART_HEIGHT, 0);
    vec3f_set(parts[i].rot, 0, frand(360), 0);
    vec3f_set(parts[i].vel, 0, 0, 0);
    parts[i].scale = 1;
  }

  vec3f_set(top_bun.pos, 0, part_count * PART_HEIGHT, 0);
  vec3f_set(top_bun.rot, 180, frand(360), 0);
  vec3f_set(top_bun.vel, 0, 0, 0);
  top_bun.scale = 1;

  // Move camera up to the top of the stack
  camera.pos.y = CAMERA_BASE_Y + part_count * PART_HEIGHT;
}

void game_update(double dt) {
  // Check for a pause button press
  if (controller[0].trigger & START_BUTTON) {
    paused = !paused;
  }

  if (paused) {
    return;
  }
}

void game_draw(void) {
  int i;
  MVP* mvpp = &mvp[task_num];
  glistp = &glist[task_num][0];

  graphics_init_RCP();
  graphics_clear(0, 0, 0);

  camera_look(mvpp);

  // Draw things
  // Bottom bun
  graphics_draw_object(&bottom_bun, bun_Cube_mesh, FALSE);

  // Burger parts
  for (i = 0; i < part_count; i++) {
    switch (i % 3) {
      case 0:
        graphics_draw_object(&parts[i], patty_Cube_mesh, FALSE);
        break;

      case 1:
        graphics_draw_object(&parts[i], cheese_Cube_mesh, FALSE);
        break;

      case 2:
        graphics_draw_object(&parts[i], lettuce_Cube_mesh, FALSE);
        break;
    }
  }

  // Top bun
  graphics_draw_object(&top_bun, bun_Cube_mesh, FALSE);

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
