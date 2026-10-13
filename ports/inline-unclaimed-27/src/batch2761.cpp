#include "ff.h"
// batch2761.cpp - unclaimed-27 batch 61 (residue 6). FUN_00662660 (GUESS): thiscall, one stack argument (an object whose vtable
// is used), ret 4, returns true (AL). Sends floats at +0, +4, +8, +0xc, then the byte at +0x10 via vslot +0x60, then floats at
// +0x11, +0x15, +0x19, +0x1d, +0x21, +0x25, +0x29 (unaligned); each float goes through vslot +0x4c (thiscall, one stack float, callee pops 4). The floats are passed as raw dwords, which is the same stack layout
// as the movss store in the exe and cannot canonicalise a NaN.
static u8 THISCALL funcSendFloats(u8 *self, u8 *o) {
  typedef void(THISCALL * F)(u8 *, u32);
  u32 *vt = *(u32 **)o;
  F f4c = (F)vt[0x4c / 4];
  f4c(o, *(u32 *)(self + 0));
  f4c = (F)(*(u32 **)o)[0x4c / 4];
  f4c(o, *(u32 *)(self + 4));
  f4c = (F)(*(u32 **)o)[0x4c / 4];
  f4c(o, *(u32 *)(self + 8));
  f4c = (F)(*(u32 **)o)[0x4c / 4];
  f4c(o, *(u32 *)(self + 0xc));
  ((F)(*(u32 **)o)[0x60 / 4])(o, *(u8 *)(self + 0x10));
  for (u32 off = 0x11; off <= 0x29; off += 4) {
    ((F)(*(u32 **)o)[0x4c / 4])(o, *(u32 *)(self + off));
  }
  return 1;
}
PCREG(662660, funcSendFloats);
