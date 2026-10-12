#include "ff.h"
// batch8010.cpp - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Names GUESS (no GC name).

// 0x486e30 (GUESS): returns the constant 0x68cc08.
static u32 f_486e30() { return 0x68cc08; }
PCREG(486e30, f_486e30);

// 0x486e40 (GUESS): returns the constant 0x68cc78.
static u32 f_486e40() { return 0x68cc78; }
PCREG(486e40, f_486e40);

// 0x486e60 (GUESS): returns the constant 0x68cc40.
static u32 f_486e60() { return 0x68cc40; }
PCREG(486e60, f_486e60);

// 0x4951e0 (GUESS): decrements the dword at this+0xbc9.
static void THISCALL f_4951e0(u8 *self) { (*(s32 *)(self + 0xbc9))--; }
PCREG(4951e0, f_4951e0);

// 0x49def0 (GUESS): stores vtable 0x68f008 at this, zeros this+4, returns this.
static u8 *THISCALL f_49def0(u8 *self) { *(u32 *)self = 0x68f008; *(u32 *)(self + 4) = 0; return self; }
PCREG(49def0, f_49def0);

// 0x49c620 (GUESS): stores this+0x31 to the dword at its argument, returns this+0x35.
static u32 THISCALL f_49c620(u8 *self, u32 p) { *(u32 *)(unsigned long)p = *(u32 *)(self + 0x31); return *(u32 *)(self + 0x35); }
PCREG(49c620, f_49c620);

// 0x49c640 (GUESS): stdcall, stores 0x200 at its argument, returns 0x6ffaa8.
static u32 STDCALL f_49c640(u32 p) { *(u32 *)(unsigned long)p = 0x200; return 0x6ffaa8; }
PCREG(49c640, f_49c640);

// 0x496330 (GUESS): returns (arg - field) < field, unsigned, on the sub-object at this+0x14 (setb al).
static u8 THISCALL f_496330(u8 *self, u32 a) { u8 *c = *(u8 **)(self + 0x14); return (u32)(a - *(u32 *)(c + 4)) < *(u32 *)(c + 0xc); }
PCREG(496330, f_496330);
