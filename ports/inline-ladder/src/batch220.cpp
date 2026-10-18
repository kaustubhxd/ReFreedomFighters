// batch220.cpp - hero action bodies (inline-ladder thread, 2026-10-11): ZFFActionSwingBat::CallBack (the bat hit).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void THISCALL ext_4e09b0(float *v);                                  // vneg
extern "C" long double FASTCALL ext_4e0830(const float *a, const float *b);    // vdist2 (x87, ST0)
extern "C" void FASTCALL ext_43e920(float *dst, const float *src, const float *a);   // PSVECSubtract
extern "C" long double FASTCALL ext_44c840(float *v);                          // vnorm (old length in ST0)

static inline void *db220() { return (void *)U32(G(u32, 0x70039c), 0x9b); }

// 0x5dfaa0 ZFFActionSwingBat::CallBack() [GC 80087a50, high; slot 3], AL = 0. +8 hero.
// At the hit frame: hero slot 0x80(mat, pos) gives the hero's matrix and position; fwd = -(first row). The cone is
// cos(2.35619449...) (the double at 0x6b7518, 135 degrees). Walk the engine list "TrackLinkObjects" (database +0xadc
// slot 0x25c; iterator at +0x18, slots 0x4c begin / 0x5c next): for each object (database slot 0x58) that passes
// slot 0x1e0(0x200074) (a class test) and is not the hero: p = its world origin (slot 0x84 of (0,0,0)); within
// vdist2 <= 28900 (170 units; NaN passes) and with dot(fwd, normalised p - pos) not below the cone (NaN passes), it is
// hit, and the walk stops. The hit object gets slot 0x128(msg "DamageInfo" (database slot 0x114, line 0x268), &info,
// 0), info = {ref(hero), 0, ?, ?, p.x, p.y + 120, p.z, dir, 40.0 at +0x28}: 40 damage, from the hero, at chest height.
// Exe quirk (not exercised by the spec, as it reads uninitialised stack): when the list has no iterator, or the first
// "next" already ends while returning a non-zero item, the "hit" goes to the list object itself with stack garbage.
static inline bool meleeHit(u8 *self, u32 line) {
  u8 *list = vcall<u8 *>((void *)U32(db220(), 0xadc), 0x25c, (const char *)0x685f44, 0u);
  float mat[9], pos[3];
  vcall<void>((void *)U32(self, 8), 0x80, mat, pos);
  ext_4e09b0(mat);
  float cosA = (float)crt::cos(G(double, 0x6b7518));
  u32 item;
  u8 *obj;
  float p[3], dir[3];
  u32 st[3];
  if (!U32(list, 0x18)) {
    item = (u32)list;
    obj = list;
  } else {
    vcall<void>((void *)U32(list, 0x18), 0x4c, st);
    item = vcall<u32>((void *)U32(list, 0x18), 0x5c, st);
    obj = list;
    if (st[0]) {
      for (;;) {
        obj = vcall<u8 *>(db220(), 0x58, item);
        if ((u8)vcall<u32>(obj, 0x1e0, 0x200074u) && obj != (u8 *)U32(self, 8)) {
          p[0] = 0.0f;
          p[1] = 0.0f;
          p[2] = 0.0f;
          vcall<void>(obj, 0x84, p);
          float d2 = (float)ext_4e0830(pos, p);
          if (!(d2 > 28900.0f)) {
            ext_43e920(dir, p, pos);
            (void)ext_44c840(dir);
            float dot = mat[1] * dir[1] + mat[0] * dir[0];
            dot = dot + mat[2] * dir[2];
            if (!(cosA > dot))
              break;
          }
        }
        item = vcall<u32>((void *)U32(list, 0x18), 0x5c, st);
        if (!st[0])
          break;
      }
    }
  }
  if (!item)
    return false;
  u32 info[12];
  info[0] = vcall<u32>(db220(), 0x4c, U32(self, 8));
  info[1] = 0;
  info[10] = 0x42200000;
  ((float *)info)[4] = p[0];
  ((float *)info)[6] = p[2];
  ((float *)info)[7] = dir[0];
  ((float *)info)[8] = dir[1];
  ((float *)info)[9] = dir[2];
  u8 *ovt = *(u8 **)obj;
  ((float *)info)[5] = p[1] + 120.0f;
  u32 msg = (u16)vcall<u32>(db220(), 0x114, (const char *)0x69eaac, 0u, (const char *)0x6b74a4, line);
  typedef void(THISCALL * fn)(void *, u32, void *, u32);
  (*(fn *)(ovt + 0x128))(obj, msg, info, 0);
  return false;
}
static bool THISCALL swingBatCallBack(u8 *self) { return meleeHit(self, 0x268); }
PCREG(5dfaa0, swingBatCallBack);

// 0x5dfea0 ZFFActionUseKnife::CallBack() [GC 800886a0, medium; slot 3] (batch 221): the same machine code as
// SwingBat::CallBack except the source line 0x406 given with the DamageInfo message registration. Same range (170),
// cone (135 degrees) and damage (40): the knife hits exactly like the bat.
static bool THISCALL useKnifeCallBack(u8 *self) { return meleeHit(self, 0x406); }
PCREG(5dfea0, useKnifeCallBack);
