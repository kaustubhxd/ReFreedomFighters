// batch959.cpp - residue-04 (core todo), batch 959: 0x5124d0 (ZMoveOnSpline body after its class init, thiscall, no args)
// and its jmp thunk 0x513500 (tail to 0x5124d0). Order: vslot 0x110(0x10, 0); vslot 0x2c8([this+0xce], 0); 0x513d10 (exe,
// stood in); when [this+0x134] is set: vslot 0x28, the vector 0x4de7a0 (exe) on loc34, vslot 0x1bc on that object with
// (render manager +0xadc, &loc34, &loc10 (zero), 0, 0, 0, 1) and the result stored at [this+0x134] with vslot 0x28; then
// vslot 0x2e4 on this. The thunk just calls the body.
#include "ff.h"

extern "C" void THISCALL ext_513d10(void *self);      // exe (stood in by the checker)
extern "C" void THISCALL ext_4de7a0(void *self);      // exe, vector init (thiscall, no args)

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x5124d0 body.
static void THISCALL zmosBody(u8 *t) {
  vcall<void>(t, 0x110, 0x10u, 0u);
  vcall<void>(t, 0x2c8, D(t, 0xce), 0u);
  ext_513d10(t);
  void *o = (void *)D(t, 0x134);
  if (o) {
    vcall<void>(o, 0x28);
    u32 loc34[9];   // the exe frame gives the vector 0x24 bytes below loc10
    u32 loc10[3] = {0, 0, 0};
    ext_4de7a0(loc34);
    u8 *rm = *(u8 **)(*(u8 **)0x70039c + 0x9b);
    void *n = (void *)vcall<u32>(o, 0x1bc, D(rm, 0xadc), (u32)loc34, (u32)loc10, 0u, 0u, 0u, 1u);
    D(t, 0x134) = (u32)n;
    vcall<void>(n, 0x28);
  }
  vcall<void>(t, 0x2e4);
}
PCREG(5124d0, zmosBody);

// 0x513500 jmp 0x5124d0.
static void THISCALL zmosThunk(u8 *t) {
  zmosBody(t);
}
PCREG(513500, zmosThunk);
