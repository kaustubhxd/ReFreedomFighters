// batch1614.cpp - small ZDllSound helpers under the shouts (soundtimers thread). Sound data offsets are relative to
// the loaded block at +0x5302; record types: 1 wave, 2 sound, 3 sound set.
#include "st.h"

static inline u8 *base(void *self) { return AT(u8 *, self, 0x5302); }

// 0x537770 ZDllSound::GetSoundObject(int id) [high]: base + id (0 for id 0 or no data).
u8 *THISCALL ZDllSound_GetSoundObject(void *self, u32 id) {
  u8 *b = base(self);
  if (!b || !id) return 0;
  return (u8 *)((u32)b + id);
}
PCREG(537770, ZDllSound_GetSoundObject);

// 0x537310 ZDllSound::GetName(SSoundBase*) [high]: base + record +4 (the name offset), 0 when absent.
const char *THISCALL ZDllSound_GetName(void *self, u8 *rec) {
  u8 *b = base(self);
  if (!b || !rec) return 0;
  u32 n = AT(u32, rec, 4);
  if (!n) return 0;
  return (const char *)((u32)b + n);
}
PCREG(537310, ZDllSound_GetName);

// 0x537790 ZDllSound::GetWave(SSoundBase*) [high]: a wave is itself; a sound (type 2) gives base + its +8 (wave
// offset); anything else 0.
u8 *THISCALL ZDllSound_GetWave(void *self, u8 *rec) {
  u8 *b = base(self);
  if (!b || !rec) return 0;
  u32 t = AT(u32, rec, 0);
  if (t == 1) return rec;
  if (t != 2) return 0;
  u32 w = AT(u32, rec, 8);
  if (!w) return 0;
  return (u8 *)((u32)b + w);
}
PCREG(537790, ZDllSound_GetWave);

// 0x537e40 ZDllSound::IsWave(int id) [high]: the record at id has type 1.
u8 THISCALL ZDllSound_IsWave(void *self, u32 id) {
  if (!id) return 0;
  u8 *b = base(self);
  if (!b) return 0;
  return AT(u32, b, id) == 1;
}
PCREG(537e40, ZDllSound_IsWave);

// 0x537e00 ZDllSound::IsPlayingMono(int id) [high]: bit 0 of the wave's +8 (GetWave(GetSound(id))), false when either
// is missing. ZIKLNKOBJ::PlaySound starts a sound 3D only when this is true.
u8 THISCALL ZDllSound_IsPlayingMono(void *self, u32 id) {
  u8 *s = vcall<u8 *>(self, 0x40, id);
  if (!s) return 0;
  u8 *w = vcall<u8 *>(self, 0x1dc, s);
  if (!w) return 0;
  return AT(u8, w, 8) & 1;
}
PCREG(537e00, ZDllSound_IsPlayingMono);

// 0x537370 ZDllSound::GetRandomFromSoundSet(SSoundSet*) [high]: member trunc(rnd x count - 0.01), rnd from the engine
// (sys vtable +0x1c0(file, line), x87 float return); x87 arithmetic at the current precision, stored as float.
u32 THISCALL ZDllSound_GetRandomFromSoundSet(void *self, u8 *set) {
  u8 *b = base(self);
  if (!b) return (u32)b;
  u32 *tab = (u32 *)((u32)b + AT(u32, set, 0x10));
  typedef float(THISCALL * RndFn)(void *, const char *, u32);
  void *sys = G(void *, 0x70039c);
  long double r = (*(RndFn *)(*(u8 **)sys + 0x1c0))(sys, (const char *)0x6a1e2c, 0x3ac);
  float cnt = (float)(s32)AT(u16, set, 8);
  long double x = r * (long double)cnt;
  x = x - (long double)bitsf(0x3c23d70a);  // 0.01 at 0x67da00
  float f = (float)x;
  return tab[_mm_cvttss_si32(_mm_set_ss(f))];
}
PCREG(537370, ZDllSound_GetRandomFromSoundSet);

// 0x534d60 ZDllSound::ActorRegister(ZGEOM*) [high]: CEVENTCONTROLLER::AddActor on +0x52fa when there is one.
extern "C" char ext_53a910[];
void THISCALL ZDllSound_ActorRegister(void *self, void *actor) {
  void *ec = AT(void *, self, 0x52fa);
  if (ec) ((void(THISCALL *)(void *, void *))(void *)ext_53a910)(ec, actor);
}
PCREG(534d60, ZDllSound_ActorRegister);

// 0x537400 ZDllSound::GetSound(uint id) [high]: resolves an id to something playable. Needs data whose header record
// (offset at base+0) is not empty. Type 1 (wave) and 2 (sound) are returned as they are; 5 (a reference) follows its
// +8; 3 (a set) picks a random member (as GetRandomFromSoundSet, sound.cpp line 0x490) and repeats until it reaches a
// wave or sound, giving 0 at an empty set; types 4 and 6..16 give 0. A reference to a non-set non-sound record is
// also "picked from" as if it were a set (the original does not check).
u8 *THISCALL ZDllSound_GetSound(void *self, u32 id) {
  if (!id) return 0;
  u8 *b = base(self);
  if (!b) return 0;
  u32 h = AT(u32, b, 0);
  if (AT(u32, b, h + 4) == 0 && AT(u32, b, h) == 0) return 0;
  u8 *rec = (u8 *)((u32)b + id);
  u32 t = AT(u32, rec, 0);
  switch (t) {
    case 1:
    case 2:
      return rec;
    case 3:
      break;
    case 5:
      rec = (u8 *)((u32)b + AT(u32, rec, 8));
      t = AT(u32, rec, 0);
      if (t == 2) return rec;
      break;
    default:
      return 0;
  }
  for (;;) {
    if (t == 2 || t == 1) return rec;
    u32 *tab = (u32 *)((u32)b + AT(u32, rec, 0x10));
    typedef float(THISCALL * RndFn)(void *, const char *, u32);
    void *sys = G(void *, 0x70039c);
    long double r = (*(RndFn *)(*(u8 **)sys + 0x1c0))(sys, (const char *)0x6a1e2c, 0x490);
    u32 cntw = AT(u16, rec, 8);
    b = base(self);
    float cnt = (float)(s32)cntw;
    long double x = r * (long double)cnt;
    x = x - (long double)bitsf(0x3c23d70a);
    float f = (float)x;
    u32 m = tab[_mm_cvttss_si32(_mm_set_ss(f))];
    t = AT(u32, b, m);
    rec = (u8 *)((u32)b + m);
    if (t == 3 && AT(u16, rec, 8) == 0) return 0;
  }
}
PCREG(537400, ZDllSound_GetSound);
