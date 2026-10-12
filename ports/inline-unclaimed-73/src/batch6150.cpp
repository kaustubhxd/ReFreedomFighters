// batch6150.cpp - area 73 batch 61 (gap band, GUESS name): FUN_4e80c0.
#include "ff.h"

extern "C" u32 THISCALL ext_4e8000(u8 *self, u32 r);

// 0x4e80c0 (GUESS FUN_4e80c0): ret 4. r = vtable slot +8 on this with (arg, 0). When r is non-null, t = 0x4e8000(this, r),
// then vtable slot +0x20 on the object at this+0x1d is called with t.
static void THISCALL guess4e80c0(u8 *self, u32 arg) {
  u32 r = vcall<u32>(self, 0x08, arg, 0u);
  if (!r)
    return;
  u8 *obj = *(u8 **)(self + 0x1d);
  u32 t = ext_4e8000(self, r);
  vcall<void>(obj, 0x20, t);
}
PCREG(4e80c0, guess4e80c0);
