// batch909.cpp - unclaimed-09: ZFFActor small accessors and ZFFHeroMovementBaseMove::GotControl (docs/20-unclaimed-09.md).
// Every function is thiscall (this in ECX). Names are from the GC name map (naming only). Bodies are from the PC bytes.
#include "ff.h"

// 0x59fce0, ZFFActor::GetAmmoFor(ZItemWeapon*) (high): ignores the argument, returns 999 in eax, ret 4.
static u32 THISCALL ffActorGetAmmoFor(u8 *self, u32 a1) {
  return 999;
}
PCREG(59fce0, ffActorGetAmmoFor);

// 0x59fe10, ZFFActor::GetHitsOnObstacle() const (high): returns the dword at this+0x90b in eax.
static u32 THISCALL ffActorGetHitsOnObstacle(u8 *self) {
  return *(u32 *)(self + 0x90b);
}
PCREG(59fe10, ffActorGetHitsOnObstacle);

// 0x59fe70, ZFFActor::GetKnockedOut() const (high): returns the byte at this+0x929 in al (eax upper bits untouched).
static u8 THISCALL ffActorGetKnockedOut(u8 *self) {
  return self[0x929];
}
PCREG(59fe70, ffActorGetKnockedOut);

// 0x59feb0, ZFFActor::GetLastHitRef() const (high): returns the dword at this+0x907 in eax.
static u32 THISCALL ffActorGetLastHitRef(u8 *self) {
  return *(u32 *)(self + 0x907);
}
PCREG(59feb0, ffActorGetLastHitRef);

// 0x5a2970, ZFFActor::ResetHitsOnObstacle() (high): stores 0 as a dword at this+0x90b.
static void THISCALL ffActorResetHitsOnObstacle(u8 *self) {
  *(u32 *)(self + 0x90b) = 0;
}
PCREG(5a2970, ffActorResetHitsOnObstacle);

// 0x5e48f0, ZFFHeroMovementBaseMove::GotControl() (high): stores 1 as a byte at this+0x54b.
static void THISCALL ffHeroMoveGotControl(u8 *self) {
  self[0x54b] = 1;
}
PCREG(5e48f0, ffHeroMoveGotControl);
