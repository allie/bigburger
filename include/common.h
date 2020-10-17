#ifndef COMMON_H
#define COMMON_H

#include <math.h>
#include <nusys.h>

#define EPSILON 0.00001f

#define DEADZONE 10

#define UNIT_SIZE 200.0f

#define radians(d) ((d) * M_PI / 180.0)
#define degrees(r) ((r) * 180.0 / M_PI)

#define flatten3D(x, y, z, width, height) (((z) * (width) * (height)) + ((y) * (width)) + (x))

// Cube sides
enum {
  SIDE_LEFT = 0,
  SIDE_RIGHT = 1,
  SIDE_TOP = 2,
  SIDE_BOTTOM = 3,
  SIDE_FRONT = 4,
  SIDE_BACK = 5
};

typedef u32 bool;

#endif
