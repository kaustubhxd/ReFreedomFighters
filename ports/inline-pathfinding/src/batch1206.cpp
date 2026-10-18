// batch1206.cpp - pathfinding tree: the packed octree iterator (moves between neighbouring elements / nodes).
//
// ZPFOctree_packed (more fields): +0x2a u16 dwords per leaf bit block, +0x48 bits per element, +0x72 leaf bit data
// (u32 words). Component table +0x54 (0x16-byte nodes: +4 parent, +6 children[8] u16), area-info table +0x5a
// (12-byte records: +4 parent node, +6 leaf block index; 0 = no leaf data).
// ZPFOctreeIterator_packed: +0 octree*, +0x12 int level, +0x16 u16 current node / area id, +0x18 / +0x1a / +0x1c u16
// position (local x, z, y), +0x20 u8 kind of the current id (1 = component node, 2 = area), +0x21 / +0x25 / +0x29
// u16 step per axis (NodeMove), each in a 4-byte slot.
// Child index inside a node: bit 0 = x, bit 1 = z, bit 2 = y. A leaf covers 8 x 8 elements in x/z and one in y.
#include "pf.h"

#define COMP(o) (*(u8 **)((o) + 0x54))
#define AREA(o) (*(u8 **)((o) + 0x5a))
#define NODE(base, i) ((base) + (u32)(i) * 0x16)
#define PARENT(n) (*(u16 *)((n) + 4))
#define CHILD(n, k) (*(u16 *)((n) + 6 + (k) * 2))

// 0x5308e0 (no GC name; inlined there) ZPFOctree_packed element value: thiscall (octree), ret 0xc,
// (int* out, u32* leafBits, int index). The +0x48 bits of element `index` are stored in bit planes 64 bits apart,
// highest plane first; *out is rebuilt through memory one bit at a time, as the exe does.
static void THISCALL octElementBits(u8 *oct, int *out, u32 *bits, int idx) {
  *out = 0;
  int bpe = *(int *)(oct + 0x48);
  u32 pos = (u32)bpe * 64u + (u32)idx - 64u;
  int sh = pos & 0x1f;
  u32 *w = (u32 *)((u8 *)bits + ((int)pos >> 5) * 4);
  for (int k = bpe - 1; k >= 0; k--) {
    int b = ((int)*w >> sh) & 1;
    *out = b | (int)((u32)*out * 2u);
    w -= 2;
  }
}
PCREG(5308e0, octElementBits);

static inline u8 *opaque(u8 *p) {
  asm("" : "+r"(p));
  return p;
}

// 0x52e320 ZPFOctreeIterator_packed::ElementMove(const short*) [map high; GC 80195e20]. thiscall, ret 4, u16 (AX).
// Moves the element position by d (x, z, y). If the move leaves the current leaf (x>>3, z>>3 or y changes), it climbs
// one node per significant bit of the difference from the leaf's parent node and descends again along the new
// position's bits. Then the element value of the new position is read; 0 (blocked) or no leaf data clears the id.
static u32 THISCALL elementMove(u8 *it, const s16 *d) {
  u8 *oct = *(u8 **)it;
  u16 px = *(u16 *)(it + 0x18), pz = *(u16 *)(it + 0x1a), py = *(u16 *)(it + 0x1c);
  u16 nx = (u16)(d[0] + px), nz = (u16)(d[1] + pz), ny = (u16)(d[2] + py);
  u16 diff = (u16)((u16)((pz ^ nz) | (px ^ nx)) >> 3) | (u16)(py ^ ny);
  if (diff) {
    u8 *comp = COMP(oct);
    u8 *n = NODE(comp, *(u16 *)(AREA(oct) + *(u16 *)(it + 0x16) * 12 + 4));
    u32 lx = (u16)(nx >> 3), lz = (u16)(nz >> 2), ly = (u16)(ny << 2);
    int up = 0;
    for (u16 c = diff >> 1; c; c >>= 1) {
      n = NODE(comp, PARENT(n));
      up++;
    }
    for (; up; up--) n = NODE(comp, CHILD(n, ((lz >> up) & 2) | ((lx >> up) & 1) | ((ly >> up) & 4)));
    *(u16 *)(it + 0x16) = CHILD(n, (ly & 4) | (lz & 2) | (lx & 1));
  }
  *(u16 *)(it + 0x18) += d[0];
  *(u16 *)(it + 0x1a) += d[1];
  *(u16 *)(it + 0x1c) += d[2];
  u16 leaf = *(u16 *)(AREA(oct) + *(u16 *)(it + 0x16) * 12 + 6);
  if (!leaf) {
    *(u16 *)(it + 0x16) = 0;
    return 0;
  }
  int idx = (*(u16 *)(it + 0x18) & 7) + (*(u16 *)(it + 0x1a) & 7) * 8;
  int v;
  octElementBits(oct, &v, (u32 *)(*(u8 **)(oct + 0x72) + (u32)*(u16 *)(oct + 0x2a) * leaf * 4), idx);
  if (!v) *(u16 *)(it + 0x16) = 0;
  return *(u16 *)(it + 0x16);
}
PCREG(52e320, elementMove);

// 0x531070 ZPFOctreeIterator_packed::NodeMove(const short*) [map high; GC 80196084]. thiscall, ret 4, u16 (AX).
// Same walk for nodes on level +0x12: the node position is the element position shifted by (levels - level + 2) in
// x/z and (levels - level - 1) in y; the move is d in nodes, and the element position then advances by d * step.
// Start node: kind 1 = parent of the current component node, kind 2 = parent node of the current area; any other
// kind starts from NULL (the exe then faults on the first read).
static u32 THISCALL nodeMove(u8 *it, const s16 *d) {
  u8 *oct = *(u8 **)it;
  u32 L = *(u32 *)(oct + 0x38) - *(u32 *)(it + 0x12);
  u32 sxz = (L + 2) & 0x1f, sy = (L - 1) & 0x1f;
  u16 sx = (u16)(*(u16 *)(it + 0x18) >> sxz), sz = (u16)(*(u16 *)(it + 0x1a) >> sxz);
  u16 syv = (u16)(*(u16 *)(it + 0x1c) >> sy);
  u16 nx = (u16)(d[0] + sx), ny = (u16)(d[2] + syv), nz = (u16)(d[1] + sz);
  u16 diff = (u16)((u16)((ny ^ syv) | (nz ^ sz) | (nx ^ sx)) >> 1);
  u8 kind = it[0x20];
  u8 *n = opaque(0);
  if (kind == 1) {
    u8 *comp = COMP(oct);
    n = NODE(comp, PARENT(NODE(comp, *(u16 *)(it + 0x16))));
    kind = it[0x20];
  }
  if (kind == 2) n = NODE(COMP(oct), *(u16 *)(AREA(oct) + *(u16 *)(it + 0x16) * 12 + 4));
  u32 nz2 = (u16)(nz + nz), ny4 = (u16)(ny << 2);
  int up = 0;
  if (diff) {
    u8 *comp = COMP(oct);
    for (u16 c = diff; c; c >>= 1) {
      n = NODE(comp, PARENT(n));
      up++;
    }
    for (; up; up--) n = NODE(COMP(oct), CHILD(n, ((nz2 >> up) & 2) | ((nx >> up) & 1) | ((ny4 >> up) & 4)));
  }
  *(u16 *)(it + 0x16) = CHILD(n, (ny4 & 4) | (nz2 & 2) | (nx & 1));
  *(u16 *)(it + 0x18) += (u16)((u32)*(u16 *)(it + 0x21) * (u16)d[0]);
  *(u16 *)(it + 0x1a) += (u16)((u32)*(u16 *)(it + 0x25) * (u16)d[1]);
  *(u16 *)(it + 0x1c) += (u16)((u32)*(u16 *)(it + 0x29) * (u16)d[2]);
  return *(u16 *)(it + 0x16);
}
PCREG(531070, nodeMove);
