// batch1202.cpp - pathfinding tree: the A* open list and the GetAreaInfo octree visitors.
#include "pf.h"

// SPFAStarData_packed (PC, /Zp1, 0x15 bytes; array at ZPFOctree_packed+0x98, index 0 unused):
//   +0x0a float  f (cost so far + estimate), the sort key of the open list
//   +0x10 u16    prev (towards the cheaper end; 0 = none)
//   +0x12 u16    next (0 = not linked behind anything)
#define AS(base, i) ((base) + (u32)(i) * 0x15)
#define AS_F(p) (*(float *)((p) + 0xa))
#define AS_PREV(p) (*(u16 *)((p) + 0x10))
#define AS_NEXT(p) (*(u16 *)((p) + 0x12))

// 0x52d250 ZPFOctree_packed::AddToPrioQueue(unsigned short head, unsigned short node) [map high; GameCube reference].
// thiscall, ret 8. Sorted doubly linked open list.
//  - node already linked (next != 0): unlink it, then walk forward from its old next and insert it in front of the
//    first entry whose f is <= node.f (a decrease-key moves it towards the head that way only when f fell).
//  - otherwise walk backwards (prev links) from `head` while the previous entry's f is lower than node.f, and insert
//    the node there.
static void THISCALL addToPrioQueue(u8 *self, u32 head32, u32 node32) {
  u16 node = (u16)node32;
  u8 *base = *(u8 **)(self + 0x98);
  u8 *n = AS(base, node);
  u16 nx = AS_NEXT(n);
  if (nx) {
    AS_PREV(AS(base, nx)) = AS_PREV(n);
    u16 pv = AS_PREV(n);
    if (pv) AS_NEXT(AS(*(u8 **)(self + 0x98), pv)) = AS_NEXT(n);
    u16 c = AS_NEXT(n);
    if (!c) return;
    u8 *b2 = *(u8 **)(self + 0x98);
    float f = AS_F(n);
    u8 *e;
    for (;;) {
      e = AS(b2, c);
      if (f >= AS_F(e)) break;
      c = AS_NEXT(e);
      if (!c) return;
    }
    AS_NEXT(n) = c;
    AS_PREV(n) = AS_PREV(e);
    u8 *b3 = *(u8 **)(self + 0x98);
    AS_NEXT(AS(b3, AS_PREV(e))) = (u16)node32;
    AS_PREV(e) = (u16)node32;
    return;
  }
  u16 cur = (u16)head32;
  u8 *c = AS(base, cur);
  u8 *e = 0;
  if (AS_PREV(c)) {
    float f = AS_F(n);
    for (;;) {
      u16 p = AS_PREV(c);
      e = AS(base, p);
      if (AS_F(e) >= f) break;
      cur = p;
      c = AS(base, cur);
      if (!AS_PREV(c)) break;
    }
  }
  AS_NEXT(n) = cur;
  AS_PREV(n) = AS_PREV(c);
  if (AS_PREV(c)) AS_NEXT(e) = (u16)node32;
  AS_PREV(c) = (u16)node32;
}
PCREG(52d250, addToPrioQueue);

// SPFAreaInfo_packed, filled by the GetAreaInfo visitors (functor +4 = record, +8 = wanted level):
//   +0 u16 id, +2/+4/+6 u16 the low words of the node's lo corner (x, z, y), +9 u8 level, +0xa u8 kind
//   (1 = node, 2 = leaf, 3 = element).
// The level of a node at tree depth d is octree+0x38 (levels) - d - 1; the visitor fires on the wanted level only.
static inline void fillArea(u8 *self, u8 kind, u16 id, s32 level, int *lo) {
  (*(u8 **)(self + 4))[0xa] = kind;
  *(u16 *)*(u8 **)(self + 4) = id;
  (*(u8 **)(self + 4))[9] = (u8)level;
  *(u16 *)(*(u8 **)(self + 4) + 2) = (u16)lo[0];
  *(u16 *)(*(u8 **)(self + 4) + 4) = (u16)lo[1];
  *(u16 *)(*(u8 **)(self + 4) + 6) = (u16)lo[2];
}

// 0x52d380 ZPFOctreeElementFuncGetAreaInfo_packed::Apply(ZPFOctree_packed*, int&, int, int*, int*, int, unsigned short)
// [map medium; GameCube reference, vtable slot 0]. thiscall, ret 0x1c. Only for a non-zero element.
static int THISCALL elemGetAreaInfo(u8 *self, u8 *oct, int *elem, int, int *lo, int *, int depth, u32 id) {
  s32 level = (s32)(*(u32 *)(oct + 0x38) - (u32)depth - 1u);
  if (level != *(s32 *)(self + 8) || *elem == 0) return 0;
  fillArea(self, 3, (u16)id, level, lo);
  return 1;
}
PCREG(52d380, elemGetAreaInfo);

// 0x52d4a0 ZPFOctreeLeafFuncGetAreaInfo_packed::Apply(ZPFOctree_packed*, unsigned short&, int*, int*, int)
// [map medium; GameCube reference]. thiscall, ret 0x14.
static int THISCALL leafGetAreaInfo(u8 *self, u8 *oct, u16 *id, int *lo, int *, int depth) {
  s32 level = (s32)(*(u32 *)(oct + 0x38) - (u32)depth - 1u);
  if (level != *(s32 *)(self + 8)) return 0;
  fillArea(self, 2, *id, level, lo);
  return 1;
}
PCREG(52d4a0, leafGetAreaInfo);

// 0x52d510 ZPFOctreeNodeFuncGetAreaInfo_packed::Apply(...) [map medium; GameCube reference]. Same as the leaf one, kind 1.
static int THISCALL nodeGetAreaInfo(u8 *self, u8 *oct, u16 *id, int *lo, int *, int depth) {
  s32 level = (s32)(*(u32 *)(oct + 0x38) - (u32)depth - 1u);
  if (level != *(s32 *)(self + 8)) return 0;
  fillArea(self, 1, *id, level, lo);
  return 1;
}
PCREG(52d510, nodeGetAreaInfo);
