#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>

// 2-dimensional vector
typedef struct {
  float x, y;
} Vec2f;

// 3-dimensional vector
typedef struct {
  float x, y, z;
} Vec3f;

// 4-dimensional vector
typedef struct {
  float x, y, z, w;
} Vec4f;

// Set values
#define vec2f_set(dst, nx, ny) { \
  (dst).x = (nx); \
  (dst).y = (ny); \
}

// Set values
#define vec3f_set(dst, nx, ny, nz) { \
  (dst).x = (nx); \
  (dst).y = (ny); \
  (dst).z = (nz); \
}

// Set values
#define vec4f_set(dst, nx, ny, nz, nw) { \
  (dst).x = (nx); \
  (dst).y = (ny); \
  (dst).z = (nz); \
  (dst).w = (nw); \
}

// Copy src to dst
#define vec2f_copy(dst, src) { \
  (dst).x = (src).x; \
  (dst).y = (src).y; \
}

// Copy src to dst
#define vec3f_copy(dst, src) { \
  (dst).x = (src).x; \
  (dst).y = (src).y; \
  (dst).z = (src).z; \
}

// Copy src to dst
#define vec4f_copy(dst, src) { \
  (dst).x = (src).x; \
  (dst).y = (src).y; \
  (dst).z = (src).z; \
  (dst).w = (src).w; \
}

// Add src to dst
#define vec2f_add(dst, src) { \
  (dst).x += (src).x; \
  (dst).y += (src).y; \
}

// Add src to dst
#define vec3f_add(dst, src) { \
  (dst).x += (src).x; \
  (dst).y += (src).y; \
  (dst).z += (src).z; \
}

// Add src to dst
#define vec4f_add(dst, src) { \
  (dst).x += (src).x; \
  (dst).y += (src).y; \
  (dst).z += (src).z; \
  (dst).w += (src).w; \
}

// Multiply dst by src
#define vec2f_mul(dst, src) { \
  (dst).x *= (src).x; \
  (dst).y *= (src).y; \
}

// Multiply dst by src
#define vec3f_mul(dst, src) { \
  (dst).x *= (src).x; \
  (dst).y *= (src).y; \
  (dst).z *= (src).z; \
}

// Multiply dst by src
#define vec4f_mul(dst, src) { \
  (dst).x *= (src).x; \
  (dst).y *= (src).y; \
  (dst).z *= (src).z; \
  (dst).w *= (src).w; \
}

// Multiply dst by a constant
#define vec2f_mag(dst, mag) { \
  (dst).x *= (mag); \
  (dst).y *= (mag); \
}

// Multiply dst by a constant
#define vec3f_mag(dst, mag) { \
  (dst).x *= (mag); \
  (dst).y *= (mag); \
  (dst).z *= (mag); \
}

// Multiply dst by a constant
#define vec4f_mag(dst, mag) { \
  (dst).x *= (mag); \
  (dst).y *= (mag); \
  (dst).z *= (mag); \
  (dst).w *= (mag); \
}

// Calculate the dot product of a and b
#define vec2f_dot(a, b) ((a).x * (b).x + (a).y * (b).y)
#define vec3f_dot(a, b) ((a).x * (b).x + (a).y * (b).y + (a).z * (b).z)
#define vec4f_dot(a, b) ((a).x * (b).x + (a).y * (b).y + (a).z * (b).z + (a).w * (b).w)

// Set dst to the cross product of a and b
#define vec3f_cross(dst, a, b) { \
  (dst).x = (a).y * (b).z - (a).z * (b).y; \
  (dst).y = (a).z * (b).x - (a).x * (b).z; \
  (dst).z = (a).x * (b).y - (a).y * (b).x; \
}

// Normalize dst in place
#define vec3f_norm(dst) { \
  float len = sqrt(((dst).x * (dst).x) + ((dst).y * (dst).y) + ((dst).z * (dst).z)); \
  (dst).x /= len; \
  (dst).y /= len; \
  (dst).z /= len; \
}

// Unpack src
#define vec2f_unpack(src) (src).x, (src).y
#define vec3f_unpack(src) (src).x, (src).y, (src).z
#define vec4f_unpack(src) (src).x, (src).y, (src).z, (src).w

#endif
