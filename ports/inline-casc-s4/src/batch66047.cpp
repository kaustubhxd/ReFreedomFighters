// batch66047.cpp - cascade s4 batch 66047: 0x431110 (tier F row).
#include "ff.h"

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// 0x431110, thiscall(out, key) ret 8 (this = pointer to the tree head node, packed layout: root +1, left +5, right +9, key begin +0xd, key end +0x11): lower bound search.
// key = {begin, end}; head = *this; root == 0 -> *out = head. Otherwise best = head; for each node p from the root: nlen = p.end - p.begin; m = min(klen, nlen) (signed);
// c = bytewise unsigned memcmp(p.begin, key.begin, m); c == 0 -> c = (nlen < klen) ? -1 : (nlen > klen); c < 0 -> p = p.right else best = p, p = p.left. *out = best.
static void THISCALL fn431110(u8 **tp, u32 *out, u32 *key) {
  u8 *head = *tp;
  u8 *best = head;
  u8 *p = *(u8 **)(head + 1);
  if (!p) {
    *out = (u32)head;
    return;
  }
  u8 *kb = (u8 *)key[0];
  s32 klen = (s32)(key[1] - key[0]);
  do {
    u8 *nb = (u8 *)rd(p + 0xd);
    s32 nlen = (s32)(rd(p + 0x11) - (u32)nb);
    s32 m = klen < nlen ? klen : nlen;
    s32 c = 0;
    for (s32 i = 0; i < m; i++) {
      if (nb[i] != kb[i]) {
        c = nb[i] < kb[i] ? -1 : 1;
        break;
      }
    }
    if (c == 0) {
      if (nlen < klen) c = -1;
      else c = nlen > klen ? 1 : 0;
    }
    if (c < 0) {
      p = *(u8 **)(p + 9);
    } else {
      best = p;
      p = *(u8 **)(p + 5);
    }
  } while (p);
  *out = (u32)best;
}
PCREG(431110, fn431110);
