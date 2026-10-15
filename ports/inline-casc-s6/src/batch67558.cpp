// batch67558.cpp - cascade s6 batch 67558: 0x467260.
#include "ff.h"

extern "C" void THISCALL ext_44b610(u8 *o);                                         // plain ret
extern "C" void ext_44b740(u8 *o);                                                  // cdecl
extern "C" u32 THISCALL ext_43ec00(u8 *o, u32 *m, u32 *v, u32 a, u32 b, u32 z0, u32 z1);   // ret 0x18

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define SYS (*(u8 **)0x70039c)

// 0x467260, thiscall(a, b, c) ret 0xc, returns the new handle (0 when sys[0x1a9f] is unset): replaces the effect handle this[0x153]. The old one (object table slot 0x60) is shut down (0x44b610,
// 0x44b740) and cleared. The object's slot 0x3a0 fills a 9-dword matrix and 3-dword vector (stack locals), slot 0x390 is fed its result, slot 0x20 gives the creator on which 0x43ec00(matrix, vector, a,
// b, 0, 0) makes the new handle. A found record gets flag 0x80 in +0x40, mode 2 (+0x2c), the duration c - old+0x64 (+0x60) and c (+0x64); when sys[0x1a9f] slot 0x70(a) accepts it the three tuning
// floats +0x88 / +0x54 / +0x5c are set to 30.0 / 150.0 / 5760.0.
static u32 THISCALL fn467260(u8 *self, u32 a, u32 b, u32 c) {
  u32 m[9], v[3];
  if (D32(SYS, 0x1a9f) == 0) return 0;
  u32 id = D32(self, 0x153);
  if (id) {
    u8 *o = vcall<u8 *>(*(u8 **)(SYS + 0x9b), 0x60, id);
    if (o) {
      ext_44b610(o);
      ext_44b740(o);
    }
    D32(self, 0x153) = 0;
  }
  u32 r = vcall<u32>(self, 0x3a0, (u32)m, (u32)v);
  vcall<void>(self, 0x390, r);
  u8 *cr = vcall<u8 *>(self, 0x20);
  u32 h = ext_43ec00(cr, m, v, a, b, 0, 0);
  D32(self, 0x153) = h;
  u8 *o = vcall<u8 *>(*(u8 **)(SYS + 0x9b), 0x60, h);
  if (o) {
    u32 dur = c - D32(o, 0x64);
    D32(o, 0x40) |= 0x80;
    D32(o, 0x2c) = 2;
    D32(o, 0x60) = dur;
    D32(o, 0x64) = c;
    if ((u8)vcall<u32>(*(u8 **)(SYS + 0x1a9f), 0x70, a)) {
      D32(o, 0x88) = 0x41f00000u;
      D32(o, 0x54) = 0x43160000u;
      D32(o, 0x5c) = 0x45b40000u;
    }
  }
  return h;
}
PCREG(467260, fn467260);
