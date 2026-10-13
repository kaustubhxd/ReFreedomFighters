// batch1124.cpp - collision thread, batch 1124: octree box walk 0x4e3380 (CheckCube's walk; names GUESS).
#include "ff.h"

extern "C" void THISCALL ext_4e3ce0(u8 *node, u8 *info);   // OctreeNodeWalkAll (batch 1123)

// 0x4e3380 (unnamed; GUESS OctreeCubeWalk), thiscall (ECX = node record), 5 stack args (info, depth, cx, cy, cz), ret 0x14.
// info (query record): +4 item callback (fastcall: item in ECX, info in EDX), +0xc child record base, +0x10 item base,
// +0x14/+0x18/+0x1c query min x/y/z, +0x20/+0x24/+0x28 query max x/y/z (signed compares).
// Cube of this node: half-size size = 0x10000 >> (depth + 1), centred on (cx, cy, cz).
// 1. Each item of the node (6 words: +4/+6/+8 min, +0xa/+0xc/+0xe max) that overlaps the query gets the callback.
// 2. Each child of the sibling run (6-byte records from node+2): its octant (bits 0..2 of its word) puts its centre at
//    +-q, q = size >> 1, from (cx, cy, cz). If its cube (centre +- size) overlaps the query: when the query contains it
//    the whole subtree goes to the node walk (ext 0x4e3ce0); otherwise this walk recurses with depth and the child centre.
static void THISCALL octreeCubeWalk(u8 *node, u8 *info, s32 depth, s32 cx, s32 cy, s32 cz) {
  s32 size = (s32)(0x10000u >> (depth + 1));
  u32 cnt = (*(const u16 *)node >> 3) & 0xfff;
  if (cnt) {
    u8 *item = *(u8 **)(info + 0x10) + 16 * (u32)*(const u16 *)(node + 4);
    for (u32 i = 0; i < cnt; i++, item += 16) {
      const u16 *u = (const u16 *)item;   // movzx in the exe: unsigned words
      if (*(s32 *)(info + 0x14) >= (s32)u[5] || *(s32 *)(info + 0x20) <= (s32)u[2] ||
          *(s32 *)(info + 0x18) >= (s32)u[6] || *(s32 *)(info + 0x24) <= (s32)u[3] ||
          *(s32 *)(info + 0x1c) >= (s32)u[7] || *(s32 *)(info + 0x28) <= (s32)u[4])
        continue;
      ((void (FASTCALL *)(u8 *, u8 *))(*(void **)(info + 4)))(item, info);
    }
  }
  u32 first = *(const u16 *)(node + 2);
  if (!first)
    return;
  u8 *child = *(u8 **)(info + 0xc) + 6 * first;
  s32 q = size >> 1;
  for (;;) {
    u32 oct = *(const u16 *)child & 7;
    s32 ccx = cx + ((oct & 1) ? q : -q);
    s32 ccy = cy + ((oct & 2) ? q : -q);
    s32 ccz = cz + ((oct & 4) ? q : -q);
    bool overlap = !(*(s32 *)(info + 0x14) >= ccx + size || *(s32 *)(info + 0x20) < ccx - size ||
                     *(s32 *)(info + 0x18) >= ccy + size || *(s32 *)(info + 0x24) < ccy - size ||
                     *(s32 *)(info + 0x1c) >= ccz + size || *(s32 *)(info + 0x28) < ccz - size);
    if (overlap) {
      bool inside = *(s32 *)(info + 0x14) <= ccx - size && *(s32 *)(info + 0x20) >= ccx + size &&
                    *(s32 *)(info + 0x18) <= ccy - size && *(s32 *)(info + 0x24) >= ccy + size &&
                    *(s32 *)(info + 0x1c) <= ccz - size && *(s32 *)(info + 0x28) >= ccz + size;
      if (inside)
        ext_4e3ce0(child, info);
      else
        octreeCubeWalk(child, info, depth + 1, ccx, ccy, ccz);   // the exe pushes its stored depth+1 (mov [ebp+0xc], ecx)
    }
    bool last = (*(const u16 *)child & 0x8000) != 0;
    child += 6;
    if (last)
      break;
  }
}
PCREG(4e3380, octreeCubeWalk);
