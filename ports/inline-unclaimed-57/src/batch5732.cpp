// batch5732.cpp - unclaimed-57, band batch 32 (names GUESS): 0x5d5970, thiscall, no args, ret. If the dword this+0x25 is set, sub =
// that value and sub->vt[+0x25c](dword this+8) (thiscall, one argument). Then this->vt[+0x110](0x10, 0) (thiscall, two arguments).
// Both slots are unverified callees, stubbed in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *SlotA)(u8 *self, u32 a);
typedef void(THISCALL *SlotB)(u8 *self, u32 a, u32 b);

static void THISCALL unnamed5d5970(u8 *self) {
  u8 *sub = *(u8 **)(self + 0x25);
  if (sub != 0) ((SlotA)VT(sub)[0x25c / 4])(sub, *(u32 *)(self + 8));
  ((SlotB)VT(self)[0x110 / 4])(self, 0x10, 0);
}
PCREG(5d5970, unnamed5d5970);
