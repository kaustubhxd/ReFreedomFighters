// batch602.cpp - unclaimed-06: ZFFActor small accessors and flag setters (docs/20-unclaimed-06.md, batch 2).
// Names are from the GC name map (naming only); the bodies are from the PC bytes. Thiscall; the callee pops its argument
// (ret 4) where the PC function has one.
#include "ff.h"

// 0x59fce0, ZFFActor::GetAmmoFor(ZItemWeapon*) (high): returns the constant 999 (mov eax, 0x3e7), ignores its argument.
static u32 THISCALL ffActorGetAmmoFor(u8 *self, u32 a1) {
  (void)self;
  (void)a1;
  return 999;
}
PCREG(59fce0, ffActorGetAmmoFor);

// 0x59fcf0, ZFFActor::GetCloseCombatStrength() (high): loads the word at this+0x7a4 into ax. The high half of eax is
// whatever the caller left there; the pilot enters every call with eax = 0, so the zero-extended port matches (see the
// caveat in docs/20-unclaimed-06.md).
static u16 THISCALL ffActorGetCloseCombatStrength(u8 *self) {
  return *(u16 *)(self + 0x7a4);
}
PCREG(59fcf0, ffActorGetCloseCombatStrength);

// 0x59fe10, ZFFActor::GetHitsOnObstacle() const (high): returns the dword at this+0x90b.
static u32 THISCALL ffActorGetHitsOnObstacle(u8 *self) {
  return *(u32 *)(self + 0x90b);
}
PCREG(59fe10, ffActorGetHitsOnObstacle);

// 0x59fe70, ZFFActor::GetKnockedOut() const (high): loads the byte at this+0x929 into al (same caveat as GetCloseCombatStrength).
static u8 THISCALL ffActorGetKnockedOut(u8 *self) {
  return self[0x929];
}
PCREG(59fe70, ffActorGetKnockedOut);

// 0x59feb0, ZFFActor::GetLastHitRef() const (high): returns the dword at this+0x907.
static u32 THISCALL ffActorGetLastHitRef(u8 *self) {
  return *(u32 *)(self + 0x907);
}
PCREG(59feb0, ffActorGetLastHitRef);

// 0x59fe80, ZFFActor::GetLastHitPos(float*) (high): copies the three dwords at this+0x8fb, +0x8ff, +0x903 to out[0..2].
// Stdcall-style callee pop (ret 4) for the one argument.
static void THISCALL ffActorGetLastHitPos(u8 *self, u32 *out) {
  out[0] = *(u32 *)(self + 0x8fb);
  out[1] = *(u32 *)(self + 0x8ff);
  out[2] = *(u32 *)(self + 0x903);
}
PCREG(59fe80, ffActorGetLastHitPos);

// 0x5a2970, ZFFActor::ResetHitsOnObstacle() (high): stores 0 at the dword this+0x90b.
static void THISCALL ffActorResetHitsOnObstacle(u8 *self) {
  *(u32 *)(self + 0x90b) = 0;
}
PCREG(5a2970, ffActorResetHitsOnObstacle);

// 0x5a2c30, ZFFActor::SetCloseCombatAttack(bool) (high): flag bit 2 of the dword at this+0x7a6, set when the low byte of
// the argument is nonzero, cleared otherwise.
static void THISCALL ffActorSetCloseCombatAttack(u8 *self, u32 a1) {
  u32 *flags = (u32 *)(self + 0x7a6);
  if ((u8)a1) {
    *flags |= 2;
  } else {
    *flags &= 0xfffffffdu;
  }
}
PCREG(5a2c30, ffActorSetCloseCombatAttack);

// 0x5a2c50, ZFFActor::SetCloseCombatEnable(bool) (high): flag bit 1 of the dword at this+0x7a6.
static void THISCALL ffActorSetCloseCombatEnable(u8 *self, u32 a1) {
  u32 *flags = (u32 *)(self + 0x7a6);
  if ((u8)a1) {
    *flags |= 1;
  } else {
    *flags &= 0xfffffffeu;
  }
}
PCREG(5a2c50, ffActorSetCloseCombatEnable);

// 0x5a2c70, ZFFActor::SetCloseCombatEvade(bool) (high): flag bit 4 of the dword at this+0x7a6.
static void THISCALL ffActorSetCloseCombatEvade(u8 *self, u32 a1) {
  u32 *flags = (u32 *)(self + 0x7a6);
  if ((u8)a1) {
    *flags |= 4;
  } else {
    *flags &= 0xfffffffbu;
  }
}
PCREG(5a2c70, ffActorSetCloseCombatEvade);
