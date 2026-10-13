#include "ff.h"
// batch2736.cpp - unclaimed-27 batch 38 (docs/20-unclaimed-27.md). FUN_59dd10 and FUN_58bbc0 (GUESS names). SEH frames not reproduced (tagged).
// Callees 0x45c4f0 (cdecl, two args), 0x45c4b0 (cdecl, one arg), 0x59d580 and 0x58ab50 (thiscall, three stack args, ret 0xc) are hooked
// by address in the spec (stubs, NOT verified).
extern "C" u32 ext_45c4f0(u32 k, u32 a2);          // cdecl (hooked)
extern "C" u32 ext_45c4b0(u32 k);                  // cdecl (hooked)
extern "C" u32 THISCALL ext_59d580(u8 *self, u32 a1, u8 *t, u32 e);   // hooked
extern "C" u32 THISCALL ext_58ab50(u8 *self, u32 a1, u8 *t, u32 e);   // hooked

// 0x59dd10 (GUESS): ecx = this, edx = esi value, two stack args (a1, a2); ret 8.
static u32 FASTCALL funcDdChain(u8 *self, u32 esiv, u32 a1, u32 a2) {
  u32 r;
  if (a2 != 0) {
    r = ext_45c4f0(0x951u, a2);
  } else {
    r = ext_45c4b0(0x951u);
  }
  if (r == 0) return 0;
  return ext_59d580((u8 *)(unsigned long)r, a1, self, esiv);
}
PCREG(59dd10, funcDdChain);

// 0x58bbc0 (GUESS): same chain with K = 0xf62 and the callee 0x58ab50.
static u32 FASTCALL funcBbChain(u8 *self, u32 esiv, u32 a1, u32 a2) {
  u32 r;
  if (a2 != 0) {
    r = ext_45c4f0(0xf62u, a2);
  } else {
    r = ext_45c4b0(0xf62u);
  }
  if (r == 0) return 0;
  return ext_58ab50((u8 *)(unsigned long)r, a1, self, esiv);
}
PCREG(58bbc0, funcBbChain);
