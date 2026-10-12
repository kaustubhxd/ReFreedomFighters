// batch2468.cpp - decomp area 24, batch 2468 (parked light getters: a stack buffer filled by the vtable callee).
#include "ff.h"

// 0x4493c0 ZSPOTLIGHT::GetFallOffAngle() const, thiscall, plain ret, float on st0. Buffer 0x38 bytes; float at +0x24.
static float THISCALL spotLightGetFallOffAngle(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  u8 *A = *(u8 **)(sys + 0x1aa3);
  void *B = *(void **)(A + 0x18);
  u8 *geom = *(u8 **)(self + 8);
  u8 buf[0x38];
  vcall<void>(B, 0x84, *(u32 *)(geom + 0x6c), (void *)buf);
  return *(float *)(buf + 0x24);
}
PCREG(4493c0, spotLightGetFallOffAngle);

// 0x449400 ZOMNILIGHT::GetFarRange() const, thiscall, plain ret, float on st0. Buffer 0x24 bytes; float at +0x1c. Slot 0x80.
static float THISCALL omniLightGetFarRange(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  u8 *A = *(u8 **)(sys + 0x1aa3);
  void *B = *(void **)(A + 0x18);
  u8 *geom = *(u8 **)(self + 8);
  u8 buf[0x24];
  vcall<void>(B, 0x80, *(u32 *)(geom + 0x6c), (void *)buf);
  return *(float *)(buf + 0x1c);
}
PCREG(449400, omniLightGetFarRange);

// 0x449440 ZSPOTLIGHT::GetFarRange() const, thiscall, plain ret, float on st0. Buffer 0x38 bytes; float at +0x1c. Slot 0x84.
static float THISCALL spotLightGetFarRange(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  u8 *A = *(u8 **)(sys + 0x1aa3);
  void *B = *(void **)(A + 0x18);
  u8 *geom = *(u8 **)(self + 8);
  u8 buf[0x38];
  vcall<void>(B, 0x84, *(u32 *)(geom + 0x6c), (void *)buf);
  return *(float *)(buf + 0x1c);
}
PCREG(449440, spotLightGetFarRange);
