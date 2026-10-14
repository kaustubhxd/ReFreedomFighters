// batch5717.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 17: 0x4c2bc0 (GUESS, unnamed), thiscall, two stack arguments (float a,
// float b), ret 8. If byte this+0xd1 is 0, return. Else t = dword (dword this+0x44) + 0x18 target; dword t+0x84 = bits of a;
// dword t+0x68 = (int) truncation of b (cvttss2si, as the original). No calls.
#include "ff.h"

static void THISCALL unnamed4c2bc0(u8 *self, float a, float b) {
  if (self[0xd1] == 0) return;
  u8 *sub = *(u8 **)(self + 0x44);
  u8 *t = *(u8 **)(sub + 0x18);
  *(u32 *)(t + 0x84) = fbits(a);
  *(s32 *)(t + 0x68) = _mm_cvttss_si32(_mm_set_ss(b));
}
PCREG(4c2bc0, unnamed4c2bc0);
