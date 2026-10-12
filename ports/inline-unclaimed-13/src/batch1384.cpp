#include "ff.h"
// batch1384.cpp - unclaimed-13 claim 2, batch 3 (docs/20-unclaimed-13.md). Names are low confidence in the GC name
// map, so both are GUESS labels.

// 0x5c2790, ZFenceGate::Init (low, GUESS): ecx is the value. Appends ecx to the list of the global object at 0x7003b8:
// index = the dword at +0xbe5 of that object, store at +0xbe9 + 4 * index, then the count is incremented. No stack
// arguments, void, ret 0 (fastcall with the argument in ecx).
static void FASTCALL zFenceGateInitAppend(u32 value) {
  u8 *g = (u8 *)(unsigned long)G(u32, 0x7003b8);
  u32 index = *(u32 *)(g + 0xbe5);
  *(u32 *)(g + 0xbe9 + index * 4) = value;
  *(u32 *)(g + 0xbe5) = index + 1;
}
PCREG(5c2790, zFenceGateInitAppend);

// 0x488ba0, ZMovementAction::GetAnims (low, GUESS): calls vtable slot +0x58 with the argument 0x68d420 (a data address,
// passed as is) and stores the result at this+0x1d (unaligned dword). The result is returned in eax (the callee's value).
static u32 THISCALL movementActionGetAnims(u8 *self) {
  typedef u32(THISCALL * slot58_fn)(u8 *, u32);
  u32 v = ((slot58_fn)*(u32 *)(*(u32 *)self + 0x58))(self, 0x68d420u);
  *(u32 *)(self + 0x1d) = v;
  return v;
}
PCREG(488ba0, movementActionGetAnims);
