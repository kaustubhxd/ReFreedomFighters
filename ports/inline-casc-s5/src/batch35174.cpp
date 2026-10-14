// batch35174.cpp - cascade s5 batch 35174: 0x648c50 (GUESS grow a draw array: allocate a block, thread its free list, link it into the ring).
#include "ff.h"

typedef u8 *(THISCALL *g0_t)(void *);
typedef u32(THISCALL *n0_t)(void *);

// 0x648c50, thiscall, no args, returns al. blk = this slot 0x30(); null returns 0. blk[1] = this[0x10]; n = this slot 0x28(); blk[8] = blk[0xc] = blk, blk[0] = 0, word blk[2] = 0; the free list: for i in 0..n-2 the word at blk + 0x10 + 0x78 * i = i + 1
// (n - 1 entries), then the word at the next entry = 0xffff. When this[8] (ecx) is set: blk[8] = ecx, blk[0xc] = ecx[0xc], ecx[0xc][8] = blk, ecx[0xc] = blk. this[8] = blk. Returns 1.
static u8 THISCALL fn648c50(u8 *self) {
  u8 *blk = (*(g0_t **)self)[0x30 / 4](self);
  if (!blk) return 0;
  blk[1] = self[0x10];
  u32 n = (*(n0_t **)self)[0x28 / 4](self);
  *(u8 **)(blk + 8) = blk;
  *(u8 **)(blk + 0xc) = blk;
  blk[0] = 0;
  *(u16 *)(blk + 2) = 0;
  u32 cnt = n - 1;
  u8 *e = blk + 0x10;
  if (cnt != 0) {
    u32 i = 0;
    do {
      i++;
      *(u16 *)e = (u16)i;
      e += 0x78;
    } while (i != cnt);
  }
  *(u16 *)e = 0xffff;
  u8 *ecx = *(u8 **)(self + 8);
  if (ecx) {
    *(u8 **)(blk + 8) = ecx;
    u8 *eax = *(u8 **)(ecx + 0xc);
    *(u8 **)(blk + 0xc) = eax;
    *(u8 **)(eax + 8) = blk;
    *(u8 **)(ecx + 0xc) = blk;
  }
  *(u8 **)(self + 8) = blk;
  return 1;
}
PCREG(648c50, fn648c50);
