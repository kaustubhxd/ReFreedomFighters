// batch1208.cpp - pathfinding tree: the generic octree walk with visitor functors (no GC names: inlined there as
// template code; names here are descriptive), and its first users.
//
// SPFFuncs (the walk's visitor set, on the caller's stack): +0 box check functor (vtable slot 0: bool (octree, u16
// id, int* lo, int* hi), e.g. ZPFOctreeNodeCheckBox_packed::isOK), +4 node functor (int (octree, u16& id, int* lo,
// int* hi, int depth)), +8 leaf functor (same), +0xc element functor (int (octree, int& value, int slot, int* lo,
// int* hi, int depth, u16 leafId)), +0x10 bool stop at the first hit. Any functor may be NULL.
// Boxes are [lo, hi) in cells (x, z, y), ints.
#include "pf.h"

struct SPFFuncs {
  void *check, *node, *leaf, *elem;
  u8 stop;
} __attribute__((packed));

typedef u32(THISCALL *CheckFn)(void *, void *, u32, int *, int *);
typedef int(THISCALL *NodeFn)(void *, void *, u16 *, int *, int *, int);
typedef int(THISCALL *ElemFn)(void *, void *, int *, int, int *, int *, int, u32);
#define SLOT0(f) (**(void ***)(f))

// 0x52d580 leaf walk: the 8 x 8 elements of the leaf `*node` (x = lo0 + col, z = lo1 + row, one y layer).
// thiscall (octree), ret 0x24: (funcs, u16* node, int depth, lo0, lo1, lo2, hi0, hi1, hi2); hi is not read.
// Per element: box check (skip on false), element value from the leaf bit planes (0 when the area has no leaf
// block), A* slot = area +0xa + index, element functor (sum of results). With `stop`, returns after the first
// element that passed the check, functor or not.
static int THISCALL traverseLeaf(u8 *oct, SPFFuncs *f, u16 *node, int depth, int lo0, int lo1, int lo2, int, int,
                                 int) {
  u8 *area = *(u8 **)(oct + 0x5a) + *node * 12;
  int total = 0;
  u32 *bits = (u32 *)(*(u8 **)(oct + 0x72) + (u32)*(u16 *)(oct + 0x2a) * *(u16 *)(area + 6) * 4);
  int z = lo1;
  for (int row = 0; row < 64; row += 8) {
    for (int col = 0; col < 8; col++) {
      int lo[3], hi[3];
      lo[0] = (int)((u32)lo0 + (u32)col);
      hi[0] = (int)((u32)lo[0] + 1u);
      lo[1] = z;
      hi[1] = (int)((u32)z + 1u);
      lo[2] = lo2;
      hi[2] = (int)((u32)lo2 + 1u);
      if (f->check && !(u8)((CheckFn)SLOT0(f->check))(f->check, oct, *node, lo, hi)) continue;
      int idx = row + col;
      int v = 0;
      if (*(u16 *)(area + 6)) {
        int bpe = *(int *)(oct + 0x48);
        u32 pos = (u32)bpe * 64u - 64u + (u32)idx;
        int sh = pos & 0x1f;
        u32 *w = (u32 *)((u8 *)bits + ((int)pos >> 5) * 4);
        for (int k = bpe - 1; k >= 0; k--) {
          v = (int)((u32)v * 2u) | (((int)*w >> sh) & 1);
          w -= 2;
        }
      }
      int slot = *(u16 *)(area + 0xa) + idx;
      if (f->elem) total += ((ElemFn)SLOT0(f->elem))(f->elem, oct, &v, slot, lo, hi, depth - 1, *node);
      if (f->stop) return total;
    }
    z = (int)((u32)lo1 + 1u);
    lo1 = z;
  }
  return total;
}
PCREG(52d580, traverseLeaf);

extern "C" int THISCALL ext_52d750(void *oct, SPFFuncs *f, u16 *node, int depth, int, int, int, int, int, int);

// 0x52d750 octree walk: thiscall (octree), ret 0x24: (funcs, u16* node, int depth, lo0, lo1, lo2, hi0, hi1, hi2).
// Box check, then on depth > 0 the node functor and the 8 children (child k: bit 0 = upper half in x, bit 1 = z,
// bit 2 = y; the middle is (lo + hi) / 2 truncated to 16 bits), each walked through a local copy of the child id that
// is written back into the node afterwards (so functors can relink). Depth 0: leaf functor, then the leaf walk
// (whose result replaces the leaf functor's). Results add up; `stop` returns at the first non-zero sum.
static int THISCALL traverse(u8 *oct, SPFFuncs *f, u16 *node, int depth, int a0, int a1, int a2, int b0, int b1,
                             int b2) {
  int lo[3] = {a0, a1, a2}, hi[3] = {b0, b1, b2};
  if (f->check && !(u8)((CheckFn)SLOT0(f->check))(f->check, oct, *node, lo, hi)) return 0;
  int r = 0;
  if (!depth) {
    if (f->leaf) r = ((NodeFn)SLOT0(f->leaf))(f->leaf, oct, node, lo, hi, 0);
    if (!*node) return r;
    if (f->stop && r) return r;
    return traverseLeaf(oct, f, node, 0, a0, a1, a2, b0, b1, b2);
  }
  if (f->node) r = ((NodeFn)SLOT0(f->node))(f->node, oct, node, lo, hi, depth);
  if (!*node) return r;
  if (f->stop && r) return r;
  depth--;
  u32 m0 = (u16)((int)((u32)a0 + (u32)b0) / 2);   // wrapping sum, signed halving (cdq/sub/sar)
  u32 m1 = (u16)((int)((u32)a1 + (u32)b1) / 2);
  u32 m2 = (u16)((int)((u32)a2 + (u32)b2) / 2);
  for (int k = 0; k < 8; k++) {
    u32 c = *(u16 *)(*(u8 **)(oct + 0x54) + *node * 0x16 + 6 + 2 * k);
    int l0 = k & 1 ? (int)m0 : a0, h0 = k & 1 ? b0 : (int)m0;
    int l1 = k & 2 ? (int)m1 : a1, h1 = k & 2 ? b1 : (int)m1;
    int l2 = k & 4 ? (int)m2 : a2, h2 = k & 4 ? b2 : (int)m2;
    r += ext_52d750(oct, f, (u16 *)&c, depth, l0, l1, l2, h0, h1, h2);
    *(u16 *)(*(u8 **)(oct + 0x54) + *node * 0x16 + 6 + 2 * k) = (u16)c;
    if (f->stop && r) return r;
  }
  return r;
}
PCREG(52d750, traverse);
