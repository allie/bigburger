#include <nusys.h>
#include "common.h"
#include "vector.h"
#include "camera.h"
#include "graphics.h"

// Global camera
Camera camera;

// Recalculate orientation vectors
static void recalc_orientation() {
  // Calculate front vector
  vec3f_set(
    camera.front,
    cos(radians(camera.yaw)) * cos(radians(camera.pitch)),
    sin(radians(camera.pitch)),
    sin(radians(camera.yaw)) * cos(radians(camera.pitch))
  );
  vec3f_norm(camera.front);

  // Calculate forward vector
  vec3f_set(
    camera.forward,
    cos(radians(camera.yaw)),
    0,
    sin(radians(camera.yaw))
  );
  vec3f_norm(camera.forward);

  // Calculate right vector
  vec3f_cross(camera.right, camera.front, camera.world_up);
  vec3f_norm(camera.right);

  // Calculate up vector
  vec3f_cross(camera.up, camera.right, camera.front);
  vec3f_norm(camera.up);
}

void camera_init() {
  // Initialize field of view
  camera.fov = 50;

  // Initialize camera position
  vec3f_set(camera.pos, 0, 300, 600);

  // Initialize world_up vector
  vec3f_set(camera.world_up, 0, 1, 0);

  // Initialize camera rotation
  camera.pitch = -30;
  camera.yaw = -90;

  recalc_orientation();
}

// Move the camera in a particular direction
void camera_move(Vec3f velocity) {
  Vec3f move_forward;
  Vec3f move_right;
  Vec3f move_up;

  vec3f_copy(move_right, camera.right);
  vec3f_mag(move_right, velocity.x);

  vec3f_copy(move_up, camera.world_up);
  vec3f_mag(move_up, velocity.y);

  vec3f_copy(move_forward, camera.forward);
  vec3f_mag(move_forward, velocity.z);

  vec3f_add(camera.pos, move_right);
  vec3f_add(camera.pos, move_up);
  vec3f_add(camera.pos, move_forward);
}

// Move the camera to a given position
void camera_move_to(Vec3f pos) {
  vec3f_copy(camera.pos, pos);
}

// Rotate the camera by a given amount of degrees
void camera_rotate(Vec2f rot) {
  camera.yaw += rot.x;
  camera.pitch += rot.y;
  recalc_orientation();
}

void camera_rotate_to(Vec2f rot) {
  camera.yaw = rot.x - 90;
  camera.pitch = rot.y;
  recalc_orientation();
}

void camera_look(MVP* mvpp) {
  u16 persp_norm;

  // Initialize the projection matrix
  guPerspective(
    &mvpp->projection,
    &persp_norm,
    camera.fov,
    (float)SCREEN_W / (float)SCREEN_H,
    10,
    10000,
    1.0
  );
  gSPPerspNormalize(glistp++, persp_norm);

  // Calculate where to look
  vec3f_copy(camera.target, camera.pos);
  vec3f_add(camera.target, camera.front);

  // Initialize the model view matrix
  guLookAt(
    &mvpp->modelview,
    vec3f_unpack(camera.pos),
    vec3f_unpack(camera.target),
    vec3f_unpack(camera.up)
  );

  // Load the projection matrix into the matrix stack
  gSPMatrix(
    glistp++,
    OS_K0_TO_PHYSICAL(&(mvpp->projection)),
    G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH
  );

  // Load the model view matrix into the matrix stack
  gSPMatrix(
    glistp++,
    OS_K0_TO_PHYSICAL(&(mvpp->modelview)),
    G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH
  );
}
