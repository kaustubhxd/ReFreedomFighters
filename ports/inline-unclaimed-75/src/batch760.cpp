// batch760.cpp - unclaimed area 75 (docs/20-unclaimed-75.md), slice floor(addr/16) mod 20 == 13.
#include "ff.h"

typedef int i32;

// 0x4a1710, thiscall(v) ret 4 (GUESS name: bucket update). Arrays: A = this+4 (dwords), KB = this+0x800, K = this+0x804,
// count c = [this+0x820]. Stage 1 finds L (the first index p >= 1 with v <= K[p], or 0 when v <= K[0]); L == 7 moves
// A[c] into A[v]; L > 7 ends. Stage 2 loops while v < c and L < 7: search e = 0..7 with lo(e) (0 for e = 0, else KB[e] + 1)
// <= v <= K[e] (the first match is f); if none, the hook at 0x7003b0 is called (and f = 0). Then the old key is swapped
// into place (A[v] and A[oldkey]), the run K[f-1..1] equal to K[f] is decremented, K[f] is decremented, and L++.
// Finally, if v < c, A[v] and A[c] are swapped; the count goes c-1; and the dwords at this+0x81c, 0x818, ... equal to the old
// c are decremented while they match. Name GUESS.
static void THISCALL bucketUpdate_4a1710(u8 *self, u32 v0) {
  u32 *A = (u32 *)(self + 4);
  u32 *KB = (u32 *)(self + 0x800);
  u32 *K = (u32 *)(self + 0x804);
  u32 *cnt = (u32 *)(self + 0x820);
  u32 esi = v0;
  i32 L = 0;
  bool toEnd = false;
  if ((i32)esi > (i32)K[0]) {
    i32 p = 0;
    do {
      ++p;
    } while ((i32)esi > (i32)K[p]);
    L = p;
  }
  if (L == 7) {
    A[esi] = A[*cnt];
    toEnd = true;
  } else if (L > 7) {
    toEnd = true;
  }
  while (!toEnd) {
    if ((i32)esi >= (i32)*cnt) break;
    i32 f = -1;
    for (u32 e = 0; e < 8; ++e) {
      i32 lo = (e == 0) ? 0 : ((i32)KB[e] + 1);
      if ((i32)esi < lo) continue;
      if ((i32)esi <= (i32)K[e]) {
        f = (i32)e;
        break;
      }
    }
    if (f < 0) {
      void (*hook)(void) = (void (*)(void))*(u32 *)0x7003b0u;
      if (hook) hook();
      f = 0;
    }
    i32 oldkey = (i32)K[f];
    if (oldkey == (i32)esi) {
      esi = (u32)oldkey;
    } else {
      u32 t = A[esi];
      A[esi] = A[(u32)oldkey];
      A[(u32)oldkey] = t;
      esi = (u32)oldkey;
    }
    for (i32 j = f - 1; j > 0; --j) {
      if ((i32)K[j] != (i32)K[f]) break;
      K[j] -= 1;
    }
    K[f] -= 1;
    ++L;
    if (L >= 7) break;
  }
  // end: swap A[v] and A[c] when v < c; then the count goes down and the matching trailing dwords are decremented
  u32 c = *cnt;
  if ((i32)esi < (i32)c) {
    u32 t = A[esi];
    A[esi] = A[c];
    A[c] = t;
  }
  *cnt = c - 1;
  u32 *addr = (u32 *)(self + 0x81c);
  while (*addr == c) {
    *addr -= 1;
    --addr;
  }
}
PCREG(4a1710, bucketUpdate_4a1710);
