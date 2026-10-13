#include "ff.h"
// batch981.cpp - unclaimed-80 residue-19 (docs/20-unclaimed-80.md), batch 59: 0x431330 (thiscall, self in ecx, two stack arguments out and key, ret 8,
// returns out). Map upper-bound style search over packed nodes: head = [self]; node fields root/left +1/+5 (head +1 is the root), right +9, key begin +0xd,
// key end +0x11. key is a {begin, end} range. Compare = memcmp over min(klen, nlen) (dwords then a byte tail, -1/1 by unsigned byte); on a tie the
// shorter key is less. key < node: y = node, go left; else go right. *out = y (the head when nothing is less).

static s32 cmp431330(const u8 *a, const u8 *b, s32 n) {
  for (s32 i = 0; i < n; i++)
    if (a[i] != b[i]) return a[i] < b[i] ? -1 : 1;
  return 0;
}

static u8 **THISCALL zg431330(u8 **self, u8 **out, u8 **key) {
  u8 *y = *self;
  u8 *x = *(u8 **)(y + 1);
  if (x != 0) {
    u8 *kb = key[0];
    s32 klen = (s32)(key[1] - kb);
    do {
      u8 *nb = *(u8 **)(x + 0xd);
      s32 nlen = (s32)(*(u8 **)(x + 0x11) - nb);
      s32 m = nlen < klen ? nlen : klen;
      s32 c = cmp431330(kb, nb, m);
      bool less = c != 0 ? c < 0 : klen < nlen;
      if (less) {
        y = x;
        x = *(u8 **)(x + 5);
      } else {
        x = *(u8 **)(x + 9);
      }
    } while (x != 0);
  }
  *out = y;
  return out;
}
PCREG(431330, zg431330);
