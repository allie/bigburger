#ifndef OBJECT_H
#define OBJECT_H

#include <nusys.h>
#include "vector.h"

typedef struct {
  Vec3f pos;
  Vec3f rot;
  Vec3f vel;
  float scale;
  Mtx transform;
} Object;

#endif
