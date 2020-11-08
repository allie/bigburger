// Data resides in game_over.h
extern struct {
  u32 width;
  u32 height;
  u32 size;
  u32 chunk_height;
  u32 chunk_count;
  u16 pixels[5820] __attribute__((__aligned__(8)));
} game_over_img;
