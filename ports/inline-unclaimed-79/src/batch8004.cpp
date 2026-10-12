#include "ff.h"
// batch8004.cpp - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Names GUESS (no GC name).

// 0x481920 (GUESS): address of this+0x445.
static u32 THISCALL f_481920(u8 *self) { return (u32)(unsigned long)(self + 0x445); }
PCREG(481920, f_481920);

// 0x48f6f0 (GUESS): increment the dword at this+0x5d39.
static void THISCALL f_48f6f0(u8 *self) { *(u32 *)(self + 0x5d39) += 1; }
PCREG(48f6f0, f_48f6f0);

// 0x490cf0 (GUESS): address of this+0x1c61.
static u32 THISCALL f_490cf0(u8 *self) { return (u32)(unsigned long)(self + 0x1c61); }
PCREG(490cf0, f_490cf0);

// 0x492b20 (GUESS): increment the dword at this+0xbc9.
static void THISCALL f_492b20(u8 *self) { *(u32 *)(self + 0xbc9) += 1; }
PCREG(492b20, f_492b20);

// 0x49b720 (GUESS): returns its stack argument (ret 4).
static u32 THISCALL f_49b720(u8 *self, u32 a) { (void)self; return a; }
PCREG(49b720, f_49b720);

// 0x49df20 (GUESS): address of this+0x104.
static u32 THISCALL f_49df20(u8 *self) { return (u32)(unsigned long)(self + 0x104); }
PCREG(49df20, f_49df20);

// 0x49eec0 (GUESS): address of this+0x11a.
static u32 THISCALL f_49eec0(u8 *self) { return (u32)(unsigned long)(self + 0x11a); }
PCREG(49eec0, f_49eec0);

