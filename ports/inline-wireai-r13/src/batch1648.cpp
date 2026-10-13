// batch1648.cpp - ZInputActions::CheckActionCheat(const char* name, void*) (0x4380d0, residue 13, 2026-10-12). Name map:
// medium (the name is the cheat's string; the second argument is not read). Returns the result of vslot 0x2c with
// (the action id from vslot 0x58(name), 0), but only when the system's byte at +0x9b9 is set; else false. The result is
// the callee's al. GUESS: the names of the slots 0x58 and 0x2c.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

u8 THISCALL ZInputActions_CheckActionCheat(u8 *self, u32 name, u32 unused) {
  u8 *sys = AT(u8 *, 0x70039c, 0);
  if (!AT(u8, sys, 0x9b9)) return 0;
  u32 action = vcall<u32>(self, 0x58, name);
  return vcall<u8>(self, 0x2c, action, (u32)0);
}
PCREG(4380d0, ZInputActions_CheckActionCheat);
