// batch1609.cpp - unclaimed-16 batch 9 (docs/20-unclaimed-16.md): ZInputActions::CheckAction(ZInputAction*, void*)
// (high). The second argument is only a default (the exe writes the return address into it when it is zero) and is
// never read, so the port ignores it. The callee 0x437d60 takes the action in ecx and no stack arguments; it is original
// code called through ext_437d60 (stubbed in the spec, not verified).
#include "ff.h"

extern "C" u8 THISCALL ext_437d60(u8 *action); // original code (stubbed in the spec)

// 0x437f70: returns 0 if the action is null or the dword at this+0x120c is nonzero; otherwise returns the low byte
// returned by 0x437d60(action).
static u32 THISCALL inputCheckActionObj(u8 *self, u32 a1, u32 a2) {
  (void)a2;
  if (a1 == 0)
    return 0;
  if (*(u32 *)(self + 0x120c) != 0)
    return 0;
  return ext_437d60((u8 *)a1);
}
PCREG(437f70, inputCheckActionObj);
