// batch614.cpp - damage thread, batch 614: small helpers around kill boxes and damage infos.
#include "ff.h"

extern "C" void THISCALL ext_5b1ce0(void *self);              // ZKillBox::Kill (batch 613)
extern "C" void THISCALL ext_5b1f80(void *self);              // ZKillBox::RemoveWeapons
extern "C" void THISCALL ext_475820(void *self, u32 zone, float m);  // ZLNKWHANDS::SetDamageMultForBone

// 0x5b1c90 ZKillBox::FrameUpdate() (GC 800dd7ac): while active (+0x82), Kill then RemoveWeapons every frame.
static void THISCALL killBoxFrameUpdate(u8 *self) {
  if (!self[0x82]) return;
  ext_5b1ce0(self);
  ext_5b1f80(self);
}
PCREG(5b1c90, killBoxFrameUpdate);

// 0x5b1b30 ZKillBox::Command(unsigned short msg, void*) (GC 800dd080): its own trigger message (+0x48) kills once
// (Kill + RemoveWeapons); message [0x714304] deactivates it (+0x82 = 0). Returns 0.
static u32 THISCALL killBoxCommand(u8 *self, u16 msg, void *) {
  if (msg == *(u16 *)(self + 0x48)) {
    ext_5b1ce0(self);
    ext_5b1f80(self);
  }
  if (msg == *(u16 *)0x714304) self[0x82] = 0;
  return 0;
}
PCREG(5b1b30, killBoxCommand);

// 0x5a0ad0 (name map: ZFFActor::IsDead, medium) is really a test on an SDamageInfo: type (+8) is 1, 2 or 3 (close
// combat). OnDamageInfo calls it with ECX = the damage info.
static u8 THISCALL isCloseCombatInfo(u8 *info) {
  u32 t = *(u32 *)(info + 8);
  return t == 1 || t == 2 || t == 3;
}
PCREG(5a0ad0, isCloseCombatInfo);

// 0x5a2d20 ZFFActor::SetHPMultiplierForHeadShot(float) (GC 80074704): sets the multiplier of both head zones (2, 3).
static void THISCALL setHeadShotMultiplier(u8 *self, float m) {
  ext_475820(self, 2, m);
  ext_475820(self, 3, m);
}
PCREG(5a2d20, setHeadShotMultiplier);
