// batch522.cpp - weapons thread, batch 522: the hand layer's drop and use-item decisions (the generic, NPC-side
// versions of the hero's ControlDrop / ControlUseOneAlone) and ZItemWeapon::PlaySound.
// Hand action ids used here: 6 put away, 8 get item, 9 drop left, 0xa drop right, 0xb swap hands (move the right
// item to the left hand; guess from the uses).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vU0)(void *self);
typedef u32(THISCALL *vUU)(void *self, u32 a);
typedef u32(THISCALL *vUUU)(void *self, u32 a, u32 b);
typedef long double(THISCALL *vRand)(void *self, const char *file, u32 line);
typedef void *(THISCALL *vLogLine)(void *self, const char *file, u32 line);
typedef void (*logPrintf)(void *self, const char *fmt, ...);
extern "C" u32 THISCALL ext_43ec00(void *grp, float *m, float *p, u32 id, u32 a, u32 h, u32 b);   // ZGROUP::AddSound3d
extern "C" u32 THISCALL ext_4db3b0(void *geom);                                                   // ZBaseGeom::GetOwnerRoom

static inline u8 *rmgr() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x473000 ZLNKWHANDS::ControlDrop(item): drop from the hand holding it (action 9 left, 0xa right, unless already
// the current action); no item means the right hand; an item in neither hand logs "ERROR: Trying to drop an item
// not in the hands" (zlnkwhands.cpp line 0x65e). (The item's handle is fetched and not used.)
static void THISCALL hControlDrop(u8 *s, u32 item) {
  if (item) {
    u8 *rm = rmgr();
    ((vUU)VT(rm, 0x4c))(rm, item);
    u32 l = ((vU0)VT(s, 0x500))(s);
    u32 r = ((vU0)VT(s, 0x504))(s);
    if (l == item) {
      if (((vU0)VT(s, 0x3f0))(s) != 9)
        ((vUUU)VT(s, 0x45c))(s, 9, 0);
      return;
    }
    if (r != item) {
      u8 *lg = G(u8 *, 0x700390);
      void *st = ((vLogLine)VT(lg, 0x20))(lg, (const char *)0x68961c, 0x65e);
      ((logPrintf)VT(st, 0x2c))(st, (const char *)0x689850);
      return;
    }
  }
  if (((vU0)VT(s, 0x3f0))(s) != 0xa)
    ((vUUU)VT(s, 0x45c))(s, 0xa, 0);
}
PCREG(473000, hControlDrop);

// 0x4732a0 ZLNKWHANDS::ControlUseOneAlone(handle): nothing when already in the right hand; an item held in the left
// hand is swapped over (action 0xb). Otherwise the right hand is emptied first: items of size 0 are put away
// (action 6); others are dropped (0xa) when their state is 2 or the left hand is busy, else moved to the left hand
// (0xb). Then the new item is taken (action 8).
static void THISCALL hControlUseOneAlone(u8 *s, u32 handle) {
  u8 *rm = rmgr();
  u32 nw = ((vUU)VT(rm, 0x58))(rm, handle);
  u8 *r = (u8 *)((vU0)VT(s, 0x504))(s);
  u32 l = ((vU0)VT(s, 0x500))(s);
  if (nw == (u32)r)
    return;
  if (nw && nw == l) {
    ((vUUU)VT(s, 0x45c))(s, 0xb, 0);
    return;
  }
  if (r) {
    u8 *t = (u8 *)((vU0)VT(r, 0x2e8))(r);
    u32 size = ((vU0)VT(t, 0x308))(t);
    if (!size) {
      ((vUUU)VT(s, 0x45c))(s, 6, size);
    } else {
      t = (u8 *)((vU0)VT(r, 0x2e8))(r);
      if (((vU0)VT(t, 0x300))(t) == 2 || l)
        ((vUUU)VT(s, 0x45c))(s, 0xa, 0);
      else
        ((vUUU)VT(s, 0x45c))(s, 0xb, 0);
    }
  }
  if (handle)
    ((vUUU)VT(s, 0x45c))(s, 8, handle);
}
PCREG(4732a0, hControlUseOneAlone);

// 0x4700a0 ZItemWeapon::PlaySound(id): a 3D sound at the item's main root transform (slot 0x2c8), converted into the
// owner's group (or the item itself without an owner) with GetLocalMatPos (slot 0x94), started with
// ZGROUP::AddSound3d(m, p, id, 0, owner handle, 0). A random pitch step in -n..n (n = the template's GetPitchChange)
// is applied; a sound in the world room ([render manager]+0xadc) loses flag 4 of +0x40. Returns the sound handle (0
// for id 0).
static u32 THISCALL weaponPlaySound(u8 *s, u32 id) {
  if (!id)
    return 0;
  u8 *grp;
  if (((vU0)VT(s, 0x2f4))(s)) {
    u8 *o = (u8 *)((vU0)VT(s, 0x2f4))(s);
    grp = (u8 *)((vU0)VT(o, 0x20))(o);
  } else {
    grp = s;
  }
  float m[9], p[3];
  ((vUUU)VT(s, 0x2c8))(s, (u32)m, (u32)p);
  ((vUUU)VT(grp, 0x94))(grp, (u32)m, (u32)p);
  u32 ow = ((vU0)VT(s, 0x2f4))(s);
  u8 *rm = rmgr();
  u32 h = ((vUU)VT(rm, 0x4c))(rm, ow);
  u32 snd = ext_43ec00(grp, m, p, id, 0, h, 0);
  rm = rmgr();
  u8 *so = (u8 *)((vUU)VT(rm, 0x60))(rm, snd);
  if (!so)
    return snd;
  u8 *t = (u8 *)((vU0)VT(s, 0x350))(s);
  s32 n = (s32)((vU0)VT(t, 0x33c))(t);
  u8 *sy = G(u8 *, 0x70039c);
  long double r = ((vRand)VT(sy, 0x1c0))(sy, (const char *)0x6887c4, 0xa74);
  float f = (float)(r * (float)(n + n) - (float)n);
  s32 v = _mm_cvttss_si32(_mm_set_ss(f));
  *(s32 *)(so + 0x60) = v - *(s32 *)(so + 0x64);
  *(s32 *)(so + 0x64) = v;
  rm = rmgr();
  u8 *g2 = (u8 *)((vUU)VT(rm, 0x58))(rm, *(u32 *)(so + 0x3c));
  if (!g2)
    return snd;
  u32 room = ext_4db3b0(*(void **)(g2 + 8));
  if (room && room == *(u32 *)(rmgr() + 0xadc))
    *(u32 *)(so + 0x40) &= 0xfffffffbu;
  return snd;
}
PCREG(4700a0, weaponPlaySound);
