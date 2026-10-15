// batch305.cpp - mounted gun tree, batch 305: the nest's set-up: CopyEventDataBlock (level data), Init2 (find the
// gun model parts), Init (register in the level's MachinegunList).
// Engine database = [0x70039c]+0x9b (GC: g_pSysInterface->0xc4, ZEngineDataBase): slot 0x4c is GeomPtrToRef(ZGEOM*)
// (GC Init calls ZEngineDataBase::GeomPtrToRef with one argument at the same place), slot 0x58 the reverse lookup,
// slot 0x138 GetSceneCom(); its +0xadc dword is the scene root geom (GC +0xad8), whose slot 0x25c(name, 0) finds a
// geom by name and slot 0x294(name, class, 0, 1) creates one. Global 0x7003b8 is g_pGameData (GC SetMachinegunList).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u8 *(THISCALL *vcallPU)(void *self, u32 a);
typedef u8 *(THISCALL *vcallP0)(void *self);
typedef u32(THISCALL *vcallUU)(void *self, u32 a);
typedef u8 *(THISCALL *vcallPUU)(void *self, u32 a, u32 b);
typedef u8 *(THISCALL *vcallPUUUU)(void *self, u32 a, u32 b, u32 c, u32 d);
typedef void(THISCALL *vcallVU)(void *self, u32 a);
typedef void(THISCALL *vcallVUUU)(void *self, u32 a, u32 b, u32 c);

extern "C" u32 THISCALL ext_4e5e60(void *db);                       // DBREAD::operator unsigned int
extern "C" long double THISCALL ext_4e5e80(void *db);               // DBREAD::operator float (ST0)
extern "C" const char *THISCALL ext_4dc110(void *geom);             // ZBaseGeom::Name
extern "C" int FASTCALL ext_4cc850(const char *s, const char *pat); // striwcmp (batch 54)
extern "C" void THISCALL ext_4db860(void *geom, u8 hide);           // ZBaseGeom::Hide(bool)
extern "C" u8 *THISCALL ext_4db520(void *geom);                     // ZBaseGeom::GetPrev

static inline u8 *db() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x5c8c50 CMachinegunControlGroup::CopyEventDataBlock(DBREAD &r), GC map [high]; thiscall, ret 4.
// Reads two references (+0x68 the gun's item template object, +0x6c the optional matrix receiver) and the horizontal
// half-arc in degrees -> radians (+0x48; below 2^-13 it becomes pi/4). The vertical half-arc +0x4c is not read here.
// Then the limits used by ClampAndNormAimDir: +0x50 sin(h), +0x54 cos(h), +0x58 sin(v), +0x5c cos(v),
// +0x60 cos(h - 5 deg), +0x64 sin(v - 5 deg) (5 deg = 0x6b4ae0); sin/cos are the CRT's (IAT).
static void THISCALL copyEventDataBlock(u8 *self, void *r) {
  *(u32 *)(self + 0x68) = ext_4e5e60(r);
  *(u32 *)(self + 0x6c) = ext_4e5e60(r);
  long double d = ext_4e5e80(r);
  float h = (float)(d * (long double)0.01745329238474369f);   // 0x67da04
  *(float *)(self + 0x48) = h;
  if (0.0001220703125f > h)   // 0x679540
    *(u32 *)(self + 0x48) = 0x3f490fdbu;   // pi/4
  float *f = (float *)self;
  const float five = 0.0872664600610733f;   // 0x6b4ae0
  f[0x50 / 4] = (float)crt::sin((double)f[0x48 / 4]);
  f[0x54 / 4] = (float)crt::cos((double)f[0x48 / 4]);
  f[0x58 / 4] = (float)crt::sin((double)f[0x4c / 4]);
  f[0x5c / 4] = (float)crt::cos((double)f[0x4c / 4]);
  f[0x60 / 4] = (float)crt::cos((double)(f[0x48 / 4] - five));
  f[0x64 / 4] = (float)crt::sin((double)(f[0x4c / 4] - five));
}
PCREG(5c8c50, copyEventDataBlock);

// The geom flags word used by Init2: geom+0x54 -> +0xc -> +0x23, or 0x200002 when +0x54 is null.
static inline u32 geomFlags(u8 *g) {
  u8 *i = *(u8 **)(g + 0x54);
  return i ? *(u32 *)(*(u8 **)(i + 0xc) + 0x23) : 0x200002u;
}

// 0x5c8e00 CMachinegunControlGroup::Init2(), GC map [high]; thiscall, no args.
// The item template (+0x68) makes the gun: slot 0x2c4(scene root, 'UGAM' 0x4d414755); the gun gets slot 0x2f0(0, gun geom,
// 1) and its reference goes to +0x70. Starting at the gun geom's +0x54 and walking GetPrev while the flags lack
// 0x100000, every geom named like "PosBox*" (striwcmp) is hidden. +0x74 = ref of child "PosBox_Center" (or the gun
// geom itself), +0x78 = ref of child "PosBox_Hand" (or the gun geom).
static void THISCALL init2(u8 *self) {
  u8 *tmpl = ((vcallPU)VT(db(), 0x58))(db(), *(u32 *)(self + 0x68));
  u8 *gun = ((vcallPUU)VT(tmpl, 0x2c4))(tmpl, *(u32 *)(db() + 0xadc), 0x4d414755u);
  ((vcallVUUU)VT(gun, 0x2f0))(gun, 0, *(u32 *)(self + 0x44), 1);
  *(u32 *)(self + 0x70) = ((vcallUU)VT(db(), 0x4c))(db(), (u32)gun);
  for (u8 *g = *(u8 **)(*(u8 **)(self + 0x44) + 0x54); g && !(geomFlags(g) & 0x100000u); g = ext_4db520(g)) {
    if (ext_4cc850(ext_4dc110(g), (const char *)0x6b4a3c) == 0)   // "PosBox*"
      ext_4db860(g, 1);
  }
  u8 *gg = *(u8 **)(self + 0x44);
  u8 *c = ((vcallPUU)VT(gg, 0x25c))(gg, 0x68886c, 0);   // "PosBox_Center"
  if (!c)
    c = *(u8 **)(self + 0x44);
  *(u32 *)(self + 0x74) = ((vcallUU)VT(db(), 0x4c))(db(), (u32)c);
  gg = *(u8 **)(self + 0x44);
  u8 *h = ((vcallPUU)VT(gg, 0x25c))(gg, 0x688860, 0);   // "PosBox_Hand"
  if (!h)
    h = *(u8 **)(self + 0x44);
  *(u32 *)(self + 0x78) = ((vcallUU)VT(db(), 0x4c))(db(), (u32)h);
}
PCREG(5c8e00, init2);

// 0x5c8f10 CMachinegunControlGroup::Init(), GC map [low] (GC Init has the same calls: confirmed); thiscall, no args.
// +0x7c = the scene's "MachinegunList" (found with slot 0x25c, else created as a ZLIST with slot 0x294 and announced
// to the scene com, slot 0x60(name, ref, 2)); the gun geom is added to it (slot 0x218), and g_pGameData+0x2c29 = list.
static void THISCALL init(u8 *self) {
  u8 *root = *(u8 **)(db() + 0xadc);
  u8 *lst = ((vcallPUU)VT(root, 0x25c))(root, 0x6b4a2c, 0);   // "MachinegunList"
  *(u8 **)(self + 0x7c) = lst;
  if (!lst) {
    root = *(u8 **)(db() + 0xadc);
    *(u8 **)(self + 0x7c) = ((vcallPUUUU)VT(root, 0x294))(root, 0x6b4a2c, 0x67f610, 0, 1);   // "ZLIST"
    u8 *sc = ((vcallP0)VT(db(), 0x138))(db());
    void **svt = *(void ***)sc;
    u32 ref = ((vcallUU)VT(db(), 0x4c))(db(), *(u32 *)(self + 0x7c));
    ((vcallVUUU)svt[0x60 / 4])(sc, 0x6b4a2c, ref, 2);
  }
  u8 *l = *(u8 **)(self + 0x7c);
  ((vcallVU)VT(l, 0x218))(l, *(u32 *)(self + 0x44));
  *(u8 **)(G(u8 *, 0x7003b8) + 0x2c29) = *(u8 **)(self + 0x7c);
}
PCREG(5c8f10, init);
