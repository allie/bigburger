#ifndef ANIMATION_H
#define ANIMATION_H

#define MAX_ANIMATIONS 100

#include <ultra64.h>

// Data types of values that can be animated
enum AnimDataType {
  ANIM_F64,
  ANIM_F32,
  ANIM_S32,
  ANIM_S64
};

// Easing function types
enum EasingFuncType {
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
typedef double (*EasingFuncF64)(double time, double duration, double start, double change);
typedef float (*EasingFuncF32)(double time, double duration, float start, float change);
typedef int (*EasingFuncS32)(double time, double duration, int start, int change);
typedef long long (*EasingFuncS64)(double time, double duration, long long start, long long change);

// Represents a keyframe and the necessary information about tweening to the next keyframe
typedef struct {
  double start_time;
  double duration;
  union {
    double _f64;
    float _f32;
    int _s32;
    long long _s64;
  } start;
  union {
    double _f64;
    float _f32;
    int _s32;
    long long _s64;
  } end;
  union {
    EasingFuncF64 _f64;
    EasingFuncF32 _f32;
    EasingFuncS32 _s32;
    EasingFuncS64 _s64;
  } easing_func;
} Tween;

// Represents a timeline consisting of one or more tweens to animate a single value
typedef struct {
  int data_type;
  unsigned int current_tween;
  union {
    double* _f64;
    float* _f32;
    int* _s32;
    long long* _s64;
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
  int destroy_after;
  AnimationStatus status;
  AnimatedValue* values;
} Animation;

// Initialize the animation system
void animation_init();

// Update all animations managed by the system
void animation_update(double dt);

/*
Initialize an animated value structure.

Only should be used within animation_create calls, you shouldn't ever need to directly
initialize and work with an AnimatedValue structure.

Parameters:

tween_count:      Number of tweens in the timeline
data_type:        The data type to be animated. See AnimDataType enum for possible values

The first variadic argument should be a pointer to the value to be animated.
Following that, data for each tween should be specified in this format:

duration, start_val, end_val, easing_func_type, [easing_func_ptr,]

duration:         The length of time this tween should span
start_val:        The starting value for this tween
end_val:          The ending value for this tween
easing_func_type: The type of easing function to use. See EasingFuncType enum for possible values.
easing_func_ptr:  This argument should be omitted unless using EASE_CUSTOM, in which case you should
                  pass a pointer to your custom easing function. Custom easing functions should be of
                  the following form:
                  T my_easing_func(double time, double duration, T start, T change)
                  where T is the same data type as the value that is being animated.

Example:

animate_value(
  2, ANIM_F64, &x,
  0.5, 0.0, 100.0, EASE_QUAD_IN_OUT,
  0.5, 100.0, 0.0, EASE_QUAD_IN_OUT
);

This animate_value call would set up an AnimatedValue pointing to a double value called x
with 2 tweens. The total duration would be 1 second, and the value would go from 0.0 to 100.0
and back, with quadratic easing in and out for each tween.
*/
AnimatedValue animate_value(unsigned int tween_count, int data_type, ...);

/*
Create a new animation consisting of one or more animated values.
Animations are automatically updated internally.

Parameters:

loop_count:       Number of times this animation should be repeated. Pass -1 for an infinite loop
destroy_after:    Whether or not this animation should be destroyed after it is finished playing
value_count:      Number of values being animated in this animation

Arguments should be followed by AnimatedValues created by calling animate_value.

Example:

int anim = animation_create(
  0, 1, 2,
  animate_value(
    2, ANIM_F64, &x,
    0.5, 0.0, 100.0, EASE_QUAD_IN_OUT,
    0.5, 100.0, 0.0, EASE_QUAD_IN_OUT
  ),
  animate_value(
    2, ANIM_F64, &y,
    0.5, 100.0, 0.0, EASE_QUAD_IN_OUT,
    0.5, 0.0, 100.0, EASE_QUAD_IN_OUT
  )
);

This animation_create call would add an animation to the system which animates two double values
called x and y. The point would animate from (0.0, 100.0) to (100.0, 0.0) and back over a duration of
1 second. Each tween uses quadratic easing in and out.
*/
int animation_create(int loop_count, int destroy_after, unsigned int value_count, ...);

// Destroy an animation, freeing all its allocating memory and freeing up an animation slot
void animation_destroy(int id);

// Destroy all animations within the system
void animation_destroy_all();

// Command an animation to play by its ID
void animation_play(int id);

// Command an animation to pause by its ID
void animation_pause(int id);

// Command an animation to stop (resetting the playhead to 0) by its ID
void animation_stop(int id);

// Get a copy of an animation's status structure
AnimationStatus animation_status(int id);

#endif