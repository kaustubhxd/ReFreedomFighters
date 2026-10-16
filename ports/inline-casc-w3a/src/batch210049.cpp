// batch210049.cpp - Sonnet-w3a: /GS-protected message formatter with a failure report
#include "ff.h"

extern "C" void FASTCALL ext_633654(u32 cookie);  // /GS check
extern "C" u32 THISCALL ext_563710(u8 *self, u32 a, void *buf);

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static void THISCALL fn56d750(u8 *self) {
  u8 buf[0x100];
  u8 *o = (u8 *)vcall<u32>(G(u8 *, 0x70039c), 0x190);  // @56d750_a
  u8 *m = *(u8 **)(ld32(G(u8 *, 0x70039c) + 0x9b) + 0xae4);
  typedef u32 (THISCALL *S2)(u8 *, u32, u32);
  typedef int (*F)(u8 *, void *, u32, u32, u32, u32);
  F *fp = (F *)(*(u8 **)o + 0x198);
  u32 r1 = (*(S2 *)(*(u8 **)m))(m, 0x6a6760, 0x6a8070);  // @56d750_b
  u32 x3 = ld32(self + 0x1b6) * 3;  // @56d750_c
  u32 r2 = (*(S2 *)(*(u8 **)m))(m, 0x6a67e8, 0x6a8078);  // @56d750_d
  int r = (*fp)(o, buf, 0x6a8084, r2, x3, r1);  // @56d750_e
  if (r < 0) {  // @56d750_f
    u8 *g = G(u8 *, 0x700390);
    u8 *o2 = (u8 *)vcall<u32, u32, u32>(g, 0x20, 0x6a8040, 0xfc);  // @56d750_g
    typedef u32 (*F2)(u8 *, u32);
    F2 f2 = *(F2 *)(*(u8 **)o2 + 0x2c);
    f2(o2, 0x6a8090);  // @56d750_h
  }
  ext_563710(self, *(u32 *)(self + 0x180), buf);  // @56d750_i
  ext_633654(0);
}
PCREG(56d750, fn56d750);
