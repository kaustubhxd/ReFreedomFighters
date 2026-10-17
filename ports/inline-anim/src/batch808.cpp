// batch808.cpp - animation layer thread, batch 808: ZLNKOBJ per-bone anim table helpers.
// ZLNKOBJ (PC): +0x18 anim controller (vt 0x14 = "running"), +0x1c per-bone table (0x18 bytes per bone: +0 frame,
// +4 flags (bit 0 bone anim running, bit 1 bone motion), +0xc extra, +0x10 anim id, +0x14 ZBoneAnim*), +0x20 bones.
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// ZLNKOBJ::ActivateAnim(AnimHeader*, int) [high, GameCube reference]: vt[0x228] = ActivateAnimSegment(hdr, n, 0, -1, 1).
static u32 THISCALL ActivateAnim(void *self, void *hdr, u32 n) {
  return vcall<u32>(self, 0x228, hdr, n, 0.0f, -1.0f, 1.0f);
}
PCREG(4610f0, ActivateAnim);

// ZLNKOBJ::CheckActiveAnim(AnimHeader*, int) [medium, GameCube reference]: forwards to vt[0x23c] (the by-name overload).
static u32 THISCALL CheckActiveAnim(void *self, void *hdr, u32 n) { return vcall<u32>(self, 0x23c, hdr, n); }
PCREG(461970, CheckActiveAnim);

// ZLNKOBJ::CheckBoneAnimRunning(int) [high, GameCube reference]: flags bit 0.
static u8 THISCALL CheckBoneAnimRunning(void *self, s32 i) { return F8((u8 *)FP(self, 0x1c) + i * 0x18, 4) & 1; }
PCREG(4619c0, CheckBoneAnimRunning);

// ZLNKOBJ::CheckBoneMotion(int) const [high, GameCube reference]: flags bits 0..1.
static bool THISCALL CheckBoneMotion1(void *self, s32 i) { return (F8((u8 *)FP(self, 0x1c) + i * 0x18, 4) & 3) != 0; }
PCREG(4619e0, CheckBoneMotion1);

// ZLNKOBJ::CheckBoneMotion() const [high, GameCube reference]: any bone with vt[0x324](i) (CheckBoneMotion(int)).
static bool THISCALL CheckBoneMotion(void *self) {
  u32 n = F32(self, 0x20);
  for (u32 i = 0; i != n; i++)
    if (vcall<bool>(self, 0x324, i)) return true;
  return false;
}
PCREG(461a00, CheckBoneMotion);

// ZLNKOBJ::IsAnimationRunning() const [medium, GameCube reference].
static bool THISCALL IsAnimationRunning(void *self) {
  void *c = FP(self, 0x18);
  return c && vcall<u32>(c, 0x14) != 0;
}
PCREG(4634d0, IsAnimationRunning);

// ZLNKOBJ::ResetInactiveBones() [high, GameCube reference]: anim id cleared for bones with no bone anim / motion.
static void THISCALL ResetInactiveBones(void *self) {
  u8 *b = (u8 *)FP(self, 0x1c);
  for (u32 i = 0; i != F32(self, 0x20); i++, b += 0x18)
    if (!(F8(b, 4) & 3)) F32(b, 0x10) = 0;
}
PCREG(463fc0, ResetInactiveBones);

// ZLNKOBJ::ResetAllAnimBones() [high, GameCube reference]: vt[0x340](i, 0) for every bone (EndMatBoneMotion, inference
// from the GC slot), then clear flags bits 0..1, anim id, ZBoneAnim* and frame of every bone.
static void THISCALL ResetAllAnimBones(void *self) {
  for (u32 i = 0; i != F32(self, 0x20); i++) vcall<void>(self, 0x340, i, 0);
  u8 *b = (u8 *)FP(self, 0x1c);
  for (u32 i = 0; i != F32(self, 0x20); i++, b += 0x18) {
    F32(b, 4) &= ~3u;
    F32(b, 0x10) = 0;
    F32(b, 0x14) = 0;
    F32(b, 0) = 0;
  }
}
PCREG(463f60, ResetAllAnimBones);
