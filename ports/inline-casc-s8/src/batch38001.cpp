// batch38001.cpp - cascade s8 batch 38001: 0x5318a0 (skip-list style chain shortening over 0x15-byte nodes).
#include "ff.h"

extern "C" u32 THISCALL ext_52dbb0(u8 *tree, u8 *node, u8 *parent, u32 zero);   // thiscall, ret 0xc

// 0x5318a0, thiscall(u16 start) ret 4. Nodes live at [this+0x98], 0x15 bytes each: u16 +0xe = next, byte +0x14 = flags (bit 0 = locked).
// Walks the chain from `start`. For each node P (via table [this + 32*cur + 0x9e] when the previous node was locked), finds the furthest
// descendant x of its next link by doubling steps while 0x52dbb0(node, P, 0) accepts, then halves back down; stores x as P.next (unless locked).
static void THISCALL fn5318a0(u8 *self, u32 arg) {
  u32 cur = arg & 0xffff;
  u8 f = 0;
  if (cur == 0) return;
  for (;;) {
    u32 idx = cur;
    if (f & 1) idx = *(u16 *)(self + cur * 32 + 0x9e);
    u8 *base = *(u8 **)(self + 0x98);
    u8 *P = base + (idx & 0xffff) * 0x15;
    u32 c = *(u16 *)(P + 0xe);
    u8 bl = P[0x14];
    if (c == 0) return;
    u32 edi = 1;
    u32 x;
    u8 bh;
    for (;;) {
      x = c;
      bh = bl;
      if (cur == 0) break;
      if ((bl | f) & 1) break;
      base = *(u8 **)(self + 0x98);
      u32 s = c;
      u8 *n = base + (s & 0xffff) * 0x15;
      u32 k = 0;
      if ((s32)edi > 0) {
        do {
          s = *(u16 *)(n + 0xe);
          bl = n[0x14];
          if ((u16)s == 0) break;
          if (bl & 1) goto stopA;
          n = base + (s & 0xffff) * 0x15;
          k++;
        } while ((s32)k < (s32)edi);
      }
      if (bl & 1) break;
      if ((u16)s == 0) break;
      if (ext_52dbb0(self, n, P, 0) == 0) break;
      edi += edi;
      c = s & 0xffff;
      continue;
    stopA:
      break;
    }
    u8 bx = bh;   // bl = bh
    u32 ax = x;
    if (ax != 0 && cur != 0 && !((bh | f) & 1) && (s32)edi > 1) {
      do {
        edi = (u32)((s32)edi / 2);
        base = *(u8 **)(self + 0x98);
        u32 s = ax & 0xffff;
        u8 *n = base + s * 0x15;
        u32 k = 0;
        u8 b2 = bx;
        if ((s32)edi > 0) {
          do {
            s = *(u16 *)(n + 0xe);
            b2 = n[0x14];
            if ((u16)s == 0) break;
            if (b2 & 1) break;
            n = base + (s & 0xffff) * 0x15;
            k++;
          } while ((s32)k < (s32)edi);
        }
        if ((u16)s != 0 && !(b2 & 1) && ext_52dbb0(self, n, P, 0) != 0) {
          ax = s & 0xffff;
          bh = b2;
          bx = b2;
        } else {
          bx = bh;
        }
      } while ((s32)edi > 1);
    }
    if (!(((bx | f) & 1))) *(u16 *)(P + 0xe) = (u16)ax;
    cur = *(u16 *)(P + 0xe);
    f = P[0x14];
    if (cur == 0) return;
  }
}
PCREG(5318a0, fn5318a0);
