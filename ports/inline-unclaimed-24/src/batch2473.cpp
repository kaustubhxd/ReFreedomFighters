// batch2473.cpp - decomp area 24, batch 2473 (gap band).
#include "ff.h"

extern "C" void THISCALL ext_459c40(void *self, u32 fbits);  // ZParticleBox update(float), thiscall, ret 4

// 0x459b60 ZParticleBox::DrawUpdate(), thiscall, plain ret.
static void THISCALL particleBoxDrawUpdate(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  u32 t = *(u32 *)(sys + 0x3c);
  if (*(u32 *)(self + 0x24) != t) {
    *(u32 *)(self + 0x24) = t;
    float v = *(float *)(sys + 0x48) * G(float, 0x67885c);
    u32 bits;
    __builtin_memcpy(&bits, &v, 4);
    ext_459c40(self, bits);
  }
}
PCREG(459b60, particleBoxDrawUpdate);
