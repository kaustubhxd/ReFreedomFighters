// batch1668.cpp - 0x4762a0 (GUESS, residue 13 gap band, 2026-10-12). Thiscall, no stack arguments, plain ret. The eax of
// every path is modelled: the tick gate returns the system pointer (eax was loaded from 0x70039c and not changed); mode
// word +0x4e other than 0 or 1 returns mode-1; mode 1 returns 0 (no object) or the result of the object's slot 0x210(1);
// the main path runs slot 0x68(0x10, 0), slot 0x28 and slot 0x1e0(0x1000ca) on the object at +0x44, returns that last
// eax when its low byte is zero, else tail-jumps into ZAllocMany::Free (0x476bd0, hooked; no stack arguments) with the
// object as this and returns its eax. GUESS: all slot names.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_476bd0[];
typedef u32(THISCALL *TailNoArgs)(void *self);

u32 THISCALL GUESS_4762a0(u8 *self) {
  u8 *sys = AT(u8 *, 0x70039c, 0);
  if ((s32)AT(u32, self, 0x52) > (s32)AT(u32, sys, 0x40)) return (u32)sys;
  u32 mode = AT(u32, self, 0x4e);
  if (mode != 0) {
    if (mode != 1) return mode - 1;
    u8 *o = AT(u8 *, self, 0x44);
    if (!o) return 0;
    return vcall<u32>(o, 0x210, (u32)1);
  }
  vcall<void>(self, 0x68, (u32)0x10, (u32)0);
  vcall<void>(AT(u8 *, self, 0x44), 0x28);
  u32 r = vcall<u32>(AT(u8 *, self, 0x44), 0x1e0, (u32)0x1000ca);
  if (!(u8)r) return r;
  return ((TailNoArgs)(void *)ext_476bd0)(AT(u8 *, self, 0x44));
}
PCREG(4762a0, GUESS_4762a0);
