// batch222.cpp - ZIKLNKOBJ small members (inline-ladder thread, 2026-10-11). Names are GC names via the name map
// (confidence as given); +0x6c is the IK/ragdoll object, +0x136 a flag word (0x20000 = IK on), +0x158 a byte
// "facing disabled", +0x159 the flag word saved by PushState.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" u32 THISCALL ext_4639f0(void *self);   // ZLNKOBJ::PushState
extern "C" u32 THISCALL ext_463940(void *self);   // ZLNKOBJ::PopState
struct Quad222 { u32 a, b, c, d; };

// 0x4690b0: an empty function (ret), shared by ZIKLNKOBJ::ResetTargets, RemoveTargets, CalcAnimRemapNames,
// DisableControls, EnableControls and others (identical code folding).
static void THISCALL emptyFn(void *) {}
PCREG(4690b0, emptyFn);

// 0x420060: returns 0, one stack argument (ret 4). ZIKLNKOBJ::CreateLnkAction(unsigned) [low]: the base class makes no
// actions (ZLNKWHANDS overrides it, batch 212).
static u32 THISCALL returnZero4(void *, u32) { return 0; }
PCREG(420060, returnZero4);

// 0x466610 ZIKLNKOBJ::EnableFacing() [high]: byte +0x158 = 0.
static void THISCALL enableFacing(u8 *self) { self[0x158] = 0; }
PCREG(466610, enableFacing);
// 0x466620 ZIKLNKOBJ::EnableIK() [high]: +0x136 |= 0x20000.
static void THISCALL enableIK(u8 *self) { U32(self, 0x136) |= 0x20000; }
PCREG(466620, enableIK);
// 0x466470 ZIKLNKOBJ::DisableIK() [high]: +0x136 &= ~0x20000.
static void THISCALL disableIK(u8 *self) { U32(self, 0x136) &= 0xfffdffff; }
PCREG(466470, disableIK);

// Bone index getters [medium]: own slot 0x2b4(bone id) (the skeleton's bone lookup), result returned.
static u32 THISCALL headBone(void *s) { return vcall<u32>(s, 0x2b4, 0x16u); }
PCREG(466f40, headBone);
static u32 THISCALL neckBone(void *s) { return vcall<u32>(s, 0x2b4, 2u); }
PCREG(466f50, neckBone);
static u32 THISCALL pelvisBone(void *s) { return vcall<u32>(s, 0x2b4, 0x11u); }
PCREG(466d70, pelvisBone);
static u32 THISCALL lHandBone(void *s) { return vcall<u32>(s, 0x2b4, 0x15u); }
PCREG(4673f0, lHandBone);
static u32 THISCALL rHandBone(void *s) { return vcall<u32>(s, 0x2b4, 6u); }
PCREG(466d80, rHandBone);
static u32 THISCALL lToeBone(void *s) { return vcall<u32>(s, 0x2b4, 0xau); }
PCREG(467400, lToeBone);

// 0x466c30: four stack args (a member-function pointer by value, 16 bytes), ret 0x10: 2 when it is exactly
// {0x465708, 0, 0, 0}, else 0. A "callback to id" helper; the name map's "RToeBoneIndex" [high] does not fit the body.
static u32 THISCALL callBackToId(void *, u32 a, u32 b, u32 c, u32 d) {
  return (a == 0x465708 && b == 0 && c == 0 && d == 0) ? 2 : 0;
}
PCREG(466c30, callBackToId);

// 0x465870 ZIKLNKOBJ::BoneAnimIdToCallBack(unsigned id) [high], ret 4: 0x465710 (the action-callback thunk used by every
// hero action) for id 1, else 0.
static u32 THISCALL boneAnimIdToCallBack(void *, u32 id) { return id == 1 ? 0x465710 : 0; }
PCREG(465870, boneAnimIdToCallBack);

// 0x4673d0 ZIKLNKOBJ::PushState() [high]: save +0x136 in +0x159, turn IK off, then ZLNKOBJ::PushState (tail call).
static u32 THISCALL pushState(u8 *self) {
  u32 f = U32(self, 0x136);
  U32(self, 0x159) = f;
  U32(self, 0x136) = f & 0xfffdffff;
  return ext_4639f0(self);
}
PCREG(4673d0, pushState);

// 0x467390 ZIKLNKOBJ::PopState() [high]: own slot 0x360 (EnableIK) when the saved flags had IK on, else slot 0x364
// (DisableIK); then ZLNKOBJ::PopState (tail call).
static u32 THISCALL popState(u8 *self) {
  if (U32(self, 0x159) & 0x20000)
    vcall<void>(self, 0x360);
  else
    vcall<void>(self, 0x364);
  return ext_463940(self);
}
PCREG(467390, popState);

// 0x466420 ZIKLNKOBJ::DisableFacing() [medium]: own slot 0x3c8(0, {0, 0, 0, -1} by value) (facing target cleared),
// then byte +0x158 = 1.
static void THISCALL disableFacing(u8 *self) {
  Quad222 q = {0, 0, 0, 0xffffffffu};
  vcall<void>(self, 0x3c8, 0u, q);
  self[0x158] = 1;
}
PCREG(466420, disableFacing);

// 0x466480 ZIKLNKOBJ::DisplayGround(bool) [high], ret 4: own slot 0x2a8(0, b); its result is returned.
static u32 THISCALL displayGround(void *self, u32 b) { return vcall<u32>(self, 0x2a8, 0u, b); }
PCREG(466480, displayGround);

// 0x466c10 ZIKLNKOBJ::HitRagdoll(const float *p, const float *d, float f) [high], ret 0xc: the ragdoll (+0x6c) slot
// 0x3c(p, d, f); result returned.
static u32 THISCALL hitRagdoll(u8 *self, u32 p, u32 d, float f) { return vcall<u32>((void *)U32(self, 0x6c), 0x3c, p, d, f); }
PCREG(466c10, hitRagdoll);

// 0x466890 ZIKLNKOBJ::GetIKBonePos(int bone, float *pos) const [high], ret 8: the IK object (+0x6c) slot 0x10
// (matrix out, pos out, bone, owner) with a scratch 3x3 matrix on the stack.
static u32 THISCALL getIKBonePos(u8 *self, u32 bone, u32 pos) {
  float mat[9];
  return vcall<u32>((void *)U32(self, 0x6c), 0x10, mat, pos, bone, self);
}
PCREG(466890, getIKBonePos);
// 0x466830 ZIKLNKOBJ::GetIKBoneMat(int bone, float *mat) const [high], ret 8: same call with a scratch position.
static u32 THISCALL getIKBoneMat(u8 *self, u32 bone, u32 mat) {
  float pos[3];
  return vcall<u32>((void *)U32(self, 0x6c), 0x10, mat, pos, bone, self);
}
PCREG(466830, getIKBoneMat);
// 0x466870 ZIKLNKOBJ::GetIKBoneMatPos(int bone, float *mat, float *pos) const [high], ret 0xc.
static u32 THISCALL getIKBoneMatPos(u8 *self, u32 bone, u32 mat, u32 pos) {
  return vcall<u32>((void *)U32(self, 0x6c), 0x10, mat, pos, bone, self);
}
PCREG(466870, getIKBoneMatPos);
