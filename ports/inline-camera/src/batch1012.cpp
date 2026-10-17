// batch1012.cpp - ZCamHelper::SetFocusSystemMouse (aim focus frame from yaw/pitch). Camera thread, 2026-10-11.
#include "cam.h"

extern "C" FASTCALL void ext_4de040(float *m33, const float *dir, const float *up);  // createmat
extern "C" FASTCALL void ext_43e960(float *v, const float *a);   // v -= a
extern "C" FASTCALL void ext_441a60(float *v, const float *m);   // vmtmul
extern "C" FASTCALL void ext_4419f0(float *v, const float *m);   // vmmul
extern "C" FASTCALL void ext_441940(float *v, const float *a);   // v += a
extern "C" FASTCALL void ext_4de420(float *d, const float *s);   // mcpy

// Focus frame of the aim: position +0xc71, matrix +0xc89 (rows; row 0 used as the facing). Aim angles: yaw
// +0xae9, pitch +0xaed (copies of the pointer yaw/pitch +0xa54/+0xa5c, see RestrictPointerAngle).
// 0x5d1ea0 ZCamHelper::SetFocusSystemMouse(): the focus position becomes the hero's aim point (hero slot 0x378,
// to world by slot 0x84), moved back along the horizontal facing by pitch*20 when aiming down or pitch*15 when
// aiming up. When hero flag 0x20000000 is set, the pitch is below 3 degrees and the camera's max distance is
// under 110 (camera squeezed), yaw and pitch pitch are forced to 3 degrees. The focus matrix is rebuilt to look
// along (cos p cos y, sin p, sin y cos p).
static THISCALL void ZCamHelper_SetFocusSystemMouse(void *self) {
  float p[3];
  void *hero = ptr(self, 0x44);
  vcall<void>(hero, 0x378, p);
  vcall<void>(hero, 0x84, p);
  float d[3] = {at<float>(self, 0xc89), 0.0f, at<float>(self, 0xc91)};
  float m[9];
  ext_4de040(m, d, 0);
  float *fpos = &at<float>(self, 0xc71);
  ext_43e960(p, fpos);
  ext_441a60(p, m);
  float pitch = at<float>(self, 0xaed);
  p[2] = p[2] - (0.0f > pitch ? pitch * G(float, 0x67da20) : pitch * G(float, 0x680a80));
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
PCREG(5d1ea0, ZCamHelper_SetFocusSystemMouse);

extern "C" THISCALL u32 ext_591b20(void *hero);                                        // ZFFHERO::GetFFItemType
extern "C" FASTCALL void ext_4e09b0(float *v);                                         // vneg
extern "C" FASTCALL u32 ext_4e0130(float *out, const float *from, const float *to, float maxang);  // vangpul
extern "C" THISCALL void ext_5cf820(void *self, float *yaw, float *pitch, const float *dir);      // ZCamHelper::GetPolarAngles

static inline float wrap_pi(float y) {
  if (y > G(float, 0x67da18))
    y = y - G(float, 0x68aef8);
  else if (G(float, 0x6ad238) > y)
    y = y + G(float, 0x68aef8);
  return y;
}

// 0x5d1530 ZCamHelper::RestrictPointerAngle(): only for item type 9 (a mounted machine gun; the limits come from
// the "MachinegunControlGroup" object of the hero's +0x84a). Otherwise it just arms +0xb1a. With the gun: the
// gun's facing is -(row 0) of its matrix (hero slot 0x80 -> +0xcdd). On the first frame (+0xb1a) the aim
// direction (+0xa72) is pulled toward the gun facing at 2*pi*dt rad per frame until reached, and yaw/pitch are
// taken from it. Afterwards the aim pitch is kept within -30..+18 degrees of the gun's pitch and the aim yaw
// within +-limit of the gun's yaw, limit = group +0x48 (180 if beyond +-179.9) or 20 degrees without a group.
static THISCALL void ZCamHelper_RestrictPointerAngle(void *self) {
  void *hero = ptr(self, 0x44);
  if (ext_591b20(hero) != 9) {
    at<u8>(self, 0xb1a) = 1;
    return;
  }
  float gyaw = 0.0f, gpitch, pos[3];
  float *gm = &at<float>(self, 0xcdd);
  vcall<void>(hero, 0x80, gm, pos);
  float d[3] = {gm[0], gm[1], gm[2]};
  ext_4e09b0(d);
  if (at<u8>(self, 0xb1a)) {
    at<u32>(self, 0xbd1) = 0;
    float *aim = &at<float>(self, 0xa72);
    u32 done = ext_4e0130(aim, aim, d, at<float>(G(u8 *, 0x70039c), 0x48) * G(float, 0x68aef8));
    float *yaw = &at<float>(self, 0xa54), *pitch = &at<float>(self, 0xa5c);
    ext_5cf820(self, yaw, pitch, aim);
    at<float>(self, 0xae9) = *yaw;
    at<u32>(self, 0xaed) = *(u32 *)pitch;
    if ((u8)done) at<u8>(self, 0xb1a) = 0;
    return;
  }
  ext_5cf820(self, &gyaw, &gpitch, d);
  float diff = at<float>(self, 0xa5c) - gpitch;
  if (G(float, 0x6a0bd0) > diff)
    at<float>(self, 0xa5c) = gpitch - G(float, 0x6a0bc8);
  else if (diff > G(float, 0x6b4fa4))
    at<float>(self, 0xa5c) = gpitch + G(float, 0x6b4fa4);
  float y = at<float>(self, 0xa54);
  if (gyaw > y) y = y + G(float, 0x68aef8);
  float dy = y - gyaw;
  if (G(float, 0x67af28) > dy) {  // "WARNING: AngleDist: %f" (angle.h line 0x8f)
    void *s = vcall<void *>(G(void *, 0x700390), 0x20, (const char *)0x6b4d68, 0x8fu);
    typedef void (*logfn)(void *, const char *, double);
    (*(logfn *)(*(u8 **)s + 0x2c))(s, (const char *)0x6b4db8, (double)dy);
  }
  dy = wrap_pi(dy);
  if (at<u32>(self, 0xbd1) == 0) {
    void *g = vcall<void *>(SYS9B, 0x58, at<u32>(hero, 0x84a));
    at<u32>(self, 0xbd1) = vcall<u32>(g, 0x100, (const char *)0x6b48f8);  // "MachinegunControlGroup"
  }
  u8 *grp = ptr(self, 0xbd1);
  float lim;
  const float pi = G(float, 0x67da18);
  if (grp) {
    lim = at<float>(grp, 0x48);
    if (lim > G(float, 0x6ad1fc))
      lim = pi;
    else if (G(float, 0x6ad234) > lim)
      lim = pi;
  } else {
    lim = G(float, 0x6b4fa8);  // 20 degrees
  }
  if (-lim > dy)
    at<float>(self, 0xa54) = wrap_pi(gyaw - lim);
  else if (dy > lim)
    at<float>(self, 0xa54) = wrap_pi(lim + gyaw);
}
PCREG(5d1530, ZCamHelper_RestrictPointerAngle);
