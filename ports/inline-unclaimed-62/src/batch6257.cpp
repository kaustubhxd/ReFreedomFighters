// batch6257 - ragdoll side (claim 50): CRagdoll2::Init(ZLNKOBJ *lnk) [0x644630; thiscall, one stack argument, ret 4]:
// 0x645000 (thiscall, this, lnk; GUESS stub by address), then 0x6411b0 (thiscall, this; GUESS stub by address), then this+0x2e = 0.
#include "ff.h"

extern "C" void THISCALL ext_645000(void *self, void *lnk);   // ragdoll setup (GUESS stub)
extern "C" void THISCALL ext_6411b0(void *self);              // ComputeParticlePositions (GUESS stub)

static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static void THISCALL fn644630(u8 *self, void *lnk) {
  ext_645000(self, lnk);
  ext_6411b0(self);
  wr32u(self + 0x2e, 0);
}
PCREG(644630, fn644630);
