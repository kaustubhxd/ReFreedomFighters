// batch262.cpp - unclaimed area 67, slice floor(addr/16) mod 20 == 6 (FUN_ names; bodies from the PC bytes).
#include "ff.h"

typedef u32 (THISCALL *F1)(u8 *self, u32 a);
typedef u32 (THISCALL *F0)(u8 *self);

static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// 0x612160, thiscall (no stack args): obj = [this+0x2c]; ecx = vtable of obj (as the original loads it), argument obj,
// call slot 0x30 of that vtable; the callee pops the argument and the result is returned.
static u32 THISCALL callSlot30(u8 *selfP) {
  u32 self = (u32)(unsigned long)selfP;
  u32 obj = rdw(self, 0x2c);
  u32 vt = rdw(obj, 0);
  u32 fn = rdw(vt, 0x30);
  return ((F1)fn)((u8 *)(unsigned long)vt, obj);
}
PCREG(612160, callSlot30);

// 0x436120, thiscall (no stack args): tail call to slot 0x1c of the object at this+0x65 (that object is this).
static u32 THISCALL tailSlot1c(u8 *selfP) {
  u32 obj = rdw((u32)(unsigned long)selfP, 0x65);
  u32 fn = rdw(rdw(obj, 0), 0x1c);
  return ((F0)fn)((u8 *)(unsigned long)obj);
}
PCREG(436120, tailSlot1c);

// 0x45eda0, thiscall (no stack args): tail call to slot 0x100 of this (this is the object).
static u32 THISCALL tailSlot100(u8 *selfP) {
  u32 fn = rdw(rdw((u32)(unsigned long)selfP, 0), 0x100);
  return ((F0)fn)(selfP);
}
PCREG(45eda0, tailSlot100);

// 0x491b60, thiscall, ret 8 (two stack arguments, callee-cleaned): stores 0 at this+0xbc5.
static void THISCALL zeroAtBc5(u8 *self, u32 a, u32 b) {
  (void)a; (void)b;
  *(u32 *)(self + 0xbc5) = 0;
}
PCREG(491b60, zeroAtBc5);
