// batch5822.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 122: 0x5db420 (ZDamageBox::Load(ZLoadGame*)), thiscall, one stack argument L (ret 4), returns al = 1.
// this+4 &= ~0x40; L->vt[+0x40](&l1); this+0x48 = (engine+0x9b)->vt[+0x58](l1); L->vt[+0x50](this+0x4c); L->vt[+0x50](this+0x50); L->vt[+0x40](&slot)
// where slot is the argument's own slot (the callee writes the count into it); for i < slot: r = 0x41e290(13) (cdecl, hooked); L->vt[+0x50](r+9);
// L->vt[+0x40](r); o = (engine+0x9b)->vt[+0x58](r->dword); r+4 = o; r+8 = (o->vt[+0x1e0](0x2003e8) != 0); (this+0x84)->vt[+4](r).
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef u32(THISCALL *SlotN)(u8 *self);

extern "C" void *ext_41e290(u32 size);  // operator new (cdecl), original code (hooked in the spec)

// 0x5db420, thiscall, one stack argument (GUESS name)
static u8 THISCALL unnamed5db420(u8 *self, u8 *L) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  u32 l1 = 0;
  ((SlotA)VT(L)[0x40 / 4])(L, (u32)(unsigned long)&l1);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  *(u32 *)(self + 0x48) = ((SlotA)VT(sub)[0x58 / 4])(sub, l1);
  ((SlotA)VT(L)[0x50 / 4])(L, (u32)(unsigned long)(self + 0x4c));
  ((SlotA)VT(L)[0x50 / 4])(L, (u32)(unsigned long)(self + 0x50));
  u32 slot = (u32)(unsigned long)L;  // the argument's own slot: the callee writes the count into it
  ((SlotA)VT(L)[0x40 / 4])(L, (u32)(unsigned long)&slot);
  for (u32 i = 0; i < slot; i++) {
    u8 *r = (u8 *)ext_41e290(0xd);
    ((SlotA)VT(L)[0x50 / 4])(L, (u32)(unsigned long)(r + 9));
    ((SlotA)VT(L)[0x40 / 4])(L, (u32)(unsigned long)r);
    eng = G(u8 *, 0x70039c);
    sub = *(u8 **)(eng + 0x9b);
    u8 *o = (u8 *)(unsigned long)((SlotA)VT(sub)[0x58 / 4])(sub, *(u32 *)r);
    *(u32 *)(r + 4) = (u32)(unsigned long)o;
    u32 f = ((SlotA)VT(o)[0x1e0 / 4])(o, 0x2003e8);
    *(u8 *)(r + 8) = (u8)(f != 0);
    u8 *m = *(u8 **)(self + 0x84);
    ((SlotA)VT(m)[4 / 4])(m, (u32)(unsigned long)r);
  }
  return 1;
}
PCREG(5db420, unnamed5db420);
