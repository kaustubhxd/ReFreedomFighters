// batch67559.cpp - cascade s6 batch 67559: 0x639fb0.
#include "ff.h"

extern "C" void THISCALL ext_638ea0(u32 *s, u32 w, u32 h, u32 d);     // Morton mask builder, ret 0xc
extern "C" u8 *ext_41e290(u32 n);                                      // alloc, cdecl
extern "C" void ext_634d22(u8 *dst, u8 *src, u32 n);                   // memcpy thunk, cdecl
extern "C" void ext_634273(u8 *p, u32 n);                              // free, cdecl

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x639fb0, thiscall() plain ret: swizzles the mip levels of a texture description. this[0x10] levels of 0x14 bytes at this[0x14]; each has width +4, height +8 and a byte pointer +0x10. 0x638ea0 builds
// the Morton masks for (width, height); a scratch buffer of width*height bytes receives the linear bytes in swizzled order (x mask stepping inside a row, y mask stepping per row), is copied back
// over the level's data (0x634d22) and freed.
static void THISCALL fn639fb0(u8 *self) {
  u32 s[9];
  int count = (int)D32(self, 0x10);
  if (count <= 0) return;
  for (int lv = 0; lv < count; lv++) {
    u8 *ent = *(u8 **)(self + 0x14) + lv * 0x14;
    ext_638ea0(s, D32(ent, 4), D32(ent, 8), 0);
    u8 *buf = ext_41e290(D32(ent, 4) * D32(ent, 8));
    u32 lin = 0;
    u32 y = 0;
    u8 *dest = *(u8 **)(ent + 0x10);
    int h = (int)D32(ent, 8);
    if (h > 0) {
      for (int row = 0; row < h; row++) {
        u32 x = 0;
        int w = (int)D32(*(u8 **)(self + 0x14) + lv * 0x14, 4);
        for (int col = 0; w > 0 && col < w;) {
          buf[y | x] = dest[lin];
          x = (x - s[3]) & s[3];
          lin++;
          col++;
          w = (int)D32(*(u8 **)(self + 0x14) + lv * 0x14, 4);
        }
        y = (y - s[4]) & s[4];
      }
    }
    ent = *(u8 **)(self + 0x14) + lv * 0x14;
    ext_634d22(dest, buf, D32(ent, 8) * D32(ent, 4));
    ext_634273(buf, 1);
  }
}
PCREG(639fb0, fn639fb0);
