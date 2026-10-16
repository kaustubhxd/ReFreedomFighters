// batch210080.cpp - Sonnet-w3a: 0x4387a0 (find the element whose name equals a, or whose alias equals b, via the string-compare import)
#include "ff.h"

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" u8 *THISCALL ext_4cc1d0(u8 *self);

typedef int (*StrCmp)(const u8 *a, const u8 *b);

static u8 *THISCALL fn4387a0(u8 *self, const u8 *a, const u8 *b) {
  u8 *cont = (u8 *)ld32(self + 0x1338);
  if (!cont) return 0;  // @4387a0_a
  u32 it[3];
  vcall<u32, u32 *>(cont, 0x4c, it);  // @4387a0_b
  u8 *e = (u8 *)vcall<u32, u32 *>((u8 *)ld32(self + 0x1338), 0x64, it);  // @4387a0_c
  while (e) {
    StrCmp f = G(StrCmp, 0x676414);
    if (f(ext_4cc1d0(e), a) == 0) {  // @4387a0_d
      const u8 *alias = (const u8 *)ld32(e + 0xaf);
      if (!alias || f(b, alias) == 0) return e;  // @4387a0_e
    }
    e = (u8 *)vcall<u32, u32 *>((u8 *)ld32(self + 0x1338), 0x64, it);  // @4387a0_f
  }
  return 0;
}
PCREG(4387a0, fn4387a0);
