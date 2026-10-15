// batch1661.cpp - 0x468220 (GUESS, residue 13 gap band, 2026-10-12). ret 4 (one argument: obj). Calls ZIKLNKOBJ::Load
// (0x466dc0, hooked; thiscall, one argument, ret 4) with this and obj. When that returns nothing (low byte zero) the
// function returns Load's eax; otherwise it calls obj's slots 0x18(this+0x1d2, 4), 0x40(this+0x1d6) and 0x50(this+0x1da)
// and returns 1 (al). GUESS: the slot names and the field names.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_466dc0[];
typedef u32(THISCALL *LoadFn)(void *self, void *obj);

u32 THISCALL GUESS_468220(u8 *self, u8 *obj) {
  u32 r = ((LoadFn)(void *)ext_466dc0)(self, obj);
  if (!(u8)r) return r;
  vcall<void>(obj, 0x18, (u32)(self + 0x1d2), (u32)4);
  vcall<void>(obj, 0x40, (u32)(self + 0x1d6));
  u32 last = vcall<u32>(obj, 0x50, (u32)(self + 0x1da));  // eax of the last call survives into the return
  return (last & 0xffffff00u) | 1u;
}
PCREG(468220, GUESS_468220);
