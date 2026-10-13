// batch756.cpp - gap band batch 756 (docs/20-gap-band-401000.md): 0x41ef80, thiscall, no arguments, void.
#include "ff.h"

typedef u32(THISCALL *F1)(u8 *self, u32 a);
static u32 vc1(u8 *o, u32 s, u32 a) { return ((F1)(*(const u32 *)(*(const u32 *)o + s)))(o, a); }

extern "C" void THISCALL ext_4d0b30(u8 *self);   // thiscall, no arguments (exe code)

static void THISCALL fn41ef80(u8 *self) {
  const u32 esi = vc1(G(u8 *, 0x70038c), 0x54, 0xffffffff);
  ext_4d0b30(*(u8 **)(self + 0x31));
  vc1(G(u8 *, 0x70038c), 0x54, esi);
}

PCREG(41ef80, fn41ef80);
