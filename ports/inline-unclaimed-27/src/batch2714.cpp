#include "ff.h"
// batch2714.cpp - unclaimed-27 batch 14 (docs/20-unclaimed-27.md).

// 0x5edb00, CSpriteBorder2D::SetHeight(unsigned int) (high). Thiscall, ret 4: if the dword at this+0xe3 differs from the
// argument, stores it there and sets the byte at this+0xa6 to 1.
static void THISCALL spriteBorder2DSetHeight(u8 *self, u32 a1) {
  if (*(u32 *)(self + 0xe3) != a1) {
    *(u32 *)(self + 0xe3) = a1;
    self[0xa6] = 1;
  }
}
PCREG(5edb00, spriteBorder2DSetHeight);

// 0x45d380 (GUESS name): thiscall, ret 8. Calls vtable slot +0x16c with (first, second) (callee cleans), returns 0.
static u32 THISCALL funcForwardSlot16c(u8 *self, u32 first, u32 second) {
  typedef void(THISCALL * slot16c_fn)(u8 *, u32, u32);
  ((slot16c_fn)(*(u32 *)(*(u32 *)self + 0x16c)))(self, first, second);
  return 0;
}
PCREG(45d380, funcForwardSlot16c);
