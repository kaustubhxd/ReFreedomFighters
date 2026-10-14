// batch34130.cpp - cascade tier E, batch 34130: 0x646350 (checked lookup with error print), 0x497320 (pointer to handle).
#include "ff.h"

extern "C" void THISCALL ext_4de7a0(void *self);
extern "C" u32 THISCALL ext_497670(void *self, u32 p);     // ret 4
extern "C" u32 THISCALL ext_4964e0(void *self, u32 p);     // ret 4
extern "C" void THISCALL ext_499810(void *self, u32 p, u32 h);   // ret 8

// 0x646350, thiscall(a, b, c, d) ret 0x10: t = [[0x70039c]+0x1aa3]->[+0x18]->slot0xc8([[d+8]+0x6c]); when this->slot0x10(a, b, byte t[c], d) returns false (low byte):
// ext_4de7a0(a), clears the three dwords at b, then p = [0x700390]->slot0x20(0x6c2904, 0x104) and p->slot0x2c(p, 0x6c2988, c) (cdecl, ecx = vtable).
static void THISCALL fn646350(u8 *self, u32 a, u32 *b, u32 c, u8 *d) {
  u8 *eng = *(u8 **)(G(u8 *, 0x70039c) + 0x1aa3);
  u8 *sub = *(u8 **)(eng + 0x18);
  u8 *t = vcall<u8 *>(sub, 0xc8, *(u32 *)(*(u8 **)(d + 8) + 0x6c));
  u8 v = t[c];
  if (!(u8)vcall<u32>(self, 0x10, a, (u32)b, (u32)v, (u32)d)) {
    ext_4de7a0((void *)a);
    b[0] = 0;
    b[1] = 0;
    b[2] = 0;
    u8 *p = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x6c2904u, 0x104u);
    typedef void (*pf)(u8 *, u32, u32);
    (*(pf *)(*(u8 **)p + 0x2c))(p, 0x6c2988, c);
  }
}
PCREG(646350, fn646350);

// 0x497320, thiscall(p) ret 4: 0 for null; when [this+0x24] is set and p >= [[this+0x14]+4] + [this+0x28]: h = ext_497670(p), else-if zero h = ext_4964e0(p) followed by ext_499810(p, h); returns h.
// Otherwise returns (p - [[this+0x14]+4]) | 0x40000000.
static u32 THISCALL fn497320(u8 *self, u32 p) {
  if (!p) return 0;
  u32 base = *(u32 *)(*(u8 **)(self + 0x14) + 4);
  if (*(u32 *)(self + 0x24) && p >= base + *(u32 *)(self + 0x28)) {
    u32 h = ext_497670(self, p);
    if (h) return h;
    h = ext_4964e0(self, p);
    ext_499810(self, p, h);
    return h;
  }
  return (p - base) | 0x40000000;
}
PCREG(497320, fn497320);
