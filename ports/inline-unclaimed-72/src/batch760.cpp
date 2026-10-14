// batch760.cpp - area 72 (2026-10-12): 0x4c59f0, one call to DBREAD::GetRefTab (0x4e6330, ret 4) with ecx = arg, pushed = this+0x48.
#include "ff.h"

extern "C" void THISCALL ext_4e6330(void *dbread, u32 refTab);

// 0x4c59f0 (thiscall, ret 4): GetRefTab(this+0x48) on the DBREAD argument.
static void THISCALL f_4c59f0(u8 *self, u8 *dbread) { ext_4e6330(dbread, (u32)(self + 0x48)); }
PCREG(4c59f0, f_4c59f0);
