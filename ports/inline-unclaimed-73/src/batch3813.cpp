// batch3813.cpp - area 73 batch 13 (gap band 0x4e1000-0x501000, shortest unnamed rows): GUESS names FUN_4f65d0, FUN_4e6870,
// FUN_4f22c0, FUN_4f65f0 (docs/20-unclaimed-73.md). Names are GUESS (no name map entry); bodies from the PC bytes.
#include "ff.h"

// 0x4f65d0 (GUESS FUN_4f65d0): eax = [[this+0x97]+0xc]; plain ret.
static u32 THISCALL guess4f65d0(u8 *self) {
  u8 *p = *(u8 **)(self + 0x97);
  return *(u32 *)(p + 0xc);
}
PCREG(4f65d0, guess4f65d0);

// 0x4e6870 (GUESS FUN_4e6870): eax = [this+8] + [this+8]; push eax; call vtable slot 0 on this (the callee pops it); plain ret.
static void THISCALL guess4e6870(u8 *self) {
  u32 v = *(u32 *)(self + 8);
  vcall<void>(self, 0, v + v);
}
PCREG(4e6870, guess4e6870);

// 0x4f22c0 (GUESS FUN_4f22c0): returns the low byte of the argument, zero-extended; ret 4.
static u32 THISCALL guess4f22c0(u8 *self, u32 a) {
  (void)self;
  return (u8)a;
}
PCREG(4f22c0, guess4f22c0);

// 0x4f65f0 (GUESS FUN_4f65f0): vtable slot +0xbc on this with one argument (1); plain ret.
static void THISCALL guess4f65f0(u8 *self) {
  vcall<void>(self, 0xbc, 1u);
}
PCREG(4f65f0, guess4f65f0);
