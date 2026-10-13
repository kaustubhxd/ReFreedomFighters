// batch3007.cpp - unclaimed-30: batch 7 (docs/20-unclaimed-30.md, claim 1). CPullToValueAccel::Save(ZSaveGame*) [map 0x527190;
// thiscall, ret 4, returns true]. The save object's slot +0x4c takes a float (this+4, +8, +0xc, +0x10, +0x14, then +0x1d, +0x21,
// +0x25); slot +0x60 takes the byte at +0x18; slot +0x10 takes the four bytes at +0x19 and the count 4.
#include "ff.h"

static bool THISCALL pullToValueSave(u8 *self, u8 *save) {
  vcall<void>(save, 0x4c, *(const float *)(self + 4));
  vcall<void>(save, 0x4c, *(const float *)(self + 8));
  vcall<void>(save, 0x4c, *(const float *)(self + 0xc));
  vcall<void>(save, 0x4c, *(const float *)(self + 0x10));
  vcall<void>(save, 0x4c, *(const float *)(self + 0x14));
  vcall<void>(save, 0x60, (u32)self[0x18]);
  vcall<void>(save, 0x10, (const void *)(self + 0x19), (u32)4);
  vcall<void>(save, 0x4c, *(const float *)(self + 0x1d));
  vcall<void>(save, 0x4c, *(const float *)(self + 0x21));
  vcall<void>(save, 0x4c, *(const float *)(self + 0x25));
  return true;
}
PCREG(527190, pullToValueSave);
