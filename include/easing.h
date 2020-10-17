#ifndef EASING_H
#define EASING_H

typedef struct {
  double timer;
  double duration;
  float min;
  float max;
  float val;
  float (*func)(double x, float min, float max);
} EasingF;

typedef struct {
  double timer;
  double duration;
  double min;
  double max;
  double val;
  double (*func)(double x, double min, double max);
} EasingD;

typedef struct {
  double timer;
  double duration;
  int min;
  int max;
  int val;
  int (*func)(double x, int min, int max);
} EasingI;

// Initialize an Easing struct
#define easing_init(easing, _duration, _min, _max, _func) { \
  (easing).timer = 0; \
  (easing).duration = (_duration); \
  (easing).min = (_min); \
  (easing).max = (_max); \
  (easing).val = (_min); \
  (easing).func = (_func); \
}

#define easing_reset(easing) { \
  (easing).timer = 0; \
  (easing).val = (easing).min;
}

// Update an Easing struct with float values
#define easing_update(easing, dt) { \
  (easing).timer += (dt); \
  (easing).timer = (easing).timer > (easing).duration ? (easing).duration : (easing).timer; \
  (easing).val = (easing).func((easing).timer / (easing).duration, (easing).min, (easing).max); \
}

// Linear interpolation between two floats
float easing_linear_f(double x, float min, float max);

// Linear interpolation between two doubles
double easing_linear_d(double x, double min, double max);

// Linear interpolation between two ints
int easing_linear_i(double x, int min, int max);

#maxif
