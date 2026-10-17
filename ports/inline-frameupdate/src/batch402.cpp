// batch402.cpp - per-frame update chain: vaddscalar (4-arg), ZPlayer::SetGroupPos, ZCamHelper::UpdateFocusSystem,
// ZLNKOBJ::ClassFrameUpdate, ZTARGET::Remove (inference).
#include "ff.h"

// ---------------------------------------------------------------- 0x443ef0 vaddscalar(float*, const float*, const float*, float) [high]
// fastcall (out in ECX, a in EDX, b and s on the stack), ret 8. out = a + b * s, x87: every lane is (b[i] * s) + a[i] at
// the precision the control word selects, stored as float. All inputs are read before the first store.
static void FASTCALL vaddscalar4(float *out, const float *a, const float *b, float s) {
  long double r0 = (long double)b[0] * (long double)s;
  long double r1 = (long double)b[1] * (long double)s;
  long double r2 = (long double)b[2] * (long double)s;
  r0 = r0 + (long double)a[0];
  r1 = r1 + (long double)a[1];
  r2 = r2 + (long double)a[2];
  out[0] = (float)r0;
  out[1] = (float)r1;
  out[2] = (float)r2;
}
PCREG(443ef0, vaddscalar4);

// ---------------------------------------------------------------- 0x484ff0 ZPlayer::SetGroupPos(const float*, const float*) [high]
// thiscall, ret 8. Moves the parent group (slot 0x20) so that the player's centre lands at pos: the group's root
// position is pos minus the matrix's up row (mat + 3) times the centre height +0x451 (the inverse of GetCenterMatPos).
extern "C" void FASTCALL ext_443ef0(float *out, const float *a, const float *b, float s);
static void THISCALL playerSetGroupPos(u8 *self, const float *mat, const float *pos) {
  float root[3];
  ext_443ef0(root, pos, mat + 3, -*(float *)(self + 0x451));
  u8 *g = vcall<u8 *>(self, 0x20);
  vcall<void>(g, 0x7c, mat, (const float *)root);  // ZGEOM::SetRootTM [high]
}
PCREG(484ff0, playerSetGroupPos);

// ---------------------------------------------------------------- 0x5d2e60 ZCamHelper::UpdateFocusSystem() [high]
// thiscall. Byte +0xd35 set: tail-calls 0x5cebc0 (no name). Else, unless +0xdd8 is set, control mode +0xe1c picks the
// focus system: 0, 1 and 2 SetFocusSystemOni, 3 SetFocusSystemMouse, anything else nothing (jump table 0x5d2e94).
extern "C" void THISCALL ext_5cebc0(u8 *cam);
extern "C" void THISCALL ext_5d1ea0(u8 *cam);  // ZCamHelper::SetFocusSystemMouse [medium]
extern "C" void THISCALL ext_5d2080(u8 *cam);  // ZCamHelper::SetFocusSystemOni [medium]
static void THISCALL camUpdateFocusSystem(u8 *cam) {
  if (cam[0xd35]) {
    ext_5cebc0(cam);
    return;
  }
  if (cam[0xdd8])
    return;
  u32 mode = *(u32 *)(cam + 0xe1c);
  if (mode > 3)
    return;
  if (mode == 3)
    ext_5d1ea0(cam);
  else
    ext_5d2080(cam);
}
PCREG(5d2e60, camUpdateFocusSystem);

// ---------------------------------------------------------------- 0x461c40 ZLNKOBJ::ClassFrameUpdate() [high]
// thiscall. Clears two dwords of the link record (+0x6c), runs slot 0x348 (UpdateAnimationsAndGroundLink [low]) and,
// when it returns true, places the object relative to its parent group: mat = this+0x24 * groupMat,
// pos = this+0x48 * groupMat + groupPos, then either (IsDerivedFrom(0x2007d0)) the parent's parent gets slot 0x98 and
// the object SetRootTM, or the parent gets SetMatPos.
extern "C" void THISCALL ext_4db2c0(u8 *geom, float *mat, float *pos);           // ZBaseGeom::GetMatPos [high]
extern "C" void FASTCALL ext_4de440(float *out, const float *a, const float *b);  // mmmul [low]
extern "C" void FASTCALL ext_441970(float *out, const float *v, const float *m);  // vmmul (out = v * m) [high]
extern "C" void FASTCALL ext_441940(float *a, const float *b);                    // PSVECAdd, a += b [medium]
extern "C" void FASTCALL ext_4de420(float *dst, const float *src);                // mcpy [low]
static void THISCALL zlnkobjClassFrameUpdate(u8 *self) {
  u8 *link = *(u8 **)(self + 0x6c);
  *(u32 *)(link + 0x65) = 0;
  *(u32 *)(link + 0x251) = 0;
  if (!vcall<u8>(self, 0x348))
    return;
  float gMat[9], gPos[3], m[9], p[3], outMat[9];
  u32 outPos[3];
  ext_4db2c0(*(u8 **)(vcall<u8 *>(self, 0x20) + 8), gMat, gPos);
  ext_4de440(m, (const float *)(self + 0x24), gMat);
  ext_441970(p, (const float *)(self + 0x48), gMat);
  ext_441940(p, gPos);
  ext_4de420(outMat, m);
  outPos[0] = ((u32 *)p)[0];
  outPos[1] = ((u32 *)p)[1];
  outPos[2] = ((u32 *)p)[2];
  if (vcall<u8>(self, 0x1e0, 0x2007d0u)) {  // ZGEOM::IsDerivedFrom [high]
    u8 *g = vcall<u8 *>(vcall<u8 *>(self, 0x20), 0x20);
    vcall<void>(g, 0x98, (const float *)outMat, (const float *)outPos);
    vcall<void>(self, 0x7c, (const float *)outMat, (const float *)outPos);  // SetRootTM
  } else {
    u8 *g = vcall<u8 *>(self, 0x20);
    vcall<void>(g, 0x74, (const float *)outMat, (const float *)outPos);  // ZGEOM::SetMatPos [high]
  }
}
PCREG(461c40, zlnkobjClassFrameUpdate);

// ---------------------------------------------------------------- 0x467410 ZTARGET::Remove(ZIKLNKOBJ*, float, PMF) (inference)
// thiscall, ret 0x18: obj, fade time, and a 16-byte pointer to member function (the callback) by value. Name: no
// map entry; GC ZTARGET::Remove(ZIKLNKOBJ*, float, void (ZIKLNKOBJ::*)(ZIKLNKOBJ*)) has this signature, and the body
// calls CallBackAndRemove first (inference, medium). Fields: +0x31 fade time, +0x35 start time in seconds (negative =
// fading out, inference), +0x39 cleared, +0x3d callback.
extern "C" void THISCALL ext_4658d0(u8 *t, u8 *obj);  // ZTARGET::CallBackAndRemove [medium]
extern "C" void THISCALL ext_465930(u8 *t, u8 *obj);  // (no name; called only on the fade == 0 path)
struct PMF16 {
  u32 w[4];
};
static inline s32 cvtt(float x) { return _mm_cvtt_ss2si(_mm_set_ss(x)); }
static inline float fabsf_(float x) { return bitsf(fbits(x) & 0x7fffffffu); }
static void THISCALL ztargetRemove(u8 *t, u8 *obj, float fade, PMF16 cb) {
  const float inv1024 = 0.0009765625f;  // [0x6785e4]
  const float one = 1.0f;               // [0x678858]
  ext_4658d0(t, obj);
  *(PMF16 *)(t + 0x3d) = cb;
  if (fade == 0.0f) {
    float st = *(float *)(t + 0x35);
    u32 now = *(u32 *)(G(u8 *, 0x70039c) + 0x40);
    float el = (float)(s32)(now - (u32)cvtt(fabsf_(st) * 1024.0f)) * inv1024;  // 1024 at [0x678620]
    float prc;
    float d = *(float *)(t + 0x31);
    if (st >= 0.0f) {
      prc = d > el ? el / d : one;
    } else if (el > d) {
      prc = 0.0f;
    } else if (d == 0.0f) {
      prc = 0.0f;
    } else {
      prc = one - el / d;
    }
    *(u32 *)(t + 0x31) = 0;
    u32 now2 = *(u32 *)(G(u8 *, 0x70039c) + 0x40);
    *(u32 *)(t + 0x39) = 0;
    u32 r = prc == one ? 0u - now2 : 0u - now2 - (u32)cvtt((one - prc) * 0.0f * -1024.0f);  // -1024 at [0x67862c]
    *(float *)(t + 0x35) = (float)(s32)r * inv1024;
    ext_465930(t, obj);
    return;
  }
  float st = *(float *)(t + 0x35);
  if (!(st >= 0.0f))
    return;
  u32 now = *(u32 *)(G(u8 *, 0x70039c) + 0x40);
  float d = *(float *)(t + 0x31);
  float el = (float)(s32)(now - (u32)cvtt(fabsf_(st) * 1024.0f)) * inv1024;
  float prc = d > el ? el / d : one;
  *(float *)(t + 0x31) = fade;
  u32 now2 = *(u32 *)(G(u8 *, 0x70039c) + 0x40);
  *(u32 *)(t + 0x39) = 0;
  u32 r = prc == one ? 0u - now2 : 0u - now2 - (u32)cvtt((one - prc) * fade * -1024.0f);
  *(float *)(t + 0x35) = (float)(s32)r * inv1024;
}
PCREG(467410, ztargetRemove);
