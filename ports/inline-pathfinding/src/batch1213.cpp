// batch1213.cpp - pathfinding tree: component lookup and the coarse A* (FindPathCoarse).
//
// More ZPFOctree_packed fields: +0x6c component bit planes of the leaves (u32 words; area record +8 = first word),
// +0x82 u8 component remap tables (size-table record +4 = offset): the component of a cell one level up is
// table[offset + component - 1]. Globals: 0x701b5c (byte) mark neighbours on the leaf level too, 0x701b5d (byte)
// report "Couldn't get component info".
#include "pf.h"

extern "C" int THISCALL ext_530890(void *self, const u32 *base, int idx, int nbits);
extern "C" u32 THISCALL ext_531740(void *it, const u16 *pos, int level);
extern "C" u32 THISCALL ext_531810(void *it, const u16 *cell);
extern "C" u32 THISCALL ext_530940(void *oct, const u16 *cell, int level);
extern "C" u32 THISCALL ext_530a40(void *it);
extern "C" float FASTCALL ext_532850(const u16 *a, const u16 *b);
extern "C" u32 THISCALL ext_532770(void *oct, u16 *path, u32 idx, int level);
extern "C" u32 THISCALL ext_531c40(void *oct, u32 from, int level, void *it, u32 dir, const u16 *x);
extern "C" u32 THISCALL ext_5320b0(void *oct, u32 from, int level, void *it, const u16 *x);
extern "C" u32 THISCALL ext_52e320(void *it, const s16 *d);
extern "C" u32 THISCALL ext_531070(void *it, const s16 *d);

// 0x530890 (no GC name) value of `nbits` bit planes (64 bits apart, highest first) at bit `idx`. thiscall (unused
// this), ret 0xc.
static int THISCALL planeBits(void *, const u32 *base, int idx, int nbits) {
  int v = 0;
  for (int k = nbits - 1; k >= 0; k--) {
    int pos = (int)((u32)k * 64u + (u32)idx);
    v = (base[pos >> 5] & (1u << (pos & 31))) ? (int)((u32)v * 2u) | 1 : (int)((u32)v * 2u);
  }
  return v;
}
PCREG(530890, planeBits);

// 0x531810 (no GC name) ZPFOctreeIterator_packed: component (1-based, 0 = blocked or none) of an element cell: the
// area record of the cell's leaf, then as many bit planes as the area's slot count needs (bit length of size +0).
static u32 THISCALL iterElementComponent(u8 *it, const u16 *cell) {
  if (!(u16)ext_531740(it, cell, *(int *)(*(u8 **)it + 0x38) - 1)) return 0;
  u16 id = *(u16 *)(it + 0x16);
  if (!id) return 0;
  u8 *oct = *(u8 **)it;
  u8 *area = *(u8 **)(oct + 0x5a) + id * 12;
  int n = (*(u8 **)(oct + 0x78))[*(u16 *)area * 10];
  int bits = 0;
  while (n) {
    bits++;
    n >>= 1;
  }
  u16 idx = (u16)(((cell[1] & 7) << 3) + (cell[0] & 7));
  return ext_530890(oct, (u32 *)(*(u8 **)(oct + 0x6c) + *(u16 *)(area + 8) * 4), idx, bits);
}
PCREG(531810, iterElementComponent);

// 0x530940 (no GC name) component of a cell on `level`: the element component, then mapped up level by level through
// the remap tables at +0x82 (area level first, then node levels). thiscall (octree), ret 8, u16 (zero-extended).
static u32 THISCALL cellComponent(u8 *self, const u16 *cell, int level) {
  u8 it[0x30];
  if (self) {
    *(u8 **)it = self;
    *(u16 **)(it + 4) = (u16 *)(self + 0x96);
    *(u32 *)(it + 8) = 0x40;
  }
  u32 c = (u16)ext_531810(it, cell);
  int levels = *(int *)(self + 0x38);
  int up = levels - level;
  if (up >= 2) {
    ext_531740(it, cell, levels - 1);
    u16 cellIdx = *(u16 *)(*(u8 **)(self + 0x5a) + *(u16 *)(it + 0x16) * 12);
    u32 off = *(u16 *)(*(u8 **)(self + 0x78) + cellIdx * 10 + 4);
    c = (*(u8 **)(self + 0x82))[off + c - 1];
  }
  for (int j = 2; j < up; j++) {
    ext_531740(it, cell, *(int *)(self + 0x38) - j);
    u16 cellIdx = *(u16 *)(*(u8 **)(self + 0x54) + *(u16 *)(it + 0x16) * 0x16);
    u32 off = *(u16 *)(*(u8 **)(self + 0x78) + cellIdx * 10 + 4);
    c = (*(u8 **)(self + 0x82))[off + (u16)c - 1];
  }
  return (u16)c;
}
PCREG(530940, cellComponent);

#define ASTAR(o, i) (*(u8 **)((o) + 0x98) + (u32)(u16)(i) * 0x15)

// 0x530130 ZPFOctree_packed::FindPathCoarse(unsigned short* from, unsigned short* to, float maxF, int level, int mode,
// CHelpers*) [map high; GameCube reference; source zpfoctreepacked.cpp line 0x4ed]. thiscall, ret 0x18, AX: 1 found,
// 0 not found / no component, 0xffff A* full or f above maxF (maxF 0 = no limit).
// A* over the nodes of `level` (cells rounded down to the level's node size, heuristic = Manhattan cells), each node
// split into components. Expansion order: x+, x-, z+, z-, y+, y- (directions 2, 3, 0, 1, 4, 5), then special links.
// mode 2 expands only nodes inside the coarser path (isInCoarserPath). With mode 1 or 2 the found path is walked
// back and every node on it (and, except on the leaf level unless 0x701b5c is set, its 26 neighbours) gets the marker
// 0xffff in its +2 word: that is the corridor the next, finer search keeps to.
static u32 THISCALL findPathCoarse(u8 *self, u16 *from, u16 *to, float maxF, int level, int mode, void *) {
  u8 it[0x30];
  if (self) {
    *(u8 **)it = self;
    *(u16 **)(it + 4) = (u16 *)(self + 0x96);
    *(u32 *)(it + 8) = 0x40;
  }
  u32 result = 0;
  u16 A[3] = {from[0], from[1], from[2]};
  u16 B[3] = {to[0], to[1], to[2]};
  u32 compA = ext_530940(self, A, level);
  u32 compB = ext_530940(self, B, level);
  int L = *(int *)(self + 0x38) - level;
  int sx = 1, sz = 1, sy = 1;
  if (L) {
    sx = sz = 8 << ((L - 1) & 0x1f);
    sy = 1 << ((L - 1) & 0x1f);
  }
  A[0] = (u16)((int)A[0] / sx * sx);
  A[1] = (u16)((int)A[1] / sz * sz);
  A[2] = (u16)((int)A[2] / sy * sy);
  B[0] = (u16)((int)B[0] / sx * sx);
  B[1] = (u16)((int)B[1] / sz * sz);
  B[2] = (u16)((int)B[2] / sy * sy);
  u16 bx = B[0], bz = B[1], by = B[2];
  if (!compA || !compB) {
    if (G(u8, 0x701b5d)) pfReport((const char *)0x6a1438, 0x4ed, (const char *)0x6a14a4);
    return 0;
  }
  ext_531740(it, A, level);
  u16 idx = (u16)((u16)ext_530a40(it) + (u16)(compA - 1));
  if (!idx) return 0xffff;
  u8 *cur = ASTAR(self, idx);
  *(u32 *)(cur + 0xa) = 0;
  float h = ext_532850(from, to);
  *(u32 *)(cur + 0x10) = 0;
  *(float *)(cur + 0xa) = h;
  *(u16 *)(cur + 4) = *(u16 *)(it + 0xc);
  *(u16 *)(cur + 6) = *(u16 *)(it + 0xe);
  *(u16 *)(cur + 8) = *(u16 *)(it + 0x10);
  *(u16 *)cur = *(u16 *)(it + 0x16);
  cur[3] = (u8)compA;
  static const u8 order[6] = {2, 3, 0, 1, 4, 5};
  for (;;) {
    if (maxF != 0.0f && *(float *)(cur + 0xa) > maxF) {
      result = 0xffff;
      break;
    }
    if (*(u16 *)(cur + 4) == bx && *(u16 *)(cur + 6) == bz && *(u16 *)(cur + 8) == by && cur[3] == compB) {
      result = 1;
      break;
    }
    if (mode != 2 || (u8)ext_532770(self, (u16 *)(cur + 4), *(u16 *)cur, level)) {
      for (int k = 0; k < 7; k++) {
        *(u16 *)(it + 0x18) = *(u16 *)(cur + 4);
        *(u16 *)(it + 0xc) = *(u16 *)(cur + 4);
        *(u16 *)(it + 0x1a) = *(u16 *)(cur + 6);
        *(u16 *)(it + 0xe) = *(u16 *)(cur + 6);
        *(u16 *)(it + 0x1c) = *(u16 *)(cur + 8);
        *(u16 *)(it + 0x10) = *(u16 *)(cur + 8);
        *(u16 *)(it + 0x16) = *(u16 *)cur;
        u16 r = (u16)(k < 6 ? ext_531c40(self, idx, level, it, order[k], B)
                            : ext_5320b0(self, idx, level, it, B));
        if (r == 0xffff) return 0xffff;
      }
      bx = B[0];
      bz = B[1];
      by = B[2];
    }
    u16 nxt = *(u16 *)(cur + 0x10);
    *(u16 *)(cur + 0x10) = 0;
    idx = nxt;
    cur = ASTAR(self, nxt);
    *(u16 *)(cur + 0x12) = 0;
    if (!nxt) break;
  }
  if ((mode == 1 || mode == 2) && idx) {
    u16 n = idx;
    do {
      cur = ASTAR(self, n);
      u16 back = *(u16 *)(cur + 0xe);
      if (cur[0x14] & 1) back = *(u16 *)(self + 0x9e + back * 32);
      int top = *(int *)(self + 0x38) - 1;
      if (!G(u8, 0x701b5c) && level == top) {
        *(u16 *)(*(u8 **)(self + 0x5a) + *(u16 *)cur * 12 + 2) = 0xffff;
      } else {
        s16 d[3];
        for (d[2] = -1; d[2] < 2; d[2]++)
          for (d[1] = -1; d[1] < 2; d[1]++)
            for (d[0] = -1; d[0] < 2; d[0]++) {
              *(u16 *)(it + 0x18) = *(u16 *)(cur + 4);
              *(u16 *)(it + 0xc) = *(u16 *)(cur + 4);
              *(u16 *)(it + 0x1a) = *(u16 *)(cur + 6);
              *(u16 *)(it + 0xe) = *(u16 *)(cur + 6);
              *(u16 *)(it + 0x1c) = *(u16 *)(cur + 8);
              *(u16 *)(it + 0x10) = *(u16 *)(cur + 8);
              *(u16 *)(it + 0x16) = *(u16 *)cur;
              u16 id = (u16)(it[0x20] == 3 ? ext_52e320(it, d) : ext_531070(it, d));
              if (!id) continue;
              if (level == top) *(u16 *)(*(u8 **)(self + 0x5a) + id * 12 + 2) = 0xffff;
              else *(u16 *)(*(u8 **)(self + 0x54) + id * 0x16 + 2) = 0xffff;
            }
      }
      n = back;
    } while (n);
  }
  return result;
}
PCREG(530130, findPathCoarse);
