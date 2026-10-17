// batch504.cpp - weapons thread, batch 504: ZTARGET (the aim/IK target with a blend timer) and the small aim
// functions of ZLNKWHANDS, plus ZFFHERO::SetHoldFire.
// ZTARGET layout (PC, byte-packed, 0x4d bytes): +0x00 u8 enabled, +0x01 float[9] matrix (dword 0x7fffffff = none),
// +0x25 float[3] position (x dword 0x7fffffff = none), +0x31 float blend duration (s), +0x35 float blend start
// time (s; negative = blending out, "removing"), +0x39 u32 geom handle, +0x3d 16-byte callback (MSVC member-function
// pointer: code, this-adjust, vbase, vindex; "none" is {0, 0, 0, -1}).
// ZLNKWHANDS aim fields: +0x26a ZTARGET aim target, +0x136 IK flags, +0x1e2 float aim blend, +0x3c8 float[3]
// cached aim point, +0x3e8 u8 aim disabled, +0x3e9 u8 aim in position.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vU0)(void *self);
typedef u32(THISCALL *vUU)(void *self, u32 a);
typedef void(THISCALL *vCB)(void *self);
struct PMF { u32 fn, adj, vb, vi; };
typedef void(THISCALL *vSetAim)(void *self, u32 geom, const float *pos, float t, PMF cb);
typedef void(THISCALL *vRemAim)(void *self, float t, PMF cb);

extern "C" void FASTCALL ext_4de7a0(float *m);                // mreset (identity)
extern "C" void FASTCALL ext_4de420(float *d, const float *s);  // mcpy (9 floats)
extern "C" void THISCALL ext_465930(u8 *t, void *obj);          // ZTARGET::Update body (not lifted yet)

static inline s32 ticks() { return *(s32 *)(G(u8 *, 0x70039c) + 0x40); }

// ---------------------------------------------------------------------------------------------- ZTARGET
static u8 THISCALL tIsEnabled(u8 *t) { return t[0]; }   // 0x466cd0 (no GC name; guess IsEnabled)
PCREG(466cd0, tIsEnabled);
static u8 THISCALL tEnable(u8 *t, u8 on) { u8 old = t[0]; t[0] = on; return old; }
PCREG(466600, tEnable);
static u32 THISCALL tGeom(u8 *t) { return *(u32 *)(t + 0x39); }
PCREG(4666d0, tGeom);
static u32 THISCALL tPos(u8 *t) { return *(u32 *)(t + 0x25) == 0x7fffffff ? 0 : (u32)(t + 0x25); }
PCREG(4673c0, tPos);
static u8 THISCALL tRemoving(u8 *t) { return *(float *)(t + 0x35) < 0.0f || __builtin_isnan(*(float *)(t + 0x35)); }
PCREG(467700, tRemoving);
static u8 THISCALL tGetPos(u8 *t, u32 *out) {
  if (*(u32 *)(t + 0x25) == 0x7fffffff)
    return 0;
  out[0] = *(u32 *)(t + 0x25);
  out[1] = *(u32 *)(t + 0x29);
  out[2] = *(u32 *)(t + 0x2d);
  return 1;
}
PCREG(4669c0, tGetPos);
static void THISCALL tSetCallBack(u8 *t, PMF cb) { *(PMF *)(t + 0x3d) = cb; }
PCREG(4678e0, tSetCallBack);
static u32 THISCALL tGetCallBack(u8 *t, PMF *out) { *out = *(PMF *)(t + 0x3d); return (u32)out; }
PCREG(4667e0, tGetCallBack);

static void THISCALL tClear(u8 *t) {
  ext_4de7a0((float *)(t + 1));
  *(u32 *)(t + 0x25) = 0;
  *(u32 *)(t + 0x29) = 0;
  *(u32 *)(t + 0x2d) = 0;
  *(u32 *)(t + 0x39) = 0;
  *(u32 *)(t + 0x31) = 0;
  *(u32 *)(t + 0x35) = 0;
  *(PMF *)(t + 0x3d) = PMF{0, 0, 0, 0xffffffffu};
  t[0] = 0;
}
PCREG(466220, tClear);
static u32 THISCALL tCtor(u8 *t) { tClear(t); return (u32)t; }   // 0x465650 ZTARGET::ZTARGET()
PCREG(465650, tCtor);

// 0x467aa0 SetMatPosGeom(mat, pos, geom): null mat / pos store the "none" marker 0x7fffffff.
static void THISCALL tSetMatPosGeom(u8 *t, const float *mat, const u32 *pos, u32 geom) {
  if (mat)
    ext_4de420((float *)(t + 1), mat);
  else
    *(u32 *)(t + 1) = 0x7fffffff;
  if (pos) {
    *(u32 *)(t + 0x25) = pos[0];
    *(u32 *)(t + 0x29) = pos[1];
    *(u32 *)(t + 0x2d) = pos[2];
  } else {
    *(u32 *)(t + 0x25) = 0x7fffffff;
  }
  *(u32 *)(t + 0x39) = geom;
}
PCREG(467aa0, tSetMatPosGeom);

// 0x467cd0 Update(obj): only when enabled (tail call to 0x465930).
static void THISCALL tUpdate(u8 *t, void *obj) {
  if (t[0])
    ext_465930(t, obj);
}
PCREG(467cd0, tUpdate);

// 0x4658d0 CallBackAndRemove(obj): while a callback is set, clear it and call it on obj + this-adjust.
static void THISCALL tCallBackAndRemove(u8 *t, u8 *obj) {
  for (;;) {
    PMF cb = *(PMF *)(t + 0x3d);
    if (!cb.fn)
      return;
    *(PMF *)(t + 0x3d) = PMF{0, 0, 0, 0xffffffffu};
    ((vCB)cb.fn)(obj + cb.adj);
  }
}
PCREG(4658d0, tCallBackAndRemove);

// 0x467b00 SetTime(time, removing): re-times the blend so that the current blend weight is kept. The weight now
// (0..1) is elapsed/duration while blending in (start >= 0), 1 - elapsed/duration while blending out (0 once
// elapsed > duration or with duration 0), 1 when blending in is complete. The new start is chosen so that the new
// duration `time` gives the same weight; `removing` makes it a blend out (negative stamp) and clears the geom.
static void THISCALL tSetTime(u8 *t, float time, u8 removing) {
  float start = *(float *)(t + 0x35);
  float dur = *(float *)(t + 0x31);
  float ab = (float)__builtin_fabs((double)start);
  s32 e = ticks() - _mm_cvttss_si32(_mm_set_ss(ab * 1024.0f));
  float el = (float)e * 0.0009765625f;
  float w;
  if (start >= 0.0f) {
    if (dur > el)
      w = el / dur;
    else
      w = 1.0f;
  } else {
    w = 0.0f;
    if (!(el > dur) && dur != 0.0f)
      w = 1.0f - el / dur;
  }
  *(float *)(t + 0x31) = time;
  if (w == 1.0f) {
    if (removing) {
      *(u32 *)(t + 0x39) = 0;
      *(float *)(t + 0x35) = (float)(s32)(0u - (u32)ticks()) * 0.0009765625f;
    } else {
      *(float *)(t + 0x35) = (float)ticks() * 0.0009765625f;
    }
    return;
  }
  if (removing) {
    *(u32 *)(t + 0x39) = 0;
    float a = (1.0f - w) * time * -1024.0f;
    u32 v = (0u - (u32)ticks()) - (u32)_mm_cvttss_si32(_mm_set_ss(a));
    *(float *)(t + 0x35) = (float)(s32)v * 0.0009765625f;
  } else {
    float a = w * time * 1024.0f;
    u32 v = (u32)ticks() - (u32)_mm_cvttss_si32(_mm_set_ss(a));
    *(float *)(t + 0x35) = (float)(s32)v * 0.0009765625f;
  }
}
PCREG(467b00, tSetTime);

// ---------------------------------------------------------------------------------------------- ZLNKWHANDS aim
// 0x475710 SetAimTarget(pos, time, cb): the general SetAimTarget (own slot 0x4ac) with geom 0.
static void THISCALL hSetAimTargetPos(u8 *self, const float *pos, float time, PMF cb) {
  ((vSetAim)VT(self, 0x4ac))(self, 0, pos, time, cb);
}
PCREG(475710, hSetAimTargetPos);
static u32 THISCALL hGetAimTargetGeom(u8 *self) { return *(u32 *)(self + 0x26a + 0x39); }   // 0x473fb0
PCREG(473fb0, hGetAimTargetGeom);
static u8 THISCALL hGetAimTargetHandle(u8 *self, u32 *out) {   // 0x473fc0
  u32 g = *(u32 *)(self + 0x26a + 0x39);
  *out = g;
  return g != 0;
}
PCREG(473fc0, hGetAimTargetHandle);

// 0x473f20 GetAimTarget(float* out): a live target geom gives the cached aim point (+0x3c8); otherwise a target
// position is copied and transformed by own slot 0x84 (ZGEOM::GetRootPoint); false with neither.
static u8 THISCALL hGetAimTargetPos(u8 *self, u32 *out) {
  u32 g = *(u32 *)(self + 0x26a + 0x39);
  if (g) {
    u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    if (((vUU)VT(rm, 0x58))(rm, g)) {
      out[0] = *(u32 *)(self + 0x3c8);
      out[1] = *(u32 *)(self + 0x3cc);
      out[2] = *(u32 *)(self + 0x3d0);
      return 1;
    }
  }
  u32 *p = (u32 *)tPos(self + 0x26a);
  if (!p)
    return 0;
  out[0] = p[0];
  out[1] = p[1];
  out[2] = p[2];
  ((vUU)VT(self, 0x84))(self, (u32)out);
  return 1;
}
PCREG(473f20, hGetAimTargetPos);

static u8 THISCALL hIsAiming(u8 *self) {   // 0x4746d0: target enabled and not blending out
  u8 *t = self + 0x26a;
  return t[0] && !tRemoving(t);
}
PCREG(4746d0, hIsAiming);
static void THISCALL hDisableAim(u8 *self) {   // 0x473a10: RemoveAimTarget(0, none) (slot 0x4b4), then disabled
  ((vRemAim)VT(self, 0x4b4))(self, 0.0f, PMF{0, 0, 0, 0xffffffffu});
  self[0x3e8] = 1;
}
PCREG(473a10, hDisableAim);
static void THISCALL hEnableAim(u8 *self) { self[0x3e8] = 0; }
PCREG(473b40, hEnableAim);
static void THISCALL hFreezeAimTarget(u8 *self) {
  if (self[0x26a])
    *(u32 *)(self + 0x136) |= 0x400000;
}
PCREG(473e30, hFreezeAimTarget);
static void THISCALL hSetAimInPosition(u8 *self, u8 on) { self[0x3e9] = on; }
PCREG(4754d0, hSetAimInPosition);
// 0x473b50 FireShotNotify(): a shot snaps the aim blend (+0x1e2) to 1 when it is below 0.3.
static void THISCALL hFireShotNotify(u8 *self) {
  if (0.3f > *(float *)(self + 0x1e2))
    *(float *)(self + 0x1e2) = 1.0f;
}
PCREG(473b50, hFireShotNotify);

// 0x594f10 ZFFHERO::SetHoldFire(bool): fire button state +0x669; pressing it also sets +0x66b ("pressed this frame").
static void THISCALL heroSetHoldFire(u8 *self, u8 on) {
  if (self[0x669] == on)
    return;
  self[0x669] = on;
  if (on)
    self[0x66b] = 1;
}
PCREG(594f10, heroSetHoldFire);
