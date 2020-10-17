#ifndef CAMERA_H
#define CAMERA_H

#include <nusys.h>
#include "vector.h"
#include "graphics.h"

typedef struct {
  float fov;
  Vec3f pos;
  Vec3f world_up;
  Vec3f up;
  Vec3f front;
  Vec3f right;
  Vec3f forward;
  float pitch;
  float yaw;
  Vec3f target;
} Camera;

extern Camera camera;

void camera_init();
void camera_look(MVP* mvpp);
void camera_move(Vec3f velocity);
void camera_move_to(Vec3f pos);
void camera_rotate(Vec2f rot);
void camera_rotate_to(Vec2f rot);

#endif
