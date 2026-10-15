// batch1013.cpp - ZCamHelper::UpdateFocusAngleMouse (mouse aim direction and target point). Camera thread, 2026-10-11.
#include "cam.h"

extern "C" THISCALL void ext_5d1ea0(void *self);                  // ZCamHelper::SetFocusSystemMouse (batch1012)
extern "C" FASTCALL void ext_4e0d80(float *v, float len);          // vsetlen
extern "C" FASTCALL void ext_43e8e0(float *d, const float *a, const float *b);  // d = a + b
extern "C" THISCALL void ext_5d2630(void *self, u32 target);       // (unnamed) lock onto target +0xd2e
extern "C" THISCALL void ext_5cf300(void *self, float *scr, const float *p);  // ZCamHelper::Get2DProjection
extern "C" THISCALL void ext_5a7500(void *osd, float x, float y);  // OSD pointer offset (inferred)

// 0x5d28c0 ZCamHelper::UpdateFocusAngleMouse(): aim yaw/pitch (+0xa54/+0xa5c) become the focus angles, the focus
// frame is rebuilt, and from the focal point (vslot 0x88) the aim direction (+0xa72) = (cos y cos p, sin p,
// sin y cos p) gives the target point at pick range +0xdfd (+0xd15) and the far point at 10000 (+0xa7e). With a
// locked target (+0xd33) the far point is the target point. The far point's screen offset is sent to the OSD
// pointer when the extra angles +0xaf9/+0xafd exceed 1 degree, then the offset is reset to (0, 0).
static THISCALL void ZCamHelper_UpdateFocusAngleMouse(void *self) {
  at<float>(self, 0xae9) = at<float>(self, 0xa54);
  at<u32>(self, 0xaed) = at<u32>(self, 0xa5c);
  ext_5d1ea0(self);
  float eye[3];
  vcall<void>(self, 0x88, eye);
  double p = (double)at<float>(self, 0xa5c);
  double y = (double)at<float>(self, 0xa54);
  float *aim = &at<float>(self, 0xa72);
  double cy = crt::cos(y);
  aim[0] = (float)(cy * crt::cos(p));
  aim[1] = (float)crt::sin(p);
  double sy = crt::sin(y);
  aim[2] = (float)(sy * crt::cos(p));
  ext_4e0d80(aim, at<float>(self, 0xdfd));
  ext_43e8e0(&at<float>(self, 0xd15), eye, aim);
  ext_4e0d80(aim, 10000.0f);
  u32 *far_ = &at<u32>(self, 0xa7e);
  ext_43e8e0((float *)far_, eye, aim);
  u32 *tgt = &at<u32>(self, 0xd15);
  if (at<u8>(self, 0xd33)) {
    far_[0] = tgt[0];
    far_[1] = tgt[1];
    far_[2] = tgt[2];
    ext_5d2630(self, at<u32>(self, 0xd2e));
  }
  float scr[2];
  ext_5cf300(self, scr, (float *)far_);
  const float one = G(float, 0x67da04);
  float sx = !(one >= at<float>(self, 0xaf9)) ? scr[0] : 0.0f;
  float sy2 = !(one >= at<float>(self, 0xafd)) ? scr[1] : 0.0f;
  if (ptr(self, 0xe18)) ext_5a7500(ptr(self, 0xe18), sx, sy2);
  tgt[0] = far_[0];
  tgt[1] = far_[1];
  tgt[2] = far_[2];
  if (ptr(self, 0xe18)) ext_5a7500(ptr(self, 0xe18), 0.0f, 0.0f);
}
PCREG(5d28c0, ZCamHelper_UpdateFocusAngleMouse);
