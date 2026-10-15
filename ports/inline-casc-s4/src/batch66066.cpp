// batch66066.cpp - cascade s4 batch 66066: 0x5fb980 (tier F row).
#include "ff.h"

typedef s32(*nicmp_t)(const char *, const char *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }

// 0x5fb980, thiscall(out, key) ret 8 (this = pointer to the tree head node, packed layout: root +1, left +5, right +9, key begin +0xd, key end +0x11): find. key = {begin, end}.
// Lower bound: best = head; for each node p from the root: m = min(klen, nlen); c = _strnicmp(p.begin, key.begin, m); c == 0 -> c = nlen vs klen; c < 0 -> right else best = p, left.
// Then best != head and not (key < best: c2 = _strnicmp(key.begin, best.begin, min), ties by length) -> *out = best, otherwise *out = head.
static void THISCALL fn5fb980(u8 **tp, u32 *out, u32 *key) {
  u8 *head = *tp;
  u8 *best = head;
  u8 *p = *(u8 **)(head + 1);
  s32 klen = (s32)(key[1] - key[0]);
  while (p) {
    u32 nb = rd(p + 0xd);
    s32 nlen = (s32)(rd(p + 0x11) - nb);
    s32 m = klen < nlen ? klen : nlen;
    s32 c = G(nicmp_t, 0x676408)((const char *)nb, (const char *)key[0], (u32)m);
    if (c == 0) c = nlen < klen ? -1 : (nlen > klen ? 1 : 0);
    if (c < 0) {
      p = *(u8 **)(p + 9);
    } else {
      best = p;
      p = *(u8 **)(p + 5);
    }
  }
  if (best != head) {
    u32 bb = rd(best + 0xd);
    s32 blen = (s32)(rd(best + 0x11) - bb);
    s32 m = blen < klen ? blen : klen;
    s32 c = G(nicmp_t, 0x676408)((const char *)key[0], (const char *)bb, (u32)m);
    if (c == 0) c = klen < blen ? -1 : (klen > blen ? 1 : 0);
    if (c >= 0) {
      *out = (u32)best;
      return;
    }
  }
  *out = (u32)head;
}
PCREG(5fb980, fn5fb980);
