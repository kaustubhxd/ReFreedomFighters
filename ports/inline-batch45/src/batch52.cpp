// batch52.cpp - shoot tree, inline session batch 52: ZCamHelper::Find3DPointerPos and ZCamHelper::GetFireAimPos.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u8(THISCALL *vcallRay)(void *self, void *coli, u32 a, u32 mask, u32 b, u32 c, u32 d);
typedef double(THISCALL *vcallF0)(void *self);   // result in ST0

extern "C" void FASTCALL ext_43e8e0(float *dst, const float *a, const float *b);   // dst = a + b (math1)
extern "C" void THISCALL ext_4dc630(u8 *geom, u32 set, u32 clear);                 // ZBaseGeom::SetControl
extern "C" u8 THISCALL ext_5cf110(u8 *cam);                                       // pick aim target (batch 51)
extern "C" void THISCALL ext_5d2630(u8 *cam, u32 handle);                          // set aim target (batch 50)
extern "C" void THISCALL ext_5cf420(u8 *cam, float *out);                          // aim origin (batch 50)
extern "C" void THISCALL ext_4e09b0(float *v);                                     // vneg (batch 29)
extern "C" void THISCALL ext_4e0d80(float *v, float len);                          // vsetlen (batch 31)
extern "C" u32 THISCALL ext_5ceed0(u8 *cam, float *out, const float *from, const float *dir, u32 mask, u32 b1, u32 b2);

// 0x5ceed0 ZCamHelper::Find3DPointerPos(float *out, float *from, float *dir, int mask, bool, bool), thiscall,
// ret 0x18, eax. Casts the COLI embedded at +0xb5b (from, dir, +0x34 = 1.0, byte +0x6c = 1) with the hero's geom
// flags in mask cleared for the cast (SetControl before and after). out = from + dir, or the hit point (COLI +0x28) on
// a hit; returns COLI +0x44 on a hit, else 0.
static u32 THISCALL find3DPointerPos(u8 *cam, float *out, const float *from, const float *dir, u32 mask, u32 b1, u32 b2) {
  u32 result = 0;
  u8 *hero = *(u8 **)(cam + 0x44);
  float *cf = (float *)(cam + 0xb5b);
  *(u32 *)(cam + 0xb8f) = 0x3f800000u;
  cam[0xbc7] = 1;
  cf[0] = from[0];
  cf[1] = from[1];
  cf[2] = from[2];
  float *cd = (float *)(cam + 0xb67);
  cd[0] = dir[0];
  cd[1] = dir[1];
  cd[2] = dir[2];
  ext_43e8e0(out, from, cd);
  u8 *geom = *(u8 **)(hero + 8);
  u32 saved = *(u32 *)(geom + 0x3c) & mask;
  ext_4dc630(geom, 0, mask);
  u8 *w = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xadc);
  if (((vcallRay)VT(w, 0x2e0))(w, cf, 0, mask, 0xffffffffu, b1, b2)) {
    out[0] = *(float *)(cam + 0xb83);
    out[1] = *(float *)(cam + 0xb87);
    out[2] = *(float *)(cam + 0xb8b);
    result = *(u32 *)(cam + 0xb9f);
  }
  ext_4dc630(*(u8 **)(hero + 8), saved, 0);
  return result;
}
PCREG(5ceed0, find3DPointerPos);

// 0x5cf690 ZCamHelper::GetFireAimPos(float *out), thiscall, ret 4. With aim assist on (byte +0xd32), the team mask
// +0xb50 comes from the hero's team record, and a picked target is locked. A locked target's position (+0xd15) is the
// aim point. Otherwise a ray from the aim origin along the aim direction, 10000 long plus the camera's slot 0xac
// (20000 with byte +0xb45 set in camera mode 4), finds the point (+0xa7e).
static void THISCALL getFireAimPos(u8 *cam, float *out) {
  if (cam[0xd32]) {
    *(u32 *)(cam + 0xb50) = *(u32 *)(*(u8 **)(*(u8 **)(cam + 0x44) + 0x54) + 0xc);
    if (ext_5cf110(cam))
      ext_5d2630(cam, *(u32 *)(cam + 0xd2e));
  }
  if (cam[0xd33]) {
    out[0] = *(float *)(cam + 0xd15);
    out[1] = *(float *)(cam + 0xd19);
    out[2] = *(float *)(cam + 0xd1d);
    return;
  }
  float org[3], dir[3];
  ext_5cf420(cam, org);
  if (*(u32 *)(cam + 0xa4c) == 1) {
    dir[0] = *(float *)(cam + 0xcdd);
    dir[1] = *(float *)(cam + 0xce1);
    dir[2] = *(float *)(cam + 0xce5);
    ext_4e09b0(dir);
  } else {
    dir[0] = *(float *)(cam + 0xa72);
    dir[1] = *(float *)(cam + 0xa76);
    dir[2] = *(float *)(cam + 0xa7a);
  }
  float range = 10000.0f;
  if (cam[0xb45] && *(u32 *)(cam + 0xad5) == 4)
    range = 20000.0f;
  u8 *c = *(u8 **)(cam + 0xb54);
  double d = ((vcallF0)VT(c, 0xac))(c);
  ext_4e0d80(dir, (float)(d + (double)range));
  float *p = (float *)(cam + 0xa7e);
  ext_5ceed0(cam, p, org, dir, 2, 1, 1);
  out[0] = p[0];
  out[1] = p[1];
  out[2] = p[2];
}
PCREG(5cf690, getFireAimPos);
