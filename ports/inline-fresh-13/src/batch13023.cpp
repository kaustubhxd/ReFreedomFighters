// batch13023.cpp - fresh slice 13, batch 23 (docs/20-fresh-13.md), 2026-10-12.
// 0x54bfd0 GUESS DirectSound driver probe (no name map entry; strings "DirectSound" / "Direct Sound" / " (SW)" at
// 0x6a38b8): thiscall, no arguments, returns a bool in al (0 when this->vtbl[+0xc]() fails, else 1).
//  - Copies the driver names into the globals 0x713d34 / 0x713d74 (8 + 4 bytes and 8 + 4 + 1 bytes from .rdata).
//  - this+0xa27c = 1, hardware flag 0x713df9 = 1; up to 0x80 drivers are collected with 0x54c3f0(this) until it returns
//    0. None: " (SW)" is appended to the name at 0x713d74, both flags go to 0 and up to 0x40 software drivers are
//    collected. The count goes to 0x713df4; each driver gets vtbl[+0x40]() then vtbl[+4](1) (deleting destructor).
//  - 0x713df8 = 0. With hardware (0x713df9) and 0x713dfa set: dev = this->vtbl[+0x40](); dev->vtbl[+8](&params, 1)
//    with the 12-word format record (6, 0, 1, 0x5622, 0x10, 0x20, unset, 1, 0, 0x10, 2, 1); on failure dev->vtbl[+4](1)
//    and dev = 0 (the exe then reads dev+0x63ec through null; the spec never fails it). A 0x50-byte object (operator new
//    0x41e290, ctor 0x54e9d0) is opened with vtbl[+4](dev+0x63ec, 0); when that succeeds 0x713df8 |= (vtbl[+0xc]() != 0).
//    Then obj->vtbl[0](1), dev->vtbl[+0x40](), dev->vtbl[+4](1).
//  - this->vtbl[+0xb4](); return 1.
// The SEH frame and /GS cookie are not reproduced.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))
#define VT(o, off) (*(u32 *)(*(u32 *)(o) + (off)))

extern "C" char ext_54c3f0[], ext_41e290[], ext_54e9d0[];
typedef u32(THISCALL *R0)(void *self);
typedef u8(THISCALL *B0)(void *self);
typedef u32(THISCALL *R1)(void *self, u32 a);
typedef u8(THISCALL *B2)(void *self, u32 *a, u32 b);
typedef u32(THISCALL *R2)(void *self, u32 a, u32 b);
typedef void *(*New)(u32 n);

static u8 THISCALL fn54bfd0(u8 *self) {
  G(u64, 0x713d34) = G(u64, 0x6a38b8);
  G(u32, 0x713d3c) = G(u32, 0x6a38c0);
  G(u64, 0x713d74) = G(u64, 0x6a38c4);
  G(u32, 0x713d7c) = G(u32, 0x6a38cc);
  G(u8, 0x713d80) = G(u8, 0x6a38d0);
  u32 r = ((R0)VT(self, 0xc))(self);
  if (!(u8)r)
    return 0;
  AT(u8, self, 0xa27c) = 1;
  G(u8, 0x713df9) = 1;
  u8 *drv[0x80];
  s32 n = 0;
  for (;;) {
    u8 *d = (u8 *)((R0)(void *)ext_54c3f0)(self);
    if (!d)
      break;
    drv[n++] = d;
    if (n == 0x80)
      break;
  }
  if (n == 0) {
    char *s = (char *)0x713d74;
    while (*s)
      s++;
    AT(u32, s, 0) = G(u32, 0x6a38d4);
    AT(u16, s, 4) = G(u16, 0x6a38d8);
    G(u8, 0x713df9) = 0;
    AT(u8, self, 0xa27c) = 0;
    do {
      u8 *d = (u8 *)((R0)(void *)ext_54c3f0)(self);
      if (!d)
        break;
      drv[n++] = d;
    } while (n < 0x40);
  }
  G(s32, 0x713df4) = n;
  for (s32 i = 0; i < n; i++) {
    u8 *d = drv[i];
    ((R0)VT(d, 0x40))(d);
    if (d)
      ((R1)VT(d, 4))(d, 1);
  }
  G(u8, 0x713df8) = 0;
  if (G(u8, 0x713df9) && G(u8, 0x713dfa)) {
    u32 prm[12];
    prm[0] = 6;
    prm[1] = 0;
    prm[2] = 1;
    prm[3] = 0x5622;
    prm[4] = 0x10;
    prm[5] = 0x20;
    prm[7] = 1;
    prm[8] = 0;
    prm[9] = 0x10;
    prm[10] = 2;
    prm[11] = 1;
    u8 *dev = (u8 *)((R0)VT(self, 0x40))(self);
    if (!((B2)VT(dev, 8))(dev, prm, 1)) {
      ((R1)VT(dev, 4))(dev, 1);
      dev = 0;
    }
    u8 *mem = (u8 *)((New)(void *)ext_41e290)(0x50);
    u8 *o = mem ? (u8 *)((R0)(void *)ext_54e9d0)(mem) : 0;
    if (((R2)VT(o, 4))(o, AT(u32, dev, 0x63ec), 0)) {
      u8 hw = ((B0)VT(o, 0xc))(o);
      if (hw)
        G(u8, 0x713df8) = 1;
    }
    ((R1)VT(o, 0))(o, 1);
    ((R0)VT(dev, 0x40))(dev);
    ((R1)VT(dev, 4))(dev, 1);
  }
  ((R0)VT(self, 0xb4))(self);
  return 1;
}
PCREG(54bfd0, fn54bfd0);
