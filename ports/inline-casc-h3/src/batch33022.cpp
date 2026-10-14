// batch33022.cpp - h3 batch 33022: conditional field setters
#include "ff.h"

// 0x446eb0, thiscall: read byte from stack arg, store at 0x196, set 0x5c to one of two float constants based on test, ret 4
static void THISCALL fn446eb0(u8 *self, u8 cond) {
  self[0x196] = cond;
  if (cond) {
    *(u32 *)(self + 0x5c) = 0x3fb4f4ab;
  } else {
    *(u32 *)(self + 0x5c) = 0x3f95adef;
  }
}
PCREG(446eb0, fn446eb0);
