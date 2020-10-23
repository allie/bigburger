// Original: next_up.png
// Format: 16-bit RGBA (5-5-5-1)
struct {
  u32 width;
  u32 height;
  u32 size;
  u32 chunk_height;
  u32 chunk_count;
  u16 pixels[663] __attribute__((__aligned__(8)));
} next_up_img __attribute__((__aligned__(8))) = {
  51,
  13,
  663,
  40,
  1,
  {
    0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0,
    0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0,
    0x1, 0x1, 0x4211, 0xAD6B, 0xAD6B, 0x1, 0x1, 0x1, 0x9CE7, 0xAD6B, 0x4211, 0x1, 0xAD6B, 0xAD6B, 0xAD6B, 0xAD6B, 0x4211, 0x2109, 0xAD6B, 0xAD6B, 0x2109, 0x1, 0x9CE7, 0xAD6B, 0x7BDF, 0xAD6B, 0xAD6B, 0xAD6B, 0xAD6B, 0xAD6B, 0x4211, 0x1, 0x1, 0x1, 0x7BDF, 0xAD6B, 0x7BDF, 0x1, 0x1, 0x9CE7, 0xAD6B, 0x1, 0x7BDF, 0xAD6B, 0xAD6B, 0xAD6B, 0x9CE7, 0x2109, 0x1, 0x1, 0x0,
    0x1, 0x1, 0x7BDF, 0xFFFF, 0xFFFF, 0xBDEF, 0x1, 0x1, 0xDEF7, 0xFFFF, 0x7BDF, 0x2109, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7BDF, 0x1, 0xC631, 0xFFFF, 0xBDEF, 0x9CE7, 0xFFFF, 0xF7BD, 0x2109, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7BDF, 0x1, 0x1, 0x1, 0xAD6B, 0xFFFF, 0xAD6B, 0x1, 0x1, 0xDEF7, 0xFFFF, 0x2109, 0xAD6B, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xDEF7, 0x1, 0x1, 0x1,
    0x1, 0x1, 0x7BDF, 0xFFFF, 0xFFFF, 0xFFFF, 0x9CE7, 0x1, 0xDEF7, 0xFFFF, 0x7BDF, 0x2109, 0xFFFF, 0xFFFF, 0x2109, 0x2109, 0x1, 0x1, 0x2109, 0xF7BD, 0xFFFF, 0xF7BD, 0xFFFF, 0x7BDF, 0x1, 0x2109, 0x7BDF, 0xFFFF, 0xDEF7, 0x2109, 0x1, 0x1, 0x1, 0x1, 0xAD6B, 0xFFFF, 0xAD6B, 0x1, 0x1, 0xDEF7, 0xFFFF, 0x2109, 0xAD6B, 0xFFFF, 0xAD6B, 0x4211, 0xEF7B, 0xFFFF, 0x7BDF, 0x1, 0x1,
    0x1, 0x1, 0x7BDF, 0xFFFF, 0xEF7B, 0xF7BD, 0xF7BD, 0x5AD7, 0xDEF7, 0xFFFF, 0x7BDF, 0x2109, 0xFFFF, 0xFFFF, 0xAD6B, 0xAD6B, 0x4211, 0x1, 0x1, 0x8C63, 0xFFFF, 0xFFFF, 0xBDEF, 0x1, 0x1, 0x1, 0x7BDF, 0xFFFF, 0xDEF7, 0x1, 0x1, 0x1, 0x1, 0x1, 0xAD6B, 0xFFFF, 0xAD6B, 0x1, 0x1, 0xDEF7, 0xFFFF, 0x2109, 0xAD6B, 0xFFFF, 0xAD6B, 0x5AD7, 0xEF7B, 0xFFFF, 0x7BDF, 0x1, 0x1,
    0x1, 0x1, 0x7BDF, 0xFFFF, 0xDEF7, 0x9CE7, 0xFFFF, 0xEF7B, 0xDEF7, 0xFFFF, 0x7BDF, 0x2109, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7BDF, 0x1, 0x1, 0x9CE7, 0xFFFF, 0xFFFF, 0xBDEF, 0x1, 0x1, 0x1, 0x7BDF, 0xFFFF, 0xDEF7, 0x1, 0x1, 0x0, 0x1, 0x1, 0xAD6B, 0xFFFF, 0xAD6B, 0x1, 0x1, 0xDEF7, 0xFFFF, 0x2109, 0xAD6B, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xDEF7, 0x1, 0x1, 0x1,
    0x1, 0x1, 0x7BDF, 0xFFFF, 0xDEF7, 0x1, 0xBDEF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7BDF, 0x2109, 0xFFFF, 0xFFFF, 0x2109, 0x2109, 0x1, 0x1, 0x6B5B, 0xFFFF, 0xFFFF, 0xEF7B, 0xFFFF, 0x8C63, 0x1, 0x1, 0x7BDF, 0xFFFF, 0xDEF7, 0x1, 0x1, 0x0, 0x1, 0x1, 0x9CE7, 0xFFFF, 0xBDEF, 0x1, 0x1, 0xF7BD, 0xFFFF, 0x2109, 0xAD6B, 0xFFFF, 0xD6B5, 0xAD6B, 0x9CE7, 0x2109, 0x1, 0x1, 0x0,
    0x1, 0x1, 0x7BDF, 0xFFFF, 0xDEF7, 0x1, 0x1, 0xDEF7, 0xFFFF, 0xFFFF, 0x7BDF, 0x2109, 0xFFFF, 0xFFFF, 0xDEF7, 0xDEF7, 0x6B5B, 0x2109, 0xDEF7, 0xFFFF, 0x9CE7, 0x7BDF, 0xFFFF, 0xF7BD, 0x2109, 0x1, 0x7BDF, 0xFFFF, 0xDEF7, 0x1, 0x1, 0x0, 0x1, 0x1, 0x6B5B, 0xFFFF, 0xF7BD, 0xBDEF, 0xC631, 0xFFFF, 0xEF7B, 0x1, 0xAD6B, 0xFFFF, 0xAD6B, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0,
    0x1, 0x1, 0x7BDF, 0xFFFF, 0xDEF7, 0x1, 0x1, 0x2109, 0xF7BD, 0xFFFF, 0x7BDF, 0x2109, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7BDF, 0xBDEF, 0xFFFF, 0xD6B5, 0x1, 0x1, 0xC631, 0xFFFF, 0xC631, 0x1, 0x7BDF, 0xFFFF, 0xDEF7, 0x1, 0x1, 0x0, 0x1, 0x1, 0x1, 0xBDEF, 0xFFFF, 0xFFFF, 0xFFFF, 0xEF7B, 0x5AD7, 0x1, 0xAD6B, 0xFFFF, 0xAD6B, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0,
    0x1, 0x1, 0x1, 0x2109, 0x1, 0x1, 0x1, 0x1, 0x1, 0x2109, 0x1, 0x1, 0x2109, 0x2109, 0x2109, 0x2109, 0x1, 0x2109, 0x2109, 0x1, 0x1, 0x1, 0x1, 0x2109, 0x2109, 0x1, 0x1, 0x2109, 0x1, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0x1, 0x4211, 0x7BDF, 0x6B5B, 0x1, 0x1, 0x1, 0x1, 0x2109, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x0, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
  }
};
