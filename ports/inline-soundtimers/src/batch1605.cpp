// batch1605.cpp - the hero's command lines: ZFFHERO::PlaySound_Command and the speech time-left helper
// (soundtimers thread, 2026-10-11).
//
// ZFFHERO (PC) fields: +0xef2 u32[24] hero lines by index, filled by ZFFHERO::InitSounds (0x592580) from the hero
// sound set (vtable +0x578): 1 *_Die, 2 *_Pain, 3 *_ColdPain, 4 *_Give_Health, 5 *_GiveHealth, 6 *_Pickup_Ammo,
// 7 *_Pickup_FirstAid, 8 *_Pickup_Gun, 9 *_Punch, 10 *_Use_FirstAid, 11 *_Attack, 12 *_Attac, 13 *_Defend,
// 14 *_Defen, 15 *_Formation, 16 *_Formatio, 17 *_Followme, 18 *_Followm, 19 *_Scout, 20 *_Scou, 21 *_Obs, 22 *_Ob,
// 23 *_All* (index 0 unused). +0xf5e = the hero's voice pitch. InitSounds sets the hero's priority class to 4.
#include "st.h"

static inline u8 *sys() { return *(u8 *volatile *)0x70039c; }
static inline void *srefToPtr(u32 h) { return vcall<void *>(AT(void *, sys(), 0x9b), 0x60, h); }

// 0x467ca0 [map: ZFFHERO::IsSoundCommandDone, medium; by body it is ZIKLNKOBJ::Sound_GetTimeLeft (GameCube reference), the
// x87 float return of the current speech's time left (+0x70), 0.0 without one].
float THISCALL ZIKLNKOBJ_Sound_GetTimeLeft(void *self) {
  u8 *o = (u8 *)srefToPtr(AT(u32, self, 0x13b));
  if (o) return AT(float, o, 0x70);
  return 0.0f;
}
PCREG(467ca0, ZIKLNKOBJ_Sound_GetTimeLeft);

static inline void setPitch(void *self, u8 *o) {
  s32 p = AT(s32, self, 0xf5e);
  AT(s32, o, 0x60) = p - AT(s32, o, 0x64);
  AT(s32, o, 0x64) = p;
}

// 0x594040 ZFFHERO::PlaySound_Command(uint line, bool all) [high]: the hero says a squad order and returns how long
// it takes, in ms (the recruits' reply delay, docs/27 E33b). Lines are forced speech (ControlSound(sound, true): the
// line before fades out). The same line again while it still has 0.2 s or more left: nothing, returns 0.
// all: first try the short-pattern line (line + 1, e.g. "*_Attac"); if it exists and starts, that is the whole
// reply. Otherwise the normal line, and with `all` the "*_All*" line queued after it (start delay = the first line's
// time left), returning both lengths together.
s32 THISCALL ZFFHERO_PlaySound_Command(void *self, u32 line, u32 all) {
  u32 *tab = (u32 *)((u8 *)self + 0xef2);
  if (AT(u32, self, 0x13f) == tab[line]) {
    float t = ZIKLNKOBJ_Sound_GetTimeLeft(self);
    if (!(0.2f > t)) return (s32)crt_ftoll_lo(0.0f * 1000.0f);  // 0.2 at 0x67c194
    AT(u32, self, 0x13f) = 0;
  }
  u8 a = (u8)all;
  float t;
  if (a && tab[line + 1]) {
    u32 h = ZIKLNKOBJ_ControlSound(self, tab[line + 1], 1);
    if (h) {
      t = ZIKLNKOBJ_Sound_GetTimeLeft(self);
      u8 *o = (u8 *)srefToPtr(h);
      if (o) setPitch(self, o);
      return (s32)crt_ftoll_lo(t * 1000.0f);
    }
  }
  if (!tab[line]) return (s32)crt_ftoll_lo(0.0f * 1000.0f);
  u32 h = ZIKLNKOBJ_ControlSound(self, tab[line], 1);
  t = ZIKLNKOBJ_Sound_GetTimeLeft(self);
  u8 *o = (u8 *)srefToPtr(h);
  if (o) setPitch(self, o);
  if (!a) return (s32)crt_ftoll_lo(t * 1000.0f);
  float d = t;
  u32 h2 = ZIKLNKOBJ_PlaySound4(self, AT(u32, self, 0xf4e), 0, _mm_cvttss_si32(_mm_set_ss(t * 1000.0f)), 0);
  u8 *o2 = (u8 *)srefToPtr(h2);
  if (!o2) return (s32)crt_ftoll_lo(t * 1000.0f);
  float x = AT(float, o2, 0x70) + d;
  setPitch(self, o2);
  return (s32)crt_ftoll_lo(x * 1000.0f);
}
PCREG(594040, ZFFHERO_PlaySound_Command);
