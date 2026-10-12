// batch901.cpp - unclaimed-01: ZActor small setters (docs/20-unclaimed-01.md). Every function is thiscall, void, ret 4.
// Names are from the GC name map (naming only, GUESS where the map is low confidence); the bodies are from the PC bytes.
#include "ff.h"

// 0x479610, ZActor::LookAt(unsigned int) (high): stores the argument at this+0x648.
static void THISCALL actorLookAt(u8 *self, u32 a1) {
  *(u32 *)(self + 0x648) = a1;
}
PCREG(479610, actorLookAt);

// 0x47bd50, ZActor::SetCage(unsigned int) (high): stores the argument at this+0x6bf (unaligned dword).
static void THISCALL actorSetCage(u8 *self, u32 a1) {
  *(u32 *)(self + 0x6bf) = a1;
}
PCREG(47bd50, actorSetCage);

// 0x47bd80, ZActor::SetDisableIdleAnimation(bool) (high): stores the low byte of the argument at this+0x771.
static void THISCALL actorSetDisableIdleAnimation(u8 *self, u32 a1) {
  self[0x771] = (u8)a1;
}
PCREG(47bd80, actorSetDisableIdleAnimation);

// 0x47bdf0, ZActor::SetHero(unsigned int) (high): stores the argument at this+0x492.
static void THISCALL actorSetHero(u8 *self, u32 a1) {
  *(u32 *)(self + 0x492) = a1;
}
PCREG(47bdf0, actorSetHero);

// 0x47be90, ZActor::SetMaxPathLen(float) (high): copies the float argument's bits to this+0x6b6 (no FP operation).
static void THISCALL actorSetMaxPathLen(u8 *self, u32 a1) {
  *(u32 *)(self + 0x6b6) = a1;
}
PCREG(47be90, actorSetMaxPathLen);

// 0x47beb0, ZActor::SetMovePoolWeight(float) (high): copies the float bits to this+0x60f.
static void THISCALL actorSetMovePoolWeight(u8 *self, u32 a1) {
  *(u32 *)(self + 0x60f) = a1;
}
PCREG(47beb0, actorSetMovePoolWeight);

// 0x47bef0, ZActor::SetMoveSpeedMultiplier(float) (high): copies the float bits to this+0x688.
static void THISCALL actorSetMoveSpeedMultiplier(u8 *self, u32 a1) {
  *(u32 *)(self + 0x688) = a1;
}
PCREG(47bef0, actorSetMoveSpeedMultiplier);
