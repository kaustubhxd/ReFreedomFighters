#include "ff.h"
// batch2762.cpp - unclaimed-27 batch 62 (residue 6). FUN_00663060 (GUESS): thiscall, one stack argument (pointer to 3 floats), ret 4.
// d = 0x4e0830(ecx = arg, edx = this+0x10) (float in st0). If d > the float at 0x67a284 (ordered compare; NaN fails):
// this[0x10..0x18] = arg[0..2]; this[0x1c..0x24] = this[4..0xc]; f = 0x4e0030(ecx = this+4, edx = this+0x10) (float in st0);
// this[0x3c] = 0; 0x662ab0(ecx = this+0x34, 0.0f) then 0x662b00(ecx = this+0x34, f), both thiscall, one stack float, ret 4.
extern "C" float FASTCALL ext_4e0830(u8 *a, u8 *b);
extern "C" float FASTCALL ext_4e0030(u8 *a, u8 *b);
extern "C" void THISCALL ext_662ab0(u8 *self, u32 bits);
extern "C" void THISCALL ext_662b00(u8 *self, u32 bits);

static void THISCALL funcUpdateDir(u8 *self, u8 *arg) {
  float d = ext_4e0830(arg, self + 0x10);
  if (!(d > *(float *)0x67a284)) return;
  *(u32 *)(self + 0x10) = *(u32 *)(arg + 0);
  *(u32 *)(self + 0x14) = *(u32 *)(arg + 4);
  *(u32 *)(self + 0x18) = *(u32 *)(arg + 8);
  *(u32 *)(self + 0x1c) = *(u32 *)(self + 4);
  *(u32 *)(self + 0x20) = *(u32 *)(self + 8);
  *(u32 *)(self + 0x24) = *(u32 *)(self + 0xc);
  float f = ext_4e0030(self + 4, self + 0x10);
  *(u32 *)(self + 0x3c) = 0;
  ext_662ab0(self + 0x34, 0);
  ext_662b00(self + 0x34, fbits(f));
}
PCREG(663060, funcUpdateDir);
