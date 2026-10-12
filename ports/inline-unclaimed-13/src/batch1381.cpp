#include "ff.h"
// batch1381.cpp - unclaimed-13 claim 1 (docs/20-unclaimed-13.md). Names from the GC name map (naming only).
// Each is thiscall, void, ret 4. The bool argument is tested by its low byte (cmp byte ptr [ebp+8], 0).

// 0x5a2c30, ZFFActor::SetCloseCombatAttack(bool) (high): sets bit 0x2 of the dword at this+0x7a6 when the flag is
// nonzero, clears it otherwise.
static void THISCALL ffActorSetCloseCombatAttack(u8 *self, u32 a1) {
  u32 *flags = (u32 *)(self + 0x7a6);
  if ((u8)a1) *flags |= 0x2u;
  else *flags &= 0xfffffffdu;
}
PCREG(5a2c30, ffActorSetCloseCombatAttack);

// 0x5a2c50, ZFFActor::SetCloseCombatEnable(bool) (high): bit 0x1 of the dword at this+0x7a6.
static void THISCALL ffActorSetCloseCombatEnable(u8 *self, u32 a1) {
  u32 *flags = (u32 *)(self + 0x7a6);
  if ((u8)a1) *flags |= 0x1u;
  else *flags &= 0xfffffffeu;
}
PCREG(5a2c50, ffActorSetCloseCombatEnable);

// 0x5a2c70, ZFFActor::SetCloseCombatEvade(bool) (high): bit 0x4 of the dword at this+0x7a6.
static void THISCALL ffActorSetCloseCombatEvade(u8 *self, u32 a1) {
  u32 *flags = (u32 *)(self + 0x7a6);
  if ((u8)a1) *flags |= 0x4u;
  else *flags &= 0xfffffffbu;
}
PCREG(5a2c70, ffActorSetCloseCombatEvade);
