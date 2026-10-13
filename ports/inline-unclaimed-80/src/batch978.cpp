#include "ff.h"
// batch978.cpp - unclaimed-80 residue-19 (docs/20-unclaimed-80.md), batch 56: 0x54aaf0 (thiscall, self in ecx, one stack argument a, ret 4, returns al).
// r = self.vt[0xa8]() (thiscall, no arguments). [self+0xa273] = 0. If (a low byte) != 0 and [r+0xc8] != 0: [self+0xa273] = 1. Return [self+0xa273].

typedef u32(THISCALL *tc0)(u8 *);

static u8 THISCALL zg54aaf0(u8 *self, u32 a) {
  u8 *r = (u8 *)((tc0)(*(u32 *)(*(u32 *)self + 0xa8)))(self);
  *(u8 *)(self + 0xa273) = 0;
  if ((u8)a != 0 && *(u8 *)(r + 0xc8) != 0) *(u8 *)(self + 0xa273) = 1;
  return *(u8 *)(self + 0xa273);
}
PCREG(54aaf0, zg54aaf0);
