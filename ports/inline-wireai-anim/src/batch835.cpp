// batch835.cpp - animation layer thread, batch 835: ZIKLNKOBJ per-frame target update and ragdoll hit forwarder.
#include "ff.h"

#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// ZIKLNKOBJ::UpdateTargets() [medium]: vt +0x408(), vt +0x404(), then the tail call vt +0x40c().
static void THISCALL UpdateTargets(u8 *self) {
  vcall<void>(self, 0x408);
  vcall<void>(self, 0x404);
  vcall<void>(self, 0x40c);
}
PCREG(467f60, UpdateTargets);

// ZIKLNKOBJ::HitRagdoll(const float* a, const float* b, float f) [medium]: the bone modifier's vt +0x3c(a, b, f).
// The exe pushes the owner pointer first and then overwrites that slot with f, so the order on the stack is a, b, f.
static void THISCALL HitRagdoll(u8 *self, const float *a, const float *b, float f) {
  vcall<void>(FP(self, 0x6c), 0x3c, a, b, f);
}
PCREG(466c10, HitRagdoll);
