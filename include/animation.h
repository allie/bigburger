#ifndef ANIMATION_H
#define ANIMATION_H

#define MAX_ANIMATIONS 100

// Data types of values that can be animated
enum {
  ANIM_DOUBLE,
  ANIM_FLOAT,
  ANIM_INT
};

// Easing function types
enum {
  EASE_LINEAR,
  EASE_QUAD_IN,
  EASE_QUAD_OUT,
  EASE_QUAD_IN_OUT,
  EASE_CUBIC_IN,
  EASE_CUBIC_OUT,
  EASE_CUBIC_IN_OUT,
  EASE_QUART_IN,
  EASE_QUART_OUT,
  EASE_QUART_IN_OUT,
  EASE_QUINT_IN,
  EASE_QUINT_OUT,
  EASE_QUINT_IN_OUT,
  EASE_SIN_IN,
  EASE_SIN_OUT,
  EASE_SIN_IN_OUT,
  EASE_EXP_IN,
  EASE_EXP_OUT,
  EASE_EXP_IN_OUT,
  EASE_CIRC_IN,
  EASE_CIRC_OUT,
  EASE_CIRC_IN_OUT,
  EASE_CUSTOM
};

// Easing function pointer typedefs
typedef double (*EasingFuncD)(double time, double duration, double start, double change);
typedef float (*EasingFuncF)(double time, double duration, float start, float change);
typedef int (*EasingFuncI)(double time, double duration, int start, int change);

// Represents a keyframe and the necessary information about tweening to the next keyframe
typedef struct {
  double start_time;
  double duration;
  union {
    double d;
    float f;
    int i;
  } start;
  union {
    double d;
    float f;
    int i;
  } end;
  union {
    EasingFuncD d;
    EasingFuncF f;
    EasingFuncI i;
  } easing_func;
} Tween;

// Represents a timeline consisting of one or more tweens to animate a single value
typedef struct {
  int data_type;
  unsigned int current_tween;
  union {
    double* d;
    float* f;
    int* i;
  } ptr;
  unsigned int tween_count;
  Tween* tweens;
} AnimatedValue;

// Status information for an animation
typedef struct {
  double duration;
  double elapsed;
  int playing;
} AnimationStatus;

// Represents one or more animated values that collectively make a whole animation
typedef struct {
  int loop_count;
  unsigned int value_count;
  AnimationStatus status;
  AnimatedValue* values;
} Animation;

// Initialize the animation system
void animation_init();

// Update all animations managed by the system
void animation_update(double dt);

// Initialize an animated value structure
// Only should be used within animation_create calls, you shouldn't ever need to directly
// initialize and work with an AnimatedValue structure.
AnimatedValue animate_value(unsigned int tween_count, int data_type, ...);

// Create a new animation consisting of one or more animated values
// Animations are automatically updated internally
int animation_create(int loop_count, unsigned int value_count, ...);

// Destroy an animation, freeing all its allocating memory and freeing up an animation slot
void animation_destroy(int id);

// Command an animation to play by its ID
void animation_play(int id);

// Command an animation to pause by its ID
void animation_pause(int id);

// Command an animation to stop (resetting the playhead to 0) by its ID
void animation_stop(int id);

// Get a copy of an animation's status structure
AnimationStatus animation_status(int id);

// Preset easing functions
// Linear
double ease_linear_d(double time, double duration, double start, double change);
float ease_linear_f(double time, double duration, float start, float change);
int ease_linear_i(double time, double duration, int start, int change);
// Quadratic in
double ease_quad_in_d(double time, double duration, double start, double change);
float ease_quad_in_f(double time, double duration, float start, float change);
int ease_quad_in_i(double time, double duration, int start, int change);
// Quadratic out
double ease_quad_out_d(double time, double duration, double start, double change);
float ease_quad_out_f(double time, double duration, float start, float change);
int ease_quad_out_i(double time, double duration, int start, int change);
// Quadratic in/out
double ease_quad_in_out_d(double time, double duration, double start, double change);
float ease_quad_in_out_f(double time, double duration, float start, float change);
int ease_quad_in_out_i(double time, double duration, int start, int change);
// Cubic in
double ease_cubic_in_d(double time, double duration, double start, double change);
float ease_cubic_in_f(double time, double duration, float start, float change);
int ease_cubic_in_i(double time, double duration, int start, int change);
// Cubic out
double ease_cubic_out_d(double time, double duration, double start, double change);
float ease_cubic_out_f(double time, double duration, float start, float change);
int ease_cubic_out_i(double time, double duration, int start, int change);
// Cubic in/out
double ease_cubic_in_out_d(double time, double duration, double start, double change);
float ease_cubic_in_out_f(double time, double duration, float start, float change);
int ease_cubic_in_out_i(double time, double duration, int start, int change);
// Quartic in
double ease_quart_in_d(double time, double duration, double start, double change);
float ease_quart_in_f(double time, double duration, float start, float change);
int ease_quart_in_i(double time, double duration, int start, int change);
// Quartic out
double ease_quart_out_d(double time, double duration, double start, double change);
float ease_quart_out_f(double time, double duration, float start, float change);
int ease_quart_out_i(double time, double duration, int start, int change);
// Quartic in/out
double ease_quart_in_out_d(double time, double duration, double start, double change);
float ease_quart_in_out_f(double time, double duration, float start, float change);
int ease_quart_in_out_i(double time, double duration, int start, int change);
// Quintic in
double ease_quint_in_d(double time, double duration, double start, double change);
float ease_quint_in_f(double time, double duration, float start, float change);
int ease_quint_in_i(double time, double duration, int start, int change);
// Quintic out
double ease_quint_out_d(double time, double duration, double start, double change);
float ease_quint_out_f(double time, double duration, float start, float change);
int ease_quint_out_i(double time, double duration, int start, int change);
// Quintic in/out
double ease_quint_in_out_d(double time, double duration, double start, double change);
float ease_quint_in_out_f(double time, double duration, float start, float change);
int ease_quint_in_out_i(double time, double duration, int start, int change);
// Sinusoidal in
double ease_sin_in_d(double time, double duration, double start, double change);
float ease_sin_in_f(double time, double duration, float start, float change);
int ease_sin_in_i(double time, double duration, int start, int change);
// Sinusoidal out
double ease_sin_out_d(double time, double duration, double start, double change);
float ease_sin_out_f(double time, double duration, float start, float change);
int ease_sin_out_i(double time, double duration, int start, int change);
// Sinusoidal in/out
double ease_sin_in_out_d(double time, double duration, double start, double change);
float ease_sin_in_out_f(double time, double duration, float start, float change);
int ease_sin_in_out_i(double time, double duration, int start, int change);
// Exponential in
double ease_exp_in_d(double time, double duration, double start, double change);
float ease_exp_in_f(double time, double duration, float start, float change);
int ease_exp_in_i(double time, double duration, int start, int change);
// Exponential out
double ease_exp_out_d(double time, double duration, double start, double change);
float ease_exp_out_f(double time, double duration, float start, float change);
int ease_exp_out_i(double time, double duration, int start, int change);
// Exponential in/out
double ease_exp_in_out_d(double time, double duration, double start, double change);
float ease_exp_in_out_f(double time, double duration, float start, float change);
int ease_exp_in_out_i(double time, double duration, int start, int change);
// Circular in
double ease_circ_in_d(double time, double duration, double start, double change);
float ease_circ_in_f(double time, double duration, float start, float change);
int ease_circ_in_i(double time, double duration, int start, int change);
// Circular out
double ease_circ_out_d(double time, double duration, double start, double change);
float ease_circ_out_f(double time, double duration, float start, float change);
int ease_circ_out_i(double time, double duration, int start, int change);
// Circular in/out
double ease_circ_in_out_d(double time, double duration, double start, double change);
float ease_circ_in_out_f(double time, double duration, float start, float change);
int ease_circ_in_out_i(double time, double duration, int start, int change);

#endif