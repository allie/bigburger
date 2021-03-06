// Original: ingredients.png
// Format: 16-bit RGBA (5-5-5-1)
struct {
  u32 width;
  u32 height;
  u32 size;
  u32 chunk_height;
  u32 chunk_count;
  u16 pixels[740] __attribute__((__aligned__(8)));
} ingredients_img __attribute__((__aligned__(8))) = {
  74,
  10,
  740,
  27,
  1,
  {
    0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0,
    0x1, 0x8421, 0x94A5, 0x39CF, 0x39CF, 0x94A5, 0x94A5, 0x1, 0x1, 0x1, 0x8421, 0x94A5, 0x39CF, 0x1, 0x1, 0x5AD7, 0xAD6B, 0xC631, 0xB5AD, 0x8421, 0x1, 0x1, 0x39CF, 0x94A5, 0x94A5, 0x94A5, 0x94A5, 0x39CF, 0x1, 0x39CF, 0x94A5, 0x94A5, 0x94A5, 0x94A5, 0x1, 0x6B5B, 0x94A5, 0x94A5, 0x94A5, 0x8421, 0x1, 0x1, 0x1, 0x6B5B, 0x94A5, 0x6B5B, 0x1, 0x94A5, 0x94A5, 0x94A5, 0x94A5, 0x39CF, 0x39CF, 0x94A5, 0x94A5, 0x1, 0x1, 0x1, 0x8421, 0x94A5, 0x39CF, 0x94A5, 0x94A5, 0x94A5, 0x94A5, 0x94A5, 0x39CF, 0x2109, 0x9CE7, 0xC631, 0xB5AD, 0x8421, 0x1, 0x0,
    0x1, 0xC631, 0xDEF7, 0x6B5B, 0x6B5B, 0xDEF7, 0xDEF7, 0x9CE7, 0x1, 0x1, 0xC631, 0xDEF7, 0x6B5B, 0x1, 0x8421, 0xDEF7, 0xDEF7, 0xDEF7, 0xDEF7, 0xDEF7, 0x9CE7, 0x1, 0x6B5B, 0xDEF7, 0xDEF7, 0xDEF7, 0xDEF7, 0xD6B5, 0x2109, 0x6B5B, 0xDEF7, 0xDEF7, 0xDEF7, 0xDEF7, 0x2109, 0x94A5, 0xDEF7, 0xDEF7, 0xDEF7, 0xDEF7, 0xC631, 0x2109, 0x1, 0x94A5, 0xDEF7, 0x94A5, 0x2109, 0xDEF7, 0xDEF7, 0xDEF7, 0xDEF7, 0x6B5B, 0x6B5B, 0xDEF7, 0xDEF7, 0x9CE7, 0x1, 0x1, 0xC631, 0xDEF7, 0x6B5B, 0xDEF7, 0xDEF7, 0xDEF7, 0xDEF7, 0xDEF7, 0x6B5B, 0xB5AD, 0xDEF7, 0xDEF7, 0xDEF7, 0xAD6B, 0x1, 0x0,
    0x1, 0xC631, 0xDEF7, 0x6B5B, 0x6B5B, 0xDEF7, 0xDEF7, 0xDEF7, 0x8421, 0x1, 0xC631, 0xDEF7, 0x6B5B, 0x1, 0xD6B5, 0xDEF7, 0x8421, 0x2109, 0x5AD7, 0xD6B5, 0xAD6B, 0x1, 0x6B5B, 0xDEF7, 0xC631, 0x2109, 0xC631, 0xDEF7, 0x6B5B, 0x6B5B, 0xDEF7, 0xC631, 0x2109, 0x2109, 0x1, 0x94A5, 0xDEF7, 0x94A5, 0x6B5B, 0xAD6B, 0xDEF7, 0xB5AD, 0x1, 0x94A5, 0xDEF7, 0x94A5, 0x2109, 0xDEF7, 0xDEF7, 0x2109, 0x2109, 0x1, 0x6B5B, 0xDEF7, 0xDEF7, 0xDEF7, 0x8421, 0x1, 0xC631, 0xDEF7, 0x6B5B, 0x2109, 0x6B5B, 0xDEF7, 0xC631, 0x2109, 0x2109, 0xDEF7, 0xDEF7, 0x4A53, 0x39CF, 0x2109, 0x1, 0x0,
    0x1, 0xC631, 0xDEF7, 0x6B5B, 0x6B5B, 0xDEF7, 0xCE73, 0xD6B5, 0xD6B5, 0x4A53, 0xC631, 0xDEF7, 0x6B5B, 0x6B5B, 0xDEF7, 0xCE73, 0x1, 0x2109, 0x6B5B, 0x6B5B, 0x6B5B, 0x39CF, 0x6B5B, 0xDEF7, 0xC631, 0x6B5B, 0xCE73, 0xDEF7, 0x5AD7, 0x6B5B, 0xDEF7, 0xCE73, 0x94A5, 0x94A5, 0x1, 0x94A5, 0xDEF7, 0x94A5, 0x1, 0x39CF, 0xDEF7, 0xDEF7, 0x39CF, 0x94A5, 0xDEF7, 0x94A5, 0x2109, 0xDEF7, 0xDEF7, 0x94A5, 0x94A5, 0x39CF, 0x6B5B, 0xDEF7, 0xCE73, 0xD6B5, 0xD6B5, 0x4A53, 0xC631, 0xDEF7, 0x6B5B, 0x1, 0x6B5B, 0xDEF7, 0xC631, 0x1, 0x1, 0xCE73, 0xDEF7, 0xCE73, 0x9CE7, 0x39CF, 0x1, 0x1,
    0x1, 0x8421, 0x94A5, 0x4211, 0x4211, 0x94A5, 0x8421, 0x5AD7, 0x94A5, 0x8421, 0x8421, 0x94A5, 0x4211, 0x4211, 0x94A5, 0x8421, 0x1, 0x4211, 0x94A5, 0x94A5, 0x94A5, 0x6319, 0x4211, 0x94A5, 0x94A5, 0x94A5, 0x8C63, 0x6B5B, 0x1, 0x4211, 0x94A5, 0x94A5, 0x94A5, 0x94A5, 0x1085, 0x6319, 0x94A5, 0x6319, 0x1, 0x1085, 0x94A5, 0x94A5, 0x39CF, 0x6319, 0x94A5, 0x6319, 0x1085, 0x94A5, 0x94A5, 0x94A5, 0x94A5, 0x4211, 0x4211, 0x94A5, 0x8421, 0x5AD7, 0x94A5, 0x8421, 0x8421, 0x94A5, 0x4211, 0x1, 0x4211, 0x94A5, 0x8421, 0x1, 0x1, 0x294B, 0x7BDF, 0x94A5, 0x94A5, 0x8C63, 0x1085, 0x1,
    0x1, 0x6B5B, 0x7BDF, 0x39CF, 0x39CF, 0x7BDF, 0x6B5B, 0x1, 0x5AD7, 0x7BDF, 0x7BDF, 0x7BDF, 0x39CF, 0x2109, 0x7BDF, 0x739D, 0x843, 0x843, 0x39CF, 0x739D, 0x7BDF, 0x4A53, 0x39CF, 0x7BDF, 0x6B5B, 0x739D, 0x739D, 0x2109, 0x1, 0x39CF, 0x7BDF, 0x6B5B, 0x843, 0x843, 0x1, 0x5295, 0x7BDF, 0x5295, 0x1, 0x39CF, 0x7BDF, 0x739D, 0x1, 0x5295, 0x7BDF, 0x5295, 0x843, 0x7BDF, 0x7BDF, 0x843, 0x843, 0x1, 0x39CF, 0x7BDF, 0x6B5B, 0x1, 0x5AD7, 0x7BDF, 0x7BDF, 0x7BDF, 0x39CF, 0x1, 0x39CF, 0x7BDF, 0x6B5B, 0x1, 0x1, 0x843, 0x1, 0x2109, 0x739D, 0x7BDF, 0x39CF, 0x1,
    0x1, 0x6B5B, 0x7BDF, 0x39CF, 0x39CF, 0x7BDF, 0x6B5B, 0x1, 0x1, 0x6B5B, 0x7BDF, 0x7BDF, 0x39CF, 0x1, 0x5AD7, 0x7BDF, 0x739D, 0x5295, 0x5AD7, 0x7BDF, 0x739D, 0x843, 0x39CF, 0x7BDF, 0x6B5B, 0x4211, 0x7BDF, 0x6B5B, 0x843, 0x39CF, 0x7BDF, 0x739D, 0x6B5B, 0x6B5B, 0x1, 0x5295, 0x7BDF, 0x739D, 0x6B5B, 0x7BDF, 0x7BDF, 0x4A53, 0x1, 0x5295, 0x7BDF, 0x5295, 0x843, 0x7BDF, 0x7BDF, 0x6B5B, 0x6B5B, 0x318D, 0x39CF, 0x7BDF, 0x6B5B, 0x1, 0x1, 0x6B5B, 0x7BDF, 0x7BDF, 0x39CF, 0x1, 0x39CF, 0x7BDF, 0x6B5B, 0x1, 0x1, 0x739D, 0x5AD7, 0x5295, 0x739D, 0x7BDF, 0x2109, 0x1,
    0x1, 0x6B5B, 0x7BDF, 0x39CF, 0x39CF, 0x7BDF, 0x6B5B, 0x1, 0x1, 0x843, 0x739D, 0x7BDF, 0x39CF, 0x1, 0x843, 0x5AD7, 0x7BDF, 0x7BDF, 0x7BDF, 0x6B5B, 0x2109, 0x1, 0x39CF, 0x7BDF, 0x6B5B, 0x1, 0x5AD7, 0x7BDF, 0x5AD7, 0x39CF, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x843, 0x5295, 0x7BDF, 0x7BDF, 0x7BDF, 0x739D, 0x4211, 0x1, 0x1, 0x5295, 0x7BDF, 0x5295, 0x843, 0x7BDF, 0x7BDF, 0x7BDF, 0x7BDF, 0x39CF, 0x39CF, 0x7BDF, 0x6B5B, 0x1, 0x1, 0x843, 0x739D, 0x7BDF, 0x39CF, 0x1, 0x39CF, 0x7BDF, 0x6B5B, 0x1, 0x18C7, 0x6B5B, 0x7BDF, 0x7BDF, 0x7BDF, 0x4A53, 0x1, 0x1,
    0x1, 0x1, 0x843, 0x1, 0x1, 0x843, 0x1, 0x1, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x843, 0x843, 0x843, 0x843, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0
  }
};
