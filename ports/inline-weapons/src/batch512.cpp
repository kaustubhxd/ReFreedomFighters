// batch512.cpp - weapons thread, batch 512: the reload and chamber actions (zlnkwhandsactions.cpp).
// ZActionReloadItem: +8 owner, +0xc hand, anims +0x10 (default), +0x14, +0x18, +0x1c, +0x20, +0x24, +0x28,
// +0x2c chosen anim, +0x30 start time (s), +0x34 time accumulated for shell-by-shell loading, +0x38 time per round
// (0 = whole-magazine reload), +0x3c round cycle time. ZActionChamberItem: +8 owner, +0xc hand, anims +0x10..+0x24,
// +0x28 chosen anim, +0x2c start time. AnimHeader: +0x5c, +0x60 first frame, +0x64 last frame, +0x6c (frames are at
// 25 per second). The owner's slots: 0x560/0x564 Get/SetAmmoFor, 0x128 SendCommand, 0x244 SetBoneFrameBlend,
// 0x458 SetAimInPosition, 0x470/0x474 ShowReloadAnim/ShowChamberAnim.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vU0)(void *self);
typedef u32(THISCALL *vUU)(void *self, u32 a);
typedef u32(THISCALL *vUUU)(void *self, u32 a, u32 b);
typedef u32(THISCALL *vUUUU)(void *self, u32 a, u32 b, u32 c);
typedef u8(THISCALL *vBU)(void *self, u32 a);
typedef u32(THISCALL *vRegMsg)(void *self, const char *name, u32 z, const char *file, u32 line, u32 z1, u32 z2);
typedef void(THISCALL *vBlend)(void *self, u32 anim, float f, float w, u32 b, u32 n);
typedef void *(THISCALL *vLogLine)(void *self, const char *file, u32 line);
typedef void (*logPrintf)(void *self, const char *fmt, ...);
typedef u32 (*hookFn)();

static const char *const kFile = (const char *)0x68cdc4;   // zlnkwhandsactions.cpp
static inline u8 *sys() { return G(u8 *, 0x70039c); }
static inline float nowS() { return (float)*(s32 *)(sys() + 0x40) * 0.0009765625f; }
static inline void sendMsg(u8 *owner, const char *name, u32 line) {
  u8 *rm = *(u8 **)(sys() + 0x9b);
  u32 id = ((vRegMsg)VT(rm, 0x114))(rm, name, 0, kFile, line, 0, 0) & 0xffff;   // six pushes at the exe sites
  ((vUU)VT(owner, 0x128))(owner, id);   // ONE argument at the exe site (movzx eax,ax; push eax; call [esi+0x128])
}
static inline u32 assertHook() {
  hookFn h = G(hookFn, 0x7003b0);
  if (!h)
    __builtin_debugtrap();
  return h();
}
static inline const char *nameOf(u8 *o) {
  const char *n = *(const char **)(o + 4);
  return n ? n : (const char *)0x67c8e8;
}

extern "C" u32 THISCALL ext_4869e0(u8 *a, u8 *tmpl);           // GetChamberAnim
extern "C" void THISCALL ext_486e90(u8 *a, u8 *w, s32 limit);    // ReloadWeapon
extern "C" u8 THISCALL ext_4873f0(u8 *a, u8 *w);                 // WeaponReloaded
extern "C" void THISCALL ext_4863c0(u8 *a, u8 *w);               // ChamberWeapon

static u32 THISCALL reloadGetHand(u8 *a) { return *(u32 *)(a + 0xc); }   // 0x64a6f0 (folded)
PCREG(64a6f0, reloadGetHand);
static float THISCALL reloadGetStartTime(u8 *a) { return *(float *)(a + 0x30); }
PCREG(486cb0, reloadGetStartTime);

// 0x486bb0 GetReloadAnimFromId(id) / 0x486c30 GetReloadAnimId(anim): ids 1..7 <-> +0x10, +0x14, +0x18, +0x1c, +0x24,
// +0x20, +0x28; anything else asserts (the hook's eax is returned).
static u32 THISCALL getReloadAnimFromId(u8 *a, u32 id) {
  switch (id) {
  case 1: return *(u32 *)(a + 0x10);
  case 2: return *(u32 *)(a + 0x14);
  case 3: return *(u32 *)(a + 0x18);
  case 4: return *(u32 *)(a + 0x1c);
  case 5: return *(u32 *)(a + 0x24);
  case 6: return *(u32 *)(a + 0x20);
  case 7: return *(u32 *)(a + 0x28);
  }
  return assertHook();
}
PCREG(486bb0, getReloadAnimFromId);
static u32 THISCALL getReloadAnimId(u8 *a, u32 anim) {
  if (anim == *(u32 *)(a + 0x10)) return 1;
  if (anim == *(u32 *)(a + 0x14)) return 2;
  if (anim == *(u32 *)(a + 0x18)) return 3;
  if (anim == *(u32 *)(a + 0x1c)) return 4;
  if (anim == *(u32 *)(a + 0x24)) return 5;
  if (anim == *(u32 *)(a + 0x20)) return 6;
  if (anim == *(u32 *)(a + 0x28)) return 7;
  return assertHook();
}
PCREG(486c30, getReloadAnimId);

// 0x486aa0 GetReloadAnim(template): by weapon type. Type 5 also sets shell-by-shell timing (0.44 s per round, cycle
// 0.68 s). Types 11 and 12 have no reload (0). Unknown types warn "Unable to locate reload animation for %s".
static u32 THISCALL getReloadAnim(u8 *a, u8 *t) {
  *(u32 *)(a + 0x38) = 0;
  u32 ty = ((vU0)VT(t, 0x330))(t);
  u32 r;
  switch (ty) {
  case 0: return *(u32 *)(a + 0x14);
  case 1: return *(u32 *)(a + 0x10);
  case 2: return *(u32 *)(a + 0x18);
  case 3: case 4: r = *(u32 *)(a + 0x1c); break;
  case 5:
    r = *(u32 *)(a + 0x20);
    *(u32 *)(a + 0x38) = 0x3ee147ae;   // 0.44f
    *(u32 *)(a + 0x3c) = 0x3f2e147b;   // 0.68f
    break;
  case 6: r = *(u32 *)(a + 0x24); break;
  case 7: r = *(u32 *)(a + 0x28); break;
  case 11: case 12: return 0;
  default: {
    u8 *l = G(u8 *, 0x700390);
    void *st = ((vLogLine)VT(l, 0x20))(l, kFile, 0x27f);
    ((logPrintf)VT(st, 0x2c))(st, (const char *)0x68ce50, nameOf(t));
    return *(u32 *)(a + 0x10);
  }
  }
  return r ? r : *(u32 *)(a + 0x10);
}
PCREG(486aa0, getReloadAnim);

// 0x4869e0 ZActionChamberItem::GetChamberAnim(template): types 0-2 the default anim (+0x10), 3-4 +0x14, 5 +0x18,
// 6 +0x1c, 7 +0x20, 11 +0x24; others warn "Unable to locate chamber animation for %s" and use the default.
static u32 THISCALL getChamberAnim(u8 *a, u8 *t) {
  switch (((vU0)VT(t, 0x330))(t)) {
  case 0: case 1: case 2: return *(u32 *)(a + 0x10);
  case 3: case 4: return *(u32 *)(a + 0x14);
  case 5: return *(u32 *)(a + 0x18);
  case 6: return *(u32 *)(a + 0x1c);
  case 7: return *(u32 *)(a + 0x20);
  case 11: return *(u32 *)(a + 0x24);
  }
  u8 *l = G(u8 *, 0x700390);
  void *st = ((vLogLine)VT(l, 0x20))(l, kFile, 0x381);
  ((logPrintf)VT(st, 0x30))(st, (const char *)0x68ce90, nameOf(t));
  return *(u32 *)(a + 0x10);
}
PCREG(4869e0, getChamberAnim);

// 0x486e90 ReloadWeapon(weapon, limit): load min(clip - inMag, spare) rounds (at most `limit` when limit != 0),
// take them from the spare ammo, chamber a bullet, item state 0.
static void THISCALL reloadWeapon(u8 *a, u8 *w, s32 limit) {
  u8 *o = *(u8 **)(a + 8);
  s32 spare = (s32)((vUU)VT(o, 0x560))(o, (u32)w);
  s32 clip = (s32)((vU0)VT(w, 0x364))(w);
  s32 cur = (s32)((vU0)VT(w, 0x35c))(w);
  s32 n = cur + spare;
  if (clip < n)
    n = clip;
  n -= cur;
  if (limit && limit < n)
    n = limit;
  o = *(u8 **)(a + 8);
  ((vUUU)VT(o, 0x564))(o, (u32)w, (u32)(spare - n));
  ((vUU)VT(w, 0x360))(w, (u32)(cur + n));
  ((vUU)VT(w, 0x358))(w, 1);
  ((vUUU)VT(w, 0x2d0))(w, 0, 0);
}
PCREG(486e90, reloadWeapon);

// 0x4873f0 WeaponReloaded(weapon): no spare ammo left, or the magazine is full.
static u8 THISCALL weaponReloaded(u8 *a, u8 *w) {
  u8 *o = *(u8 **)(a + 8);
  u32 spare = ((vUU)VT(o, 0x560))(o, (u32)w);
  u32 clip = ((vU0)VT(w, 0x364))(w);
  u32 cur = ((vU0)VT(w, 0x35c))(w);
  return !spare || clip == cur;
}
PCREG(4873f0, weaponReloaded);

// 0x4870c0 Terminate(): owner gets the "ReloadDone" message (line 0x307).
static void THISCALL reloadTerminate(u8 *a) { sendMsg(*(u8 **)(a + 8), (const char *)0x68ce84, 0x307); }
PCREG(4870c0, reloadTerminate);

// 0x486900 ZActionReloadItem::Execute(): weapon state 0, start 0x133 ticks (0.3 s) from now, pick the animation,
// "Reload" message to the owner (line 0x2b6).
static u8 THISCALL reloadExecute(u8 *a) {
  u8 *hd = *(u8 **)(a + 0xc);
  u8 *w = (u8 *)((vU0)VT(hd, 0x10))(hd);
  ((vUUU)VT(w, 0x2d0))(w, 0, 0);
  *(u32 *)(a + 0x34) = 0;
  *(float *)(a + 0x30) = (float)(s32)(*(u32 *)(sys() + 0x40) + 0x133) * 0.0009765625f;
  u32 t = ((vU0)VT(w, 0x350))(w);
  *(u32 *)(a + 0x2c) = ((vUU)VT(a, 0x24))(a, t);
  sendMsg(*(u8 **)(a + 8), (const char *)0x686794, 0x2b6);
  return 1;
}
PCREG(486900, reloadExecute);

// 0x487230 ZActionReloadItem::Update(): returns 1 while running, 0 when done. Without an animation the reload is
// immediate. Before the start time nothing happens. Whole-magazine reloads (+0x38 == 0) finish when the animation
// has played through (frames / 25 s). Shell-by-shell reloads load one round every cycle (+0x3c - +0x38) of
// accumulated frame time ([0x70039c]+0x48), and finish 0.6 s after the weapon is full or out of spare ammo. The
// animation frame is driven by hand (SetBoneFrameBlend) when the owner shows reload animations.
static u8 THISCALL reloadUpdate(u8 *a) {
  u8 *hd = *(u8 **)(a + 0xc);
  u8 *w = (u8 *)((vU0)VT(hd, 0x10))(hd);
  if (!w)
    return 0;
  if (!*(u32 *)(a + 0x2c)) {
    ((vUUU)VT(w, 0x2d0))(w, 5, 0);
    ext_486e90(a, w, 0);
    return 0;
  }
  float now = nowS();
  if (*(float *)(a + 0x30) > now)
    return 1;
  ((vUUU)VT(w, 0x2d0))(w, 5, 0);
  float blend = 0.0f;
  u8 *anim = *(u8 **)(a + 0x2c);
  s32 frames = *(s32 *)(anim + 0x64) - *(s32 *)(anim + 0x60);
  if (frames) {
    float per = *(float *)(a + 0x38);
    float t;
    if (per == 0.0f) {
      t = (now - *(float *)(a + 0x30)) / ((float)frames / 25.0f);
      blend = t;
      if (t > 1.0f) {
        ext_486e90(a, w, 0);
        return 0;
      }
      goto show;
    }
    if (per > now) {
      t = now - *(float *)(a + 0x30);
    } else {
      *(float *)(a + 0x34) = *(float *)(sys() + 0x48) + *(float *)(a + 0x34);
      if (!ext_4873f0(a, w)) {
        if (*(float *)(a + 0x34) > *(float *)(a + 0x3c) - *(float *)(a + 0x38)) {
          ext_486e90(a, w, 1);
          *(u32 *)(a + 0x34) = 0;
        }
        t = *(float *)(a + 0x34) + *(float *)(a + 0x38);
      } else {
        t = *(float *)(a + 0x34);
        if (t > 0.6f)
          return 0;
        t = t + 0.8f;
      }
    }
    blend = t / ((float)frames / 25.0f);
  }
show:
  u8 *o = *(u8 **)(a + 8);
  if (((vBU)VT(o, 0x470))(o, (u32)w)) {
    o = *(u8 **)(a + 8);
    ((vBlend)VT(o, 0x244))(o, *(u32 *)(a + 0x2c), blend, 1.0f, 0, 1);
  }
  o = *(u8 **)(a + 8);
  ((vUU)VT(o, 0x458))(o, 0);
  return 1;
}
PCREG(487230, reloadUpdate);

// 0x4863c0 ZActionChamberItem::ChamberWeapon(weapon): bullet chambered, state 0, "ChamberDone" (line 0x39c).
static void THISCALL chamberWeapon(u8 *a, u8 *w) {
  ((vUU)VT(w, 0x358))(w, 1);
  ((vUUU)VT(w, 0x2d0))(w, 0, 0);
  sendMsg(*(u8 **)(a + 8), (const char *)0x68cec4, 0x39c);
}
PCREG(4863c0, chamberWeapon);

// 0x486430 ZActionChamberItem::Execute(): start 0.3 s from now, pick the chamber animation.
static u8 THISCALL chamberExecute(u8 *a) {
  u8 *hd = *(u8 **)(a + 0xc);
  u8 *w = (u8 *)((vU0)VT(hd, 0x10))(hd);
  *(float *)(a + 0x2c) = (float)(s32)(*(u32 *)(sys() + 0x40) + 0x133) * 0.0009765625f;
  u8 *t = (u8 *)((vU0)VT(w, 0x350))(w);
  *(u32 *)(a + 0x28) = ext_4869e0(a, t);
  return 1;
}
PCREG(486430, chamberExecute);

// 0x487110 ZActionChamberItem::Update(): like the whole-magazine reload: chamber when the animation has played
// (or at once without one); frame driven by hand with weight anim+0x5c / anim+0x6c.
static u8 THISCALL chamberUpdate(u8 *a) {
  u8 *hd = *(u8 **)(a + 0xc);
  u8 *w = (u8 *)((vU0)VT(hd, 0x10))(hd);
  if (!w)
    return 0;
  if (!*(u32 *)(a + 0x28)) {
    ((vUUU)VT(w, 0x2d0))(w, 6, 0);
    ext_4863c0(a, w);
    return 0;
  }
  float now = nowS();
  if (*(float *)(a + 0x2c) > now)
    return 1;
  ((vUUU)VT(w, 0x2d0))(w, 6, 0);
  float blend = 0.0f;
  u8 *anim = *(u8 **)(a + 0x28);
  s32 frames = *(s32 *)(anim + 0x64) - *(s32 *)(anim + 0x60);
  if (frames) {
    float t = (now - *(float *)(a + 0x2c)) / ((float)frames / 25.0f);
    blend = t;
    if (t > 1.0f) {
      ext_4863c0(a, w);
      return 0;
    }
  }
  u8 *o = *(u8 **)(a + 8);
  if (((vBU)VT(o, 0x474))(o, (u32)w)) {
    anim = *(u8 **)(a + 0x28);
    o = *(u8 **)(a + 8);
    float wgt = (float)*(s32 *)(anim + 0x5c) / (float)*(s32 *)(anim + 0x6c);
    ((vBlend)VT(o, 0x244))(o, (u32)anim, blend, wgt, 0, 1);
  }
  o = *(u8 **)(a + 8);
  ((vUU)VT(o, 0x458))(o, 0);
  return 1;
}
PCREG(487110, chamberUpdate);

// 0x595210 ZFFHERO::ShowReloadAnim / ShowChamberAnim (one folded body): no animation for weapon type 7 (the sniper
// rifle, guess) while the camera helper's aim lock byte +0xb45 is set (scoped).
static u8 THISCALL showReloadAnim(u8 *self, u8 *w) {
  u8 *t = (u8 *)((vU0)VT(w, 0x350))(w);
  if (((vU0)VT(t, 0x330))(t) == 7 && (*(u8 **)(self + 0x85a))[0xb45])
    return 0;
  return 1;
}
PCREG(595210, showReloadAnim);
