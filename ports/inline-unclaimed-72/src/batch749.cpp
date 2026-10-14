// batch749.cpp - area 72, gap list round 2 (2026-10-12): vtable stores, field getters and simple virtual calls (docs/20-unclaimed-72.md).
#include "ff.h"

// 0x54ba10 u8_a273
static u8 THISCALL f_54ba10(u8 *self) { return *(u8 *)(self + 0xa273); }
PCREG(54ba10, f_54ba10);

// 0x59b3b0 ptr_121b0
static u8 *THISCALL f_59b3b0(u8 *self) { return self + 0x121b0; }
PCREG(59b3b0, f_59b3b0);

// 0x59c610 ptr_12108
static u8 *THISCALL f_59c610(u8 *self) { return self + 0x12108; }
PCREG(59c610, f_59c610);

// 0x59ca40 ptr_1210c
static u8 *THISCALL f_59ca40(u8 *self) { return self + 0x1210c; }
PCREG(59ca40, f_59ca40);

// 0x4f4cc0 bit4_70
static u8 THISCALL f_4f4cc0(u8 *self) { return (u8)((*(u32 *)(self + 0x70) >> 4) & 1); }
PCREG(4f4cc0, f_4f4cc0);

// 0x54df90 vc24_true
static bool THISCALL f_54df90(u8 *self) { vcall<void>(self, 0x24); return true; }
PCREG(54df90, f_54df90);

// 0x54e080 vc2c_zero
static void THISCALL f_54e080(u8 *self) { vcall<void>(self, 0x2c, 0u); }
PCREG(54e080, f_54e080);

// 0x4ce510 vc8_zero
static void THISCALL f_4ce510(u8 *self) { vcall<void>(self, 0x8, 0u); }
PCREG(4ce510, f_4ce510);

