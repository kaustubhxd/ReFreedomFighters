// batch6254 - ragdoll side (claim 47): ZBoneModifyBase::HitRagdoll(pos, dir, strength) [0x647140; thiscall, three stack arguments, ret 0xc].
// If this+0x291 is non-zero: CRagdoll2::Hit(pos, dir, strength) on that ragdoll (exe 0x644400; verified in batch 6252, stubbed by address here).
#include "ff.h"

extern "C" void THISCALL ext_644400(void *ragdoll, const float *pos, const float *dir, float strength);  // CRagdoll2::Hit (stub in the spec)

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }

static void THISCALL fn647140(u8 *self, const float *pos, const float *dir, float strength) {
  u8 *rag = rdp(self + 0x291);
  if (rag != 0) ext_644400(rag, pos, dir, strength);
}
PCREG(647140, fn647140);
