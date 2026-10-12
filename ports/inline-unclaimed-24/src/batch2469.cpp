// batch2469.cpp - decomp area 24, batch 2469 (parked light getters, same shape as batch 2468).
#include "ff.h"

// 0x449480 ZSPOTLIGHT::GetHotSpotAngle() const, thiscall, plain ret, float on st0. Buffer 0x38; float at +0x28; slot 0x84.
static float THISCALL spotLightGetHotSpotAngle(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  u8 *A = *(u8 **)(sys + 0x1aa3);
  void *B = *(void **)(A + 0x18);
  u8 *geom = *(u8 **)(self + 8);
  u8 buf[0x38];
  vcall<void>(B, 0x84, *(u32 *)(geom + 0x6c), (void *)buf);
  return *(float *)(buf + 0x28);
}
PCREG(449480, spotLightGetHotSpotAngle);

// 0x4494c0 ZOMNILIGHT::GetNearRange() const, thiscall, plain ret, float on st0. Buffer 0x24; float at +0x18; slot 0x80.
static float THISCALL omniLightGetNearRange(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  u8 *A = *(u8 **)(sys + 0x1aa3);
  void *B = *(void **)(A + 0x18);
  u8 *geom = *(u8 **)(self + 8);
  u8 buf[0x24];
  vcall<void>(B, 0x80, *(u32 *)(geom + 0x6c), (void *)buf);
  return *(float *)(buf + 0x18);
}
PCREG(4494c0, omniLightGetNearRange);

// 0x449500 ZSPOTLIGHT::GetNearRange() const, thiscall, plain ret, float on st0. Buffer 0x38; float at +0x18; slot 0x84.
static float THISCALL spotLightGetNearRange(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  u8 *A = *(u8 **)(sys + 0x1aa3);
  void *B = *(void **)(A + 0x18);
  u8 *geom = *(u8 **)(self + 8);
  u8 buf[0x38];
  vcall<void>(B, 0x84, *(u32 *)(geom + 0x6c), (void *)buf);
  return *(float *)(buf + 0x18);
}
PCREG(449500, spotLightGetNearRange);
