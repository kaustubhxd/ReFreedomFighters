// batch5806.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 106: 0x5d81b0 (GUESS name unnamed_5d81b0), thiscall, two stack arguments (a16: the low
// word is compared; b unused; ret 8), returns 0. If w == this+0x4a: eng->vt[+0x1cc](0); eng+0x1b40 = 1.0f; eng->vt[+0xc](0, 0, 0, 0); n = sub->vt[+0xac]();
// n times: sub->vt[+0xa4](); p = eng+0x190f; p->vt[+0xbc](); sub->vt[+0xa0](this+0x4e). Else if w == this+0x4c: 0x5d8470(this) (hooked); if
// this+0xbc == 0: obj = this+0x44; obj->vt[+0x114](0x10). (sub = (engine 0x70039c)+0x9b.)
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotN)(u8 *self);
typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef u32(THISCALL *Slot4)(u8 *self, u32 a, u32 b, u32 c, u32 d);

extern "C" void THISCALL ext_5d8470(u8 *self);  // another area's function, original code (hooked in the spec)

// 0x5d81b0, thiscall, two stack arguments (GUESS name)
static u32 THISCALL unnamed5d81b0(u8 *self, u32 a16, u32 b) {
  (void)b;
  u16 w = (u16)a16;
  if (w == *(u16 *)(self + 0x4a)) {
    u8 *eng = G(u8 *, 0x70039c);
    ((SlotA)VT(eng)[0x1cc / 4])(eng, 0);
    eng = G(u8 *, 0x70039c);
    *(float *)(eng + 0x1b40) = 1.0f;
    eng = G(u8 *, 0x70039c);
    ((Slot4)VT(eng)[0xc / 4])(eng, 0, 0, 0, 0);
    eng = G(u8 *, 0x70039c);
    u8 *sub = *(u8 **)(eng + 0x9b);
    u32 n = ((SlotN)VT(sub)[0xac / 4])(sub);
    for (s32 i = (s32)n; i > 0; i--) {
      eng = G(u8 *, 0x70039c);
      sub = *(u8 **)(eng + 0x9b);
      ((SlotN)VT(sub)[0xa4 / 4])(sub);
    }
    eng = G(u8 *, 0x70039c);
    u8 *p = *(u8 **)(eng + 0x190f);
    ((SlotN)VT(p)[0xbc / 4])(p);
    eng = G(u8 *, 0x70039c);
    sub = *(u8 **)(eng + 0x9b);
    ((SlotA)VT(sub)[0xa0 / 4])(sub, (u32)(unsigned long)(self + 0x4e));
  } else if (w == *(u16 *)(self + 0x4c)) {
    ext_5d8470(self);
    if (*(u32 *)(self + 0xbc) == 0) {
      u8 *obj = *(u8 **)(self + 0x44);
      ((SlotA)VT(obj)[0x114 / 4])(obj, 0x10);
    }
  }
  return 0;
}
PCREG(5d81b0, unnamed5d81b0);
