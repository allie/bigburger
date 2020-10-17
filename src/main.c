#include <nusys.h>
#include "game.h"

char heap[1024 * 512 * 1];

NUContData controller[1];

static OSTime last;

static void vsync_callback(int pending) {
  OSTime now;
  f32 dt;

  now = osGetTime();
  dt = OS_CYCLES_TO_USEC(now - last) / 1000000.0;
  last = now;

  nuContDataGetEx(controller, 0);

  game_update(dt);

  if (pending < 1) {
    game_draw();
  }
}

void mainproc(void* dummy) {
  nuGfxInit();
  nuContInit();

  InitHeap(heap, sizeof(heap));

  game_init();

  last = osGetTime();
  nuGfxFuncSet((NUGfxFunc)vsync_callback);
  nuGfxDisplayOn();

  while (1);
}
