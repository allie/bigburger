// Data resides in bracket_offscreen.h
extern struct {
  u32 width;
  u32 height;
  u32 size;
  u32 chunk_height;
  u32 chunk_count;
  u16 pixels[2508] __attribute__((__aligned__(8)));
} bracket_offscreen_img;
