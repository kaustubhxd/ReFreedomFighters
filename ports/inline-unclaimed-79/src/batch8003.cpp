#include "ff.h"
// batch8003.cpp - unclaimed-79 gap-band accessor group 3 (docs/20-unclaimed-79.md). Names are GC names where known, else GUESS.

// 0x491ec0, GUESS FUN_491ec0 (getter at +0xbb0).
static u8 THISCALL f_491ec0(u8 *self) { return *(u8 *)(self + 0xbb0); }
PCREG(491ec0, f_491ec0);

// 0x491ed0, GUESS FUN_491ed0 (getter at +0xbc1).
static u8 THISCALL f_491ed0(u8 *self) { return *(u8 *)(self + 0xbc1); }
PCREG(491ed0, f_491ed0);

// 0x493ff0, GUESS FUN_493ff0 (getter at +0xbc2).
static u8 THISCALL f_493ff0(u8 *self) { return *(u8 *)(self + 0xbc2); }
PCREG(493ff0, f_493ff0);

// 0x4951d0, GUESS FUN_4951d0 (zero store at +0xbc3; 0 stack argument(s)).
static void THISCALL f_4951d0(u8 *self) { *(u8 *)(self + 0xbc3) = 0; }
PCREG(4951d0, f_4951d0);

// 0x497310, ZGeomBuffer::GeomCreationLocked() (getter at +0x50).
static u8 THISCALL f_497310(u8 *self) { return *(u8 *)(self + 0x50); }
PCREG(497310, f_497310);

// 0x499870, ZGeomBuffer::UnlockGeomCreation() (zero store at +0x50; 0 stack argument(s)).
static void THISCALL f_499870(u8 *self) { *(u8 *)(self + 0x50) = 0; }
PCREG(499870, f_499870);

// 0x49c660, CListUser::GetFullBuffer() (getter at +0x1d).
static u32 THISCALL f_49c660(u8 *self) { return *(u32 *)(self + 0x1d); }
PCREG(49c660, f_49c660);

// 0x49d6b0, ZEventList::NrEvents() (getter at +0x10).
static u32 THISCALL f_49d6b0(u8 *self) { return *(u32 *)(self + 0x10); }
PCREG(49d6b0, f_49d6b0);

