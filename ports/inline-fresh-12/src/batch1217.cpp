// batch1217.cpp - fresh slice 12, batch 17. Exe callees run as ext_<hex>; the harness hooks and logs them.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_41e2c0(void *p);   // free, cdecl
extern "C" void THISCALL ext_469870(u8 *self);                // base constructor, ret 0
extern "C" void THISCALL ext_4ccba0(u8 *self);                // member constructor, ret 0

// 0x4d6040: releases three arrays {begin +0x46, end +0x4a, data +0x4e} style triples (+0x46..+0x4e, +0x52..+0x5a,
// +0x5e..+0x66: freed by the third word, all three cleared), then (+0x15) slot 4(+0x11), byte +8 = 0, and deletes
// +0x6a (slot 0(1)) and clears it.
static void THISCALL release4d6040(u8 *self) {
  for (u32 b = 0x46; b <= 0x5e; b += 0xc) {
    if (void *p = *(void **)(self + b + 8)) {
      ext_41e2c0(p);
      *(u32 *)(self + b + 8) = 0;
      *(u32 *)(self + b + 4) = 0;
      *(u32 *)(self + b) = 0;
    }
  }
  vcall<void>(*(u8 **)(self + 0x15), 4, *(u32 *)(self + 0x11));
  self[8] = 0;
  if (u8 *o = *(u8 **)(self + 0x6a)) {
    vcall<void>(o, 0, 1u);
    *(u32 *)(self + 0x6a) = 0;
  }
}
PCREG(4d6040, release4d6040);

// 0x63f800: pool free. --count (+0xc); page d = this slot 0x2c(p); p's byte 5 bit 1 cleared; p's first word = page's
// free head (word +2), page free head = (p - d - 0x10) >> 3; --page used count (byte 0). Empty page: off the ring
// (+8 next, +0xc prev; this+8 moves to next, or 0 if it was alone) and this slot 0x34(d). Else the page moves to the
// ring front (just before this+8) and becomes this+8. ret 4.
static void THISCALL free63f800(u8 *self, u8 *p) {
  --*(u32 *)(self + 0xc);
  u8 *d = vcall<u8 *>(self, 0x2c, p);
  p[5] &= 0xfd;
  u16 h = *(u16 *)(d + 2);
  --d[0];
  *(u16 *)p = h;
  *(u16 *)(d + 2) = (u16)((s32)(p - d - 0x10) >> 3);
  if (!d[0]) {
    if (*(u8 **)(self + 8) == d) {
      u8 *n = *(u8 **)(d + 8);
      *(u8 **)(self + 8) = n == d ? 0 : n;
    }
    *(u32 *)(*(u8 **)(d + 8) + 0xc) = *(u32 *)(d + 0xc);
    *(u32 *)(*(u8 **)(d + 0xc) + 8) = *(u32 *)(d + 8);
    vcall<void>(self, 0x34, d);
    return;
  }
  if (d == *(u8 **)(self + 8)) return;
  *(u32 *)(*(u8 **)(d + 8) + 0xc) = *(u32 *)(d + 0xc);
  *(u32 *)(*(u8 **)(d + 0xc) + 8) = *(u32 *)(d + 8);
  u8 *f = *(u8 **)(self + 8);
  *(u8 **)(d + 8) = f;
  u8 *b = *(u8 **)(f + 0xc);
  *(u8 **)(d + 0xc) = b;
  *(u8 **)(b + 8) = d;
  *(u8 **)(f + 0xc) = d;
  *(u8 **)(self + 8) = d;
}
PCREG(63f800, free63f800);

// 0x4a2ec0: constructor (SEH frame, ESI restored), null this -> 0. Base 0x469870, +4 |= 0x20, +0x44 = 0, vtable
// 0x68f088, +0x49 = +0x4d = 0, member at +0x59 gets vtable 0x68f068 and 0x4ccba0(+0x65). Returns this.
static u8 *THISCALL ctor4a2ec0(u8 *self) {
  if (!self) return 0;
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x68f088;
  *(u32 *)(self + 0x49) = 0;
  *(u32 *)(self + 0x4d) = 0;
  *(u32 *)(self + 0x59) = 0x68f068;
  ext_4ccba0(self + 0x65);
  return self;
}
PCREG(4a2ec0, ctor4a2ec0);
