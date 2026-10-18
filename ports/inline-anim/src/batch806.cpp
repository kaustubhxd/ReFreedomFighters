// batch806.cpp - animation layer thread, batch 806: ZIKHAND (hand IK + held item). PC layout (packed):
//   +0 vtable, +4 ZTARGET (0x4d bytes, batch 805), +0x51 dword, +0x56 hand bone id (byte), +0x5a item offset vec3.
// ZIKHAND vtable used: +8 (detach/release item(obj, 0); name from HBM order is a guess), +0x10 GetItem().
#include "ff.h"

#define F8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FF(p, o) (*(float *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

struct PMF { u32 w[4]; };

// ZIKHAND::GetItemType() const [medium, GC 801879fc]: item->GetItemTemplate() (vt 0x2e8) -> template vt 0x300.
static u32 THISCALL ZIKHAND_GetItemType(void *self) {
  void *item = vcall<void *>(self, 0x10);
  if (!item) return 0;
  void *tmpl = vcall<void *>(item, 0x2e8);
  if (!tmpl) return 0;
  return vcall<u32>(tmpl, 0x300);
}
PCREG(474410, ZIKHAND_GetItemType);

// ZIKHAND::Reset() [high, GC 80187e74].
extern "C" void THISCALL ext_466220(void *t);   // ZTARGET::Clear (batch 805)
static void THISCALL ZIKHAND_Reset(u8 *self) {
  ext_466220(self + 4);
  F32(self, 0x51) = 0;
}
PCREG(4752e0, ZIKHAND_Reset);

// ZIKHAND::SlipItem(ZIKLNKOBJ*) [medium, GC 80187ee8]: if holding an item, vt[8](obj, 0).
static void THISCALL ZIKHAND_SlipItem(void *self, void *obj) {
  if (vcall<void *>(self, 0x10)) vcall<void>(self, 8, obj, 0);
}
PCREG(475a80, ZIKHAND_SlipItem);

// ZIKHAND::SetTarget(ZIKLNKOBJ* obj, const float* mat, const float* pos, float time, callback) [high, GC 80187a84]:
// fire any pending callback of the old target, then set matrix/position (geom 0), callback, blend time (in) and
// enable the target.
extern "C" void THISCALL ext_4658d0(void *t, void *obj);                          // ZTARGET::CallBackAndRemove
extern "C" void THISCALL ext_467aa0(void *t, const float *m, const float *p, u32 g); // ZTARGET::SetMatPosGeom
extern "C" void THISCALL ext_4678e0(void *t, PMF cb);                              // ZTARGET::SetCallBack
extern "C" void THISCALL ext_467b00(void *t, float T, u32 out);                    // ZTARGET::SetTime
extern "C" u8 THISCALL ext_466600(void *t, u32 on);                                // ZTARGET::Enable
static void THISCALL ZIKHAND_SetTarget(u8 *self, void *obj, const float *mat, const float *pos, float time, PMF cb) {
  u8 *t = self + 4;
  ext_4658d0(t, obj);
  ext_467aa0(t, mat, pos, 0);
  ext_4678e0(t, cb);
  ext_467b00(t, time, 0);
  ext_466600(t, 1);
}
PCREG(475a20, ZIKHAND_SetTarget);

// ZIKHAND::PlaceItem(ZIKLNKOBJ* obj, ZItem* item) [high, GC 80187b10]: put the item in the hand bone.
//   obj->vt[0x390](obj->vt[0x2b4](hand bone +0x56, M, P))   (bone matrix/position; result passed on)
//   obj->vt[0x98](M, P)                                     (to world space)
//   item->vt[0x20]()->vt[0x94](M, P)                        (item geometry's attach transform)
//   P += M * offset(+0x5a)  (vmmul 0x441970)
//   item->vt[0x2d4](M, P)                                   (set item matrix/position)
extern "C" void FASTCALL ext_441970(float *out, const float *v, const float *m);  // vmmul (out = v * m)
extern "C" void FASTCALL ext_441940(float *dst, const float *src);                // PSVECAdd
static void THISCALL ZIKHAND_PlaceItem(u8 *self, void *obj, void *item) {
  float M[9], P[3], T[4];
  u8 *vt = *(u8 **)obj;
  u32 b = (*(u32(THISCALL **)(void *, u32, float *, float *))(vt + 0x2b4))(obj, F8(self, 0x56), M, P);
  (*(void(THISCALL **)(void *, u32))(vt + 0x390))(obj, b);
  vcall<void>(obj, 0x98, M, P);
  void *g = vcall<void *>(item, 0x20);
  vcall<void>(g, 0x94, M, P);
  ext_441970(T, (float *)(self + 0x5a), M);
  ext_441940(P, T);
  vcall<void>(item, 0x2d4, M, P);
}
PCREG(474eb0, ZIKHAND_PlaceItem);
