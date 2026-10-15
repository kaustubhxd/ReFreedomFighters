#include "ff.h"

extern "C" u32 FASTCALL ext_54f2b0(u32 code, u32 label);
typedef void (THISCALL *slot2)(void *, u32, u32);
typedef u32 (THISCALL *slot4)(void *, u32, u32, u32, u32);

static u32 THISCALL fn54c320(u8 *self) {
  u32 state = G(u32, self + 0x75) - 2;
  self[0x7a] = 1;
  if (state <= 1) self[0x7b] = 1;
  u8 *collection = (u8 *)G(u32, self + 0x63ec);
  u32 vt = G(u32, collection);
  ((slot2)G(u32, vt + 0x34))((void *)vt, (u32)collection, 0);
  u32 enabled = self[0x7b];
  collection = (u8 *)G(u32, self + 0x63ec);
  vt = G(u32, collection);
  u32 result = ((slot4)G(u32, vt + 0x30))((void *)vt, (u32)collection, 0, 0, enabled ? 1 : 0);
  if (result) return ext_54f2b0(result, 0x6a3c20u);
  return 0;
}

PCREG(54c320, fn54c320);
