// batch306.cpp - ZGEOM::ActivateEvents() (area 43, 2026-10-12). 0x45c6a0, thiscall (this = ECX), no stack args, ret 0.
// GC 8015a218 (name map, high). Frame: a 4-byte count at ebp-0xc, written by the vtable calls below.
// Steps: if ZBaseGeom::ChkEvents(this+8) is false, return. E = this+0x10, X = E+8; if X == 0 return.
// cnt via X slot 0x4c; v = X slot 0x5c(&cnt); if cnt == 0 return. Loop while cnt != 0:
//   r = g2 slot 0xcc(v) (g2 at 0x70038c); if r == 0: X' slot 0x44(&cnt), else this slot 0x11c(r, r+8);
//   v = X' slot 0x5c(&cnt) (X' re-read from this+0x10 each time).
// ChkEvents (0x4da3a0) is original exe code (reads this+8 -> +0x54 -> +0x10 -> +8).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" bool FASTCALL ext_4da3a0(u8 *g);   // ZBaseGeom::ChkEvents (ecx = geom)

static void THISCALL geomActivateEvents(u8 *self) {
  if (!ext_4da3a0((u8 *)U32(self, 8)))
    return;
  u8 *E = (u8 *)U32(self, 0x10);
  u8 *X = (u8 *)U32(E, 8);
  if (X == 0)
    return;
  u32 cnt;
  vcall<void>((void *)X, 0x4c, (void *)&cnt);
  E = (u8 *)U32(self, 0x10);
  X = (u8 *)U32(E, 8);
  u32 v = vcall<u32>((void *)X, 0x5c, (void *)&cnt);
  if (cnt == 0)
    return;
  u8 *g2 = (u8 *)G(u32, 0x70038c);
  do {
    u8 *r = (u8 *)vcall<u32>((void *)g2, 0xcc, v);
    if (r == 0) {
      E = (u8 *)U32(self, 0x10);
      X = (u8 *)U32(E, 8);
      vcall<void>((void *)X, 0x44, (void *)&cnt);
    } else {
      vcall<void>((void *)self, 0x11c, (void *)r, U32(r, 8));
    }
    E = (u8 *)U32(self, 0x10);
    X = (u8 *)U32(E, 8);
    v = vcall<u32>((void *)X, 0x5c, (void *)&cnt);
  } while (cnt != 0);
}
PCREG(45c6a0, geomActivateEvents);
