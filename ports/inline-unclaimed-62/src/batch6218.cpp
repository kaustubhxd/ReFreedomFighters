// batch6218.cpp - unclaimed-62 claim 11 (slice 2): six one-to-two-instruction leaves, all taking this only.
//   0x437070  this+0x10 = 1 (void)
//   0x438330  this+0x10 = 0 (void)
//   0x440930  returns 3
//   0x440cb0  returns this+0x30
//   0x44c0f0  returns -1
//   0x4632f0  returns this+0x58
#include "ff.h"

static void THISCALL fn437070(u8 *self) { self[0x10] = 1; }
static void THISCALL fn438330(u8 *self) { self[0x10] = 0; }
static u32 THISCALL fn440930(u8 *self) { (void)self; return 3; }
static u32 THISCALL fn440cb0(u8 *self) { u32 v; __builtin_memcpy(&v, self + 0x30, 4); return v; }
static u32 THISCALL fn44c0f0(u8 *self) { (void)self; return 0xffffffffu; }
static u32 THISCALL fn4632f0(u8 *self) { u32 v; __builtin_memcpy(&v, self + 0x58, 4); return v; }

PCREG(437070, fn437070);
PCREG(438330, fn438330);
PCREG(440930, fn440930);
PCREG(440cb0, fn440cb0);
PCREG(44c0f0, fn44c0f0);
PCREG(4632f0, fn4632f0);
