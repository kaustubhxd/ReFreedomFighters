// batch986.cpp - area 56 band, claim A52 (0x5348e0): one helper call, two virtual calls, a list walk; void.
#include "ff.h"

extern "C" u32 THISCALL ext_534100(u8 *self, u32 b);  // original exe helper (thiscall, one argument; hooked in the spec, GUESS)

// A52 0x5348e0: idx = ext_534100(this, b); o->vt[0x44](idx); if b is 0 or 0x80000000 return; esi = this + (b+1)*8; walk o->vt[0x3c].
static void THISCALL walk5348e0(u8 *self, u8 *o, u32 b) {
  u32 idx = ext_534100(self, b);
  ((void(THISCALL *)(u8 *, u32))(*(u32 *)(*(u8 **)o + 0x44)))(o, idx);
  if (b == 0 || b == 0x80000000u) return;
  u8 *esi = self + (b + 1) * 8;
  if (esi == 0) return;
  for (;;) {
    ((void(THISCALL *)(u8 *, u32))(*(u32 *)(*(u8 **)o + 0x3c)))(o, *(u32 *)esi);
    u32 n = *(u32 *)(esi + 4);
    if (n == 0 || n == 0x80000000u) return;
    esi = self + 8 + n * 8;
    if (esi == 0) return;
  }
}
PCREG(5348e0, walk5348e0);
