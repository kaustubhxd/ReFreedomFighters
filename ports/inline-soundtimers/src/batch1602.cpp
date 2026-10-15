// batch1602.cpp - ZFFActor shouts: PlaySound_Enum, PlaySound_Command, PlaySound_Enum_Keep, ExpandSoundset, and
// ZFFGameData::GetGameOSD (soundtimers thread, 2026-10-11).
//
// ZFFActor (PC, byte-packed) fields used here:
//   +0x054  ptr to the team record; team number is the dword at +4 (FFActor_If.GetTeam)
//   +0x92e  ZFFHERO* the actor follows (recruit's hero), may be 0
//   +0x936  u32* shout table: sound ids by enum. 38 entries (0..37) after InitSounds, 98 after ExpandSoundset
//   +0x93a  ZCharacterControl* (the scene's Character_Controller), 0 = never speak
//   +0x93e  u8  table already expanded
//   +0x143  u8  priority class of the actor's sounds (ZIKLNKOBJ field; ExpandSoundset sets 3)
// Vtable: +0x680 GetActorSoundSet, +0x684 GetActorVoicePitch, +0x6ec PlaySound_Enum_On_Screen(enum, text, bool).
#include "st.h"

static inline u8 *sys() { return *(u8 *volatile *)0x70039c; }
static inline void *srefToPtr(u32 h) { return vcall<void *>(AT(void *, sys(), 0x9b), 0x60, h); }

extern "C" void *ext_41e290(u32 size);                          // __builtin_new [low; operator new by use]
extern "C" void *ext_634d10(void *d, int v, u32 n);              // memset (CRT)
extern "C" void ext_634273(void *p, u32 size);                  // __builtin_delete [high] (sized delete)
extern "C" int ext_42ac56(char *buf, const char *fmt, ...);     // _sprintf (CRT)
typedef void *(THISCALL *GetGameOSDFn)(void *gd, u32 idx);
typedef void(THISCALL *AddActorActionMarkerFn)(void *osd, void *actor, u32 kind, float t);
extern "C" char ext_598e10[];  // ZGameOSD::AddActorActionMarker [high]

// 0x589c20 ZFFGameData::GetGameOSD(char player) [high]: per-player OSD at +0x2c2d (signed index).
void *THISCALL ZFFGameData_GetGameOSD(void *self, u32 idx) { return AT(void *, self, (s32)(s8)idx * 4 + 0x2c2d); }
PCREG(589c20, ZFFGameData_GetGameOSD);

// 0x59fb50 ZFFActor::ExpandSoundset() [high]: once per actor, grows the shout table from 38 to 98 entries and fills
// enums 39..97 with the actor's own numbered lines: enum 38 + i -> FindInSoundSet(set, "*_0<i>*") for i = 1..9,
// "*_<i>*" for i = 10..59. Entry 38 is left 0 (only 0x26 entries are copied). The actor's sound priority class
// becomes 3. With no sound DLL or no sound set the new entries stay 0.
void THISCALL ZFFActor_ExpandSoundset(void *self) {
  if (AT(u8, self, 0x93e)) return;
  u32 set = vcall<u32>(self, 0x680);
  AT(u8, self, 0x143) = 3;
  u32 *nt = (u32 *)ext_41e290(0x188);
  ext_634d10(nt, 0, 0x188);
  u32 *old = AT(u32 *, self, 0x936);
  for (int i = 0; i < 0x26; i++) nt[i] = old[i];
  ext_634273(AT(void *, self, 0x936), 4);
  AT(u32 *, self, 0x936) = nt;
  if (AT(void *, sys(), 0x1a9f) && set) {
    char buf[20];
    u32 off = 0x9c;
    u32 i = 1;
    u8 b = 0;
    do {
      ext_42ac56(buf, b < 9 ? (const char *)0x6aed14 : (const char *)0x6aed1c, i);  // "*_0%i*" / "*_%i*"
      u32 snd = vcall<u32>(AT(void *, sys(), 0x1a9f), 0x60, set, (const char *)buf);  // ZDllSound::FindInSoundSet
      b++;
      i++;
      AT(u32, AT(u8 *, self, 0x936), off) = snd;
      off += 4;
    } while (b < 0x3b);
  }
  AT(u8, self, 0x93e) = 1;
}
PCREG(59fb50, ZFFActor_ExpandSoundset);

static inline u32 team(void *self) { return AT(u32, AT(u8 *, self, 0x54), 4); }
static inline u32 table(void *self, u32 e) { return AT(u32 *, self, 0x936)[e]; }

// 0x5a1b50 ZFFActor::PlaySound_Enum(uchar enum, bool marker, ZFFHERO* hero) [high]: CanIPlay(enum, team), the
// table expansion for enums above 38, then the shout as speech (ZIKLNKOBJ::PlaySound(sound, pitch, true): dropped
// while the actor still talks). With `marker`, the started sound's time left (+0x70, i.e. its length) goes to
// ZGameOSD::AddActorActionMarker(actor, 1, t) on the OSD of the followed hero (+0x92e, else the `hero` argument):
// player index = low byte of hero+0x684, minus 1. Returns the sound handle (0 when refused).
u32 THISCALL ZFFActor_PlaySound_Enum(void *self, u32 e, u32 marker, void *hero) {
  void *cc = AT(void *, self, 0x93a);
  if (!cc) return 0;
  u8 eb = (u8)e;
  if (!ZCharacterControl_CanIPlay(cc, eb, team(self))) return 0;
  if (eb > 0x26) ZFFActor_ExpandSoundset(self);
  s32 pitch = vcall<s32>(self, 0x684);
  u32 h = ZIKLNKOBJ_PlaySound3(self, table(self, eb), pitch, 1);
  if ((u8)marker) {
    u8 *o = (u8 *)srefToPtr(h);
    u8 *x = AT(u8 *, self, 0x92e);
    if (!x) x = (u8 *)hero;
    if (o && x) {
      float t = AT(float, o, 0x70);
      u8 idx = (u8)(AT(u32, x, 0x684) - 1);
      void *osd = ZFFGameData_GetGameOSD(G(void *, 0x7003b8), idx);
      ((AddActorActionMarkerFn)(void *)ext_598e10)(osd, self, 1, t);
    }
  }
  return h;
}
PCREG(5a1b50, ZFFActor_PlaySound_Enum);

// 0x5a1c20 ZFFActor::PlaySound_Enum_Keep(uchar enum) [high]: the table sound as a plain (non-speech) sound, no
// timer check, so it plays even while the actor talks.
u32 THISCALL ZFFActor_PlaySound_Enum_Keep(void *self, u32 e) {
  s32 pitch = vcall<s32>(self, 0x684);
  return ZIKLNKOBJ_PlaySound3(self, table(self, (u8)e), pitch, 0);
}
PCREG(5a1c20, ZFFActor_PlaySound_Enum_Keep);

// 0x5a1ac0 ZFFActor::PlaySound_Command(uchar enum, uint delay_ms, bool onScreen) [high]: a recruit's reply. After
// CanIPlay: on screen with a delay -> ZCharacterControl::Play_OnScreen_Delayed(this, enum, delay, "FF"); on screen
// without -> PlaySound_Enum_On_Screen(enum, "FF", false) now; otherwise the table sound as speech with the delay as a
// start delay (ZIKLNKOBJ::PlaySound(sound, pitch, delay, true)). "FF" is the literal at 0x6a6e64 (speaker tag).
// Returns nothing (EAX is whatever the last call left).
void THISCALL ZFFActor_PlaySound_Command(void *self, u32 e, u32 delay, u32 onScreen) {
  void *cc = AT(void *, self, 0x93a);
  if (!cc) return;
  u32 ee = (u8)e;
  if (!ZCharacterControl_CanIPlay(cc, ee, team(self))) return;
  if ((u8)onScreen) {
    if (delay)
      ZCharacterControl_Play_OnScreen_Delayed(AT(void *, self, 0x93a), self, ee, delay, (const char *)0x6a6e64);
    else
      vcall<void>(self, 0x6ec, e, (const char *)0x6a6e64, (u32)0);  // full dword of the enum argument
    return;
  }
  s32 pitch = vcall<s32>(self, 0x684);
  ZIKLNKOBJ_PlaySound4(self, table(self, ee), pitch, (s32)delay, 1);
}
PCREG(5a1ac0, ZFFActor_PlaySound_Command);
