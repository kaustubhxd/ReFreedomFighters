// batch6.cpp - first-level functions, inline session batch 6 (Haiku, 2026-10-09 night).
#include "ff.h"

// 0x466c70, stdcall (ret 8): writes a 16-byte result to out and returns out. k == 2 selects {vtable 0x465708, 0, 0, 0},
// otherwise {0, 0, 0, -1}. Name unknown (a status or key record).
static u32 *STDCALL resultOfK(u32 *out, s32 k) {
  if (k == 2) {
    out[0] = 0x465708;
    out[1] = 0;
    out[2] = 0;
    out[3] = 0;
  } else {
    out[0] = 0;
    out[1] = 0;
    out[2] = 0;
    out[3] = 0xffffffffu;
  }
  return out;
}
PCREG(466c70, resultOfK);

// 0x4ccb40, thiscall (ret 8): constructor of a table with rows = m + 2 and cols = max(n, 1). Vtable 0x6958cc at +0,
// zeroes +4, +8, +0x14, +0x1c, +0x20; sets +0xc = cols, +0x10 = cols * rows, +0x18 = rows. Returns this.
static u32 *THISCALL initTable2(u32 *self, s32 n, s32 m) {
  s32 cols = n >= 1 ? n : 1;
  u32 rows = (u32)m + 2u;
  self[0] = 0x6958cc;
  self[1] = 0;
  self[2] = 0;
  self[3] = (u32)cols;
  self[4] = (u32)cols * rows;
  self[5] = 0;
  self[6] = rows;
  self[7] = 0;
  self[8] = 0;
  return self;
}
PCREG(4ccb40, initTable2);

// 0x4cf530, thiscall (ret 4): pool step. p = {node, count}. If node == 0, returns 0. Otherwise count -= this+0x18; if
// count went negative, node = *node (next), *p = node, return 0 when node is NULL, else count = this+0x10 - this+0x18.
// Returns node_base + 0x10 + count * 4 (the address of the entry the count points at). Name unknown.
static u32 THISCALL pooledStep(u8 *self, u32 *p) {
  if (p[0] == 0)
    return 0;
  s32 cnt = (s32)(p[1] - *(u32 *)(self + 0x18));
  p[1] = (u32)cnt;
  if (cnt < 0) {
    u32 node = *(u32 *)p[0];
    p[0] = node;
    if (node == 0)
      return 0;
    cnt = (s32)(*(u32 *)(self + 0x10) - *(u32 *)(self + 0x18));
    p[1] = (u32)cnt;
  }
  return p[0] + p[1] * 4u + 0x10u;
}
PCREG(4cf530, pooledStep);

// 0x59d530, fastcall (ECX = src, EDX = end, one stack arg dst, ret 4): copies 64-byte blocks from src to dst
// (dst is advanced by 0x40 per block, skipped when dst is NULL) until src reaches end. Requires end - src to be a
// multiple of 0x40 (otherwise the original never leaves the loop). Name unknown.
static void FASTCALL copyBlocks64(u8 *src, u8 *end, u8 *dst) {
  if (src == end)
    return;
  u32 off = (u32)src - (u32)dst;
  u32 cur = (u32)dst;
  do {
    if (cur != 0) {
      for (u32 i = 0; i < 0x40; i += 16)
        __builtin_memcpy((u8 *)(cur + i), (u8 *)(off + cur + i), 16);
    }
    cur += 0x40;
  } while (off + cur != (u32)end);
}
PCREG(59d530, copyBlocks64);

// 0x5853a0, fastcall (ECX = src, EDX = end, stack dst and one unused dword, ret 8): copies 0x48-byte records from
// src to dst (both advance by 0x48) until src reaches end. Name unknown.
static void FASTCALL copyRecords48(u8 *src, u8 *end, u8 *dst, u32 unused) {
  (void)unused;
  if (src == end)
    return;
  do {
    if (dst != 0) {
      for (u32 i = 0; i < 0x40; i += 16)
        __builtin_memcpy(dst + i, src + i, 16);
      __builtin_memcpy(dst + 0x40, src + 0x40, 8);
    }
    src += 0x48;
    dst += 0x48;
  } while (src != end);
}
PCREG(5853a0, copyRecords48);
