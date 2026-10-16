// batch503.cpp - weapons thread, batch 503: ZItemTemplateWeapon and ZItemTemplateAmmo (the weapon/ammo data read
// from the level files), damage and impact falloff, recoil, fire-mode cycling, muzzle-flash part lookups.
// ZItemTemplateWeapon fields (PC, byte-packed): +0x98 weapon-operation bit mask, +0x9c weapon type, +0xa0 ammo
// template list, +0xa4 default rounds per magazine, +0xa8 muzzle velocity, +0xac precision (degrees; also the recoil
// input), +0xb0 near range, +0xb4 far range, +0xb8 damage multiplier, +0xbc impact, +0xc0 time between shots,
// +0xc4 can fire projectiles, +0xc5 can have magazines, +0xc6 has sniper mode, +0xc7 weapon parts, +0xcb weapon
// flash group handle, +0xcf sound set, +0xd3 pitch change.
// ZItemTemplateAmmo: +0x7c default rounds per magazine, +0x80 projectiles per shot, +0x84 near damage, +0x88 far
// damage, +0x8c ammo type (>= 5 is "heavy caliber"), +0x90 projectile handle, +0x94 cartridge handle,
// +0x98 projectile-instance handle array, +0x9c its count, +0xa0 next index.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vU0)(void *self);
typedef u32(THISCALL *vUU)(void *self, u32 a);
typedef u32(THISCALL *vUUU)(void *self, u32 a, u32 b);
typedef long double(THISCALL *vLD0)(void *self);
typedef void *(THISCALL *vLogLine)(void *self, const char *file, u32 line);
typedef void (*logPrintf)(void *self, const char *fmt, ...);

static const char *const kItemCpp = (const char *)0x6887c4;   // "..\..\code\engine\geomsextend\zitem.cpp"
static inline u8 *renderMgr() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u32 resolve(u32 h) { u8 *rm = renderMgr(); return ((vUU)VT(rm, 0x58))(rm, h); }
static inline void *logAt(u32 line) {
  u8 *l = G(u8 *, 0x700390);
  return ((vLogLine)VT(l, 0x20))(l, kItemCpp, line);
}
static inline const char *nameOf(u8 *o) {
  const char *n = *(const char **)(o + 4);
  return n ? n : (const char *)0x67c8e8;   // "<NONAME>"
}

// ---------------------------------------------------------------------------------------------- plain getters
#define GETU(addr, nm, off) static u32 THISCALL nm(u8 *s) { return *(u32 *)(s + off); } PCREG(addr, nm);
#define GETB(addr, nm, off) static u8 THISCALL nm(u8 *s) { return s[off]; } PCREG(addr, nm);
#define GETF(addr, nm, off) static float THISCALL nm(u8 *s) { return *(float *)(s + off); } PCREG(addr, nm);
GETB(46b6e0, twCanFireProjectiles, 0xc4)
GETB(46b6f0, twCanHaveMagazines, 0xc5)
GETU(46e6a0, twGetDefaultProjectilesPerMagazine, 0xa4)
GETF(46e6c0, twGetFarRange, 0xb4)
GETF(46ecd0, twGetMuzzleVelocity, 0xa8)
GETF(46ecf0, twGetNearRange, 0xb0)
GETU(46ed10, twGetPitchChange, 0xd3)
GETF(46ed20, twGetPrecisionDegrees, 0xac)
GETU(46eec0, twGetSoundSet, 0xcf)
GETF(46ef60, twGetTimeBetweenShots, 0xc0)
GETU(46efb0, twGetWeaponParts, 0xc7)
GETU(46efd0, twGetWeaponType, 0x9c)
GETB(46efe0, twHasSniperMode, 0xc6)
GETU(46e690, taGetDefaultProjectilesPerMagazine, 0x7c)
GETF(46e6b0, taGetFarDamage, 0x88)
GETF(46ece0, taGetNearDamage, 0x84)
GETU(46ee00, taGetProjectilesPerShot, 0x80)
static u32 THISCALL twGetItemClassName(u8 *) { return 0x6867bc; }   // "ZItemWeapon"
PCREG(46e730, twGetItemClassName);
static u32 THISCALL taGetItemClassName(u8 *) { return 0x6864f8; }   // "ZItemAmmo"
PCREG(46e710, taGetItemClassName);
static u8 THISCALL taIsHeavyCaliber(u8 *s) { return *(s32 *)(s + 0x8c) >= 5; }
PCREG(46f500, taIsHeavyCaliber);

// ZItemTemplateAmmo::GetCartridge / GetProjectile: resolve handles +0x94 / +0x90.
static u32 THISCALL taGetCartridge(u8 *s) { return resolve(*(u32 *)(s + 0x94)); }
PCREG(46e590, taGetCartridge);
static u32 THISCALL taGetProjectile(u8 *s) { return resolve(*(u32 *)(s + 0x90)); }
PCREG(46ed30, taGetProjectile);

// 0x46ed50 ZItemTemplateAmmo::GetProjectileInstance(): round-robin over the handle array (+0x98, count +0x9c, next
// +0xa0, wraps to 0 when it reaches the count); the geom is made active (slot 0x2c) when bit 10 of its flags is set.
static u32 THISCALL taGetProjectileInstance(u8 *s) {
  u32 i = *(u32 *)(s + 0xa0);
  u32 h = (*(u32 **)(s + 0x98))[i];
  i++;
  if (i == *(u32 *)(s + 0x9c))
    i = 0;
  *(u32 *)(s + 0xa0) = i;
  u8 *g = (u8 *)resolve(h);
  if ((*(u32 *)(*(u8 **)(g + 8) + 0x3c) >> 10) & 1)
    ((vU0)VT(g, 0x2c))(g);
  return (u32)g;
}
PCREG(46ed50, taGetProjectileInstance);

// 0x46e410 ZItemTemplateWeapon::GetAmmoTemplate(int i): the list at +0xa0 gives a handle (slot 0x30), resolved.
static u32 THISCALL twGetAmmoTemplate(u8 *s, u32 i) {
  u8 *l = *(u8 **)(s + 0xa0);
  u32 h = ((vUU)VT(l, 0x30))(l, i);
  return resolve(h);
}
PCREG(46e410, twGetAmmoTemplate);

// ---------------------------------------------------------------------------------------------- recoil
// 0x46ee10 GetRecoil(): clamp(precision - 1, 0, 10) / 10 (SSE max/min operand order: NaN passes through), x87 divide.
static long double THISCALL twGetRecoil(u8 *s) {
  __m128 v = _mm_sub_ss(_mm_set_ss(*(float *)(s + 0xac)), _mm_set_ss(1.0f));
  v = _mm_max_ss(_mm_setzero_ps(), v);
  v = _mm_min_ss(_mm_set_ss(10.0f), v);
  return (long double)_mm_cvtss_f32(v) / 10.0f;
}
PCREG(46ee10, twGetRecoil);

// ---------------------------------------------------------------------------------------------- damage
// 0x46b5d0 CalcImpact(weapon, dist): impact * 1 up to the near range, * 0 beyond the far range, linear in between.
// Unordered compares fall to the next test exactly like comiss/jb and comiss/jbe.
static long double THISCALL twCalcImpact(u8 *s, void *, float d) {
  float n = *(float *)(s + 0xb0);
  if (!(n < d) && !__builtin_isunordered(n, d))
    return (long double)*(float *)(s + 0xbc) * 1.0f;
  float f = *(float *)(s + 0xb4);
  if (d > f)
    return (long double)*(float *)(s + 0xbc) * 0.0f;
  float k = 1.0f - (d - n) / (f - n);
  return (long double)*(float *)(s + 0xbc) * k;
}
PCREG(46b5d0, twCalcImpact);

// 0x46b4c0 CalcDamage(weapon, dist): the weapon's ammo template (weapon slot 0x328) gives near and far damage
// (slots 0x324 / 0x328); damage = multiplier (+0xb8) * (near damage up to the near range, far damage beyond the far
// range, linear in between). No ammo template: logs "Fired harmless ammo ??" (line 0x89c) and returns 0.
static long double THISCALL twCalcDamage(u8 *s, u8 *w, float d) {
  u8 *a = (u8 *)((vU0)VT(w, 0x328))(w);
  if (!a) {
    void *st = logAt(0x89c);
    ((logPrintf)VT(st, 0x2c))(st, (const char *)0x688bf8);
    return 0.0L;
  }
  float n = *(float *)(s + 0xb0);
  if (!(n < d) && !__builtin_isunordered(n, d)) {
    float nd = (float)((vLD0)VT(a, 0x324))(a);
    return (long double)*(float *)(s + 0xb8) * nd;
  }
  if (d > *(float *)(s + 0xb4)) {
    float fd = (float)((vLD0)VT(a, 0x328))(a);
    return (long double)*(float *)(s + 0xb8) * fd;
  }
  float nd = (float)((vLD0)VT(a, 0x324))(a);
  long double fdx = ((vLD0)VT(a, 0x328))(a);
  float span = (float)((long double)nd - fdx);
  float near_ = *(float *)(s + 0xb0);
  long double nd2 = ((vLD0)VT(a, 0x324))(a);
  float k = (d - near_) / (*(float *)(s + 0xb4) - near_) * span;
  float r = (float)(nd2 - k);
  return (long double)*(float *)(s + 0xb8) * r;
}
PCREG(46b4c0, twCalcDamage);

// ---------------------------------------------------------------------------------------------- fire modes
// 0x470b00 SelectNextWeaponOperation(op): the next fire mode allowed by the mask (own slot 0x334
// GetWeaponOperations, bit n = mode n, re-read for every test). Modes cycle 0 -> 1 -> 3 -> 2 -> 0 (jump table at
// 0x470bd8). A mode above 3 is returned when its own bit (op & 31) is set; otherwise the original loops forever.
// No modes at all: "ERROR: No weapon operations defined for %s" (line 0x7fb) and the old op is returned.
static u32 THISCALL twSelectNextWeaponOperation(u8 *s, u32 op) {
  if (((vU0)VT(s, 0x334))(s) == 0) {
    void *st = logAt(0x7fb);
    ((logPrintf)VT(st, 0x30))(st, (const char *)0x688b24, nameOf(s));
    return op;
  }
#define HAS(n) ((((vU0)VT(s, 0x334))(s) >> (n)) & 1)
  u32 m;
  for (;;) {
    switch (op) {
    case 0: goto t1;
    case 1: goto t3;
    case 2: goto t0;
    case 3: goto t2;
    default:
      if (HAS(op & 31))   // shr eax, cl uses cl & 31
        return op;
      continue;
    }
  }
  for (;;) {
  t2:
    m = 2; if (HAS(2)) return m;
  t0:
    m = 0; if (HAS(0)) return m;
  t1:
    m = 1; if (HAS(1)) return m;
  t3:
    m = 3; if (HAS(3)) return m;
  }
#undef HAS
}
PCREG(470b00, twSelectNextWeaponOperation);

// ---------------------------------------------------------------------------------------------- weapon flash parts
// The weapon-flash geom (handle +0xcb) must be a group (class-info flags +0xc -> +0x23 bit 0x100000), else
// "WARNING: WeaponFlash %s is not a group"; then ZGROUP::FindGeom(name, 0) (slot 0x25c), else "WARNING: %s/<name>
// not found!". Four copies differ only in the part name and the log lines.
static inline u32 flashPart(u8 *s, const char *part, const char *notFound, u32 line1, u32 line2) {
  u8 *g = (u8 *)resolve(*(u32 *)(s + 0xcb));
  if (!g)
    return 0;
  if (!(*(u32 *)(*(u8 **)(g + 0xc) + 0x23) & 0x100000)) {
    void *st = logAt(line1);
    ((logPrintf)VT(st, 0x30))(st, (const char *)0x688b50, nameOf(g));
    return 0;
  }
  u32 r = ((vUUU)VT(g, 0x25c))(g, (u32)part, 0);
  if (r)
    return r;
  void *st = logAt(line2);
  ((logPrintf)VT(st, 0x30))(st, notFound, nameOf(g));
  return 0;
}
static u32 THISCALL twGetMuzzleFire(u8 *s) {
  return flashPart(s, (const char *)0x688b78, (const char *)0x688b84, 0x840, 0x845);   // "MuzzleFire"
}
PCREG(46eac0, twGetMuzzleFire);
static u32 THISCALL twGetMuzzleSmoke(u8 *s) {
  return flashPart(s, (const char *)0x688ba8, (const char *)0x688bb0, 0x85d, 0x862);   // "Smoke"
}
PCREG(46ec20, twGetMuzzleSmoke);
static u32 THISCALL twFlashSmoke2(u8 *s) {   // name map says GetCartridge (low); body is a second "Smoke" lookup
  return flashPart(s, (const char *)0x688ba8, (const char *)0x688bb0, 0x871, 0x876);
}
PCREG(46e5b0, twFlashSmoke2);
static u32 THISCALL twGetMuzzleLight(u8 *s) {
  return flashPart(s, (const char *)0x688bd0, (const char *)0x688bd8, 0x885, 0x88a);   // "Omni01"
}
PCREG(46eb70, twGetMuzzleLight);
