// batch6960.cpp - area 73 batch 69 (gap band, GUESS names): FUN_4f76f0 and FUN_4f75e0.
#include "ff.h"

// 0x4f76f0 (GUESS FUN_4f76f0): ret 4. Stores (float)arg at this+0x9b. A non-zero dword at this+0x93 gives vtable slot +0x36c(that
// dword); vtable slot +0x370 is then called.
static void THISCALL guess4f76f0(u8 *self, u32 arg) {
  *(float *)(self + 0x9b) = (float)(int)arg;
  u32 f = *(u32 *)(self + 0x93);
  if (f)
    vcall<void>(self, 0x36c, f);
  vcall<void>(self, 0x370);
}
PCREG(4f76f0, guess4f76f0);

// 0x4f75e0 (GUESS FUN_4f75e0): ret 4. Same as FUN_4f76f0, but the float goes to this+0x9f.
static void THISCALL guess4f75e0(u8 *self, u32 arg) {
  *(float *)(self + 0x9f) = (float)(int)arg;
  u32 f = *(u32 *)(self + 0x93);
  if (f)
    vcall<void>(self, 0x36c, f);
  vcall<void>(self, 0x370);
}
PCREG(4f75e0, guess4f75e0);
