// batch973.cpp - area 56 band, claim A39 (0x533d60).
#include "ff.h"

extern "C" void ext_634273(u8 *p, u32 n);  // original exe free (cdecl, hooked in the spec)

// A39 0x533d60: vcall slot 0 of [this] with argument 1; free([this+4], 4); free([this+8], 1). Void.
static void THISCALL dtor533d60(u8 *self) {
  u8 *p = *(u8 **)self;
  if (p) ((void(THISCALL *)(u8 *, u32))(*(u32 *)*(u8 **)p))(p, 1);
  u8 *q = *(u8 **)(self + 4);
  if (q) ext_634273(q, 4);
  u8 *r = *(u8 **)(self + 8);
  if (r) ext_634273(r, 1);
}
PCREG(533d60, dtor533d60);
