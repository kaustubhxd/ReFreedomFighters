#include "ff.h"
// batch2717.cpp - unclaimed-27 batch 17 (docs/20-unclaimed-27.md).

// 0x5003d0 is original code, but the spec hooks it (a stub). Thiscall, one argument, ret 4.
extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 a1);

// 0x4cf0c0, LINKREFTAB::RunInitNxtRef(RefRun*) (high). Thiscall, ret 4: sets the dword at arg+4 to 1 and the dword at arg to 0;
// clears the top bit of the dword at this+0xc.
static void THISCALL linkRefTabRunInitNxtRef(u8 *self, u32 *run) {
  run[1] = 1;
  run[0] = 0;
  *(u32 *)(self + 0xc) &= 0x7fffffffu;
}
PCREG(4cf0c0, linkRefTabRunInitNxtRef);

// 0x55c740 (GUESS): thiscall, one argument, ret 4. Stores whether the dword at the lookup's result (lookup of the arg's +4
// object with 0) is nonzero as a byte at (this+0x1c)+0x917.
static void THISCALL funcLookupFlag917(u8 *self, u8 *arg) {
  u8 *p = ext_5003d0(*(u8 **)(arg + 4), 0u);
  u8 flag = *(u32 *)p != 0 ? 1 : 0;
  u8 *o = *(u8 **)(self + 0x1c);
  o[0x917] = flag;
}
PCREG(55c740, funcLookupFlag917);
