// batch1608.cpp - ZFFHERO::InitSounds: the hero's line table (soundtimers thread, 2026-10-11).
#include "st.h"

static inline u8 *sys() { return *(u8 *volatile *)0x70039c; }
extern "C" void *ext_634d10(void *d, int v, u32 n);  // memset

// 0x592580 ZFFHERO::InitSounds() [high]: priority class 4, the 24-entry line table at +0xef2 zeroed (0x60 bytes),
// +0xf5a = 0, then with a sound DLL each line is FindInSoundSet(hero sound set (vtable +0x578), pattern); the set is
// not checked for 0. Table index: pattern (see batch1605.cpp for the list).
static void THISCALL ZFFHERO_InitSounds(void *self) {
  AT(u8, self, 0x143) = 4;
  ext_634d10((u8 *)self + 0xef2, 0, 0x60);
  AT(u32, self, 0xf5a) = 0;
  u32 set = vcall<u32>(self, 0x578);
  if (!AT(void *, sys(), 0x1a9f)) return;
  static const struct { u16 off; u32 str; } L[] = {
      {0xef6, 0x6ad0ec},  // *_Die
      {0xf02, 0x6ad0f4},  // *_Give_Health
      {0xf06, 0x6ad104},  // *_GiveHealth
      {0xefa, 0x6ad114},  // *_Pain
      {0xefe, 0x6ad11c},  // *_ColdPain
      {0xf0a, 0x6ad128},  // *_Pickup_Ammo
      {0xf0e, 0x6ad138},  // *_Pickup_FirstAid
      {0xf12, 0x6ad14c},  // *_Pickup_Gun
      {0xf16, 0x6ad15c},  // *_Punch
      {0xf1a, 0x6ad164},  // *_Use_FirstAid
      {0xf1e, 0x6ad174},  // *_Attack
      {0xf22, 0x6ad180},  // *_Attac
      {0xf26, 0x6ad188},  // *_Defend
      {0xf2a, 0x6ad194},  // *_Defen
      {0xf2e, 0x6ad19c},  // *_Formation
      {0xf32, 0x6ad1a8},  // *_Formatio
      {0xf36, 0x6ad1b4},  // *_Followme
      {0xf3a, 0x6ad1c0},  // *_Followm
      {0xf3e, 0x6ad1cc},  // *_Scout
      {0xf42, 0x6ad1d4},  // *_Scou
      {0xf46, 0x6ad1dc},  // *_Obs
      {0xf4a, 0x6ad1e4},  // *_Ob
      {0xf4e, 0x6ad1ec},  // *_All*
  };
  for (const auto &l : L)
    AT(u32, self, l.off) = vcall<u32>(AT(void *, sys(), 0x1a9f), 0x60, set, (const char *)l.str);
}
PCREG(592580, ZFFHERO_InitSounds);
