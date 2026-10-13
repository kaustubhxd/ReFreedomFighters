// batch777.cpp - gap band batch 777 (docs/20-gap-band-401000.md): 0x41cf80, cdecl, no arguments, void.
#include "ff.h"

typedef u32(THISCALL *F0)(u8 *self);
typedef u32(THISCALL *F1)(u8 *self, u32 a);
static u32 vc0(u8 *o, u32 s) { return ((F0)(*(const u32 *)(*(const u32 *)o + s)))(o); }
static u32 vc1(u8 *o, u32 s, u32 a) { return ((F1)(*(const u32 *)(*(const u32 *)o + s)))(o, a); }

extern "C" void __attribute__((cdecl)) ext_634273(u32 p, u32 flag);   // cdecl, two arguments (exe code)

static void __attribute__((cdecl)) fn41cf80(void) {
  const u32 v = G(u32, 0x6fcd44);
  if (v != 0) {
    ext_634273(v, 0xd);
    G(u32, 0x6fcd44) = 0;
  }
  const u32 o = G(u32, 0x6fcd48);
  if (o == 0) return;
  vc0((u8 *)o, 0x10);
  const u32 o2 = G(u32, 0x6fcd48);
  if (o2 != 0) vc1((u8 *)o2, 0, 1);
  G(u32, 0x6fcd48) = 0;
}

PCREG(41cf80, fn41cf80);
