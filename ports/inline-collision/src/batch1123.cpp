// batch1123.cpp - collision thread, batch 1123: octree node walk 0x4e3ce0 (GUESS name: the recursive helper of
// ZOctreeCompiled::GetEverything 0x4e3cc0, slot 0x20). Names are GUESSes from the bytes.
#include "ff.h"

// 0x4e3ce0 (unnamed; GUESS OctreeNodeWalkAll), thiscall (ECX = node record), one stack arg (info), ret 4.
// Node record (6 bytes): u16 +0 = bit 15 "last sibling" flag and count in bits 3..14, u16 +2 = first child index
// (0 = none; child records are 6 bytes at info+0xc), u16 +4 = first item index (items are 16 bytes at info+0x10).
// info: +4 callback (fastcall: item in ECX, info in EDX), +0xc child record base, +0x10 item base.
// 1. Every item of this node (count from +0) goes to the callback, in order.
// 2. Each child in the sibling run starting at child index (+2) is walked recursively, until a child whose
//    flag word has bit 15 set has been walked.
static void THISCALL octreeNodeWalkAll(u8 *node, u8 *info) {
  u32 cnt = (*(const u16 *)node >> 3) & 0xfff;
  u8 *item = *(u8 **)(info + 0x10) + 16 * (u32)*(const u16 *)(node + 4);
  for (u32 i = 0; i < cnt; i++, item += 16)
    ((void (FASTCALL *)(u8 *, u8 *))(*(void **)(info + 4)))(item, info);
  u32 first = *(const u16 *)(node + 2);
  if (!first)
    return;
  u8 *child = *(u8 **)(info + 0xc) + 6 * first;
  for (;;) {
    octreeNodeWalkAll(child, info);
    bool last = (*(const u16 *)child & 0x8000) != 0;
    child += 6;
    if (last)
      break;
  }
}
PCREG(4e3ce0, octreeNodeWalkAll);
