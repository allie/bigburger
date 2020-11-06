// Original: dpad.png
// Format: 16-bit RGBA (5-5-5-1)
struct {
  u32 width;
  u32 height;
  u32 size;
  u32 chunk_height;
  u32 chunk_count;
  u16 pixels[1600] __attribute__((__aligned__(8)));
} dpad_img __attribute__((__aligned__(8))) = {
  40,
  40,
  1600,
  51,
  1,
  {
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x294B, 0x6B5B, 0x739D, 0x739D, 0x739D, 0x739D, 0x739D, 0x739D, 0x739D, 0x739D, 0x6B5B, 0x318D, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x5295, 0x5AD7, 0x4A53, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4A53, 0x5AD7, 0x6319, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x5295, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4A53, 0x5AD7, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x5295, 0x4211, 0x4211, 0x4211, 0x4211, 0x318D, 0x318D, 0x4211, 0x4211, 0x4211, 0x4211, 0x5295, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x5295, 0x4211, 0x4211, 0x4211, 0x39CF, 0x318D, 0x318D, 0x39CF, 0x4211, 0x4211, 0x4211, 0x5295, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x5295, 0x4211, 0x4211, 0x4211, 0x318D, 0x318D, 0x318D, 0x318D, 0x4211, 0x4211, 0x4211, 0x5295, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x5295, 0x4211, 0x4211, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x4211, 0x4211, 0x5295, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x5295, 0x4211, 0x4211, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x4211, 0x4211, 0x5295, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x5295, 0x4211, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x4211, 0x5295, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x5295, 0x4211, 0x4211, 0x39CF, 0x39CF, 0x39CF, 0x39CF, 0x39CF, 0x39CF, 0x4211, 0x4211, 0x5295, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1085, 0x5295, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x5295, 0x843, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0,
    0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1085, 0x5295, 0x5295, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x5295, 0x4A53, 0x1085, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1,
    0x1, 0x1, 0x294B, 0x6B5B, 0x739D, 0x739D, 0x739D, 0x739D, 0x7BDF, 0x739D, 0x739D, 0x739D, 0x739D, 0x6319, 0x4A53, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4A53, 0x6319, 0x6B5B, 0x739D, 0x739D, 0x739D, 0x739D, 0x739D, 0x739D, 0x739D, 0x739D, 0x6B5B, 0x318D, 0x1, 0x1,
    0x1, 0x1, 0x5295, 0x5AD7, 0x4A53, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4A53, 0x5AD7, 0x6319, 0x1, 0x1,
    0x1, 0x1, 0x5295, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x318D, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x39CF, 0x318D, 0x318D, 0x39CF, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x318D, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4A53, 0x5AD7, 0x1, 0x1,
    0x1, 0x1, 0x5295, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x318D, 0x318D, 0x318D, 0x39CF, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x318D, 0x294B, 0x294B, 0x318D, 0x294B, 0x318D, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x39CF, 0x318D, 0x318D, 0x318D, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x5295, 0x1, 0x1,
    0x1, 0x1, 0x5295, 0x4211, 0x4211, 0x4211, 0x39CF, 0x294B, 0x318D, 0x318D, 0x318D, 0x39CF, 0x4211, 0x4211, 0x4211, 0x4211, 0x39CF, 0x294B, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x39CF, 0x4211, 0x4211, 0x4211, 0x4211, 0x39CF, 0x318D, 0x318D, 0x318D, 0x294B, 0x39CF, 0x4211, 0x4211, 0x4211, 0x5295, 0x1, 0x1,
    0x1, 0x1, 0x5295, 0x4211, 0x4211, 0x294B, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x39CF, 0x4211, 0x4211, 0x4211, 0x4211, 0x39CF, 0x318D, 0x318D, 0x39CF, 0x39CF, 0x39CF, 0x318D, 0x39CF, 0x4211, 0x4211, 0x4211, 0x4211, 0x39CF, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x294B, 0x4211, 0x4211, 0x5295, 0x1, 0x1,
    0x1, 0x1, 0x5295, 0x4211, 0x4211, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x39CF, 0x4211, 0x4211, 0x4211, 0x4211, 0x39CF, 0x318D, 0x39CF, 0x39CF, 0x39CF, 0x39CF, 0x39CF, 0x39CF, 0x4211, 0x4211, 0x4211, 0x4211, 0x39CF, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x4211, 0x4211, 0x5295, 0x1, 0x1,
    0x1, 0x1, 0x5295, 0x4211, 0x4211, 0x4211, 0x39CF, 0x318D, 0x318D, 0x318D, 0x318D, 0x39CF, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x39CF, 0x39CF, 0x4211, 0x4211, 0x4211, 0x39CF, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x39CF, 0x318D, 0x318D, 0x318D, 0x318D, 0x39CF, 0x4211, 0x4211, 0x4211, 0x5295, 0x1, 0x1,
    0x1, 0x1, 0x5295, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x318D, 0x318D, 0x318D, 0x39CF, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x39CF, 0x39CF, 0x4211, 0x4211, 0x4211, 0x39CF, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x39CF, 0x318D, 0x318D, 0x318D, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x5295, 0x1, 0x1,
    0x1, 0x1, 0x5295, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x318D, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x318D, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x5295, 0x1, 0x1,
    0x1, 0x1, 0x5295, 0x4A53, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4A53, 0x1, 0x1,
    0x1, 0x1, 0x2109, 0x4211, 0x39CF, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x39CF, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x39CF, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x39CF, 0x18C7, 0x1, 0x1,
    0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x843, 0x318D, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4A53, 0x39CF, 0x843, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1,
    0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x843, 0x4A53, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x5295, 0x843, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x5295, 0x4211, 0x4211, 0x39CF, 0x39CF, 0x39CF, 0x39CF, 0x39CF, 0x39CF, 0x4211, 0x4211, 0x5295, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x5295, 0x4211, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x4211, 0x5295, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x5295, 0x4211, 0x4211, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x4211, 0x4211, 0x5295, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x5295, 0x4211, 0x4211, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x4211, 0x4211, 0x5295, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x5295, 0x4211, 0x4211, 0x4211, 0x318D, 0x318D, 0x318D, 0x318D, 0x4211, 0x4211, 0x4211, 0x5295, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x5295, 0x4211, 0x4211, 0x4211, 0x39CF, 0x318D, 0x318D, 0x39CF, 0x4211, 0x4211, 0x4211, 0x5295, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x5295, 0x4211, 0x4211, 0x4211, 0x4211, 0x318D, 0x318D, 0x4211, 0x4211, 0x4211, 0x4211, 0x5295, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x5295, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x5295, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x5295, 0x4A53, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4211, 0x4A53, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x2109, 0x4211, 0x39CF, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x318D, 0x39CF, 0x18C7, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
  }
};
