// batch1211.cpp - pathfinding tree: line-of-walk checks (straight walk through the octree from cell to cell).
#include "pf.h"

extern "C" void THISCALL ext_52db40(void *it);
extern "C" u32 THISCALL ext_52e320(void *it, const s16 *d);     // ElementMove
extern "C" u32 THISCALL ext_531070(void *it, const s16 *d);     // NodeMove
extern "C" u32 THISCALL ext_531740(void *it, const u16 *pos, int level);
extern "C" int THISCALL ext_52dbb0(void *oct, const u8 *a, const u8 *b, void *helpers);
extern "C" int THISCALL ext_530e80(void *oct, u16 *out, const u16 *pos, u32 ry, u32 rxz, float weight);
extern "C" int THISCALL ext_530bf0(void *it, u16 *out, float *p, u8 *flag);
extern "C" int THISCALL ext_52dfc0(void *oct, const u16 *a, const u16 *b);

#define IT_SIZE 0x2d

// 0x52db40 (no GC name) ZPFOctreeIterator_packed: per-axis steps for its level (as in SetPosition) and the kind:
// 3 (element) on the leaf level, 2 (area) one above, 1 (node) two or more above; other levels keep the kind.
static void THISCALL iterUpdateLevel(u8 *it) {
  u32 L = (u32)*(int *)(*(u8 **)it + 0x38) - *(u32 *)(it + 0x12);
  if (L) {
    u32 s = (L - 1) & 0x1f;
    *(u32 *)(it + 0x21) = 8u << s;
    *(u32 *)(it + 0x25) = 8u << s;
    *(u32 *)(it + 0x29) = 1u << s;
  } else {
    *(u32 *)(it + 0x21) = 1;
    *(u32 *)(it + 0x25) = 1;
    *(u32 *)(it + 0x29) = 1;
  }
  int lev = *(int *)(it + 0x12), levels = *(int *)(*(u8 **)it + 0x38);
  if (lev == levels) it[0x20] = 3;
  if (lev == (int)((u32)levels - 1u)) it[0x20] = 2;
  if (lev <= (int)((u32)levels - 2u)) it[0x20] = 1;
}
PCREG(52db40, iterUpdateLevel);

static inline int iabs(int v) { return (int)(((u32)v ^ (u32)(v >> 31)) - (u32)(v >> 31)); }

// 0x52dbb0 ZPFOctree_packed::CheckLine(SPFAStarData_packed* a, SPFAStarData_packed* b, CHelpers*) [map medium; GC
// 80194be8]. thiscall, ret 0xc, 1 = walkable straight line. A 2-D Bresenham-like walk in x/z from a's cell to b's
// (one axis step per iteration, chosen by the smaller cross-product error), where each step may also go one cell up
// or down if the level move is blocked; the walk fails when no move works, when the height leaves the band -2..+5
// cells around the straight line's height, or after 1000 steps. Success when x/z reach b with the height within
// -2..+5 of b's. The iterator is copied whole (0x2d bytes) before each try and taken over on success.
static int THISCALL lineCheck(u8 *self, const u8 *a, const u8 *b, void *) {
  s16 dx = (s16)(*(u16 *)(b + 4) - *(u16 *)(a + 4));
  s16 dz = (s16)(*(u16 *)(b + 6) - *(u16 *)(a + 6));
  s16 dy = (s16)(*(u16 *)(b + 8) - *(u16 *)(a + 8));
  float inv = 1.0f / (float)(int)((u32)(int)dx * (u32)(int)dx + (u32)(int)dz * (u32)(int)dz +
                                  (u32)(int)dy * (u32)(int)dy);
  u16 sx = dx > 0 ? 1 : 0xffff, sz = dz > 0 ? 1 : 0xffff;
  u16 px = *(u16 *)(a + 4), pz = *(u16 *)(a + 6), py = *(u16 *)(a + 8);
  u8 S[IT_SIZE], W[IT_SIZE];
  if (self) {
    *(u8 **)S = self;
    *(u16 **)(S + 4) = (u16 *)(self + 0x96);
    *(u32 *)(S + 8) = 0x40;
  }
  int levels = *(int *)(self + 0x38);
  *(u16 *)(S + 0x18) = px;
  *(u16 *)(S + 0x1a) = pz;
  *(u16 *)(S + 0x1c) = py;
  *(u16 *)(S + 0xc) = px;
  *(u16 *)(S + 0xe) = pz;
  *(u16 *)(S + 0x10) = py;
  *(u16 *)(S + 0x16) = *(u16 *)a;
  *(int *)(S + 0x12) = levels;
  S[0x1f] = (u8)levels;
  if (!*(u16 *)a) return 0;
  ext_52db40(S);
  for (int iter = 0; iter < 1000; iter++) {
    u16 nx = px + sx, nz = pz + sz;
    int pzA = (s16)(pz - *(u16 *)(a + 6));
    int nxA = (s16)(nx - *(u16 *)(a + 4));
    int e1 = iabs((int)((u32)(int)(s16)(px - *(u16 *)(b + 4)) * (u32)(int)dz -
                        (u32)(int)(s16)(nz - *(u16 *)(b + 6)) * (u32)(int)dx));
    int e2 = iabs((int)((u32)nxA * (u32)(int)dz - (u32)pzA * (u32)(int)dx));
    s16 d[3];
    if (e2 < e1) {
      d[0] = (s16)(u16)(nx - px);
      d[1] = 0;
    } else {
      d[0] = 0;
      d[1] = (s16)(u16)(nz - pz);
    }
    static const s16 ys[3] = {0, 1, -1};
    u16 id = 0;
    for (int t = 0; t < 3 && !id; t++) {
      __builtin_memcpy(W, S, IT_SIZE);
      d[2] = ys[t];
      id = (u16)(S[0x20] == 3 ? ext_52e320(W, d) : ext_531070(W, d));
    }
    if (!id) return 0;
    px += (u16)d[0];
    pz += (u16)d[1];
    py += (u16)d[2];
    __builtin_memcpy(S, W, IT_SIZE);
    float proj = (float)(int)((u32)nxA * (u32)(int)dx + (u32)pzA * (u32)(int)dz) * inv * (float)(int)dy +
                 (float)(int)*(u16 *)(a + 8);
    int band = (int)((u32)_mm_cvtt_ss2si(_mm_set_ss(proj)) - (u32)py);
    if (band > 5 || band < -2) return 0;
    if (px == *(u16 *)(b + 4) && pz == *(u16 *)(b + 6)) {
      int e = (int)py - (int)*(u16 *)(b + 8);
      if (e <= 5 && e >= -2) return 1;
    }
  }
  return 0;
}
PCREG(52dbb0, lineCheck);

// 0x52dfc0 (no GC name) line check between two cells: equal cells pass; else the start cell's element is found
// (iterator SetPosition at the leaf level) and the A*-record form of both cells goes to the line check above.
// thiscall (octree), ret 8, bool.
static bool THISCALL cellLineCheck(u8 *self, const u16 *a, const u16 *b) {
  if (a[0] == b[0] && a[1] == b[1] && a[2] == b[2]) return true;
  u8 it[0x30];
  if (self) {
    *(u8 **)it = self;
    *(u16 **)(it + 4) = (u16 *)(self + 0x96);
    *(u32 *)(it + 8) = 0x40;
  }
  ext_531740(it, a, *(int *)(self + 0x38));
  u8 ra[0x18], rb[0x18];
  u16 id = *(u16 *)(it + 0x16);
  *(u16 *)(ra + 4) = a[0];
  *(u16 *)(ra + 6) = a[1];
  *(u16 *)(ra + 8) = a[2];
  *(u16 *)(rb + 4) = b[0];
  *(u16 *)(rb + 6) = b[1];
  *(u16 *)(rb + 8) = b[2];
  *(u16 *)ra = id;
  *(u16 *)rb = id;
  return ext_52dbb0(self, ra, rb, 0) != 0;
}
PCREG(52dfc0, cellLineCheck);

static inline void worldToCell(u8 *oct, const float *p, u16 *c) {
  float *mn = (float *)(oct + 6), *mx = (float *)(oct + 0x12);
  float ex = mx[0] - mn[0], ey = mx[1] - mn[1], ez = mx[2] - mn[2];
  float lx = (p[0] - mn[0]) / ex * (float)*(int *)(oct + 0x3c);
  float ly = (p[1] - mn[1]) / ey * (float)*(int *)(oct + 0x44);
  float lz = (p[2] - mn[2]) / ez * (float)*(int *)(oct + 0x40);
  c[0] = (u16)_mm_cvtt_ss2si(_mm_set_ss(lx));
  c[1] = (u16)_mm_cvtt_ss2si(_mm_set_ss(lz));
  c[2] = (u16)_mm_cvtt_ss2si(_mm_set_ss(ly));
}

// 0x530bf0 (no GC name) ZPFOctreeIterator_packed: nearest walkable cell (1 cell in x/z, 10 below) of a world point.
// thiscall (iterator), ret 0xc. Sets *flag = 1 first.
static int THISCALL iterNearestCell(u8 *it, u16 *out, float *p, u8 *flag) {
  *flag = 1;
  u8 *oct = *(u8 **)it;
  u16 c[3];
  worldToCell(oct, p, c);
  return ext_530e80(*(u8 **)it, out, c, 10, 1, 1.0f);
}
PCREG(530bf0, iterNearestCell);

// 0x52e0a0 ZPFOctree_packed::CheckLine(float* a, float* b, bool snapY) [map medium; GameCube reference]. thiscall, ret 0xc,
// bool. Both points go to their nearest walkable cell (fails when none); with snapY both points' y is moved to the top
// of that cell (cell y + 1, world space); then the cell line check.
static bool THISCALL worldLineCheck(u8 *self, float *a, float *b, u32 snap) {
  u8 it[0x30];
  if (self) {
    *(u8 **)it = self;
    *(u16 **)(it + 4) = (u16 *)(self + 0x96);
    *(u32 *)(it + 8) = 0x40;
  }
  u8 *oct = *(u8 **)it;
  u16 c[3], ca[4], cb[4];
  worldToCell(oct, a, c);
  if (!ext_530e80(oct, ca, c, 10, 1, 1.0f)) return false;
  u8 flag;
  if (!ext_530bf0(it, cb, b, &flag)) return false;
  if ((u8)snap) {
    float *mn = (float *)(self + 6), *mx = (float *)(self + 0x12);
    float ey = mx[1] - mn[1];
    u32 ya = (u16)(ca[2] + 1), yb = (u16)(cb[2] + 1);
    float ay = ey * (float)(int)ya / (float)*(int *)(self + 0x44) + mn[1];
    ey = mx[1] - mn[1];
    float by = ey * (float)(int)yb / (float)*(int *)(self + 0x44) + mn[1];
    a[1] = ay;
    b[1] = by;
  }
  return ext_52dfc0(self, ca, cb) != 0;
}
PCREG(52e0a0, worldLineCheck);
