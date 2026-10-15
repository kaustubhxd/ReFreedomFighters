// batch968.cpp - residue-05 (core todo), batch 968: ZWindControl::FrameUpdate(), 0x4c3510, thiscall, no args, void.
// Timer: [+0x4c] += frame time (sys+0x48); when it exceeds [+0x50]: [+0x54] = [+0x5c], [+0x5c] = sys vslot 0x1c0(0x693ec0, 0xd4)
// (float), [+0x4c] = 0. Then [+0x58] = [+0x54] + ([+0x5c] - [+0x54]) * ([+0x4c] / [+0x50]). If [+0x48] is set, its list is
// walked with vslot 0x4c(&loc) and vslot 0x5c(&loc) (loc = more); for each entry, X = render manager vslot 0x58(entry),
// Y = X+8, and when Y's dword at +0x3c has 0x1000 the helper 0x4c3740 (exe, stood in) runs with (Y).
#include "ff.h"

extern "C" void THISCALL ext_4c3740(void *self, u32 y);   // stood in by the checker

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F(p, o) (*(float *)((u8 *)(p) + (o)))

// 0x4c3510 ZWindControl::FrameUpdate().
static void THISCALL windFrameUpdate(u8 *t) {
  u8 *sys = *(u8 **)0x70039c;
  F(t, 0x4c) = F(sys, 0x48) + F(t, 0x4c);
  if (F(t, 0x4c) > F(t, 0x50)) {
    D(t, 0x54) = D(t, 0x5c);
    F(t, 0x5c) = vcall<float>(sys, 0x1c0, 0x693ec0u, 0xd4u);
    F(t, 0x4c) = 0.0f;
  }
  float ratio = F(t, 0x4c) / F(t, 0x50);
  F(t, 0x58) = (F(t, 0x5c) - F(t, 0x54)) * ratio + F(t, 0x54);
  u8 *obj = (u8 *)D(t, 0x48);
  if (obj) {
    u32 loc = 0;
    vcall<void>(obj, 0x4c, (u32)&loc);
    u32 entry = vcall<u32>(obj, 0x5c, (u32)&loc);
    while (loc) {
      void *rm = *(void **)(*(u8 **)0x70039c + 0x9b);
      u8 *x = (u8 *)vcall<u32>(rm, 0x58, entry);
      u8 *y = (u8 *)D(x, 8);
      if (D(y, 0x3c) & 0x1000)
        ext_4c3740(t, (u32)y);
      entry = vcall<u32>(obj, 0x5c, (u32)&loc);
    }
  }
}
PCREG(4c3510, windFrameUpdate);
