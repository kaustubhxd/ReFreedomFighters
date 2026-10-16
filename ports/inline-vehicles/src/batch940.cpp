// batch940.cpp - vehicles thread, batch 940: ZHeli::ClassInit() (0x51c140), thiscall, no arguments.
// The base class init (0x512590, batch 935; stood in by the spec) runs first. With a sound manager and a sound set
// (+0x12f): the jet sound (+0x491, pattern 0x69f924) and the second sound (+0x495, pattern 0x69f92c) come from it.
// Then the transform is read (slot 0x80 into +0x6c / +0x60), copied to +0x216 and +0x222, +0x21a cleared, and the
// embedded object at +0x34e gets slot 4 with (+0x216, +0x222).
#include "ff.h"

extern "C" void THISCALL ext_512590(void *self);  // ZMoveOnSpline::ClassInit (stood in by the spec)

static inline u8 *sysp() { return *(u8 **)0x70039c; }

// 0x51c140 ZHeli::ClassInit().
static void THISCALL heliClassInit(u8 *s) {
  ext_512590(s);
  void *sm = *(void **)(sysp() + 0x1a9f);
  if (sm && *(u32 *)(s + 0x12f)) {
    *(u32 *)(s + 0x491) = vcall<u32>(sm, 0x60, *(u32 *)(s + 0x12f), 0x69f924u);
    *(u32 *)(s + 0x495) = vcall<u32>(*(void **)(sysp() + 0x1a9f), 0x60, *(u32 *)(s + 0x12f), 0x69f92cu);
  }
  vcall<void>(s, 0x80, s + 0x6c, s + 0x60);
  u32 *a = (u32 *)(s + 0x216), *b = (u32 *)(s + 0x222);
  a[0] = *(u32 *)(s + 0x6c);
  a[1] = *(u32 *)(s + 0x70);
  a[2] = *(u32 *)(s + 0x74);
  b[0] = a[0];
  b[1] = a[1];
  b[2] = a[2];
  *(u32 *)(s + 0x21a) = 0;
  b[0] = a[0];
  b[1] = a[1];
  b[2] = a[2];
  vcall<void>((void *)(s + 0x34e), 4, (u32)a, (u32)b);
}
PCREG(51c140, heliClassInit);
