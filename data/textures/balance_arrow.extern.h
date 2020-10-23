// Data resides in balance_arrow.h
extern struct {
  u32 width;
  u32 height;
  u32 size;
  u32 chunk_height;
  u32 chunk_count;
  u16 pixels[64] __attribute__((__aligned__(8)));
} balance_arrow_img;
