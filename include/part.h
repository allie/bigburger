#ifndef PART_H
#define PART_H

#include "common.h"
#include "object.h"

#define TOTAL_PARTS 5

enum {
  MEAT = 0,
  CHEESE = 1,
  LETTUCE = 2,
  ONION = 3,
  TOMATO = 4
};

// Represents a part of the burger, like meat or cheese
typedef struct {
  u32 ingredient;
  f32 x;
  f32 mass;
  u32 height;
  u32 size;
  Object obj;
} Part;

#endif
