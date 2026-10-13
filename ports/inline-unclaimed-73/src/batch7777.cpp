// batch7777.cpp - area 73 batch 77 (GUESS name): FUN_500500 (stdcall, ret 0xc).
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a, u32 b);
extern "C" void THISCALL ext_5002f0(u8 *self);

// 0x500500 (GUESS FUN_500500): stdcall, three arguments. esi = vtable slot +0x18 on p with a2. When esi is non-null, r = vtable slot
// +0x4c on esi; rr = 0x5003d0(r, 0, a3); 0x5002f0(rr). Returns esi.
static u32 STDCALL guess500500(u8 *p, u32 a2, u32 a3) {
  u32 esi = vcall<u32>(p, 0x18, a2);
  if (esi) {
    u32 r = vcall<u32>((u8 *)esi, 0x4c);
    u32 rr = ext_5003d0((u8 *)r, 0u, a3);
    ext_5002f0((u8 *)rr);
  }
  return esi;
}
PCREG(500500, guess500500);
