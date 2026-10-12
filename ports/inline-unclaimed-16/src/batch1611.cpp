// batch1611.cpp - unclaimed-16 batch 11 (docs/20-unclaimed-16.md): ZInputActions::DeActivateMap(const char*) (medium).
// obj = slot 0x58 of this (called with the name). If obj is 0, returns 0. Otherwise: if obj+0x29 is not the stack slot
// the exe uses for its local, the dword at obj+0x29 is set to 0; then the byte at obj+0x2e is ANDed with 0x2f and the
// byte at obj+0x2f with 1; returns obj.
#include "ff.h"

typedef u32(THISCALL *FnR1)(void *, u32);

static u32 THISCALL inputDeActivateMap(u8 *self, u32 a1) {
  u32 *vt = *(u32 **)self;
  u8 *obj = (u8 *)(u32)((FnR1)vt[0x58 / 4])(self, a1);
  if (obj == 0)
    return 0;
  volatile u32 local = 0;
  if ((u32)(obj + 0x29) != (u32)&local)
    *(u32 *)(obj + 0x29) = 0;
  obj[0x2e] &= 0x2f;
  obj[0x2f] &= 1;
  return (u32)obj;
}
PCREG(43abe0, inputDeActivateMap);
