// batch2605.cpp - wider batch 2605. 0x53a9e0 (GUESS), thiscall, no args, plain ret. p = slot 4 of the object at *this, called with (0) (thiscall, callee pops 4);
// dst = p - 4 + 0x20; when dst != system+0x40 (system = [0x70039c]) the dword at system+0x40 is stored into *dst.
#include "ff.h"

typedef u8 *(THISCALL *vs4_t)(void *, u32);

static void THISCALL guess53a9e0(u8 *self) {
  void *obj = *(void **)self;
  u8 *p = (*(vs4_t **)obj)[1](obj, 0);
  u8 *sys = *(u8 **)0x70039c;
  u32 *src = (u32 *)(sys + 0x40);
  u32 *dst = (u32 *)(p - 4 + 0x20);
  if (dst != src) *dst = *src;
}
PCREG(53a9e0, guess53a9e0);
