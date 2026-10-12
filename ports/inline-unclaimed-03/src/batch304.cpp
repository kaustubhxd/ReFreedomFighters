// batch304.cpp - unclaimed-03 batch 4 (docs/20-unclaimed-03.md): ZMatPosAnim::RunOffscreen and
// ZMovementBaseMove::GetActiveWalkDefsList. Names are from the GC name map (naming only, GUESS where medium or low);
// bodies are from the PC bytes.
#include "ff.h"

// 0x4a5da0, ZMatPosAnim::RunOffscreen(bool) (high): if the argument byte is nonzero, calls vtable slot +0x64 on this
// with one stack argument 0x10 (thiscall, callee pops 4); then stores the byte at this+0x92. Callee pops 4.
static void THISCALL matPosRunOffscreen(u8 *self, u32 a1) {
  u8 b = (u8)a1;
  if (b) {
    typedef void(THISCALL * slot_fn)(u8 *, u32);
    slot_fn f = *(slot_fn *)(*(u32 *)self + 0x64);
    f(self, 0x10);
  }
  self[0x92] = b;
}
PCREG(4a5da0, matPosRunOffscreen);

// 0x488b60, ZMovementBaseMove::GetActiveWalkDefsList() (high): owner = this+4. Calls the owner's vtable slot +0x534
// (no arguments, returns al). Returns this+0x25; if al is 0 and the owner's flags dword at +0x417 has 0x400, returns
// this+0x3d instead. Then, if the same owner dword has 0x800 set, returns this+0x55 (cmove on a clear test result
// keeps the earlier pick). Plain ret, no stack effect.
static u8 *THISCALL moveBaseGetActiveWalkDefsList(u8 *self) {
  u8 *owner = *(u8 **)(self + 4);
  typedef u8(THISCALL * slot_fn)(u8 *);
  slot_fn f = *(slot_fn *)(*(u32 *)owner + 0x534);
  u8 *pick = self + 0x25;
  if (!f(owner)) {
    if (*(u32 *)(owner + 0x417) & 0x400)
      pick = self + 0x3d;
  }
  if (*(u32 *)(owner + 0x417) & 0x800)
    return self + 0x55;
  return pick;
}
PCREG(488b60, moveBaseGetActiveWalkDefsList);
