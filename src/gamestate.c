#include "gamestate.h"
#include "title.h"
#include "game.h"
#include "result.h"

static int current_state;

void gamestate_init_manager() {
  current_state = GAMESTATE_TITLE;
}

void gamestate_init() {
  switch (current_state) {
    case GAMESTATE_TITLE:
      title_init();
      break;
    case GAMESTATE_GAME:
      game_init();
      break;
    case GAMESTATE_RESULT:
      result_init();
      break;
    default:
      break;
  }
}

void gamestate_update(double dt) {
  switch (current_state) {
    case GAMESTATE_TITLE:
      title_update(dt);
      break;
    case GAMESTATE_GAME:
      game_update(dt);
      break;
    case GAMESTATE_RESULT:
      result_update(dt);
      break;
    default:
      break;
  }
}

void gamestate_draw() {
  switch (current_state) {
    case GAMESTATE_TITLE:
      title_draw();
      break;
    case GAMESTATE_GAME:
      game_draw();
      break;
    case GAMESTATE_RESULT:
      result_draw();
      break;
    default:
      break;
  }
}

void gamestate_replace(int new_state, bool destroy_old, bool init_new) {
  if (destroy_old) {
    switch (current_state) {
      case GAMESTATE_TITLE:
        title_destroy();
        break;
      case GAMESTATE_GAME:
        game_destroy();
        break;
      case GAMESTATE_RESULT:
        result_destroy();
        break;
      default:
        break;
    }
  }

  current_state = new_state;

  if (init_new) {
    switch (current_state) {
      case GAMESTATE_TITLE:
        title_init();
        break;
      case GAMESTATE_GAME:
        game_init();
        break;
      case GAMESTATE_RESULT:
        result_init();
        break;
      default:
        break;
    }
  }
}
