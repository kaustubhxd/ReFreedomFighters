// batch403.cpp - per-frame update chain: ZFFHERO::ControlBody, ZPlayer::CalcBonesFromMotion, ZTARGET callbacks,
// the camera's focus blend (0x5cebc0).
#include "ff.h"

struct PMF16 {
  u32 w[4];  // MSVC pointer to member: function, this adjustment, two more words (vbtable data; -1 when unused)
};
static inline s32 cvtt(float x) { return _mm_cvtt_ss2si(_mm_set_ss(x)); }
static inline float fabsf_(float x) { return bitsf(fbits(x) & 0x7fffffffu); }

// ---------------------------------------------------------------- 0x58eb40 ZFFHERO::ControlBody() [low]
// thiscall: tail-calls ZCamHelper::ControlBody on the camera helper at +0x85a.
extern "C" void THISCALL ext_5cdb70(u8 *cam);  // ZCamHelper::ControlBody (batch 400)
static void THISCALL heroControlBody(u8 *self) { ext_5cdb70(*(u8 **)(self + 0x85a)); }
PCREG(58eb40, heroControlBody);

// ---------------------------------------------------------------- 0x481570 ZPlayer::CalcBonesFromMotion(4 x const float*) [high]
// thiscall, ret 0x10. The animation controller at +0x455 picks the anim for this frame's motion and returns a blend
// weight; the player switches to it and updates the blend.
static void THISCALL playerCalcBonesFromMotion(u8 *self, const float *a0, const float *a1, const float *a2,
                                               const float *a3) {
  u8 *link = *(u8 **)(self + 0x6c);
  *(u32 *)(link + 0x65) = 0;
  *(u32 *)(link + 0x251) = 0;
  if (!vcall<u8>(self, 0x324, 0u) || (vcall<u8>(self, 0x320, 0u) & 0x20)) {
    u32 anim = 0;
    float w = vcall<float>(*(u8 **)(self + 0x455), 0x24, &anim, a0, a1, a2, a3);
    if (*(float *)(self + 0x612) > w && anim) {
      vcall<void>(self, 0x268, anim, *(u32 *)((u8 *)anim + 0x7c));
    }
    *(float *)(self + 0x612) = w;
    if (!anim) {
      anim = *(u32 *)(self + 0x424);
      if (!anim)
        goto done;
    }
    if (*(u32 *)(self + 0x417) & 0x40000)
      goto done;
    if (*(u32 *)(self + 0x424) != anim) {
      if (*(u32 *)(self + 0x424))
        *(float *)(self + 0x428) = (float)*(s32 *)(G(u8 *, 0x70039c) + 0x40) * 0.0009765625f;  // [0x6785e4]
      else
        *(u32 *)(self + 0x428) = 0xc47a0000u;  // -1000.0
      *(u32 *)(self + 0x424) = anim;
    }
    {
      void **vt = *(void ***)self;
      float g = vcall<float>(*(u8 **)(self + 0x455), 0x30, anim);  // ZMovementBase::BlendInSpeed(const AnimHeader*)
      // ZLNKOBJ::SetBoneFrameBlend(AnimHeader*, float, float, bool, unsigned int) [high]
      ((void(THISCALL *)(u8 *, u32, float, float, u32, u32))vt[0x244 / 4])(self, anim, w, g, 0, 0);
    }
    if (!vcall<u8>(*(u8 **)(self + 0x455), 0x28))
      vcall<void>(self, 0x5f8, w);
  }
done:
  vcall<void>(self, 0x3e0);
}
PCREG(481570, playerCalcBonesFromMotion);

// ---------------------------------------------------------------- 0x4658d0 ZTARGET::CallBackAndRemove(ZIKLNKOBJ*) [medium]
// thiscall, ret 4. While the callback at +0x3d is set: clear it (to {0, 0, 0, -1}) and call it on obj (+ adjustment).
static void THISCALL ztargetCallBackAndRemove(u8 *t, u8 *obj) {
  for (;;) {
    PMF16 p = *(PMF16 *)(t + 0x3d);
    if (!p.w[0])
      return;
    PMF16 z = {{0, 0, 0, 0xffffffffu}};
    *(PMF16 *)(t + 0x3d) = z;
    ((void(THISCALL *)(u8 *))p.w[0])(obj + p.w[1]);
  }
}
PCREG(4658d0, ztargetCallBackAndRemove);

// ---------------------------------------------------------------- 0x465930 ZTARGET::CallBackIfTime(ZIKLNKOBJ*) (inference)
// thiscall, ret 4. No map entry; the GC function of this name (328 bytes) is the only ZTARGET method of this shape.
// Progress p of the fade as in ZTARGET::Remove (batch 402). A fade-in (start >= 0) that reached p == 1, or a fade-out
// (start < 0 or NaN) that reached p == 0 (this one also clears the enabled byte +0), takes the callback (cleared to
// {0, 0, 0, -1}) and calls it on obj.
static void THISCALL ztargetCallBackIfTime(u8 *t, u8 *obj) {
  const float one = 1.0f;
  float st = *(float *)(t + 0x35);
  u32 now = *(u32 *)(G(u8 *, 0x70039c) + 0x40);
  float el = (float)(s32)(now - (u32)cvtt(fabsf_(st) * 1024.0f)) * 0.0009765625f;
  float d = *(float *)(t + 0x31);
  float p;
  if (st >= 0.0f)
    p = d > el ? el / d : one;
  else if (el > d)
    p = 0.0f;
  else if (d == 0.0f)
    p = 0.0f;
  else
    p = one - el / d;
  PMF16 cb = {{0, 0, 0, 0xffffffffu}};
  if (st >= 0.0f) {
    if (p == one)
      cb = *(PMF16 *)(t + 0x3d);
  } else if (p == 0.0f) {
    t[0] = 0;
    cb = *(PMF16 *)(t + 0x3d);
  }
  if (!cb.w[0])
    return;
  PMF16 z = {{0, 0, 0, 0xffffffffu}};
  *(PMF16 *)(t + 0x3d) = z;
  ((void(THISCALL *)(u8 *))cb.w[0])(obj + cb.w[1]);
}
PCREG(465930, ztargetCallBackIfTime);

// ---------------------------------------------------------------- 0x5cebc0 camera focus blend (no name)
// thiscall. Called by ZCamHelper::UpdateFocusSystem while byte +0xd35 is set. Steps two smoothers embedded in the
// camera helper: +0xd36 (target point into +0xd3a) and +0xd87 (angles into +0xd8b); the camera matrix +0xc89 is
// createmat of the angles and the focus point +0xc71 the smoothed point. When both smoothers report done (their
// slot 0), +0xd35 is cleared.
extern "C" u32 THISCALL ext_662c50(u8 *smoother, float *io);  // point smoother step (EaseInEaseOut, inference)
extern "C" u32 THISCALL ext_662f40(u8 *smoother, float *io);  // angle smoother step (inference)
extern "C" void FASTCALL ext_4de040(float *out, const float *fwd, const float *up);  // createmat [high]
extern "C" void FASTCALL ext_4de420(float *dst, const float *src);                   // mcpy [low]
static void THISCALL camFocusBlend(u8 *cam) {
  ext_662c50(cam + 0xd36, (float *)(cam + 0xd3a));
  u32 p0 = *(u32 *)(cam + 0xd3a), p1 = *(u32 *)(cam + 0xd3e), p2 = *(u32 *)(cam + 0xd42);
  ext_662f40(cam + 0xd87, (float *)(cam + 0xd8b));
  float ang[3];
  ((u32 *)ang)[0] = *(u32 *)(cam + 0xd8b);
  ((u32 *)ang)[1] = *(u32 *)(cam + 0xd8f);
  ((u32 *)ang)[2] = *(u32 *)(cam + 0xd93);
  float m[9];
  ext_4de040(m, ang, 0);
  ext_4de420((float *)(cam + 0xc89), m);
  *(u32 *)(cam + 0xc71) = p0;
  *(u32 *)(cam + 0xc75) = p1;
  *(u32 *)(cam + 0xc79) = p2;
  if (vcall<u8>(cam + 0xd36, 0x0) && vcall<u8>(cam + 0xd87, 0x0))
    cam[0xd35] = 0;
}
PCREG(5cebc0, camFocusBlend);
