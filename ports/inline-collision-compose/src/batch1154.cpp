// batch1154.cpp - collision thread, batch 1154 (camera row, name GUESS: CMAINCAMERACONTROL::Command): 0x4fbe20. Thiscall (ECX = this),
// two stack arguments (cmd as a word, arg), ret 8; returns 0 on every path. Nine command words are checked in order at fixed
// offsets of this: +0x90 (slot 4 of [this+0x98] with arg, then slot 0x84 of this with (4, 0)); +0x92 (slot 0x3c of [this+0x98] with
// arg, then slot 0x84 with (5, 0)); +0x8e (store [this+0x48] to *arg unless arg is null); +0x82 (store arg at [this+0x84]); +0x72
// (store arg at [this+0x48]); +0x8a and +0x8c (walk the list at [[this+0x84]+0x48]: slot 0x12c of [this+0x44] with (entry, cmd,
// arg or 0), following the next pointer at +0xc); +0x14c (store arg at [this+0x14e]); +0x96 (float from slot 0x58 of the object
// returned by slot 0xbc of the sys object, stored at [this+0x5e]). The fakes are in the spec.
#include "ff.h"

typedef void (*Nothing)(void);

static u32 THISCALL command4fbe20(u8 *self, u32 cmdw, u32 arg) {
  u16 cmd = (u16)cmdw;
  if (cmd == *(u16 *)(self + 0x90)) {
    vcall<void>(self + 0x98, 4, arg);
    vcall<void>(self, 0x84, 4u, 0u);
    return 0;
  }
  if (cmd == *(u16 *)(self + 0x92)) {
    vcall<void>(self + 0x98, 0x3c, arg);
    vcall<void>(self, 0x84, 5u, 0u);
    return 0;
  }
  if (cmd == *(u16 *)(self + 0x8e)) {
    if (arg != 0) *(u32 *)arg = *(u32 *)(self + 0x48);
    return 0;
  }
  if (cmd == *(u16 *)(self + 0x82)) {
    *(u32 *)(self + 0x84) = arg;
    return 0;
  }
  if (cmd == *(u16 *)(self + 0x72)) {
    *(u32 *)(self + 0x48) = arg;
    return 0;
  }
  if (cmd == *(u16 *)(self + 0x8a) || cmd == *(u16 *)(self + 0x8c)) {
    bool useArg = (cmd == *(u16 *)(self + 0x8a));
    u8 *head = *(u8 **)(self + 0x84);
    if (head == 0) return 0;
    head = *(u8 **)(head + 0x48);
    if (head == 0) return 0;
    u32 cmdOut = useArg ? *(u16 *)(self + 0x8a) : *(u16 *)(self + 0x8c);
    for (u8 *e = head; e != 0; e = *(u8 **)(e + 0xc)) {
      vcall<void>(*(void **)(self + 0x44), 0x12c, *(u32 *)e, cmdOut, useArg ? arg : 0u);
    }
    return 0;
  }
  if (cmd == *(u16 *)(self + 0x14c)) {
    *(u32 *)(self + 0x14e) = arg;
    return 0;
  }
  if (cmd == *(u16 *)(self + 0x96)) {
    u8 *obj = (u8 *)vcall<u32>(G(void *, 0x70039c), 0xbc);
    *(float *)(self + 0x5e) = vcall<float>(obj, 0x58, 0x6922d4u, 1.0f);
    return 0;
  }
  return 0;
}
PCREG(4fbe20, command4fbe20);
