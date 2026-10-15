// batch1021.cpp - ZCamHelper: Find3DPointerShadowPos, StartRaisingFlag, Command, ActionInputs. Camera thread, 2026-10-11.
#include "cam.h"

extern "C" FASTCALL void ext_4e09b0(float *v);                  // vneg
extern "C" FASTCALL void ext_4e0d80(float *v, float len);       // vsetlen
extern "C" FASTCALL void ext_441940(float *v, const float *a);  // v += a
extern "C" FASTCALL void ext_4419f0(float *v, const float *m);  // vmmul
extern "C" THISCALL void ext_5cd7f0(void *self, float *pos, float *dir, float t, u32 mode);  // ChangeFocus (batch1014)

// 0x5cefc0 ZCamHelper::Find3DPointerShadowPos(float* p, float* d, float h, int mask): p moves back along d by h,
// then drops straight down (5000 units) onto the world; p becomes the ground point when there is one.
static THISCALL void ZCamHelper_Find3DPointerShadowPos(void *self, float *p, const float *d, float h, u32 mask) {
  at<u32>(self, 0xb8f) = 0x3f800000;
  at<u8>(self, 0xbc7) = 1;
  float v[3] = {d[0], d[1], d[2]};
  ext_4e09b0(v);
  ext_4e0d80(v, h);
  float w[3] = {p[0], p[1], p[2]};
  ext_441940(w, v);
  p[1] = w[1];
  p[2] = w[2];
  p[0] = w[0];
  u32 *st = &at<u32>(self, 0xb5b);
  *(float *)&st[0] = w[0];
  st[1] = ((u32 *)p)[1];
  st[2] = ((u32 *)p)[2];
  at<u32>(self, 0xb67) = 0;
  at<u32>(self, 0xb6b) = 0xc59c4000;  // -5000
  at<u32>(self, 0xb6f) = 0;
  if (vcall<bool>(ptr(SYS9B, 0xadc), 0x2e0, st, 0u, mask, 0xffffffffu, 1u, 0u)) {
    ((u32 *)p)[0] = at<u32>(self, 0xb83);
    ((u32 *)p)[1] = at<u32>(self, 0xb87);
    ((u32 *)p)[2] = at<u32>(self, 0xb8b);
  }
}
PCREG(5cefc0, ZCamHelper_Find3DPointerShadowPos);

// 0x5d26c0 ZCamHelper::StartRaisingFlag(CEnemyFlag*): remember the focus (for AbortRaisingFlag) and swing the
// camera over 6 s (mode 3) to look at the flag: from the box distance (+0x479 of the camera) behind the flag
// pole along its frame (rows 0 and 1 swapped, row 2 negated), facing -(row 0). Without a pole the focus just
// rises 400 units. Not when sys +0x1b5d == 1.
static THISCALL void ZCamHelper_StartRaisingFlag(void *self, u8 *flag) {
  if (at<u32>(G(u8 *, 0x70039c), 0x1b5d) == 1) return;
  float m[9], p[3];
  vcall<void>(self, 0x90, m, p);
  at<float>(self, 0xddd) = p[0];
  at<float>(self, 0xde5) = p[2];
  at<float>(self, 0xde1) = p[1];
  at<float>(self, 0xde9) = m[0];
  at<float>(self, 0xded) = m[1];
  at<float>(self, 0xdf1) = m[2];
  at<u8 *>(self, 0xdd9) = flag;
  void *pole = ptr(flag, 0x119);
  float dx, dy, dz;
  if (pole) {
    float t[3];
    vcall<void>(pole, 0x80, m, t);
    float a0 = m[0], a1 = m[1], a2 = m[2];
    m[0] = m[3];
    m[1] = m[4];
    m[2] = m[5];
    m[3] = a0;
    m[4] = a1;
    m[5] = a2;
    ext_4e09b0(&m[6]);
    float back = -at<float>(ptr(self, 0xb54), 0x479);
    p[0] = 0.0f;
    p[1] = 0.0f;
    p[2] = back;
    ext_4419f0(p, m);
    ext_441940(p, t);
    dx = m[0];
    dy = m[1];
    dz = m[2];
  } else {
    p[1] = p[1] + G(float, 0x694d10);  // 400
    dx = m[0];
    dy = m[1];
    dz = m[2];
  }
  float d[3] = {dx, dy, dz};
  ext_4e09b0(d);
  ext_5cd7f0(self, p, d, 6.0f, 3);
  at<u8>(self, 0xdd8) = 1;
}
PCREG(5d26c0, ZCamHelper_StartRaisingFlag);

// 0x5cd9c0 ZCamHelper::Command(unsigned short, void*): the script query "GetRefObjectCamHelper" (+0xb59) answers
// the helper's script reference through the reference table at 0x70038c (slot 0x20 check, a range-checked
// callback at +8 for objects in [+0xc, +0x10), else the cached id at this-4, created by slot 0xac).
static THISCALL u32 ZCamHelper_Command(u8 *self, u32 cmd, u32 *data) {
  if ((u16)cmd != at<u16>(self, 0xb59)) return 0;
  u8 *t = G(u8 *, 0x70038c);
  if (vcall<u32>(t, 0x20, self)) {
    *data = 0;
    return 0;
  }
  t = G(u8 *, 0x70038c);
  typedef u32(THISCALL * refcb)(void *);
  refcb cb = at<refcb>(t, 8);
  if (cb && at<u32>(t, 0xc) <= (u32)self && (u32)self < at<u32>(t, 0x10)) {
    *data = cb(self);
    return 0;
  }
  if (*(u32 *)(self - 4) == 0) vcall<void>(t, 0xac, self);
  *data = *(u32 *)(self - 4);
  return 0;
}
PCREG(5cd9c0, ZCamHelper_Command);

// 0x5cd5c0 ZCamHelper::ActionInputs(): stick values with no fresh input this frame (flags +0xb2f..+0xb34) are
// zeroed, all of them while raising a flag; then the fresh flags are cleared. (A dead-zone test against 0 that
// can never fire follows the zeroing.)
static THISCALL void ZCamHelper_ActionInputs(void *self) {
  if (!at<u8>(self, 0xb33)) at<u32>(self, 0xb1f) = 0;
  if (!at<u8>(self, 0xb34)) at<u32>(self, 0xb23) = 0;
  if (!at<u8>(self, 0xb30)) at<u32>(self, 0xb27) = 0;
  if (!at<u8>(self, 0xb2f)) at<u32>(self, 0xb2b) = 0;
  if (at<u8>(self, 0xdd8)) {
    at<u32>(self, 0xb1f) = 0;
    at<u32>(self, 0xb23) = 0;
    at<u32>(self, 0xb2b) = 0;
    at<u32>(self, 0xb27) = 0;
  }
  static const u16 offs[4] = {0xb23, 0xb1f, 0xb27, 0xb2b};
  for (int i = 0; i < 4; i++) {
    __m128d a = _mm_and_pd(_mm_cvtps_pd(_mm_load_ss(&at<float>(self, offs[i]))), *(const __m128d *)0x67cd50);
    if (0.0 > _mm_cvtsd_f64(a)) at<u32>(self, offs[i]) = 0;
  }
  at<u16>(self, 0xb33) = 0;
  at<u16>(self, 0xb2f) = 0;
}
PCREG(5cd5c0, ZCamHelper_ActionInputs);
