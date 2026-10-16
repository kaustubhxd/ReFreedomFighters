// batch5795.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 95: 0x5d5b40 (GUESS name unnamed_5d5b40), thiscall, four stack arguments (a, b, c, d;
// ret 0x10; c and d are not read), no return value. The original overwrites a and b in its own frame (the counts and the local below), so the
// port keeps them as locals and writes the same values. Order: if this+0x31: if this+0x2d > 1 { this->vt[+0x110](0x10, 0); p = this+0x25;
// if p: p->vt[+0x2c](); this+0x18 = 1 }; this+0x2d = 0. If lst = this+0x19 != 0: lst->vt[+4](a, b); a = 0x64fc60(lst); m = 0x64fc60(lst);
// if m < this+0x32: x = (engine)+0x9b ->vt[+0x138](); b = 0; x->vt[+0x88](0x6b588c, &b); w = (u16)(engine+0x9b ->vt[+0x114](0x6b587c, 0,
// 0x6b583c, 0x98)); this->vt[+0x12c](b, w). Finally this+0x32 = a. The callees run as hooked stubs in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotN)(u8 *self);
typedef void(THISCALL *Slot2)(u8 *self, u32 a, u32 b);
typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef u32(THISCALL *SlotEng5)(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e);  // five pushes in the original (ret 0x14)

extern "C" u32 THISCALL ext_64fc60(u8 *self);  // count helper, original code (hooked in the spec)

// 0x5d5b40, thiscall, four stack arguments (GUESS name)
static void THISCALL unnamed5d5b40(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  (void)c;
  (void)d;
  if (*(u8 *)(self + 0x31) != 0) {
    if (*(u32 *)(self + 0x2d) > 1) {
      ((Slot2)VT(self)[0x110 / 4])(self, 0x10, 0);
      u8 *p = *(u8 **)(self + 0x25);
      if (p) ((SlotN)VT(p)[0x2c / 4])(p);
      *(u8 *)(self + 0x18) = 1;
    }
    *(u32 *)(self + 0x2d) = 0;
  }
  u8 *lst = *(u8 **)(self + 0x19);
  if (lst) {
    ((Slot2)VT(lst)[0x4 / 4])(lst, a, b);
    a = ext_64fc60(lst);
    u32 m = ext_64fc60(*(u8 **)(self + 0x19));
    if (m < *(u32 *)(self + 0x32)) {
      u8 *eng = G(u8 *, 0x70039c);
      u8 *sub = *(u8 **)(eng + 0x9b);
      u8 *x = (u8 *)(unsigned long)((SlotN)VT(sub)[0x138 / 4])(sub);
      b = 0;
      ((Slot2)VT(x)[0x88 / 4])(x, 0x6b588c, (u32)(unsigned long)&b);
      eng = G(u8 *, 0x70039c);
      sub = *(u8 **)(eng + 0x9b);
      void **selfVt = VT(self);  // the original reads this's vtable pointer before the next call
      u32 w = (u16)((SlotEng5)VT(sub)[0x114 / 4])(sub, 0x6b587c, 0, 0x6b583c, 0x98, 0);
      ((Slot2)selfVt[0x12c / 4])(self, b, w);
    }
    *(u32 *)(self + 0x32) = a;
  }
}
PCREG(5d5b40, unnamed5d5b40);
