#include "number.h"
#include "graphics.h"
#include "img.h"

#include "textures/num_0.h"
#include "textures/num_1.h"
#include "textures/num_2.h"
#include "textures/num_3.h"
#include "textures/num_4.h"
#include "textures/num_5.h"
#include "textures/num_6.h"
#include "textures/num_7.h"
#include "textures/num_8.h"
#include "textures/num_9.h"

#define MAX_DIGITS 19

static u8 digits[MAX_DIGITS];

void number_draw(int number, float x, float y) {
  float curr_x = x;
  int digit = MAX_DIGITS - 1;
  float width = 0;
  int i;

  while (number > 0) {
    int curr_digit = number % 10;
    digits[digit--] = curr_digit;
    number /= 10;
    switch (curr_digit) {
      case 0: width += num_0_img.width; break;
      case 1: width += num_1_img.width; break;
      case 2: width += num_2_img.width; break;
      case 3: width += num_3_img.width; break;
      case 4: width += num_4_img.width; break;
      case 5: width += num_5_img.width; break;
      case 6: width += num_6_img.width; break;
      case 7: width += num_7_img.width; break;
      case 8: width += num_8_img.width; break;
      case 9: width += num_9_img.width; break;
      default: break;
    }
  }

  if (x == NUMBER_ALIGN_CENTRE) {
    curr_x = (int)(SCREEN_W / 2 - width / 2);
  }

  for (i = digit + 1; i < MAX_DIGITS; i++) {
    switch (digits[i]) {
      case 0: img_draw(num_0_img, curr_x, y); curr_x += num_0_img.width; break;
      case 1: img_draw(num_1_img, curr_x, y); curr_x += num_1_img.width; break;
      case 2: img_draw(num_2_img, curr_x, y); curr_x += num_2_img.width; break;
      case 3: img_draw(num_3_img, curr_x, y); curr_x += num_3_img.width; break;
      case 4: img_draw(num_4_img, curr_x, y); curr_x += num_4_img.width; break;
      case 5: img_draw(num_5_img, curr_x, y); curr_x += num_5_img.width; break;
      case 6: img_draw(num_6_img, curr_x, y); curr_x += num_6_img.width; break;
      case 7: img_draw(num_7_img, curr_x, y); curr_x += num_7_img.width; break;
      case 8: img_draw(num_8_img, curr_x, y); curr_x += num_8_img.width; break;
      case 9: img_draw(num_9_img, curr_x, y); curr_x += num_9_img.width; break;
      default: break;
    }
  }
}

void number_draw_0_padded(int number, int num_digits, float x, float y) {
  float curr_x = x;
  int real_num_digits = 0;
  int digit = MAX_DIGITS - 1;
  float width = 0;
  int i;

  while (number > 0) {
    int curr_digit = number % 10;
    digits[digit--] = curr_digit;
    number /= 10;
    real_num_digits++;
    switch (curr_digit) {
      case 0: width += num_0_img.width; break;
      case 1: width += num_1_img.width; break;
      case 2: width += num_2_img.width; break;
      case 3: width += num_3_img.width; break;
      case 4: width += num_4_img.width; break;
      case 5: width += num_5_img.width; break;
      case 6: width += num_6_img.width; break;
      case 7: width += num_7_img.width; break;
      case 8: width += num_8_img.width; break;
      case 9: width += num_9_img.width; break;
      default: break;
    }
  }
  
  if (x == NUMBER_ALIGN_CENTRE) {
    for (i = 0; i < num_digits - real_num_digits; i++) {
      width += num_0_img.width;
    }
    curr_x = (int)(SCREEN_W / 2 - width / 2);
  }

  for (i = 0; i < num_digits - real_num_digits; i++) {
    img_draw(num_0_img, curr_x, y);
    curr_x += num_0_img.width;
  }

  for (i = digit + 1; i < MAX_DIGITS; i++) {
    switch (digits[i]) {
      case 0: img_draw(num_0_img, curr_x, y); curr_x += num_0_img.width; break;
      case 1: img_draw(num_1_img, curr_x, y); curr_x += num_1_img.width; break;
      case 2: img_draw(num_2_img, curr_x, y); curr_x += num_2_img.width; break;
      case 3: img_draw(num_3_img, curr_x, y); curr_x += num_3_img.width; break;
      case 4: img_draw(num_4_img, curr_x, y); curr_x += num_4_img.width; break;
      case 5: img_draw(num_5_img, curr_x, y); curr_x += num_5_img.width; break;
      case 6: img_draw(num_6_img, curr_x, y); curr_x += num_6_img.width; break;
      case 7: img_draw(num_7_img, curr_x, y); curr_x += num_7_img.width; break;
      case 8: img_draw(num_8_img, curr_x, y); curr_x += num_8_img.width; break;
      case 9: img_draw(num_9_img, curr_x, y); curr_x += num_9_img.width; break;
      default: break;
    }
  }
}