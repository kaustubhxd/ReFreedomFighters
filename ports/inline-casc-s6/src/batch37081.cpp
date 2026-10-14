// batch37081.cpp - cascade s6 batch 37081: 0x58eb50.
#include "ff.h"

extern "C" void THISCALL ext_473000(u8 *self, u8 *a);   // ret 4

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static inline void *tabObj() { return *(void **)(*(u8 **)0x70039c + 0x9b); }

// Slot 0x4c of the table object takes one argument at the first site and three (this, 0, 1) at the other two.
// 0x58eb50, thiscall(a) ret 4: attaches the entity a to this object. Stores the table handle of a at +0x83e; if a answers slot 0x1e0 (arg 0x1007d2) and its slot 0x2e8 object reports
// type 0xc or 0xb, then when a has more than one part (slot 0x35c) it takes the existing object for a (slot 0x55c) or builds one through a's slot 0x328 object, positions it
// (slots 0x320 / 0x324) and notifies a (slot 0x360); finally it creates a record of kind 'METI' through the slot 0x2e8 object, binds it and calls 0x473000.
static void THISCALL fn58eb50(u8 *self, u8 *a) {
  D32(self, 0x83e) = vcall<u32>(tabObj(), 0x4c, (u32)a);
  if ((u8)vcall<u32>(a, 0x1e0, 0x1007d2u)) {
    u8 *o = (u8 *)vcall<u32>(a, 0x2e8);
    if (vcall<u32>(o, 0x330) == 0xc || vcall<u32>(o, 0x330) == 0xb) {
      s32 cnt = (s32)vcall<u32>(a, 0x35c);
      if (cnt > 1) {
        u8 *e = (u8 *)vcall<u32>(self, 0x55c, (u32)a);
        if (!e) {
          u8 *q = (u8 *)vcall<u32>(a, 0x328);
          u32 r1 = vcall<u32>(self, 0x20, 0x4954454du);
          e = (u8 *)vcall<u32>(q, 0x2c4, r1);
          u32 r3 = vcall<u32>(tabObj(), 0x4c, (u32)self, 0u, 1u);
          vcall<void>(e, 0x2f0, r3);
        }
        u32 v = vcall<u32>(e, 0x320);
        vcall<void>(e, 0x324, v + (u32)(cnt - 1));
        vcall<void>(a, 0x360, 1u);
      }
      u8 *t = *(u8 **)(*(u8 **)0x70039c + 0x9b);
      u8 *b = (u8 *)vcall<u32>(o, 0x2c4, D32(t, 0xadc), 0x4954454du);
      u32 r5 = vcall<u32>(tabObj(), 0x4c, (u32)self, 0u, 1u);
      vcall<void>(b, 0x2f0, r5);
      vcall<void>(b, 0x2d0, 1u, 0u);
    }
  }
  ext_473000(self, a);
}
PCREG(58eb50, fn58eb50);
