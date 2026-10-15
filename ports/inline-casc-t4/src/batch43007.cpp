// batch43007.cpp - t4 (Sonnet) batch 43007: tier H float/SSE functions
#include "ff.h"

extern "C" void THISCALL ext_528260(u8 *self, u32 a);            // thiscall ret 4
extern "C" void THISCALL ext_5291f0(u8 *self, float f);          // thiscall ret 4
extern "C" void THISCALL ext_527f80(u8 *self);                   // thiscall, plain ret
extern "C" void THISCALL ext_5c3560(u8 *self, u32 a, u32 b);     // thiscall ret 8

#define SYS (*(u8 **)0x70039c)

// 0x478f90, thiscall(float key) ret 4, returns an index: idx = [this]; records of 16 bytes (float at +0) at [this+0xc], count [this+8];
// while idx > 0 and rec[idx] > key (ordered): idx--; then (idx < count - 1) while key >= rec[idx] (ordered): idx++, stopping at count - 1;
// returns idx (also stored in [this])
static s32 THISCALL fn478f90(u8 *self, float key) {
  s32 *pidx = (s32 *)self;
  if (*pidx > 0) {
    u8 *arr = *(u8 **)(self + 0xc);
    for (;;) {
      s32 e = *pidx;
      if (!(*(float *)(arr + e * 16) > key)) break;
      *pidx = e - 1;
      if (!(*pidx > 0)) break;
    }
  }
  s32 lim = *(s32 *)(self + 8) - 1;
  if (*pidx < lim) {
    u8 *arr = *(u8 **)(self + 0xc);
    for (;;) {
      s32 e = *pidx;
      if (!(key >= *(float *)(arr + e * 16))) return e;
      *pidx = e + 1;
      if (!(*pidx < lim)) return *pidx;
    }
  }
  return *pidx;
}
PCREG(478f90, fn478f90);

// 0x527ee0, thiscall(a, float f, c, d) ret 0x10: [this+0x89] = a; [this+0x38] = [this+0x30] = 0; a->slot 0x80(this+0xc, this); 0x528260(this, c);
// byte [this+0x21cd] = d; 0x5291f0(this, f); 0x527f80(this); byte [this+0x84] = 1; [this+0x48] = (float)(int)[sys+0x40] * K (0x6785e4);
// dword [this+0x85] = [sys+0x40] + 0x1c00 (skipped when this+0x85 is the address of a stack local, an inlining leftover)
static void THISCALL fn527ee0(u8 *self, u8 *a, float f, u32 c, u32 d) {
  u32 marker;
  *(u8 **)(self + 0x89) = a;
  *(u32 *)(self + 0x38) = 0;
  *(u32 *)(self + 0x30) = 0;
  vcall<void>(a, 0x80, (u32)(self + 0xc), (u32)self);
  ext_528260(self, c);
  self[0x21cd] = (u8)d;
  ext_5291f0(self, f);
  ext_527f80(self);
  *(float *)(self + 0x48) = (float)*(s32 *)(SYS + 0x40) * G(float, 0x6785e4);
  self[0x84] = 1;
  if (self + 0x85 != (u8 *)&marker) *(u32 *)(self + 0x85) = *(u32 *)(SYS + 0x40) + 0x1c00;
}
PCREG(527ee0, fn527ee0);

// 0x5c3000, thiscall no args: byte +0x125 = 0, byte +0x114 = 1, dwords +0x11d, +0x121, +0x119, +0x115 = 0; this->slot 0x68(0x10, 0); k = byte [this+0xf4]:
// 0: [+0x114] = 1, 0x5c3560(this, 1, 1); 1: 0x5c3560(this, 0, 1), then [+0x114] = 0; 2: [+0x114] = 1, [+0x115] = (float)(int)[sys+0x40] * K, slot 0x64(0x10)
static void THISCALL fn5c3000(u8 *self) {
  self[0x125] = 0;
  self[0x114] = 1;
  *(u32 *)(self + 0x11d) = 0;
  *(u32 *)(self + 0x121) = 0;
  *(u32 *)(self + 0x119) = 0;
  *(u32 *)(self + 0x115) = 0;
  vcall<void>(self, 0x68, 0x10u, 0u);
  u8 k = self[0xf4];
  if (k == 0) {
    self[0x114] = 1;
    ext_5c3560(self, 1, 1);
  } else if (k == 1) {
    ext_5c3560(self, 0, 1);
    self[0x114] = 0;
  } else if (k == 2) {
    self[0x114] = 1;
    *(float *)(self + 0x115) = (float)*(s32 *)(SYS + 0x40) * G(float, 0x6785e4);
    vcall<void>(self, 0x64, 0x10u);
  }
}
PCREG(5c3000, fn5c3000);
