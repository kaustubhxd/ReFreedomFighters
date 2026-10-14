// batch966.cpp - residue-05 (core todo), batch 966: CActionController::Init(), 0x4a1190, thiscall, no args.
// X = render manager vslot 0x138(); X vslot 0x60(0x68f75c, render manager vslot 0x4c(this+0x44, 4)); two message ids from
// the render manager vslot 0x114 (name 0x68f774 line 0x220, name 0x68f788 line 0x221) go to the word fields +0x8b0 and
// +0x8b2; then nine dwords are cleared (+0x48, +0x4c, +0x50, +0x54, +0x58, +0x5c, +0x60, +0x64, +0x68).
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x4a1190 CActionController::Init().
static void THISCALL actionCtrlInit(u8 *t) {
  void *rm = *(void **)(*(u8 **)0x70039c + 0x9b);
  void *x = (void *)vcall<u32>(rm, 0x138);
  u32 v = vcall<u32>(rm, 0x4c, D(t, 0x44), 4u);
  vcall<void>(x, 0x60, 0x68f75cu, v);
  *(u16 *)(t + 0x8b0) = vcall<u16>(rm, 0x114, 0x68f774u, 0u, 0x68f6b4u, 0x220u);
  *(u16 *)(t + 0x8b2) = vcall<u16>(rm, 0x114, 0x68f788u, 0u, 0x68f6b4u, 0x221u);
  D(t, 0x5c) = 0;
  D(t, 0x4c) = 0;
  D(t, 0x60) = 0;
  D(t, 0x50) = 0;
  D(t, 0x64) = 0;
  D(t, 0x54) = 0;
  D(t, 0x68) = 0;
  D(t, 0x58) = 0;
  D(t, 0x48) = 0;
}
PCREG(4a1190, actionCtrlInit);
