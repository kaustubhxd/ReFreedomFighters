// batch1404.cpp - unclaimed-14 batch 4 (slice 13, docs/20-unclaimed-14.md): ZActor::GetMoveFromPos(float*) const.
#include "ff.h"

// 0x478d10, ZActor::GetMoveFromPos(float*) const (high): thiscall, one stack argument (the out pointer), ret 4.
// Zeroes the out vector, calls vtable slot +0x57c with a local buffer and the out pointer (two stack arguments, callee
// pops 8; the callee's result is not read here), then
// if the byte at +0x726 is nonzero copies a vector from +0x6e6 (when the dword at +0x64c is 0xa) or from +0x660.
// The PC code also calls the stack-cookie check (0x633654) before returning; with a matching cookie it does nothing,
// so the port omits it (GUESS: the cookie always matches in this function).
static void THISCALL actorGetMoveFromPos(u8 *self, u32 out) {
  u32 *o = (u32 *)out;
  u32 buf[3];
  o[2] = 0;
  o[1] = 0;
  o[0] = 0;
  typedef void(THISCALL * slot_fn)(u8 *, u32 *, u32);
  slot_fn f = *(slot_fn *)(*(u32 *)self + 0x57c);
  f(self, buf, out);
  if (self[0x726] == 0)
    return;
  if (*(u32 *)(self + 0x64c) == 0xa) {
    o[0] = *(u32 *)(self + 0x6e6);
    o[1] = *(u32 *)(self + 0x6ea);
    o[2] = *(u32 *)(self + 0x6ee);
  } else {
    o[0] = *(u32 *)(self + 0x660);
    o[1] = *(u32 *)(self + 0x664);
    o[2] = *(u32 *)(self + 0x668);
  }
}
PCREG(478d10, actorGetMoveFromPos);
