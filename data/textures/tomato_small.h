// Original: tomato_small.png
// Format: 16-bit RGBA (5-5-5-1)
struct {
  u32 width;
  u32 height;
  u32 size;
  u32 chunk_height;
  u32 chunk_count;
  u16 pixels[576] __attribute__((__aligned__(8)));
} tomato_small_img __attribute__((__aligned__(8))) = {
  24,
  24,
  576,
  85,
  1,
  {
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xF807, 0xF807, 0xF807, 0xF807, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xFFFE, 0xFFFE, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xFFFE, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x8003, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF803, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xFFFE, 0x8003, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF807, 0xF803, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xFFFE, 0xFFFE, 0x8003, 0x8003, 0x8003, 0xF807, 0xF807, 0xF807, 0xF807, 0xE803, 0xE803, 0xE803, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0x8003, 0xE803, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
  }
};