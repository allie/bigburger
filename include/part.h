#ifndef PART_H
#define PART_H

#include "common.h"

// Represents a part of the burger, like meat or cheese
typedef struct {
  f32 x;
  f32 mass;
  u32 length;
} Part;

#endif
