// batch811.cpp - core gameplay batch 811 (docs/20-unclaimed-65.md, batch 811), two residue-00 entries (core-todo/residue-00.txt):
// 0x51a7c0 returns the constant 0x69f26c (no argument, ret 0); 0x53e800 (CRigidBody::CopyData) copies the byte at +0x149 and the
// dwords at +0x145 and +0x141 from the argument into this (thiscall, ret 4).
#include "ff.h"

static u32 THISCALL fn51a7c0(void) { return 0x69f26c; }

static void THISCALL fn53e800(u8 *self, const u8 *src) {
  *(u8 *)(self + 0x149) = *(const u8 *)(src + 0x149);
  *(u32 *)(self + 0x145) = *(const u32 *)(src + 0x145);
  *(u32 *)(self + 0x141) = *(const u32 *)(src + 0x141);
}

PCREG(51a7c0, fn51a7c0);
PCREG(53e800, fn53e800);
