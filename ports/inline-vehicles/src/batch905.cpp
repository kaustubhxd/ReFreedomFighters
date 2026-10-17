// batch905.cpp - vehicles thread, batch 905: helicopter weapons. ZHeli::UpdateCannon, ZHeli::UpdateWeaponFire,
// ZHeli::ProcessProjectileHit, ZHeli::SetTarget with AimControl, ZMoveOnSpline::UpdateWeaponFireAndPos and
// ZBaseGeom::SetMatPosSimple.
#include "ff.h"

extern "C" void FASTCALL ext_4de420(float *dst, const float *src);                 // mcpy (3x3)
extern "C" void FASTCALL ext_4de040(float *mat, const float *dir, const float *up);  // createmat
extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);      // PSVECSubtract d = a - b
extern "C" void THISCALL ext_51d6f0(void *heli);                                     // ZHeli::UpdateCannonSound

static inline u8 *sysp() { return *(u8 **)0x70039c; }
static inline void *world() { return *(void **)(sysp() + 0x9b); }
// World object slot 0x58: geom pointer from a geom id.
static inline u8 *geomOf(u32 id) { return vcall<u8 *>(world(), 0x58, id); }

// 0x4dcb50 ZBaseGeom::SetMatPosSimple(const float* mat, const float* pos): position +0x24, matrix +0 (mcpy), and the
// "moved" flag 0x100000 of +0x3c (set twice, as in the exe).
static void THISCALL setMatPosSimple(u8 *g, const float *mat, const u32 *pos) {
  *(u32 *)(g + 0x24) = pos[0];
  *(u32 *)(g + 0x28) = pos[1];
  *(u32 *)(g + 0x2c) = pos[2];
  *(u32 *)(g + 0x3c) |= 0x100000;
  ext_4de420((float *)g, mat);
  *(u32 *)(g + 0x3c) |= 0x100000;
}
PCREG(4dcb50, setMatPosSimple);

// ZItemWeapon slots used here: 0x33c(3) select fire mode, 0x35c rounds left, 0x360(100) add rounds, 0x354 ready,
// 0x2d0(state, 0) set state (6 reload?, 0 idle, 3 fire), 0x32c(point) aim at.
// Ready the weapon: always given ammo (+100 when empty); a weapon that is not ready goes through state 6 then 0.
static inline void ready(void *w) {
  if (vcall<u32>(w, 0x35c) == 0)
    vcall<void>(w, 0x360, 100);
  if (!vcall<u8>(w, 0x354)) {
    vcall<void>(w, 0x2d0, 6, 0);
    vcall<void>(w, 0x2d0, 0, 0);
  }
}

// 0x514890 ZMoveOnSpline::UpdateWeaponFireAndPos(ZItemWeapon*, const float* target, const float* mat,
// const float* pos, bool fire, bool aim), thiscall (this unused), callee pops 0x18. Firing: mode 3, ready, aim at
// target when `aim`, state 3; not firing: state 0. Then the weapon geom (+8) gets mat/pos.
static void THISCALL updateWeaponFireAndPos(void *self, u8 *w, const float *target, const float *mat, const u32 *pos,
                                            u32 fire, u32 aim) {
  if (!w)
    return;
  if ((u8)fire) {
    vcall<void>(w, 0x33c, 3);
    ready(w);
    if ((u8)aim)
      vcall<void>(w, 0x32c, target);
    vcall<void>(w, 0x2d0, 3, 0);
  } else {
    vcall<void>(w, 0x2d0, 0, 0);
  }
  setMatPosSimple(*(u8 **)(w + 8), mat, pos);
}
PCREG(514890, updateWeaponFireAndPos);

// 0x51e700 ZHeli::UpdateWeaponFire(ZItemWeapon*, bool fire, float* target), this unused. Firing: mode 3, ready,
// state 0 then 3, aim at target (after the state change, unlike UpdateWeaponFireAndPos). Not firing: state 0.
static void THISCALL heliUpdateWeaponFire(void *self, u8 *w, u32 fire, const float *target) {
  if (!(u8)fire) {
    vcall<void>(w, 0x2d0, 0, 0);
    return;
  }
  vcall<void>(w, 0x33c, 3);
  ready(w);
  vcall<void>(w, 0x2d0, 0, 0);
  vcall<void>(w, 0x2d0, 3, 0);
  vcall<void>(w, 0x32c, target);
}
PCREG(51e700, heliUpdateWeaponFire);

// 0x5138f0 AimControl::NewTarget(unsigned int): +0 id, +4 geom (world slot 0x58), +8 the same geom when it is an
// actor (slot 0x1e0 IsA 0x200074) else 0; +0xc = (now - (int)(+0x30 * -1024)) / 1024 and
// +0x10 = ((int)(+0x30 * 1024) - (int)(+0x34 * -1024) + now) / 1024: the aim fade-in window from the two delays.
static void THISCALL aimNewTarget(u8 *a, u32 id) {
  *(u32 *)a = id;
  u8 *g = geomOf(id);
  *(u8 **)(a + 4) = g;
  if (g && vcall<u8>(g, 0x1e0, 0x200074))
    *(u8 **)(a + 8) = *(u8 **)(a + 4);
  else
    *(u32 *)(a + 8) = 0;
  float d0 = *(float *)(a + 0x30);
  s32 t0 = *(s32 *)(sysp() + 0x40) - _mm_cvttss_si32(_mm_set_ss(d0 * -1024.0f));
  s32 i1 = _mm_cvttss_si32(_mm_set_ss(d0 * 1024.0f));
  *(float *)(a + 0xc) = (float)t0 * 0.0009765625f;
  s32 i2 = _mm_cvttss_si32(_mm_set_ss(*(float *)(a + 0x34) * -1024.0f));
  s32 t1 = (i1 - i2) + *(s32 *)(sysp() + 0x40);
  *(float *)(a + 0x10) = (float)t1 * 0.0009765625f;
}
PCREG(5138f0, aimNewTarget);

// 0x514480 AimControl::SetTarget(unsigned int): NewTarget only when the id changes.
static void THISCALL aimSetTarget(u8 *a, u32 id) {
  if (id != *(u32 *)a)
    aimNewTarget(a, id);
}
PCREG(514480, aimSetTarget);

// 0x51cfb0 ZHeli::SetTarget(unsigned int): the target (+0x3fd) is kept only if slot 0x310 (CanSee) accepts it;
// a kept target also goes to the aim control at +0x59b.
static void THISCALL heliSetTarget(u8 *s, u32 id) {
  if (vcall<u8>(s, 0x310, id))
    *(u32 *)(s + 0x3fd) = id;
  else
    *(u32 *)(s + 0x3fd) = 0;
  if (*(u32 *)(s + 0x3fd))
    aimSetTarget(s + 0x59b, *(u32 *)(s + 0x3fd));
}
PCREG(51cfb0, heliSetTarget);

// 0x51cae0 ZHeli::ProcessProjectileHit(SHitInfo*): the hit geom (+0xc) must exist and not be the heli itself.
// The weapon (+0x10, slot 0x330 weapon type): type 7 (RPG) always sends the command id in word +0x5d3; type 4
// (AK/Dragunov) sends word +0x5d5 only when slot 0x32c is true and the impact point (projectile +0x28) is inside the
// heli's hit group +0x479 (GetLocalPoint slot 0x8c, then slot 0x184 inside). Any other weapon type does nothing.
// The command goes to the heli itself: ZGEOM::SendCommand (slot 0x130)(self, id, 0), so the level script decides
// what a hit does. The geom of +8 (the shooter) is looked up but not used.
static void THISCALL heliProcessProjectileHit(u8 *s, u32 *h) {
  u8 *g = geomOf(h[3]);
  if (!g || g == s)
    return;
  geomOf(h[2]);
  u8 *w = geomOf(h[4]);
  if (!w)
    return;
  u32 type = vcall<u32>(w, 0x330);
  u32 dmg;
  if (type == 4) {
    if (!vcall<u8>(w, 0x32c))
      return;
    u32 box = *(u32 *)(s + 0x479);
    if (!box)
      return;
    u8 *b = geomOf(box);
    vcall<void>(b, 0x8c, (u8 *)h[0] + 0x28);
    if (!vcall<u8>(b, 0x184, (u8 *)h[0] + 0x28))
      return;
    dmg = *(u16 *)(s + 0x5d5);
  } else if (type == 7) {
    dmg = *(u16 *)(s + 0x5d3);
  } else {
    return;
  }
  vcall<void>(s, 0x130, s, dmg, 0);
}
PCREG(51cae0, heliProcessProjectileHit);

// ZGEOM slots: 0x84 GetRootPoint (local point to world), 0x88 GetRootVect, 0x8c GetLocalPoint (world point to
// local), 0x90 GetLocalVect, 0x7c SetRootTM. Heli slots: 0x310 ZMoveOnSpline::TargetValid, 0x384
// ZHeli::UpdateWeaponFire. (tools/vt.py ZHeli)
// Wing-gun round toward the target: target position (GetRootPoint of its origin) into heli space (GetLocalPoint),
// x replaced by half the gun's own x (gun geom +0x24), back to world (GetRootPoint), y + 75, and
// UpdateWeaponFire(gun, 1, point).
// Engine random (slot 0x1c0(file, line)) returns a float in st0.
static inline long double rnd(u32 line) {
  typedef long double(THISCALL * fn)(void *, const char *, u32);
  u8 *sy = sysp();
  return (*(fn *)(*(u8 **)sy + 0x1c0))(sy, (const char *)0x69f8b8, line);
}

// One wing-gun bank: 5 slots (`arr`), round-robin index `ix`; fires the current slot if it holds a gun.
static inline void wingBank(u8 *s, u32 ix, u32 arr, float *pos, float *t, float *mat) {
  if (*(u32 *)(s + arr + 4 * *(u32 *)(s + ix))) {
    u32 tg = *(u32 *)(s + 0x3fd);
    if (tg) {
      t[2] = 0;
      t[1] = 0;
      t[0] = 0;
      vcall<void>(geomOf(tg), 0x84, t);
      vcall<void>(s, 0x8c, t);
      u8 *gun = *(u8 **)(s + arr + 4 * *(u32 *)(s + ix));
      t[0] = *(float *)(*(u8 **)(gun + 8) + 0x24) * 0.5f;
      vcall<void>(s, 0x84, t);
      t[1] = t[1] + 75.0f;
      vcall<void>(s, 0x384, *(void **)(s + arr + 4 * *(u32 *)(s + ix)), 1, t);
    } else {
      vcall<void>(s, 0x90, pos);
      ext_4de040(mat, pos, 0);
      updateWeaponFireAndPos(s, *(u8 **)(s + arr + 4 * *(u32 *)(s + ix)), t, mat, (u32 *)pos,
                             *(u32 *)(s + 0x469) != 0, 0);
    }
  }
  if (++*(s32 *)(s + ix) >= 5)
    *(u32 *)(s + ix) = 0;
}

// 0x51d120 ZHeli::UpdateCannon(). The main cannon (+0x405, if any) is placed at +0x45d with a matrix made from
// GetLocalVect(v) (slot 0x90), where v is the heli position (+0x216), or with a target -(target point): the target
// branch computes PSVECSubtract(v, zero, targetpoint), writing into v and never into the aim vector, which stays
// (0,0,0). The cannon fires with the fire level (+0x469) and aim on. Cannon sound when +0x409 or +0x40d. While firing (+0x469):
//  - bank A (+0x411, index +0x455) every 184 ticks (0xb8 / 1024 s, next time +0x471),
//  - bank B (+0x425, index +0x459) every 184 + (int)(rand * 0.03 * 1024) ticks (next time +0x46d),
//  - rockets (+0x439, if the first is set): slot (int)(rand * 4), always given ammo, aimed at the target with the
//    rocket's own x (no +75), states 3 then 0; next time +0x475 = now + (int)(2 * rand * 1024) ticks.
// Times are float seconds (ticks / 1024) compared as (int)(t * 1024) against engine time +0x40.
static void THISCALL heliUpdateCannon(u8 *s) {
  float tgt[3], pos[3], t[3], mat[9];
  tgt[0] = 0;
  tgt[1] = 0;
  tgt[2] = 0;
  pos[0] = *(float *)(s + 0x216);
  pos[1] = *(float *)(s + 0x21a);
  pos[2] = *(float *)(s + 0x21e);
  if (*(u32 *)(s + 0x3fd)) {
    t[0] = *(float *)(s + 0x45d);
    t[1] = *(float *)(s + 0x461);
    t[2] = *(float *)(s + 0x465);
    vcall<void>(s, 0x84, t);
    ext_43e920(pos, tgt, t);
  }
  if (*(u32 *)(s + 0x405)) {
    vcall<void>(s, 0x90, pos);
    ext_4de040(mat, pos, 0);
    updateWeaponFireAndPos(s, *(u8 **)(s + 0x405), tgt, mat, (u32 *)(s + 0x45d), *(u32 *)(s + 0x469) != 0, 1);
  }
  if (*(u32 *)(s + 0x409) || *(u32 *)(s + 0x40d))
    ext_51d6f0(s);
  if (!*(u32 *)(s + 0x469))
    return;
  if (*(s32 *)(sysp() + 0x40) > _mm_cvttss_si32(_mm_set_ss(*(float *)(s + 0x471) * 1024.0f))) {
    wingBank(s, 0x455, 0x411, pos, t, mat);
    *(float *)(s + 0x471) = (float)(*(s32 *)(sysp() + 0x40) + 0xb8) * 0.0009765625f;
  }
  if (!*(u32 *)(s + 0x469))
    return;
  if (*(s32 *)(sysp() + 0x40) > _mm_cvttss_si32(_mm_set_ss(*(float *)(s + 0x46d) * 1024.0f))) {
    wingBank(s, 0x459, 0x425, pos, t, mat);
    s32 now = *(s32 *)(sysp() + 0x40) + 0xb8;
    long double r = rnd(0x363);
    float f = (float)(r * (long double)0.029999999329447746f * (long double)-1024.0f);
    *(float *)(s + 0x46d) = (float)(now - _mm_cvttss_si32(_mm_set_ss(f))) * 0.0009765625f;
  }
  if (!*(u32 *)(s + 0x469) || !*(u32 *)(s + 0x439))
    return;
  if (!(*(s32 *)(sysp() + 0x40) > _mm_cvttss_si32(_mm_set_ss(*(float *)(s + 0x475) * 1024.0f))))
    return;
  float fi = (float)(rnd(0x366) * 4.0L);
  u8 *rk = *(u8 **)(s + 0x439 + 4 * _mm_cvttss_si32(_mm_set_ss(fi)));
  ready(rk);
  u32 tg = *(u32 *)(s + 0x3fd);
  if (tg) {
    t[2] = 0;
    t[1] = 0;
    t[0] = 0;
    vcall<void>(geomOf(tg), 0x84, t);
    vcall<void>(s, 0x8c, t);
    t[0] = *(float *)(*(u8 **)(rk + 8) + 0x24);
    vcall<void>(s, 0x84, t);
    vcall<void>(rk, 0x32c, t);
  }
  vcall<void>(rk, 0x2d0, 3, 0);
  vcall<void>(rk, 0x2d0, 0, 0);
  long double r = rnd(0x37d);
  s32 now = *(s32 *)(sysp() + 0x40);
  float f = (float)((r + r) * 1024.0L);
  *(float *)(s + 0x475) = (float)(now + _mm_cvttss_si32(_mm_set_ss(f))) * 0.0009765625f;
}
PCREG(51d120, heliUpdateCannon);
