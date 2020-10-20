#ifndef COMMON_H
#define COMMON_H

#include <math.h>
#include <nusys.h>

#define EPSILON 0.00001f

#define DEADZONE 10

#define UNIT_SIZE 200.0f

#define radians(d) ((d) * M_PI / 180.0)
#define degrees(r) ((r) * 180.0 / M_PI)
#define max(a, b) ((a) > (b) ? (a) : (b))

#define flatten3D(x, y, z, width, height) (((z) * (width) * (height)) + ((y) * (width)) + (x))

typedef u32 bool;

#endif
