// batch500.cpp - weapons thread, batch 500: ZItemWeapon field accessors (magazine, chamber, target, operation,
// ammo template). PC build is byte-packed, so the fields sit at odd offsets. Field names are the GameCube method
// names from the name map (decoders/gc_pc_namemap.tsv); offsets are from the PC code.
//   +0x60  ZItem: the template handle (non-zero when the item has one; GetProjectilesPerMagazine tests it)
//   +0xaa  float target[3]            (Target / SetTarget / GetTarget)
//   +0xb6  u32 ammo template handle   (render-manager handle, resolved with slot 0x58, made with slot 0x4c)
//   +0xba  s32 projectiles in magazine
//   +0xbf  u8  bullet in chamber
//   +0xc4  u32 (cleared by FireEnd; guess: firing flag/timer)
//   +0xd5  u32 weapon operation (WEAPONOPERATION; single, burst, auto... names not checked)
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vU0)(void *self);
typedef u32(THISCALL *vUU)(void *self, u32 a);

// 0x46e570 ZItemWeapon::GetBulletInChamber() const -> al
static u8 THISCALL getBulletInChamber(u8 *self) { return self[0xbf]; }
PCREG(46e570, getBulletInChamber);

// 0x470c50 ZItemWeapon::SetBulletInChamber(bool): a bullet can only be chambered when the magazine is not empty
// (own slot 0x35c = GetProjectilesInMagazine).
static void THISCALL setBulletInChamber(u8 *self, u8 on) {
  if (((vU0)VT(self, 0x35c))(self) != 0 && on)
    self[0xbf] = 1;
  else
    self[0xbf] = 0;
}
PCREG(470c50, setBulletInChamber);

// 0x46eda0 ZItemWeapon::GetProjectilesInMagazine() const
static u32 THISCALL getProjectilesInMagazine(u8 *self) { return *(u32 *)(self + 0xba); }
PCREG(46eda0, getProjectilesInMagazine);

// 0x4711e0 ZItemWeapon::SetProjectilesInMagazine(int)
static void THISCALL setProjectilesInMagazine(u8 *self, u32 n) { *(u32 *)(self + 0xba) = n; }
PCREG(4711e0, setProjectilesInMagazine);

// 0x46edb0 ZItemWeapon::GetProjectilesPerMagazine() const: -1 without a template; else the weapon template's
// GetDefaultProjectilesPerMagazine (template slot 0x354) when non-zero; else the ammo template's slot 0x31c
// (own slot 0x328 = GetAmmoTemplate), -1 when there is no ammo template. The last call is a tail jump.
static u32 THISCALL getProjectilesPerMagazine(u8 *self) {
  if (*(u32 *)(self + 0x60) == 0)
    return 0xffffffffu;
  u8 *t = (u8 *)((vU0)VT(self, 0x350))(self);
  u32 n = ((vU0)VT(t, 0x354))(t);
  if (n)
    return n;
  if (!((vU0)VT(self, 0x328))(self))
    return 0xffffffffu;
  u8 *a = (u8 *)((vU0)VT(self, 0x328))(self);
  return ((vU0)VT(a, 0x31c))(a);
}
PCREG(46edb0, getProjectilesPerMagazine);

// 0x46efc0 ZItemWeapon::GetWeaponTemplate() const: tail call to own slot 0x2e8 (ZItem::GetItemTemplate).
static u32 THISCALL getWeaponTemplate(u8 *self) { return ((vU0)VT(self, 0x2e8))(self); }
PCREG(46efc0, getWeaponTemplate);

// 0x46e450 ZItemWeapon::GetAmmoTemplate() const: resolve the handle at +0xb6 with the render manager's slot 0x58.
static u32 THISCALL getAmmoTemplate(u8 *self) {
  u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  return ((vUU)VT(rm, 0x58))(rm, *(u32 *)(self + 0xb6));
}
PCREG(46e450, getAmmoTemplate);

// 0x470c20 ZItemWeapon::SetAmmoTemplate(ZItemTemplateAmmo*): store the render manager's handle (slot 0x4c).
static void THISCALL setAmmoTemplate(u8 *self, u32 tmpl) {
  u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  *(u32 *)(self + 0xb6) = ((vUU)VT(rm, 0x4c))(rm, tmpl);
}
PCREG(470c20, setAmmoTemplate);

// 0x46efa0 ZItemWeapon::GetWeaponOperation() const
static u32 THISCALL getWeaponOperation(u8 *self) { return *(u32 *)(self + 0xd5); }
PCREG(46efa0, getWeaponOperation);

// 0x471670 ZItemWeapon::SetWeaponOperation(WEAPONOPERATION)
static void THISCALL setWeaponOperation(u8 *self, u32 op) { *(u32 *)(self + 0xd5) = op; }
PCREG(471670, setWeaponOperation);

// 0x471850 ZItemWeapon::Target() const -> pointer to the target vector
static u32 THISCALL target(u8 *self) { return (u32)(self + 0xaa); }
PCREG(471850, target);

// 0x471640 ZItemWeapon::SetTarget(const float*): three dword copies.
static void THISCALL setTarget(u8 *self, const u32 *p) {
  *(u32 *)(self + 0xaa) = p[0];
  *(u32 *)(self + 0xae) = p[1];
  *(u32 *)(self + 0xb2) = p[2];
}
PCREG(471640, setTarget);

// 0x46eef0 ZItemWeapon::GetTarget(float*) const: copies the target out; true unless it is exactly (0, 0, 0)
// (NaN counts as set). x and y are compared after being stored to out, z from the field.
static u8 THISCALL getTarget(u8 *self, float *out) {
  *(u32 *)out = *(u32 *)(self + 0xaa);
  float x = out[0];
  *(u32 *)(out + 1) = *(u32 *)(self + 0xae);
  float z = *(float *)(self + 0xb2);
  out[2] = z;
  if (x != 0.0f || out[1] != 0.0f || z != 0.0f)
    return 1;
  return 0;
}
PCREG(46eef0, getTarget);

// 0x470bf0 ZItemWeapon::SelectNextWeaponOperation(): +0xd5 = template slot 0x358 (SelectNextWeaponOperation) of it.
static void THISCALL selectNextWeaponOperation(u8 *self) {
  u8 *t = (u8 *)((vU0)VT(self, 0x350))(self);
  *(u32 *)(self + 0xd5) = ((vUU)VT(t, 0x358))(t, *(u32 *)(self + 0xd5));
}
PCREG(470bf0, selectNextWeaponOperation);

// 0x46d8c0 ZItemWeapon::FireEnd(): clears +0xc4; an empty magazine also clears the chamber.
static void THISCALL fireEnd(u8 *self) {
  *(u32 *)(self + 0xc4) = 0;
  if (*(u32 *)(self + 0xba) == 0)
    self[0xbf] = 0;
}
PCREG(46d8c0, fireEnd);
