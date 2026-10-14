// batch501.cpp - weapons thread, batch 501: the hand layer ZLNKWHANDS (ammo lookup, reload and chamber requests,
// hand item access) and ZItemAmmo's projectile count. Source file (from the exe's assert/log strings):
// ..\..\code\engine\geomsextend\zlnkwhands.cpp.
// ZLNKWHANDS layout used here: +0x2e3 inventory list object (slot 0x98 = find by template), +0x2e7 left-hand
// slot object, +0x34f right-hand slot object (each: slot 0x10 = item, slot 0x14 = item type).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vU0)(void *self);
typedef u32(THISCALL *vUU)(void *self, u32 a);
typedef u32(THISCALL *vUUU)(void *self, u32 a, u32 b);
typedef u8(THISCALL *vB0)(void *self);
typedef u8(THISCALL *vBU)(void *self, u32 a);
typedef void *(THISCALL *vLogLine)(void *self, const char *file, u32 line);
typedef void (*logPrintf)(void *self, const char *fmt, ...);

static const char *const kFile = (const char *)0x68961c;   // "..\..\code\engine\geomsextend\zlnkwhands.cpp"

static inline u8 *renderMgr() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u32 handleOf(u32 obj) { u8 *rm = renderMgr(); return ((vUU)VT(rm, 0x4c))(rm, obj); }
// The debug log at 0x700390: slot 0x20(file, line) gives a stream, whose slot 0x2c is a cdecl printf.
static inline void *logAt(u32 line) {
  u8 *l = G(u8 *, 0x700390);
  return ((vLogLine)VT(l, 0x20))(l, kFile, line);
}

// ---------------------------------------------------------------------------------------------- ZItemAmmo
// +0x8e s32 number of projectiles (rounds) in this ammo item.
static u32 THISCALL ammoGetNr(u8 *self) { return *(u32 *)(self + 0x8e); }
PCREG(46ed00, ammoGetNr);
static void THISCALL ammoAddNr(u8 *self, s32 n) { *(s32 *)(self + 0x8e) += n; }
PCREG(46ac30, ammoAddNr);
static void THISCALL ammoSetNr(u8 *self, s32 n) { *(s32 *)(self + 0x8e) = n; }
PCREG(4711d0, ammoSetNr);
static void THISCALL ammoSubNr(u8 *self, s32 n) { *(s32 *)(self + 0x8e) -= n; }
PCREG(471840, ammoSubNr);

// ---------------------------------------------------------------------------------------------- hand items
static u32 THISCALL getRHandItem(u8 *self) { u8 *h = self + 0x34f; return ((vU0)VT(h, 0x10))(h); }
PCREG(474670, getRHandItem);
static u32 THISCALL getRHandItemType(u8 *self) { u8 *h = self + 0x34f; return ((vU0)VT(h, 0x14))(h); }
PCREG(474680, getRHandItemType);
static u32 THISCALL getLHandItem(u8 *self) { u8 *h = self + 0x2e7; return ((vU0)VT(h, 0x10))(h); }
PCREG(474450, getLHandItem);
static u32 THISCALL getLHandItemType(u8 *self) { u8 *h = self + 0x2e7; return ((vU0)VT(h, 0x14))(h); }
PCREG(474460, getLHandItemType);

// The item in the hand when it IsDerivedFrom(0x1007d2) (ZItemWeapon's class id), else 0.
static inline u32 handWeapon(u8 *h) {
  u8 *it = (u8 *)((vU0)VT(h, 0x10))(h);
  if (!it)
    return 0;
  return ((vBU)VT(it, 0x1e0))(it, 0x1007d2) ? (u32)it : 0;
}
static u32 THISCALL getRHandWeapon(u8 *self) { return handWeapon(self + 0x34f); }
PCREG(474690, getRHandWeapon);
static u32 THISCALL getLHandWeapon(u8 *self) { return handWeapon(self + 0x2e7); }
PCREG(474470, getLHandWeapon);

// SetR/LHandItemState(s): item->SetState(s, 0) (ZItem slot 0x2d0) for the item in that hand (own slots 0x504 / 0x500).
static void THISCALL setRHandItemState(u8 *self, u32 s) {
  u8 *it = (u8 *)((vU0)VT(self, 0x504))(self);
  if (it)
    ((vUUU)VT(it, 0x2d0))(it, s, 0);
}
PCREG(4759f0, setRHandItemState);
static void THISCALL setLHandItemState(u8 *self, u32 s) {
  u8 *it = (u8 *)((vU0)VT(self, 0x500))(self);
  if (it)
    ((vUUU)VT(it, 0x2d0))(it, s, 0);
}
PCREG(475980, setLHandItemState);

// ---------------------------------------------------------------------------------------------- ammo lookup
// 0x474320 ZLNKWHANDS::GetInventoryAmmoFor(ZItemWeapon*): the ammo item in the inventory (+0x2e3) whose template is
// the weapon template's ammo template 0 (template slot 0x340(0)); inventory slot 0x98(template, 0) gives a handle.
// Returns the item only when it IsDerivedFrom(0x1007d8) (ZItemAmmo's class id), else 0.
static u32 THISCALL getInventoryAmmoFor(u8 *self, u8 *w) {
  if (*(u32 *)(self + 0x2e3) == 0)
    return 0;
  u8 *t = (u8 *)((vU0)VT(w, 0x350))(w);
  if (!t) {
    void *s = logAt(0x3c4);
    ((logPrintf)VT(s, 0x2c))(s, (const char *)0x6897a0);  // "WARNING: Trying to get inventory ammo for an item that's not a weapon"
    return 0;
  }
  if (!((vB0)VT(t, 0x328))(t))
    return 0;
  u32 at = ((vUU)VT(t, 0x340))(t, 0);
  u8 *inv = *(u8 **)(self + 0x2e3);
  u32 h = ((vUUU)VT(inv, 0x98))(inv, at, 0);
  if (!h)
    return 0;
  u8 *rm = renderMgr();
  u8 *a = (u8 *)((vUU)VT(rm, 0x58))(rm, h);
  if (!a)
    return 0;
  return ((vBU)VT(a, 0x1e0))(a, 0x1007d8) ? (u32)a : 0;
}
PCREG(474320, getInventoryAmmoFor);

// 0x473fe0 ZLNKWHANDS::GetAmmoFor(ZItemWeapon*): spare rounds for the weapon. 999 when the render manager's byte
// +0xbac is set (guess: the unlimited-ammo cheat; not checked) or the weapon's template cannot fire projectiles;
// else the inventory ammo item's count (own slot 0x55c, then ZItemAmmo slot 0x320), 0 when there is none.
static u32 THISCALL getAmmoFor(u8 *self, u8 *w) {
  if (renderMgr()[0xbac])
    return 999;
  u8 *t = (u8 *)((vU0)VT(w, 0x350))(w);
  if (t && !((vB0)VT(t, 0x328))(t))
    return 999;
  u8 *a = (u8 *)((vUU)VT(self, 0x55c))(self, (u32)w);
  if (!a || !((vBU)VT(a, 0x1e0))(a, 0x1007d8))
    return 0;
  return ((vU0)VT(a, 0x320))(a);
}
PCREG(473fe0, getAmmoFor);

// ---------------------------------------------------------------------------------------------- reload / chamber
// 0x475010 ZLNKWHANDS::Reload(ZItem*): with spare ammo (own slot 0x560), queue action 0xd (right hand) or 0xc
// (left hand) through AddAction (slot 0x45c) with the item's handle, unless that action is already current.
static void THISCALL reload(u8 *self, u32 item) {
  if (((vUU)VT(self, 0x560))(self, item) == 0)
    return;
  if (item == ((vU0)VT(self, 0x504))(self)) {
    if (((vU0)VT(self, 0x3f0))(self) == 0xd)
      return;
    ((vUUU)VT(self, 0x45c))(self, 0xd, handleOf(item));
    return;
  }
  if (item != ((vU0)VT(self, 0x500))(self))
    return;
  if (((vU0)VT(self, 0x3f0))(self) == 0xc)
    return;
  ((vUUU)VT(self, 0x45c))(self, 0xc, handleOf(item));
}
PCREG(475010, reload);

// 0x4728a0 ZLNKWHANDS::Chamber(ZItem*): the same with actions 0xe (right) and 0xf (left), no ammo test.
static void THISCALL chamber(u8 *self, u32 item) {
  if (item == ((vU0)VT(self, 0x504))(self)) {
    if (((vU0)VT(self, 0x3f0))(self) == 0xe)
      return;
    ((vUUU)VT(self, 0x45c))(self, 0xe, handleOf(item));
    return;
  }
  if (item != ((vU0)VT(self, 0x500))(self))
    return;
  if (((vU0)VT(self, 0x3f0))(self) == 0xf)
    return;
  ((vUUU)VT(self, 0x45c))(self, 0xf, handleOf(item));
}
PCREG(4728a0, chamber);

// 0x4750b0 ZLNKWHANDS::ReloadItem(ZItem*): the reload itself. newCount = min(clip size, inMag + spare) (signed),
// loaded = newCount - inMag; logs "%d Bullets added"; spare -= loaded via SetAmmoFor (slot 0x564); the magazine
// becomes newCount and a bullet is chambered.
static void THISCALL reloadItem(u8 *self, u8 *item) {
  s32 spare = (s32)((vUU)VT(self, 0x560))(self, (u32)item);
  s32 clip = (s32)((vU0)VT(item, 0x364))(item);
  s32 cur = (s32)((vU0)VT(item, 0x35c))(item);
  s32 n = cur + spare;
  if (clip < n)
    n = clip;
  s32 loaded = n - cur;
  void *s = logAt(0x3fe);
  ((logPrintf)VT(s, 0x2c))(s, (const char *)0x689820, loaded);  // "%d Bullets added"
  ((vUUU)VT(self, 0x564))(self, (u32)item, (u32)(spare - loaded));
  ((vUU)VT(item, 0x360))(item, (u32)n);
  ((vUU)VT(item, 0x358))(item, 1);
}
PCREG(4750b0, reloadItem);
