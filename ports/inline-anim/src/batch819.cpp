// batch819.cpp - animation layer thread, batch 819: small ZLNKOBJ / ZBoneModifyBase forwarders.
// ZLNKOBJ +0x6c is its ZBoneModifyBase (bone modifier); ZBoneModifyBase +0x291 is the active ragdoll (CRagdoll2).
#include "ff.h"

#define F16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" u32 THISCALL ext_4db2c0(void *geom, float *m, float *p);           // ZBaseGeom::GetMatPos
extern "C" u32 THISCALL ext_641c90(void *rd, s32 i, float *p);                // CRagdoll2::FixParticle
extern "C" void THISCALL ext_644400(void *rd, const float *a, const float *b, float f);   // CRagdoll2::Hit
extern "C" void FASTCALL ext_4de420(float *d, const float *s);                // mcpy
extern "C" void FASTCALL ext_4de7a0(float *m);                                // mreset

// ZLNKOBJ::GetFocusMatPos(float*, float*) [high, GameCube reference]: the base geom's matrix/position.
static u32 THISCALL GetFocusMatPos(void *self, float *m, float *p) { return ext_4db2c0(FP(self, 8), m, p); }
PCREG(4632c0, GetFocusMatPos);

// ZBoneModifyBase::FixParticle(int, float*) [medium, GameCube reference]: forwards to the ragdoll (no null check).
static u32 THISCALL FixParticle(void *self, s32 i, float *p) { return ext_641c90(FP(self, 0x291), i, p); }
PCREG(6461c0, FixParticle);

// ZLNKOBJ::AttachBaseGeomToBone(geom, bone, m, p) [medium, GameCube reference]: modifier vt 0x24.
static u32 THISCALL AttachBaseGeomToBone(void *self, void *g, u32 b, float *m, float *p) {
  return vcall<u32>(FP(self, 0x6c), 0x24, g, b, m, p);
}
PCREG(462d00, AttachBaseGeomToBone);

// ZLNKOBJ::GetBoneMatPos(float* m, float* p, unsigned bone) const [medium, GameCube reference]: modifier vt 0x1c.
static u32 THISCALL LnkGetBoneMatPos(void *self, float *m, float *p, u32 b) { return vcall<u32>(FP(self, 0x6c), 0x1c, m, p, b); }
PCREG(4616b0, LnkGetBoneMatPos);

// ZLNKOBJ::SetForcedLODLevel(int) [high, GameCube reference]: modifier +0x268.
static void THISCALL SetForcedLODLevel(void *self, u32 l) { F32(FP(self, 0x6c), 0x268) = l; }
PCREG(464710, SetForcedLODLevel);

// ZLNKOBJ::CopyPoseFrom(ZLNKOBJ*) [high, GameCube reference]: only logs "ZLNKOBJ::CopyPoseFrom not supported!. Talk to DG".
static void THISCALL CopyPoseFrom(void *, void *) {
  void *sink = vcall<void *>(G(void *, 0x700390), 0x20, (const char *)0x685834, 0x5f9);
  typedef void(__attribute__((cdecl)) * pf)(void *, const char *);
  (*(pf *)(*(u8 **)sink + 0x2c))(sink, (const char *)0x6859c0);
}
PCREG(462430, CopyPoseFrom);

// 0x4632d0 [GC name ZLNKOBJ::GetAttachedBaseGeomBoneId; the PC body copies the matrix from modifier vt 0x58].
static void THISCALL GetAttachedBaseGeomBoneId(void *self, float *out) {
  float *m = vcall<float *>(FP(self, 0x6c), 0x58, self);
  ext_4de420(out, m);
}
PCREG(4632d0, GetAttachedBaseGeomBoneId);

// ZLNKOBJ::GetAttachedGeomMatPos(geom, m, p) const [high, GameCube reference]: modifier vt 0x14(m, p, geom, this).
static u32 THISCALL GetAttachedGeomMatPos(void *self, void *g, float *m, float *p) {
  return vcall<u32>(FP(self, 0x6c), 0x14, m, p, g, self);
}
PCREG(462d10, GetAttachedGeomMatPos);

// ZBoneModifyBase::HitRagdoll(const float*, const float*, float) [medium, GameCube reference].
static void THISCALL HitRagdoll(void *self, const float *a, const float *b, float f) {
  void *rd = FP(self, 0x291);
  if (rd) ext_644400(rd, a, b, f);
}
PCREG(647140, HitRagdoll);

// 0x464730 [GC name ZLNKOBJ::DetachBaseGeomFromBone; the PC body copies the argument matrix into modifier vt 0x58].
static void THISCALL DetachBaseGeomFromBone(void *self, float *src) {
  if (!F16(FP(self, 8), 0x5a)) return;
  float *m = vcall<float *>(FP(self, 0x6c), 0x58, self);
  ext_4de420(m, src);
}
PCREG(464730, DetachBaseGeomFromBone);

// ZLNKOBJ::GetRootFocusMatPos(float*, float*) [high, GameCube reference]: vt 0x2ac(m, p) then vt 0x98(m, p).
static void THISCALL GetRootFocusMatPos(void *self, float *m, float *p) {
  vcall<void>(self, 0x2ac, m, p);
  vcall<void>(self, 0x98, m, p);
}
PCREG(463320, GetRootFocusMatPos);

// ZBoneModifyBase::GetBoneMatPos(float* m, float* p, unsigned fileBoneId, const ZLNKOBJ* obj) const [medium,
// GameCube reference]: maps the file bone id to a bone (definitions vt 0xc8) and asks vt 0x10(m, p, bone, obj); on failure
// identity/zero and "WARNING: ZBoneModifyBase::GetBoneMatPos got invalid bone id %d" (line 0x104).
static void THISCALL BmGetBoneMatPos(void *self, float *m, float *p, u32 id, void *obj) {
  u32 gid = F32(FP(obj, 8), 0x6c);
  u8 *map = vcall<u8 *>(FP(FP(G(void *, 0x70039c), 0x1aa3), 0x18), 0xc8, gid);
  if (vcall<bool>(self, 0x10, m, p, (u32)map[id], obj)) return;
  ext_4de7a0(m);
  F32(p, 0) = 0;
  F32(p, 4) = 0;
  F32(p, 8) = 0;
  void *sink = vcall<void *>(G(void *, 0x700390), 0x20, (const char *)0x6c2904, 0x104);
  typedef void(__attribute__((cdecl)) * pf)(void *, const char *, u32);
  (*(pf *)(*(u8 **)sink + 0x2c))(sink, (const char *)0x6c2988, id);
}
PCREG(646350, BmGetBoneMatPos);
