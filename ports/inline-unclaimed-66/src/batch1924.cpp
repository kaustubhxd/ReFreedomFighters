// batch1924.cpp - unclaimed-66 batch 24: two slice-5 functions (GUESS names).
#include "ff.h"

// 0x656490, GUESS FUN_00656490: thiscall(a1, a2) (ret 8): r = vtable +0xc of this with a1; then vtable +0x158 of this with (a2, r) (the asm pushes r first, so a2 is the first argument);
// returns AL = 1.
static u8 THISCALL chainedVtableWithTwoArgsReturnsTrue(u8 *self, u32 a1, u32 a2) {
  u32 r = vcall<u32>(self, 0xc, a1);
  vcall<void>(self, 0x158, a2, r);
  return 1;
}
PCREG(656490, chainedVtableWithTwoArgsReturnsTrue);

extern "C" void ext_634273(void *self, u32 size);  // cdecl: the caller pops (push size; push self; call; add esp, 8)  // not an extern in batch 9; here it is only referenced by the gap path

// 0x54cd10, GUESS FUN_0054cd10 (scalar deleting destructor): [this] = 0x6a3dd0; if bit 0 of flags is set, free(this, 12) (the CRT
// delete path; NOT run by the spec: bit 0 is kept clear, a documented gap). Returns this.
static u8 *THISCALL scalarDeletingDtorNoFree(u8 *self, u32 flags) {
  *(u32 *)self = 0x6a3dd0;
  if (flags & 1) ext_634273(self, 0xc);
  return self;
}
PCREG(54cd10, scalarDeletingDtorNoFree);
