#include "ff.h"
// batch8002.cpp - unclaimed-79 gap-band accessor group 2 (docs/20-unclaimed-79.md). Names are GC names where known, else GUESS.

// 0x48f750, GUESS FUN_48f750 (zero store at +0xbc5; 1 stack argument(s)).
static void THISCALL f_48f750(u8 *self, u32 a0) { *(u32 *)(self + 0xbc5) = 0; }
PCREG(48f750, f_48f750);

// 0x48f7d0, GUESS FUN_48f7d0 (getter at +0xbc3).
static u8 THISCALL f_48f7d0(u8 *self) { return *(u8 *)(self + 0xbc3); }
PCREG(48f7d0, f_48f7d0);

// 0x48ffc0, GUESS FUN_48ffc0 (getter at +0x44).
static u32 THISCALL f_48ffc0(u8 *self) { return *(u32 *)(self + 0x44); }
PCREG(48ffc0, f_48ffc0);

// 0x490930, GUESS FUN_490930 (getter at +0x5d45).
static u32 THISCALL f_490930(u8 *self) { return *(u32 *)(self + 0x5d45); }
PCREG(490930, f_490930);

// 0x490d00, GUESS FUN_490d00 (getter at +0x5d25).
static u32 THISCALL f_490d00(u8 *self) { return *(u32 *)(self + 0x5d25); }
PCREG(490d00, f_490d00);

// 0x490fe0, ZEngineDataBase::GetStaticBuffer() (getter at +0x1c5d).
static u32 THISCALL f_490fe0(u8 *self) { return *(u32 *)(self + 0x1c5d); }
PCREG(490fe0, f_490fe0);

// 0x491b60, GUESS FUN_491b60 (zero store at +0xbc5; 2 stack argument(s)).
static void THISCALL f_491b60(u8 *self, u32 a0, u32 a1) { *(u32 *)(self + 0xbc5) = 0; }
PCREG(491b60, f_491b60);

// 0x491eb0, GUESS FUN_491eb0 (getter at +0xbc0).
static u8 THISCALL f_491eb0(u8 *self) { return *(u8 *)(self + 0xbc0); }
PCREG(491eb0, f_491eb0);

