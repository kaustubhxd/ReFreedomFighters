#include "ff.h"
// batch904.cpp - unclaimed-01 claim 3 (docs/20-unclaimed-01.md). Names from the GC name map (naming only).
// Thiscall functions with ret 4 unless noted. Bodies are the PC bytes.

// 0x5a2c90, ZFFActor::SetCloseCombatStrength(short) (high): low word of the argument to this+0x7a4.
static void THISCALL ffActorSetCloseCombatStrength(u8 *self, u32 a1) {
  *(u16 *)(self + 0x7a4) = (u16)a1;
}
PCREG(5a2c90, ffActorSetCloseCombatStrength);

// 0x5a2df0, ZFFActor::SetMinProjectilesWhenDead(short) (medium): low word of the argument to this+0x788.
static void THISCALL ffActorSetMinProjectilesWhenDead(u8 *self, u32 a1) {
  *(u16 *)(self + 0x788) = (u16)a1;
}
PCREG(5a2df0, ffActorSetMinProjectilesWhenDead);

// 0x514470, ZMoveOnSpline::SetStationary(bool) (high): low byte of the argument to this+0x133.
static void THISCALL moveOnSplineSetStationary(u8 *self, u32 a1) {
  self[0x133] = (u8)a1;
}
PCREG(514470, moveOnSplineSetStationary);

// 0x4a1c70, CAction::SetMessage(unsigned short) (high): low word of the argument to this+0x4c.
static void THISCALL actionSetMessage(u8 *self, u32 a1) {
  *(u16 *)(self + 0x4c) = (u16)a1;
}
PCREG(4a1c70, actionSetMessage);

// 0x5ab040, ZOnScreenDisplay::Show(ZOnScreenDisplay::ESHOW) (high): the whole dword argument to this+0x300.
static void THISCALL onScreenDisplayShow(u8 *self, u32 a1) {
  *(u32 *)(self + 0x300) = a1;
}
PCREG(5ab040, onScreenDisplayShow);

// 0x4fda20, CMAINCAMERACONTROL::SetBaseViewport(const float*) (high): copies 16 bytes from the argument to this+0x4e.
static void THISCALL cameraControlSetBaseViewport(u8 *self, u32 a1) {
  const u8 *src = (const u8 *)a1;
  for (u32 i = 0; i < 16; i++)
    self[0x4e + i] = src[i];
}
PCREG(4fda20, cameraControlSetBaseViewport);

// 0x4fc4e0, CMAINCAMERACONTROL::GetBaseViewport(float*) const (high): copies 16 bytes from this+0x4e to the argument.
static void THISCALL cameraControlGetBaseViewport(u8 *self, u32 a1) {
  u8 *dst = (u8 *)a1;
  for (u32 i = 0; i < 16; i++)
    dst[i] = self[0x4e + i];
}
PCREG(4fc4e0, cameraControlGetBaseViewport);

// 0x5a2980, ZFFActor::ResetLastHitPos() (high): three zero dwords at this+0x8fb, +0x8ff and +0x903. No stack arguments.
static void THISCALL ffActorResetLastHitPos(u8 *self) {
  *(u32 *)(self + 0x8fb) = 0;
  *(u32 *)(self + 0x8ff) = 0;
  *(u32 *)(self + 0x903) = 0;
}
PCREG(5a2980, ffActorResetLastHitPos);

// 0x47aab0, ZActor::OnViewLeave() (high): decrements the dword at this+0x640; when that reaches zero and the object
// at this+8 has bit 0x800 clear in the dword at +0x3c, calls vtable slot +0xbc with argument 1. Otherwise returns.
static void THISCALL actorOnViewLeave(u8 *self) {
  u32 *count = (u32 *)(self + 0x640);
  *count = *count - 1u;
  if (*count != 0)
    return;
  u8 *owner = *(u8 **)(self + 8);
  if ((*(u32 *)(owner + 0x3c) & 0x800u) != 0)
    return;
  typedef void(THISCALL * slot_fn)(u8 *, u32);
  slot_fn f = *(slot_fn *)(*(u32 *)self + 0xbc);
  f(self, 1u);
}
PCREG(47aab0, actorOnViewLeave);
