// batch4009.cpp - area 70 (residue 9), batch 4009: 0x4408d0 (flag setter, then one call per list node).
#include "ff.h"

extern "C" void THISCALL ext_45e900(u8 *self, u32 flag);   // exe: set/clear bit 0x10 at +0x14 from the flag's low byte
extern "C" void THISCALL ext_4daed0(u8 *self, u32 flag);   // exe: flag path (global pointer 0x7003b0 when the node's +0x54 is 0)

// 0x4408d0 (name GUESS): thiscall, ret 4. Calls 0x45e900(this, flag); then for each node n of the list at this+0x50
// (next at n+0x60) calls 0x4daed0(n, flag).
static void THISCALL flagAndWalk(u8 *self, u32 flag) {
  ext_45e900(self, flag);
  for (u8 *n = *(u8 **)(self + 0x50); n; n = *(u8 **)(n + 0x60))
    ext_4daed0(n, flag);
}
PCREG(4408d0, flagAndWalk);
