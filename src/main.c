#include <nusys.h>
#include "common.h"
#include "gamestate.h"
#include "timer.h"
#include "animation.h"

char heap[1024 * 512 * 1];

// Globals
NUContData controller[1];

static OSTime last;

static void vsync_callback(int pending) {
  OSTime now;
  f32 dt;

  now = osGetTime();
  dt = OS_CYCLES_TO_USEC(now - last) / 1000000.0;
  last = now;

  // Update timer system, running any callbacks before the game state update
  timer_update(dt);

  // Update animation system
  animation_update(dt);

  nuContDataGetEx(controller, 0);

  gamestate_update(dt);

  if (pending < 1) {
    gamestate_draw();
  }
}

void mainproc(void* dummy) {
  nuGfxInit();

#ifdef PAL_MODE
  osViSetMode(&osViModeTable[OS_VI_FPAL_LAN1]);
  osViSetYScale(0.833);
#endif

  nuContInit();

  InitHeap(heap, sizeof(heap));

  // Initialize timer system
  timer_init();

  // Initialize animation system
  animation_init();

  // Initialize game state manager
  gamestate_init_manager();

  // Start on the title screen
  gamestate_replace(GAMESTATE_TITLE, FALSE, TRUE);

  last = osGetTime();
  nuGfxFuncSet((NUGfxFunc)vsync_callback);
  nuGfxDisplayOn();

  while (1);
}
