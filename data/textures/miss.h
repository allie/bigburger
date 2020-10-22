// Original: miss.png
// Format: 16-bit RGBA (5-5-5-1)
struct {
  u32 width;
  u32 height;
  u32 size;
  u32 chunk_height;
  u32 chunk_count;
  u16 pixels[3102];
} miss_img = {
  94,
  33,
  3102,
  21,
  2,
  {
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x6001, 0x7001, 0x7001, 0x7001, 0x7001, 0x7001, 0x7001, 0x2801, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x7001, 0x7001, 0x7001, 0x7001, 0x7001, 0x7001, 0x7001, 0x1, 0x1, 0x0, 0x0, 0x0, 0x1, 0x1, 0x2801, 0x7001, 0x7001, 0x7001, 0x7001, 0x7001, 0x7001, 0x7001, 0x1, 0x1, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x9801, 0xC801, 0xE001, 0xF801, 0xF801, 0xE001, 0xE001, 0xA801, 0x8801, 0x2801, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x9801, 0xC803, 0xE001, 0xF801, 0xF803, 0xE001, 0xE001, 0xA803, 0x8803, 0x2801, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xA801, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x6001, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0x4801, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0x7001, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0x1, 0xA801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xC801, 0x7003, 0x1, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0x1, 0xA803, 0xF805, 0xF807, 0xF807, 0xF807, 0xF807, 0xF809, 0xF809, 0xF809, 0xF809, 0xF809, 0xF809, 0xC807, 0x7005, 0x1, 0x1, 0x1, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0xB801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0x7001, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0x7001, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0x1, 0x1, 0x0, 0x1, 0x1, 0x1, 0xC801, 0xF803, 0xF803, 0xF805, 0xF805, 0xF805, 0xF805, 0xF805, 0xF805, 0xF805, 0xF807, 0xF807, 0xF807, 0xF807, 0xF809, 0x9803, 0x1, 0x1, 0x0, 0x1, 0x1, 0x1, 0xC807, 0xF80B, 0xF80B, 0xF80B, 0xF80B, 0xF80B, 0xF80D, 0xF80D, 0xF80D, 0xF80D, 0xF80D, 0xF80D, 0xF80D, 0xF80F, 0xF80F, 0x9807, 0x1, 0x1, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x7001, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0x6001, 0x1, 0x1, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xA801, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0x7003, 0xF803, 0xF803, 0xF805, 0xF805, 0xF805, 0xF805, 0xF805, 0x1, 0x1, 0x0, 0x1, 0x1, 0xB805, 0xF809, 0xF809, 0xF809, 0xF809, 0xF809, 0xF809, 0xF809, 0xF809, 0xF80B, 0xF80B, 0xF80B, 0xF80B, 0xF80B, 0xF80B, 0xF80B, 0x2801, 0x1, 0x1, 0x0, 0x1, 0x1, 0xB809, 0xF80F, 0xF80F, 0xF80F, 0xF80F, 0xF80F, 0xF80F, 0xF80F, 0xF811, 0xF811, 0xF811, 0xF811, 0xF811, 0xF811, 0xF811, 0xF811, 0x2803, 0x1, 0x1, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x9801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xF801, 0xC801, 0x1, 0x1, 0x0, 0x0, 0x0, 0x1, 0x1, 0x8801, 0xF803, 0xF803, 0xF803, 0xF805, 0xF805, 0xF805, 0xF805, 0xF805, 0xD005, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0x7003, 0xF809, 0xF809, 0xF809, 0xF809, 0xF809, 0xF809, 0xF809, 0x1, 0x1, 0x1, 0x1, 0x6003, 0xF80D, 0xF80D, 0xF80D, 0xF80D, 0xF80D, 0xF80D, 0xF80D, 0xF80F, 0xF80F, 0xF80F, 0xF80F, 0xF80F, 0xF80F, 0xF80F, 0xF80F, 0x9809, 0x1, 0x1, 0x0, 0x1, 0x1, 0x6005, 0xF811, 0xF811, 0xF813, 0xF813, 0xF813, 0xF813, 0xF813, 0xF813, 0xF815, 0xF815, 0xF815, 0xF815, 0xF815, 0xF815, 0xF815, 0x980B, 0x1, 0x1, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0xB801, 0xF801, 0xF801, 0xF803, 0xF803, 0xF803, 0xF803, 0xF805, 0xF805, 0xF803, 0x1, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0xD005, 0xF809, 0xF809, 0xF809, 0xF809, 0xF809, 0xF809, 0xF809, 0xF809, 0xF009, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0x7005, 0xF80D, 0xF80D, 0xF80D, 0xF80D, 0xF80D, 0xF80F, 0xF80F, 0x1, 0x1, 0x1, 0x1, 0xC80B, 0xF80F, 0xF811, 0xF811, 0xF811, 0xF811, 0xF811, 0xF811, 0xF811, 0xF811, 0xF811, 0xF813, 0xF813, 0xF813, 0xF813, 0xF811, 0x1, 0x1, 0x1, 0x0, 0x1, 0x1, 0xC00F, 0xF815, 0xF817, 0xF817, 0xF817, 0xF817, 0xF817, 0xF817, 0xF817, 0xF817, 0xF819, 0xF819, 0xF819, 0xF819, 0xF819, 0xF817, 0x1, 0x1, 0x1, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0xE005, 0xF807, 0xF807, 0xF809, 0xF809, 0xF809, 0xF809, 0xF809, 0xF809, 0xF809, 0x9805, 0x1, 0x1, 0x0, 0x1, 0x1, 0x2801, 0xF80D, 0xF80D, 0xF80D, 0xF80D, 0xF80D, 0xF80D, 0xF80D, 0xF80F, 0xF80F, 0xF80F, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0x7007, 0xF811, 0xF811, 0xF811, 0xF811, 0xF811, 0xF811, 0xF811, 0x1, 0x1, 0x1, 0x1, 0xF813, 0xF813, 0xF815, 0xF815, 0xF815, 0xF815, 0xF815, 0xF815, 0x8009, 0x1, 0x1, 0x4805, 0xA80D, 0xF815, 0xF817, 0x980B, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0xF819, 0xF81B, 0xF81B, 0xF81B, 0xF81B, 0xF81B, 0xF81B, 0xF819, 0x800D, 0x1, 0x1, 0x4807, 0xA811, 0xF81B, 0xF81D, 0x980F, 0x1, 0x1, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0xF80B, 0xF80B, 0xF80B, 0xF80D, 0xF80D, 0xF80D, 0xF80D, 0xF80D, 0xF80D, 0xF80D, 0xD00B, 0x1, 0x1, 0x0, 0x1, 0x1, 0xA809, 0xF80F, 0xF811, 0xF811, 0xF811, 0xF811, 0xF811, 0xF811, 0xF811, 0xF811, 0xF811, 0x6005, 0x1, 0x1, 0x0, 0x1, 0x1, 0x7007, 0xF815, 0xF815, 0xF815, 0xF815, 0xF815, 0xF815, 0xF817, 0x1, 0x1, 0x1, 0x6007, 0xF817, 0xF817, 0xF817, 0xF819, 0xF819, 0xF819, 0xF819, 0x800B, 0x1, 0x1, 0x1, 0x1, 0x1, 0x2803, 0xA80F, 0x1, 0x1, 0x1, 0x0, 0x1, 0x1, 0x5809, 0xF81D, 0xF81D, 0xF81D, 0xF81D, 0xF81D, 0xF81F, 0xF81F, 0x800F, 0x1, 0x1, 0x1, 0x1, 0x1, 0x2805, 0xA813, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0x1, 0x2803, 0xF80F, 0xF80F, 0xF80F, 0xF811, 0xF811, 0xF811, 0xF811, 0xF811, 0xF811, 0xF811, 0xF811, 0x4805, 0x1, 0x1, 0x1, 0x1, 0xE811, 0xF813, 0xF815, 0xF815, 0xF815, 0xF815, 0xF815, 0xF815, 0xF815, 0xF815, 0xF817, 0x800B, 0x1, 0x1, 0x0, 0x1, 0x1, 0x7009, 0xF819, 0xF819, 0xF819, 0xF819, 0xF819, 0xF81B, 0xF81B, 0x1, 0x1, 0x1, 0x700B, 0xF81B, 0xF81B, 0xF81B, 0xF81B, 0xF81D, 0xF81D, 0xF81D, 0x4807, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0x700D, 0xF821, 0xF821, 0xF821, 0xF821, 0xF821, 0xF821, 0xF823, 0x4807, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0x1, 0x7007, 0xF813, 0xF813, 0xF813, 0xF815, 0xF815, 0xF815, 0xF815, 0xF815, 0xF815, 0xF815, 0xF815, 0xA80D, 0x1, 0x1, 0x1, 0x6007, 0xF817, 0xF817, 0xF817, 0xF819, 0xF819, 0xF819, 0xF819, 0xF819, 0xF819, 0xF81B, 0xF81B, 0xA80F, 0x1, 0x1, 0x0, 0x1, 0x1, 0x700B, 0xF81B, 0xF81D, 0xF81D, 0xF81D, 0xF81D, 0xF81D, 0xF81D, 0x1, 0x1, 0x1, 0x700B, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0xF821, 0xF821, 0xC017, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x1, 0x1, 0x700F, 0xF825, 0xF825, 0xF825, 0xF825, 0xF825, 0xF825, 0xF825, 0xC01B, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0x1, 0xA80D, 0xF817, 0xF817, 0xF817, 0xF817, 0xF817, 0xF819, 0xF819, 0xF819, 0xF819, 0xF819, 0xF81B, 0xF817, 0x1, 0x1, 0x1, 0xB011, 0xF81B, 0xF81B, 0xF81B, 0xF81B, 0xF81D, 0xF81D, 0xF81D, 0xF81D, 0xF81D, 0xF81D, 0xF81D, 0xD017, 0x1, 0x1, 0x0, 0x1, 0x1, 0x700D, 0xF81F, 0xF81F, 0xF821, 0xF821, 0xF821, 0xF821, 0xF821, 0x1, 0x1, 0x1, 0x580B, 0xF823, 0xF823, 0xF823, 0xF823, 0xF823, 0xF823, 0xF823, 0xF823, 0xE01D, 0x9013, 0x2805, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x1, 0x1, 0x580D, 0xF827, 0xF827, 0xF827, 0xF829, 0xF829, 0xF829, 0xF829, 0xF829, 0xE021, 0x9017, 0x2807, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0x1, 0xB811, 0xF81B, 0xF81B, 0xF81B, 0xF81B, 0xF81B, 0xF81B, 0xF81D, 0xF81D, 0xF81D, 0xF81D, 0xF81D, 0xF81D, 0x5809, 0x1, 0x1, 0xF81D, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0xF821, 0xF821, 0xF821, 0xF821, 0xF821, 0xF821, 0xE81D, 0x1, 0x1, 0x0, 0x1, 0x1, 0x700D, 0xF823, 0xF823, 0xF823, 0xF823, 0xF825, 0xF825, 0xF825, 0x1, 0x1, 0x1, 0x1, 0xF823, 0xF825, 0xF827, 0xF827, 0xF827, 0xF827, 0xF827, 0xF827, 0xF827, 0xF827, 0xF829, 0xD01F, 0x9015, 0x2807, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x1, 0x1, 0xF829, 0xF82B, 0xF82B, 0xF86B, 0xF86B, 0xF86B, 0xF86B, 0xF86B, 0xF86D, 0xF86D, 0xF8AD, 0xD063, 0x9019, 0x2807, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0x1, 0xE019, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0xF81F, 0xF821, 0xF821, 0xF821, 0xF821, 0xF821, 0xC017, 0x1, 0x800F, 0xF823, 0xF823, 0xF823, 0xF823, 0xF823, 0xF823, 0xF823, 0xF823, 0xF823, 0xF825, 0xF825, 0xF825, 0xF825, 0x1, 0x1, 0x0, 0x1, 0x1, 0x700F, 0xF827, 0xF827, 0xF827, 0xF827, 0xF827, 0xF827, 0xF827, 0x1, 0x1, 0x1, 0x1, 0xA019, 0xF829, 0xF829, 0xF829, 0xF829, 0xF82B, 0xF82B, 0xF82B, 0xF82B, 0xF82B, 0xF82B, 0xF86B, 0xF86B, 0xF869, 0xA01B, 0x2807, 0x1, 0x1, 0x1, 0x0, 0x1, 0x1, 0xA05B, 0xF8AD, 0xF8ED, 0xF8ED, 0xF8EF, 0xF8EF, 0xF8EF, 0xF8EF, 0xF8EF, 0xF8EF, 0xF8EF, 0xF8EF, 0xF8EF, 0xF92D, 0xA09D, 0x2807, 0x1, 0x1, 0x1, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0x1, 0xF821, 0xF821, 0xF823, 0xF823, 0xF823, 0xF823, 0xE01D, 0xC019, 0xF823, 0xF823, 0xF825, 0xF825, 0xF825, 0xF823, 0x1, 0xC01B, 0xF825, 0xF825, 0xF825, 0xF827, 0xF827, 0xE821, 0xA017, 0xF827, 0xF827, 0xF827, 0xF827, 0xF829, 0xF829, 0x580D, 0x1, 0x1, 0x1, 0x1, 0x7011, 0xF829, 0xF82B, 0xF82B, 0xF82B, 0xF82B, 0xF82B, 0xF82B, 0x1, 0x1, 0x1, 0x1, 0x2807, 0xF869, 0xF86D, 0xF8AD, 0xF8AD, 0xF8AD, 0xF8AD, 0xF8AD, 0xF8AD, 0xF8ED, 0xF8ED, 0xF8ED, 0xF8EF, 0xF8EF, 0xF8EF, 0xE8A9, 0x580F, 0x1, 0x1, 0x0, 0x1, 0x1, 0x2807, 0xF8EB, 0xF931, 0xF931, 0xF931, 0xF931, 0xF931, 0xF931, 0xF931, 0xF931, 0xF931, 0xF931, 0xF931, 0xF931, 0xF933, 0xE96F, 0x5853, 0x1, 0x1, 0x0, 0x0,
    0x0, 0x0, 0x1, 0x1, 0x2805, 0xF825, 0xF825, 0xF825, 0xF825, 0xF825, 0xF827, 0xD01D, 0x580D, 0xF827, 0xF827, 0xF827, 0xF827, 0xF827, 0xF829, 0xA019, 0xF829, 0xF829, 0xF829, 0xF829, 0xF829, 0xF829, 0x9017, 0xA019, 0xF82B, 0xF82B, 0xF82B, 0xF82B, 0xF82B, 0xF86B, 0x8015, 0x1, 0x1, 0x1, 0x1, 0x7013, 0xF8AD, 0xF8AD, 0xF8AD, 0xF8AD, 0xF8AD, 0xF8AD, 0xF8ED, 0x1, 0x1, 0x0, 0x1, 0x1, 0x580F, 0xE8E9, 0xF8EF, 0xF8EF, 0xF8EF, 0xF92F, 0xF92F, 0xF92F, 0xF931, 0xF931, 0xF931, 0xF931, 0xF931, 0xF931, 0xF931, 0xF92F, 0x400B, 0x1, 0x1, 0x0, 0x1, 0x1, 0x5853, 0xE9B1, 0xFA3B, 0xFA7D, 0xFA7F, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFA7D, 0x4051, 0x1, 0x1, 0x0,
    0x0, 0x0, 0x1, 0x1, 0x7011, 0xF829, 0xF829, 0xF829, 0xF829, 0xF829, 0xF829, 0xA019, 0x1, 0xE825, 0xF82B, 0xF82B, 0xF82B, 0xF82B, 0xF86B, 0xF869, 0xF86B, 0xF86B, 0xF86B, 0xF86D, 0xF86D, 0xF8AB, 0x2807, 0x7013, 0xF8AD, 0xF8AD, 0xF8AD, 0xF8ED, 0xF8ED, 0xF8ED, 0xA05D, 0x1, 0x1, 0x1, 0x1, 0x7013, 0xF8EF, 0xF8EF, 0xF92F, 0xF92F, 0xF92F, 0xF92F, 0xF931, 0x1, 0x1, 0x0, 0x1, 0x1, 0x1, 0x2807, 0xA09F, 0xF92F, 0xF931, 0xF931, 0xF933, 0xF9B5, 0xF9F9, 0xFA3B, 0xFA3D, 0xFA7D, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xDA35, 0x1, 0x1, 0x0, 0x1, 0x1, 0x1, 0x2809, 0xA1A7, 0xFABD, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xD235, 0x1, 0x1, 0x0,
    0x0, 0x0, 0x1, 0x1, 0xA01B, 0xF86B, 0xF86B, 0xF86B, 0xF86D, 0xF86D, 0xF8AD, 0x9019, 0x1, 0x9019, 0xF8AD, 0xF8AD, 0xF8AD, 0xF8ED, 0xF8ED, 0xF8EF, 0xF8EF, 0xF8EF, 0xF8EF, 0xF8EF, 0xF8EF, 0xC0A1, 0x1, 0x2807, 0xF92F, 0xF92F, 0xF92F, 0xF931, 0xF931, 0xF931, 0xD0E5, 0x1, 0x1, 0x1, 0x1, 0x7055, 0xF931, 0xF931, 0xF931, 0xF931, 0xF973, 0xF9B7, 0xF9F9, 0x1, 0x1, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x9163, 0xC9F1, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0x58D7, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x8963, 0xC231, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0x50D7, 0x1, 0x1,
    0x0, 0x0, 0x1, 0x1, 0xB05F, 0xF8EF, 0xF8EF, 0xF8EF, 0xF8EF, 0xF8EF, 0xF8EF, 0x7013, 0x1, 0x2807, 0xF92F, 0xF92F, 0xF92F, 0xF931, 0xF931, 0xF931, 0xF931, 0xF931, 0xF931, 0xF931, 0xF931, 0x5811, 0x1, 0x1, 0xF931, 0xF933, 0xF9B5, 0xF9F9, 0xFA3B, 0xFA3D, 0xF239, 0x1, 0x1, 0x1, 0x1, 0x70DB, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x2009, 0x8963, 0xE277, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0x99A7, 0x1, 0x1, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x2009, 0x8163, 0xD277, 0xF2BF, 0xF2BF, 0xF2BF, 0xF2BF, 0xF2BF, 0xF2BF, 0xF2BF, 0xF2BF, 0x91A7, 0x1, 0x1,
    0x0, 0x0, 0x1, 0x1, 0xD8E7, 0xF931, 0xF931, 0xF931, 0xF931, 0xF931, 0xF931, 0x1, 0x1, 0x1, 0xC0E3, 0xF973, 0xF9B7, 0xF9F9, 0xFA3B, 0xFA7D, 0xFA7F, 0xFABF, 0xFABF, 0xFABF, 0xDA35, 0x1, 0x1, 0x1, 0xDA35, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0x1, 0x1, 0x1, 0x1, 0x691B, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x99A7, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xF2BF, 0xB1EF, 0x1, 0x1, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x91A7, 0xF2BF, 0xF2BF, 0xEABF, 0xEABF, 0xEABF, 0xEABF, 0xEABF, 0xA9EF, 0x1, 0x1,
    0x0, 0x0, 0x1, 0x1, 0xFA39, 0xFA7D, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFA7D, 0x1, 0x1, 0x1, 0x68DB, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0x9163, 0x1, 0x1, 0x1, 0xCA31, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0x691B, 0x1, 0x1, 0x1, 0x691B, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0x1, 0x1, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0xD279, 0xF2BF, 0xF2BF, 0xF2BF, 0xF2BF, 0xF2BF, 0xF2BF, 0xC235, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0xCA39, 0xE2BF, 0xE2BF, 0xE2BF, 0xE2BF, 0xE2BF, 0xE2BF, 0xBA35, 0x1, 0x1,
    0x0, 0x1, 0x1, 0x4051, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xFABF, 0xD235, 0x1, 0x1, 0x1, 0x1, 0xEABB, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xF2BD, 0x1, 0x1, 0x1, 0x1, 0x99A7, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0x8963, 0x1, 0x1, 0x1, 0x611B, 0xF2BF, 0xF2BF, 0xF2BF, 0xF2BF, 0xF2BF, 0xF2BF, 0xF2BF, 0x1, 0x1, 0x0, 0x1, 0x1, 0xA1AB, 0x711F, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0xC235, 0xEABF, 0xEABF, 0xEABF, 0xEABF, 0xEABF, 0xEABF, 0xA1EF, 0x1, 0x1, 0x1, 0x1, 0x99AB, 0x691F, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0xBA35, 0xE2BF, 0xE2BF, 0xE2BF, 0xE27F, 0xDA7F, 0xDA7F, 0xA1AF, 0x1, 0x1,
    0x0, 0x1, 0x1, 0x691B, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xB9EF, 0x1, 0x1, 0x1, 0x1, 0x99A7, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xA1EB, 0x1, 0x1, 0x1, 0x1, 0x711F, 0xF2BF, 0xF2BF, 0xF2BF, 0xF2BF, 0xF2BF, 0xF2BF, 0x91A7, 0x1, 0x1, 0x1, 0x60DB, 0xF2BF, 0xF2BF, 0xF2BF, 0xEABF, 0xEABF, 0xEABF, 0xEABF, 0x1, 0x1, 0x1, 0x1, 0x3851, 0xEABF, 0xEABF, 0x99AB, 0x200B, 0x1, 0x1, 0x1, 0x1, 0x1, 0x4897, 0xE2BF, 0xE2BF, 0xE2BF, 0xE2BF, 0xE2BF, 0xE2BF, 0xE2BF, 0x8967, 0x1, 0x1, 0x1, 0x3851, 0xDA7F, 0xDA7F, 0x91AB, 0x200B, 0x1, 0x1, 0x1, 0x1, 0x1, 0x4897, 0xDA7F, 0xDA7F, 0xDA7F, 0xDA7F, 0xDA7F, 0xDA7F, 0xD27F, 0x8167, 0x1, 0x1,
    0x0, 0x1, 0x1, 0x99A7, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0xFAFF, 0x91A7, 0x1, 0x1, 0x1, 0x1, 0x3891, 0xF2BF, 0xF2BF, 0xF2BF, 0xF2BF, 0xF2BF, 0xF2BF, 0xF2BF, 0x3851, 0x1, 0x1, 0x1, 0x1, 0x60DB, 0xEABF, 0xEABF, 0xEABF, 0xEABF, 0xEABF, 0xEABF, 0xBA35, 0x1, 0x1, 0x1, 0x60DB, 0xE2BF, 0xE2BF, 0xE2BF, 0xE2BF, 0xE2BF, 0xE2BF, 0xE2BF, 0x1, 0x1, 0x1, 0x1, 0xA9F1, 0xE2BF, 0xE2BF, 0xE2BF, 0xD27F, 0xA1EF, 0x7963, 0x58DB, 0x58DB, 0x8967, 0xD27F, 0xDA7F, 0xDABF, 0xDABF, 0xDA7F, 0xDA7F, 0xDA7F, 0xDA7F, 0x58DB, 0x1, 0x1, 0x1, 0xA1F3, 0xDA7F, 0xDA7F, 0xD27F, 0xCA7F, 0x99AF, 0x7125, 0x58DB, 0x58DB, 0x8167, 0xCA7F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0x50DB, 0x1, 0x1,
    0x0, 0x1, 0x1, 0xA9EF, 0xF2BF, 0xF2BF, 0xF2BF, 0xF2BF, 0xF2BF, 0xF2BF, 0x60DB, 0x1, 0x1, 0x0, 0x1, 0x1, 0xB1F1, 0xEABF, 0xEABF, 0xEABF, 0xEABF, 0xEABF, 0xB1F1, 0x1, 0x1, 0x0, 0x1, 0x1, 0x1, 0xE2BF, 0xE2BF, 0xE2BF, 0xE2BF, 0xE2BF, 0xE2BF, 0xD27B, 0x1, 0x1, 0x1, 0x58DB, 0xE2BF, 0xE2BF, 0xE2BF, 0xE2BF, 0xE27F, 0xDA7F, 0xDA7F, 0x1, 0x1, 0x1, 0x58DB, 0xDA7F, 0xDA7F, 0xDA7F, 0xDA7F, 0xDA7F, 0xDA7F, 0xDA7F, 0xDA7F, 0xDA7F, 0xDA7F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xC23B, 0x1, 0x1, 0x1, 0x50DB, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0xBA3B, 0x1, 0x1, 0x1,
    0x0, 0x1, 0x1, 0xC235, 0xEABF, 0xEABF, 0xEABF, 0xEABF, 0xEABF, 0xEABF, 0x5097, 0x1, 0x1, 0x0, 0x1, 0x1, 0x691F, 0xE2BF, 0xE2BF, 0xE2BF, 0xE2BF, 0xE2BF, 0x691F, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0xD27F, 0xE27F, 0xDA7F, 0xDA7F, 0xDA7F, 0xDABF, 0xDABF, 0x1, 0x1, 0x1, 0x58DB, 0xDA7F, 0xDA7F, 0xDA7F, 0xDA7F, 0xDA7F, 0xDA7F, 0xDA7F, 0x1, 0x1, 0x1, 0xA9F5, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0x6121, 0x1, 0x1, 0x1, 0xA9F5, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA3F, 0xCA3F, 0xCA3F, 0xCA3F, 0xCA3F, 0xCA3F, 0x60E1, 0x1, 0x1, 0x0,
    0x0, 0x1, 0x1, 0xE2BF, 0xE2BF, 0xE2BF, 0xE2BF, 0xE2BF, 0xE2BF, 0xE2BF, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0x1, 0xCA7B, 0xDA7F, 0xDABF, 0xDABF, 0xCA7B, 0x1, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0xB1F5, 0xDA7F, 0xDA7F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0x58DB, 0x1, 0x1, 0x58DB, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0x1, 0x1, 0x4097, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0x91AF, 0x1, 0x1, 0x1, 0x4097, 0xCA3F, 0xCA3F, 0xCA3F, 0xCA3F, 0xCA3F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0x896F, 0x1, 0x1, 0x1, 0x0,
    0x1, 0x1, 0x3851, 0xDA7F, 0xDA7F, 0xDABF, 0xDABF, 0xDA7F, 0xDA7F, 0xCA3B, 0x1, 0x1, 0x0, 0x0, 0x0, 0x1, 0x1, 0x91AB, 0xD27F, 0xD27F, 0xD27F, 0x8167, 0x1, 0x1, 0x0, 0x0, 0x0, 0x1, 0x1, 0x896B, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0x7125, 0x1, 0x1, 0x50DB, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0x1, 0x1, 0x1, 0x50DB, 0xBA3B, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA3F, 0xCA3F, 0xCA3F, 0xCA3F, 0xCA3F, 0xCA3F, 0xCA3F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0x816B, 0x1, 0x1, 0x1, 0x1, 0x1, 0x509B, 0xB1FB, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0x816B, 0x1, 0x1, 0x1, 0x0, 0x0,
    0x1, 0x1, 0x58DB, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xD27F, 0xA9F5, 0x1, 0x1, 0x0, 0x0, 0x0, 0x1, 0x1, 0x3051, 0xD27F, 0xD27F, 0xD27F, 0x3051, 0x1, 0x1, 0x0, 0x0, 0x0, 0x1, 0x1, 0x7969, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0xCA7F, 0x7969, 0x1, 0x1, 0x50DB, 0xCA3F, 0xCA3F, 0xCA3F, 0xCA3F, 0xCA3F, 0xCA3F, 0xCA3F, 0x1, 0x1, 0x1, 0x1, 0x1, 0x6925, 0xA1F5, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0x99B5, 0x509B, 0x1, 0x1, 0x1, 0x0, 0x1, 0x1, 0x1, 0x1, 0x6925, 0x99B5, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0xC23F, 0x99B5, 0x509B, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0,
    0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x3051, 0x6925, 0x7129, 0x99B5, 0x99B5, 0x99B5, 0x99B5, 0x816B, 0x6925, 0x3051, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x3051, 0x6925, 0x7129, 0x99B5, 0x99B5, 0x99B5, 0x99B5, 0x816B, 0x6925, 0x3051, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
  }
};