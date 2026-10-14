// batch833.cpp - animation layer thread, batch 833: shadow projection plane and the object-track registration.
#include "ff.h"

#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_461760(void *self, u32 *out, u32 a, u32 b);   // (ported below as CalcShadowProjectPlane)

// ZLNKOBJ::CalcShadowProjectPlane(float* out, const float* a, const float* b) const [medium]. Writes the "no plane"
// marker 0x7e967699 (a large float) into all four plane words.
static void THISCALL CalcShadowProjectPlane(void *, u32 *out, u32, u32) {
  out[0] = 0x7e967699u;
  out[1] = 0x7e967699u;
  out[2] = 0x7e967699u;
  out[3] = 0x7e967699u;
}
PCREG(461760, CalcShadowProjectPlane);

// ZIKLNKOBJ::CalcShadowProjectPlane(float* out, const float* a, const float* b) const [medium]: the bone modifier's
// vt +0x54(this, out, a, b) decides; when it returns false the base plane is used.
static void THISCALL ZIKLNKOBJ_CalcShadowProjectPlane(void *self, u32 *out, u32 a, u32 b) {
  bool done = vcall<bool>(FP(self, 0x6c), 0x54, self, out, a, b);
  if (!done) ext_461760(self, out, a, b);
}
PCREG(465890, ZIKLNKOBJ_CalcShadowProjectPlane);

// ZIKLNKOBJ::Load2() [medium]: the track-objects setting (the string "TrackLinkObjects", flag 0) is read from the
// engine's settings object ([[0x70039c]+0x9b]+0xadc, vt +0x25c) and stored at [0x7003b8]+0x4ac.
static void THISCALL Load2(void *) {
  void *g = G(void *, 0x70039c);
  void *mgr = FP(FP(g, 0x9b), 0xadc);
  u32 v = vcall<u32>(mgr, 0x25c, (const char *)0x685f44, 0u);
  *(u32 *)((u8 *)G(void *, 0x7003b8) + 0x4ac) = v;
}
PCREG(466d90, Load2);
