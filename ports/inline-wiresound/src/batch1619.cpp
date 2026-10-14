// batch1619.cpp - hero footstep / SFX wrappers and ZIKLNKOBJ::KillAllSounds (soundtimers thread, 2026-10-11).
#include "st.h"

static inline u8 *sys() { return *(u8 *volatile *)0x70039c; }
static inline void *srefToPtr(u32 h) { return vcall<void *>(AT(void *, sys(), 0x9b), 0x60, h); }
u32 THISCALL ZIKLNKOBJ_PlaySoundFootStep(void *self, u32 right);  // batch 1610
u32 THISCALL ZIKLNKOBJ_PlaySoundSFX(void *self, u32 sound);       // batch 1609

// 0x593fd0 ZFFHERO::PlaySoundFootStep(bool) [high]: silent while status +0x417 has 0x400 (sneaking, docs/31).
u32 THISCALL ZFFHERO_PlaySoundFootStep(void *self, u32 right) {
  if (AT(u32, self, 0x417) & 0x400) return 0;
  return ZIKLNKOBJ_PlaySoundFootStep(self, right);
}
PCREG(593fd0, ZFFHERO_PlaySoundFootStep);

// 0x593ff0 ZFFHERO::PlaySoundSFX(uint) [high]: one hero SFX at a time: while the previous one (+0xf5a) still has
// time left (NaN counts as playing) nothing plays and 0 is returned; otherwise it plays and its handle is kept.
u32 THISCALL ZFFHERO_PlaySoundSFX(void *self, u32 sound) {
  u8 *o = (u8 *)srefToPtr(AT(u32, self, 0xf5a));
  if (o && !(AT(float, o, 0x70) == 0.0f)) return 0;
  u32 h = ZIKLNKOBJ_PlaySoundSFX(self, sound);
  AT(u32, self, 0xf5a) = h;
  return h;
}
PCREG(593ff0, ZFFHERO_PlaySoundSFX);

// 0x466ce0 ZIKLNKOBJ::KillAllSounds() [high] (ActivateRagdoll calls it): the current speech fades out over 0.1 s (as
// Sound_Delete), speech is switched off (+0x13a = 0, so ControlSound never plays again for this object), and the
// sound DLL's +0x84(object) is called (DLL slot named in the doc).
void THISCALL ZIKLNKOBJ_KillAllSounds(void *self) {
  u8 *o = (u8 *)srefToPtr(AT(u32, self, 0x13b));
  if (o) {
    AT(u8, o, 0xec) = 1;
    AT(float, o, 0xed) = (float)*(volatile s32 *)(sys() + 0x40) * 0.0009765625f;
    float v = AT(float, o, 0x88);
    AT(float, o, 0xf1) = v;
    AT(float, o, 0xf5) = v / 0.1f;
  }
  AT(u8, self, 0x13a) = 0;
  void *dll = AT(void *, sys(), 0x1a9f);
  if (dll) vcall<void>(dll, 0x84, self);
}
PCREG(466ce0, ZIKLNKOBJ_KillAllSounds);
