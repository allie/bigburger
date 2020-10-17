#include <nusys.h>
#include <math.h>
#include "common.h"
#include "game.h"
#include "graphics.h"
#include "camera.h"
#include "object.h"

extern NUContData controller[1];

static bool paused = TRUE;

void game_init(void) {
  // Initialize camera
  camera_init();
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
