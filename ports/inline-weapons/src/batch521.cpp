// batch521.cpp - weapons thread, batch 521: more ZItemWeapon members and ZLNKWHANDS::GetAimAnim.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vU0)(void *self);
typedef u32(THISCALL *vUU)(void *self, u32 a);
typedef u32(THISCALL *vUUU)(void *self, u32 a, u32 b);
typedef u8(THISCALL *vBU)(void *self, u32 a);
extern "C" void THISCALL ext_4db2c0(void *geom, float *mat, float *pos);   // ZBaseGeom::GetMatPos
extern "C" void THISCALL ext_4db500(void *geom, float *pos);               // ZBaseGeom::GetPos
extern "C" void FASTCALL ext_4419f0(float *v, const float *m);             // vmmul in place
extern "C" void FASTCALL ext_441940(float *a, const float *b);             // a += b
extern "C" void THISCALL ext_43f8c0(u8 *self, u8 *other);                  // ZGROUP::CopyData

// 0x46eab0 GetMuzzleExitPos(): the weapon template's muzzle geom (+0x11b).
static u32 THISCALL getMuzzleExitPos(u8 *s) {
  u8 *t = (u8 *)((vU0)VT(s, 0x350))(s);
  return *(u32 *)(t + 0x11b);
}
PCREG(46eab0, getMuzzleExitPos);

// 0x46e6d0 GetFirePosition(mat, pos): GetMatPos of the muzzle exit geom (own slot 0x348), tail call.
static void THISCALL getFirePosition(u8 *s, float *mat, float *pos) {
  u8 *m = (u8 *)((vU0)VT(s, 0x348))(s);
  ext_4db2c0(*(void **)(m + 8), mat, pos);
}
PCREG(46e6d0, getFirePosition);

// 0x46ee50 GetRootMuzzleExitPos(out): the muzzle geom's position through the item's root transform (GetItemRootTM,
// slot 0x2c4).
static void THISCALL getRootMuzzleExitPos(u8 *s, float *out) {
  u8 *t = (u8 *)((vU0)VT(s, 0x350))(s);
  ext_4db500(*(void **)(*(u8 **)(t + 0x11b) + 8), out);
  float m[9], p[3];
  ((vUUU)VT(s, 0x2c4))(s, (u32)m, (u32)p);
  ext_4419f0(out, m);
  ext_441940(out, p);
}
PCREG(46ee50, getRootMuzzleExitPos);

// 0x471aa0 VerifyItemTemplate(t): a weapon template (class info +0xc, class id +0x23 == 0x1007d4).
static u8 THISCALL verifyItemTemplate(u8 *s, u8 *t) {
  if (!t)
    return 0;
  return *(u32 *)(*(u8 **)(t + 0xc) + 0x23) == 0x1007d4;
}
PCREG(471aa0, verifyItemTemplate);

// 0x46d6e0 DestroyItem(): the template's DestroyItem (slot 0x31c) with this.
static void THISCALL destroyItem(u8 *s) {
  u8 *t = (u8 *)((vU0)VT(s, 0x350))(s);
  ((vUU)VT(t, 0x31c))(t, (u32)s);
}
PCREG(46d6e0, destroyItem);

// 0x46cd60 CopyData(other): ZGROUP::CopyData, then the item fields +0x60/+0x64 when other IsDerivedFrom 0x1007d1
// (ZItem), and the ammo template handle +0xb6 when it is a weapon (0x1007d2).
static void THISCALL copyData(u8 *s, u8 *o) {
  ext_43f8c0(s, o);
  if (((vBU)VT(o, 0x1e0))(o, 0x1007d1)) {
    *(u32 *)(s + 0x60) = *(u32 *)(o + 0x60);
    *(u32 *)(s + 0x64) = *(u32 *)(o + 0x64);
  }
  if (((vBU)VT(o, 0x1e0))(o, 0x1007d2))
    *(u32 *)(s + 0xb6) = *(u32 *)(o + 0xb6);
}
PCREG(46cd60, copyData);

// 0x46f240 InitSounds(): from the template's sound set (slot 0x378) and the sound table [0x70039c]+0x1a9f (slot 0x60
// = find by pattern): +0x8e "*_Shot*", +0x92 "*_Empty*" (the dry-fire click), +0x96 "*_Reload*"; +0x9a cleared.
static void THISCALL initSounds(u8 *s) {
  u8 *t = (u8 *)((vU0)VT(s, 0x350))(s);
  u32 set = ((vU0)VT(t, 0x378))(t);
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x1a9f);
  if (tab && set) {
    *(u32 *)(s + 0x8e) = ((vUUU)VT(tab, 0x60))(tab, set, 0x688d1c);
    tab = *(u8 **)(G(u8 *, 0x70039c) + 0x1a9f);
    *(u32 *)(s + 0x92) = ((vUUU)VT(tab, 0x60))(tab, set, 0x688d24);
    tab = *(u8 **)(G(u8 *, 0x70039c) + 0x1a9f);
    *(u32 *)(s + 0x96) = ((vUUU)VT(tab, 0x60))(tab, set, 0x688d30);
  }
  *(u32 *)(s + 0x9a) = 0;
}
PCREG(46f240, initSounds);

// 0x473e50 ZLNKWHANDS::GetAimAnim(): the upper-body aim animation for the right-hand weapon type: none +0x266;
// types 0/1 (pistols, guess) +0x2d7 when the left hand holds a weapon of the same type (dual wield), else +0x2db;
// types 2-6 +0x2d3; 7 +0x2df; 11 none (0); 8-10 and others +0x2db.
static u32 THISCALL getAimAnim(u8 *s) {
  u8 *w = (u8 *)((vU0)VT(s, 0x50c))(s);
  if (!w)
    return *(u32 *)(s + 0x266);
  u8 *t = (u8 *)((vU0)VT(w, 0x350))(w);
  u32 ty = ((vU0)VT(t, 0x330))(t);
  switch (ty) {
  case 0:
  case 1: {
    u8 *l = (u8 *)((vU0)VT(s, 0x508))(s);
    if (!l)
      break;
    u8 *lt = (u8 *)((vU0)VT(l, 0x350))(l);
    u8 *rt = (u8 *)((vU0)VT(w, 0x350))(w);
    u32 rty = ((vU0)VT(rt, 0x330))(rt);
    if (((vU0)VT(lt, 0x330))(lt) == rty)
      return *(u32 *)(s + 0x2d7);
    break;
  }
  case 2: case 3: case 4: case 5: case 6:
    return *(u32 *)(s + 0x2d3);
  case 7:
    return *(u32 *)(s + 0x2df);
  case 11:
    return 0;
  }
  return *(u32 *)(s + 0x2db);
}
PCREG(473e50, getAimAnim);
