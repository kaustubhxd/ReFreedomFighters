// batch1641.cpp - CEntityTracker::UpdateEntity(int id) (0x5c08d0, residue 13, 2026-10-12).
// Ids below the count (+0x54, signed) are turned into a record address (id * 0x17 + base at +0x50) and passed to the
// object's vtable slot +0x98 (the original tail-jumps there; this port calls it and returns, which pops the same
// argument). Ids at or above the count do nothing. GUESS: the meaning of 0x17-byte records and slot +0x98 is not traced.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

void THISCALL CEntityTracker_UpdateEntity(u8 *self, s32 id) {
  if (id < AT(s32, self, 0x54)) {
    u32 ptr = (u32)id * 0x17u + AT(u32, self, 0x50);
    vcall<void>(self, 0x98, ptr);
  }
}
PCREG(5c08d0, CEntityTracker_UpdateEntity);
