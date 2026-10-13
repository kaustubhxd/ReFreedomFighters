// batch1116.cpp - collision thread, batch 1116: the quadtree box query (CQuadtree / CNodeQuad), names guessed.
#include "ff.h"

typedef void(FASTCALL *BoxCb)(u8 *obj, u8 *info);
extern "C" void THISCALL ext_4e49f0(u8 *node, u8 *info, u8 *pool);
extern "C" void THISCALL ext_4e42d0(u8 *node, u8 *info, u8 *pool, s32 level, s32 x, s32 z);

static inline u8 *childNode(const u8 *pool, u16 idx) { return *(u8 *const *)pool + idx * *(const u32 *)(pool + 0xc); }

// The box-query info record (an SRecurseInfoCompiled): +4 per-object callback (fastcall: object+8, info; its result
// is ignored here), +0x14 / +0x18 / +0x1c quantised min x, y, z (minus 1), +0x20 / +0x24 / +0x28 max (plus 2).

// 0x4e49f0 (unnamed; guessed CNodeQuad::CollectAll(info, pool)), thiscall, ret 8: every object of this node and of
// all its descendants goes to the callback (node objects first, then children 0..3 depth first).
static void THISCALL collectAll(u8 *self, u8 *info, u8 *pool) {
  for (u8 *o = *(u8 **)(self + 0xc); o; o = *(u8 **)o)
    (*(BoxCb *)(info + 4))(o + 8, info);
  for (u32 k = 0; k < 4; k++) {
    u16 c = ((const u16 *)self)[k];
    if (c)
      ext_4e49f0(childNode(pool, c), info, pool);
  }
}
PCREG(4e49f0, collectAll);

// 0x4e42d0 (unnamed; guessed CNodeQuad::CheckBox(info, pool, level, x, z)), thiscall, ret 0x14. Objects whose u16 box
// overlaps the query box (strict integer compares on all three axes) go to the callback. A child quadrant (half size
// 0x10000 >> (level + 1), centre x/z +- half/2 by index bits 0/1) that overlaps the query in XZ is either collected
// whole (when the query covers it in XZ) or walked recursively.
static void THISCALL checkBox(u8 *self, u8 *info, u8 *pool, s32 level, s32 x, s32 z) {
  level++;
  s32 half = 0x10000 >> level;
  const s32 *q = (const s32 *)(info + 0x14);   // min x y z, max x y z
  for (u8 *o = *(u8 **)(self + 0xc); o; o = *(u8 **)o) {
    const u16 *b = (const u16 *)(o + 0xc);
    if (q[0] < b[3] && q[3] > b[0] && q[1] < b[4] && q[4] > b[1] && q[2] < b[5] && q[5] > b[2])
      (*(BoxCb *)(info + 4))(o + 8, info);
  }
  s32 hq = half >> 1;
  for (u32 k = 0; k < 4; k++) {
    u16 c = ((const u16 *)self)[k];
    if (!c)
      continue;
    s32 cx = ((k & 1) ? hq : -hq) + x;
    s32 cz = ((k & 2) ? hq : -hq) + z;
    s32 x1 = half + cx, x0 = cx - half, z1 = half + cz, z0 = cz - half;
    if (q[0] >= x1 || q[3] < x0 || q[2] >= z1 || q[5] < z0)
      continue;
    if (q[0] <= x0 && q[3] >= x1 && q[2] <= z0 && q[5] >= z1)
      ext_4e49f0(childNode(pool, c), info, pool);
    else
      ext_4e42d0(childNode(pool, c), info, pool, level, cx, cz);
  }
}
PCREG(4e42d0, checkBox);

// 0x4e4420 (unnamed; guessed CQuadtree::CheckBox(info, min, max)), thiscall, ret 0xc. Quantises the box like
// CheckLinesegment ((p - origin) * scale + 32768, truncated), widens it (min - 1, max + 2) into info+0x14..0x28 and
// queries from the root (level 0, centre 0x8000, 0x8000).
static void THISCALL quadCheckBox(u8 *self, u8 *info, const float *mn, const float *mx) {
  float sc = *(const float *)(self + 0x1d);
  float ox = *(const float *)(self + 0x21), oy = *(const float *)(self + 0x25), oz = *(const float *)(self + 0x29);
  s32 a0 = (s32)(((mn[0] - ox) * sc) + 32768.0f);
  s32 a1 = (s32)(((mn[1] - oy) * sc) + 32768.0f);
  s32 a2 = (s32)(((mn[2] - oz) * sc) + 32768.0f);
  s32 b0 = (s32)(((mx[0] - ox) * sc) + 32768.0f);
  s32 b1 = (s32)(((mx[1] - oy) * sc) + 32768.0f);
  float t = ((mx[2] - oz) * sc);
  s32 *q = (s32 *)(info + 0x14);
  q[0] = a0 - 1;
  q[1] = a1 - 1;
  q[2] = a2 - 1;
  q[3] = b0 + 2;
  q[4] = b1 + 2;
  q[5] = (s32)(t + 32768.0f) + 2;
  ext_4e42d0(*(u8 **)self, info, self + 4, 0, 0x8000, 0x8000);
}
PCREG(4e4420, quadCheckBox);
