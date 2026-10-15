// batch821.cpp - animation layer thread, batch 821: ZMovementBase helpers (movement controller that plays clips).
// ZMovementBase (PC): +4 the owner player/actor (vtable with the subclass virtuals), +8 collision box holder.
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// ZMovementBase::FindBestAnim(const char*) const [medium, GameCube reference]: a tail jump into the owner's virtual 0x35c.
static void *THISCALL FindBestAnim(u8 *self, const char *name) { return vcall<void *>(FP(self, 4), 0x35c, name); }
PCREG(488490, FindBestAnim);

// ZMovementBase::GetSettingsFromAnim(ZAnimDefs*) const [medium, GameCube reference]: tail jump into vt 0x5e4.
static void *THISCALL GetSettingsFromAnim(u8 *self, void *defs) { return vcall<void *>(FP(self, 4), 0x5e4, defs); }
PCREG(489330, GetSettingsFromAnim);

// ZMovementBase::CalcNewSpeed(const float* a, const float* b, float* out1, float* out2) [medium, GameCube reference].
// Base version: both outputs cleared (the movement classes override it).
static void THISCALL CalcNewSpeed(void *, const float *, const float *, float *o1, float *o2) {
  for (int i = 0; i < 3; i++) { ((u32 *)o2)[i] = 0; ((u32 *)o1)[i] = 0; }
}
PCREG(487c30, CalcNewSpeed);

// ZMovementBase::CheckMovingSphereCollision(ZSphereImpact*, const float* from, const float* to, float* hit,
// float* normal, float* dist) const [medium, GameCube reference]. The owner's flag +0x5ff must be set (else false). The
// owner's box offsets (+0x42d, +0x431, +0x435) go to the collision box (+0x54..+0x5c) and the box's moving-sphere test
// runs with the owner's extent at +0x439 and the owner's byte at +0x1c. Argument 2 and 4 are not used.
extern "C" u32 THISCALL ext_4ea390(void *box, u32 imp, u32 a2, u32 a4, void *pos, u32 a5, u32 flag);   // ZCollisionBox::MovingSphereCollision
static u32 THISCALL CheckMovingSphereCollision(u8 *self, u32 imp, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 *p = (u8 *)FP(self, 4);
  if (!F8(p, 0x5ff)) return 0;
  u8 *box = (u8 *)FP(self, 8);
  F32(box, 0x54) = F32(p, 0x42d);
  F32(box, 0x58) = F32(p, 0x431);
  F32(box, 0x5c) = F32(p, 0x435);
  return ext_4ea390(box, imp, a2, a4, p + 0x439, a5, F8(self, 0x1c));
}
PCREG(4883d0, CheckMovingSphereCollision);
