// batch67534.cpp - cascade s6 batch 67534: 0x430b70.
#include "ff.h"

extern "C" int FASTCALL ext_42feb0(u8 *b1, u8 *e1, u8 *b2, u8 *e2);   // ret 8: memcmp of the common prefix, then length order; -1 / 0 / 1

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x430b70, thiscall(out, key) ret 8, returns out: find in a std::map-like tree keyed by byte strings. this -> head node (head+1 = root; node +5 left, +9 right, +0xd / +0x11 = key begin / end).
// Lower bound: a node whose key is below the search key [key[0], key[1]) (prefix memcmp of the common length, then the shorter first) goes right, otherwise it becomes the candidate and the walk goes
// left. Then the exact check 0x42feb0 (key against the candidate): when the key is below the candidate (or there is none) *out = head (end), else *out = candidate.
static u8 *THISCALL fn430b70(u8 **self, u8 **out, u32 *key) {
  u8 *head = *self;
  u8 *cand = head;
  u8 *node = (u8 *)D32(head, 1);
  while (node) {
    u8 *nb = (u8 *)D32(node, 0xd), *ne = (u8 *)D32(node, 0x11);
    int nlen = (int)(ne - nb), klen = (int)(key[1] - key[0]);
    int m = klen < nlen ? klen : nlen;
    int c = 0;
    for (int k = 0; k < m; k++) {
      u8 x = nb[k], y = ((u8 *)key[0])[k];
      if (x != y) { c = x < y ? -1 : 1; break; }
    }
    if (c == 0) c = nlen < klen ? -1 : (nlen > klen ? 1 : 0);
    if (c < 0) {
      node = (u8 *)D32(node, 9);
    } else {
      cand = node;
      node = (u8 *)D32(node, 5);
    }
  }
  if (cand != head && ext_42feb0((u8 *)key[0], (u8 *)key[1], (u8 *)D32(cand, 0xd), (u8 *)D32(cand, 0x11)) >= 0) {
    *out = cand;
    return (u8 *)out;
  }
  *out = head;
  return (u8 *)out;
}
PCREG(430b70, fn430b70);
