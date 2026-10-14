// batch820.cpp - standing assignment, residue 19 (docs/20-unclaimed-gap-621.md). Names are GUESS.
// Reworked in the 10th-agent session: the old port misread vt[5] and skipped four of the five paths. This one follows
// the machine code branch by branch. 0x676408 is the _strnicmp import slot (stubbed in the spec via hook + w32).
#include "ff.h"

typedef int (__attribute__((cdecl)) *cmp_fn)(const void *a, const void *b, u32 n);
extern "C" void THISCALL ext_5fb400(u8 *self, u8 *out, u8 *a, u8 *b, u8 *k);  // hooked (GUESS): tree insert, ret 0x10
extern "C" u32 *THISCALL ext_5fc480(u8 *self, u32 *tmp, u8 *k);               // hooked (GUESS): find/insert-unique, ret 8
extern "C" void THISCALL ext_42ffc0(u32 *slot);                               // hooked (GUESS): slot = predecessor(slot)
extern "C" u8 THISCALL ext_5fb270(u8 *self, u8 *k, u8 *keyRange);             // real callee: span less-than

// span compare of two [start,end) byte ranges (strnicmp over the shorter, then length)
static inline bool spanLess(const u8 *a0, s32 alen, const u8 *b0, s32 blen) {
  s32 n = blen < alen ? blen : alen;
  int r = G(cmp_fn, 0x676408)(a0, b0, (u32)n);
  if (r) return r < 0;
  return alen < blen;
}

// 0x5fc2f0, thiscall(out, node, key) ret 0xc: hinted insert position in a tree whose head node is *this (head+5 / head+9
// are its first/last links, node+0xd..+0x15 the key range, this[4] the size). Returns out.
static u8 *THISCALL hintInsert_5fc2f0(u8 *self, u8 *out, u8 *node, u8 *k) {
  u8 *head = *(u8 **)self;
  u32 tmp = 0;
  const u32 *kr = (const u32 *)k;
  s32 klen = (s32)(kr[1] - kr[0]);
  if (node == *(u8 **)(head + 5)) {
    if (*(u32 *)(self + 4) != 0) {
      const u32 *nr = (const u32 *)(node + 0xd);
      s32 nlen = (s32)(nr[1] - nr[0]);
      if (spanLess((u8 *)kr[0], klen, (u8 *)nr[0], nlen)) {
        ext_5fb400(self, out, node, node, k);
        return out;
      }
    }
  } else if (node == head) {
    u8 *p = *(u8 **)(head + 9);
    const u32 *pr = (const u32 *)(p + 0xd);
    s32 plen = (s32)(pr[1] - pr[0]);
    if (spanLess((u8 *)pr[0], plen, (u8 *)kr[0], klen)) {
      ext_5fb400(self, out, 0, *(u8 **)(head + 9), k);
      return out;
    }
  } else {
    u32 local = (u32)node;
    ext_42ffc0(&local);
    u8 *p = (u8 *)local;
    const u32 *pr = (const u32 *)(p + 0xd);
    s32 plen = (s32)(pr[1] - pr[0]);
    if (spanLess((u8 *)pr[0], plen, (u8 *)kr[0], klen) && ext_5fb270(self + 8, k, node + 0xd)) {
      if (*(u32 *)(p + 9) == 0)
        ext_5fb400(self, out, 0, p, k);
      else
        ext_5fb400(self, out, node, node, k);
      return out;
    }
  }
  u32 *r = ext_5fc480(self, &tmp, k);
  *(u32 *)out = *r;
  return out;
}
PCREG(5fc2f0, hintInsert_5fc2f0);
