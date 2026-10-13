// batch632.cpp - band 0x421000-0x441000, batch 632: two functions.
//   0x422b00 (thiscall, one byte flag; ret 4): slot 4 of [0x700394]; if byte [this+0x60] is 0: slot 0x78 of [0x70038c]; then if
//     the flag is 0: o = [[0x70039c]+0x1a9f]; if o: slot 0x38 of o. The value left in eax is incidental (void).
//   0x43d310 (thiscall, no args; float in st0): a = byte [this+0x1c] ? ((f[0]+f[4])+f[8])+f[0xc] : 0; b = byte [this+0x39] ?
//     ((f[0x21]+f[0x1d])+f[0x25])+f[0x29] : 0 (unaligned floats); returns maxss(a, b) = a > b ? a : b (b when unordered or equal).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vNone)(void *self);

static void THISCALL pumpAndRefresh(u8 *self, u32 flag) {
  u8 *a = G(u8 *, 0x700394);
  ((vNone)VT(a, 4))(a);
  if (self[0x60] != 0)
    return;
  u8 *b = G(u8 *, 0x70038c);
  ((vNone)VT(b, 0x78))(b);
  if ((u8)flag != 0)
    return;
  u8 *o = *(u8 **)(G(u8 *, 0x70039c) + 0x1a9f);
  if (o)
    ((vNone)VT(o, 0x38))(o);
}
PCREG(422b00, pumpAndRefresh);

static inline float F32(const u8 *p) { return *(const float *)p; }

static float THISCALL maxOfSums(u8 *self) {
  float a = 0.0f, b = 0.0f;
  if (self[0x1c] != 0)
    a = ((F32(self + 4) + F32(self)) + F32(self + 8)) + F32(self + 0xc);
  if (self[0x39] != 0)
    b = ((F32(self + 0x21) + F32(self + 0x1d)) + F32(self + 0x25)) + F32(self + 0x29);
  return a > b ? a : b;
}
PCREG(43d310, maxOfSums);
