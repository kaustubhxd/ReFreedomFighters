// batch844.cpp - gap band pool free (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

typedef u8 *(THISCALL *vfind_t)(u8 *self, u8 *item);
typedef void (THISCALL *vfree_t)(u8 *self, u8 *blk);

// 0x63f760: thiscall(item) ret 4 - pool release. this[0xc]--; blk = vt[0x2c](item) (the 16-byte-stride block header holding the
// item); clears item[5] bit 1, pushes the item onto the block's free chain ([blk+2], item[0..1] = next index), blk[0]-- (live
// count). Still live: moves blk to the front of the ring this[8] (links +8 next, +0xc prev). Empty: unlinks it (advancing this[8]
// first when it is the head, 0 when alone) and gives it back through vt[0x34].
static void THISCALL poolRelease_63f760(u8 *self, u8 *item) {
  u8 *vt = *(u8 **)self;
  *(u32 *)(self + 0xc) -= 1;
  u8 *blk = (*(vfind_t *)(vt + 0x2c))(self, item);
  item[5] &= 0xfd;
  u16 next = *(u16 *)(blk + 2);
  blk[0]--;
  *(u16 *)item = next;
  s32 idx = ((s32)((u32)item - (u32)blk - 0x10)) >> 4;
  *(u16 *)(blk + 2) = (u16)idx;
  if (blk[0] != 0) {
    if (blk == *(u8 **)(self + 8)) return;
    u8 *n = *(u8 **)(blk + 8);
    u8 *p = *(u8 **)(blk + 0xc);
    *(u8 **)(n + 0xc) = p;
    p = *(u8 **)(blk + 0xc);
    n = *(u8 **)(blk + 8);
    *(u8 **)(p + 8) = n;
    u8 *head = *(u8 **)(self + 8);
    *(u8 **)(blk + 8) = head;
    u8 *hp = *(u8 **)(head + 0xc);
    *(u8 **)(blk + 0xc) = hp;
    *(u8 **)(hp + 8) = blk;
    *(u8 **)(head + 0xc) = blk;
    *(u8 **)(self + 8) = blk;
    return;
  }
  if (*(u8 **)(self + 8) == blk) {
    u8 *nx = *(u8 **)(blk + 8);
    if (nx == blk) nx = 0;
    *(u8 **)(self + 8) = nx;
  }
  u8 *n = *(u8 **)(blk + 8);
  u8 *p = *(u8 **)(blk + 0xc);
  *(u8 **)(n + 0xc) = p;
  p = *(u8 **)(blk + 0xc);
  n = *(u8 **)(blk + 8);
  *(u8 **)(p + 8) = n;
  (*(vfree_t *)(*(u8 **)self + 0x34))(self, blk);
}
PCREG(63f760, poolRelease_63f760);

// Siblings of 0x63f760 with a different item stride (the block header is 0x10 bytes, items follow): the index stored in blk[2] is
// (item - blk - 0x10) / stride; 0x63f6b0 does not clear item[5] bit 1. All share the ring / vt[0x2c] / vt[0x34] handling.
#define POOL_RELEASE(NAME, ADDR, IDXEXPR, CLR)                                                   \
  static void THISCALL NAME(u8 *self, u8 *item) {                                                \
    u8 *vt = *(u8 **)self;                                                                       \
    *(u32 *)(self + 0xc) -= 1;                                                                   \
    u8 *blk = (*(vfind_t *)(vt + 0x2c))(self, item);                                             \
    if (CLR) item[5] &= 0xfd;                                                                    \
    u16 next = *(u16 *)(blk + 2);                                                                \
    blk[0]--;                                                                                    \
    *(u16 *)item = next;                                                                         \
    s32 diff = (s32)((u32)item - (u32)blk - 0x10);                                               \
    *(u16 *)(blk + 2) = (u16)(IDXEXPR);                                                          \
    if (blk[0] != 0) {                                                                           \
      if (blk == *(u8 **)(self + 8)) return;                                                     \
      u8 *n = *(u8 **)(blk + 8);                                                                 \
      u8 *p = *(u8 **)(blk + 0xc);                                                               \
      *(u8 **)(n + 0xc) = p;                                                                     \
      p = *(u8 **)(blk + 0xc);                                                                   \
      n = *(u8 **)(blk + 8);                                                                     \
      *(u8 **)(p + 8) = n;                                                                       \
      u8 *head = *(u8 **)(self + 8);                                                             \
      *(u8 **)(blk + 8) = head;                                                                  \
      u8 *hp = *(u8 **)(head + 0xc);                                                             \
      *(u8 **)(blk + 0xc) = hp;                                                                  \
      *(u8 **)(hp + 8) = blk;                                                                    \
      *(u8 **)(head + 0xc) = blk;                                                                \
      *(u8 **)(self + 8) = blk;                                                                  \
      return;                                                                                    \
    }                                                                                            \
    if (*(u8 **)(self + 8) == blk) {                                                             \
      u8 *nx = *(u8 **)(blk + 8);                                                                \
      if (nx == blk) nx = 0;                                                                     \
      *(u8 **)(self + 8) = nx;                                                                   \
    }                                                                                            \
    u8 *n = *(u8 **)(blk + 8);                                                                   \
    u8 *p = *(u8 **)(blk + 0xc);                                                                 \
    *(u8 **)(n + 0xc) = p;                                                                       \
    p = *(u8 **)(blk + 0xc);                                                                     \
    n = *(u8 **)(blk + 8);                                                                       \
    *(u8 **)(p + 8) = n;                                                                         \
    (*(vfree_t *)(*(u8 **)self + 0x34))(self, blk);                                              \
  }                                                                                              \
  PCREG(ADDR, NAME)

POOL_RELEASE(poolRelease48_63f6b0, 63f6b0, diff / 48, 0);
POOL_RELEASE(poolRelease76_63f8a0, 63f8a0, diff / 76, 1);
POOL_RELEASE(poolRelease64_63f950, 63f950, diff >> 6, 1);
POOL_RELEASE(poolRelease24_63f9f0, 63f9f0, diff / 24, 1);
