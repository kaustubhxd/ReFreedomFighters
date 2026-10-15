// batch67504.cpp - cascade s6 batch 67504: 0x4f28e0.
#include "ff.h"

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static inline void *tabObj() { return *(void **)(*(u8 **)0x70039c + 0x9b); }

// 0x4f28e0, thiscall(), plain ret: walks the embedded iterator at +0xcb (slot 0x54 starts, 0x6c yields the key through an out count, 0x44 advances) resolving each key through the
// table object (slot 0x58): the first non-null object is `a`, the next non-null one is `b` (iteration stops when the count turns zero). With `a` found the table is asked for a
// handle (slot 0x4c with b, 1, a) which is passed to slot 0x200-command 0x2dc of this; with `b` found a second handle request (slot 0x4c with a, this, 0) precedes command 0x100
// (argument b). Finally +0x63b is set to 1.
static void THISCALL fn4f28e0(u8 *self) {
  u8 *it = self + 0xcb;
  u32 cnt = 0;
  u8 *a = 0, *b = 0;
  vcall<void>(it, 0x54, (u32)&cnt);
  u32 key = vcall<u32>(it, 0x6c, (u32)&cnt);
  if (cnt == 0) {
    self[0x63b] = 1;
    return;
  }
  for (;;) {
    u8 *obj = (u8 *)vcall<u32>(tabObj(), 0x58, key);
    if (!a) {
      a = obj;
    } else {
      b = obj;
      if (b) break;
    }
    vcall<void>(it, 0x44, (u32)&cnt);
    key = vcall<u32>(it, 0x6c, (u32)&cnt);
    if (cnt == 0) break;
  }
  if (a) {
    u32 h = vcall<u32>(tabObj(), 0x4c, (u32)b, 1u, (u32)a);
    vcall<void>(self, 0x2dc, 0x200u, h);
  }
  if (b) {
    vcall<u32>(tabObj(), 0x4c, (u32)a, (u32)self, 0u);
    vcall<void>(self, 0x2dc, 0x100u, (u32)b);
  }
  self[0x63b] = 1;
}
PCREG(4f28e0, fn4f28e0);
