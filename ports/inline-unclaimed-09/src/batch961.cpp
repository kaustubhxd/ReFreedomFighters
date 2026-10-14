// batch961.cpp - area 56 band, claim A24.
#include "ff.h"

// A24 0x533b80: ecx = dword [dword [0x70039c] + 0x1a9f]; push 0x1200; call vt[0x160] (thiscall, one argument); ret.
static u32 callVt533b80(void) {
  u8 *objA = (u8 *)G(u32, 0x70039c);
  u8 *objB = (u8 *)*(u32 *)(objA + 0x1a9f);
  u32 vt = *(u32 *)objB;
  return ((u32(THISCALL *)(u8 *, u32))(*(u32 *)(vt + 0x160)))(objB, 0x1200);
}
PCREG(533b80, callVt533b80);
