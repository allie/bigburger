#include <nusys.h>
#include <stdarg.h>
#include <assert.h>
#include <math.h>
#include "animation.h"

static Animation* animations[MAX_ANIMATIONS];
static int next_id = 0;

// Preset easing functions
// Implementations are defined in macros for code integrity, as the same code is executed for each
// variant of each easing function, but data types differ.

// Generates easing function definitions, to make adding new easing functions much quicker
#define gen_ease_func(name) \
	static double ease_##name##_f64(double t, double d, double s, double c) { ease_##name(t, d, s, c) } \
	static float ease_##name##_f32(double t, double d, float s, float c) { ease_##name(t, d, s, c) } \
	static int ease_##name##_s32(double t, double d, int s, int c) { ease_##name(t, d, s, c) } \
	static long long ease_##name##_s64(double t, double d, long long s, long long c) { ease_##name(t, d, s, c) }

// Linear
#define ease_linear(time, duration, start, change) \
	return change * time / duration + start;

gen_ease_func(linear);

// Quadratic in
#define ease_quad_in(time, duration, start, change) \
	time /= duration; \
	return change * time * time + start;

gen_ease_func(quad_in);

// Quadratic out
#define ease_quad_out(time, duration, start, change) \
	time /= duration; \
	return -change * time * (time - 2) + start;

gen_ease_func(quad_out);

// Quadratic in/out
#define ease_quad_in_out(time, duration, start, change) \
	time /= duration / 2; \
	if (time < 1) return change / 2 * time * time + start; \
	time--; \
	return -change / 2 * (time * (time - 2) - 1) + start;

gen_ease_func(quad_in_out);

// Cubic in
#define ease_cubic_in(time, duration, start, change) \
	time /= duration; \
	return change * time * time * time + start;

gen_ease_func(cubic_in);

// Cubic out
#define ease_cubic_out(time, duration, start, change) \
	time /= duration; \
	time--; \
	return change * (time * time * time + 1) + start;

gen_ease_func(cubic_out);

// Cubic in/out
#define ease_cubic_in_out(time, duration, start, change) \
	time /= duration / 2; \
	if (time < 1) return change / 2 * time * time * time + start; \
	time -= 2; \
	return change / 2 * (time * time * time + 2) + start;

gen_ease_func(cubic_in_out);

// Quartic in
#define ease_quart_in(time, duration, start, change) \
	time /= duration; \
	return change * time * time * time * time + start;

gen_ease_func(quart_in);

// Quartic out
#define ease_quart_out(time, duration, start, change) \
	time /= duration; \
	time--; \
	return -change * (time * time * time * time - 1) + start;

gen_ease_func(quart_out);

// Quartic in/out
#define ease_quart_in_out(time, duration, start, change) \
	time /= duration / 2; \
	if (time < 1) return change / 2 * time * time * time * time + start; \
	time -= 2; \
	return -change / 2 * (time * time * time * time - 2) + start;

gen_ease_func(quart_in_out);

// Quintic in
#define ease_quint_in(time, duration, start, change) \
	time /= duration; \
	return change * time * time * time * time * time + start;

gen_ease_func(quint_in);

// Quintic out
#define ease_quint_out(time, duration, start, change) \
	time /= duration; \
	time--; \
	return change * (time * time * time * time * time + 1) + start;

gen_ease_func(quint_out);

// Quintic in/out
#define ease_quint_in_out(time, duration, start, change) \
	time /= duration / 2; \
	if (time < 1) return change / 2 * time * time * time * time * time + start; \
	time -= 2; \
	return change / 2 * (time * time * time * time * time + 2) + start;

gen_ease_func(quint_in_out);

// Sinusoidal in
#define ease_sin_in(time, duration, start, change) \
	return -change * cos(time / duration * (M_PI / 2)) + change + start;

gen_ease_func(sin_in);

// Sinusoidal out
#define ease_sin_out(time, duration, start, change) \
	return change * sin(time / duration * (M_PI / 2)) + start;

gen_ease_func(sin_out);

// Sinusoidal in/out
#define ease_sin_in_out(time, duration, start, change) \
	return -change / 2 * (cos(M_PI * time / duration) - 1) + start;

gen_ease_func(sin_in_out);

// Exponential in
#define ease_exp_in(time, duration, start, change) \
	return change * pow(2, 10 * (time / duration - 1)) + start;

gen_ease_func(exp_in);

// Exponential out
#define ease_exp_out(time, duration, start, change) \
	return change * (-pow(2, -10 * time / duration) + 1) + start;

gen_ease_func(exp_out);

// Exponential in/out
#define ease_exp_in_out(time, duration, start, change) \
	time /= duration  / 2; \
	if (time < 1) return change / 2 * pow(2, 10 * (time - 1)) + start; \
	time--; \
	return change / 2 * (-pow(2, -10 * time) + 2 ) + start;

gen_ease_func(exp_in_out);

// Circular in
#define ease_circ_in(time, duration, start, change) \
	time /= duration; \
	return -change * (sqrt(1 - time * time) - 1) + start;

gen_ease_func(circ_in);

// Circular out
#define ease_circ_out(time, duration, start, change) \
	time /= duration; \
	time--; \
	return change * sqrt(1 - time * time) + start;

gen_ease_func(circ_out);

// Circular in/out
#define ease_circ_in_out(time, duration, start, change) \
	time /= duration / 2; \
	if (time < 1) return -change / 2 * (sqrt(1 - time * time) - 1) + start; \
	time -= 2; \
	return change / 2 * (sqrt(1 - time * time) + 1) + start;

gen_ease_func(circ_in_out);

// Get a free animation ID. If -1 is returned, increase MAX_ANIMATIONS
static int get_free_id() {
	int i;

	for (i = next_id; i < MAX_ANIMATIONS; i++) {
		if (animations[i] == NULL) {
			next_id = (i + 1) % MAX_ANIMATIONS;
			return i;
		}
	}

	for (i = 0; i < next_id; i++) {
		if (animations[i] == NULL) {
			next_id = (i + 1) % MAX_ANIMATIONS;
			return i;
		}
	}

	return -1;
}

// Initialize the animation system, destroying any existing animations and resetting the next ID
void animation_init() {
	int i = 0;

	for (i = 0; i < MAX_ANIMATIONS; i++) {
		animation_destroy(i);
	}

	next_id = 0;
}

// Update all animations within the system for a given period of time
void animation_update(double dt) {
	int a, v, t;

	for (a = 0; a < MAX_ANIMATIONS; a++) {
		Animation* anim = animations[a];

		if (anim == NULL || !anim->status.playing) {
			continue;
		}

		// Update the timer
		anim->status.elapsed += dt;

		// Handle reaching the end of the timeline
		if (anim->status.elapsed >= anim->status.duration) {
			anim->status.elapsed -= anim->status.duration;

			// Stop playing the animation if there are no more loops left
			if (anim->loop_count == 0) {
				anim->status.playing = 0;
			}
			// Otherwise, if this isn't an infinite loop, decrement the loop counter
			else if (anim->loop_count > -1) {
				anim->loop_count--;
			}
		}

		for (v = 0; v < anim->value_count; v++) {
			AnimatedValue* value = &(anim->values[v]);
			Tween* current_tween;
			double elapsed, progress;

			// Determine which tween each animated value is on based on the current time
			// TODO: optimize this, no need to iterate through every single update.
			for (t = 0; t < value->tween_count; t++) {
				if (anim->status.elapsed < value->tweens[t].start_time + value->tweens[t].duration) {
					value->current_tween = t;
					break;
				}
			}

			// Update each animated value with the easing function for its current tween
			current_tween = &(value->tweens[value->current_tween]);
			elapsed = anim->status.elapsed - current_tween->start_time;

			if (elapsed >= current_tween->duration) {
				switch (value->data_type) {
					case ANIM_F64:
						*(value->ptr._f64) = current_tween->end._f64;
						break;

					case ANIM_F32:
						*(value->ptr._f32) = current_tween->end._f32;
						break;

					case ANIM_S32:
						*(value->ptr._s32) = current_tween->end._s32;
						break;

					case ANIM_S64:
						*(value->ptr._s64) = current_tween->end._s64;
						break;

					default:
						break;
				}
				continue;
			}

			progress = elapsed / current_tween->duration;
			progress = progress > 1.0 ? 1.0 : progress;

			switch (value->data_type) {
				case ANIM_F64: {
					*(value->ptr._f64) = current_tween->easing_func._f64(
						anim->status.elapsed - current_tween->start_time,
						current_tween->duration,
						current_tween->start._f64,
						current_tween->end._f64 - current_tween->start._f64
					);
					break;
				}

				case ANIM_F32: {
					*(value->ptr._f32) = current_tween->easing_func._f32(
						anim->status.elapsed - current_tween->start_time,
						current_tween->duration,
						current_tween->start._f32,
						current_tween->end._f32 - current_tween->start._f32
					);
					break;
				}

				case ANIM_S32: {
					*(value->ptr._s32) = current_tween->easing_func._s32(
						anim->status.elapsed - current_tween->start_time,
						current_tween->duration,
						current_tween->start._s32,
						current_tween->end._s32 - current_tween->start._s32
					);
					break;
				}

				case ANIM_S64: {
					*(value->ptr._s64) = current_tween->easing_func._s64(
						anim->status.elapsed - current_tween->start_time,
						current_tween->duration,
						current_tween->start._s64,
						current_tween->end._s64 - current_tween->start._s64
					);
					break;
				}

				default:
					break;
			}
		}

		// If this animation finished playing on this update, and it has no more remaining loops,
		// ensure that all values are set to their final values
		if (anim->loop_count == 0 && !anim->status.playing) {
			for (v = 0; v < anim->value_count; v++) {
				AnimatedValue* value = &(anim->values[v]);

				switch (value->data_type) {
					case ANIM_F64:
						*(value->ptr._f64) = value->tweens[value->tween_count - 1].end._f64;
						break;

					case ANIM_F32:
						*(value->ptr._f32) = value->tweens[value->tween_count - 1].end._f32;
						break;

					case ANIM_S32:
						*(value->ptr._s32) = value->tweens[value->tween_count - 1].end._s32;
						break;

					case ANIM_S64:
						*(value->ptr._s64) = value->tweens[value->tween_count - 1].end._s64;
						break;

					default:
						break;
				}
			}

			// And, if it's set to be destroyed after it finishes playing, destroy it now
			if (anim->destroy_after) {
				animation_destroy(a);
			}
		}
	}
}

// Initialize an animated value
AnimatedValue animate_value(unsigned int tween_count, int data_type, ...) {
	int i = 0;
	double elapsed = 0;
	va_list v;
	AnimatedValue anim;
	
	assert(data_type == ANIM_F64 || data_type == ANIM_F32 || data_type == ANIM_S32);

	anim.data_type = data_type;
	anim.tween_count = tween_count;
	anim.current_tween = 0;
	anim.tweens = (Tween*)malloc(sizeof(Tween) * tween_count);

	va_start(v, data_type);

// Macro for handling preset easing function cases when setting the easing function, to avoid redudant and tedious code
#define preset_easing_func_cases(suffix) \
	case EASE_LINEAR: anim.tweens[i].easing_func._##suffix = ease_linear_##suffix; break; \
	case EASE_QUAD_IN: anim.tweens[i].easing_func._##suffix = ease_quad_in_##suffix; break; \
	case EASE_QUAD_OUT: anim.tweens[i].easing_func._##suffix = ease_quad_out_##suffix; break; \
	case EASE_QUAD_IN_OUT: anim.tweens[i].easing_func._##suffix = ease_quad_in_out_##suffix; break; \
	case EASE_CUBIC_IN: anim.tweens[i].easing_func._##suffix = ease_cubic_in_##suffix; break; \
	case EASE_CUBIC_OUT: anim.tweens[i].easing_func._##suffix = ease_cubic_out_##suffix; break; \
	case EASE_CUBIC_IN_OUT: anim.tweens[i].easing_func._##suffix = ease_cubic_in_out_##suffix; break; \
	case EASE_QUART_IN: anim.tweens[i].easing_func._##suffix = ease_quart_in_##suffix; break; \
	case EASE_QUART_OUT: anim.tweens[i].easing_func._##suffix = ease_quart_out_##suffix; break; \
	case EASE_QUART_IN_OUT: anim.tweens[i].easing_func._##suffix = ease_quart_in_out_##suffix; break; \
	case EASE_QUINT_IN: anim.tweens[i].easing_func._##suffix = ease_quint_in_##suffix; break; \
	case EASE_QUINT_OUT: anim.tweens[i].easing_func._##suffix = ease_quint_out_##suffix; break; \
	case EASE_QUINT_IN_OUT: anim.tweens[i].easing_func._##suffix = ease_quint_in_out_##suffix; break; \
	case EASE_SIN_IN: anim.tweens[i].easing_func._##suffix = ease_sin_in_##suffix; break; \
	case EASE_SIN_OUT: anim.tweens[i].easing_func._##suffix = ease_sin_out_##suffix; break; \
	case EASE_SIN_IN_OUT: anim.tweens[i].easing_func._##suffix = ease_sin_in_out_##suffix; break; \
	case EASE_EXP_IN: anim.tweens[i].easing_func._##suffix = ease_exp_in_##suffix; break; \
	case EASE_EXP_OUT: anim.tweens[i].easing_func._##suffix = ease_exp_out_##suffix; break; \
	case EASE_EXP_IN_OUT: anim.tweens[i].easing_func._##suffix = ease_exp_in_out_##suffix; break; \
	case EASE_CIRC_IN: anim.tweens[i].easing_func._##suffix = ease_circ_in_##suffix; break; \
	case EASE_CIRC_OUT: anim.tweens[i].easing_func._##suffix = ease_circ_out_##suffix; break; \
	case EASE_CIRC_IN_OUT: anim.tweens[i].easing_func._##suffix = ease_circ_in_out_##suffix; break; \
	default: anim.tweens[i].easing_func._##suffix = ease_linear_##suffix; break;

	// The first item in the va list is a pointer to the value to be animated
	switch (data_type) {
		case ANIM_F64: {
			anim.ptr._f64 = va_arg(v, double*);

			for (i = 0; i < tween_count; i++) {
				int easing_type;
				anim.tweens[i].duration = va_arg(v, double);
				anim.tweens[i].start._f64 = va_arg(v, double);
				anim.tweens[i].end._f64 = va_arg(v, double);
				easing_type = va_arg(v, int);

				switch (easing_type) {
					preset_easing_func_cases(f64);
					case EASE_CUSTOM:
						anim.tweens[i].easing_func._f64 = va_arg(v, EasingFuncF64);
						break;
				}
			}

			break;
		}

		case ANIM_F32: {
			anim.ptr._f32 = va_arg(v, float*);

			for (i = 0; i < tween_count; i++) {
				int easing_type;
				anim.tweens[i].duration = va_arg(v, double);
				anim.tweens[i].start._f32 = va_arg(v, double);
				anim.tweens[i].end._f32 = va_arg(v, double);
				easing_type = va_arg(v, int);

				switch (easing_type) {
					preset_easing_func_cases(f32);
					case EASE_CUSTOM:
						anim.tweens[i].easing_func._f32 = va_arg(v, EasingFuncF32);
						break;
				}
			}

			break;
		}

		case ANIM_S32: {
			anim.ptr._s32 = va_arg(v, int*);

			for (i = 0; i < tween_count; i++) {
				int easing_type;
				anim.tweens[i].duration = va_arg(v, double);
				anim.tweens[i].start._s32 = va_arg(v, int);
				anim.tweens[i].end._s32 = va_arg(v, int);
				easing_type = va_arg(v, int);

				switch (easing_type) {
					preset_easing_func_cases(s32);
					case EASE_CUSTOM:
						anim.tweens[i].easing_func._s32 = va_arg(v, EasingFuncS32);
						break;
				}
			}

			break;
		}

		case ANIM_S64: {
			anim.ptr._s64 = va_arg(v, long long*);

			for (i = 0; i < tween_count; i++) {
				int easing_type;
				anim.tweens[i].duration = va_arg(v, double);
				anim.tweens[i].start._s64 = va_arg(v, long long);
				anim.tweens[i].end._s64 = va_arg(v, long long);
				easing_type = va_arg(v, long long);

				switch (easing_type) {
					preset_easing_func_cases(s64);
					case EASE_CUSTOM:
						anim.tweens[i].easing_func._s64 = va_arg(v, EasingFuncS64);
						break;
				}
			}

			break;
		}

		default: {
			break;
		}
	}

	va_end(v);

	// Fill in starting timestamps for each tween
	for (i = 0; i < anim.tween_count; i++) {
		anim.tweens[i].start_time = elapsed;
		elapsed += anim.tweens[i].duration;
	}

	return anim;
}

// Create a new animation
int animation_create(int loop_count, int destroy_after, unsigned int value_count, ...) {
	int i = 0;
	int t = 0;
	va_list v;

	int id = get_free_id();
	assert(id > -1);

	animations[id] = (Animation*)malloc(sizeof(Animation));
	animations[id]->loop_count = loop_count;
	animations[id]->value_count = value_count;
	animations[id]->destroy_after = destroy_after;
	animations[id]->values = (AnimatedValue*)malloc(sizeof(AnimatedValue) * value_count);
	animations[id]->status.elapsed = 0;
	animations[id]->status.playing = 0;
	
	va_start(v, value_count);

	for (i = 0; i < value_count; i++) {
		animations[id]->values[i] = va_arg(v, AnimatedValue);
	}

	va_end(v);

	// Calculate the duration of the longest animated value, and use that as the total
	// duration for this animation as a whole
	for (i = 0; i < value_count; i++) {
		double duration = 0;

		for (t = 0; t < animations[id]->values[i].tween_count; t++) {
			duration += animations[id]->values[i].tweens[t].duration;
		}

		if (duration > animations[id]->status.duration) {
			animations[id]->status.duration = duration;
		}
	}

	return id;
}

// Destroy an existing animation
void animation_destroy(int id) {
	int i;

	if (animations[id] == NULL) {
		return;
	}

	assert(id > -1 && id < MAX_ANIMATIONS);

	for (i = 0; i < animations[id]->value_count; i++) {
		free(animations[id]->values[i].tweens);
	}

	free(animations[id]->values);
	free(animations[id]);
	animations[id] = NULL;
}

// Destroy all animations
void animation_destroy_all() {
	int i;

	for (i = 0; i < MAX_ANIMATIONS; i++) {
		if (animations[i] == NULL) {
			continue;
		}
		animation_destroy(i);
	}
}

void animation_play(int id) {
	assert(id > -1 && id < MAX_ANIMATIONS);

	if (animations[id] == NULL) {
		return;
	}

	animations[id]->status.playing = 1;
}

void animation_pause(int id) {
	assert(id > -1 && id < MAX_ANIMATIONS);

	if (animations[id] == NULL) {
		return;
	}

	animations[id]->status.playing = 0;
}

void animation_stop(int id) {
	assert(id > -1 && id < MAX_ANIMATIONS);

	if (animations[id] == NULL) {
		return;
	}

	animations[id]->status.playing = 0;
	animations[id]->status.elapsed = 0;
}

AnimationStatus animation_status(int id) {
	AnimationStatus ret = { 0, 0, 0 };

	assert(id > -1 && id < MAX_ANIMATIONS);

	if (animations[id] == NULL) {
		return ret;
	}

	return animations[id]->status;
}
