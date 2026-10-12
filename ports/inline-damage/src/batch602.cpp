// batch602.cpp - damage thread, batch 602: ZFFActor::OnProjectileHit (a bullet hits a soldier).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])

#pragma pack(push, 1)
// SIKBoneCollision on PC: 2 bytes (ZIKLNKOBJ::GetBoneCollision PC 0x4666e0 writes +0 zone, +1 front flag).
struct SIKBoneCollision { u8 zone; u8 front; };
// SHitInfo (fields read here): +0 projectile (dir at +0xc, hit pos at +0x28), +8 weapon handle, +0xc attacker,
// +0x14 distance travelled.
// SDamageInfo, 0x2c bytes as built on the stack: +0 attacker, +4 = 0, +8 damage type, +0xc weapon handle,
// +0x10 hit pos[3], +0x1c dir[3], +0x28 damage.
struct SDamageInfo {
  u32 attacker, zero, type, weapon;
  float pos[3], dir[3];
  float damage;
};
#pragma pack(pop)

extern "C" float THISCALL ext_474250(void *self, u32 zone);  // ZLNKWHANDS::GetDamageMultForBone

typedef void *(THISCALL *vColl)(void *self, SIKBoneCollision *out, const float *pos, const float *dir);
typedef void *(THISCALL *vResolve)(void *self, u32 handle);
typedef void *(THISCALL *vP0)(void *self);
typedef void *(THISCALL *vPU)(void *self, u32 a);
typedef s32(THISCALL *vI0)(void *self);
typedef float(THISCALL *vCalc)(void *self, void *item, float dist);
typedef void(THISCALL *vDmg)(void *self, SDamageInfo *d);

// 0x5a16a0 ZFFActor::OnProjectileHit(const SHitInfo*) (GC 80071174).
//  zone = own GetBoneCollision(hit pos, dir) (slot 0x388); weapon = render manager slot 0x58 (handle);
//  no weapon -> nothing. damage = GetDamageMultForBone(zone) * template CalcDamage(weapon, distance)
//  (template = weapon slot 0x350, CalcDamage = template slot 0x35c). Sniper rule: zone 2 or 3, engine flag +0x1b5d == 1,
//  weapon type 4 (slot 0x330) with ammo (slot 0x340(0)) of ammo type 5 (ammo slot 0x32c) -> damage = current hitpoints.
//  Damage type 5 for weapon types 5 and 6, else 0. Then own slot 0x6c0 = OnDamageInfo(&info).
static void THISCALL onProjectileHit(u8 *self, u8 *hit) {
  SDamageInfo d;
  d.zero = 0;
  d.attacker = *(u32 *)(hit + 0xc);
  d.weapon = *(u32 *)(hit + 8);
  u8 *proj = *(u8 **)hit;
  float *pos = (float *)(proj + 0x28), *dir = (float *)(proj + 0xc);
  d.pos[0] = pos[0]; d.pos[1] = pos[1]; d.pos[2] = pos[2];
  d.dir[0] = dir[0]; d.dir[1] = dir[1]; d.dir[2] = dir[2];
  SIKBoneCollision bc;
  u16 zoneWord = *(u16 *)((vColl)VT(self, 0x388))(self, &bc, pos, dir);
  u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *w = (u8 *)((vResolve)VT(rm, 0x58))(rm, *(u32 *)(hit + 8));
  if (!w) return;
  u8 *t = (u8 *)((vP0)VT(w, 0x350))(w);
  float raw = ((vCalc)VT(t, 0x35c))(t, w, *(float *)(hit + 0x14));
  long double mult = ext_474250(self, zoneWord);
  d.damage = (float)(mult * (long double)raw);
  u8 zone = (u8)zoneWord;
  if ((zone == 2 || zone == 3) && *(s32 *)(G(u8 *, 0x70039c) + 0x1b5d) == 1) {
    void *ammo = ((vPU)VT(t, 0x340))(t, 0);
    if (((vI0)VT(t, 0x330))(t) == 4 && ammo) {
      u8 *a = (u8 *)((vPU)VT(t, 0x340))(t, 0);
      if (((vI0)VT(a, 0x32c))(a) == 5) d.damage = (float)*(s16 *)(self + 0x7a0);
    }
  }
  d.type = (u32)(((vI0)VT(t, 0x330))(t) - 5) <= 1 ? 5 : 0;
  ((vDmg)VT(self, 0x6c0))(self, &d);
}
PCREG(5a16a0, onProjectileHit);
