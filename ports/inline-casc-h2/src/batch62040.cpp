#include "ff.h"

extern "C" u32 THISCALL ext_5a5950(u8 *self, u32 a, u32 b);

static u32 THISCALL fn5a56d0(u8 *self, u32 a, u32 b, u32 kind) {
  if (kind == 2) return ext_5a5950(self + 0x54a, a, b);
  if (kind == 3) return ext_5a5950(self + 0x53c, a, b);
  u32 assert_fn = G(u32, 0x7003b0);
  ((void (STDCALL *)(void))assert_fn)();
  return 0;
}

PCREG(5a56d0, fn5a56d0);
