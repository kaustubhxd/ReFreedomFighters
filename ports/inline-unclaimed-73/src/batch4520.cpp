// batch4520.cpp - area 73 batch 20 (gap band, GUESS names): FUN_4f50a0, FUN_4f6430.
#include "ff.h"

// 0x4cc500: thiscall, ECX = the argument, no stack arguments; returns eax (original code, hooked in the spec).
extern "C" u32 THISCALL ext_4cc500(u8 *obj);

// 0x4f50a0 (GUESS FUN_4f50a0): stdcall-like (ret 8, two arguments). o = slot +0x20 on this; slot +0x128 on o with (arg1, arg2, 0);
// returns 0.
static u32 THISCALL guess4f50a0(u8 *self, u32 a1, u32 a2) {
  u32 o = vcall<u32>(self, 0x20);
  vcall<void>((void *)o, 0x128, a1, a2, 0u);
  return 0;
}
PCREG(4f50a0, guess4f50a0);

// 0x4f6430 (GUESS FUN_4f6430): ret 4 (one argument). r = helper 0x4cc500(arg); slot +0x280 on this with r; plain return.
static void THISCALL guess4f6430(u8 *self, u32 arg) {
  u32 r = ext_4cc500((u8 *)arg);
  vcall<void>(self, 0x280, r);
}
PCREG(4f6430, guess4f6430);
