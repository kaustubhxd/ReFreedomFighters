// batch513.cpp - weapons thread, batch 513: spare-ammo store and the right hand's line-of-fire checks.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vU0)(void *self);
typedef u32(THISCALL *vUU)(void *self, u32 a);
typedef u32(THISCALL *vUUU)(void *self, u32 a, u32 b);
typedef u8(THISCALL *vCast)(void *self, u8 *coli, u32 a, u32 mask, u32 b, u32 c, u32 d);
typedef void *(THISCALL *vLogLine)(void *self, const char *file, u32 line);
typedef void (*logPrintf)(void *self, const char *fmt, ...);

extern "C" const char *THISCALL ext_4cc1d0(void *mystr);          // MYSTR -> const char*
extern "C" void THISCALL ext_4cbec0(void *mystr);                 // MYSTR::~MYSTR
extern "C" u32 THISCALL ext_4666d0(u8 *t);                        // ZTARGET::Geom
extern "C" u8 THISCALL ext_4669c0(u8 *t, float *out);             // ZTARGET::GetPos
extern "C" void THISCALL ext_4e1b60(u8 *coli);                    // COLI::COLI
extern "C" void FASTCALL ext_43e960(float *a, const float *b);    // a -= b (x87)
extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);   // PSVECSubtract: out = a - b
extern "C" void FASTCALL ext_4e0d80(float *v, float len);         // vsetlen

static inline u8 *rmgr() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

static inline void muzzlePos(u8 *m, float *p) {
  u8 *g = *(u8 **)(m + 8);
  p[0] = *(float *)(g + 0x24);
  p[1] = *(float *)(g + 0x28);
  p[2] = *(float *)(g + 0x2c);
}
static inline u8 cast(u8 *coli, const float *from, const float *dir) {
  ((float *)coli)[0] = from[0];
  ((float *)coli)[1] = from[1];
  ((float *)coli)[2] = from[2];
  ((float *)coli)[3] = dir[0];
  ((float *)coli)[4] = dir[1];
  ((float *)coli)[5] = dir[2];
  u8 *world = *(u8 **)(rmgr() + 0xadc);
  return ((vCast)VT(world, 0x2e0))(world, coli, 0, 2, 0xffffffffu, 1, 0);
}

// 0x472930 ZLNKWHANDS::CheckRHandFireTarget(): with firing enabled (+0x3a4), a right-hand weapon with a muzzle exit
// geom (slot 0x348) and a live aim-target geom: cast a ray (mask 2) from the muzzle to the target's root point and
// return whether the first thing hit (COLI +0x44) is the target.
static u8 THISCALL checkRHandFireTarget(u8 *self) {
  if (!self[0x3a4])
    return 0;
  u8 *w = (u8 *)((vU0)VT(self, 0x50c))(self);
  if (!w)
    return 0;
  u8 *m = (u8 *)((vU0)VT(w, 0x348))(w);
  if (!m)
    return 0;
  u8 *rm = rmgr();
  u8 *g = (u8 *)((vUU)VT(rm, 0x58))(rm, ext_4666d0(self + 0x26a));
  if (!g)
    return 0;
  float mp[3], tp[3];
  muzzlePos(m, mp);
  ((vUU)VT(w, 0x84))(w, (u32)mp);
  tp[0] = 0.0f;
  tp[1] = 0.0f;
  tp[2] = 0.0f;
  ((vUU)VT(g, 0x84))(g, (u32)tp);
  ext_43e960(tp, mp);
  u8 coli[0x70];
  ext_4e1b60(coli);
  cast(coli, mp, tp);
  return *(u32 *)(coli + 0x44) == ext_4666d0(self + 0x26a);
}
PCREG(472930, checkRHandFireTarget);

