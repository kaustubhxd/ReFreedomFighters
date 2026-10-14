// batch32086.cpp - cascade h2 (): eight tier C wrappers (sixth batch).
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);               // thiscall ret 4
extern "C" void THISCALL ext_593f40(u8 *self, u32 a);              // thiscall ret 4
extern "C" u32 THISCALL ext_594040(u8 *self, u32 a, u32 b);        // thiscall ret 8
extern "C" u32 THISCALL ext_596ef0(u8 *self, u32 a, u32 b);        // thiscall ret 8
extern "C" u32 THISCALL ext_43de70(u8 *self);                      // thiscall, plain ret (tail jump target)
extern "C" void ext_634273(u32 p, u32 n);                          // free-style, cdecl
extern "C" void THISCALL ext_6493d0(u8 *self, u8 *p);              // thiscall ret 4
extern "C" void THISCALL ext_4de7a0(u8 *self);                     // thiscall, plain ret
extern "C" u32 THISCALL ext_4db2c0(u8 *self, u32 a, u32 b);        // thiscall ret 8
extern "C" void THISCALL ext_440e10(u8 *self, u8 *p);              // thiscall ret 4

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x522850, thiscall(a) ret 4: r = 0x5003d0([a+4], 0); returns slot 0x37c of [this+0x1c] with ([r], 0).
static u32 THISCALL fn522850(u8 *self, u8 *a) {
  u32 r = ext_5003d0(*(u8 **)(a + 4), 0);
  return vcall<u32>(*(void **)(self + 0x1c), 0x37c, *(u32 *)r, 0u);
}
PCREG(522850, fn522850);

// 0x596900 / 0x597f70, thiscall no args: o = [this+0x1d0b] (unaligned); 0x593f40(o, f); [this+0xdd] = 0x594040(o, k, 0) (unaligned); returns 0x596ef0(this, m, 0).
static u32 THISCALL fn596900(u8 *self) {
  ext_593f40((u8 *)rd32(self + 0x1d0b), 0);
  u32 r = ext_594040((u8 *)rd32(self + 0x1d0b), 0xb, 0);
  wr32(self + 0xdd, r);
  return ext_596ef0(self, 4, 0);
}
PCREG(596900, fn596900);
static u32 THISCALL fn597f70(u8 *self) {
  ext_593f40((u8 *)rd32(self + 0x1d0b), 1);
  u32 r = ext_594040((u8 *)rd32(self + 0x1d0b), 0xd, 0);
  wr32(self + 0xdd, r);
  return ext_596ef0(self, 0, 0);
}
PCREG(597f70, fn597f70);

// 0x5d5790, thiscall no args: [this] = 0x6b5610; o = [this+0x19] (unaligned) != 0 -> slot 0 of o with 1; free([this+0x29], 1); tail jump to 0x43de70(this).
static u32 THISCALL fn5d5790(u8 *self) {
  u8 *o = (u8 *)rd32(self + 0x19);
  *(u32 *)self = 0x6b5610;
  if (o) vcall<void>(o, 0, 1u);
  ext_634273(rd32(self + 0x29), 1);
  return ext_43de70(self);
}
PCREG(5d5790, fn5d5790);

// 0x65c030, thiscall(p) ret 4: 0x6493d0(p); returns slot 0 of p with this.
static u32 THISCALL fn65c030(u8 *self, u8 *p) {
  ext_6493d0(self, p);
  return vcall<u32>(p, 0, (u32)self);
}
PCREG(65c030, fn65c030);

// 0x46e980, thiscall(a, b) ret 8: r = slot 0x2dc of this; r == 0 -> 0x4de7a0(a), b[0..2] = 0, returns b; else tail jump to 0x4db2c0([r+8], a, b).
static u32 THISCALL fn46e980(void *self, u8 *a, u32 *b) {
  u8 *r = vcall<u8 *>(self, 0x2dc);
  if (!r) {
    ext_4de7a0(a);
    b[0] = 0; b[1] = 0; b[2] = 0;
    return (u32)b;
  }
  return ext_4db2c0(*(u8 **)(r + 8), (u32)a, (u32)b);
}
PCREG(46e980, fn46e980);

// 0x46f660, thiscall(p) ret 4, returns true: 0x440e10(p); slot 0x70 of p with [this+0x70].
static bool THISCALL fn46f660(u8 *self, u8 *p) {
  ext_440e10(self, p);
  vcall<void>(p, 0x70, *(u32 *)(self + 0x70));
  return true;
}
PCREG(46f660, fn46f660);

// 0x4798d0, thiscall(a) ret 4: [this+0x691] <= 0 (signed) -> slot 0x128 of this with (word [0x6ffa28], a, 0); clear unaligned dword [this+0x6ba] and byte [this+0x6be].
static void THISCALL fn4798d0(u8 *self, u32 a) {
  if (*(int *)(self + 0x691) > 0) return;
  (void)0;
  vcall<void>(self, 0x128, (u32)G(u16, 0x6ffa28), a, 0u);
  wr32(self + 0x6ba, 0);
  self[0x6be] = 0;
}
PCREG(4798d0, fn4798d0);
