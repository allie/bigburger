#ifndef POPUP_H
#define POPUP_H

#include "common.h"
#include "easing.h"

#define POPUP_DURATION 0.4
#define POPUP_Y_ANIM_DURATION 0.1
#define POPUP_START_Y 85
#define POPUP_END_Y 80

enum {
  POPUP_GREAT,
  POPUP_GOOD,
  POPUP_MISS
};

typedef struct {
  bool visible;
  int popup_type;
  double timer;
  float y;
  struct {
    EasingF y;
  } anim;
} Popup;

void popup_init();
void popup_show(int popup_type);
void popup_update(double dt);
void popup_draw();

#endif
