#include "ff.h"
// batch919.cpp - unclaimed-01 claim 18 (docs/20-unclaimed-01.md). ZMoveOnSpline::~ZMoveOnSpline() (0x5120c0, high).
// Original code called here (ext_): the deletes 0x634273 (cdecl, pointer and size), 0x4690b0 (cdecl, pointer and size),
// 0x45c510 (cdecl, pointer) and the base destructor 0x43ea20 (thiscall). The spec stubs them (logging for the deletes).

extern "C" void ext_634273(void *p, u32 n);
extern "C" void ext_4690b0(void *p, u32 n);
extern "C" void ext_45c510(void *p);
extern "C" void THISCALL ext_43ea20(u8 *self);

static u32 THISCALL moveOnSplineDtor(u8 *self, u32 flag) {
  *(u32 *)self = 0x69e15cu;
  ext_634273(*(void **)(self + 0x5c), 0x67u);
  typedef void(THISCALL * vdtor_fn)(u8 *, u32);
  u8 *o = *(u8 **)(self + 0x127);
  if (o != 0)
    ((vdtor_fn)(*(u32 *)(*(u32 *)o + 0)))(o, 1u);
  o = *(u8 **)(self + 0x12b);
  if (o != 0)
    ((vdtor_fn)(*(u32 *)(*(u32 *)o + 0)))(o, 1u);
  o = *(u8 **)(self + 0x1ed);
  if (o != 0)
    ((vdtor_fn)(*(u32 *)(*(u32 *)o + 0)))(o, 1u);
  ext_43ea20(self);
  if ((flag & 1) != 0) {
    if ((flag & 4) != 0)
      ext_4690b0(self, 0x216u);
    else
      ext_45c510(self);
  }
  return (u32)self;
}
PCREG(5120c0, moveOnSplineDtor);
