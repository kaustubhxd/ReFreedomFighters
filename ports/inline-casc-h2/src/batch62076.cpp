#include "ff.h"

static u32 THISCALL fn4a0e40(u8 *self, s32 value) {
  for (u32 i = 0; i < 8; ++i) {
    s32 lower = i == 0 ? 0 : (s32)G(u32, self + i * 4 + 0x800) + 1;
    s32 upper = (s32)G(u32, self + i * 4 + 0x804);
    if (value >= lower && value <= upper) return i;
  }
  u32 assert_fn = G(u32, 0x7003b0);
  if (assert_fn) {
    typedef void (*fn_t)();
    ((fn_t)assert_fn)();
  }
  return 0;
}
PCREG(4a0e40, fn4a0e40);
