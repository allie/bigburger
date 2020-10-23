// Original: next_big.png
// Format: 16-bit RGBA (5-5-5-1)
struct {
  u32 width;
  u32 height;
  u32 size;
  u32 chunk_height;
  u32 chunk_count;
  u16 pixels[1024] __attribute__((__aligned__(8)));
} next_big_img __attribute__((__aligned__(8))) = {
  32,
  32,
  1024,
  64,
  1,
  {
    0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xE739, 0xB5AD, 0xA529, 0x9CE7, 0x9CE7, 0x9CE7, 0x9CE7, 0x9CE7, 0x9CE7, 0x9CE7, 0x9CE7, 0x9CE7, 0x9CE7, 0x9CE7, 0x9CE7, 0x9CE7, 0x9CE7, 0x9CE7, 0x9CE7, 0xA529, 0xB5AD, 0xE739, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xC631, 0x1085, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1085, 0xC631, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0x1085, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1085, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0xFFFF, 0xFFFF,
    0xFFFF, 0xF7BD, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0xF7BD, 0xFFFF,
    0xF7BD, 0xEF7B, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0xEF7B, 0xF7BD,
    0xF7BD, 0xF7BD, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0xF7BD, 0xF7BD,
    0xF7BD, 0xF7BD, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0xF7BD, 0xF7BD,
    0xF7BD, 0xF7BD, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0xF7BD, 0xF7BD,
    0xF7BD, 0xF7BD, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0xF7BD, 0xF7BD,
    0xF7BD, 0xF7BD, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0xF7BD, 0xF7BD,
    0xF7BD, 0xF7BD, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0xF7BD, 0xF7BD,
    0xF7BD, 0xF7BD, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0xF7BD, 0xF7BD,
    0xF7BD, 0xF7BD, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0xF7BD, 0xF7BD,
    0xF7BD, 0xF7BD, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0xF7BD, 0xF7BD,
    0xF7BD, 0xF7BD, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0xF7BD, 0xF7BD,
    0xF7BD, 0xF7BD, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0xF7BD, 0xF7BD,
    0xF7BD, 0xF7BD, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0xF7BD, 0xF7BD,
    0xF7BD, 0xF7BD, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0xF7BD, 0xF7BD,
    0xF7BD, 0xF7BD, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0xF7BD, 0xF7BD,
    0xF7BD, 0xF7BD, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0xF7BD, 0xF7BD,
    0xF7BD, 0xF7BD, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0xF7BD, 0xF7BD,
    0xF7BD, 0xF7BD, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0xF7BD, 0xF7BD,
    0xEF7B, 0xFFFF, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0xFFFF, 0xEF7B,
    0xE739, 0xFFFF, 0x1, 0x1, 0x1, 0x18C7, 0x2109, 0x1085, 0x1085, 0x1085, 0x1085, 0x1085, 0x1085, 0x1085, 0x1085, 0x1085, 0x1085, 0x1085, 0x1085, 0x1085, 0x1085, 0x1085, 0x1085, 0x1085, 0x1085, 0x2109, 0x18C7, 0x1, 0x1, 0x1, 0xFFFF, 0xE739,
    0xDEF7, 0xFFFF, 0x1085, 0x18C7, 0x294B, 0x4211, 0x5AD7, 0x5295, 0x5295, 0x5295, 0x5295, 0x5295, 0x5295, 0x5295, 0x5295, 0x5295, 0x5295, 0x5295, 0x5295, 0x5295, 0x5295, 0x5295, 0x5295, 0x5295, 0x5295, 0x5AD7, 0x4211, 0x294B, 0x18C7, 0x1085, 0xFFFF, 0xDEF7,
    0xC631, 0xFFFF, 0x2109, 0x318D, 0x4A53, 0x6319, 0x739D, 0x739D, 0x739D, 0x739D, 0x739D, 0x739D, 0x739D, 0x739D, 0x739D, 0x739D, 0x739D, 0x739D, 0x739D, 0x739D, 0x739D, 0x739D, 0x739D, 0x739D, 0x739D, 0x739D, 0x6319, 0x4A53, 0x318D, 0x2109, 0xFFFF, 0xC631,
    0xB5AD, 0xD6B5, 0x318D, 0x4211, 0x5AD7, 0x6B5B, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x6B5B, 0x5AD7, 0x4211, 0x318D, 0xD6B5, 0xB5AD,
    0xAD6B, 0xA529, 0x94A5, 0x318D, 0x5295, 0x6B5B, 0x739D, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x739D, 0x6B5B, 0x5295, 0x39CF, 0x94A5, 0xA529, 0xAD6B,
    0xC631, 0x8C63, 0x8C63, 0xAD6B, 0xE739, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xE739, 0xAD6B, 0x8C63, 0x8C63, 0xC631,
    0xFFFE, 0xB5AD, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x8421, 0x8C63, 0x94A5, 0x94A5, 0x94A5, 0x94A5, 0x94A5, 0x94A5, 0x94A5, 0x94A5, 0x94A5, 0x94A5, 0x94A5, 0x94A5, 0x94A5, 0x94A5, 0x94A5, 0x94A5, 0x8C63, 0x8421, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0xB5AD, 0x18C6
  }
};
