// batch210044.cpp - Sonnet-w3a: small BLOCKED row (forward then iterate a stack cursor filled by slots)
#include "ff.h"

extern "C" u32 THISCALL ext_45faf0(u8 *self, u32 a, u32 b, u32 c);

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *mgr() { return (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b); }

static u32 THISCALL fn44a710(u8 *self, u32 a, u32 b, u32 c) {
  u32 buf[3];
  ext_45faf0(self, a, b, c);  // @44a710_a
  u8 *m = *(u8 **)(self + 0x18);
  if (!m) return 0;  // @44a710_b
  vcall<u32, u32 *>(m, 0x4c, buf);  // @44a710_c
  u32 r = vcall<u32, u32 *>(*(u8 **)(self + 0x18), 0x5c, buf);  // @44a710_d
  while (buf[0] != 0) {  // @44a710_e
    u8 *o = (u8 *)vcall<u32, u32>(mgr(), 0x58, r);  // @44a710_f
    if (o) vcall<u32, u32, u32, u32>(o, 0x138, a, b, c);  // @44a710_g
    r = vcall<u32, u32 *>(*(u8 **)(self + 0x18), 0x5c, buf);  // @44a710_h
  }
  return 0;
}
PCREG(44a710, fn44a710);
