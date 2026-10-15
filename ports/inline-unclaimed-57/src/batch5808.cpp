// batch5808.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 108: 0x5d78e0 (GUESS name unnamed_5d78e0), thiscall, no stack args, plain ret.
// eng = (global 0x70039c); q = eng+0x1907: if q: q->vt[+0xc](0x6ef72c, 0x6b5de0, 0). eng->vt[+0x1cc](1). 0x5d7b10() (unclaimed; hooked in the spec).
// if this+0x1c8 != the local's address: this+0x1c8 = eng+0x40 + 0x800. p = eng+0x190f: v = p->vt[+0xdc](); r = p->vt[+0xd8]((float)v);
// p->vt[+0x134](0, 0, (float)r); p->vt[+0x138](3, 0); p->vt[+0x50](); p->vt[+0x138](3, 0); p->vt[+0x50]().
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef u32(THISCALL *SlotN)(u8 *self);
typedef void(THISCALL *Slot3u)(u8 *self, u32 a, u32 b, u32 c);
typedef u32(THISCALL *SlotF)(u8 *self, float f);
typedef void(THISCALL *Slot3f)(u8 *self, u32 a, u32 b, float c);
typedef void(THISCALL *Slot2)(u8 *self, u32 a, u32 b);

extern "C" void ext_5d7b10(void);  // unclaimed, original code (hooked in the spec)

// 0x5d78e0, thiscall, no stack args (GUESS name)
static void THISCALL unnamed5d78e0(u8 *self) {
  u32 loc = 0;  // stands in for the original's local address (never equal to this+0x1c8)
  u8 *eng = G(u8 *, 0x70039c);
  u8 *q = *(u8 **)(eng + 0x1907);
  if (q != 0) {
    ((Slot3u)VT(q)[0xc / 4])(q, 0x6ef72c, 0x6b5de0, 0);
    eng = G(u8 *, 0x70039c);
  }
  ((SlotA)VT(eng)[0x1cc / 4])(eng, 1);
  ext_5d7b10();
  if ((u8 *)(self + 0x1c8) != (u8 *)&loc) {
    eng = G(u8 *, 0x70039c);
    *(u32 *)(self + 0x1c8) = *(u32 *)(eng + 0x40) + 0x800;
  }
  eng = G(u8 *, 0x70039c);
  u8 *p = *(u8 **)(eng + 0x190f);
  s32 v = (s32)((SlotN)VT(p)[0xdc / 4])(p);
  u32 r = ((SlotF)VT(p)[0xd8 / 4])(p, (float)v);
  ((Slot3f)VT(p)[0x134 / 4])(p, 0, 0, (float)(s32)r);
  ((Slot2)VT(p)[0x138 / 4])(p, 3, 0);
  ((SlotN)VT(p)[0x50 / 4])(p);
  ((Slot2)VT(p)[0x138 / 4])(p, 3, 0);
  ((SlotN)VT(p)[0x50 / 4])(p);
}
PCREG(5d78e0, unnamed5d78e0);
