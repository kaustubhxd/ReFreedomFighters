#include "ff.h"
// batch3546.cpp - slice 14, batch 46 (docs/20-gap-band-561000.md): seven small bodies (GUESS names).
// Stubbed in the harness: 0x634273 (cdecl, two args), 0x64f380, 0x63ab30, 0x469870 (thiscall, no args), 0x62f980 (stdcall,
// one arg), 0x5003d0 and 0x5a46f0 (thiscall, one arg, return pointers).

extern "C" void ext_634273(u32 a0, u32 a1);
extern "C" void STDCALL ext_62f980(u32 a0);
extern "C" void THISCALL ext_64f380(u8 *self);
extern "C" void THISCALL ext_63ab30(u8 *self);
extern "C" void THISCALL ext_469870(u8 *self);
extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 a0);
extern "C" u8 *THISCALL ext_5a46f0(u8 *self, u32 a0);

u8 *THISCALL gapDtor549420(u8 *self, u32 a0) {
  *(u32 *)self = 0x6a3234;
  if ((a0 & 1) != 0)
    ext_634273((u32)self, 0x40b1);
  return self;
}
PCREG(549420, gapDtor549420);

u8 *THISCALL gapDtor64f5e0(u8 *self, u32 a0) {
  ext_64f380(self);
  if ((a0 & 1) != 0)
    ext_634273((u32)self, 0x12f);
  return self;
}
PCREG(64f5e0, gapDtor64f5e0);

u8 *THISCALL gapDtor65a3a0(u8 *self, u32 a0) {
  ext_63ab30(self);
  if ((a0 & 1) != 0)
    ext_634273((u32)self, 0xb9a8);
  return self;
}
PCREG(65a3a0, gapDtor65a3a0);

u8 *THISCALL gapCtor4fb9a0(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x69c428;
  *(u32 *)(self + 0x48) = 0;
  *(u32 *)(self + 0x4c) = 0;
  *(u32 *)(self + 0x50) = 0;
  return self;
}
PCREG(4fb9a0, gapCtor4fb9a0);

void STDCALL gap4d61a0(u8 *p) {
  ext_62f980(*(u32 *)(p + 0x26));
  ext_634273((u32)p, 4);
}
PCREG(4d61a0, gap4d61a0);

u8 *STDCALL gap55ffe0(u8 *p) {
  u8 *r = ext_5003d0(*(u8 **)(p + 4), 0);
  u8 *mgr = *(u8 **)0x7003b8;
  u8 *q = ext_5a46f0(*(u8 **)(mgr + 0x2c21), *(u32 *)r);
  if (q != 0)
    *q = 1;
  return q;
}
PCREG(55ffe0, gap55ffe0);

u32 gap62d260(u8 *p, u32 code) {
  if (code == 0xf)
    return 0;
  if (code == 0x12 || code == 0x29) {
    *(u32 *)p = 0x62d2b0;
    return 0x23;
  }
  if (*(u32 *)(p + 0xc) == 0 && code == 0x1c)
    return 0x34;
  *(u32 *)p = 0x51f230;
  return 0xffffffffu;
}
PCREG(62d260, gap62d260);
