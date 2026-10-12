// batch4318.cpp - area 73 batch 18 (gap band, GUESS names): FUN_4fa100, FUN_4ffbd0, FUN_4f52e0, FUN_4face0.
#include "ff.h"

// Helpers (original code, hooked in the spec): thiscall with one argument (0x44edd0, 0x4ef660), thiscall without (0x4e1b30).
extern "C" void THISCALL ext_44edd0(u8 *self, u32 a);
extern "C" void THISCALL ext_4ef660(u8 *self, u32 a);
extern "C" void THISCALL ext_4e1b30(u8 *self);

// 0x4fa100 (GUESS FUN_4fa100): o = slot +0x2c4 on this; slot +0x2ec(this) on o; plain ret.
static void THISCALL guess4fa100(u8 *self) {
  u32 o = vcall<u32>(self, 0x2c4);
  vcall<void>((void *)o, 0x2ec, (u32)self);
}
PCREG(4fa100, guess4fa100);

// 0x4ffbd0 (GUESS FUN_4ffbd0): stdcall (ret 0x10). The object is the fourth argument; slot +0x18 with (arg3, arg1, arg2).
static void __attribute__((stdcall)) guess4ffbd0(u32 a1, u32 a2, u32 a3, u8 *obj) {
  vcall<void>(obj, 0x18, a3, a1, a2);
}
PCREG(4ffbd0, guess4ffbd0);

// 0x4f52e0 (GUESS FUN_4f52e0): ext_44edd0(this, arg), then ext_4e1b30(arg); ret 4.
static void THISCALL guess4f52e0(u8 *self, u32 a) {
  ext_44edd0(self, a);
  ext_4e1b30((u8 *)a);
}
PCREG(4f52e0, guess4f52e0);

// 0x4face0 (GUESS FUN_4face0): ext_4ef660(this, arg), then ext_4e1b30(arg); ret 4.
static void THISCALL guess4face0(u8 *self, u32 a) {
  ext_4ef660(self, a);
  ext_4e1b30((u8 *)a);
}
PCREG(4face0, guess4face0);
