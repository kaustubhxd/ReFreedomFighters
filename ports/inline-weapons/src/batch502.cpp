// batch502.cpp - weapons thread, batch 502: ZItemWeapon fire / reload / chamber state steps and the reload sound.
// More ZItemWeapon fields (PC, byte-packed): +0x5c item state, +0x88 (sound object) volume, +0x92 empty-click sound
// id (guess), +0x96 reload sound id, +0x9a playing reload sound handle, +0xa2/+0xa4/+0xa6 three u16 command ids sent
// to the hand-animation objects, +0xc4 rounds left in the current trigger pull, +0xd1 float time (s) of the next
// allowed shot, +0xfd / +0x101 handles of two attached geoms (guess: magazine models), +0x5c..: see docs/20-weapons.md.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vU0)(void *self);
typedef u32(THISCALL *vUU)(void *self, u32 a);
typedef u32(THISCALL *vUUU)(void *self, u32 a, u32 b);
typedef u32(THISCALL *vUUUU)(void *self, u32 a, u32 b, u32 c);
typedef u8(THISCALL *vB0)(void *self);
typedef u8(THISCALL *vBU)(void *self, u32 a);
typedef float(THISCALL *vF0)(void *self);
typedef void *(THISCALL *vLogLine)(void *self, const char *file, u32 line);
typedef void (*logPrintf)(void *self, const char *fmt, ...);

extern "C" u8 THISCALL ext_4711f0(void *item, u32 state, void *com);   // ZItem::SetState(ITEMSTATE, CCom*)
extern "C" void THISCALL ext_46b440(void *snd, float delay, float time);

static inline u8 *renderMgr() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u32 resolve(u32 h) { u8 *rm = renderMgr(); return ((vUU)VT(rm, 0x58))(rm, h); }
static inline s32 ticks() { return *(s32 *)(G(u8 *, 0x70039c) + 0x40); }   // 1024 per second

// 0x46b440 (no GC name; guess: sound FadeOut(delay, time)): +0xec = 1, +0xed = start time = now - trunc(delay *
// -1024) / 1024, +0xf1 = current volume (+0x88), +0xf5 = volume / time (time 0 counts as 1.0).
static void THISCALL soundFade(u8 *s, float delay, float time) {
  s32 d = _mm_cvttss_si32(_mm_set_ss(delay * -1024.0f));
  s[0xec] = 1;
  u32 t = (u32)ticks() - (u32)d;
  *(float *)(s + 0xed) = (float)(s32)t * 0.0009765625f;
  float v = *(float *)(s + 0x88);
  *(float *)(s + 0xf1) = v;
  if (time == 0.0f)
    time = 1.0f;
  *(float *)(s + 0xf5) = v / time;
}
PCREG(46b440, soundFade);

// 0x470250 ZItemWeapon::PlaySound_Reload(): with a reload sound (+0x96): fade out the one still playing (+0x9a,
// render-manager slot 0x60) over 0.3 s, then play a new one (own slot 0x304 PlaySound) and keep its handle.
static void THISCALL playSoundReload(u8 *self) {
  if (*(u32 *)(self + 0x96) == 0)
    return;
  u32 h = *(u32 *)(self + 0x9a);
  if (h) {
    u8 *rm = renderMgr();
    u8 *s = (u8 *)((vUU)VT(rm, 0x60))(rm, h);
    if (s)
      ext_46b440(s, 0.0f, 0.3f);
  }
  *(u32 *)(self + 0x9a) = ((vUU)VT(self, 0x304))(self, *(u32 *)(self + 0x96));
}
PCREG(470250, playSoundReload);

// 0x46b730 ZItemWeapon::ChamberStart(): with rounds in the magazine, reload sound and item state 6.
static void THISCALL chamberStart(u8 *self) {
  if (((vU0)VT(self, 0x35c))(self) == 0)
    return;
  ((vU0)VT(self, 0x374))(self);
  ext_4711f0(self, 6, 0);
}
PCREG(46b730, chamberStart);

// 0x46b700 ZItemWeapon::ChamberEnd(): with rounds in the magazine, item state 0 and a bullet in the chamber.
static void THISCALL chamberEnd(u8 *self) {
  if (((vU0)VT(self, 0x35c))(self) == 0)
    return;
  ext_4711f0(self, 0, 0);
  self[0xbf] = 1;
}
PCREG(46b700, chamberEnd);

// 0x4703b0 ZItemWeapon::ReloadEnd(): chamber a bullet and set the next-shot time so that the weapon can fire
// 0x66 ticks (~0.1 s) from now: +0xd1 = (now + 0x66 - trunc(timeBetweenShots * 1024)) / 1024.
static void THISCALL reloadEnd(u8 *self) {
  ((vUU)VT(self, 0x358))(self, 1);
  u8 *t = (u8 *)((vU0)VT(self, 0x350))(self);
  u32 base = (u32)ticks() + 0x66;
  long double x = ((vF0)VT(t, 0x338))(t);   // GetTimeBetweenShots, ST0
  float f = (float)(x * 1024.0f);
  base -= (u32)_mm_cvttss_si32(_mm_set_ss(f));
  *(float *)(self + 0xd1) = (float)(s32)base * 0.0009765625f;
}
PCREG(4703b0, reloadEnd);

// 0x471ad0 ZItemWeapon::WeaponReady() const: true for weapons that do not fire projectiles; false with an empty
// chamber; else trunc((timeBetweenShots + nextShotTime) * 1024) <= now (x87 add and multiply, then float).
static u8 THISCALL weaponReady(u8 *self) {
  u8 *t = (u8 *)((vU0)VT(self, 0x350))(self);
  if (!((vB0)VT(t, 0x328))(t))
    return 1;
  if (!self[0xbf])
    return 0;
  t = (u8 *)((vU0)VT(self, 0x350))(self);
  u8 *sys = G(u8 *, 0x70039c);
  long double x = ((vF0)VT(t, 0x338))(t);
  x += *(float *)(self + 0xd1);
  x *= 1024.0f;
  float f = (float)x;
  return _mm_cvttss_si32(_mm_set_ss(f)) <= *(s32 *)(sys + 0x40);
}
PCREG(471ad0, weaponReady);

// 0x46e2d0 ZItemWeapon::FireStart(): needs an ammo template (own slot 0x328), else logs "WARNING: No ammo template
// active for %s" with the item name (+4, "<NONAME>" when null) from zitem.cpp line 0xb4e. Rounds for this trigger
// pull (+0xc4) by weapon operation +0xd5: 0 or 1 -> 1, 2 -> the whole magazine, 3 -> 3 (burst), other -> unchanged;
// capped at the magazine (signed). With rounds and a chambered bullet: EnableClassCall(0x10, 0) (slot 0x110) and
// ClassFrameUpdate (slot 0x160, tail call); otherwise PlaySound(+0x92) (the dry-fire click, guess).
static void THISCALL fireStart(u8 *self) {
  if (((vU0)VT(self, 0x328))(self) == 0) {
    u8 *l = G(u8 *, 0x700390);
    void *s = ((vLogLine)VT(l, 0x20))(l, (const char *)0x6887c4, 0xb4e);   // "..\..\code\engine\geomsextend\zitem.cpp"
    const char *nm = *(const char **)(self + 4);
    if (!nm)
      nm = (const char *)0x67c8e8;   // "<NONAME>"
    ((logPrintf)VT(s, 0x30))(s, (const char *)0x688d3c, nm);
    return;
  }
  switch (*(u32 *)(self + 0xd5)) {
  case 0:
  case 1:
    *(u32 *)(self + 0xc4) = 1;
    break;
  case 2:
    *(u32 *)(self + 0xc4) = *(u32 *)(self + 0xba);
    break;
  case 3:
    *(u32 *)(self + 0xc4) = 3;
    break;
  }
  s32 n = *(s32 *)(self + 0xc4);
  s32 mag = *(s32 *)(self + 0xba);
  if (n < mag)
    mag = n;
  *(s32 *)(self + 0xc4) = mag;
  if (mag != 0 && self[0xbf]) {
    ((vUUU)VT(self, 0x110))(self, 0x10, 0);
    ((vU0)VT(self, 0x160))(self);
    return;
  }
  ((vUU)VT(self, 0x304))(self, *(u32 *)(self + 0x92));
}
PCREG(46e2d0, fireStart);

// 0x470420 ZItemWeapon::ReloadStart(): item state 5; the geom at handle +0xfd gets SendCommand (slot 0x128) of the
// ids at +0xa4 (data 4), +0xa6 (data -1), +0xa2 (data = this). Unless the owner (slot 0x2f4) IsDerivedFrom(0x200074)
// and has a controller (slot 0x420), the geom at handle +0x101 is made active (slot 0x2c) when bit 10 of its
// geom flags (+8 -> +0x3c) is set, and gets the same three commands. Ends with PlaySound_Reload (tail call).
static inline void send3(u8 *self, u8 *g) {
  ((vUUUU)VT(g, 0x128))(g, *(u16 *)(self + 0xa4), 4, 0);
  ((vUUUU)VT(g, 0x128))(g, *(u16 *)(self + 0xa6), 0xffffffffu, 0);
  ((vUUUU)VT(g, 0x128))(g, *(u16 *)(self + 0xa2), (u32)self, 0);
}
static void THISCALL reloadStart(u8 *self) {
  ext_4711f0(self, 5, 0);
  u8 *g = (u8 *)resolve(*(u32 *)(self + 0xfd));
  if (g)
    send3(self, g);
  u8 *o = (u8 *)((vU0)VT(self, 0x2f4))(self);
  if (!(o && ((vBU)VT(o, 0x1e0))(o, 0x200074) && ((vU0)VT(o, 0x420))(o) != 0)) {
    g = (u8 *)resolve(*(u32 *)(self + 0x101));
    if (g) {
      if ((*(u32 *)(*(u8 **)(g + 8) + 0x3c) >> 10) & 1)
        ((vU0)VT(g, 0x2c))(g);
      send3(self, g);
    }
  }
  ((vU0)VT(self, 0x374))(self);
}
PCREG(470420, reloadStart);
