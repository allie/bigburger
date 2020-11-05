#include "timer.h"

typedef struct {
  bool vacant;
  double elapsed;
  double total;
  TimerCallback callback;
  void* user_data;
} Timer;

static Timer timers[MAX_TIMERS];
static int current_id = 0;

static int get_next_free_id() {
  bool found = timers[current_id].vacant;
  int next_id = (current_id + 1) % MAX_TIMERS;
  int i;

  if (found) {
    return current_id;
  }

  for (i = next_id; i < MAX_TIMERS; i++) {
    if (timers[i].vacant) {
      return i;
    }
  }

  for (i = 0; i < next_id; i++) {
    if (timers[i].vacant) {
      return i;
    }
  }

  // Reaching this point means no free IDs exist, and you should increase MAX_TIMERS
  assert(0);
}

int timer_run_callback(TimerCallback callback, void* user_data, double delay) {
  current_id = get_next_free_id();
  printf("id %d\n", current_id);
  timers[current_id].vacant = FALSE;
  timers[current_id].elapsed = 0;
  timers[current_id].total = delay;
  timers[current_id].callback = callback;
  timers[current_id].user_data = user_data;
  return current_id;
}

int timer_create(double duration) {
  current_id = get_next_free_id();
  timers[current_id].vacant = FALSE;
  timers[current_id].elapsed = 0;
  timers[current_id].total = duration;
  timers[current_id].callback = NULL;
  timers[current_id].user_data = NULL;
  return current_id;
}

void timer_destroy(int timer) {
  assert(timer >= 0 && timer < MAX_TIMERS);
  timers[timer].vacant = TRUE;
  timers[timer].elapsed = 0;
  timers[timer].total = 0;
  timers[timer].callback = NULL;
  timers[current_id].user_data = NULL;
  current_id = timer;
}

bool timer_is_running(int timer) {
  assert(timer >= 0 && timer < MAX_TIMERS);
  return timers[timer].elapsed < timers[timer].total;
}

void timer_init() {
  int i;
  for (i = 0; i < MAX_TIMERS; i++) {
    timers[i].vacant = TRUE;
    timers[i].elapsed = 0;
    timers[i].total = 0;
    timers[i].callback = NULL;
    timers[current_id].user_data = NULL;
  }
}

void timer_update(double dt) {
  int i;
  for (i = 0; i < MAX_TIMERS; i++) {
    if (timers[i].vacant || timers[i].elapsed >= timers[i].total) {
      continue;
    }

    timers[i].elapsed += dt;

    if (timers[i].elapsed >= timers[i].total && timers[i].callback != NULL) {
      timers[i].callback(timers[i].user_data);
      timer_destroy(i);
    }
  }
}
