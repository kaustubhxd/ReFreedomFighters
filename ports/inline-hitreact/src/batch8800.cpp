// batch8800.cpp - hit-reaction / ragdoll thread, batch 8800: the bullet impulse chain below a soldier's death.
// ZIKLNKOBJ::HitRagdoll (hand-off into the ragdoll classes, owned by area 62) and ZActor::DieByForce.
// Draft lifts of CRagdoll2::Hit / BlowDirBomb / BlowBomb / ZBoneModifyBase::HitRagdoll moved to ../handoff-area62/ (2026-10-12).
// docs/42-soldier-hit-reaction-ragdoll.md has the write-up.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])

extern "C" void THISCALL ext_644400(void *self, const float *pos, const float *force, float strength);  // CRagdoll2::Hit
extern "C" void THISCALL ext_5438f0(void *ps, const float *pos, float force, const float *dir);          // BlowDirBomb
extern "C" void THISCALL ext_543810(void *ps, const float *pos, float force);                            // BlowBomb
extern "C" void THISCALL ext_4e0d00(float *v, float s);                                 // vscalar in place (batch 29)
extern "C" float FASTCALL ext_4e0870(const float *a, const float *b);                   // |a - b| (ST0)
extern "C" void FASTCALL ext_451890(float *dst, const float *v, float s);               // dst += v * s
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);        // PSVECSubtract dst = a - b
extern "C" void FASTCALL ext_441940(float *dst, const float *src);                      // PSVECAdd dst += src
extern "C" void FASTCALL ext_43e960(float *v, const float *a);                          // v -= a (x87)
extern "C" float FASTCALL ext_44e630(float *dst, const float *src);                     // vnorm(dst, src), length in ST0
extern "C" void THISCALL ext_545c80(void *ps, u32 i, float *out);                       // ConstrainedParticleSystem::GetParticlePos
extern "C" void THISCALL ext_4e1b60(void *coli);                                        // COLI::COLI
extern "C" void FASTCALL ext_4e0d40(float *out, const float *a, float s);               // out = a * s
extern "C" void THISCALL ext_641c90(void *self, u32 i, float *p);                       // CRagdoll2::FixParticle

typedef void(THISCALL *vHit)(void *self, const float *pos, const float *force, float strength);
typedef u8 *(THISCALL *vP0)(void *self);
typedef u8(THISCALL *vLine)(void *self, void *coli, u32 a, u32 b, u32 c, u32 d, u32 e);

// 0x466c10 ZIKLNKOBJ::HitRagdoll(const float*, const float*, float) (GC 8017cbe8): forwards unchanged to slot 0x3c of the
// bone modifier at +0x6c (ZBoneModifyBase::HitRagdoll).
static void THISCALL iklnkHitRagdoll(u8 *self, const float *pos, const float *force, float strength) {
  void *bm = *(void **)(self + 0x6c);
  ((vHit)VT(bm, 0x3c))(bm, pos, force, strength);
}
PCREG(466c10, iklnkHitRagdoll);

// 0x4783f0 ZActor::DieByForce (GC 8017ad08): calls own slot 0x664 = ZActor::Die() with NO arguments (the four arguments
// are only popped, ret 0x10).
typedef void(THISCALL *vV0)(void *self);
static void THISCALL actorDieByForce(u8 *self, const float *, const float *, float, u32) {
  ((vV0)VT(self, 0x664))(self);
}
PCREG(4783f0, actorDieByForce);

