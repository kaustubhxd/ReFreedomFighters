// batch507.cpp - weapons thread, batch 507: ZItemWeapon::FireRound (0x46d8e0), the shot itself.
// What it does, in order (all positions are taken through the item's root transform m/p, GetItemRootTM, slot 0x2c4):
//  1. Projectiles: the template's muzzle geom (+0x11b) gives the muzzle matrix and point. A pending kick vector
//     (+0x109..+0x111, any lane non-zero or NaN) replaces the point and is cleared. A 0x22-byte fire message
//     {owner handle, weapon handle, muzzle velocity, far range, thrown-type flags (type 0xb or 0xc, type 0xc),
//     target[3], precision * spread(+0xcd)} goes to GetProjectilesPerShot projectile instances (round-robin pool of
//     the ammo template), each placed at the muzzle (slot 0x74) and sent the fire command (SendCommandRecursive,
//     slot 0x138, id at +0xa2). No muzzle geom: no projectiles at all.
//  2. Particles through the emitter at handle +0xdd (slot 0x218 = emit(id, pos, vel, time)): ejected shell (+0xe5,
//     from template geom +0x127, sideways velocity (1 - rnd/2) * -1000 along the muzzle's third axis, random +-15 in
//     y and z), muzzle smoke (+0xe9, template geom +0x11f, velocity (1 - rnd/10) * 250 along the second axis), and a
//     5-puff trail (+0xe1, template geom +0x123, each 8 units back along the third axis).
//  3. Muzzle flash geom (handle +0xed) placed at +0xf1 through m/p (slot 0x7c), made active if bit 10 is set.
//  4. Hand-animation commands to the geom at +0xfd (ids +0xa4, +0xa6 with 1 for the last round else 3, +0xa2).
//  5. The playing reload sound (+0x9a) fades out over 0.3 s; the fire sound (+0x8e) plays.
//  6. For an owner that IsDerivedFrom(0x80200014) and weapon types 0, 2, 3, 4: two shell-drop sounds from the
//     sound table at [0x70039c]+0x1a9f ("ShellMetalSmall" group, the owner's surface name +0x14b or +0x147) with random
//     pitch and volume.
//  7. Owner SendCommand(id +0xa8, 0, 0).
// The global byte 0x6ff988 skips everything (guess: an effects-off switch). [0x70039c] slot 0x1c0(file, line) is
// the engine's random float (name map says TimeStampCounter, low; the body is not lifted here).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vU0)(void *self);
typedef u32(THISCALL *vUU)(void *self, u32 a);
typedef u32(THISCALL *vUUU)(void *self, u32 a, u32 b);
typedef u32(THISCALL *vUUUU)(void *self, u32 a, u32 b, u32 c);
typedef u32(THISCALL *vU4)(void *self, u32 a, u32 b, u32 c, u32 d);
typedef u8(THISCALL *vBU)(void *self, u32 a);
typedef long double(THISCALL *vLD0)(void *self);
typedef long double(THISCALL *vRand)(void *self, const char *file, u32 line);

extern "C" void THISCALL ext_4db2c0(void *geom, float *mat, float *pos);   // ZBaseGeom::GetMatPos
extern "C" void THISCALL ext_4db500(void *geom, float *pos);               // ZBaseGeom::GetPos
extern "C" void FASTCALL ext_4de480(float *mat, const float *m);           // mat = mat * m (three vmmul rows)
extern "C" void FASTCALL ext_4419f0(float *v, const float *m);             // vmmul in place
extern "C" void FASTCALL ext_441940(float *a, const float *b);             // PSVECAdd: a += b (x87)
extern "C" void FASTCALL ext_4e0d00(float *v, float s);                    // vscalar
extern "C" void FASTCALL ext_441970(float *out, const float *in, const float *m);   // vmmul
extern "C" void FASTCALL ext_451890(float *a, const float *b, float s);    // vaddscalar: a += b * s

static const char *const kItemCpp = (const char *)0x6887c4;
static inline u8 *sys() { return G(u8 *, 0x70039c); }
static inline u8 *rmgr() { return *(u8 **)(sys() + 0x9b); }
static inline float rnd(u32 line) { u8 *s = sys(); return (float)((vRand)VT(s, 0x1c0))(s, kItemCpp, line); }
static inline long double rndx(u32 line) { u8 *s = sys(); return ((vRand)VT(s, 0x1c0))(s, kItemCpp, line); }

#pragma pack(push, 1)
struct FireMsg {
  u32 owner, weapon;
  float muzzleVelocity, farRange;
  u8 thrown, typeC;
  float target[3];
  float precision;
};
#pragma pack(pop)

static inline void shellSound(u8 *self, u32 snd, u32 l1, float base) {
  u8 *rm = rmgr();
  u8 *s = (u8 *)((vUU)VT(rm, 0x60))(rm, ((vUU)VT(self, 0x304))(self, snd));
  if (!s)
    return;
  float r = rnd(l1);
  *(float *)(s + 0x78) = ((r - 0.5f) * 200.0f + base) * 0.001f;
  float q = (float)((rndx(l1 + 1) - 0.5f) * 40.0f);
  s32 v = _mm_cvttss_si32(_mm_set_ss(q));
  *(s32 *)(s + 0x60) = v - *(s32 *)(s + 0x64);
  *(s32 *)(s + 0x64) = v;
  long double x = rndx(l1 + 2) * 0.75f;
  *(u32 *)(s + 0xc) = 1;
  *(float *)(s + 0x84) = (float)(1.0L - x);
}

static void THISCALL fireRound(u8 *self) {
  if (G(u8, 0x6ff988))
    return;
  u8 *ammo = (u8 *)((vU0)VT(self, 0x328))(self);
  float m[9], p[3], ma[9], a[3], b[3], c[3], m2[9];
  ((vUUU)VT(self, 0x2c4))(self, (u32)m, (u32)p);
  u32 count = ((vU0)VT(ammo, 0x320))(ammo);
  u8 *tw = (u8 *)((vU0)VT(self, 0x350))(self);
  if (*(u8 **)(tw + 0x11b)) {
    ext_4db2c0(*(u8 **)(*(u8 **)(tw + 0x11b) + 8), ma, a);
    ext_4de480(ma, m);
    ext_4419f0(a, m);
    ext_441940(a, p);
    float *k = (float *)(self + 0x109);
    if (k[0] != 0.0f || k[1] != 0.0f || k[2] != 0.0f) {
      a[0] = k[0];
      a[1] = k[1];
      a[2] = k[2];
      *(u32 *)(self + 0x111) = 0;
      *(u32 *)(self + 0x10d) = 0;
      *(u32 *)(self + 0x109) = 0;
    }
    u8 *t = (u8 *)((vU0)VT(self, 0x350))(self);
    u8 thrown;
    if (((vU0)VT(t, 0x330))(t) == 0xb) {
      thrown = 1;
    } else {
      t = (u8 *)((vU0)VT(self, 0x350))(self);
      thrown = ((vU0)VT(t, 0x330))(t) == 0xc;
    }
    t = (u8 *)((vU0)VT(self, 0x350))(self);
    u8 typeC = ((vU0)VT(t, 0x330))(t) == 0xc;
    t = (u8 *)((vU0)VT(self, 0x350))(self);
    float spread = *(float *)(self + 0xcd);
    float prec = (float)(((vLD0)VT(t, 0x350))(t) * spread);
    u8 *tA = (u8 *)((vU0)VT(self, 0x350))(self);
    u8 *tB = (u8 *)((vU0)VT(self, 0x350))(self);
    u32 owner = ((vU0)VT(self, 0x2f4))(self);
    u8 *rm = rmgr();
    u32 h1 = ((vUU)VT(rm, 0x4c))(rm, owner);
    rm = rmgr();
    u32 h2 = ((vUU)VT(rm, 0x4c))(rm, (u32)self);
    float mv = (float)((vLD0)VT(tB, 0x344))(tB);
    float far = (float)((vLD0)VT(tA, 0x34c))(tA);
    float *tg = (float *)((vU0)VT(self, 0x334))(self);
    FireMsg msg;
    msg.owner = h1;
    msg.weapon = h2;
    msg.muzzleVelocity = mv;
    msg.farRange = far;
    msg.thrown = thrown;
    msg.typeC = typeC;
    msg.precision = prec;
    msg.target[0] = tg[0];
    msg.target[1] = tg[1];
    msg.target[2] = tg[2];
    for (u32 n = count; n; n--) {
      u8 *inst = (u8 *)((vU0)VT(ammo, 0x33c))(ammo);
      if (!inst)
        continue;
      ((vUUU)VT(inst, 0x74))(inst, (u32)ma, (u32)a);
      ((vUUUU)VT(inst, 0x138))(inst, *(u16 *)(self + 0xa2), (u32)&msg, 0);
    }
  }
  u8 *rm = rmgr();
  u8 *em = (u8 *)((vUU)VT(rm, 0x58))(rm, *(u32 *)(self + 0xdd));
  if (em) {
    if (*(u32 *)(self + 0xe5) && *(u8 **)(tw + 0x127)) {
      ext_4db500(*(u8 **)(*(u8 **)(tw + 0x127) + 8), b);
      ext_4419f0(b, m);
      ext_441940(b, p);
      a[0] = ma[6];
      a[1] = ma[7];
      a[2] = ma[8];
      float r = rnd(0xbc5);
      ext_4e0d00(a, (1.0f - r * 0.5f) * -1000.0f);
      c[0] = 0.0f;
      c[1] = (float)(rndx(0xbc6) * 30.0f - 15.0f);
      c[2] = (float)(rndx(0xbc6) * 30.0f - 15.0f);
      ext_441940(c, b);
      ((vU4)VT(em, 0x218))(em, *(u32 *)(self + 0xe5), (u32)c, (u32)a, *(u32 *)(sys() + 0x40));
    }
    if (*(u32 *)(self + 0xe9) && *(u8 **)(tw + 0x11f)) {
      ext_4db2c0(*(u8 **)(*(u8 **)(tw + 0x11f) + 8), m2, b);
      ext_4419f0(b, m);
      ext_441940(b, p);
      ext_4de480(m2, m);
      c[0] = m2[3];
      c[1] = m2[4];
      c[2] = m2[5];
      float r = rnd(0xbd6);
      ext_4e0d00(c, (1.0f - r * 0.1f) * 250.0f);
      ((vU4)VT(em, 0x218))(em, *(u32 *)(self + 0xe9), (u32)b, (u32)c, *(u32 *)(sys() + 0x40));
    }
    if (*(u8 **)(tw + 0x123)) {
      ext_4db2c0(*(u8 **)(*(u8 **)(tw + 0x123) + 8), m2, a);
      b[0] = 0.0f;
      b[1] = 0.0f;
      b[2] = 0.0f;
      for (int i = 0; i < 5; i++) {
        ext_441970(c, a, m);
        ext_441940(c, p);
        ((vU4)VT(em, 0x218))(em, *(u32 *)(self + 0xe1), (u32)c, (u32)b, *(u32 *)(sys() + 0x40));
        ext_451890(a, m2 + 6, -8.0f);
      }
    }
  }
  rm = rmgr();
  u8 *fl = (u8 *)((vUU)VT(rm, 0x58))(rm, *(u32 *)(self + 0xed));
  if (fl) {
    ext_441970(b, (float *)(self + 0xf1), m);
    ext_441940(b, p);
    ((vUUU)VT(fl, 0x7c))(fl, (u32)m, (u32)b);
    if ((*(u32 *)(*(u8 **)(fl + 8) + 0x3c) >> 10) & 1)
      ((vU0)VT(fl, 0x2c))(fl);
  }
  rm = rmgr();
  u8 *g = (u8 *)((vUU)VT(rm, 0x58))(rm, *(u32 *)(self + 0xfd));
  if (g) {
    ((vUUUU)VT(g, 0x128))(g, *(u16 *)(self + 0xa4), 0, 0);
    ((vUUUU)VT(g, 0x128))(g, *(u16 *)(self + 0xa6), *(u32 *)(self + 0xba) == 1 ? 1 : 3, 0);
    ((vUUUU)VT(g, 0x128))(g, *(u16 *)(self + 0xa2), (u32)self, 0);
  }
  if (*(u32 *)(self + 0x9a)) {
    rm = rmgr();
    u8 *s = (u8 *)((vUU)VT(rm, 0x60))(rm, *(u32 *)(self + 0x9a));
    if (s) {
      s[0xec] = 1;
      *(float *)(s + 0xed) = (float)*(s32 *)(sys() + 0x40) * 0.0009765625f;
      float v = *(float *)(s + 0x88);
      *(float *)(s + 0xf1) = v;
      *(float *)(s + 0xf5) = v / 0.3f;
    }
  }
  if (*(u32 *)(self + 0x8e)) {
    ((vUU)VT(self, 0x304))(self, *(u32 *)(self + 0x8e));
    if (((vU0)VT(self, 0x2f4))(self)) {
      u8 *o = (u8 *)((vU0)VT(self, 0x2f4))(self);
      if (((vBU)VT(o, 0x1e0))(o, 0x80200014)) {
        u8 *own = (u8 *)((vU0)VT(self, 0x2f4))(self);
        u8 *t = (u8 *)((vU0)VT(self, 0x350))(self);
        u32 ty = ((vU0)VT(t, 0x330))(t);
        if (ty == 0 || ty - 2 <= 2) {
          u8 *sy = sys();
          u32 grp = 0;
          if (*(u8 **)(sy + 0x1a9f)) {
            u8 *tab = *(u8 **)(sy + 0x1a9f);
            grp = ((vUU)VT(tab, 0x5c))(tab, 0x688d64);   // "ShellMetalSmall"
            sy = sys();
          }
          u32 surf = *(u32 *)(own + 0x14b);
          if (!surf)
            surf = *(u32 *)(own + 0x147);
          if (*(u8 **)(sy + 0x1a9f)) {
            u8 *tab = *(u8 **)(sy + 0x1a9f);
            u32 snd = ((vUUU)VT(tab, 0x58))(tab, grp, surf);
            if (snd) {
              shellSound(self, snd, 0xc2b, 550.0f);
              shellSound(self, snd, 0xc34, 850.0f);
            }
          }
        }
      }
    }
  }
  if (((vU0)VT(self, 0x2f4))(self)) {
    u8 *o = (u8 *)((vU0)VT(self, 0x2f4))(self);
    ((vUUUU)VT(o, 0x128))(o, *(u16 *)(self + 0xa8), 0, 0);
  }
}
PCREG(46d8e0, fireRound);
