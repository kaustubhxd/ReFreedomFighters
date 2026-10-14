// batch974.cpp - area 56 band, claim A40 (0x536c40).
#include "ff.h"

extern "C" u32 THISCALL ext_445c50(u8 *self);  // original exe helper (CurrentRoom per docs/20-camera.md; hooked in the spec)

// A40 0x536c40: a == 0 returns g_pSysInterface->+0x9b->+0xadc; else returns ext_445c50(a) with ecx = a.
static u32 STDCALL f536c40(u32 a) {
  if (a == 0) {
    u8 *g = (u8 *)G(u32, 0x70039c);
    u8 *x = (u8 *)*(u32 *)(g + 0x9b);
    return *(u32 *)(x + 0xadc);
  }
  return ext_445c50((u8 *)a);
}
PCREG(536c40, f536c40);
