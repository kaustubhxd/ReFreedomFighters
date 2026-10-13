#include "ff.h"
// batch3503.cpp - area 35 claim 3 (docs/20-unclaimed-35.md): six small leaves in slice 14. Names from the GC name map (naming only).
// The two tail-jump wrappers call 0x45fa00 and 0x4dcd10, which are stubbed in the harness (thiscall, one argument, ret 4).

extern "C" void THISCALL ext_45fa00(u8 *self, u32 a1);
extern "C" void THISCALL ext_4dcd10(u8 *self, u32 a1);

// 0x481920, ZPlayer::CenterSpeed() const (high): returns this + 0x445.
static u8 *THISCALL zplayerCenterSpeed(u8 *self) {
  return self + 0x445;
}
PCREG(481920, zplayerCenterSpeed);

// 0x483ea0, ZPlayer::GetSoundSet() const (high): returns the dword at this + 0x60e.
static u32 THISCALL zplayerGetSoundSet(u8 *self) {
  return *(u32 *)(self + 0x60e);
}
PCREG(483ea0, zplayerGetSoundSet);

// 0x44c220, ZSNDOBJ::Select(bool) (high): tail jump to 0x45fa00 with the same argument.
static void THISCALL zsndobjSelect(u8 *self, u32 a1) {
  ext_45fa00(self, a1);
}
PCREG(44c220, zsndobjSelect);

// 0x45fd20, ZGEOM::SetPos(const float*) (high): tail jump to 0x4dcd10 with this = the dword at this + 8.
static void THISCALL zgeomSetPos(u8 *self, u32 a1) {
  ext_4dcd10(*(u8 **)(self + 8), a1);
}
PCREG(45fd20, zgeomSetPos);

// 0x47bde0, ZActor::SetFootStepVolume(unsigned int) (medium): stores the argument at this + 0x777.
static void THISCALL actorSetFootStepVolume(u8 *self, u32 a1) {
  *(u32 *)(self + 0x777) = a1;
}
PCREG(47bde0, actorSetFootStepVolume);

// 0x4682e0, ZCTRLIKLNKOBJ::SetController(CONTROLLER) (high): stores the argument at this + 0x1d2.
static void THISCALL ctrlSetController(u8 *self, u32 a1) {
  *(u32 *)(self + 0x1d2) = a1;
}
PCREG(4682e0, ctrlSetController);
