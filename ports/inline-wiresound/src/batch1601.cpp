// batch1601.cpp - ZIKLNKOBJ sound calls under the actor shouts (soundtimers thread, 2026-10-11).
//
// ZIKLNKOBJ (PC, byte-packed) fields used here:
//   +0x008  matrix pointer: 3x3 rotation, position at +0x24 (the actor's root transform; inferred from AddSound3d's
//           (float* mat, float* pos, ...) signature)
//   +0x13a  u8  speech enabled (GC +0x140)
//   +0x13b  u32 sound handle of the current speech (GC +0x144)
//   +0x13f  u32 sound id of the current speech (GC +0x148)
//   +0x143  u8  priority class given to every sound this object starts (copied to the sound object's +0xc)
// Engine: sys = *0x70039c; sys+0x9b = ZEngineDataBase (vtable +0x60 = SRefToPtr(handle) -> object or 0);
// sys+0x1a9f = the sound DLL (ZDllSound; +0xf0 = "is this a 3D sound", inferred from the branch).
// Sound object fields: +0x0c priority class, +0x2c volume category, +0x40 flags, +0x60/+0x64 pitch delta/pitch,
// +0x70 time left (s), +0x78 start delay (s), +0x88 volume, +0xec.. fade-out state (PC packed, GC +0xec/+0xf0/+0xf4/+0xf8).
#include "st.h"

static inline u8 *sys() { return *(u8 *volatile *)0x70039c; }
static inline void *srefToPtr(u32 h) { return vcall<void *>(AT(void *, sys(), 0x9b), 0x60, h); }

typedef u32(THISCALL *AddSound3dFn)(void *grp, float *mat, float *pos, u32 sound, u32, u32, u32);
typedef u32(THISCALL *AddSound2dFn)(void *grp, u32 sound);
extern "C" char ext_43ec00[], ext_43eb80[];  // ZGROUP::AddSound3d [high], ZGROUP::AddSound2d [high]

// 0x466f60 ZIKLNKOBJ::PlaySound(uint sound) [high]: starts a sound on the object's group, 3D at the object's
// transform when the DLL says the sound is 3D, else 2D. Every sound started here gets flag 0x80, volume category 2
// and the object's priority class, and has flag 4 CLEARED (flag 4 = "test against the sound graph", docs/31), so
// character sounds are not culled by rooms.
u32 THISCALL ZIKLNKOBJ_PlaySound1(void *self, u32 sound) {
  void *dll = AT(void *, sys(), 0x1a9f);
  if (!dll) return 0;
  u32 h;
  if (vcall<u8>(dll, 0xf0, sound)) {
    u8 *m = AT(u8 *, self, 8);
    void *grp = vcall<void *>(self, 0x20);
    h = ((AddSound3dFn)(void *)ext_43ec00)(grp, (float *)m, (float *)(m + 0x24), sound, 0, 0, 0);
  } else {
    void *grp = vcall<void *>(self, 0x20);
    h = ((AddSound2dFn)(void *)ext_43eb80)(grp, sound);
  }
  u8 *o = (u8 *)srefToPtr(h);
  if (o) {
    AT(u32, o, 0x40) |= 0x80;
    AT(u32, o, 0x2c) = 2;
    u32 pri = AT(u8, self, 0x143);
    AT(u32, o, 0x40) &= 0xfffffffbu;
    AT(u32, o, 0xc) = pri;
  }
  return h;
}
PCREG(466f60, ZIKLNKOBJ_PlaySound1);

// 0x467c40 ZIKLNKOBJ::Sound_Delete() [GC 8017ed90 by its body and its only caller, ControlSound; not in the map]:
// does not delete, it starts a 0.1 s fade-out of the current speech: fade flag, fade start time (s), start volume,
// volume drop per second = volume / 0.1.
void THISCALL ZIKLNKOBJ_Sound_Delete(void *self) {
  u8 *o = (u8 *)srefToPtr(AT(u32, self, 0x13b));
  if (!o) return;
  AT(u8, o, 0xec) = 1;
  AT(float, o, 0xed) = (float)*(volatile s32 *)(sys() + 0x40) * 0.0009765625f;
  float v = AT(float, o, 0x88);
  AT(float, o, 0xf1) = v;
  AT(float, o, 0xf5) = v / 0.1f;  // 0x67a284
}
PCREG(467c40, ZIKLNKOBJ_Sound_Delete);

// 0x466290 ZIKLNKOBJ::ControlSound(uint sound, bool force) [high]: the one-speech-at-a-time rule. With speech off
// (+0x13a == 0) returns 0. If the current speech still exists and has time left (+0x70 != 0.0; Sound_Playing, inlined):
// without `force` nothing new starts and the current handle is returned; with `force` the current one fades out
// (Sound_Delete) and the new one starts 0.1 s later (+0x78 = 100 x 0.001). Otherwise the new one starts at once.
u32 THISCALL ZIKLNKOBJ_ControlSound(void *self, u32 sound, u32 force) {
  if (!AT(u8, self, 0x13a)) return 0;
  s32 delayMs = 0;
  u8 *cur = (u8 *)srefToPtr(AT(u32, self, 0x13b));
  if (cur) {
    float left = AT(float, cur, 0x70);
    if (!(left == 0.0f)) {  // NaN counts as playing (unordered compare, 0x4662c5)
      if (!(u8)force) return AT(u32, self, 0x13b);
      delayMs = 100;
      ZIKLNKOBJ_Sound_Delete(self);
    }
  }
  u32 h = ZIKLNKOBJ_PlaySound1(self, sound);
  AT(u32, self, 0x13b) = h;
  AT(u32, self, 0x13f) = sound;
  u8 *o = (u8 *)srefToPtr(h);
  if (o) AT(float, o, 0x78) = (float)delayMs * 0.001f;  // 0x67d9fc
  return AT(u32, self, 0x13b);
}
PCREG(466290, ZIKLNKOBJ_ControlSound);

// 0x467060 ZIKLNKOBJ::PlaySound(uint sound, int pitch, bool speech) [high]: speech goes through ControlSound(sound,
// false) (so it is dropped while the actor is still talking), anything else through PlaySound(sound). Then the
// sound's pitch: +0x60 = pitch - old +0x64, +0x64 = pitch.
u32 THISCALL ZIKLNKOBJ_PlaySound3(void *self, u32 sound, s32 pitch, u32 speech) {
  u32 h = (u8)speech ? ZIKLNKOBJ_ControlSound(self, sound, 0) : ZIKLNKOBJ_PlaySound1(self, sound);
  u8 *o = (u8 *)srefToPtr(h);
  if (o) {
    AT(s32, o, 0x60) = pitch - AT(s32, o, 0x64);
    AT(s32, o, 0x64) = pitch;
  }
  return h;
}
PCREG(467060, ZIKLNKOBJ_PlaySound3);

// 0x467000 ZIKLNKOBJ::PlaySound(uint sound, int pitch, int delay_ms, bool speech) [high]: as above, plus a start
// delay in milliseconds (+0x78 = delay x 0.001 s), which overrides ControlSound's 0.1 s.
u32 THISCALL ZIKLNKOBJ_PlaySound4(void *self, u32 sound, s32 pitch, s32 delayMs, u32 speech) {
  u32 h = (u8)speech ? ZIKLNKOBJ_ControlSound(self, sound, 0) : ZIKLNKOBJ_PlaySound1(self, sound);
  u8 *o = (u8 *)srefToPtr(h);
  if (o) {
    AT(s32, o, 0x60) = pitch - AT(s32, o, 0x64);
    AT(s32, o, 0x64) = pitch;
    AT(float, o, 0x78) = (float)delayMs * 0.001f;
  }
  return h;
}
PCREG(467000, ZIKLNKOBJ_PlaySound4);
