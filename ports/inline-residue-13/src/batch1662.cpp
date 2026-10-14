// batch1662.cpp - 0x468270 (GUESS, residue 13 gap band, 2026-10-12). The Save twin of 0x468220 (batch 1661). ret 4
// (one argument: obj). Calls ZIKLNKOBJ::Save (0x467770, hooked; thiscall, one argument, ret 4) with this and obj. On a
// zero low byte returns Save's eax; otherwise calls obj's slots 0x10(this+0x1d2, 4), 0x3c(this+0x1d6) and
// 0x4c(this+0x1da, the float's bits) and returns the last eax with its low byte set to 1. GUESS: the slot names.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_467770[];
typedef u32(THISCALL *SaveFn)(void *self, void *obj);

u32 THISCALL GUESS_468270(u8 *self, u8 *obj) {
  u32 r = ((SaveFn)(void *)ext_467770)(self, obj);
  if (!(u8)r) return r;
  vcall<void>(obj, 0x10, (u32)(self + 0x1d2), (u32)4);
  vcall<void>(obj, 0x3c, AT(u32, self, 0x1d6));
  u32 last = vcall<u32>(obj, 0x4c, AT(u32, self, 0x1da));
  return (last & 0xffffff00u) | 1u;
}
PCREG(468270, GUESS_468270);
