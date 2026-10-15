// batch705.cpp - soldier AI, batch 705 (2026-10-11): helpers of CCheckVisible::FrameUpdate.
// These four have no name-map row; the names are the GameCube CCheckVisible methods whose signatures and bodies match
// (GC ELF 80212cb4 GetSeerPosDir, 80212e10 GetObjectPosSneak, 802131f4 UpdateVisible), inferred.
// Geom virtual slots used (PC ZGEOM/ZIKLNKOBJ vtable, names from the name map): 0x84 GetRootPoint(float*),
// 0x88 GetRootVect(float*), 0x98 GetRootMatPos(float* mat, float* pos), 0x2ac ZLNKOBJ::GetFocusMatPos(mat, pos),
// 0x390 ZIKLNKOBJ::GetIKBoneMatPos(int bone, mat, pos), 0x3a0 head bone index (bone 0x17, unnamed),
// 0x3a8 NeckBoneIndex, 0x420 GetController, 0x438 (low-confidence "ZActor::IsDead"), 0x430/0x434 return false on
// actors (shared stub; overridden by the hero).
#include "ff.h"

// 0x4ab8e0 (unnamed; set the 14-bit timer of a seer/object state word, keeping the two flag bits). Asserts 0..0x3fff.
static void THISCALL cv_SetStateTimer(u16 *w, s32 v) {
  if (v < 0 || v > 0x3fff) {
    void (*h)() = *(void (**)())0x7003b0;
    if (h)
      h();
    else
      __builtin_debugtrap();
  }
  *w ^= (u16)((*w ^ (u16)v) & 0x3fff);
}
PCREG(4ab8e0, cv_SetStateTimer);

// 0x4ab920 CCheckVisible::UpdateVisible(unsigned int seer, unsigned int obj, bool visible, bool resend) (inferred).
// Seen (and the invisible cheat off): set the visible bit and send "seen" (+0x50), unless it was already visible and
// resend is false. Not seen: if it was visible, clear the bit and send "lost" (+0x52).
static void THISCALL cv_UpdateVisible(u8 *self, u32 seer, u32 obj, u32 visible, u32 resend) {
  u8 *s = self + seer * 0x1b8 + 0x694;
  u16 *st = (u16 *)(s + 0x28) + obj;
  u32 id;
  if (G(float, 0x700324) == 0.0f && (u8)visible) {
    u16 v = *st;
    if ((v >> 14 & 1) && !(u8)resend)
      return;
    *st = v | 0x4000;
    id = *(u16 *)(self + 0x50);
  } else {
    u16 v = *st;
    if (!(v >> 14 & 1))
      return;
    *st = v & 0xbfff;
    id = *(u16 *)(self + 0x52);
  }
  vcall<void>(*(void **)(self + 0x44), 0x12c, *(u32 *)s, id, *(u32 *)(self + 0x54 + obj * 8));
}
PCREG(4ab920, cv_UpdateVisible);

// 0x4aaa50 CCheckVisible::GetObjectPosSneak(float* pos, bool* sneak, ZGEOM* g, bool isIK) (inferred). For IK
// characters: the head bone position (or, when GetController() == 1 and slot 0x438 says so, the neck bone plus 10 up),
// falling back to the focus point when the bone lookup fails; *sneak = slot 0x434 && !slot 0x430.
// Otherwise the geom's root point and no sneak. `this` is not used.
static void THISCALL cv_GetObjectPosSneak(void *, float *pos, u8 *sneak, void *g, u32 isIK) {
  if (!(u8)isIK) {
    pos[0] = 0;
    pos[1] = 0;
    pos[2] = 0;
    vcall<void>(g, 0x84, pos);
    *sneak = 0;
    return;
  }
  float mat[10];
  float up = 0.0f;
  s32 bone;
  if (vcall<s32>(g, 0x420) == 1 && vcall<bool>(g, 0x438)) {
    bone = vcall<s32>(g, 0x3a8);
    up = 10.0f;                               // 0x680a70
  } else {
    bone = vcall<s32>(g, 0x3a0);
  }
  if (!vcall<bool>(g, 0x390, bone, mat, pos))
    vcall<void>(g, 0x2ac, mat, pos);
  vcall<void>(g, 0x84, pos);
  pos[1] = pos[1] + up;
  if (vcall<bool>(g, 0x434) && !vcall<bool>(g, 0x430))
    *sneak = 1;
  else
    *sneak = 0;
}
PCREG(4aaa50, cv_GetObjectPosSneak);

// 0x4aabe0 CCheckVisible::GetSeerPosDir(float* pos, float* dir, ZGEOM* g, const float* offset, bool isIK) (inferred).
// IK characters: head bone position (focus point fallback) raised by 30, through GetRootMatPos; dir = the third row
// of the resulting matrix (forward). Others: pos = offset, dir = (0, 0, 1), both taken to world space by the geom.
static void THISCALL cv_GetSeerPosDir(void *, float *pos, float *dir, void *g, const u32 *offset, u32 isIK) {
  if (!(u8)isIK) {
    ((u32 *)pos)[0] = offset[0];
    ((u32 *)pos)[1] = offset[1];
    ((u32 *)pos)[2] = offset[2];
    ((u32 *)dir)[0] = 0;
    ((u32 *)dir)[1] = 0;
    ((u32 *)dir)[2] = 0x3f800000;
    vcall<void>(g, 0x84, pos);
    vcall<void>(g, 0x88, dir);
    return;
  }
  float mat[10];
  s32 bone = vcall<s32>(g, 0x3a0);
  if (!vcall<bool>(g, 0x390, bone, mat, pos))
    vcall<void>(g, 0x2ac, mat, pos);
  pos[1] = pos[1] + 30.0f;                    // 0x67da24
  vcall<void>(g, 0x98, mat, pos);
  dir[0] = mat[6];
  dir[1] = mat[7];
  dir[2] = mat[8];
}
PCREG(4aabe0, cv_GetSeerPosDir);
