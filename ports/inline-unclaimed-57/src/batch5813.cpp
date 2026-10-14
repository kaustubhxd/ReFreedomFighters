// batch5813.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 113: 0x5d3d90 (GUESS name unnamed_5d3d90), thiscall, no stack args, plain ret.
// fetch(k): x = sub->vt[+0x138]() (sub = (engine 0x70039c)+0x9b); loc = 0; x->vt[+0x88](k, &loc); return loc. Then this+0x68 = fetch(0x681320),
// this+0x6c = fetch(0x68fcbc), this+0x70 = fetch(0x68fccc), this+0x74 = fetch(0x68fcdc); l = fetch(0x67a1b8); this+0x85 = sub->vt[+0x58](l).
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef u32(THISCALL *SlotN)(u8 *self);
typedef void(THISCALL *Slot2)(u8 *self, u32 a, u32 b);

// the lookup used five times in the original: the sub-object's slot +0x138 gives an object, whose slot +0x88 writes a dword for the key
static u32 fetch(u32 key) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  u8 *x = (u8 *)(unsigned long)((SlotN)VT(sub)[0x138 / 4])(sub);
  u32 loc = 0;
  ((Slot2)VT(x)[0x88 / 4])(x, key, (u32)(unsigned long)&loc);
  return loc;
}

// 0x5d3d90, thiscall, no stack args (GUESS name)
static void THISCALL unnamed5d3d90(u8 *self) {
  *(u32 *)(self + 0x68) = fetch(0x681320);
  *(u32 *)(self + 0x6c) = fetch(0x68fcbc);
  *(u32 *)(self + 0x70) = fetch(0x68fccc);
  *(u32 *)(self + 0x74) = fetch(0x68fcdc);
  u32 l = fetch(0x67a1b8);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  *(u32 *)(self + 0x85) = ((SlotA)VT(sub)[0x58 / 4])(sub, l);
}
PCREG(5d3d90, unnamed5d3d90);
