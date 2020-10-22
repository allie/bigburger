#ifndef NUMBER_H
#define NUMBER_H

#include "common.h"

#define NUMBER_ALIGN_CENTRE -5000

void number_draw(int number, float x, float y);
void number_draw_0_padded(int number, int digits, float x, float y);

#endif
