// batch5778.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 78: 0x5c7980 (GUESS name unnamed_5c7980), thiscall, one stack argument a
// (ret 4), no return value. Order: if a+0x2c != 0 return; p = a+0x10; if p: local = 0; p->vt[+0x4c](&local) (fake); h = p->vt[+0x5c](&local)
// (fake; sets local); while local != 0: this+0x44 ->vt[+0x12c](h, word G(0x71434c), 0) (fake, logged); h = p->vt[+0x5c](&local) (fake).
// Finally a+0x2c = 1 (byte). The slot calls run through fake vtables in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotP)(u8 *self, u32 p);
typedef void(THISCALL *Slot3)(u8 *self, u32 a, u32 b, u32 c);

// 0x5c7980, thiscall, one stack argument (GUESS name)
static void THISCALL unnamed5c7980(u8 *self, u8 *a) {
  if (*(u8 *)(a + 0x2c) != 0) return;
  u8 *p = *(u8 **)(a + 0x10);
  if (p) {
    u32 local = 0;
    ((SlotP)VT(p)[0x4c / 4])(p, (u32)(unsigned long)&local);
    u32 h = ((SlotP)VT(p)[0x5c / 4])(p, (u32)(unsigned long)&local);
    if (local) {
      do {
        u8 *obj = *(u8 **)(self + 0x44);
        ((Slot3)VT(obj)[0x12c / 4])(obj, h, G(u16, 0x71434c), 0);
        p = *(u8 **)(a + 0x10);
        h = ((SlotP)VT(p)[0x5c / 4])(p, (u32)(unsigned long)&local);
      } while (local);
    }
  }
  *(u8 *)(a + 0x2c) = 1;
}
PCREG(5c7980, unnamed5c7980);
