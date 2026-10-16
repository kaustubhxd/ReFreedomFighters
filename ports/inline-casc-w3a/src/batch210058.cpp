// batch210058.cpp - Sonnet-w3a: 0x4367b0 (constructor from a descriptor: zero the packed fields, base init, flags, up to four attach calls)
#include "ff.h"

static inline void st32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" u32 THISCALL ext_439e50(u8 *self, u32 a);
extern "C" u32 THISCALL ext_4386a0(u8 *self, u32 a, u32 b);
extern "C" u32 THISCALL ext_4379f0(u8 *self, u32 a, u32 b);

static u8 *THISCALL fn4367b0(u8 *self, u32 a, u8 *d) {
  st32(self + 4, 0);
  st32(self + 8, 0);
  st32(self + 0xc, 0);
  st32(self, 0x67a7dc);  // @4367b0_vt
  st32(self + 0x1d, 0);
  st32(self + 0x21, 0);
  st32(self + 0x25, 0);
  st32(self + 0x29, 0);
  st32(self + 0x2d, 0);
  self[0x32] &= 0xfd;  // @4367b0_a
  ext_439e50(self, a);
  u32 e = ld32(d);
  if (e) st32(self + 8, e);  // @4367b0_b
  if (!ld32(d + 8) && !ld32(d + 0xc) && !ld32(d + 0x10) && !ld32(d + 0x14)) {  // @4367b0_c
    self[0x32] |= 4;  // @4367b0_d
    return self;
  }
  self[0x32] &= 0xfb;  // @4367b0_e
  u32 fl = ld32(d + 0x18);
  u8 al = self[0x32];
  if (fl & 1) self[0x3d] = 1;  // @4367b0_f
  if (fl & 4) al |= 8;  // @4367b0_g
  else al &= 0xf7;
  self[0x32] = al;
  st32(self + 0x35, ld32(d + 4));  // @4367b0_h
  u32 p;
  if ((p = ld32(d + 0x10)) != 0) ext_4386a0(self, p, 1);  // @4367b0_i
  if ((p = ld32(d + 0x14)) != 0) ext_4386a0(self, p, 0);  // @4367b0_j
  if ((p = ld32(d + 8)) != 0) ext_4379f0(self, p, 1);  // @4367b0_k
  if ((p = ld32(d + 0xc)) != 0) ext_4379f0(self, p, 0);  // @4367b0_l
  return self;
}
PCREG(4367b0, fn4367b0);
