// batch34144.cpp - cascade tier E, batch 34144: 0x5fcc40 (case-insensitive lower bound in a string tree).
#include "ff.h"

typedef int (*strnicmp_t)(const char *, const char *, u32);

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x5fcc40, thiscall(out, key) ret 8: h = [this]; node = unaligned [h+1] (the root). key = {begin, end}. For each node (string = [n+0xd] .. [n+0x11], unaligned fields, left +5, right +9):
// c = _strnicmp(nodestr, keybegin, min(keylen, nodelen)) (import [0x676408], signed min); when c == 0 it is -1 for nodelen < keylen, else 0 or 1 (nodelen > keylen). Negative: go right, otherwise remember the node and go left.
// *out = the remembered node (h when none). Returns out.
static u32 *THISCALL fn5fcc40(u8 *self, u32 *out, u32 *key) {
  u8 *best = *(u8 **)self;
  u8 *n = (u8 *)rd32(best + 1);
  if (n) {
    int klen = (int)(key[1] - key[0]);
    do {
      u32 s = rd32(n + 0xd);
      int nlen = (int)(rd32(n + 0x11) - s);
      int m = klen < nlen ? klen : nlen;
      int c = G(strnicmp_t, 0x676408)((const char *)s, (const char *)key[0], (u32)m);
      if (c == 0) {
        if (nlen < klen) c = -1;
        else c = nlen > klen;
      }
      if (c < 0) {
        n = (u8 *)rd32(n + 9);
      } else {
        best = n;
        n = (u8 *)rd32(n + 5);
      }
    } while (n);
  }
  *out = (u32)best;
  return out;
}
PCREG(5fcc40, fn5fcc40);
