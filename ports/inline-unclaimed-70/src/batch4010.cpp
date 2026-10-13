// batch4010.cpp - area 70 (residue 9), batch 4010: 0x4d3d10, a thiscall wrapper around 0x4d2700 (five stack arguments).
#include "ff.h"

extern "C" u32 THISCALL ext_4d2700(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);   // exe: 400+ instructions, stubbed in the spec

// 0x4d3d10 (name GUESS): thiscall (ECX passed through), four stack args (a, b, cnt, d), ret 0x10. Calls 0x4d2700 with
// (a, 4, d, b, cnt << 2) and returns its eax.
static u32 THISCALL wrapD2700(u8 *self, u32 a, u32 b, u32 cnt, u32 d) {
  return ext_4d2700(self, a, 4, d, b, cnt << 2);
}
PCREG(4d3d10, wrapD2700);
