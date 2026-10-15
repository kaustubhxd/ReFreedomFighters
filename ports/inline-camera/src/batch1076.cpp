// batch1076.cpp - ZCameraOverlay::UpdateWind(float *out, float dt) (0x459f40, high confidence in the class map). Camera/view
// thread, 2026-10-12.
#include "cam.h"

extern "C" THISCALL void ext_4e0a10(float *v);                                   // random unit direction into v (uses sys slot 0x1c4)
extern "C" THISCALL void ext_4e0d00(float *v, float s);                          // v *= s
extern "C" FASTCALL void ext_451890(float *dst, const float *src, float k);       // dst += src * k
extern "C" FASTCALL void ext_443ef0(float *out, const float *p, const float *w, float dt);  // out = p + w * dt (x87)

// 0x459f40 ZCameraOverlay::UpdateWind(float *out, float dt) (thiscall, two stack args): the wind vector W (+0xac) decays by
// 0.99, takes a random direction scaled by dt / 2, and the output is the position P (+0xa0) plus W * dt.
static THISCALL void ZCameraOverlay_UpdateWind(u8 *self, float *out, float dt) {
  float tmp[3];
  ext_4e0a10(tmp);
  float *w = (float *)(self + 0xac);
  ext_4e0d00(w, bitsf(0x3f7eb852u));       // 0.99
  ext_451890(w, tmp, dt * 0.5f);
  ext_443ef0(out, (const float *)(self + 0xa0), w, dt);
}
PCREG(459f40, ZCameraOverlay_UpdateWind);
