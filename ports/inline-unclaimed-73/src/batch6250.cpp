// batch6250.cpp - area 73 batch 62 (gap band, GUESS name): FUN_4f6680.
#include "ff.h"

extern "C" u8 THISCALL ext_4f0d70(u8 *self, u8 *a);

// 0x4f6680 (GUESS FUN_4f6680): ret 4, returns a bool. ok = 0x4f0d70(this, a). When ok is 0 the result is 0; otherwise vtable
// slot +0x3c is called on a with the dword at this+0x93, and the result is 1.
static u8 THISCALL guess4f6680(u8 *self, u8 *a) {
  u8 ok = ext_4f0d70(self, a);
  if (!ok)
    return 0;
  vcall<void>(a, 0x3c, *(u32 *)(self + 0x93));
  return 1;
}
PCREG(4f6680, guess4f6680);
