// batch6243 - unclaimed-62 claim 36 (gap band 0x561000-0x581000): 0x563620 [thiscall, two stack arguments, ret 8].
// r = the message table's slot 0x58 (thiscall, the two arguments; the engine's +0x9b object) ; then 0x563650 (thiscall, this, one stack
// argument r; GUESS stub by address, body not part of this batch).
#include "ff.h"

extern "C" void THISCALL ext_563650(void *self, u32 r);   // exe: thiscall, one stack argument

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }

static void THISCALL fn563620(u8 *self, u32 a1, u32 a2) {
  u8 *msg = rdp(G(u8 *, 0x70039c) + 0x9b);
  u32 r = vcall<u32>(msg, 0x58, a1, a2);
  ext_563650(self, r);
}

PCREG(563620, fn563620);
