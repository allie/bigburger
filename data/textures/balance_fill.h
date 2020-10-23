// Original: balance_fill.png
// Format: 16-bit RGBA (5-5-5-1)
struct {
  u32 width;
  u32 height;
  u32 size;
  u32 chunk_height;
  u32 chunk_count;
  u16 pixels[7] __attribute__((__aligned__(8)));
} balance_fill_img __attribute__((__aligned__(8))) = {
  1,
  7,
  7,
  2048,
  1,
  {
    0x6B5B,
    0x6319,
    0x4A53,
    0x39CF,
    0x294B,
    0x2109,
    0x2109
  }
};
