// batch1002.cpp - area 81 (residue 0), batch 1002: ZInputActions::RemoveActionMaps(), 0x43a800, thiscall, no args, plain ret (SEH frame not reproduced).
// L = [this+0x1214]; when L: vslot 0x4c(&f); e = vslot 0x5c(&f); while f: vslot 0x44(&f); when e: its vtable word is set to 0x67a7a4; when e+8 is set:
// free(e+8, 1) (0x634273, stood in); helper 0x43a900(e) (GUESS, stood in); when e+0x19 is set: its slot 0 (1); when P = [e+0x11] has [P+0x1334] == e, clear it;
// free(e, 0x23) (0x634273); then e = vslot 0x5c(&f).
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 n);   // CRT free (exe; stood in)
extern "C" void THISCALL ext_43a900(void *e);                       // GUESS (stood in)

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x43a800 ZInputActions::RemoveActionMaps().
static void THISCALL removeActionMaps(u8 *t) {
  u8 *l = (u8 *)D(t, 0x1214);
  if (!l)
    return;
  u32 f = 0;
  vcall<void>(l, 0x4c, (u32)&f);
  u8 *e = (u8 *)vcall<u32>(l, 0x5c, (u32)&f);
  if (!f)
    return;
  do {
    vcall<void>(l, 0x44, (u32)&f);
    if (e) {
      u32 m = D(e, 8);
      D(e, 0) = 0x67a7a4u;
      if (m)
        ext_634273((void *)m, 1);
      ext_43a900(e);
      u32 o = D(e, 0x19);
      if (o)
        vcall<void>((void *)o, 0, 1u);
      u8 *p = (u8 *)D(e, 0x11);
      if (D(p, 0x1334) == (u32)e)
        D(p, 0x1334) = 0;
      ext_634273(e, 0x23);
    }
    e = (u8 *)vcall<u32>(l, 0x5c, (u32)&f);
  } while (f);
}
PCREG(43a800, removeActionMaps);
