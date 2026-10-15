// batch969.cpp - residue-05 (core todo), batch 969: ZFFSimpleTrain2::PositionAllTrains(float*), 0x5b9050, thiscall, ret 4.
// Walks the list at [this+0x4c] (vslots 0x4c and 0x5c with a 'more' flag). For each entry X = render manager vslot 0x58(entry):
// X vslot 0x78(out); 0x4db7c0 (this = X+8, stood in) fills a 3-float vector v; the fastcall 0x451890 (ECX = out, EDX = this+0xa2,
// one float stack arg = v[2] * constant at 0x692b60; stood in) runs.
#include "ff.h"

extern "C" void THISCALL ext_4db7c0(void *self, float *v);                          // stood in by the checker
extern "C" void __attribute__((fastcall)) ext_451890(void *out, void *a, float d);  // stood in by the checker

// 0x5b9050 ZFFSimpleTrain2::PositionAllTrains(float*).
static void THISCALL trainsPosition(u8 *t, float *out) {
  u8 *list = *(u8 **)(t + 0x4c);
  if (!list)
    return;
  u32 loc = 0;
  vcall<void>(list, 0x4c, (u32)&loc);
  u32 entry = vcall<u32>(list, 0x5c, (u32)&loc);
  while (loc) {
    void *rm = *(void **)(*(u8 **)0x70039c + 0x9b);
    u8 *x = (u8 *)vcall<u32>(rm, 0x58, entry);
    vcall<void>(x, 0x78, (u32)out);
    u8 *y = *(u8 **)(x + 8);
    float v[3];
    ext_4db7c0(y, v);
    float d = v[2] * *(float *)0x692b60;
    ext_451890(out, t + 0xa2, d);
    entry = vcall<u32>(list, 0x5c, (u32)&loc);
  }
}
PCREG(5b9050, trainsPosition);
