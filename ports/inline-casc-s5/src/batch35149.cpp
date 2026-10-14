// batch35149.cpp - cascade s5 batch 35149: 0x49d220 (GUESS pool constructor: two arrays of a and b dwords).
#include "ff.h"

extern "C" u8 *ext_41e290(u32 n);   // cdecl alloc
typedef void(THISCALL *l2_t)(void *, u32, u32);

static u32 sat4(u32 n) { return n > 0x3fffffffu ? 0xffffffffu : n * 4; }

// 0x49d220, thiscall(a, b, c) ret 0xc, returns this. [0] = 0x68ee80, [0x24] = c, [0x1c] = a, [0x20] = b; [4] = alloc(a * 4), [8] = alloc(b * 4) (sizes saturate to 0xffffffff on overflow);
// [0x10] = [0x14] = [0x18] = 0, byte [0x28] = 0; when the logger at 0x70038c exists its slot 0x24(0x68ee90, a * 4 (wrapping)).
static u8 *THISCALL fn49d220(u8 *self, u32 a, u32 b, u32 c) {
  *(u32 *)(self + 0x24) = c;
  *(u32 *)self = 0x68ee80;
  *(u32 *)(self + 0x1c) = a;
  *(u32 *)(self + 0x20) = b;
  *(u8 **)(self + 4) = ext_41e290(sat4(a));
  *(u8 **)(self + 8) = ext_41e290(sat4(b));
  *(u32 *)(self + 0x10) = 0;
  *(u32 *)(self + 0x14) = 0;
  *(u32 *)(self + 0x18) = 0;
  self[0x28] = 0;
  u8 *lg = G(u8 *, 0x70038c);
  if (lg) (*(l2_t **)lg)[0x24 / 4](lg, 0x68ee90, a * 4);
  return self;
}
PCREG(49d220, fn49d220);
