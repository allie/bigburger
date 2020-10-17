#ifndef PLANE_H
#define PLANE_H

#include "vector.h"

typedef struct {
  Vec3f n; // Unit normal
  float d; // Distance from the plane to the origin
} Plane;

// Construct a plane from 3 points on the plane
Plane plane_from_points(Vec3f p1, Vec3f p2, Vec3f p3);

// Find the closest distance from a plane to a point
#define plane_distance_to_point(plane, p) (vec3f_dot((plane).n, (p)) + (plane).d)

#endif
