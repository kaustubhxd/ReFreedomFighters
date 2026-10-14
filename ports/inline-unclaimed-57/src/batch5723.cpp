// batch5723.cpp - unclaimed-57, band 0x5c1000-0x5e1000 (docs/20-unclaimed-57.md), batch 23: two unnamed functions (names GUESS).
// 0x5de3d0 (fastcall, the value in ECX, no stack args): dword at (dword 0x7003b8) + 0x2c4d = ecx.
// 0x5da650 (thiscall, no args, ret): dword this+0x4c = 0; sub = dword this+0x44; sub->vt[+0xbc](1) (thiscall, one argument).
// Slot +0xbc is an unverified callee: a logging stub in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))
#define G(T, addr) (*(T *)(addr))

typedef void(THISCALL *Slot1)(u8 *self, u32 a);

static void FASTCALL unnamed5de3d0(u32 v) {
  u8 *g = G(u8 *, 0x7003b8);
  *(u32 *)(g + 0x2c4d) = v;
}
PCREG(5de3d0, unnamed5de3d0);

static void THISCALL unnamed5da650(u8 *self) {
  *(u32 *)(self + 0x4c) = 0;
  u8 *sub = *(u8 **)(self + 0x44);
  ((Slot1)VT(sub)[0xbc / 4])(sub, 1);
}
PCREG(5da650, unnamed5da650);
