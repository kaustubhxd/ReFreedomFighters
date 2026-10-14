// batch33095.cpp - h3 () batch 33095: tier H float/SSE functions
#include "ff.h"

static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 R32(u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

// 0x607da0: thiscall(a, u32 *b, u32 *c, d) ret 0x10, returns this: init fields; a->slot 0x5c(a, 36*[this+4], d|0x208, [this+0x26], 0, this)
static u8 *THISCALL fn607da0(u8 *self, u8 *a, u32 *b, u32 *c, u32 d) {
  W32(self, 0);
  W32(self + 8, 0);
  self[0x10] = 0; self[0x11] = 1;
  W32(self + 0xc, 0);
  W32(self + 4, c[0]);
  for (int i = 0; i < 0x18; i++) self[0x12 + i] = 0;
  W32(self + 0x12, 0x64);
  u32 n = c[0];
  W32(self + 0x16, 6);
  W32(self + 0x1e, 0);
  W32(self + 0x22, n * 36u);
  W32(self + 0x26, b[0]);
  u32 v26 = R32(self + 0x26);
  u32 fl = d | 0x208u;
  W32(self + 0x1a, fl);
  u32 sz = R32(self + 4) * 36u;
  vcall<u32>(a, 0x5c, (u32)a, sz, fl, v26, 0u, (u32)self);
  return self;
}
PCREG(607da0, fn607da0);
