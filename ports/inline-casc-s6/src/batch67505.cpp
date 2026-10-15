// batch67505.cpp - cascade s6 batch 67505: 0x4377e0.
#include "ff.h"

extern "C" u8 *THISCALL ext_4382e0(u32 bucket0);   // makes a list node (plain ret per its callers: no stack args)

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// Owner of an entry through the tagged link at +0xc: tag 3 means the owner is the link minus 4, tag 1 the pointer at link+8 minus 4, anything else no owner.
static u8 *ownerOf(u8 *edi) {
  u8 *c = *(u8 **)(edi + 0xc);
  if (!c) return 0;
  u32 t = D32(c, 0);
  if (t == 3) return c - 4;
  if (t == 1) {
    u8 *y = *(u8 **)(c + 8);
    return y ? y - 4 : 0;
  }
  return 0;
}

// 0x4377e0, thiscall(key, flag) ret 8: registers this entry in the owner world's bucket list for `key` (10-byte buckets at world+0x1344), when key is below the world's counter (+0x1210,
// signed): a new node (0x4382e0 from the bucket's first dword) {payload this+4, flag byte, next = old head} becomes the head; when the bucket's byte at +8 equals the flag the entry's
// match counter (+0x42) is bumped; the entry's list object (+0x15, slot 4) is told the key, the call counter (+0x19) is bumped and, when the two counters differ, bit 4 of +0x32 is cleared.
static void THISCALL fn4377e0(u8 *self, u32 key, u32 flagArg) {
  u8 *w = *(u8 **)(ownerOf(self) + 0x11);
  if ((s32)D32(w, 0x1210) <= (s32)key) return;
  w = *(u8 **)(ownerOf(self) + 0x11);
  u32 off = key * 10;
  u8 *bucket = *(u8 **)(w + 0x1344) + off;
  u8 *node = ext_4382e0(D32(bucket, 0));
  D32(node, 5) = D32(bucket, 4);
  u32 payload = self ? (u32)(self + 4) : 0;
  D32(bucket, 4) = (u32)node;
  u8 dl = (u8)flagArg;
  D32(node, 0) = payload;
  node[4] = dl;
  w = *(u8 **)(ownerOf(self) + 0x11);
  if (dl == (*(u8 **)(w + 0x1344))[off + 8]) D32(self, 0x42)++;
  vcall<void>(*(void **)(self + 0x15), 4, key);
  D32(self, 0x19)++;
  if (D32(self, 0x42) != D32(self, 0x19)) self[0x32] &= 0xef;
}
PCREG(4377e0, fn4377e0);
