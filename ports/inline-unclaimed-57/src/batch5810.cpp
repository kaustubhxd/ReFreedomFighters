// batch5810.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 110: 0x5da160 (GUESS name unnamed_5da160), thiscall, two stack arguments (a16: the low
// word is compared; b unused; ret 8), returns 0. e = 0x5da470(this) (batch 99; hooked); if e == 0 return. w = low word of a16.
// Branch 1 (w == this+0x50): p = (engine)+0x190f; p->vt[+0xb8](e); e->vt[+0x254](); this+0x4c = 0.
// Branch 2 (w == this+0x52): x = this+0x4c; if x != 2: this+0x48 = 0; if x == 0: 0x5da670(this, e, this+0x66) (batch 48; hooked);
//   p->vt[+0xac](e, 1500.0f); e->vt[+0x250](). Then this+0x4c = 1.
// Branch 3 (w == this+0x54): x = this+0x4c; if x != 1: this+0x48 = 0x3fc30549; if x == 0: loc = the four dwords at 0x6b6640; 0x5da670(this, e, &loc);
//   p->vt[+0xac](e, 1500.0f); e->vt[+0x250](). Then this+0x4c = 2.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef void(THISCALL *SlotN)(u8 *self);
typedef void(THISCALL *SlotEF)(u8 *self, u32 e, float f);

extern "C" u32 THISCALL ext_5da470(u8 *self);  // batch 99, original code (hooked in the spec)
extern "C" void THISCALL ext_5da670(u8 *self, u8 *e, u8 *out);  // batch 48, original code (hooked in the spec)

// 0x5da160, thiscall, two stack arguments (GUESS name)
static u32 THISCALL unnamed5da160(u8 *self, u32 a16, u32 b) {
  (void)b;
  u32 e = ext_5da470(self);
  if (e == 0) return 0;
  u16 w = (u16)a16;
  if (w == *(u16 *)(self + 0x50)) {
    u8 *eng = G(u8 *, 0x70039c);
    u8 *p = *(u8 **)(eng + 0x190f);
    ((SlotA)VT(p)[0xb8 / 4])(p, e);
    u8 *eo = (u8 *)(unsigned long)e;
    ((SlotN)VT(eo)[0x254 / 4])(eo);
    *(u32 *)(self + 0x4c) = 0;
    return 0;
  }
  if (w == *(u16 *)(self + 0x52)) {
    u32 x = *(u32 *)(self + 0x4c);
    if (x != 2) {
      *(u32 *)(self + 0x48) = 0;
      if (x == 0) {
        ext_5da670(self, (u8 *)(unsigned long)e, self + 0x66);
        u8 *eng = G(u8 *, 0x70039c);
        u8 *p = *(u8 **)(eng + 0x190f);
        ((SlotEF)VT(p)[0xac / 4])(p, e, 1500.0f);
        u8 *eo = (u8 *)(unsigned long)e;
        ((SlotN)VT(eo)[0x250 / 4])(eo);
      }
    }
    *(u32 *)(self + 0x4c) = 1;
    return 0;
  }
  if (w == *(u16 *)(self + 0x54)) {
    u32 x = *(u32 *)(self + 0x4c);
    if (x != 1) {
      *(u32 *)(self + 0x48) = 0x3fc30549u;
      if (x == 0) {
        u32 loc[4];
        for (int i = 0; i < 4; i++) loc[i] = G(u32, 0x6b6640 + 4 * i);
        ext_5da670(self, (u8 *)(unsigned long)e, (u8 *)loc);
        u8 *eng = G(u8 *, 0x70039c);
        u8 *p = *(u8 **)(eng + 0x190f);
        ((SlotEF)VT(p)[0xac / 4])(p, e, 1500.0f);
        u8 *eo = (u8 *)(unsigned long)e;
        ((SlotN)VT(eo)[0x250 / 4])(eo);
      }
    }
    *(u32 *)(self + 0x4c) = 2;
  }
  return 0;
}
PCREG(5da160, unnamed5da160);
