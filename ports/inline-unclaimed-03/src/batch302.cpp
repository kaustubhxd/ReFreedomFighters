// batch302.cpp - unclaimed-03 batch 2 (docs/20-unclaimed-03.md): CMoveAlongPath accessors, ZCollisionBase getters,
// and CMoveAlongPath::SetTargetSpeed. Names are from the GC name map (naming only, GUESS where low or medium);
// bodies are from the PC bytes.
#include "ff.h"

// 0x5231b0, CMoveAlongPath::DirFactor() const (low, GUESS): returns the float at this+0x20 on the x87 stack (fld, ret).
static float THISCALL moveAlongDirFactor(u8 *self) {
  return *(float *)(self + 0x20);
}
PCREG(5231b0, moveAlongDirFactor);

// 0x523460, CMoveAlongPath::GetPath() (low, GUESS): returns the dword at this+0x4b (unaligned).
static u32 THISCALL moveAlongGetPath(u8 *self) {
  return *(u32 *)(self + 0x4b);
}
PCREG(523460, moveAlongGetPath);

// 0x523980, CMoveAlongPath::PathLength() const (low, GUESS): returns the float at this+0x53 on the x87 stack.
static float THISCALL moveAlongPathLength(u8 *self) {
  return *(float *)(self + 0x53);
}
PCREG(523980, moveAlongPathLength);

// 0x523e80, CMoveAlongPath::SetTargetSpeed(float, float) (medium, GUESS): stores the first argument at this+0x2c and
// the second at this+0x28; the second is negated (sign bit flipped, xorps with the mask at 0x67af40) when the float at
// this+0x24 is greater than the first argument. comiss sets CF on NaN, so a NaN compare does not negate, the same as
// the C '>' below. Callee pops 8 (ret 8).
static void THISCALL moveAlongSetTargetSpeed(u8 *self, float a1, float a2) {
  *(float *)(self + 0x2c) = a1;
  float v = a2;
  if (*(float *)(self + 0x24) > a1)
    v = bitsf(fbits(v) ^ 0x80000000u);
  *(float *)(self + 0x28) = v;
}
PCREG(523e80, moveAlongSetTargetSpeed);

// 0x4ecb30, ZCollisionBase::GetCollisionPack() (medium, GUESS): returns the dword at this+0x1ad (unaligned).
static u32 THISCALL collisionGetCollisionPack(u8 *self) {
  return *(u32 *)(self + 0x1ad);
}
PCREG(4ecb30, collisionGetCollisionPack);

// 0x4edca0, ZCollisionBase::IsCollisionBoxLocked() const (medium, GUESS): returns the byte at this+0xa9 in al. The
// upper bits of eax are left as they were (mov al), so the port writes only the low byte of the caller's eax.
static u8 THISCALL collisionIsCollisionBoxLocked(u8 *self) {
  return self[0xa9];
}
PCREG(4edca0, collisionIsCollisionBoxLocked);
