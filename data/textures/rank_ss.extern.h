// Data resides in rank_ss.h
extern struct {
  u32 width;
  u32 height;
  u32 size;
  u32 chunk_height;
  u32 chunk_count;
  u16 pixels[494] __attribute__((__aligned__(8)));
} rank_ss_img;
