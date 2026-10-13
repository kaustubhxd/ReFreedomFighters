// batch281.cpp - area 22 gameplay-core batch (docs/20-unclaimed-22.md, "Gameplay core, batch281"): ZActionControlMap::
// FrameUpdate, the per-frame input-to-action step for the hero (camera helper, OSD, menu modes, then the game action
// readers). Name from the GameCube name map; behaviour from the PC bytes.
#include "ff.h"

extern "C" u32 THISCALL ext_591ae0(u8 *hero);                     // ZFFHERO::GetFFCamPtr (GUESS: hooked)
extern "C" u32 THISCALL ext_589c20(u8 *gd, u32 n);                 // ZFFGameData::GetGameOSD (inline-batch45; hooked)
extern "C" u8 *ext_41e290(u32 size);                               // allocator (unclaimed-64; hooked)
extern "C" u8 *THISCALL ext_5f0340(u8 *p, u32 map);                // mode control ctor (unclaimed-76; hooked)
extern "C" u8 *THISCALL ext_5f0450(u8 *p, u32 map);                // CModeControl_Map ctor (GUESS: hooked)
extern "C" void THISCALL ext_53c590(u8 *p, u32 hero, u8 *owner);   // mode control init (GUESS: hooked)
extern "C" void THISCALL ext_5b4b40(u8 *self);                     // ReadFinalGameCheatsActions (GUESS: hooked)
extern "C" void THISCALL ext_5b4160(u8 *self);                     // ReadCommonInputDeviceActions (GUESS: hooked)
extern "C" void THISCALL ext_5b3780(u8 *self);                     // GenerateGameActions (area 22; hooked)
extern "C" void THISCALL ext_5b2e90(u8 *self);                     // FireGameActions (GUESS: hooked)
extern "C" void THISCALL ext_5b2d00(u8 *self);                     // FindGameState (unclaimed-77; hooked)

#define RM (*(u8 **)0x70039cu)

// 0x5b3350 ZActionControlMap::FrameUpdate() (thiscall). The hero +0x5f's camera helper +0x85a is created on first use
// (hero vt 0x100("ZCamHelper")) and copied to +0x63; +0x51 = GetFFCamPtr; +0x5b = GetGameOSD((u8)(hero +0x684 - 1)) on
// the game data [0x7003b8]; +0x55 and +0x56 = the input device (rm vt 0xbc) answers vt 0xb8 and vt 0xc0. On first use
// with an OSD and a hero two mode controls are made (new 0x10 + 0x5f0340(+0x57) into +0x254, new 0x14 + 0x5f0450(+0x57)
// into +0x258, each initialised by 0x53c590(hero, this)). Mode +0x250 == 3 runs +0x258 vt 0; 4 runs +0x254 vt 0 and,
// unless rm byte +0x6c, clears the helper's +0xe0f and +0xe13; any other mode runs the cheat, input, generate, fire and
// game-state steps. SEH frame not reproduced (the constructors are hooked and do not throw).
void THISCALL actionControlMapFrameUpdate_5b3350(u8 *self) {
  u8 *hero = *(u8 **)(self + 0x5f);
  if (!*(u32 *)(hero + 0x85a)) *(u32 *)(hero + 0x85a) = vcall<u32>(hero, 0x100, 0x6a6e88u);
  *(u32 *)(self + 0x63) = *(u32 *)(hero + 0x85a);
  *(u32 *)(self + 0x51) = ext_591ae0(*(u8 **)(self + 0x5f));
  u8 n = (u8)(*(u32 *)(*(u8 **)(self + 0x5f) + 0x684) - 1);
  *(u32 *)(self + 0x5b) = ext_589c20(*(u8 **)0x7003b8u, n);
  u8 *dev = (u8 *)vcall<u32>(RM, 0xbc);
  self[0x55] = (u8)vcall<u32>(dev, 0xb8);
  dev = (u8 *)vcall<u32>(RM, 0xbc);
  self[0x56] = (u8)vcall<u32>(dev, 0xc0);
  if (!*(u32 *)(self + 0x254) && *(u32 *)(self + 0x5b) && *(u32 *)(self + 0x5f)) {
    u8 *p = ext_41e290(0x10);
    p = p ? ext_5f0340(p, *(u32 *)(self + 0x57)) : 0;
    *(u8 **)(self + 0x254) = p;
    ext_53c590(p, *(u32 *)(self + 0x5f), self);
    u8 *q = ext_41e290(0x14);
    q = q ? ext_5f0450(q, *(u32 *)(self + 0x57)) : 0;
    *(u8 **)(self + 0x258) = q;
    ext_53c590(q, *(u32 *)(self + 0x5f), self);
  }
  u32 mode = *(u32 *)(self + 0x250);
  if (mode == 3) {
    vcall<void>(*(u8 **)(self + 0x258), 0);
    return;
  }
  if (mode == 4) {
    vcall<void>(*(u8 **)(self + 0x254), 0);
    if (RM[0x6c]) return;
    *(u32 *)(*(u8 **)(self + 0x63) + 0xe0f) = 0;
    *(u32 *)(*(u8 **)(self + 0x63) + 0xe13) = 0;
    return;
  }
  ext_5b4b40(self);
  ext_5b4160(self);
  ext_5b3780(self);
  ext_5b2e90(self);
  ext_5b2d00(self);
}
PCREG(5b3350, actionControlMapFrameUpdate_5b3350);
#undef RM
