#ifndef POPUP_H
#define POPUP_H

#include "common.h"
#include "easing.h"

#define POPUP_VISIBLE_FOREVER -100

#define POPUP_JUDGE_ANIM_DURATION 0.1
#define POPUP_JUDGE_VISIBLE_DURATION 0.4
#define POPUP_JUDGE_Y 80

#define POPUP_TITLE_ANIM_DURATION 0.2
#define POPUP_TITLE_Y 30

#define POPUP_GAMEOVER_ANIM_DURATION 0.2

enum {
  POPUP_GREAT,
  POPUP_GOOD,
  POPUP_MISS,
  POPUP_TITLE,
  POPUP_GAMEOVER
};

typedef struct {
  bool visible;
  int popup_type;
  double timer;
  float y;
  int opacity;
  struct {
    EasingF y;
    EasingI opacity;
  } anim;
} Popup;

void popup_init();
void popup_show(int popup_type, float y, double anim_duration, double visible_duration);
void popup_update(double dt);
void popup_draw();
bool popup_is_playing();

#endif
