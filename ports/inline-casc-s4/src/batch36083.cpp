// batch36083.cpp - cascade s4 batch 36083: 0x444840 (tier F row).
#include "ff.h"

typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef void (*pr_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }

extern "C" void THISCALL ext_440ce0(void *it, u32 a);   // ret 4

// 0x444840, thiscall(out, end) ret 8, returns the final out pointer (this = t): it = {node, cur, limit} filled by 0x440ce0(it, t[0xbc]); cur == 0 -> return out.
// Ranges: for each pair (cur[0] & ~7, cur[1] & ~7) = (lo, hi): cur += 8; for blocks of 0x70 bytes lo <= hi: end <= out -> log (0x67d564, 0x96) with message 0x67d58c, return out;
// block[0x3c] & 0x10000000 clear -> *out++ = block. When cur reaches limit: walk the chain from node: no node or node[8] & 1 clear -> return out;
// node = node[0xc]; null -> return; node[8] < 2 repeats; else cur = node + 0xc (+4 when node[8] & 1), limit = node + (node[8] + 3) * 4. cur == 0 -> return.
static u32 *THISCALL fn444840(u8 *t, u32 *out, u32 *end) {
  u32 it[4];
  ext_440ce0(it, rd(t + 0xbc));
  u8 *node = (u8 *)it[0];
  u8 *cur = (u8 *)it[1];
  u8 *limit = (u8 *)it[2];
  if (!cur) return out;
  do {
    u32 lo = rd(cur) & 0xfffffff8u;
    u32 hi = rd(cur + 4) & 0xfffffff8u;
    cur += 8;
    if (lo <= hi) {
      do {
        if (end <= out) {
          u8 *db = G(u8 *, 0x700390);
          u8 *lg = (*(v2o_t **)db)[0x20 / 4](db, 0x67d564u, 0x96u);
          void *fn = *(void **)((u8 *)*(void ***)lg + 0x30);
          ((pr_t)fn)(lg, 0x67d58cu);
          return out;
        }
        if (!(rd((u8 *)lo + 0x3c) & 0x10000000)) *out++ = lo;
        lo += 0x70;
      } while (lo <= hi);
    }
    if (cur == limit) {
      if (!node) return out;
      do {
        if (!(node[8] & 1)) return out;
        node = *(u8 **)(node + 0xc);
        if (!node) return out;
      } while (node[8] < 2);
      u8 al = node[8];
      cur = node + 0xc;
      if (al & 1) cur += 4;
      limit = node + (al + 3) * 4;
    }
  } while (cur);
  return out;
}
PCREG(444840, fn444840);
