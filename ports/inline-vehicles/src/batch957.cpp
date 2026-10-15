// batch957.cpp - residue-03 (core todo), batch 957: CAction::AddAction(ZGEOM*, const char*, const char*, EActionType, ...),
// 0x49f9b0, this in ECX, arg1 in EDX, six stack args (ret 0x18). Looks the action up (vslot 0x100 with 0x6889cc, else
// vslot 0x10c); calls vslot 0x5c(1, this, 0) on it; asks the global manager (0x70038c) slot 0x20 and, if that is zero,
// finds the entry through the manager's callback (+8, when the id is in its range [+0xc, +0x10)) or through slot 0xac;
// then vslot 0xb0 with the eight arguments, vslot 0x5c(2, 0, 0), and the manager's slot 0xcc with the entry.
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x49f9b0 CAction::AddAction.
static void FASTCALL actionAdd(u8 *t, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
  u8 *esi = (u8 *)vcall<u32>(t, 0x100, 0x6889ccu);
  if (!esi) {
    esi = (u8 *)vcall<u32>(t, 0x10c, 0x6889ccu, 0u);
    if (!esi)
      return;
  }
  vcall<void>(esi, 0x5c, 1u, (u32)t, 0u);
  u8 *g = *(u8 **)0x70038c;
  u32 e;
  if (vcall<u32>(g, 0x20, (u32)esi)) {
    e = 0;
  } else {
    u32 fn = D(g, 8);
    if (fn && !(D(g, 0xc) > (u32)esi) && !((u32)esi >= D(g, 0x10))) {
      e = ((u32(THISCALL *)(void *))fn)(esi);
    } else {
      if (D(esi, -4) == 0)
        vcall<void>(g, 0xac, (u32)esi);
      e = D(esi, -4);
    }
  }
  vcall<void>(esi, 0xb0, a0, a1, a2, a3, a4, a5, 0u, a6);
  vcall<void>(esi, 0x5c, 2u, 0u, 0u);
  vcall<void>(g, 0xcc, e);
}
PCREG(49f9b0, actionAdd);
