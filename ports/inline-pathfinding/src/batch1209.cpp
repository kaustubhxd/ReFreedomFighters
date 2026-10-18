// batch1209.cpp - pathfinding tree: users of the octree walk (find the node at a cell, nearest walkable cell,
// CheckPosition), the iterator's SetPosition, and the special-link step of the fine A* (VisitNeighborSpecialThin).
#include "pf.h"

struct SPFFuncs {
  void *check, *node, *leaf, *elem;
  u8 stop;
} __attribute__((packed));
struct BoxFunctor {      // ZPFOctreeNodeCheckBox_packed (vtable 0x6a140c)
  u32 vt;
  int lo[3], hi[3];
};
struct AreaFunctor {     // ZPFOctree{Node,Leaf,Element}FuncGetAreaInfo_packed (vtables 0x6a141c / 0x6a1424 / 0x6a142c)
  u32 vt;
  void *out;
  int level;
};
struct NearestFunctor {  // ZPFOctreeElementFuncGetNearest_packed (vtable 0x6a1434)
  u32 vt;
  int target[3], best[3];
  float bestDist, weight;
};

extern "C" int THISCALL ext_52d750(void *oct, SPFFuncs *f, u16 *node, int depth, int, int, int, int, int, int);
extern "C" int THISCALL ext_5307c0(void *oct, void *out, const u16 *pos, int level);
extern "C" int THISCALL ext_530e80(void *oct, u16 *out, const u16 *pos, u32 ry, u32 rxz, float weight);
extern "C" u32 THISCALL ext_531740(void *it, const u16 *pos, int level);
extern "C" u32 THISCALL ext_530a40(void *it);
extern "C" u32 THISCALL ext_532730(void *oct, u32 action);
extern "C" void THISCALL ext_52d250(void *oct, u32 head, u32 node);

#define ROOT ((u16 *)0x6e9034)   // the root node id (a global u16, 1)
#define LEVELS(o) (*(int *)((o) + 0x38))
#define CELLS(o, k) (*(int *)((o) + 0x3c + 4 * (k)))   // x, z, y

// 0x5307c0 (no GC name) find the area/node record at a cell: walks the whole octree with a one-cell box and the three
// GetAreaInfo functors for `level`, stopping at the first hit; the hit fills `out` (SPFAreaInfo_packed). thiscall
// (octree), ret 0xc, returns the walk's result (non-zero = found).
static int THISCALL findAreaAt(u8 *oct, void *out, const u16 *pos, int level) {
  BoxFunctor box;
  AreaFunctor nodeF, leafF, elemF;
  SPFFuncs f;
  box.vt = 0x6a140c;
  box.lo[0] = pos[0];
  box.lo[1] = pos[1];
  box.lo[2] = pos[2];
  box.hi[0] = pos[0] + 1;
  box.hi[1] = pos[1] + 1;
  box.hi[2] = pos[2] + 1;
  nodeF.vt = 0x6a141c;
  leafF.vt = 0x6a1424;
  elemF.vt = 0x6a142c;
  nodeF.out = leafF.out = elemF.out = out;
  nodeF.level = leafF.level = elemF.level = level;
  f.check = &box;
  f.node = &nodeF;
  f.leaf = &leafF;
  f.elem = &elemF;
  f.stop = 1;
  return ext_52d750(oct, &f, ROOT, LEVELS(oct) - 1, 0, 0, 0, CELLS(oct, 0), CELLS(oct, 1), CELLS(oct, 2));
}
PCREG(5307c0, findAreaAt);

// 0x531740 (no GC name) ZPFOctreeIterator_packed: set position and level. thiscall, ret 8, u16 (AX) = the id found
// (0 = none). Keeps the cell at +0xc; on a level change sets the per-axis steps (8 << (L - 1) in x/z, 1 << (L - 1) in
// y, L = levels - level; 1 at the leaf level). Then copies the found record: +0x16 id and position, +0x1e the word at
// record +8 (byte 8 is never written by the functors: whatever the caller's stack held), +0x20 kind.
static u32 THISCALL iterSetPosition(u8 *it, const u16 *pos, int level) {
  *(u16 *)(it + 0xc) = pos[0];
  *(u16 *)(it + 0xe) = pos[1];
  *(u16 *)(it + 0x10) = pos[2];
  if (*(int *)(it + 0x12) != level) {
    *(int *)(it + 0x12) = level;
    u32 L = (u32)LEVELS(*(u8 **)it) - (u32)level;
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
  }
  u8 rec[12];
  if (!ext_5307c0(*(u8 **)it, rec, pos, *(int *)(it + 0x12))) return 0;
  __builtin_memcpy(it + 0x16, rec, 8);
  *(u16 *)(it + 0x1e) = *(u16 *)(rec + 8);
  it[0x20] = rec[0xa];
  return *(u16 *)(it + 0x16);
}
PCREG(531740, iterSetPosition);

// 0x530e80 (no GC name) nearest walkable cell to `pos` in the box x, z +- rxz, y - ry .. y (upper bound exclusive:
// the search looks below). Element functor GetNearest (weight on y), starting distance 1e6. thiscall (octree),
// ret 0x14, returns 1 when a cell was found (best distance <= 999999); `out` always gets the best cell (0 if none).
static int THISCALL findNearestCell(u8 *oct, u16 *out, const u16 *pos, u32 ry32, u32 rxz32, float weight) {
  int ry = (s16)ry32, r = (s16)rxz32;
  int x = pos[0], z = pos[1], y = pos[2];
  BoxFunctor box;
  NearestFunctor nf;
  SPFFuncs f;
  box.vt = 0x6a140c;
  box.lo[0] = x - r;
  box.lo[1] = z - r;
  box.lo[2] = y - ry;
  box.hi[0] = x + r;
  box.hi[1] = z + r;
  box.hi[2] = y;
  nf.vt = 0x6a1434;
  nf.target[0] = x;
  nf.target[1] = z;
  nf.target[2] = y;
  nf.best[0] = nf.best[1] = nf.best[2] = 0;
  nf.bestDist = 1000000.0f;   // 0x49742400
  nf.weight = weight;
  f.check = &box;
  f.node = 0;
  f.leaf = 0;
  f.elem = &nf;
  f.stop = 0;
  ext_52d750(oct, &f, ROOT, LEVELS(oct) - 1, 0, 0, 0, CELLS(oct, 0), CELLS(oct, 1), CELLS(oct, 2));
  out[0] = (u16)nf.best[0];
  out[1] = (u16)nf.best[1];
  out[2] = (u16)nf.best[2];
  return 999999.0f >= nf.bestDist;   // 0x6a1588
}
PCREG(530e80, findNearestCell);

// 0x52e240 ZPFOctree_packed::CheckPosition(float*) [map low; GC 8019bfe4]. thiscall, ret 4, bool: is there a walkable
// cell within one cell in x/z and up to 10 cells below the point raised by 30 units? (A NULL `this` makes the exe use
// an uninitialised local instead; not reproduced.)
static bool THISCALL octCheckPosition(u8 *oct, float *p) {
  float px = p[0], py = p[1] + 30.0f, pz = p[2];   // 30.0 at 0x67da24
  float *mn = (float *)(oct + 6), *mx = (float *)(oct + 0x12);
  float ex = mx[0] - mn[0], ey = mx[1] - mn[1], ez = mx[2] - mn[2];
  float lx = (px - mn[0]) / ex * (float)CELLS(oct, 0);
  float ly = (py - mn[1]) / ey * (float)CELLS(oct, 2);
  float lz = (pz - mn[2]) / ez * (float)CELLS(oct, 1);
  u16 c[3], out[4];
  c[0] = (u16)_mm_cvtt_ss2si(_mm_set_ss(lx));
  c[1] = (u16)_mm_cvtt_ss2si(_mm_set_ss(lz));
  c[2] = (u16)_mm_cvtt_ss2si(_mm_set_ss(ly));
  return ext_530e80(oct, out, c, 10, 1, 1.0f) != 0;
}
PCREG(52e240, octCheckPosition);

// 0x532420 ZPFOctree_packed::VisitNeighborSpecialThin(unsigned short from, const unsigned short*) [map high; GC
// 8019b098]. thiscall, ret 8; returns 1, or 0xffff when the A* array is full.
// Octree fields: +4 / +5 bools "links have actions" / "links have world points", +0x66 link refs (10 bytes: +1 u8
// slot offset, +8 s16 signed link number, + = walked forwards), +0x78 size table (10 bytes: +8 u16 first link ref),
// +0x7c u8 link-ref count per area cell, +0x88 links (12 bytes: start cell, end cell, u16 x/z/y), +0x8c actions
// (2 u16 per link: forwards, backwards), +0x90 world points (24 bytes: start, end), +0x96 u16 next free A* slot,
// +0x9c u16 count of SExtraLinkParentInfo_packed records at +0x9e (32 bytes: +0 from, +2 action, +4 far point,
// +0x10 near point, +0x1c link number).
// For each link ref of the current element's area cell whose near end is exactly the A* element's cell: find the far
// end's record (iterator at the leaf level, 0x40 slots per leaf), take its A* slot (+ the ref's slot offset - 1),
// relax it with cost +1 (+ 0.0 + 0.0001), record the link use, check the action, and queue it.
static u32 THISCALL visitNeighborSpecialThin(u8 *self, u32 from32, const u16 *) {
  u8 *rec = *(u8 **)(self + 0x98) + (u16)from32 * 0x15;
  u16 cell = *(u16 *)(*(u8 **)(self + 0x5a) + *(u16 *)rec * 12);
  u8 cnt = (*(u8 **)(self + 0x7c))[cell];
  u32 first = *(u16 *)(*(u8 **)(self + 0x78) + cell * 10 + 8);
  if (!cnt) return 1;
  u32 off = first * 10;
  for (int i = 0; i < cnt; i++, off += 10) {
    u8 *ref = *(u8 **)(self + 0x66) + off;
    s16 ln = *(s16 *)(ref + 8);
    if (!ln) continue;
    int nearEnd = 0, farEnd = 1;
    u32 k = (u16)ln;
    if (ln < 0) {
      k = (u16)-ln;
      nearEnd = 1;
      farEnd = 0;
    }
    u16 *L = (u16 *)(*(u8 **)(self + 0x88) + k * 12);
    if (*(u16 *)(rec + 4) != L[nearEnd * 3] || *(u16 *)(rec + 6) != L[nearEnd * 3 + 1] ||
        *(u16 *)(rec + 8) != L[nearEnd * 3 + 2])
      continue;
    u8 it[0x30];
    *(u8 **)it = self;
    *(u16 **)(it + 4) = (u16 *)(self + 0x96);
    *(u32 *)(it + 8) = 0x40;
    u16 far[3] = {L[farEnd * 3], L[farEnd * 3 + 1], L[farEnd * 3 + 2]};
    u16 id = (u16)ext_531740(it, far, LEVELS(self));
    if (!id) continue;
    u16 idx = (u16)((u16)ext_530a40(it) + (u16)(ref[1] - 1));
    if (!idx) return 0xffff;
    float f = *(float *)(rec + 0xa) + 1.0f;   // 0x678858
    f = f + 0.0f;
    f = f + 0.0001f;                          // 0x68c730
    u8 *n = *(u8 **)(self + 0x98) + idx * 0x15;
    if (!(*(float *)(n + 0xa) > f + 0.1f)) continue;
    *(float *)(n + 0xa) = f;
    u8 *e = self + 0x9e + *(u16 *)(self + 0x9c) * 32;
    *(u16 *)e = (u16)from32;
    *(u32 *)(e + 0x1c) = k;
    *(u16 *)(e + 2) = 0;
    __builtin_memset(e + 4, 0, 24);
    if (self[4]) {
      *(u16 *)(e + 2) = (*(u16 **)(self + 0x8c))[nearEnd + k * 2];
      if (self[5]) {
        float *P = (float *)(*(u8 **)(self + 0x90) + k * 24);
        __builtin_memcpy(e + 4, P + farEnd * 3, 12);
        __builtin_memcpy(e + 0x10, P + nearEnd * 3, 12);
      }
      if (!(u8)ext_532730(self, *(u16 *)(e + 2))) continue;
    }
    n[0x14] |= 1;
    *(u16 *)(n + 0xe) = *(u16 *)(self + 0x9c);
    (*(u16 *)(self + 0x9c))++;
    *(u16 *)n = id;
    n[3] = ref[1];
    *(u16 *)(n + 4) = L[farEnd * 3];
    *(u16 *)(n + 6) = L[farEnd * 3 + 1];
    *(u16 *)(n + 8) = L[farEnd * 3 + 2];
    ext_52d250(self, from32, idx);
  }
  return 1;
}
PCREG(532420, visitNeighborSpecialThin);
