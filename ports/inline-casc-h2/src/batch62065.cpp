#include "ff.h"

extern "C" void THISCALL ext_4614d0(u8 *self, u32 a, u32 b, u32 c);
typedef u32 (FASTCALL *edx_method)(void *, u32);

static u32 THISCALL fn5e03c0(u8 *self) {
  u8 *first = (u8 *)G(u32, self + 0xc);
  u8 *next = (u8 *)vcall<u32>(first, 0x10);
  u32 vt = G(u32, next);
  ((edx_method)G(u32, vt + 0x2e8))(next, vt);
  u32 value = G(u32, self + 0x10);
  if (!value) return vcall<u32>(self, 0xc);
  u8 *action = (u8 *)G(u32, self + 8);
  u8 *resource = (u8 *)vcall<u32>(action, 0x230, value, 1u);
  ext_4614d0(resource, 0x3c83126fu, 0x465710u, 0u);
  return 1;
}

PCREG(5e03c0, fn5e03c0);
