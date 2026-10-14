// batch581.cpp - unclaimed area 58 (docs/20-unclaimed-58.md), slice floor(addr/16) mod 20 == 17. Word-keyed dispatch.
#include "ff.h"

extern "C" void THISCALL ext_5b5420(u8 *self);          // original helper, thiscall, no stack args
extern "C" void THISCALL ext_5b5370(u8 *self, u32 a);   // original helper, thiscall, callee pops 4

// 0x5b2bd0, thiscall(w: word, p) ret 8. Compare w (16 bits) with the words at +0x240, +0x242, +0x244, +0x246, +0x24a,
// +0x24c, +0x24e in turn; the first match decides:
//   +0x240: [this+0x4c] = 1.
//   +0x242: if p: [this+0x55] = (*(u32*)p != 0).   +0x244: if p: [this+0x56] = (*(u32*)p != 0).
//   +0x246: ext_5b5420(this).                       +0x24a: ext_5b5370(this, 0).   +0x24c: ext_5b5370(this, 4).
//   +0x24e: [this+0x1b2] = 0.
// Every path returns 0. Name GUESS (word-keyed dispatch).
static u32 THISCALL dispatchWord_5b2bd0(u8 *self, u32 wordArg, u32 p) {
  u16 w = (u16)wordArg;
  if (w == *(u16 *)(self + 0x240)) {
    self[0x4c] = 1;
  } else if (w == *(u16 *)(self + 0x242)) {
    if (p) self[0x55] = (*(u32 *)p != 0);
  } else if (w == *(u16 *)(self + 0x244)) {
    if (p) self[0x56] = (*(u32 *)p != 0);
  } else if (w == *(u16 *)(self + 0x246)) {
    ext_5b5420(self);
  } else if (w == *(u16 *)(self + 0x24a)) {
    ext_5b5370(self, 0);
  } else if (w == *(u16 *)(self + 0x24c)) {
    ext_5b5370(self, 4);
  } else if (w == *(u16 *)(self + 0x24e)) {
    self[0x1b2] = 0;
  }
  return 0;
}
PCREG(5b2bd0, dispatchWord_5b2bd0);
