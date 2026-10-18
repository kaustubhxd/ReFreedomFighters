// batch1212.cpp - pathfinding tree: the coarse (hierarchical) flood fill steps of FindPathCoarse.
//
// Coarse A* records (same SPFAStarData_packed array): +0 node/area id, +3 u8 sub-slot (1-based component inside the
// node), +4/+6/+8 cell, +0xa f, +0xe from. A node of the size table (+0x78, 10 bytes) has +0 u8 slot count, +1/+2
// u8 face sizes, +6 u16 first word of its connectivity bits in the bitset at octree+0x60.
// The global byte 0x6e9000 switches the Manhattan heuristic on.
#include "pf.h"

extern "C" u32 THISCALL ext_5320b0(void *oct, u32 from, int level, void *it, const u16 *x);
extern "C" u32 THISCALL ext_531e70(void *oct, u16 *cur, u32 from, const u16 *x, u32 dir, float w, const u16 *pos,
                                   u32 idx, u8 *S1, u8 *S0, u8 *rec, int b, int a, u32 flag, int ofs);
extern "C" u32 THISCALL ext_52e320(void *it, const s16 *d);
extern "C" u32 THISCALL ext_531070(void *it, const s16 *d);
extern "C" u32 THISCALL ext_530a40(void *it);
extern "C" u32 THISCALL ext_532730(void *oct, u32 action);
extern "C" void THISCALL ext_52d250(void *oct, u32 head, u32 node);
extern "C" float FASTCALL ext_532850(const u16 *a, const u16 *b);

#define ASTAR(o, i) (*(u8 **)((o) + 0x98) + (u32)(u16)(i) * 0x15)
#define USE_HEURISTIC G(u8, 0x6e9000)

// 0x532850 (no GC name) Manhattan distance of two cells, as a float in ST0. fastcall (a, b).
static float FASTCALL cellDistance(const u16 *a, const u16 *b) {
  int dz = (int)a[2] - (int)b[2], dy = (int)a[1] - (int)b[1], dx = (int)a[0] - (int)b[0];
  return (float)(((dz < 0 ? -dz : dz) + (dy < 0 ? -dy : dy)) + (dx < 0 ? -dx : dx));
}
PCREG(532850, cellDistance);

static inline int adiff(u16 a, u16 b) {
  int d = (int)a - (int)b;
  return d < 0 ? -d : d;
}

// 0x531e70 ZPFOctree_packed::VisitNeighborFloodFillCoarseSplit(...) [map medium; GC 80199dac]. thiscall, ret 0x38,
// returns 1. For every component (1..a) of the neighbour node: test the connectivity bit between the current
// component and it (flag: bit in the source node's set at rec.sub + (k-1)*b + ofs - 1; else in the neighbour's set at
// (rec.sub-1)*a + k + ofs - 1), and relax A* slot idx-1+k with cost 1 (or the Manhattan step with the heuristic on:
// f = rec.f + |rec-pos| + |x-pos| - |x-rec| + 0.0001). The direction and the float weight are not used on PC.
static u32 THISCALL floodSplit(u8 *self, u16 *cur, u32 from, const u16 *x, u32, float, const u16 *pos, u32 idx,
                               u8 *S1, u8 *S0, u8 *rec, int b, int a, u32 flag, int ofs) {
  int acc = 0;
  for (int k = 1; k < a + 1; k++, acc += b) {
    int bit;
    u8 *tbl;
    if ((u8)flag) {
      bit = rec[3] + acc + ofs - 1;
      tbl = S0;
    } else {
      bit = (rec[3] - 1) * a + k + ofs - 1;
      tbl = S1;
    }
    u32 w = *(u16 *)(tbl + 6) + (bit >> 5);
    if (!((*(u32 **)(self + 0x60))[w] & (1u << (bit & 31)))) continue;
    u16 slot = (u16)(idx - 1 + k);
    u8 *n = ASTAR(self, slot);
    float hx = 1.0f, h0 = 0.0f, h1 = 0.0f;
    if (USE_HEURISTIC && x) {
      h0 = (float)(adiff(x[2], pos[2]) + adiff(x[1], pos[1]) + adiff(x[0], pos[0]));
      u16 *r = (u16 *)(rec + 4);
      h1 = (float)(adiff(x[2], r[2]) + adiff(x[1], r[1]) + adiff(x[0], r[0]));
      hx = (float)(adiff(r[2], pos[2]) + adiff(r[1], pos[1]) + adiff(r[0], pos[0]));
    }
    float f = *(float *)(rec + 0xa) + hx;
    f = f + h0;
    f = f - h1;
    f = f + 0.0001f;
    if (!(*(float *)(n + 0xa) > f + 0.1f)) continue;
    n[0x14] &= 0xfe;
    *(u16 *)(n + 0xe) = (u16)from;
    *(float *)(n + 0xa) = f;
    *(u16 *)(n + 4) = pos[0];
    *(u16 *)(n + 6) = pos[1];
    *(u16 *)(n + 8) = pos[2];
    n[3] = (u8)k;
    *(u16 *)n = *cur;
    ext_52d250(self, from, slot);
  }
  return 1;
}
PCREG(531e70, floodSplit);

#define DIRS ((const s16 *)0x6e9004)
static inline u8 *sizeRec(u8 *self, int level, u16 id) {
  u16 i = level == *(int *)(self + 0x38) - 1 ? *(u16 *)(*(u8 **)(self + 0x5a) + id * 12)
                                              : *(u16 *)(*(u8 **)(self + 0x54) + id * 0x16);
  return *(u8 **)(self + 0x78) + i * 10;
}

// 0x531c40 ZPFOctree_packed::VisitNeighborFloodFillCoarse(unsigned short from, int level, ZPFOctreeIterator_packed*,
// PFDirection, const unsigned short* goal) [map high; GC 80199a14]. thiscall, ret 0x14: 0 blocked, 0xffff A* full,
// else Split's result. Direction 10 = special links, 11 = stay; the direction picks which face's connectivity bits are
// used (0/1: face size +1, 2/3: none, 4/5: faces +1 and +2 with weight 0.125; even = from the source node's set).
static u32 THISCALL floodCoarse(u8 *self, u32 from, int level, u8 *it, u32 dir, const u16 *x) {
  if (dir == 10) return ext_5320b0(self, from, level, it, x);
  u8 *rec = ASTAR(self, from);
  u8 *S0 = sizeRec(self, level, *(u16 *)rec);
  u16 id;
  if (dir == 11) id = *(u16 *)(it + 0x16);
  else id = (u16)(it[0x20] == 3 ? ext_52e320(it, DIRS + dir * 3) : ext_531070(it, DIRS + dir * 3));
  if (!id) return 0;
  if (!*(u16 *)(it + 0x16)) return 0;
  u8 *S1 = sizeRec(self, level, *(u16 *)(it + 0x16));
  u16 pos[3] = {*(u16 *)(it + 0x18), *(u16 *)(it + 0x1a), *(u16 *)(it + 0x1c)};
  u16 idx = (u16)ext_530a40(it);
  if (!idx) return 0xffff;
  float w = 1.0f;
  u8 flag = 1;
  int a = S1[0], b = S0[0], cnt;
  switch (dir) {
    case 0: cnt = S0[1] * b; break;
    case 1: cnt = S1[1] * a; flag = 0; break;
    case 2: cnt = 0; break;
    case 3: cnt = 0; flag = 0; break;
    case 4: cnt = (S0[1] + S0[2]) * b; w = 0.125f; break;
    case 5: cnt = (S1[2] + S1[1]) * a; w = 0.125f; flag = 0; break;
    default:
      pfBreak();
      cnt = b;
      break;
  }
  return ext_531e70(self, (u16 *)(it + 0x16), from, x, dir, w, pos, idx, S1, S0, rec, b, a,
                    ((u32)S1 & 0xffffff00u) | flag, cnt);
}
PCREG(531c40, floodCoarse);

// 0x5320b0 ZPFOctree_packed::VisitNeighborSpecialFloodFillCoarse(unsigned short from, int level,
// ZPFOctreeIterator_packed*, const unsigned short* goal) [map high; GC 8019a9b4]. thiscall, ret 0x10, AX = 1 or
// 0xffff (A* full). Coarse version of the link step: the link refs of the current node's cell whose component byte
// (+0) is the current sub-slot; the far end is reached by moving a copy of the iterator by the ref's node delta (+2/+4
// /+6, in nodes of this level); slot = A* slot + ref +1 - 1; cost as in Split; action check by the link number at +8.
// The stored cell is rounded down to the leaf corner in x/z (& 0xfff8).
static u32 THISCALL floodSpecialCoarse(u8 *self, u32 from32, int level, u8 *it, const u16 *x) {
  u16 from = (u16)from32;
  u8 *rec = ASTAR(self, from);
  u16 id0 = *(u16 *)rec;
  u16 cell = level == *(int *)(self + 0x38) - 1 ? *(u16 *)(*(u8 **)(self + 0x5a) + id0 * 12)
                                                 : *(u16 *)(*(u8 **)(self + 0x54) + id0 * 0x16);
  u16 first = *(u16 *)(*(u8 **)(self + 0x78) + cell * 10 + 8);
  u8 cnt = (*(u8 **)(self + 0x7c))[cell];
  if (!cnt) return 1;
  u32 off = (u32)first * 10;
  for (int i = 0; i < (int)cnt; i++, off += 10) {
    u8 *ref = *(u8 **)(self + 0x66) + off;
    if (ref[0] != rec[3]) continue;
    u32 L = (u32)*(int *)(self + 0x38) - (u32)level;
    u32 sxz = 1, sy = 1;
    if (L) {
      sxz = 8u << ((L - 1) & 0x1f);
      sy = 1u << ((L - 1) & 0x1f);
    }
    s16 d[3] = {*(s16 *)(ref + 2), *(s16 *)(ref + 4), *(s16 *)(ref + 6)};
    u16 nx = (u16)(*(u16 *)(rec + 4) + (u16)(sxz * (u16)d[0]));
    u16 nz = (u16)(*(u16 *)(rec + 6) + (u16)(sxz * (u16)d[1]));
    u16 ny = (u16)(*(u16 *)(rec + 8) + (u16)(sy * (u16)d[2]));
    u32 slotoff = ref[1];
    u8 W[0x2d];
    __builtin_memcpy(W, it, 0x2d);
    u16 id = (u16)(W[0x20] == 3 ? ext_52e320(W, d) : ext_531070(W, d));
    if (!id) continue;
    u16 idx = (u16)((u16)ext_530a40(W) + (u16)(slotoff - 1));
    if (!idx) return 0xffff;
    u8 *n = ASTAR(self, idx);
    float hx = 1.0f, h0 = 0.0f, h1 = 0.0f;
    if (USE_HEURISTIC && x) {
      u16 rp[3] = {*(u16 *)(rec + 4), *(u16 *)(rec + 6), *(u16 *)(rec + 8)};
      u16 np[3] = {nx, nz, ny};
      h0 = ext_532850(x, np);
      h1 = ext_532850(x, rp);
      hx = ext_532850(rp, np);
    }
    float f = *(float *)(rec + 0xa) + hx;
    f = f + h0;
    f = f - h1;
    f = f + 0.0001f;
    if (!(*(float *)(n + 0xa) > f + 0.1f)) continue;
    s16 ln = *(s16 *)(ref + 8);
    u32 k = (u16)ln, nearEnd = 0;
    if (ln < 0) {
      k = (u16)-ln;
      nearEnd = 1;
    }
    if (self[4] && !(u8)ext_532730(self, (*(u16 **)(self + 0x8c))[nearEnd + k * 2])) continue;
    n[0x14] &= 0xfe;
    *(float *)(n + 0xa) = f;
    *(u16 *)(n + 0xe) = from;
    *(u16 *)(n + 4) = nx & 0xfff8;
    *(u16 *)(n + 8) = ny;
    *(u16 *)(n + 6) = nz & 0xfff8;
    n[3] = (u8)slotoff;
    *(u16 *)n = id;
    ext_52d250(self, from, idx);
  }
  return 1;
}
PCREG(5320b0, floodSpecialCoarse);
