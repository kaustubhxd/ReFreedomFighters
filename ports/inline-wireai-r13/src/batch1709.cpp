// batch1709.cpp - 0x4d3ad0 (GUESS, residue 13 band, 2026-10-12). Thiscall, three stack arguments (a, b, c), ret 0xc. Calls
// CSharedCom::AddValOfType (0x4d2700, hooked; thiscall, five stack arguments, ret 0x14) as (a, 4, c, &b, 0) with this unchanged,
// and returns its eax. The callee's write through &b lands in the caller's argument slot in the exe; the port uses a local.
#include "ff.h"

extern "C" char ext_4d2700[];
typedef u32(THISCALL *AddValFn)(void *self, u32 a, u32 b, u32 c, u32 *pb, u32 zero);

u32 THISCALL GUESS_4d3ad0(u8 *self, u32 a, u32 b, u32 c) {
  u32 bb = b;
  return ((AddValFn)(void *)ext_4d2700)(self, a, 4u, c, &bb, 0u);
}
PCREG(4d3ad0, GUESS_4d3ad0);
