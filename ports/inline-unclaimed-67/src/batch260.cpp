// batch260.cpp - unclaimed area 67, slice floor(addr/16) mod 20 == 6 (names unknown: FUN_ entries in out/functions.jsonl).
#include "ff.h"

// 0x4f0020, thiscall: returns the byte at this+0x20.
static u32 THISCALL getByte20(u8 *self) { return *(u8 *)(self + 0x20); }
PCREG(4f0020, getByte20);

// 0x54bba0, thiscall: returns this+0x2c.
static u32 THISCALL addr2c(u8 *self) { return (u32)(unsigned long)(self + 0x2c); }
PCREG(54bba0, addr2c);

// 0x5acfe0, thiscall: returns this+8.
static u32 THISCALL addr8(u8 *self) { return (u32)(unsigned long)(self + 8); }
PCREG(5acfe0, addr8);

// 0x4986e0, thiscall: sets the byte at this+0x50 to 1.
static void THISCALL setByte50(u8 *self) { self[0x50] = 1; }
PCREG(4986e0, setByte50);

// 0x5060a0, thiscall: returns the constant 0x69c754.
static u32 THISCALL constTableAddr(u8 *self) { (void)self; return 0x69c754u; }
PCREG(5060a0, constTableAddr);

// 0x5696a0, thiscall: returns the dword at 0x6ec680.
static u32 THISCALL readGlobal6ec680(u8 *self) { (void)self; return *(u32 *)0x6ec680; }
PCREG(5696a0, readGlobal6ec680);
