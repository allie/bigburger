// Data resides in rank_s.h
extern struct {
  u32 width;
  u32 height;
  u32 size;
  u32 chunk_height;
  u32 chunk_count;
  u16 pixels[285] __attribute__((__aligned__(8)));
} rank_s_img;
