// Original: balance_arrow.png
// Format: 16-bit RGBA (5-5-5-1)
struct {
  u32 width;
  u32 height;
  u32 size;
  u32 chunk_height;
  u32 chunk_count;
  u16 pixels[64] __attribute__((__aligned__(8)));
} balance_arrow_img __attribute__((__aligned__(8))) = {
  8,
  8,
  64,
  256,
  1,
  {
    0xFEC1, 0xFEC1, 0xFEC1, 0xFFFE, 0xFFFE, 0xFEC1, 0xFEC1, 0xFEC1,
    0xFEC1, 0xFEC1, 0xFEC1, 0xFEC1, 0xFEC1, 0xFEC1, 0xFEC1, 0xFEC1,
    0xFEC1, 0xFEC1, 0xFEC1, 0xFEC1, 0xFEC1, 0xFEC1, 0xFEC1, 0xFEC1,
    0xFFFE, 0xFE81, 0xFE81, 0xFE81, 0xFE81, 0xFE81, 0xFE81, 0xFFFE,
    0xFFFE, 0xFE81, 0xFE81, 0xFE81, 0xFE81, 0xFE81, 0xFE81, 0xFFFE,
    0xFFFE, 0xFFFE, 0xFE81, 0xFE81, 0xFE81, 0xFE81, 0xFFFE, 0xFFFE,
    0xFFFE, 0xFFFE, 0xFE81, 0xFE81, 0xFE81, 0xFE81, 0xFFFE, 0xFFFE,
    0xFFFE, 0xFFFE, 0xFFFE, 0xFE81, 0xFE81, 0xFFFE, 0xFFFE, 0xFFFE
  }
};
