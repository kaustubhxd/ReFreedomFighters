// batch33024.cpp - h3 batch 33024: bounded array access
#include "ff.h"

// 0x4db580, thiscall: get byte at 0x1c as bound, read arg from stack, if arg < bound return this[arg*4] else 0, ret 4
static u32 THISCALL fn4db580(u8 *self, u32 idx) {
  u8 bound = self[0x1c];
  if (idx < bound) {
    return *(u32 *)(self + idx * 4);
  } else {
    return 0;
  }
}
PCREG(4db580, fn4db580);
