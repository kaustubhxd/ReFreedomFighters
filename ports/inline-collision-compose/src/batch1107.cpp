// batch1107.cpp - collision thread, batch 1107: ZMovementBase::CheckMovingSphereCollision (0x4883d0), the
// CheckCollision vtable slot 0x4c, and ZMovementBase::ChangeDimensions (0x61ba10), slot 0x5c.
#include "ff.h"

extern "C" u8 THISCALL ext_4ea390(u8 *box, u8 *impact, const float *oldPos, float *newPos, const float *ext,
                                  float *vel, u8 flag);   // ZCollisionBox::MovingSphereCollision (batch 1106)

// 0x4883d0 ZMovementBase::CheckMovingSphereCollision(ZSphereImpact*, const float *oldMat, const float *oldPos,
// float *newMat, float *newPos, float *vel) const, thiscall, ret 0x18, al. With p = [this+4] (the player) and
// box = [this+8]: returns false unless byte p+0x5ff is set; otherwise copies p+0x42d..0x435 to box+0x54..0x5c and
// returns MovingSphereCollision(impact, oldPos, newPos, p+0x439 (extent), vel, byte this+0x1c). The matrices are unused.
static u8 THISCALL checkMovingSphereCollision(u8 *self, u8 *impact, const float *oldMat, const float *oldPos,
                                              float *newMat, float *newPos, float *vel) {
  (void)oldMat;
  (void)newMat;
  u8 *p = *(u8 **)(self + 4);
  if (!p[0x5ff])
    return 0;
  u8 *box = *(u8 **)(self + 8);
  *(u32 *)(box + 0x54) = *(u32 *)(p + 0x42d);
  *(u32 *)(box + 0x58) = *(u32 *)(p + 0x431);
  *(u32 *)(box + 0x5c) = *(u32 *)(p + 0x435);
  return ext_4ea390(*(u8 **)(self + 8), impact, oldPos, newPos, (const float *)(*(u8 **)(self + 4) + 0x439), vel,
                    self[0x1c]);
}
PCREG(4883d0, checkMovingSphereCollision);

// 0x61ba10 ZMovementBase::ChangeDimensions(float*, float*, const float*, const float*) const [low]: returns false.
// (MSVC folded identical bodies, so this address likely serves several unrelated "return false, 4 args" methods.)
static u8 THISCALL changeDimensions(void *self, float *a, float *b, const float *c, const float *d) {
  (void)self, (void)a, (void)b, (void)c, (void)d;
  return 0;
}
PCREG(61ba10, changeDimensions);
