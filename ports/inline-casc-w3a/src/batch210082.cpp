// batch210082.cpp - Sonnet-w3a: 0x4cfbe0 (grow the pool by one 2 MB block: reuse a free slot or malloc a new aligned one)
#include "ff.h"

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" u32 THISCALL ext_4cfb30(u8 *self, u32 block, u32 size);

typedef u32 (*Malloc)(u32 n);

static u32 THISCALL fn4cfbe0(u8 *self) {
  *(u32 *)(self + 4) += 0x200000;  // @4cfbe0_a
  u32 n = *(u32 *)(self + 0x1c8);
  if (n) {  // @4cfbe0_b
    n--;
    *(u32 *)(self + 0x1c8) = n;
    u32 blk = *(u32 *)(self + n * 4 + 8);  // @4cfbe0_c
    return ext_4cfb30(self, blk, 0x200000);
  }
  if (ld32(self + 0x207) >= 0x2710) return 0;  // @4cfbe0_d
  u32 p = G(Malloc, 0x6762f0)(0x200020);  // @4cfbe0_e
  u32 blk = (p + 0x13) & 0xfffffff0u;  // @4cfbe0_f
  *(u32 *)(blk - 4) = p;
  u32 idx = *(u32 *)(self + 0xd628);
  u8 *slot = (u8 *)*(u32 *)(self + idx * 4 + 0xc628);  // @4cfbe0_g
  *(u32 *)(self + 0xd628) = idx + 1;  // @4cfbe0_h
  *(u32 *)(slot + 0xc) = blk;  // @4cfbe0_i
  u8 *obj = self + 0x1ea;
  typedef u32 (THISCALL *F)(u8 *, u8 *);
  (*(F *)ld32(obj))(obj, slot);  // @4cfbe0_j
  return ext_4cfb30(self, blk, 0x200000);
}
PCREG(4cfbe0, fn4cfbe0);
