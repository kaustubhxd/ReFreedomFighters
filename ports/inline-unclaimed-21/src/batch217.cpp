// batch217.cpp - unclaimed area 21 (docs/20-unclaimed-21.md). Zeroes a three-dword local and calls vtable 0x278 with
// (a, b, c, &local). The local is a scratch out-block that the function does not read back. Name GUESS.
#include "ff.h"

typedef void(THISCALL *SlotFourArgs)(u8 *, u32, u32, u32, u32 *);   // vtable slot, four stack words, no result used

static u32 vslot5(u8 *obj, u32 off) { return *(u32 *)(*(u32 *)obj + off); }

// 0x461a40, thiscall(a, b, c) (ret 0xc): local[0..2] = 0; vtable[0x278](this, a, b, c, local). Name GUESS.
static void THISCALL scratchCall_461a40(u8 *self, u32 a, u32 b, u32 c) {
  u32 local[3] = {0, 0, 0};
  ((SlotFourArgs)vslot5(self, 0x278))(self, a, b, c, local);
}
PCREG(461a40, scratchCall_461a40);
