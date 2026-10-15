#include "ff.h"
static u32 THISCALL fn49b2e0(u8 *self, u32 value) {
  u32 key = value + 1;
  u32 count = G(u32, self + 8);
  u8 *items = (u8 *)G(u32, self + 0x10);
  if (items) {
    for (u32 i = 0; i < count; ++i) {
      u8 *item = items + i * 0x10;
      if (G(u32, item) == key) {
        G(u32, self + 0xc) = (u32)item;
        return (u32)item;
      }
    }
  }
  u32 assert_fn = G(u32, 0x7003b0);
  if (assert_fn) { typedef u32 (*fn_t)(); return ((fn_t)assert_fn)(); }
  asm volatile("int3");
  return 0;
}
PCREG(49b2e0, fn49b2e0);
