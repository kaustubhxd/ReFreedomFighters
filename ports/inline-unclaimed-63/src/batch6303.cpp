// batch6303.cpp - unclaimed-63 batch 3 (docs/20-unclaimed-63.md): two functions with stubbed callees.
//   0x4dcda0 (GC name ZBaseGeom::SetPrev, medium; the body is not a setter): if the argument a is nonzero,
//     v = [[[0x70039c]+0x9b]+8]->vtbl[+0x4c](); d = a - v; q = high(0x92492493 * d) + d, sar 6; the 16-bit result is
//     q + (q >> 31 unsigned) + 1, stored at this+0x5e. If a is zero the stored value is 0.
//   0x4d9ce0 ZBaseGeom::AttachToDynamicContainer() (high): if byte [this+0x3c] is set: a = [this+0x50];
//     c = [[a+0x54]+8] (a must be nonzero); p = 0x4daff0(c) (original, one ECX argument); if p, [this+0x64] = p->vtbl[+0x318](this).
#include "ff.h"

extern "C" u32 THISCALL ext_4daff0(void *c);   // original code, stubbed by the spec

typedef u32(THISCALL * call0_fn)(void *);
typedef u32(THISCALL * call1_fn)(void *, u32);

// 0x4dcda0 (GC name ZBaseGeom::SetPrev, medium, GUESS). Signed multiply by the magic 0x92492493 (a division by 7).
static void THISCALL unnamed4dcda0(u8 *self, u32 a) {
  if (a != 0) {
    u32 rm = G(u32, 0x70039c);
    u32 o = *(u32 *)(rm + 0x9b);
    u32 p = *(u32 *)(o + 8);
    u32 v = ((call0_fn)(*(u32 *)(*(u32 *)p + 0x4c)))((void *)p);
    s32 d = (s32)(a - v);
    long long prod = (long long)(s32)0x92492493u * (long long)d;
    s32 q = (s32)(prod >> 32) + d;
    q >>= 6;
    u32 res = (u32)q + ((u32)q >> 31) + 1;
    *(u16 *)(self + 0x5e) = (u16)res;
  } else {
    *(u16 *)(self + 0x5e) = 0;
  }
}
PCREG(4dcda0, unnamed4dcda0);

// 0x4d9ce0, ZBaseGeom::AttachToDynamicContainer() (high). a must be nonzero when the byte is set (the PC reads [0+8] otherwise).
static void THISCALL baseGeomAttachToDynamicContainer(u8 *self) {
  if (self[0x3c] != 0) {
    u32 a = *(u32 *)(self + 0x50);
    u32 b = *(u32 *)(a + 0x54);
    u32 c = *(u32 *)(b + 8);
    u32 p = ext_4daff0((void *)c);
    if (p != 0) {
      u32 vt = *(u32 *)p;
      *(u32 *)(self + 0x64) = ((call1_fn)(*(u32 *)(vt + 0x318)))((void *)p, (u32)self);
    }
  }
}
PCREG(4d9ce0, baseGeomAttachToDynamicContainer);
