#include "ff.h"

extern "C" u32 THISCALL ext_600280(u8 *self, u32 a, u32 b, u32 c, u32 copied_this, u32 d);
typedef u32 (*cdecl3)(u32, u32, u32);
typedef u32 (*assert_fn)();

static u32 THISCALL fn6001e0(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  u32 ok = ext_600280(self + 0xcc, a, b, c, (u32)self, d);
  if ((u8)ok) return ok;
  u8 *logger = G(u8 *, 0x700390);
  u8 *msg = vcall<u8 *>(logger, 0x20, 0x6b94a0u, 0x1f2u);
  cdecl3 print = (cdecl3)G(u32, G(u32, msg) + 0x2c);
  print((u32)msg, 0x69c6b0u, 0x6b94d0u);
  assert_fn h = G(assert_fn, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  return h();
}

PCREG(6001e0, fn6001e0);
