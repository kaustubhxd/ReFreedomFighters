#include "ff.h"

// 0x461210, thiscall(a,b) ret 8: ask slot 0x23c whether a is accepted with
// option 0; if not, forward (a,b) to slot 0x22c and return its result.
static u32 THISCALL fn461210(u8 *self, u32 a, u32 b) {
  u32 accepted = vcall<u32>(self, 0x23c, a, 0u);
  if ((u8)accepted) return 0;
  return vcall<u32>(self, 0x22c, a, b);
}

PCREG(461210, fn461210);
