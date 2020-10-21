#include "img.h"
#include "graphics.h"

void img_start() {
  graphics_start_texrect();
}

void img_end() {
  graphics_end_texrect();
}

void img_draw(Img img, float x, float y) {
  int tx, ty, sx, sy, ti = 0;

  for (ty = 0; ty < img.num_tiles_y; ty++) {
    for (tx = 0; tx < img.num_tiles_x; tx++) {
      sx = x + tx * img.tile_width;
      sy = y + ty * img.tile_height;

      gDPLoadTextureBlock(
        glistp++,
        img.tiles[ti].data,
        G_IM_FMT_RGBA, G_IM_SIZ_16b,
        img.tile_width,
        img.tile_height,
        0,
        G_TX_WRAP, G_TX_WRAP,
        G_TX_NOMASK, G_TX_NOMASK,
        G_TX_NOLOD, G_TX_NOLOD
      );
      gSPTextureRectangle(
        glistp++,
        sx << 2,
        sy << 2,
        (sx + img.tile_width) << 2,
        (sy + img.tile_height) << 2,
        G_TX_RENDERTILE,
        0 << 5, 0 << 5,
        1 << 10, 1 << 10
      );

      ti++;
    }
  }
}
