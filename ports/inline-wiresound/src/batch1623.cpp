// batch1623.cpp - master volume setter and the speech fade-out step (soundtimers thread, 2026-10-11).
#include "st.h"

static inline u8 *sys() { return *(u8 *volatile *)0x70039c; }

// 0x539c70 ZDllSound::SetMasterVolume(int percent) [high]: master volume = percent x 0.01 (float), at +0x51b1.
void THISCALL ZDllSound_SetMasterVolume(u8 *self, s32 v) {
  AT(float, self, 0x51b1) = (float)v * 0.01f;
}
PCREG(539c70, ZDllSound_SetMasterVolume);

// 0x44bc00 ZSoundObject::ControlAutoFade() [high]: the fade-out step of a sound with the fade flag +0xec. Nothing
// happens until the fade start time (+0xed, seconds; compared as int ticks against sys+0x40) has passed. Then the
// level drops by (DLL-side value at sys+0x20 when the database call returns nonzero, else the frame step sys+0x48)
// x the fade rate (+0xf5), and +0xf1 keeps the level. When it falls below 1.0 the sound is stopped: type +4 = 3
// (sound-set kind, so the play list drops it), flag +0xec cleared, returns 0; else the level is stored in the volume
// +0x88 and the function returns 1.
// GUESS: what the database call at vtable +0xb8 tests (its nonzero answer picks sys+0x20 over the frame step) is
// not traced; sys+0x20 is read only here.
u8 THISCALL ZSoundObject_ControlAutoFade(u8 *self) {
  if (!AT(u8, self, 0xec)) return 1;
  float start = AT(float, self, 0xed);
  s32 now = AT(s32, sys(), 0x40);
  if (now < _mm_cvttss_si32(_mm_set_ss(start * 1024.0f))) return 1;
  void *db = AT(void *, sys(), 0x9b);
  u8 nz = vcall<u8>(db, 0xb8);
  float step = nz ? AT(float, sys(), 0x20) : AT(float, sys(), 0x48);
  float cur = AT(float, self, 0xf1) - step * AT(float, self, 0xf5);
  AT(float, self, 0xf1) = cur;
  if (1.0f <= cur) {  // comiss with the constant 1.0 at 0x678858
    AT(float, self, 0x88) = cur;
    return 1;
  }
  AT(u32, self, 4) = 3;
  AT(u8, self, 0xec) = 0;
  return 0;
}
PCREG(44bc00, ZSoundObject_ControlAutoFade);
