#include "ff.h"
// batch911.cpp - unclaimed-01 claim 10 (docs/20-unclaimed-01.md). CMsgForward::Load(ZLoadGame*) (0x49ef80, high).

// Clears bit 0x40 of the dword at this+4. Calls vtable slot +0x40 of the load object with a pointer to this+0x48, then
// vtable slot +0x44 with a pointer to this+0x4c (each thiscall, one argument; the load writes through the pointer).
// Returns true (al = 1).
static u8 THISCALL msgForwardLoad(u8 *self, u8 *load) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  typedef void(THISCALL * slot_fn)(u8 *, u8 *);
  slot_fn f40 = *(slot_fn *)(*(u32 *)load + 0x40);
  f40(load, self + 0x48);
  slot_fn f44 = *(slot_fn *)(*(u32 *)load + 0x44);
  f44(load, self + 0x4c);
  return 1;
}
PCREG(49ef80, msgForwardLoad);
