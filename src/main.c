#include <nusys.h>
#include "common.h"
#include "title.h"
#include "game.h"

char heap[1024 * 512 * 1];

// Globals
NUContData controller[1];
bool in_intro = TRUE;

static OSTime last;

static void vsync_callback(int pending) {
  OSTime now;
  f32 dt;

  now = osGetTime();
  dt = OS_CYCLES_TO_USEC(now - last) / 1000000.0;
  last = now;

  nuContDataGetEx(controller, 0);

  if (in_intro && controller[0].trigger & START_BUTTON) {
    in_intro = FALSE;
    game_init();
  }

  if (in_intro) {
    title_update(dt);
  } else {
    game_update(dt);
    // If booted back to the title screen during this update,
    // init and update it
    if (in_intro) {
      title_init();
      title_update(dt);
    }
  }

  if (pending < 1) {
    if (in_intro) {
      title_draw();
    } else {
      game_draw();
    }
  }
}

void mainproc(void* dummy) {
  nuGfxInit();
  nuContInit();

  InitHeap(heap, sizeof(heap));

  title_init();

  last = osGetTime();
  nuGfxFuncSet((NUGfxFunc)vsync_callback);
  nuGfxDisplayOn();

  while (1);
}
