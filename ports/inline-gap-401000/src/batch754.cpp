// batch754.cpp - gap band batch 754 (docs/20-gap-band-401000.md): 0x41ef50, thiscall, no arguments, void.
#include "ff.h"

extern "C" void THISCALL ext_4d0f80(u8 *self);                             // thiscall, no arguments (exe code)
extern "C" void __attribute__((cdecl)) ext_634273(u32 p, u32 flag);       // delete helper (cdecl, caller cleans 8)

static void THISCALL fn41ef50(u8 *self) {
  const u32 idx = *(u32 *)(self + 0x45) - 1;
  *(u32 *)(self + 0x45) = idx;
  u8 *esi = *(u8 **)(self + 0x35 + 4 * idx);
  if (esi != nullptr) {
    ext_4d0f80(esi);
    ext_634273((u32)esi, 0x8c);
  }
}

PCREG(41ef50, fn41ef50);
