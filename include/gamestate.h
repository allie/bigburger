#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "common.h"

enum {
  GAMESTATE_TITLE,
  GAMESTATE_GAME,
  GAMESTATE_RESULT
};

void gamestate_init_manager();
void gamestate_init();
void gamestate_update(double dt);
void gamestate_draw();
void gamestate_replace(int new_state, bool destroy_old, bool init_new);

#endif
