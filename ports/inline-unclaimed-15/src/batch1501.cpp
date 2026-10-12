#include "ff.h"
// batch1501.cpp - unclaimed-15 claim 1 (docs/20-unclaimed-15.md): ZFFActor combat flags and last hit point.
// Names from the GC name map (naming only). All thiscall. The flag word at +0x7a6 is read and written as a dword
// (the exe uses `or`/`and` on dword memory), so the port does the same.

// 0x5a2c30, ZFFActor::SetCloseCombatAttack(bool) (high): bit 0x2 of the dword at +0x7a6 follows the low byte of the arg.
static void THISCALL ffActorSetCloseCombatAttack(u8 *self, u32 a1) {
  if ((u8)a1)
    *(u32 *)(self + 0x7a6) |= 0x2u;
  else
    *(u32 *)(self + 0x7a6) &= ~0x2u;
}
PCREG(5a2c30, ffActorSetCloseCombatAttack);

// 0x5a2c50, ZFFActor::SetCloseCombatEnable(bool) (high): bit 0x1 of the dword at +0x7a6 follows the low byte of the arg.
static void THISCALL ffActorSetCloseCombatEnable(u8 *self, u32 a1) {
  if ((u8)a1)
    *(u32 *)(self + 0x7a6) |= 0x1u;
  else
    *(u32 *)(self + 0x7a6) &= ~0x1u;
}
PCREG(5a2c50, ffActorSetCloseCombatEnable);

// 0x5a2c70, ZFFActor::SetCloseCombatEvade(bool) (high): bit 0x4 of the dword at +0x7a6 follows the low byte of the arg.
static void THISCALL ffActorSetCloseCombatEvade(u8 *self, u32 a1) {
  if ((u8)a1)
    *(u32 *)(self + 0x7a6) |= 0x4u;
  else
    *(u32 *)(self + 0x7a6) &= ~0x4u;
}
PCREG(5a2c70, ffActorSetCloseCombatEvade);

// 0x59fe80, ZFFActor::GetLastHitPos(float*) (high): copies the three dwords at +0x8fb, +0x8ff, +0x903 to the out
// pointer. No return value (ret 4).
static void THISCALL ffActorGetLastHitPos(u8 *self, u32 out) {
  ((u32 *)out)[0] = *(u32 *)(self + 0x8fb);
  ((u32 *)out)[1] = *(u32 *)(self + 0x8ff);
  ((u32 *)out)[2] = *(u32 *)(self + 0x903);
}
PCREG(59fe80, ffActorGetLastHitPos);
