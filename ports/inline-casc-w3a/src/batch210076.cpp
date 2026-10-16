// batch210076.cpp - Sonnet-w3a: 0x4d3f10 (constructor: copy n dwords into a new array and sort them through the import at 0x676450)
#include "ff.h"

extern "C" u32 ext_41e290(u32 n);
extern "C" u32 ext_634d22(u32 dst, u32 src, u32 n);

typedef void (*QSort)(u32 base, u32 num, u32 size, u32 cmp);

static u8 *THISCALL fn4d3f10(u8 *self, u32 src, u32 n) {
  *(u32 *)(self + 8) = n;
  *(u32 *)self = 0x6965c0;  // @4d3f10_vt
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x10) = 0;
  u32 bytes = (n > 0x3fffffffu) ? 0xffffffffu : n * 4;  // @4d3f10_a
  u32 buf = ext_41e290(bytes);
  u32 sz = *(u32 *)(self + 8) << 2;  // @4d3f10_b
  *(u32 *)(self + 4) = buf;
  ext_634d22(buf, src, sz);  // @4d3f10_c
  G(QSort, 0x676450)(*(u32 *)(self + 4), *(u32 *)(self + 8), 4, 0x4cc600);  // @4d3f10_d
  return self;
}
PCREG(4d3f10, fn4d3f10);
