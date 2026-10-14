// batch580.cpp - unclaimed area 58 (docs/20-unclaimed-58.md), slice floor(addr/16) mod 20 == 17.
#include "ff.h"

// 0x5eebd0, thiscall(a): if [this+0x45] != a: [this+0x45] = a and [this+0x77] = 1. Name GUESS (set a dword and flag).
static void THISCALL setDwordIfChanged_5eebd0(u8 *self, u32 a) {
  if (*(u32 *)(self + 0x45) != a) {
    *(u32 *)(self + 0x45) = a;
    self[0x77] = 1;
  }
}
PCREG(5eebd0, setDwordIfChanged_5eebd0);

extern "C" void THISCALL ext_584cc0(u8 *self, u32 arg);   // original release of the member object, thiscall, callee pops 4

// 0x4681d0, thiscall(): if [this+0x1de] is set, call the original 0x584cc0 with ecx = that object and the word this;
// then [this+0x1de] = 0. Name GUESS (release a member object).
static void THISCALL releaseMember_4681d0(u8 *self) {
  u8 *m = *(u8 **)(self + 0x1de);
  if (m) ext_584cc0(m, (u32)self);
  *(u32 *)(self + 0x1de) = 0;
}
PCREG(4681d0, releaseMember_4681d0);
