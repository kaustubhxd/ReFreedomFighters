// batch6372.cpp - unclaimed-63 batch 72: 0x515790 ZVehicle::CopyDataBlock(DBLK*) (core list name), thiscall, one stack argument s, ret 4.
//   0x512850(this, s) (thiscall, one argument, ret 4; ZMoveOnSpline::CopyDataBlock, other area's code, stubbed). al = 0x4e1600(s) (thiscall,
//   no arguments, returns al). If al == 3: 0x4e14a0(s; this+0x21a, 1) (thiscall, two arguments: the pointer, then 1, ret 8; stubbed).
//   Then 0x4e1b30(s) (thiscall, no arguments, plain ret; stubbed).
#include "ff.h"

extern "C" void THISCALL ext_512850(void *self, u32 s);     // thiscall, one argument, stubbed
extern "C" u8 THISCALL ext_4e1600(void *s);                  // thiscall, no arguments, returns al, stubbed
extern "C" void THISCALL ext_4e14a0(void *s, u32 p, u32 one); // thiscall, two arguments, ret 8, stubbed
extern "C" void THISCALL ext_4e1b30(void *s);                // thiscall, plain ret, stubbed

// 0x515790.
static void THISCALL unnamed515790(u8 *self, u32 s) {
  ext_512850((void *)self, s);
  u8 al = ext_4e1600((void *)s);
  if (al == 3)
    ext_4e14a0((void *)s, (u32)(self + 0x21a), 1u);
  ext_4e1b30((void *)s);
}
PCREG(515790, unnamed515790);
