// batch6243 - unclaimed-62 claim 36 (gap band 0x561000-0x581000): 0x563620 [thiscall, two stack arguments, ret 8].
// r = the message table's slot 0x58 (thiscall, ONE argument a1; the engine's +0x9b object) ; then 0x563650 (thiscall, this, two stack
// arguments r and a2: the original pushes a2 before the slot call and the slot pops only a1; ret 8).
#include "ff.h"

extern "C" void THISCALL ext_563650(void *self, u32 r, u32 a2);   // exe: thiscall, two stack arguments (ret 8)

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }

static void THISCALL fn563620(u8 *self, u32 a1, u32 a2) {
  u8 *msg = rdp(G(u8 *, 0x70039c) + 0x9b);
  u32 r = vcall<u32>(msg, 0x58, a1);
  ext_563650(self, r, a2);
}

PCREG(563620, fn563620);
