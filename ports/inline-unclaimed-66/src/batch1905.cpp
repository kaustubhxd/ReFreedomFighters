// batch1905.cpp - unclaimed-66 batch 5: five slice-5 leaves from the full exe list (names are GUESS; bodies from the bytes).
// All thiscall, no stack arguments. The float getter returns on ST0 (ret 0).
#include "ff.h"

// 0x440b10, GUESS FUN_00440b10: fld dword [this+0x58]; ret. Returns ST0.
static float THISCALL leaf440b10(u8 *self) {
  return *(float *)(self + 0x58);
}
PCREG(440b10, leaf440b10);

// 0x49a4d0, GUESS FUN_0049a4d0: eax = [[this+0xc]+0xc]; ret.
static u32 THISCALL leaf49a4d0(u8 *self) {
  u8 *a = *(u8 **)(self + 0xc);
  return *(u32 *)(a + 0xc);
}
PCREG(49a4d0, leaf49a4d0);

// 0x54bb90, GUESS FUN_0054bb90: eax = [this+0xa274]; ret.
static u32 THISCALL leaf54bb90(u8 *self) {
  return *(u32 *)(self + 0xa274);
}
PCREG(54bb90, leaf54bb90);

// 0x600810, GUESS FUN_00600810: eax = [this+8]; eax -= [this+4]; ret.
static u32 THISCALL leaf600810(u8 *self) {
  return *(u32 *)(self + 8) - *(u32 *)(self + 4);
}
PCREG(600810, leaf600810);

// 0x4cdc90, GUESS FUN_004cdc90: dword [this+0x28] = 0; ret.
static void THISCALL leaf4cdc90(u8 *self) {
  *(u32 *)(self + 0x28) = 0;
}
PCREG(4cdc90, leaf4cdc90);
