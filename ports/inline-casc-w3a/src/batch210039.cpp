// batch210039.cpp - Sonnet-w3a: small BLOCKED rows (record cache update with dirty flag, state reset with engine lookup)
#include "ff.h"

extern "C" u32 THISCALL ext_64fc60(u8 *self);

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *mgr() { return (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b); }

static void upd_rec(u8 *self, u8 *rec, u32 a, u32 b, u32 c, u32 d) {
  if (*(u32 *)(rec + 4) != a || *(u32 *)(rec + 8) != b || (int)*(short *)(rec + 0xc) != (int)c || (int)*(short *)(rec + 0xe) != (int)d)  // @5ed1e0_a
    self[0xa6] = 1;  // @5ed1e0_b
  *(u16 *)(rec + 0xc) = (u16)c;  // @5ed1e0_c
  *(u32 *)(rec + 4) = a;
  *(u32 *)(rec + 8) = b;  // @5ed1e0_d
  *(u16 *)(rec + 0xe) = (u16)d;  // @5ed1e0_e
}

static u32 THISCALL fn5ed1e0(u8 *self, u32 a, u32 b, u32 c, u32 d, int e) {
  if (e == -1) {  // @5ed1e0_f
    u8 **cur = (u8 **)ld32(self + 0xcb);
    u8 **end = (u8 **)ld32(self + 0xcf);
    if (cur == end) return 0;
    do {
      upd_rec(self, *cur, a, b, c, d);
      cur++;
    } while (cur != end);  // @5ed1e0_g
    return d;
  }
  u8 *rec = ((u8 **)ld32(self + 0xcb))[e];  // @5ed1e0_h
  upd_rec(self, rec, a, b, c, d);
  return a;
}
PCREG(5ed1e0, fn5ed1e0);

static u32 THISCALL fn5d5b40(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  (void)c; (void)d;
  if (self[0x31]) {  // @5d5b40_a
    if (ld32(self + 0x2d) > 1) {  // @5d5b40_b
      vcall<u32, u32, u32>(self, 0x110, 0x10, 0);  // @5d5b40_c
      u8 *m = (u8 *)ld32(self + 0x25);
      if (m) vcall<u32>(m, 0x2c);  // @5d5b40_d
      self[0x18] = 1;  // @5d5b40_e
    }
    __builtin_memset(self + 0x2d, 0, 4);  // @5d5b40_f
  }
  u8 *p = (u8 *)ld32(self + 0x19);
  if (!p) return 0;
  vcall<u32, u32, u32>(p, 4, a, b);  // @5d5b40_g
  u32 x = ext_64fc60((u8 *)ld32(self + 0x19));  // @5d5b40_h
  u32 y = ext_64fc60((u8 *)ld32(self + 0x19));
  if (y < ld32(self + 0x32)) {  // @5d5b40_i
    u8 *g = (u8 *)vcall<u32>(mgr(), 0x138);
    u32 local = 0;
    vcall<u32, u32, u32 *>(g, 0x88, 0x6b588c, &local);  // @5d5b40_j
    u8 *vt = *(u8 **)self;
    u32 ax = vcall<u32, u32, u32, u32, u32, u32>(mgr(), 0x114, 0x6b587c, 0, 0x6b583c, 0x98, 0) & 0xffff;  // @5d5b40_k
    typedef u32 (THISCALL *F)(u8 *, u32, u32);
    (*(F *)(vt + 0x12c))(self, local, ax);  // @5d5b40_l
  }
  __builtin_memcpy(self + 0x32, &x, 4);  // @5d5b40_m
  return 0;
}
PCREG(5d5b40, fn5d5b40);
