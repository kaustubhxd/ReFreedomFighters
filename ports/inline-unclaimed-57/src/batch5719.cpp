// batch5719.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 19: 0x655b40 (GUESS, unnamed), stdcall, one argument n, ret 4.
// esi = n * 4; if esi is 0, return 0. Else o = dword (dword 0x70039c) + 0x190f; r = o->vt[+0x20](); return r->vt[+0x14](esi).
// Both virtual slots are unverified callees, stubbed in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))
#define G(T, addr) (*(T *)(addr))

typedef u32(THISCALL *SlotNone20)(u8 *self);
typedef u32(THISCALL *Slot14)(u8 *self, u32 a);

static u32 STDCALL unnamed655b40(u32 n) {
  u32 esi = n * 4;
  if (esi == 0) return 0;
  u8 *engine = G(u8 *, 0x70039c);
  u8 *o = *(u8 **)(engine + 0x190f);
  u8 *r = (u8 *)(unsigned long)((SlotNone20)VT(o)[0x20 / 4])(o);
  return ((Slot14)VT(r)[0x14 / 4])(r, esi);
}
PCREG(655b40, unnamed655b40);
