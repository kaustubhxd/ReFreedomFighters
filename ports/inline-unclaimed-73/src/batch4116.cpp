// batch4116.cpp - area 73 batch 16 (gap band, GUESS names): FUN_4f3930, FUN_4f3e60, FUN_4f22e0.
#include "ff.h"

// 0x4f3930 (GUESS FUN_4f3930): dword store of the argument bits at this+0x97; ret 4.
static void THISCALL guess4f3930(u8 *self, u32 a) {
  *(u32 *)(self + 0x97) = a;
}
PCREG(4f3930, guess4f3930);

// 0x4f3e60 (GUESS FUN_4f3e60): render control (g_sys+0x9b) slot +0x58 with the dword at this+0x60; plain ret.
static void THISCALL guess4f3e60(u8 *self) {
  u8 *ctl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  vcall<u32>(ctl, 0x58, *(u32 *)(self + 0x60));
}
PCREG(4f3e60, guess4f3e60);

// 0x4f22e0 (GUESS FUN_4f22e0): copies the dwords at this+0x77 and this+0x7b to the two dwords at the argument pointer; ret 4.
static void THISCALL guess4f22e0(u8 *self, u32 out) {
  u32 *o = (u32 *)out;
  o[0] = *(u32 *)(self + 0x77);
  o[1] = *(u32 *)(self + 0x7b);
}
PCREG(4f22e0, guess4f22e0);
