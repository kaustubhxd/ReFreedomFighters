// batch50.cpp - shoot tree (ZCamHelper aim helpers under GetFireAimPos), inline session batch 50.
// "cam" is the ZCamHelper object; its +0x44 is the hero, +0xb54 the camera.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef void(THISCALL *vcallP)(void *self, float *p);
typedef double(THISCALL *vcallF0)(void *self);            // result in ST0
typedef u32(THISCALL *vcallUP)(void *self, float *p);
typedef void(THISCALL *vcallVU)(void *self, u32 a);
typedef u32(THISCALL *vcallUU)(void *self, u32 a);
typedef u8(THISCALL *vcallBU)(void *self, u32 a);
typedef u8(THISCALL *vcallRay)(void *self, void *coli, u32 a, u32 b, u32 c, u32 d, u32 e);

extern "C" void THISCALL ext_4e0d80(float *v, float len);                          // vsetlen (batch 31)
extern "C" void FASTCALL ext_441940(float *dst, const float *src);                 // PSVECAdd (batch 34)
extern "C" void THISCALL ext_4e09b0(float *v);                                     // vneg (batch 29)
extern "C" void FASTCALL ext_43e920(float *dst, const float *src, const float *a); // PSVECSubtract (batch 34)
extern "C" float FASTCALL ext_4e0030(const float *a, const float *b);              // vangle, ST0
extern "C" void THISCALL ext_4e1b60(u8 *coli);                                     // COLI::COLI

// 0x5cf420, thiscall, ret 4. The aim origin. Camera mode 5 (+0xad5): the camera's slot 0x94 writes out, then out moves
// along the view direction (+0xa72) by the camera's slot 0xac + 150. Otherwise, mode +0xa4c == 1: the hero's position
// (slots 0x3a8, 0x398, 0x84). Otherwise the camera's slot 0x94 alone.
static void THISCALL aimOrigin(u8 *cam, float *out) {
  if (*(u32 *)(cam + 0xad5) == 5) {
    u8 *c = *(u8 **)(cam + 0xb54);
    ((vcallP)VT(c, 0x94))(c, out);
    float dir[3] = {*(float *)(cam + 0xa72), *(float *)(cam + 0xa76), *(float *)(cam + 0xa7a)};
    c = *(u8 **)(cam + 0xb54);
    double d = ((vcallF0)VT(c, 0xac))(c);
    ext_4e0d80(dir, (float)(d + 150.0));
    ext_441940(out, dir);
    return;
  }
  if (*(u32 *)(cam + 0xa4c) == 1) {
    u8 *h = *(u8 **)(cam + 0x44);
    void **hvt = *(void ***)h;
    u32 m = ((vcallUP)hvt[0x3a8 / 4])(h, out);
    ((vcallVU)hvt[0x398 / 4])(h, m);
    ((vcallP)VT(h, 0x84))(h, out);
    return;
  }
  u8 *c = *(u8 **)(cam + 0xb54);
  ((vcallP)VT(c, 0x94))(c, out);
}
PCREG(5cf420, aimOrigin);

// 0x5d2630, thiscall, ret 4. Locks the aim onto a target handle: +0xd0d = 0; if the handle resolves (render-manager
// slot 0x58) to an object whose slot 0x1e0(0x200074) is true, its position goes to +0xd15 (slots 0x3a8, 0x398, 0x84)
// and the handle to +0xd0d.
static void THISCALL setAimTarget(u8 *cam, u32 handle) {
  *(u32 *)(cam + 0xd0d) = 0;
  if (!handle)
    return;
  u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = (u8 *)((vcallUU)VT(rm, 0x58))(rm, handle);
  if (!o)
    return;
  if (!((vcallBU)VT(o, 0x1e0))(o, 0x200074))
    return;
  float *pos = (float *)(cam + 0xd15);
  void **ovt = *(void ***)o;
  u32 m = ((vcallUP)ovt[0x3a8 / 4])(o, pos);
  ((vcallVU)ovt[0x398 / 4])(o, m);
  ((vcallP)VT(o, 0x84))(o, pos);
  *(u32 *)(cam + 0xd0d) = handle;
}
PCREG(5d2630, setAimTarget);

extern "C" void THISCALL ext_5cf420(u8 *cam, float *out);
// 0x5cf520, thiscall, ret 4, result in ST0: the angle between the aim direction and (p - aim origin). The aim
// direction is -(+0xcdd) when +0xa4c == 1, else +0xa72.
static float THISCALL aimAngleTo(u8 *cam, const float *p) {
  float org[3], dir[3], d[3];
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
  ext_43e920(d, p, org);
  return ext_4e0030(d, dir);
}
PCREG(5cf520, aimAngleTo);

// 0x5cd750, thiscall, ret 4, result in al: true when the ray from +0xd22 to p is clear. Builds a COLI (from, dir =
// p - from, byte +0x6c = 0) and casts it with slot 0x2e0 of the collision world at [[0x70039c]+0x9b]+0xadc,
// args (coli, 0, 0x10, 0x200000, 1, 0); returns !hit.
static u8 THISCALL rayClear(u8 *cam, const float *p) {
  u8 coli[0x70];
  ext_4e1b60(coli);
  float *from = (float *)(cam + 0xd22);
  ((float *)coli)[0] = from[0];
  ((float *)coli)[1] = from[1];
  ((float *)coli)[2] = from[2];
  ext_43e920((float *)(coli + 0xc), p, from);
  coli[0x6c] = 0;
  u8 *w = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xadc);
  u8 hit = ((vcallRay)VT(w, 0x2e0))(w, coli, 0, 0x10, 0x200000, 1, 0);
  return hit == 0;
}
PCREG(5cd750, rayClear);
