#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <nusys.h>
#include "common.h"
#include "object.h"

#define SCREEN_W 320
#define SCREEN_H 240
#define SAFE_AREA_H 24
#define SAFE_AREA_V 16

#define MAX_TASKS 3
#define GLIST_LENGTH 2048

// Model view projection matrices
typedef struct {
  Mtx modelview;
  Mtx projection;
} MVP;

extern MVP mvp[MAX_TASKS];
extern Gfx glist[MAX_TASKS][GLIST_LENGTH];
extern Gfx* glistp;
extern u32 task_num;

void graphics_init_RCP();
void graphics_clear(u8 r, u8 g, u8 b);
void graphics_start_object(Object* object, bool xlu);
void graphics_start_textured_object(Object* object, bool xlu);
void graphics_end_object();
void graphics_draw_texrect(unsigned short* tex, u32 x, u32 y, u32 w, u32 h);
void graphics_start_texrect();
void graphics_end_texrect();

#define graphics_draw_object(obj, dl, xlu) { \
  graphics_start_object((obj), (xlu)); \
  gSPDisplayList(glistp++, dl); \
  graphics_end_object(); \
}

#define graphics_draw_textured_object(obj, dl, xlu) { \
  graphics_start_textured_object((obj), (xlu)); \
  gSPDisplayList(glistp++, dl); \
  graphics_end_object(); \
}

#endif
