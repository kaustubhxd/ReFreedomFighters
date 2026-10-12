#include "ff.h"
// batch8015.cpp - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Names GUESS (no GC name).

// 0x499c30 (GUESS): thiscall (ret 8). Calls slot +0x10 of this with (address of first argument, 8), returns this.
static u8 *THISCALL f_499c30(u8 *self, u32 a0, u32 a1) { (void)a1; vcall<void, u32, u32>(self, 0x10, (u32)(unsigned long)&a0, 8u); return self; }
PCREG(499c30, f_499c30);

// 0x499ce0 (GUESS): thiscall (ret 4). Calls slot +0x10 of this with (address of argument, 4), returns this.
static u8 *THISCALL f_499ce0(u8 *self, u32 a0) { vcall<void, u32, u32>(self, 0x10, (u32)(unsigned long)&a0, 4u); return self; }
PCREG(499ce0, f_499ce0);

// 0x499d00 (GUESS): thiscall (ret 4). Calls slot +0x10 of this with (address of argument, 1), returns this.
static u8 *THISCALL f_499d00(u8 *self, u32 a0) { vcall<void, u32, u32>(self, 0x10, (u32)(unsigned long)&a0, 1u); return self; }
PCREG(499d00, f_499d00);

// 0x499db0 (GUESS): thiscall (ret 4). Calls slot +0x10 of this with (address of argument, 4), returns nothing.
static void THISCALL f_499db0(u8 *self, u32 a0) { vcall<void, u32, u32>(self, 0x10, (u32)(unsigned long)&a0, 4u); }
PCREG(499db0, f_499db0);
