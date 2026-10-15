// batch66056.cpp - cascade s4 batch 66056: 0x401350 (tier F row).
#include "ff.h"

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" s32 ext_410de0(void *stream, u32 nbits);   // cdecl bit reader
extern "C" void ext_4010c0(void *a);                  // cdecl

// 0x401350, cdecl(a, stream), returns 0 or an error code: a[0x1c] == 0 -> 0xffffff7f. a[0] = bits(32) nonzero -> 0xffffff7a. a[4] = bits(8); a[8], a[0xc], a[0x10], a[0x14] = bits(32); c = a[0x1c]; c[0] = 1 << bits(4); c[4] = 1 << bits(4).
// a[8] < 1, a[4] < 1, c[0] < 8, c[4] < c[0] or bits(1) != 1 -> 0x4010c0(a), 0xffffff7b. Otherwise 0.
extern "C" s32 fn401350(u8 *a, void *stream) {
  u8 *c = *(u8 **)(a + 0x1c);
  if (!c) return (s32)0xffffff7f;
  wr(a, ext_410de0(stream, 0x20));
  if (rd(a)) return (s32)0xffffff7a;
  wr(a + 4, ext_410de0(stream, 8));
  wr(a + 8, ext_410de0(stream, 0x20));
  wr(a + 0xc, ext_410de0(stream, 0x20));
  wr(a + 0x10, ext_410de0(stream, 0x20));
  wr(a + 0x14, ext_410de0(stream, 0x20));
  u32 s1 = (u32)ext_410de0(stream, 4);
  wr(c, 1u << (s1 & 31));
  u32 s2 = (u32)ext_410de0(stream, 4);
  u32 v2 = 1u << (s2 & 31);
  wr(c + 4, v2);
  s32 w = (s32)rd(a + 8);
  if (w >= 1 && (s32)rd(a + 4) >= 1) {
    s32 c0 = (s32)rd(c);
    if (c0 >= 8 && (s32)v2 >= c0) {
      if (ext_410de0(stream, 1) == 1) return 0;
    }
  }
  ext_4010c0(a);
  return (s32)0xffffff7b;
}
PCREG(401350, fn401350);
