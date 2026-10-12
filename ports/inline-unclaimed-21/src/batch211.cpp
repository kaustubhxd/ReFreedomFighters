// batch211.cpp - unclaimed area 21 (docs/20-unclaimed-21.md), slice floor(addr/16) mod 20 == 0. Three small functions:
// a guarded vtable release, a list walk that sets a flag on each node, and a constructor that writes its fields.
// Names GUESS.
#include "ff.h"

typedef void(THISCALL *SlotArg)(u8 *, u32);         // vtable slot, one stack word, no result used
typedef u32(THISCALL *SlotRet)(u8 *);               // vtable slot with no argument, eax result

// 0x514500, thiscall(): v = [this+0x1d1]; if v: this->vtable[0x2ec](this, v); [this+0x1d1] = 0. Name GUESS.
static void THISCALL slot2ecRelease_514500(u8 *self) {
  u32 v = *(u32 *)(self + 0x1d1);
  if (v) {
    ((SlotArg)(*(u32 *)(*(u32 *)self + 0x2ec)))(self, v);
    *(u32 *)(self + 0x1d1) = 0;
  }
}
PCREG(514500, slot2ecRelease_514500);

// 0x440d40, thiscall(): for node = this; node; node = node->vtable[0x20](node): [node+0x30] |= 0x8000. Name GUESS.
static void THISCALL flagWalk_440d40(u8 *self) {
  u8 *node = self;
  while (node) {
    *(u32 *)(node + 0x30) |= 0x8000u;
    node = (u8 *)((SlotRet)(*(u32 *)(*(u32 *)node + 0x20)))(node);
  }
}
PCREG(440d40, flagWalk_440d40);

// 0x487600, thiscall(a, b) (ret 8): [this+4] = a; [this+0x10] = b; [this+0x1c] = 1 (byte); [this+0xc], [this+0x14],
// [this+0x18], [this+8] = 0; [this] = vtable 0x68d0e8; [this+0x21] = 0 (byte); returns this. Name GUESS.
static u8 *THISCALL ctorFields_487600(u8 *self, u32 a, u32 b) {
  *(u32 *)(self + 4) = a;
  *(u32 *)(self + 0x10) = b;
  *(u8 *)(self + 0x1c) = 1;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x14) = 0;
  *(u32 *)(self + 0x18) = 0;
  *(u32 *)(self + 8) = 0;
  *(u32 *)self = 0x68d0e8u;
  *(u8 *)(self + 0x21) = 0;
  return self;
}
PCREG(487600, ctorFields_487600);
