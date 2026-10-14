// batch957.cpp - area 56 band (claim A19): 0x53a8f0. thiscall, no arguments, plain ret. Virtual calls are unverified (GUESS stubs).
#include "ff.h"

typedef void(THISCALL *Slot0)(u8 *self, u32 a);

static u32 slot(u8 *obj, u32 off) {
  return *(u32 *)(*(u32 *)obj + off);
}

// 0x53a8f0 (unnamed): calls vt[0](1) on the object at this+0 when non-null, then on the object at this+4 when non-null.
static void THISCALL callPair53a8f0(u8 *self) {
  u8 *a = *(u8 **)self;
  if (a) ((Slot0)slot(a, 0))(a, 1);
  u8 *b = *(u8 **)(self + 4);
  if (b) ((Slot0)slot(b, 0))(b, 1);
}
PCREG(53a8f0, callPair53a8f0);
