// batch6100.cpp - unclaimed-68 batch 11 (claim 10). Name from the GC name map (naming only, never committed).
#include "ff.h"

// 0x547830, ConstrainedParticleSystem::SetParticleVel(int, float*) (name map): thiscall, ret 8. The base pointer is the dword
// at this+0xf (unaligned); the entry at base + idx*0x34 gets the three dwords of the vector at +0x24, +0x28, +0x2c.
static void THISCALL particleSetVel(u8 *self, s32 idx, const u32 *v) {
  u32 base = *(u32 *)(self + 0xf);
  u8 *dst = (u8 *)(base + (u32)idx * 0x34u);
  *(u32 *)(dst + 0x24) = v[0];
  *(u32 *)(dst + 0x28) = v[1];
  *(u32 *)(dst + 0x2c) = v[2];
}
PCREG(547830, particleSetVel);
