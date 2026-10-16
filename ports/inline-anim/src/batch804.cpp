// batch804.cpp - animation layer thread, batch 804: dual-clip frames, bone-modifier Update (ragdoll), and the
// upper-body clip getters of ZActor / ZFFActor / ZFFHERO.
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FF(p, o) (*(float *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

typedef void(THISCALL *addframe_t)(void *, void *, void *, float, float, u32);

// ZLNKOBJ::SetDualFrame(AnimHeader* a, float ta, AnimHeader* b, float tb, float wb, float blend) [high, GameCube reference].
// Two layers: clip a at fraction ta with flag 4 (paired), then clip b at fraction tb as its second clip; in
// GetBonesFrames b's "blend" field (wb) becomes the second-clip weight. blend goes into a's blend-in time.
static void THISCALL SetDualFrame(void *self, void *a, float ta, void *b, float tb, float wb, float blend) {
  float fa = (float)(s32)(F32(a, 0x64) - F32(a, 0x60)) * ta;
  float fb = (float)(s32)(F32(b, 0x64) - F32(b, 0x60)) * tb;
  u8 *mvt = *(u8 **)FP(self, 0x6c);
  void *d = vcall<void *>(self, 0x288, a);
  (*(addframe_t *)(mvt + 0x18))(FP(self, 0x6c), d, a, fa, blend, 4);
  mvt = *(u8 **)FP(self, 0x6c);
  d = vcall<void *>(self, 0x288, b);
  (*(addframe_t *)(mvt + 0x18))(FP(self, 0x6c), d, b, fb, wb, 0);
}
PCREG(464650, SetDualFrame);

// ZBoneModifyBase::Update(ZLNKOBJ* obj, float* mat, float* pos) [high, GameCube reference]. thiscall ret 0xc, bool in AL.
// Once per engine frame (frame number [0x70039c]+0x3c kept at +9; a second call logs "Update twice in same frame",
// line 0xa8). dt = (clock - last clock at +5) / 1024. Only does work while a ragdoll (+0x291) is active: identity
// mat, zero pos, and unless byte +0x295, CRagdoll2::Move(mat, pos, dt); when Move returns false the ragdoll is done:
// its pose is read into a 0x1200-byte buffer (0x6421a0), handed to obj->vt[0x284](buf, obj->vt[0x2cc]()),
// this->vt[0x28](obj), the ragdoll is returned to its container (+0x28d, DeactivateRagdoll), +0x291 = 0 and
// byte +0x295 = 1 (frozen in the ragdoll pose).
extern "C" void FASTCALL ext_4de7a0(float *m);                                   // mreset
extern "C" bool THISCALL ext_644af0(void *rd, float *mat, float *pos, float dt);  // CRagdoll2::Move
extern "C" void THISCALL ext_6421a0(void *rd, void *buf);                         // (ragdoll pose out)
extern "C" void THISCALL ext_641b60(void *cont, void *rd);                        // ZRagdollContainer::DeactivateRagdoll
static bool THISCALL Update(u8 *self, void *obj, float *mat, float *pos) {
  u8 *g = (u8 *)G(void *, 0x70039c);
  u32 fr = F32(g, 0x3c);
  if (F32(self, 9) == fr) {
    void *sink = vcall<void *>(G(void *, 0x700390), 0x20, (const char *)0x6c2904, 0xa8);
    typedef void(__attribute__((cdecl)) * pf)(void *, const char *);
    (*(pf *)(*(u8 **)sink + 0x2c))(sink, (const char *)0x6c295c);
    return false;
  }
  s32 dtk = *(s32 *)(g + 0x40) - *(s32 *)(self + 5);
  F32(self, 9) = fr;
  float dt = (float)dtk * bitsf(0x3a800000);
  F32(self, 5) = F32(G(u8 *, 0x70039c), 0x40);
  if (F32(self, 0x291) == 0) return false;
  ext_4de7a0(mat);
  F32(pos, 0) = 0;
  F32(pos, 4) = 0;
  F32(pos, 8) = 0;
  if (F8(self, 0x295)) return false;
  if (ext_644af0(FP(self, 0x291), mat, pos, dt)) return true;
  u8 buf[0x1200];
  ext_6421a0(FP(self, 0x291), buf);
  u8 *vt = *(u8 **)obj;
  u32 x = (*(u32(THISCALL **)(void *))(vt + 0x2cc))(obj);
  (*(void(THISCALL **)(void *, void *, u32))(vt + 0x284))(obj, buf, x);
  vcall<void>(self, 0x28, obj);
  ext_641b60(FP(self, 0x28d), FP(self, 0x291));
  F32(self, 0x291) = 0;
  F8(self, 0x295) = 1;
  return false;
}
PCREG(647610, Update);

// ZActor::GetCurrentUBAnim(ZItem* right, ZItem*) const [high, GameCube reference]; see docs/36 section 5 for the field
// meanings (HBM names, inference). Returns the hold-rifle clip (+0x74f) only for weapon types 2, 4, 5, 6.
extern "C" bool THISCALL ext_466cd0(void *aim);   // aim target "enabled" byte (mov al, [ecx])
static void *THISCALL ZActor_GetCurrentUBAnim(u8 *self, void *item, void *) {
  if (F8(self, 0x726) && F32(self, 0x64c) == 10) return 0;
  if (F8(self, 0x753)) return 0;
  if (!item) return 0;
  if (!vcall<bool>(item, 0x1e0, 0x1007d2)) return 0;
  if (ext_466cd0(self + 0x26a)) return 0;
  if (!F8(self, 0x726)) return 0;
  void *tmpl = vcall<void *>(item, 0x350);
  u32 t = vcall<u32>(tmpl, 0x330);
  if (t == 2 || t - 4 <= 2) return FP(self, 0x74f);
  return 0;
}
PCREG(478b70, ZActor_GetCurrentUBAnim);

// ZFFActor::GetCurrentUBAnim(ZItem*, ZItem*) const [medium, GameCube reference]: with bit 0 of byte +0x7a6 (close combat,
// inference from the clip name) the clip is this->vt[0x21c]("UB_CC_Stand") (GetAnim by name), else ZActor's.
extern "C" void *THISCALL ext_478b70(void *self, void *a, void *b);
static void *THISCALL ZFFActor_GetCurrentUBAnim(u8 *self, void *a, void *b) {
  if (F8(self, 0x7a6) & 1) return vcall<void *>(self, 0x21c, (const char *)0x6accdc);
  return ext_478b70(self, a, b);
}
PCREG(59fd00, ZFFActor_GetCurrentUBAnim);

// ZFFHERO::GetFFItemType() [high, GameCube reference]. Cached item type at +0x654 for the held item (+0x658 = last item).
// Flag 0x2000000 in +0x417 forces type 9; vt[0x438]() true forces 0. The type comes from the inventory info list
// at +0x95b (ZFFInventoryInfoList::GetFFItemType, 0x5aeff0).
extern "C" u32 THISCALL ext_5aeff0(void *list, void *item);
static u32 THISCALL GetFFItemType(u8 *self) {
  u8 forced = 0;
  if (F32(self, 0x417) & 0x2000000) {
    forced = 1;
    F32(self, 0x654) = 9;
  }
  u8 was = F8(self, 0x65c);
  F8(self, 0x65c) = forced;
  if (!forced) {
    void *it = vcall<void *>(self, 0x504);
    if (it != FP(self, 0x658) || was) {
      FP(self, 0x658) = it;
      F32(self, 0x654) = 0;
      if (it) F32(self, 0x654) = ext_5aeff0(self + 0x95b, it);
    }
    if (vcall<bool>(self, 0x438)) F32(self, 0x654) = 0;
  }
  return F32(self, 0x654);
}
PCREG(591b20, GetFFItemType);

// ZFFHERO::GetCurrentUBAnim() [high, GameCube reference]: the hero's upper-body clip by held weapon. Weapon type from
// item->vt[0x350]()->vt[0x330]() (template -> weapon type; HBM WEAPONTYPE names, inference: 0 pistol, 1 revolver,
// 2 SMG, 3 MG, 4 rifle, 5 pump gun, 6 shotgun):
//   0, 1 -> +0x79c;  2..6 -> +0x790 if flag 0x400 in +0x417, else +0x794 if flag 2, else +0x78c;
//   7 -> +0x798;  11 -> +0x7a0;  12 -> +0x7a4;  8..10 and > 12 -> none.
// Not a weapon (IsDerivedFrom(0x1007d2) false): +0x7ac when GetFFItemType() == 16, else none.
static void *THISCALL ZFFHERO_GetCurrentUBAnim(u8 *self) {
  void *item = vcall<void *>(self, 0x504);
  if (!item) return 0;
  if (!vcall<bool>(item, 0x1e0, 0x1007d2)) {
    if (GetFFItemType(self) == 0x10) return FP(self, 0x7ac);
    return 0;
  }
  void *tmpl = vcall<void *>(item, 0x350);
  switch (vcall<u32>(tmpl, 0x330)) {
    case 0: case 1: return FP(self, 0x79c);
    case 2: case 3: case 4: case 5: case 6: {
      u32 f = F32(self, 0x417);
      if (f & 0x400) return FP(self, 0x790);
      if (f & 2) return FP(self, 0x794);
      return FP(self, 0x78c);
    }
    case 7: return FP(self, 0x798);
    case 11: return FP(self, 0x7a0);
    case 12: return FP(self, 0x7a4);
    default: return 0;
  }
}
PCREG(5919f0, ZFFHERO_GetCurrentUBAnim);
