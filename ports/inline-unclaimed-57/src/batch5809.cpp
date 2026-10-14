// batch5809.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 109: 0x5d79f0 (GUESS name unnamed_5d79f0), thiscall, no stack args, plain ret.
// sub = (engine 0x70039c)+0x9b. this+0x1cd = sub->vt[+0x58](this+0x1de); this+0x1d1 = sub->vt[+0x58](this+0x1e2); m = 0x4cc850(ECX = sub->vt[+0xb0](),
// EDX = 0x6b5dd4) (fastcall, another area's function, hooked); this+0x1c3 = (m == 0); s = sub->vt[+0x58](this+0x1d6): this+0x14e = s ? s->+0x18 : 0;
// s2 = sub->vt[+0x58](this+0x1da): this+0x152 = s2 ? s2->+0x18 : 0; this+0x156 = 0; byte [(global 0x7003a0)+0x79] = 0; e4 = sub->vt[+0x138]();
// v = sub->vt[+0x4c](this+0x44, 0x10); e4->vt[+0x60](0x6b588c, v).
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef u32(THISCALL *SlotN)(u8 *self);
typedef u32(THISCALL *Slot2)(u8 *self, u32 a, u32 b);

extern "C" u32 FASTCALL ext_4cc850(u8 *ecx, u8 *edx);  // another area's fastcall, original code (hooked in the spec)

// 0x5d79f0, thiscall, no stack args (GUESS name)
static void THISCALL unnamed5d79f0(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  u32 r1 = ((SlotA)VT(sub)[0x58 / 4])(sub, *(u32 *)(self + 0x1de));
  *(u32 *)(self + 0x1cd) = r1;
  u32 r2 = ((SlotA)VT(sub)[0x58 / 4])(sub, *(u32 *)(self + 0x1e2));
  *(u32 *)(self + 0x1d1) = r2;
  eng = G(u8 *, 0x70039c);
  sub = *(u8 **)(eng + 0x9b);
  u8 *e3 = (u8 *)(unsigned long)((SlotN)VT(sub)[0xb0 / 4])(sub);
  u32 m = ext_4cc850(e3, (u8 *)0x6b5dd4);
  *(u8 *)(self + 0x1c3) = m == 0;
  eng = G(u8 *, 0x70039c);
  sub = *(u8 **)(eng + 0x9b);
  u32 s = ((SlotA)VT(sub)[0x58 / 4])(sub, *(u32 *)(self + 0x1d6));
  if (s != 0) *(u32 *)(self + 0x14e) = *(u32 *)((u8 *)(unsigned long)s + 0x18);
  else *(u32 *)(self + 0x14e) = 0;
  eng = G(u8 *, 0x70039c);
  sub = *(u8 **)(eng + 0x9b);
  u32 s2 = ((SlotA)VT(sub)[0x58 / 4])(sub, *(u32 *)(self + 0x1da));
  if (s2 != 0) *(u32 *)(self + 0x152) = *(u32 *)((u8 *)(unsigned long)s2 + 0x18);
  else *(u32 *)(self + 0x152) = 0;
  *(u32 *)(self + 0x156) = 0;
  u8 *gp = G(u8 *, 0x7003a0);
  *(u8 *)(gp + 0x79) = 0;
  eng = G(u8 *, 0x70039c);
  sub = *(u8 **)(eng + 0x9b);
  u8 *e4 = (u8 *)(unsigned long)((SlotN)VT(sub)[0x138 / 4])(sub);
  void **e4Vt = VT(e4);
  eng = G(u8 *, 0x70039c);
  sub = *(u8 **)(eng + 0x9b);
  u32 v = ((Slot2)VT(sub)[0x4c / 4])(sub, *(u32 *)(self + 0x44), 0x10);
  ((Slot2)e4Vt[0x60 / 4])(e4, 0x6b588c, v);
}
PCREG(5d79f0, unnamed5d79f0);
