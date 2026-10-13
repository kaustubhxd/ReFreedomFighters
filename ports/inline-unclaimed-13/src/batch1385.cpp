#include "ff.h"
// batch1385.cpp - unclaimed-13 claim 4 (docs/20-unclaimed-13.md). Name from the GC name map (high).

// 0x4a9cb0 is not lifted here: original code, bound by build.sh as ext_4a9cb0. Thiscall with the object in ecx and two
// stack arguments: the second parameter (eax on entry, the value at this+0x140) is pushed last, the first (the
// argument) first. Left as original code, so the port calls the same callee the exe does (stub-free).
extern "C" u8 THISCALL ext_4a9cb0(u8 *obj, u32 index, u32 arg);

// 0x5122c0, ZMoveOnSpline::CanSee(unsigned int) (high): if the dword at this+0x140 is -1, returns false (al = 0).
// Otherwise returns the result of 0x4a9cb0 called with ecx = the pointer at this+0x13c, eax = the index, and the
// argument. Result in al.
static u8 THISCALL moveOnSplineCanSee(u8 *self, u32 a1) {
  u32 index = *(u32 *)(self + 0x140);
  if (index == 0xffffffffu) return 0;
  return ext_4a9cb0(*(u8 **)(self + 0x13c), index, a1);
}
PCREG(5122c0, moveOnSplineCanSee);
