// batch780.cpp - gap band batch 780 (docs/20-gap-band-401000.md): 0x41ee90, thiscall (this, v), returns the hash value.
#include "ff.h"

typedef u32(THISCALL *F0)(u8 *self);
typedef u32(THISCALL *F3)(u8 *self, u32 a, u32 b, u32 c);
static u32 vc0(u8 *o, u32 s) { return ((F0)(*(const u32 *)(*(const u32 *)o + s)))(o); }
static u32 vc3(u8 *o, u32 s, u32 a, u32 b, u32 c) { return ((F3)(*(const u32 *)(*(const u32 *)o + s)))(o, a, b, c); }

static u32 THISCALL fn41ee90(u8 *self, u32 v) {
  u8 *X = *(u8 **)(self + 4);
  const u32 h = vc0(X, 4);
  const u32 idx = *(const u32 *)(*(u8 **)(self + 4) + 0x10) & h;
  u32 *arr = *(u32 **)(self + 0x28);
  arr[idx] = v;
  u8 *G = G(u8 *, 0x70038c);
  if (G != nullptr) {
    const u32 idx2 = *(const u32 *)(*(u8 **)(self + 4) + 0x10) & h;
    vc3(G, 0x2c, 0x677334, idx2 * 4, 4);
  }
  return h;
}

PCREG(41ee90, fn41ee90);
