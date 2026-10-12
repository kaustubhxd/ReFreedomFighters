// batch611.cpp - damage thread, batch 611: CHitpointControl::Command (shootable barrels, cars, boxes).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
#define ENGINE G(u8 *, 0x70039c)

extern "C" void THISCALL ext_5849d0(void *self);  // CHitpointControl::Notify (destroyed: message to the target)

typedef void *(THISCALL *vPU)(void *self, u32 a);
typedef u8 *(THISCALL *vCls)(void *self, const char *name, u32 z);
typedef void *(THISCALL *vP0)(void *self);
typedef float (THISCALL *vCalc)(void *self, void *item, float dist);
typedef void (THISCALL *v0)(void *self);
typedef void (THISCALL *vU)(void *self, u32 a);

// Sign flip as the exe does it (xorps with 0x67af40), kept out of clang's reach so a NaN keeps its flipped sign.
static inline float flip(float x) {
  u32 u = fbits(x);
  asm("" : "+r"(u));
  u ^= 0x80000000u;
  asm("" : "+r"(u));
  return bitsf(u);
}

static inline u8 *rm() { return *(u8 **)(ENGINE + 0x9b); }

// Apply a hitpoint change d (negative = damage). Fields: +0x64 HP, +0x4c minimum damage, +0x57 explosion delay.
// Damage only counts while HP > 0 and when -d >= the minimum; healing (d >= 0) is always added. Returns 1 when the
// damage took HP to <= 0.
static int apply(u8 *self, float d) {
  float *hp = (float *)(self + 0x64);
  if (!(0.0f > d)) { *hp = d + *hp; return 0; }
  float h = *hp;
  if (!(h > 0.0f)) return 0;
  float neg = flip(d);
  if (!(neg >= *(float *)(self + 0x4c))) return 0;  // comiss/jb: an unordered compare also skips
  h = h + d;
  *hp = h;
  return h <= 0.0f;
}

// 0x582470 CHitpointControl::Command(unsigned short msg, void* data) (GC 800d01e8). Always returns 0.
//  [0x714278] projectile hit (SHitInfo): only rounds from a weapon derived from "ZItemWeapon"; damage = weapon
//    template CalcDamage(weapon, distance) with no zone multiplier; last attacker +0x6c = SHitInfo +0xc;
//    destroyed -> Notify at once.
//  [0x71427c] damage info (SDamageInfo, e.g. explosions): needs HP > 0 first; attacker +0x6c = info +0;
//    destroyed -> Notify, or own slot 0x64(0x10) (a timer, inferred) when the delay +0x57 is > 0.
//  [0x714280] info query: out[0] = render-manager object of handle +0x5b, out[1] = +0x5f.
//  [0x714284] own slot 0x4c().
static u32 THISCALL hpcCommand(u8 *self, u16 msg, u8 *data) {
  if (msg == *(u16 *)0x714278) {
    if (!((vPU)VT(rm(), 0x58))(rm(), *(u32 *)(data + 8))) return 0;
    u8 *w = (u8 *)((vPU)VT(rm(), 0x58))(rm(), *(u32 *)(data + 8));
    u8 *ci = ((vCls)VT(rm(), 0x154))(rm(), (const char *)0x6867bc, 0);  // "ZItemWeapon"
    if (!(u8)(u32)((vPU)VT(w, 0x1e0))(w, *(u32 *)(ci + 0x23))) return 0;
    u8 *w2 = (u8 *)((vPU)VT(rm(), 0x58))(rm(), *(u32 *)(data + 8));
    if (!w2) return 0;
    u8 *t = (u8 *)((vP0)VT(w2, 0x350))(w2);
    float dmg = ((vCalc)VT(t, 0x35c))(t, w2, *(float *)(data + 0x14));
    float d = flip(dmg);
    *(u32 *)(self + 0x6c) = *(u32 *)(data + 0xc);
    if (apply(self, d)) ext_5849d0(self);
    return 0;
  }
  if (msg == *(u16 *)0x71427c) {
    if (!(*(float *)(self + 0x64) > 0.0f)) return 0;
    *(u32 *)(self + 0x6c) = *(u32 *)data;
    float d = flip(*(float *)(data + 0x28));
    if (apply(self, d)) {
      if (*(float *)(self + 0x57) > 0.0f) ((vU)VT(self, 0x64))(self, 0x10);
      else ext_5849d0(self);
    }
    return 0;
  }
  if (msg == *(u16 *)0x714280) {
    u32 o = (u32)((vPU)VT(rm(), 0x58))(rm(), *(u32 *)(self + 0x5b));
    *(u32 *)data = o;
    *(u32 *)(data + 4) = *(u32 *)(self + 0x5f);
    return 0;
  }
  if (msg == *(u16 *)0x714284) ((v0)VT(self, 0x4c))(self);
  return 0;
}
PCREG(582470, hpcCommand);
