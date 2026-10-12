// batch1909.cpp - unclaimed-66 batch 9: three slice-5 leaves (names GUESS; bodies from the bytes). Thiscall.
#include "ff.h"

// 0x555550, GUESS FUN_00555550: dwords this+0xc, +0x10, +0x14 = 0; ret.
static void THISCALL leaf555550(u8 *self) {
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x10) = 0;
  *(u32 *)(self + 0x14) = 0;
}
PCREG(555550, leaf555550);

// 0x5e0dd0, GUESS FUN_005e0dd0: xmm0 = maxss(0.0, arg) (MAXSS returns the source operand when unordered or equal), then
// the float goes to this+0x1d17; ret 4 (one float argument).
static void THISCALL leaf5e0dd0(u8 *self, float a) {
  float r = (0.0f > a) ? 0.0f : a;
  *(float *)(self + 0x1d17) = r;
}
PCREG(5e0dd0, leaf5e0dd0);

// 0x5ab950, GUESS FUN_005ab950: eax = ZSysInterface; push [this+4]; ecx = [eax+0x9b]; call vtable +0x58 (callee pops); ret.
// Returns the callee's EAX.
static u32 THISCALL leaf5ab950(u8 *self) {
  u8 *sys = *(u8 **)0x70039c;
  u8 *db = *(u8 **)(sys + 0x9b);
  return vcall<u32>(db, 0x58, *(u32 *)(self + 4));
}
PCREG(5ab950, leaf5ab950);
