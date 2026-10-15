// batch505.cpp - weapons thread, batch 505: aiming and firing at a point. ZLNKWHANDS::SetAimTarget (full form),
// ZLNKWHANDS::RemoveAimTarget and ZFFHERO::FireWeaponAtPos. ZTARGET methods run as exe code (lifted in batch 504).
// More ZLNKWHANDS fields: +0x6c animation object (its +0x255 float = aim blend time), +0x3bc float[3] aim point,
// +0x3c8 float[3] cached aim point, +0x3d4 float[3] (cleared on a new target; guess: aim velocity),
// +0x3e4 float muzzle velocity of the held weapon (10000 with none).
// ZFFHERO fields: +0x7f0 u8 firing at a point, +0x813 float fire start time (s), +0x829 float aim blend time,
// +0x85a camera helper (ZCamHelper; +0xb45 byte = aim-assist lock).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vU0)(void *self);
typedef u32(THISCALL *vUU)(void *self, u32 a);
typedef long double(THISCALL *vLD0)(void *self);
struct PMF { u32 fn, adj, vb, vi; };
typedef void(THISCALL *vSetAimPos)(void *self, const float *pos, float t, PMF cb);

extern "C" u32 THISCALL ext_4666d0(u8 *t);                                    // ZTARGET::Geom
extern "C" u8 THISCALL ext_466cd0(u8 *t);                                     // ZTARGET enabled
extern "C" u8 THISCALL ext_467700(u8 *t);                                     // ZTARGET::Removing
extern "C" void THISCALL ext_467aa0(u8 *t, const float *m, const float *p, u32 g);   // SetMatPosGeom
extern "C" void THISCALL ext_4678e0(u8 *t, PMF cb);                           // SetCallBack
extern "C" void THISCALL ext_467b00(u8 *t, float time, u8 removing);          // SetTime
extern "C" u8 THISCALL ext_466600(u8 *t, u8 on);                              // Enable
extern "C" u8 THISCALL ext_4669c0(u8 *t, float *out);                         // GetPos
extern "C" PMF *THISCALL ext_4667e0(u8 *t, PMF *out);                         // GetCallBack

// 0x4754e0 ZLNKWHANDS::SetAimTarget(geom, pos, time, cb), ret 0x1c. Nothing while aiming is disabled (+0x3e8).
// With a live geom the aim point is pos taken through the geom's GetRootPoint (slot 0x84); a new geom resets the
// cached point. A target that is already this geom (enabled, not blending out) only clears IK flag 0x400000.
// Otherwise the target is set (pos, geom, callback), blended in over `time` unless it is already showing, enabled,
// and the held weapon (slot 0x50c) gets the target point (SetTarget, slot 0x32c) and its muzzle velocity is kept.
static void THISCALL setAimTarget(u8 *self, u32 geom, const float *pos, float time, PMF cb) {
  if (self[0x3e8])
    return;
  *(float *)(*(u8 **)(self + 0x6c) + 0x255) = time;
  u8 *t = self + 0x26a;
  u8 *o = 0;
  if (geom) {
    u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    o = (u8 *)((vUU)VT(rm, 0x58))(rm, geom);
  }
  if (o) {
    u32 *a = (u32 *)(self + 0x3bc);
    a[0] = ((const u32 *)pos)[0];
    a[1] = ((const u32 *)pos)[1];
    a[2] = ((const u32 *)pos)[2];
    ((vUU)VT(o, 0x84))(o, (u32)a);
    if (ext_4666d0(t) != geom) {
      *(u32 *)(self + 0x3d4) = 0;
      *(u32 *)(self + 0x3d8) = 0;
      *(u32 *)(self + 0x3dc) = 0;
      *(u32 *)(self + 0x3c8) = *(u32 *)(self + 0x3bc);
      *(u32 *)(self + 0x3cc) = *(u32 *)(self + 0x3c0);
      *(u32 *)(self + 0x3d0) = *(u32 *)(self + 0x3c4);
    }
  } else if (!ext_466cd0(t)) {
    *(u32 *)(self + 0x3bc) = ((const u32 *)pos)[0];
    *(u32 *)(self + 0x3c0) = ((const u32 *)pos)[1];
    *(u32 *)(self + 0x3c4) = ((const u32 *)pos)[2];
  }
  if (ext_466cd0(t) && !ext_467700(t) && geom && ext_4666d0(t) == geom) {
    *(u32 *)(self + 0x136) &= 0xffbfffffu;
    return;
  }
  *(u32 *)(self + 0x136) &= 0xffbfffffu;
  ext_467aa0(t, 0, pos, geom);
  ext_4678e0(t, cb);
  if (!ext_466cd0(t) || ext_467700(t))
    ext_467b00(t, time, 0);
  ext_466600(t, 1);
  u8 *w = (u8 *)((vU0)VT(self, 0x50c))(self);
  if (!w) {
    *(u32 *)(self + 0x3e4) = 0x461c4000;   // 10000.0f
    return;
  }
  float p[3];
  if (ext_4669c0(t, p)) {
    ((vUU)VT(self, 0x84))(self, (u32)p);
    ((vUU)VT(w, 0x32c))(w, (u32)p);
  }
  u8 *tm = (u8 *)((vU0)VT(w, 0x350))(w);
  *(float *)(self + 0x3e4) = (float)((vLD0)VT(tm, 0x344))(tm);
}
PCREG(4754e0, setAimTarget);

// 0x475140 ZLNKWHANDS::RemoveAimTarget(time, cb), ret 0x14. Nothing while aiming is disabled. The blend-out time is
// 0 when the left-hand bone control (GetBoneControl(LHandBoneIndex()), slots 0x320 / 0x3b0) has bit 0x100. The held
// weapon's target is cleared to (0, 0, 0); the callback is stored. Time 0: blend out at once and UpdateAimTarget
// (slot 0x4a8); otherwise start blending out unless already doing so.
static void THISCALL removeAimTarget(u8 *self, float time, PMF cb) {
  if (self[0x3e8])
    return;
  u32 bone = ((vU0)VT(self, 0x3b0))(self);
  float t = (((vUU)VT(self, 0x320))(self, bone) & 0x100) ? 0.0f : time;
  u8 *w = (u8 *)((vU0)VT(self, 0x50c))(self);
  if (w) {
    float z[3] = {0.0f, 0.0f, 0.0f};
    ((vUU)VT(w, 0x32c))(w, (u32)z);
  }
  u8 *tg = self + 0x26a;
  ext_4678e0(tg, cb);
  if (t == 0.0f) {
    ext_467b00(tg, 0.0f, 1);
    ((vU0)VT(self, 0x4a8))(self);
    return;
  }
  if (!ext_467700(tg))
    ext_467b00(tg, t, 1);
}
PCREG(475140, removeAimTarget);

// 0x591710 ZFFHERO::FireWeaponAtPos(float* pos), ret 4: with a weapon in the right hand (slot 0x50c), its +0xcd
// (float; guess: spread factor) is 0.5 under an aim-assist lock (camera helper +0xb45) and 1.0 otherwise. The first
// call starts firing at the point (+0x7f0 = 1, start time +0x813 = now) and aims at it through SetAimTarget (slot
// 0x4b0) with the callback at 0x58b737; later calls move the aim target to the point and stop (+0x7f0 = 0) once the
// target's callback is set (the aim has reached the point).
static void THISCALL fireWeaponAtPos(u8 *self, float *pos) {
  u8 *w = (u8 *)((vU0)VT(self, 0x50c))(self);
  if (!w)
    return;
  u8 *cam = *(u8 **)(self + 0x85a);
  *(u32 *)(w + 0xcd) = cam[0xb45] ? 0x3f000000u : 0x3f800000u;
  if (!self[0x7f0]) {
    self[0x7f0] = 1;
    *(float *)(self + 0x813) = (float)*(s32 *)(G(u8 *, 0x70039c) + 0x40) * 0.0009765625f;
    ((vUU)VT(self, 0x8c))(self, (u32)pos);
    ((vSetAimPos)VT(self, 0x4b0))(self, pos, *(float *)(self + 0x829), PMF{0x58b737, 0, 0, 0});
    return;
  }
  ((vUU)VT(self, 0x8c))(self, (u32)pos);
  ext_467aa0(self + 0x26a, 0, pos, 0);
  PMF cb;
  if (ext_4667e0(self + 0x26a, &cb)->fn)
    self[0x7f0] = 0;
}
PCREG(591710, fireWeaponAtPos);
