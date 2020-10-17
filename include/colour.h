#ifndef COLOUR_H
#define COLOUR_H

#include "common.h"

typedef struct {
  u8 r;
  u8 g;
  u8 b;
} Rgb;

typedef struct {
  u8 h;
  u8 s;
  u8 v;
} Hsv;

Rgb hsv_to_rgb(Hsv hsv);

#endif
