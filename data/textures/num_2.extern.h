// Data resides in num_2.h
extern struct {
  u32 width;
  u32 height;
  u32 size;
  u32 chunk_height;
  u32 chunk_count;
  u16 pixels[270] __attribute__((__aligned__(8)));
} num_2_img;
