// u69_23.cpp - area 69, group 23 (slice 8). Dword getters on self (thiscall, no args, ret 0), no callees.
#include "ff.h"

static u32 THISCALL dwordAt420e80(u8 *self) { return *(u32 *)(self + 0x1b4d); }
PCREG(420e80, dwordAt420e80);
static u32 THISCALL dwordAt5ed9c0(u8 *self) { return *(u32 *)(self + 0xdf); }
PCREG(5ed9c0, dwordAt5ed9c0);
static u32 THISCALL remaining5f3140(u8 *self) { return *(u32 *)(self + 0xc) - *(u32 *)(self + 8); }
PCREG(5f3140, remaining5f3140);
