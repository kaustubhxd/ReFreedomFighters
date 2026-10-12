// batch1907.cpp - unclaimed-66 batch 7: four slice-5 leaves (names GUESS; bodies from the bytes). Thiscall.
#include "ff.h"

// 0x40ce50, GUESS FUN_0040ce50: ret (an empty thiscall).
static void THISCALL leaf40ce50(u8 *self) {
  (void)self;
}
PCREG(40ce50, leaf40ce50);

// 0x4b0b90, GUESS FUN_004b0b90: eax = dword at the global 0x6e6730; ret.
static u32 THISCALL leaf4b0b90(u8 *self) {
  (void)self;
  return *(u32 *)0x6e6730;
}
PCREG(4b0b90, leaf4b0b90);

// 0x65c9d0, GUESS FUN_0065c9d0: edx = [this+0x400]; eax = [this+0x410]; [edx] = eax; ret.
static void THISCALL leaf65c9d0(u8 *self) {
  u8 *dst = *(u8 **)(self + 0x400);
  *(u32 *)dst = *(u32 *)(self + 0x410);
}
PCREG(65c9d0, leaf65c9d0);

// 0x4f7950, GUESS FUN_004f7950: push [this+0x93]; call vtable +0x36c of this (ECX = this); ret (the callee pops the argument).
static void THISCALL leaf4f7950(u8 *self) {
  vcall<void>(self, 0x36c, *(u32 *)(self + 0x93));
}
PCREG(4f7950, leaf4f7950);
