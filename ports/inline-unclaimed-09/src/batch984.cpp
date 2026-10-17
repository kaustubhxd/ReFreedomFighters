// batch984.cpp - area 56 band, claim A50 (0x537fd0): a list walk with two virtual calls per node; void.
#include "ff.h"

// A50 0x537fd0: esi = idx; while esi != 0x80000000: v = [this+0x10a7+esi*8], esi = [...+4]; r = obj->vt[0x58](v);
// if r != 0: r->vt[0x128](word [this+0x50a7], arg2, 0).
static void THISCALL walk537fd0(u8 *self, u32 idx, u32 arg2) {
  u32 esi = idx;
  if (esi == 0x80000000u) return;
  do {
    u8 *edx = self + 0x10a7 + esi * 8;
    u32 v = *(u32 *)edx;
    esi = *(u32 *)(edx + 4);
    u8 *g = (u8 *)G(u32, 0x70039c);
    u8 *obj = (u8 *)*(u32 *)(g + 0x9b);
    u32 r = ((u32(THISCALL *)(u8 *, u32))(*(u32 *)(*(u8 **)obj + 0x58)))(obj, v);
    if (r != 0) {
      u32 word = *(u16 *)(self + 0x50a7);
      ((void(THISCALL *)(u8 *, u32, u32, u32))(*(u32 *)(*(u8 **)r + 0x128)))((u8 *)r, word, arg2, 0);
    }
  } while (esi != 0x80000000u);
}
PCREG(537fd0, walk537fd0);
