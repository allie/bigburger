#ifndef IMAGE_H
#define IMAGE_H

#include "common.h"

#define TMEM_SIZE 4096

// Data for a part of an image
typedef struct {
  unsigned short data[TMEM_SIZE];
} Rgba16bTexture;

// A whole image that may contain 1 or multiple parts
typedef struct {
  u16 width;
  u8 height;
  u8 tile_width;
  u8 tile_height;
  u8 num_tiles_x;
  u8 num_tiles_y;
  u16 num_tiles;
  Rgba16bTexture* tiles;
} Img;

void img_start();
void img_end();
// TODO: expand this with more options than just position
void img_draw(Img img, int x, int y);

#endif
