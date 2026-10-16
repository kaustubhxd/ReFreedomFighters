// batch210077.cpp - Sonnet-w3a: 0x4d2b40 (find the record whose flagged name of the given length matches, via the import at 0x67640c)
#include "ff.h"

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

typedef int (*MemCmp)(const u8 *a, const u8 *b, u32 n);

static u8 *THISCALL fn4d2b40(u8 *self, const u8 *str, u32 len) {
  if (!len) {  // @4d2b40_a
    u32 n = 0;
    while (str[n]) n++;
    len = n + 1;
  }
  u32 off = 0;
  if (ld32(self + 0xc) <= off) return 0;  // @4d2b40_b
  for (;;) {
    u8 *rec = (u8 *)ld32(self + 8) + off;
    off += ld32(rec);  // @4d2b40_c
    if (rec[4] != 0 && ld32(rec + 5) == len) {  // @4d2b40_d
      if (G(MemCmp, 0x67640c)(str, rec + 0x11, len) == 0) return rec;  // @4d2b40_e
    }
    if (off >= ld32(self + 0xc)) break;  // @4d2b40_f
  }
  return 0;
}
PCREG(4d2b40, fn4d2b40);
