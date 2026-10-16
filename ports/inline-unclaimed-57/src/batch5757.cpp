// batch5757.cpp - unclaimed-57, band batch 57 (name GUESS): 0x5d9f00, stdcall, three args (a, b, c), ret 12 (the object is not read). Engine
// (global 0x70039c) + 0x9b = obj; s = obj->vt[+0x58](a) (thiscall, one arg; stubbed). If s is null, return. If c != 0: if b == 0, s->vt[+0xbc](0);
// then s->vt[+0x250](c). If c == 0: if b == 0, s->vt[+0x250](0); else s->vt[+0xbc](1). Slots are unverified callees, stubbed in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))
#define G(T, addr) (*(T *)(addr))

typedef u32(THISCALL *SlotR)(u8 *self, u32 a);
typedef void(THISCALL *SlotA)(u8 *self, u32 a);

static void STDCALL unnamed5d9f00(u32 a, u32 b, u32 c) {
  u8 *engine = G(u8 *, 0x70039c);
  u8 *obj = *(u8 **)(engine + 0x9b);
  u8 *s = (u8 *)(unsigned long)((SlotR)VT(obj)[0x58 / 4])(obj, a);
  if (s == 0) return;
  if (c != 0) {
    if (b == 0) ((SlotA)VT(s)[0xbc / 4])(s, 0);
    ((SlotA)VT(s)[0x250 / 4])(s, c);
  } else {
    if (b == 0) ((SlotA)VT(s)[0x250 / 4])(s, 0);
    else ((SlotA)VT(s)[0xbc / 4])(s, 1);
  }
}
PCREG(5d9f00, unnamed5d9f00);
