// batch711.cpp - soldier AI, batch 711 (2026-10-11): CFFCoverList::FindCover, the cover-spot search.
// Spots are sorted by world x (the search starts with a lower_bound on x). Spot fields used: +4 holder, +0xc ref of the
// cover object (0 = none), +0x10 position, +0x1c facing. CFFCoverList +0x6f is a geom whose root point every spot must
// keep a distance from (inferred: the hero), +0x57 receives the chosen spot's local depth.
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);   // out = a - b (x87)
extern "C" void FASTCALL ext_4419f0(float *v, const float *m);                     // vmmul: v = v * m (x87)
extern "C" void FASTCALL ext_441940(float *v, const float *b);                     // PSVECAdd: v += b (x87)
extern "C" void FASTCALL ext_441a60(float *v, const float *m);                     // vmtmul: v = v * transpose(m)
extern "C" float FASTCALL ext_4e0830(const float *a, const float *b);              // vdist2 (squared distance)
extern "C" float THISCALL ext_585910(void *, void *, float *, u32);               // CoverSpotQuality
extern "C" void THISCALL ext_5df400(void *, u32, float, u32, u32);                // CCoverSpot::Reserve
extern "C" double VECTORCALL ext_634d7c(double);                                   // CRT sqrt (through the IAT)

static inline void *db() { return *(void **)(*(u8 **)0x70039c + 0x9b); }
static inline float mx(float a, float b) { return a > b ? a : b; }   // maxss a, b
static inline float mn(float a, float b) { return a < b ? a : b; }   // minss a, b
static inline double dabs(float v) { return __builtin_fabs((double)v); }

// Another held spot within 350 (squared 122500) whose facing points away from or across the candidate's
// (dot <= 0) and that lies in front of the candidate (dot(candidate facing, other - candidate) > 0) rules the
// candidate out.
static inline bool blocked_by(u8 *other, u8 *cur) {
  if (*(u32 *)(other + 4) == 0)
    return false;
  float d2 = ext_4e0830((float *)(other + 0x10), (float *)(cur + 0x10));
  if (d2 > 122500.0f)                 // 0x6abbb4
    return false;
  float *fo = (float *)(other + 0x1c), *fc = (float *)(cur + 0x1c);
  float dot = fo[1] * fc[1] + fo[0] * fc[0];
  dot = dot + fc[2] * fo[2];
  if (!(0.0f >= dot))
    return false;
  float v[3];
  ext_43e920(v, (float *)(other + 0x10), (float *)(cur + 0x10));
  float p = fc[1] * v[1] + fc[0] * v[0];
  p = p + fc[2] * v[2];
  return p > 0.0f;
}

// 0x586bc0 CFFCoverList::FindCover(unsigned int actor, unsigned int threat, float* mat, float* pos, float zMin,
// float zMax, float xHalf, float unused, float* goal, bool flag) [high]. Search box: in the frame of mat around pos,
// x in [-xHalf, xHalf], z in [zMin, zMax]. A spot qualifies when it is free, its cover object (if any) is active, it
// faces the threat (CoverSpotQuality > 0, when a threat is given), its height difference minus 120 is at most 0.2 of
// its distance, it is at least 75 from the +0x6f geom (200 when the actor is a ZFFActor of team 1), at least 450 from
// the threat, inside the area of the actor's slot-0x614 geom (slot 0x180 test with margin 10) when the actor is a
// ZActor that has one, and not blocked by a neighbour (blocked_by). The qualifying spot nearest to goal is reserved
// for 5 s and its index returned; -1 if none. The 8th argument is not read.
static s32 THISCALL cover_FindCover(u8 *self, u32 actor, u32 threat, float *mat, float *pos, float zMin, float zMax,
                                    float xHalf, float, float *goal, u32 flag) {
  u8 *ag = vcall<u8 *>(db(), 0x58, actor);
  void *tg = 0;
  if (threat)
    tg = vcall<void *>(db(), 0x58, threat);
  float best = 9.99999968e37f;          // 0x67cd44
  u8 *bestSpot = 0;
  float tpos[3] = {0, 0, 0};
  if (tg)
    vcall<void>(tg, 0x84, tpos);
  float minOwn = 5625.0f;               // 0x6abbac
  if (vcall<bool>(ag, 0x1e0, 0x2007f9) && *(u32 *)(*(u8 **)(ag + 0x54) + 4) == 1)
    minOwn = 40000.0f;                  // 0x6abbb0
  float opos[3] = {0, 0, 0};
  vcall<void>(*(void **)(self + 0x6f), 0x84, opos);
  float nx = -xHalf;
  float c1[3] = {nx, 0, zMin}, c2[3] = {nx, 0, zMax}, c3[3] = {xHalf, 0, zMax}, c4[3] = {xHalf, 0, zMin};
  ext_4419f0(c1, mat); ext_441940(c1, pos);
  ext_4419f0(c2, mat); ext_441940(c2, pos);
  ext_4419f0(c3, mat); ext_441940(c3, pos);
  ext_4419f0(c4, mat); ext_441940(c4, pos);
  float hi = mx(c4[0], mx(c3[0], mx(c2[0], mx(c1[0], -9.99999968e37f))));
  float lo = mn(c4[0], mn(c3[0], mn(c2[0], mn(c1[0], 9.99999968e37f))));
  void *area = 0;
  if (vcall<bool>(ag, 0x1e0, 0x2007d0))
    area = vcall<void *>(db(), 0x58, vcall<u32>(ag, 0x614));

  u8 *begin = *(u8 **)(self + 0x5f), *end = *(u8 **)(self + 0x63);
  s32 n = (s32)(end - begin) / 0x48;
  u8 *s = begin;
  while (n > 0) {
    s32 half = n >> 1;
    u8 *mid = s + half * 0x48;
    if (lo > *(float *)(mid + 0x10)) {
      s = mid + 0x48;
      n += -1 - half;
    } else {
      n = half;
    }
  }
  for (; s != *(u8 **)(self + 0x63); s += 0x48) {
    if (!(hi > *(float *)(s + 0x10)))
      break;
    u32 cref = *(u32 *)(s + 0xc);
    if (cref) {
      u8 *cg = vcall<u8 *>(db(), 0x58, cref);
      if (!(~(*(u32 *)(*(u8 **)(cg + 8) + 0x3c) >> 10) & 1))
        continue;
    }
    float l[3];
    ext_43e920(l, (float *)(s + 0x10), pos);
    ext_441a60(l, mat);
    float lz = l[2], lx = l[0];
    if (lz > zMax || zMin > lz)
      continue;
    if (dabs(lx) > (double)xHalf)
      continue;
    if (*(u32 *)(s + 4) != 0)
      continue;
    if (tg) {
      float q = ext_585910(self, s, tpos, flag);
      if (0.0f >= q)
        continue;
      lz = l[2];
      lx = l[0];
    }
    float ly = l[1];
    double dy = dabs(ly) - 120.0;       // 0x6abb98
    float r2 = ly * ly + lx * lx;
    r2 = r2 + lz * lz;
    float dist = (float)ext_634d7c((double)r2);
    if (dy > (double)(dist * 0.2f))     // 0x67c194
      continue;
    if (minOwn > ext_4e0830(opos, (float *)(s + 0x10)))
      continue;
    if (202500.0f > ext_4e0830(tpos, (float *)(s + 0x10)))   // 0x6abbb8
      continue;
    if (area) {
      float p[3] = {((float *)(s + 0x10))[0], ((float *)(s + 0x10))[1], ((float *)(s + 0x10))[2]};
      vcall<void>(area, 0x8c, p);
      if (!vcall<bool>(area, 0x180, p, 10.0f))
        continue;
    }
    bool bad = false;
    for (u8 *o = s; o != *(u8 **)(self + 0x5f);) {
      o -= 0x48;
      if (*(float *)(s + 0x10) - 350.0f > *(float *)(o + 0x10))   // 0x6abba4
        break;
      if (blocked_by(o, s)) {
        bad = true;
        break;
      }
    }
    if (bad)
      continue;
    for (u8 *o = s + 0x48; o != *(u8 **)(self + 0x63); o += 0x48) {
      if (*(float *)(o + 0x10) > *(float *)(s + 0x10) + 350.0f)
        break;
      if (blocked_by(o, s)) {
        bad = true;
        break;
      }
    }
    if (bad)
      continue;
    float d = ext_4e0830(goal, (float *)(s + 0x10));
    if (best > d) {
      best = d;
      bestSpot = s;
      *(float *)(self + 0x57) = l[2];
    }
  }
  if (!bestSpot)
    return -1;
  ext_5df400(bestSpot, actor, 5.0f, threat, flag);
  return (s32)(bestSpot - *(u8 **)(self + 0x5f)) / 0x48;
}
PCREG(586bc0, cover_FindCover);
