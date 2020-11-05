#ifndef TIMER_H
#define TIMER_H

#include "common.h"

#define MAX_TIMERS 20

typedef void (*TimerCallback)(void* user_data);

int timer_run_callback(TimerCallback callback, void* user_data, double delay);
int timer_create(double duration);
void timer_destroy(int timer);
bool timer_is_running(int timer);
void timer_init();
void timer_update(double dt);

#endif
