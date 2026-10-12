#include "ff.h"
// batch2807.cpp - unclaimed-28 batch 7 (docs/20-unclaimed-28.md). Name from the GC name map (low; naming only).
// The callee at 0x645100 (not lifted here) runs as original code; the harness stubs it with a logger.

extern "C" void THISCALL ext_645100(u8 *obj, u32 idx);

// 0x6475f0, ZBoneModifyBase::UnfixParticle(int) (low). If the pointer at this+0x291 is nonzero, tail-jumps to 0x645100 with
// that pointer as `this` and the same argument. Otherwise returns. Callee pops 4 bytes.
static void THISCALL boneModifyUnfixParticle(u8 *self, u32 idx) {
  u8 *p = *(u8 **)(self + 0x291);
  if (p != 0)
    ext_645100(p, idx);
}
PCREG(6475f0, boneModifyUnfixParticle);
