// batch800.cpp - animation layer thread, batch 800: blend-frame entry points (PC Freedom.Exe.orig).
// PC objects are byte packed (/Zp1, docs/36), so fields are read by raw offset.
// Names: GameCube startup_release.elf via decoders/gc_pc_namemap.tsv (confidence noted per function).
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FF(p, o) (*(float *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// AnimHeader (clip header) fields used here: +0x5c, +0x6c ints (BlendInSpeed), +0x60 first frame, +0x64 last frame.

// ZBoneModifyBase::AddFrame(const ZDeltaBone*, const AnimHeader*, float frame, float weight, unsigned flags)
// [high, GC 802209f8]. Appends one layer to the per-object frame list: up to 4 entries of 20 bytes at +0x15,
// count at +0x65. A fifth add logs "ZBoneModifyBase::AddFrame more than %d" (line 0x65) and is dropped.
static void THISCALL AddFrame(void *self, void *delta, void *hdr, float frame, float weight, u32 flags) {
  u32 n = F32(self, 0x65);
  if (n == 4) {
    void *sink = vcall<void *>(G(void *, 0x700390), 0x20, (const char *)0x6c2904, 0x65);
    typedef void(__attribute__((cdecl)) * pf)(void *, const char *, int);
    (*(pf *)(*(u8 **)sink + 0x2c))(sink, (const char *)0x6c2934, 4);
    return;
  }
  u8 *e = (u8 *)self + 0x15 + 20 * n;
  F32(self, 0x65) = n + 1;
  *(void **)(e + 4) = delta;
  FF(e, 8) = frame;
  *(void **)(e + 0) = hdr;
  FF(e, 0xc) = weight;
  F32(e, 0x10) = flags;
}
PCREG(645420, AddFrame);

// ZLNKOBJ::SetBoneFrameBlend(AnimHeader*, float t, float weight, bool absolute, unsigned flags) [high, GC 801834a4].
// t is a fraction of the clip unless absolute; then adds the clip's delta bones to the bone modifier (+0x6c)
// through its vtable slot 6 (AddFrame). Delta bones come from this->vt[0x288] (ZLNKOBJ::GetAnimDeltaBones).
static void THISCALL SetBoneFrameBlend(void *self, void *hdr, float t, float weight, u8 absolute, u32 flags) {
  if (!hdr) return;
  float frame = absolute ? t : (float)(s32)(F32(hdr, 0x64) - F32(hdr, 0x60)) * t;
  u8 *mvt = *(u8 **)FP(self, 0x6c);
  void *delta = vcall<void *>(self, 0x288, hdr);
  typedef void(THISCALL * af)(void *, void *, void *, float, float, u32);
  (*(af *)(mvt + 0x18))(FP(self, 0x6c), delta, hdr, frame, weight, flags);
}
PCREG(464400, SetBoneFrameBlend);

// ZBoneModifyBase::DepackAnimBones(ZAnimFileBase*, ZBoneQuat*, ZBlendBone*, ZActiveBone*) [medium, GC 802237a0].
// When animations run (see DoAnimations), unpacks bones 1..count-1 (count at +0x11); strides: ZBoneQuat 0x30,
// ZBlendBone 0x24, ZActiveBone 0x1d (packed). Bone 0 (root) is skipped.
extern "C" void THISCALL ext_645c90(void *self, void *quat, void *blend, void *file, void *active);
static void THISCALL DepackAnimBones(void *self, void *file, u8 *quat, u8 *blend, u8 *active) {
  if (F32(self, 0x291) != 0 || F8(self, 0x295) != 0) return;
  for (u32 i = 1; i != F32(self, 0x11); i++) {
    quat += 0x30;
    blend += 0x24;
    active += 0x1d;
    ext_645c90(self, quat, blend, file, active);
  }
}
PCREG(645c30, DepackAnimBones);

// ZBoneModifyBase::DoAnimations() const [medium, GC 80220f48]: true unless ragdoll (+0x291) or flag byte +0x295.
static bool THISCALL DoAnimations(void *self) { return F32(self, 0x291) == 0 && F8(self, 0x295) == 0; }
PCREG(646040, DoAnimations);

// ZMovementBase::BlendInSpeed(const AnimHeader*) [medium, GC 8014b368]: (float)hdr+0x5c / (float)hdr+0x6c, on x87.
static float THISCALL BlendInSpeed(void *, void *hdr) {
  volatile float r = (float)(s32)F32(hdr, 0x5c) / (float)(s32)F32(hdr, 0x6c);
  return r;
}
PCREG(487a50, BlendInSpeed);

// ZPlayer::SetActiveUpperBody(float t) [high, GC 80152edc]: t is used only when bits 0..1 of byte +0x417 are set,
// else 0. Plays frame t (fraction) of the current upper-body clip (vt 0x5fc, GetCurrentUBAnim) at weight 0 through
// vt 0x244 = SetBoneFrameBlend(anim, t, 0.0f, false, 0).
static void THISCALL SetActiveUpperBody(void *self, float t) {
  float v = 0.0f;
  if (F8(self, 0x417) & 3) v = t;
  void *anim = vcall<void *>(self, 0x5fc);
  if (anim) vcall<void>(self, 0x244, anim, v, 0.0f, 0, 0);
}
PCREG(484ed0, SetActiveUpperBody);

// ZActor::SetHoldWeaponUBAnim(AnimHeader*) [high, GC 8017a974]: m_pAnimUBHoldRifle (HBM name) at PC +0x74f.
static void THISCALL SetHoldWeaponUBAnim(void *self, void *hdr) { FP(self, 0x74f) = hdr; }
PCREG(47be00, SetHoldWeaponUBAnim);
