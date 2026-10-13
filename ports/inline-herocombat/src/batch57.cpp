// batch57.cpp - climb tree, inline session batch 57: ZFFHeroMovementClimb::WantControl (0x5e75a0), the climb test.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vcallUP)(void *self, void *a);
typedef u32(THISCALL *vcallUU)(void *self, u32 a);
typedef void(THISCALL *vcallV0)(void *self);
typedef void(THISCALL *vcallVP)(void *self, void *a);
typedef float(THISCALL *vcallF0)(void *self);
typedef void(THISCALL *vcallVPPP)(void *self, void *a, void *b, void *c);
typedef u8(THISCALL *rayCast)(void *self, void *coli, u32 a, u32 mask, u32 b, u32 c, u32 d);
typedef u8 *(THISCALL *logGet)(void *self, u32 file, u32 line);
typedef void(__attribute__((cdecl)) *logPrint)(void *self, u32 fmt, double v);

extern "C" void THISCALL ext_4e1b60(u8 *coli);                                         // COLI::COLI
extern "C" void FASTCALL ext_451890(float *dst, const float *v, float s);              // dst += v * s
extern "C" void FASTCALL ext_4e0d40(float *dst, const float *v, float s);              // dst = v * s
extern "C" void FASTCALL ext_446ee0(float *dst, const float *a, const float *b);       // vcross
extern "C" void FASTCALL ext_4de420(float *dst, const float *src);                     // mcpy, nine dwords
extern "C" void THISCALL ext_45bfd0(u8 *coli, float *n);                                // COLI hit-triangle normal

static u8 *world() { return *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xadc); }

// The level's ray cast (collision world slot 0x2e0) with the arguments WantControl always uses.
static u8 cast(u8 *coli) {
  *(float *)(coli + 0x34) = 1.0f;
  u8 *w = world();
  return ((rayCast)VT(w, 0x2e0))(w, coli, 0, 0x20, 0xffffffffu, 1, 0);
}

// 0x5e75a0 ZFFHeroMovementClimb::WantControl(const float*, const float*, const float*), thiscall, ret 0xc, result in al.
// The arguments are not used. Already climbing (+0x1d): true. The hero (+4) must have flag 0x80000 at +0x417.
// It flushes the queued objects of the list at +0x76 into the collision world (slot 0x220) and closes the list
// (slot 0xc). With the hero's frame (slot 0x5a0: matrix M, position P, extents X) and foot height (slot 0x5b4), it
// casts four rays down from 390 above, 15 apart along -M row 0 starting at -X[2], for the floor heights h[0..3].
// The first pair closer than 15 is the ledge. Three more rays check the space over it, the gap in front and the wall
// face; then the wall normal sets the side (flip), and the height picks one of four climbs (to 90, 140, 200, 220,
// with animations at +0x1e to +0x3a and speeds 1, 7, 7, 13 at +0x42). Higher ledges are logged as unsupported.
// On success the climb's start frame M goes to +0x46 and the start point to +0x6a.
static u8 THISCALL wantControl(u8 *self, const float *, const float *, const float *) {
  if (self[0x1d])
    return 1;
  u8 *hero = *(u8 **)(self + 4);
  if (!(*(u32 *)(hero + 0x417) & 0x80000))
    return 0;
  float foot = ((vcallF0)VT(hero, 0x5b4))(hero);
  u8 *list = *(u8 **)(self + 0x76);
  u32 it;
  if (list) {
    ((vcallVP)VT(list, 0x4c))(list, &it);
    u32 v = ((vcallUP)VT(*(u8 **)(self + 0x76), 0x5c))(*(u8 **)(self + 0x76), &it);
    while (it != 0) {
      u8 *w = world();
      ((vcallUU)VT(w, 0x220))(w, v);
      v = ((vcallUP)VT(*(u8 **)(self + 0x76), 0x5c))(*(u8 **)(self + 0x76), &it);
    }
  }
  list = *(u8 **)(self + 0x76);
  ((vcallV0)VT(list, 0xc))(list);
  float m[9], x[3], p[3], h[4], n[3], c[3];
  __attribute__((aligned(4))) u8 coli[0x70];
  hero = *(u8 **)(self + 4);
  ((vcallVPPP)VT(hero, 0x5a0))(hero, m, p, x);
  p[1] -= foot;
  ext_4e1b60(coli);
  float *from = (float *)coli, *dir = (float *)(coli + 0xc), *hit = (float *)(coli + 0x28);
  from[0] = p[0];
  from[2] = p[2];
  from[1] = p[1] + 390.0f;
  coli[0x6c] = 0;
  ext_451890(from, m, -x[2]);
  dir[0] = 0.0f;
  dir[1] = -390.0f;
  dir[2] = 0.0f;
  for (int j = 0; j < 4; ++j) {
    h[j] = 0.0f;
    if (cast(coli))
      h[j] = hit[1] - p[1];
    ext_451890(from, m, -15.0f);
  }
  int j = 0;
  for (; j < 3; ++j)
    if (15.0 > __builtin_fabs((double)(h[j] - h[j + 1])))
      break;
  if (j == 3)
    return 0;
  // Nothing above the ledge.
  from[0] = p[0];
  from[2] = p[2];
  from[1] = (h[j] > h[j + 1] ? h[j] : h[j + 1]) + 5.0f + p[1];
  ext_4e0d40(dir, m, -((float)(j + 1) * 15.0f + x[2]));
  if (cast(coli))
    return 0;
  // Nothing in the way up to the ledge.
  from[0] = p[0];
  from[2] = p[2];
  from[1] = h[j] + 1.0f + p[1];
  float t = (float)j * 15.0f;
  ext_451890(from, m, -(t + x[2]));
  dir[0] = 0.0f;
  dir[1] = 180.0f;
  dir[2] = 0.0f;
  if (cast(coli))
    return 0;
  // The wall face just below the ledge.
  from[0] = p[0];
  from[2] = p[2];
  from[1] = h[j] - 1.0f + p[1];
  ext_4e0d40(dir, m, -(t + x[2] + 1.0f));
  if (!cast(coli))
    return 0;
  ext_45bfd0(coli, n);
  u8 *rm = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *obj = (u8 *)((vcallUU)VT(rm, 0x58))(rm, *(u32 *)(coli + 0x44));
  ((vcallVP)VT(obj, 0x88))(obj, n);
  ext_446ee0(c, n, dir);
  u8 flip = c[1] > 0.0f;
  float d = n[1] * dir[1] + n[0] * dir[0] + n[2] * dir[2];
  if (d > 0.0f)
    flip ^= 1;
  p[0] = hit[0];
  p[2] = hit[2];
  float hj = h[j];
  if (25.0f >= hj)
    return 0;
  u32 anim;
  if (hj > 25.0f && 90.0f >= hj) {
    ext_451890(p, m, 37.0f);
    p[1] = hj - 50.0f + p[1];
    anim = *(u32 *)(self + (flip ? 0x1e : 0x22));
    *(float *)(self + 0x42) = 1.0f;
  } else if (140.0f >= hj) {
    ext_451890(p, m, 46.0f);
    p[1] = hj - 100.0f + p[1];
    anim = *(u32 *)(self + (flip ? 0x26 : 0x2a));
    *(float *)(self + 0x42) = 7.0f;
  } else if (200.0f >= hj) {
    ext_451890(p, m, 56.0f);
    p[1] = hj - 150.0f + p[1];
    anim = *(u32 *)(self + (flip ? 0x2e : 0x32));
    *(float *)(self + 0x42) = 7.0f;
  } else if (220.0f >= hj) {
    ext_451890(p, m, 47.0f);
    p[1] = hj - 210.0f + p[1];
    anim = *(u32 *)(self + (flip ? 0x36 : 0x3a));
    *(float *)(self + 0x42) = 13.0f;
  } else {
    u8 *lg = G(u8 *, 0x700390);
    u8 *out = ((logGet)VT(lg, 0x20))(lg, 0x6b7a5cu, 0x3a9);
    ((logPrint)VT(out, 0x2c))(out, 0x6b7bf4u, (double)hj);   // "climb height %f not supported"
    return 0;
  }
  *(u32 *)(self + 0x3e) = anim;
  if (!anim)
    return 0;
  ext_4de420((float *)(self + 0x46), m);
  *(float *)(self + 0x6a) = p[0];
  *(float *)(self + 0x6e) = p[1];
  *(float *)(self + 0x72) = p[2];
  return 1;
}
PCREG(5e75a0, wantControl);
