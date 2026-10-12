// batch910.cpp - unclaimed-09 batch 2: collision lock bits and CMoveAlongPath accessors (docs/20-unclaimed-09.md).
// Every function is thiscall. Names are from the GC name map (naming only, GUESS where the map says medium or low).
#include "ff.h"

// Original code of ZCollisionBox::Unlock (0x4eb340), called by the port of UnlockCollisionBox below.
extern "C" void THISCALL ext_4eb340(u8 *self);

// 0x4eb340, ZCollisionBox::Unlock() (medium): stores 0 in the byte at this+0xa5.
static void THISCALL colBoxUnlock(u8 *self) {
  self[0xa5] = 0;
}
PCREG(4eb340, colBoxUnlock);

// 0x4ecb30, ZCollisionBase::GetCollisionPack() (medium): returns the dword at this+0x1ad in eax.
static u32 THISCALL colGetCollisionPack(u8 *self) {
  return *(u32 *)(self + 0x1ad);
}
PCREG(4ecb30, colGetCollisionPack);

// 0x4edca0, ZCollisionBase::IsCollisionBoxLocked() const (medium): returns the byte at this+0xa9 in al.
static u8 THISCALL colIsCollisionBoxLocked(u8 *self) {
  return self[0xa9];
}
PCREG(4edca0, colIsCollisionBoxLocked);

// 0x4ede70, ZCollisionBase::UnlockCollisionBox(ZCollisionBox*) (medium): adds 4 to ecx, calls ZCollisionBox::Unlock,
// ret 4. The argument is not read.
static void THISCALL colUnlockCollisionBox(u8 *self, u32 box) {
  ext_4eb340(self + 4);
}
PCREG(4ede70, colUnlockCollisionBox);

// 0x5231b0, CMoveAlongPath::DirFactor() const (low): loads the float at this+0x20 onto the x87 stack (st0).
static float THISCALL moveDirFactor(u8 *self) {
  return *(float *)(self + 0x20);
}
PCREG(5231b0, moveDirFactor);

// 0x523460, CMoveAlongPath::GetPath() (low): returns the dword at this+0x4b in eax.
static u32 THISCALL moveGetPath(u8 *self) {
  return *(u32 *)(self + 0x4b);
}
PCREG(523460, moveGetPath);

// 0x523980, CMoveAlongPath::PathLength() const (low): loads the float at this+0x53 onto st0.
static float THISCALL movePathLength(u8 *self) {
  return *(float *)(self + 0x53);
}
PCREG(523980, movePathLength);
