// batch415.cpp - residue 2 rows 0x54ada0 and 0x5f0020 (both thiscall, return this).
// 0x54ada0 (thiscall, one stack argument flag, ret 4): [this] = vtable 0x6a36dc; call 0x549370 (thiscall, no arguments; GUESS,
// hooked); if (flag & 1): free this with size 0xa2dd through 0x634273 (cdecl delete helper, hooked in the spec).
// 0x5f0020 (thiscall, no arguments): call 0x5ec720 with ECX = this and argument 1 (thiscall, one argument; GUESS, hooked);
// [this] = vtable 0x6b8214; dword [this+0x5e] = 2; dword [this+0xd7] = 0.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void THISCALL ext_549370(void *self);
extern "C" void THISCALL ext_5ec720(void *self, u32 arg);
extern "C" void ext_634273(void *p, u32 size);

static u8 *THISCALL vtableFreeOnFlag(u8 *self, u32 flag) {
  U32(self, 0x0) = 0x6a36dcu;
  ext_549370(self);
  if (flag & 1)
    ext_634273(self, 0xa2ddu);
  return self;
}

static u8 *THISCALL vtableFields(u8 *self) {
  ext_5ec720(self, 1u);
  U32(self, 0x0) = 0x6b8214u;
  U32(self, 0x5e) = 2;
  U32(self, 0xd7) = 0;
  return self;
}

PCREG(54ada0, vtableFreeOnFlag);
PCREG(5f0020, vtableFields);
