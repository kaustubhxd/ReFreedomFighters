// batch35023.cpp - cascade s5 batch 35023: 0x468f20 (GUESS load eight dwords from a stream).
#include "ff.h"

typedef void(THISCALL *v2_t)(void *, void *, u32);

// 0x468f20, thiscall(s) ret 4, returns true. s slot 0x10(dest, 4) reads four bytes into this+0x4, +0x8, +0x14, +0x18, +0xc, +0x10, +0x1c, +0x38 (in that order).
static u8 THISCALL fn468f20(u8 *self, u8 *s) {
  static const u8 offs[8] = {0x4, 0x8, 0x14, 0x18, 0xc, 0x10, 0x1c, 0x38};
  for (int i = 0; i < 8; i++) (*(v2_t **)s)[0x10 / 4](s, self + offs[i], 4);
  return 1;
}
PCREG(468f20, fn468f20);
