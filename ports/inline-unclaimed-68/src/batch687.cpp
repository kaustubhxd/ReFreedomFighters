// batch687.cpp - unclaimed-68 batch 7 (claim 6). Name: GUESS FUN_435eb0 (indexed accessor; see docs/20-unclaimed-68.md).
#include "ff.h"

// Slot +0x10 of an array element (thiscall, no arguments, value in EAX).
typedef u32(THISCALL *VElem10)(u8 *self);

// 0x435eb0 (GUESS): unsigned idx compared with the count at this+0x1c. In range: returns the slot +0x10 of the object at
// this+0x10+4*idx. Out of range: returns 0. Thiscall, one stack argument, ret 4.
static u32 THISCALL guessFun435eb0(u8 *self, u32 idx) {
  if (idx < *(u32 *)(self + 0x1c)) {
    u8 *elem = *(u8 **)(self + 0x10 + idx * 4);
    return ((VElem10)*(u32 *)(*(u8 **)elem + 0x10))(elem);
  }
  return 0;
}
PCREG(435eb0, guessFun435eb0);
