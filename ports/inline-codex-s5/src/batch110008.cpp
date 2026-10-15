// batch1017.cpp - ZCamHelper: SetFocusSystemOni, ControlBody, ControlA. Camera thread, 2026-10-11.
#include "ff.h"
template<class T> static T& at(void*p,u32 o){return *(T*)((u8*)p+o);}
static void*ptr(void*p,u32 o){return at<void*>(p,o);}

extern "C" FASTCALL void ext_4de040(float *m33, const float *dir, const float *up);  // createmat
extern "C" FASTCALL void ext_43e960(float *v, const float *a);   // v -= a
extern "C" FASTCALL void ext_441a60(float *v, const float *m);   // vmtmul
extern "C" FASTCALL void ext_4419f0(float *v, const float *m);   // vmmul
extern "C" FASTCALL void ext_441940(float *v, const float *a);   // v += a
extern "C" FASTCALL void ext_4de420(float *d, const float *s);   // mcpy
extern "C" THISCALL void ext_5cf420(void *self, float *out);     // GetAimOrigin (batch1016)
extern "C" THISCALL void ext_5ceb30(void *self);  // ControlMouse
extern "C" THISCALL void ext_5ceb70(void *self);  // ControlOni
extern "C" THISCALL void ext_5cdab0(void *self);  // ControlA
extern "C" THISCALL void ext_5cff20(void *self);  // (unnamed) hero busy step
extern "C" THISCALL void ext_5d0080(void *self);  // leave-aim reset (batch1010)
extern "C" THISCALL void ext_5cecd0(void *self);  // DoMoveFocus (batch1014)
extern "C" THISCALL void ext_5d0c90(void *self);  // MovePointerA
extern "C" THISCALL void ext_5d0f10(void *self);  // MovePointerOni
extern "C" THISCALL void ext_5d2eb0(void *self);  // UpdatePointerMode (batch1011)
extern "C" THISCALL void ext_5d2ab0(void *self);  // UpdateFocusAngleOni
extern "C" THISCALL void ext_5d1530(void *self);  // RestrictPointerAngle (batch1012)
extern "C" THISCALL void ext_5d2280(void *self);  // SetPointerOnScreenOni
extern "C" THISCALL void ext_5cd890(void *self);  // CheckResetPointerAndFocusOni
extern "C" THISCALL void ext_5cdc60(void *self);  // ControlBodyA
extern "C" THISCALL void ext_5ce0b0(void *self);  // ControlBodyOni
extern "C" THISCALL void ext_5d2080(void *self);  // SetFocusSystemOni

// 0x5d2080 ZCamHelper::SetFocusSystemOni(): as SetFocusSystemMouse (batch1012) but in hero stance 0x400 the
// look-up shift is pitch*25 instead of pitch*15.
static THISCALL void ZCamHelper_SetFocusSystemOni(void *self) {
  float p[3];
  vcall<void>(ptr(self, 0x44), 0x378, p);
  vcall<void>(ptr(self, 0x44), 0x84, p);
  float d[3] = {at<float>(self, 0xc89), 0.0f, at<float>(self, 0xc91)};
  float m[9];
  ext_4de040(m, d, 0);
  float *fpos = &at<float>(self, 0xc71);
  ext_43e960(p, fpos);
  ext_441a60(p, m);
  float pitch = at<float>(self, 0xaed);
  float k;
  if (at<u32>(ptr(self, 0x44), 0x417) & 0x400)
    k = 0.0f > pitch ? pitch * G(float, 0x67da20) : pitch * G(float, 0x685270);
  else
    k = 0.0f > pitch ? pitch * G(float, 0x67da20) : pitch * G(float, 0x680a80);
  p[2] = p[2] - k;
  ext_4419f0(p, m);
  ext_441940(p, fpos);
  fpos[0] = p[0];
  fpos[1] = p[1];
  fpos[2] = p[2];
  if ((at<u32>(ptr(self, 0x44), 0x417) & 0x20000000) && G(float, 0x6a066c) > at<float>(self, 0xaed) &&
      G(float, 0x6b4fc0) > at<float>(ptr(self, 0xb54), 0x4aa)) {
    at<u32>(self, 0xaed) = 0x3d567750;
    at<u32>(self, 0xa5c) = 0x3d567750;
  }
  double cp = crt::cos((double)at<float>(self, 0xaed));
  float dir[3];
  dir[0] = (float)(crt::cos((double)at<float>(self, 0xae9)) * cp);
  dir[1] = (float)crt::sin((double)at<float>(self, 0xaed));
  dir[2] = (float)(crt::sin((double)at<float>(self, 0xae9)) * cp);
  float m2[9];
  ext_4de040(m2, dir, 0);
  ext_4de420(&at<float>(self, 0xc89), m2);
}
PCREG(5d2080, ZCamHelper_SetFocusSystemOni);

