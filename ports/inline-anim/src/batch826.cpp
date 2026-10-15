// batch826.cpp - animation layer thread, batch 826: ZIKLNKOBJ flags, bone-id getters, ZTARGET accessors.
// ZIKLNKOBJ flags word +0x136: 0x20000 = IK on (EnableIK/DisableIK). Byte +0x158 = facing flag.
// Bone getters ask the bone map (vt 0x2b4) for the bone of a fixed bone id: 0x11 pelvis, 6 right hand,
// 0x16 head, 2 neck, 0x15 left hand, 0xa left toe (ids as the exe passes them; names from the call site).
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FF(p, o) (*(float *)((u8 *)(p) + (o)))

// ZIKLNKOBJ::DisableIK() [high, GC-mapped]: clears flag 0x20000 at +0x136.
static void THISCALL DisableIK(u8 *self) { F32(self, 0x136) &= 0xfffdffffu; }
PCREG(466470, DisableIK);

// ZIKLNKOBJ::EnableIK(): sets flag 0x20000.
static void THISCALL EnableIK(u8 *self) { F32(self, 0x136) |= 0x20000u; }
PCREG(466620, EnableIK);

// ZIKLNKOBJ::EnableFacing() [GC-mapped]: clears the facing byte at +0x158.
static void THISCALL EnableFacing(u8 *self) { F8(self, 0x158) = 0; }
PCREG(466610, EnableFacing);

// Bone-id getters (vt 0x2b4 is the bone-by-id lookup). Each returns the bone index for its fixed id.
static s32 THISCALL PelvisBoneIndex(void *self) { return vcall<s32>(self, 0x2b4, 0x11); }
PCREG(466d70, PelvisBoneIndex);
static s32 THISCALL RHandBoneIndex(void *self) { return vcall<s32>(self, 0x2b4, 6); }
PCREG(466d80, RHandBoneIndex);
static s32 THISCALL HeadBoneIndex(void *self) { return vcall<s32>(self, 0x2b4, 0x16); }
PCREG(466f40, HeadBoneIndex);
static s32 THISCALL NeckBoneIndex(void *self) { return vcall<s32>(self, 0x2b4, 2); }
PCREG(466f50, NeckBoneIndex);
static s32 THISCALL LHandBoneIndex(void *self) { return vcall<s32>(self, 0x2b4, 0x15); }
PCREG(4673f0, LHandBoneIndex);
static s32 THISCALL LToeBoneIndex(void *self) { return vcall<s32>(self, 0x2b4, 0xa); }
PCREG(467400, LToeBoneIndex);

// ZTARGET accessors (target block at ZIKHAND+4; see batch 805). Geom id is the dword at +0x39.
static u32 THISCALL TargetGeom(u8 *t) { return F32(t, 0x39); }
PCREG(4666d0, TargetGeom);

// ZTARGET::Removing(): true while the blend time at +0x35 is below 0 (blending out).
// comiss sets CF on unordered (NaN) too, so the test is "not (x >= 0)", not "x < 0".
static bool THISCALL TargetRemoving(u8 *t) { return !(FF(t, 0x35) >= G(float, 0x6785d0)); }
PCREG(467700, TargetRemoving);

// ZTARGET::Pos(): the position at +0x25, or null when that word is the 0x7fffffff "not set" marker.
static void *THISCALL TargetPos(u8 *t) {
  if (F32(t, 0x25) == 0x7fffffffu) return 0;
  return t + 0x25;
}
PCREG(4673c0, TargetPos);
