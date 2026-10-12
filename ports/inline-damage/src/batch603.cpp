// batch603.cpp - damage thread, batch 603: ZFFHERO::OnProjectileHit (a bullet hits the Hero).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
#define ENGINE G(u8 *, 0x70039c)

#pragma pack(push, 1)
struct SIKBoneCollision { u8 zone; u8 front; };
#pragma pack(pop)

extern "C" void THISCALL ext_591820(void *self, u32 msg, void *pair);        // ZFFHERO::ForwardEventToFollowers
extern "C" float FASTCALL ext_4e0870(const float *a, const float *b);        // distance between two points
extern "C" float THISCALL ext_474250(void *self, u32 zone);                  // ZLNKWHANDS::GetDamageMultForBone
extern "C" u8 *THISCALL ext_5af0f0(void *list, u32 id);                      // ZFFInventoryInfoList::GetInventoryInfo
extern "C" float THISCALL ext_58b9c0(void *self, float d, u32 owner, u32 force);  // ZFFHERO::AdjustHitPoints
extern "C" void THISCALL ext_466f60(void *self, u32 snd);                    // ZIKLNKOBJ::PlaySound
extern "C" void THISCALL ext_59a5e0(void *osd, u32 snd);                     // ZGameOSD::PlaySound

typedef void *(THISCALL *vPU)(void *self, u32 a);
typedef void *(THISCALL *vP0)(void *self);
typedef void *(THISCALL *vLog)(void *self, const char *file, u32 line);
typedef void (*vMsg)(void *self, const char *msg);
typedef void (THISCALL *vVP)(void *self, void *p);
typedef void *(THISCALL *vColl)(void *self, SIKBoneCollision *out, const float *pos, const float *dir);
typedef float(THISCALL *vCalc)(void *self, void *item, float dist);
typedef void *(THISCALL *vAnim)(void *self, SIKBoneCollision *zr, u32 a, u32 b);
typedef void (THISCALL *vDie)(void *self, void *anim, u32 a, float f0, float f1);
typedef void (THISCALL *vImp)(void *self, const float *pos, const float *dir, float v);
typedef float(THISCALL *vRand)(void *self, const char *file, u32 line);

static const char *const kFile = (const char *)0x6ac6d0;  // "..\\..\\freedomfighter\\FFBackground\\ZFFHero.cpp"

static void logWarn(u32 line, u32 msg) {
  u8 *lg = G(u8 *, 0x700390);
  u8 *o = (u8 *)((vLog)VT(lg, 0x20))(lg, kFile, line);
  ((vMsg)VT(o, 0x2c))(o, (const char *)msg);
}

static inline u8 *rm() { return *(u8 **)(ENGINE + 0x9b); }

// 0x5936b0 ZFFHERO::OnProjectileHit(SHitInfo*) (GC 8007e02c). See docs/20-damage.md for the walk-through.
static void THISCALL heroOnProjectileHit(u8 *self, u8 *hit) {
  if (*(u32 *)(self + 0x417) & 0x40000) return;
  u8 *shooter = (u8 *)((vPU)VT(rm(), 0x58))(rm(), *(u32 *)(hit + 0xc));
  if (!shooter) { logWarn(0xa06, 0x6ace28); return; }  // "Unable to locate shooting person!"
  if ((u8)(u32)((vPU)VT(shooter, 0x1e0))(shooter, 0x200006)) {
    if (*(u32 *)(*(u8 **)(shooter + 0x54) + 4) == *(u32 *)(*(u8 **)(self + 0x54) + 4)) return;  // same team
    if (*(u32 *)(*(u8 **)(shooter + 0xc) + 0x23) == 0x2003e8) {  // shooter is a ZFFHERO
      *(u8 **)(shooter + 0xf56) = self;
      *(float *)(shooter + 0xf52) = (float)*(s32 *)(ENGINE + 0x40) * 0.0009765625f;
    }
  }
  if (shooter == self) return;
  u32 pair[2];
  pair[0] = (u32)((vPU)VT(rm(), 0x4c))(rm(), (u32)self);
  pair[1] = *(u32 *)(hit + 0xc);
  ext_591820(self, *(u16 *)(self + 0x7de), pair);
  u8 *w = (u8 *)((vPU)VT(rm(), 0x58))(rm(), *(u32 *)(hit + 8));
  if (!w) { logWarn(0xa2c, 0x6ace4c); return; }  // "WARNING: Weapon no longer exists!"
  u8 *t = (u8 *)((vP0)VT(w, 0x350))(w);
  if (!t) return;
  ((vPU)VT(self, 0x594))(self, 0);
  u8 *proj = *(u8 **)hit;
  union { SIKBoneCollision c; u32 word; } zr;
  ((vColl)VT(self, 0x388))(self, &zr.c, (float *)(proj + 0x28), (float *)(proj + 0xc));
  float a[3] = {0, 0, 0}, b[3] = {0, 0, 0};
  ((vVP)VT(shooter, 0x84))(shooter, a);
  ((vVP)VT(self, 0x84))(self, b);
  float dist = ext_4e0870(a, b);
  float raw = ((vCalc)VT(t, 0x35c))(t, w, dist);
  s32 dmg = (s32)raw;
  if (zr.c.zone == 1) {
    s32 armour = *(s32 *)(self + 0x7f7);
    if (dmg > armour) { dmg -= armour; *(s32 *)(self + 0x7f7) = 0; }
    else { *(s32 *)(self + 0x7f7) = armour - dmg; dmg = 0; }
  }
  float mult = ext_474250(self, zr.word);
  float m = mult;
  if ((zr.c.zone == 2 || zr.c.zone == 3) && *(s32 *)(ENGINE + 0x1b5d) == 1) {
    u32 id = (u32)((vP0)VT(w, 0x2e8))(w);
    u8 *info = ext_5af0f0(self + 0x95b, id);
    if (info && *(s32 *)(info + 0x10) == 8) { m = 1.0f; dmg = (s32)*(float *)(self + 0x7ff); }
  }
  float v = (float)dmg * m;
  float hp = ext_58b9c0(self, -v, *(u32 *)(hit + 0xc), 0);
  void *anim = ((vAnim)VT(self, 0x5d4))(self, &zr.c, 0, 0);
  if (hp > 0.0f) {
    ((vVP)VT(self, 0x4d8))(self, anim);
    if (*(u32 *)(self + 0x1e6)) {
      s32 *last = (s32 *)(self + 0x694), *now = (s32 *)(ENGINE + 0x40);
      if (*now > *last + 0x200 && last != now) *last = *now;
    }
  } else {
    ((vDie)VT(self, 0x224))(self, anim, 1, 0.0f, 2.0f);
    u8 *p = *(u8 **)hit;
    ((vImp)VT(self, 0x5bc))(self, (float *)(p + 0x28), (float *)(p + 0xc), v);
  }
  if (G(float, 0x6ffa60) == 0.0f) {  // god-mode float clear
    u8 *e = ENGINE;
    float r = ((vRand)VT(e, 0x1c0))(e, kFile, 0xa6f);
    if (r > 0.5f) ext_466f60(self, *(u32 *)(self + 0xefa));
  }
  s32 i = (s32)(*(float *)(self + 0x94a) * -1024.0f);
  s32 now = *(s32 *)(ENGINE + 0x40);
  if (now > 0x133 - i) *(float *)(self + 0x94a) = (float)now * 0.0009765625f;
  u8 *osd = *(u8 **)(self + 0x852);
  if (osd && !osd[0xe1]) {
    osd[0xe1] = 1;
    if (self[0x9e7]) ext_59a5e0(osd, 0xc);
  }
}
PCREG(5936b0, heroOnProjectileHit);
