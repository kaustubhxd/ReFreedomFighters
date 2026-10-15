// batch5816.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 116: 0x5de260 (GUESS name unnamed_5de260), thiscall, no stack args, plain ret.
// lookup(slot, key): x = sub->vt[+0x138](); loc = 0; x->vt[slot](key, &loc); return loc (sub = (engine 0x70039c)+0x9b).
// this+0x114 = sub->vt[+0x58](lookup(0x88, 0x681320)); this+0x118 = lookup(0x84, 0x6954e8); this+0x11c = lookup(0x84, 0x6954f8);
// e = x->vt[+0x9c](0x69c218, 4) with x = sub->vt[+0x138](); this+0x120/+0x124/+0x128 = (float)e[0..2] * G(0x697890);
// A = this+0x114; this+0x134 = sub->vt[+0x58](A+0x676 (dword)); this+0x130 = this+0x134->vt[+0x100](0x67d9e8).
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef u32(THISCALL *SlotN)(u8 *self);
typedef void(THISCALL *Slot2)(u8 *self, u32 a, u32 b);
typedef u32(THISCALL *Slot2r)(u8 *self, u32 a, u32 b);

// the lookup used three times in the original: the sub-object's slot +0x138 gives an object, whose slot (0x88 or 0x84) writes a dword for the key
static u32 lookup(u32 slot, u32 key) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  u8 *x = (u8 *)(unsigned long)((SlotN)VT(sub)[0x138 / 4])(sub);
  u32 loc = 0;
  ((Slot2)VT(x)[slot / 4])(x, key, (u32)(unsigned long)&loc);
  return loc;
}

// 0x5de260, thiscall, no stack args (GUESS name)
static void THISCALL unnamed5de260(u8 *self) {
  u32 a = lookup(0x88, 0x681320);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  *(u32 *)(self + 0x114) = ((SlotA)VT(sub)[0x58 / 4])(sub, a);
  *(u32 *)(self + 0x118) = lookup(0x84, 0x6954e8);
  *(u32 *)(self + 0x11c) = lookup(0x84, 0x6954f8);
  eng = G(u8 *, 0x70039c);
  sub = *(u8 **)(eng + 0x9b);
  u8 *x = (u8 *)(unsigned long)((SlotN)VT(sub)[0x138 / 4])(sub);
  u8 *e = (u8 *)(unsigned long)((Slot2r)VT(x)[0x9c / 4])(x, 0x69c218, 4);
  float c = G(float, 0x697890);
  *(float *)(self + 0x120) = (float)*(s32 *)(e + 0) * c;
  *(float *)(self + 0x124) = (float)*(s32 *)(e + 4) * c;
  *(float *)(self + 0x128) = (float)*(s32 *)(e + 8) * c;
  u8 *A = *(u8 **)(self + 0x114);
  u32 k = *(u32 *)(A + 0x676);
  eng = G(u8 *, 0x70039c);
  sub = *(u8 **)(eng + 0x9b);
  u8 *B = (u8 *)(unsigned long)((SlotA)VT(sub)[0x58 / 4])(sub, k);
  *(u32 *)(self + 0x134) = (u32)(unsigned long)B;
  *(u32 *)(self + 0x130) = ((SlotA)VT(B)[0x100 / 4])(B, 0x67d9e8);
}
PCREG(5de260, unnamed5de260);
