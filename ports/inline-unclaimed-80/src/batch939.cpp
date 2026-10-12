#include "ff.h"
// batch939.cpp - unclaimed-80 (docs/20-unclaimed-80.md): GUESS FUN_4e1440 (DBLK cursor step, no name in the map). Thiscall, one stack
// argument (out pointer), ret 4. The cursor is the dword at this+8. The tag byte must be 4 or 5 (low six bits; 0xff is not valid). The
// valid branch writes cursor+1 through the argument, then advances the cursor by (item size + 1), where the item size is 0x4e1590
// (original code, called here). The invalid branch (callback at 0x7003b0, then a vtable call through 0x700390) is NOT ported; the spec
// never produces an invalid tag.

extern "C" u32 THISCALL ext_4e1590(u8 *self);

static void THISCALL dblkCursorStep(u8 *self, u32 *out) {
  u8 *cur = *(u8 **)(self + 8);
  u8 tag = cur[0];
  if (tag == 0xff || ((tag & 0x3f) != 4 && (tag & 0x3f) != 5))
    return;   // invalid tag: not ported (not reached by the spec)
  *out = (u32)cur + 1;
  u32 n = ext_4e1590(self);
  *(u32 *)(self + 8) += n + 1;
}
PCREG(4e1440, dblkCursorStep);
