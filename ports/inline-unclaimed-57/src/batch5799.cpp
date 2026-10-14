// batch5799.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 99: 0x5da470 (GUESS name unnamed_5da470), thiscall, no stack args, returns eax.
// Order: r1 = (engine 0x70039c)+0x9b ->vt[+0x58](this+0x56); if r1 == 0 return 0; if this+0x5e == 0 return r1; nm = r1+4 (a string) or the
// default string 0x67c8e8; p = (engine)+0x190f; q = p->vt[+0x98](); cnt = q->vt[+0x14](); for i = 0; i < cnt: t = q->vt[+0x30](i);
// u = sub->vt[+0x58](t); s2 = u+4 or the default; if _stricmp(s2, nm) == 0 return u; cnt = q->vt[+0x14](). Return 0 at the end.
// The string compare is the CRT import at 0x676414 (_stricmp, cdecl), called through the IAT as the original does.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef u32(THISCALL *SlotN)(u8 *self);

typedef s32 (*StricmpFn)(const char *a, const char *b);

// 0x5da470, thiscall, no stack args (GUESS name)
static u32 THISCALL unnamed5da470(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  u32 r1 = ((SlotA)VT(sub)[0x58 / 4])(sub, *(u32 *)(self + 0x56));
  if (r1 == 0) return 0;
  if (*(u32 *)(self + 0x5e) == 0) return r1;
  u32 sr = *(u32 *)(r1 + 4);
  u32 nm = sr ? sr : 0x67c8e8u;
  eng = G(u8 *, 0x70039c);
  u8 *p = *(u8 **)(eng + 0x190f);
  u8 *q = (u8 *)(unsigned long)((SlotN)VT(p)[0x98 / 4])(p);
  s32 cnt = (s32)((SlotN)VT(q)[0x14 / 4])(q);
  u32 i = 0;
  if (cnt > 0) {
    do {
      eng = G(u8 *, 0x70039c);
      sub = *(u8 **)(eng + 0x9b);
      void **subVt = VT(sub);
      u32 t = ((SlotA)VT(q)[0x30 / 4])(q, i);
      eng = G(u8 *, 0x70039c);
      u32 u = ((SlotA)subVt[0x58 / 4])(*(u8 **)(eng + 0x9b), t);
      u32 us = *(u32 *)((u8 *)(unsigned long)u + 4);
      u32 s2 = us ? us : 0x67c8e8u;
      s32 c = ((StricmpFn)(unsigned long)G(u32, 0x676414))((const char *)(unsigned long)s2, (const char *)(unsigned long)nm);
      if (c == 0) return u;
      i++;
      cnt = (s32)((SlotN)VT(q)[0x14 / 4])(q);
    } while ((s32)i < cnt);
  }
  return 0;
}
PCREG(5da470, unnamed5da470);
