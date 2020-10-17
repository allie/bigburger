#include "plane.h"

// Construct a plane from 3 points on the plane
Plane plane_from_points(Vec3f p1, Vec3f p2, Vec3f p3) {
  Plane plane;
  Vec3f dp1p2, dp1p3;

  // Calculate p2 - p1
  dp1p2.x = p2.x - p1.x;
  dp1p2.y = p2.y - p1.y;
  dp1p2.z = p2.z - p1.z;

  // Calculate p3 - p1
  dp1p3.x = p3.x - p1.x;
  dp1p3.y = p3.y - p1.y;
  dp1p3.z = p3.z - p1.z;

  // Calculate unit normal N
  vec3f_cross(plane.n, dp1p2, dp1p3);
  vec3f_norm(plane.n);

  // Calculate distance from the origin D
  plane.d = -(vec3f_dot(plane.n, p1));  

  return plane;
}
