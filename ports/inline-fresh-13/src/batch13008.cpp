// batch13008.cpp - fresh slice 13, batch 8 (docs/20-fresh-13.md), 2026-10-12.
// 0x63b710 ZOffsetAllocPointerSort<1024>::AllocHi(unsigned size) (name map medium). Thiscall, one argument (ret 4).
// Free blocks are 12-byte nodes {addr, size, next} in a pool at this+0x400 (1024 nodes), chained per bucket in
// this[0..top] (top = int at +0x3408). From the top bucket down, the first bucket holding a block of at least `size`
// wins; inside it the block with the highest addr is taken. The block shrinks from the top (returns addr + new size);
// a block used up is unlinked, its node goes onto the pool's free list (word count +0x3400 decremented, head word
// +0x3402 = node index, the node's first word = the old head) and its addr is returned. No fit -> 0.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

static u32 THISCALL allocHi(u8 *self, u32 size) {
  s32 i = AT(s32, self, 0x3408);
  for (; i >= 0; i--) {
    u32 *slot = (u32 *)(self + 4 * i);
    u8 *node = (u8 *)*slot;
    if (!node)
      continue;
    u8 *best = 0;
    u32 *bestslot = (u32 *)size;  // the exe seeds this register with the size; it is only used once best is set
    u32 *link = slot;
    do {
      if (AT(u32, node, 4) >= size && (!best || AT(u32, best, 0) < AT(u32, node, 0))) {
        bestslot = link;
        best = node;
      }
      link = (u32 *)(node + 8);
      node = (u8 *)*link;
    } while (node);
    if (!best)
      continue;
    AT(u32, best, 4) -= size;
    if (AT(u32, best, 4))
      return AT(u32, best, 0) + AT(u32, best, 4);
    u32 addr = AT(u32, best, 0);
    *bestslot = AT(u32, best, 8);
    u8 *pool = self + 0x400;
    AT(u16, pool, 0x3000) += 0xffff;
    AT(u16, best, 0) = AT(u16, pool, 0x3002);
    AT(u16, pool, 0x3002) = (u16)((s32)(best - pool) / 12);
    return addr;
  }
  return 0;
}
PCREG(63b710, allocHi);
