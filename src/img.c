#include "img.h"
#include "graphics.h"

void img_start() {
  graphics_start_texrect();
}

void img_end() {
  graphics_end_texrect();
}

void img_set_colour(u8 r, u8 g, u8 b, u8 a) {
  gDPSetPrimColor(glistp++, 0, 0, r, g, b, a);
}

// Structure that we can map the structs defined in our
// image data files with.
typedef struct {
  u32 width;
  u32 height;
  u32 size;
  u32 chunk_height;
  u32 chunk_count;
} Img;

char conbuf[20];

void _img_draw(void* img_data, float x, float y) {
  u32 chunk, cy, chunk_height;

  // Cast data to an Img so we can easily access the metadata
  Img img = *((Img*)(img_data));
  // Pixel data comes immediately after the metadata
  u16* pixels = img_data + 24;

  // Calculate destination screen coordinate X components
  // Top left
  u32 sx1 = (u32)(x * (1 << 2)); // Convert float to 10.2 fixed point
  u32 sy1 = 0; // To be calculated by chunk
  // Bottom right
  u32 sx2 = sx1 + (img.width << 2);
  u32 sy2 = 0; // To be calculated by chunk

  for (chunk = 0; chunk < img.chunk_count; chunk++) {
    // y coordinate of the chunk, relative to the top of the image
    cy = chunk * img.chunk_height;

    // Height of the chunk
    // If this is the last chunk, the height will be the remaining height of the image
    // Otherwise, the chunk height is just img.chunk_height
    chunk_height = chunk == img.chunk_count - 1 ? img.height - cy : img.chunk_height;

    // Calculate destination screen coordinate Y components
    // Top left
    sy1 = (u32)(y * (1 << 2)) + (cy << 2); // Convert float to 10.2 fixed point
    // Bottom right
    sy2 = sy1 + (chunk_height << 2);

    // Load the chunk into TMEM
    gDPLoadTextureTile(
      glistp++,
      pixels, // Pixel data
      G_IM_FMT_RGBA, // Pixel format
      G_IM_SIZ_16b, // Pixel size
      img.width, // Width of the whole image
      img.height, // Height of the whole image
      0, cy, // Top left corner of the chunk
      img.width - 1, cy + chunk_height - 1, // Bottom right corner of the chunk
      0, // Palette
      G_TX_WRAP, G_TX_WRAP,
      G_TX_NOMASK, G_TX_NOMASK,
      G_TX_NOLOD, G_TX_NOLOD
    );

    // Draw the chunk on the screen
    gSPTextureRectangle(
      glistp++,
      sx1, sy1, // Top left screen coordinate
      sx2, sy2, // Bottom right screen coordinate
      G_TX_RENDERTILE,
      0 << 5, cy << 5,
      1 << 10, 1 << 10
    );
  }
}
