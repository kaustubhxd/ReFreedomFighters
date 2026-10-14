// batch977.cpp - residue-05 (core todo), batch 977: ZCollisionBase::GetInnerRoomsLst (0x4ed1d0), thiscall, five stack args, ret 0x14.
// Returns 0 when [this+0x1a1] is 0 or when p2 <= p1 (unsigned). n = vslot 0x18(p1, p2, [this+0x1a1], p4); when that is 0,
// n = vslot 0x14(p1, p2, [this+0x1a1], p3, p4, p5). Returns n when n <= 1 (signed). Otherwise, for each of the n list entries
// X (in order): M = X.vslot 0x260(); for each entry Y of the list: K = Y.vslot 0x260(); when K != M: if M >= K, the chain
// X.vslot 0x20 (M-K times) ends at Yc; Yc == Y zeroes that entry; else the chain Y.vslot 0x20 (K-M times) ends at Yc; Yc == X
// zeroes X's entry. Finally the non-zero entries are compacted to the front and their count is returned.
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x4ed1d0 ZCollisionBase::GetInnerRoomsLst(p1, p2, p3, p4, p5).
static u32 THISCALL innerRoomsLst(u8 *t, u32 p1, u32 p2, u32 p3, u32 p4, u32 p5) {
  if (D(t, 0x1a1) == 0)
    return 0;
  if (!(p2 > p1))
    return 0;
  u32 n = vcall<u32>(t, 0x18, p1, p2, D(t, 0x1a1), p4);
  if (n == 0)
    n = vcall<u32>(t, 0x14, p1, p2, D(t, 0x1a1), p3, p4, p5);
  if ((int)n <= 1)
    return n;
  u32 *a = (u32 *)p1;
  for (u32 k = 0; k < n; k++) {
    u32 *cur = a + k;
    u32 x = *cur;
    if (x == 0)
      continue;
    u32 m = vcall<u32>((void *)x, 0x260);
    for (u32 i = 0; i < n; i++) {
      u32 *q = a + i;
      u32 y = *q;
      if (y == 0)
        continue;
      u32 kk = vcall<u32>((void *)y, 0x260);
      if (kk == m)
        continue;
      if (m >= kk) {
        u32 xx = x;
        for (u32 r = m - kk; r; r--)
          xx = vcall<u32>((void *)xx, 0x20);
        if (xx == y)
          *q = 0;
      } else {
        u32 yy = y;
        for (u32 r = kk - m; r; r--)
          yy = vcall<u32>((void *)yy, 0x20);
        if (yy == x)
          *cur = 0;
      }
    }
  }
  u32 cnt = 0;
  for (u32 i = 0; i < n; i++) {
    u32 v = a[i];
    if (v)
      a[cnt++] = v;
  }
  return cnt;
}
PCREG(4ed1d0, innerRoomsLst);
