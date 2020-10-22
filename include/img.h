#ifndef IMAGE_H
#define IMAGE_H

#include "common.h"

#define TMEM_SIZE 4096

void img_start();
void img_end();
// TODO: expand this with more options than just position
// void img_draw(Img img, float x, float y);
void _img_draw(void* img, float x, float y);

// Helper macro to call img_draw more easily without casting to void*
#define img_draw(img_data, x, y) _img_draw((void*)(&(img_data)), (x), (y))

#endif
