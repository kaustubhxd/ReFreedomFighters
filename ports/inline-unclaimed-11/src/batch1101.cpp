// batch1101.cpp - unclaimed-11 batch 1 (docs/20-unclaimed-11.md): CMoveAlongPath accessors and ZMovementAction::WantControl.
// Every function is thiscall. Names are from the GC name map (naming only; GUESS where the map is low confidence).
// Bodies follow the PC bytes exactly: float returns go out on the x87 stack (ST0), flags and offsets are the original's.
#include "ff.h"

// 0x5231b0, CMoveAlongPath::DirFactor() const (GUESS): fld of the float at this+0x20; the float is returned in ST0.
static float THISCALL moveAlongPathDirFactor(u8 *self) {
  return bitsf(*(u32 *)(self + 0x20));
}
PCREG(5231b0, moveAlongPathDirFactor);

// 0x523460, CMoveAlongPath::GetPath() (GUESS): the dword at this+0x4b, returned in EAX.
static u32 THISCALL moveAlongPathGetPath(u8 *self) {
  return *(u32 *)(self + 0x4b);
}
PCREG(523460, moveAlongPathGetPath);

// 0x523980, CMoveAlongPath::PathLength() const (GUESS): fld of the float at this+0x53; the float is returned in ST0.
static float THISCALL moveAlongPathPathLength(u8 *self) {
  return bitsf(*(u32 *)(self + 0x53));
}
PCREG(523980, moveAlongPathPathLength);

// 0x523e80, CMoveAlongPath::SetTargetSpeed(float, float) (medium): arg1 is stored at this+0x2c; arg2 is stored at
// this+0x28, and its sign bit is flipped when the float at this+0x24 is greater than arg1 (ordered compare: a NaN
// on either side leaves arg2 as it is). Bits are copied, no arithmetic.
static void THISCALL moveAlongPathSetTargetSpeed(u8 *self, u32 a1, u32 a2) {
  float cur = bitsf(*(u32 *)(self + 0x24));
  float lim = bitsf(a1);
  *(u32 *)(self + 0x2c) = a1;
  u32 v = a2;
  if (cur > lim) v ^= 0x80000000u;
  *(u32 *)(self + 0x28) = v;
}
PCREG(523e80, moveAlongPathSetTargetSpeed);

// 0x489d80, ZMovementAction::WantControl(const float*, const float*, const float*) (medium): the owner is the pointer
// at this+4. If the owner's dword at +0x417 has bit 0x80000 set, the result is (this+0x21 != 0), else false. The three
// pointer arguments are not read. Returns a bool in AL (the upper bits of EAX are not part of the result).
static u8 THISCALL movementActionWantControl(u8 *self, const float *a1, const float *a2, const float *a3) {
  u8 *owner = *(u8 **)(self + 4);
  if (*(u32 *)(owner + 0x417) & 0x80000) return self[0x21] != 0;
  return 0;
}
PCREG(489d80, movementActionWantControl);
