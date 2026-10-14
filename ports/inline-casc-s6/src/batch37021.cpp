// batch37021.cpp - cascade s6 batch 37021: 0x531070.
#include "ff.h"

#define W16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x531070, thiscall(d) ret 4, returns the new node index: moves an octree cursor. this = {+0 tree, +0x12 level (dword), +0x16 node index (word), +0x18/+0x1a/+0x1c
// x/y/z positions (words), +0x20 mode (1: parent via tree+0x54 nodes, 2: via tree+0x5a table), +0x21/+0x25/+0x29 step words}; d points at three word deltas. Nodes are
// 0x16 bytes at tree+0x54 (first child index at +4, eight child indices at +6). The new position (x+dx, ...) is located by descending from the current node
// by the highest differing coordinate bit, then following the octant bits; finally the positions advance by step * delta.
static u32 THISCALL fn531070(u8 *self, u16 *d) {
  u8 *t = *(u8 **)self;
  u32 L = D32(t, 0x38) - D32(self, 0x12);
  u16 x = W16(self, 0x18), y = W16(self, 0x1a), z = W16(self, 0x1c);
  u16 xs = (u16)(x >> ((L + 2) & 31));
  u16 ys = (u16)(y >> ((L + 2) & 31));
  u16 zs = (u16)(z >> ((L - 1) & 31));
  u16 x2 = (u16)(d[0] + xs), y2 = (u16)(d[1] + ys), z2 = (u16)(d[2] + zs);
  u16 m = (u16)(((z2 ^ zs) | (y2 ^ ys) | (x2 ^ xs)) >> 1);
  u32 mode = *(u8 *)(self + 0x20);
  u8 *node = 0;
  u8 *base = (u8 *)D32(t, 0x54);
  if (mode == 1) {
    u32 ix = W16(self, 0x16) * 0x16;
    u32 ch = W16(base, ix + 4);
    node = base + ch * 0x16;
    mode = *(u8 *)(self + 0x20);
  }
  if (mode == 2) {
    u32 ix = W16(self, 0x16) * 3;
    u8 *tab = (u8 *)D32(t, 0x5a);
    u32 ch = W16(tab, ix * 4 + 4);
    node = base + ch * 0x16;
  }
  u16 ys2 = (u16)(y2 + y2);
  u16 zs4 = (u16)(z2 << 2);
  u32 edi = 0;
  u16 cx = m;
  if (cx) {
    base = (u8 *)D32(*(u8 **)self, 0x54);
    do {
      u32 ch = W16(node, 4);
      edi++;
      node = base + ch * 0x16;
      cx >>= 1;
    } while (cx);
    if (edi) {
      u32 cnt = edi;
      while (cnt) {
        u32 c = (u16)cnt & 31;
        u32 idx = ((ys2 >> c) & 2) | ((x2 >> c) & 1) | ((zs4 >> c) & 4);
        u32 ch = W16(node, idx * 2 + 6);
        node = (u8 *)(D32(t, 0x54) + ch * 0x16);
        cnt--;
      }
    }
  }
  u32 idx = (zs4 & 4) | (ys2 & 2) | (x2 & 1);
  W16(self, 0x16) = W16(node, idx * 2 + 6);
  W16(self, 0x18) = (u16)(W16(self, 0x18) + (u16)(W16(self, 0x21) * d[0]));
  W16(self, 0x1a) = (u16)(W16(self, 0x1a) + (u16)(W16(self, 0x25) * d[1]));
  W16(self, 0x1c) = (u16)(W16(self, 0x1c) + (u16)(W16(self, 0x29) * d[2]));
  return W16(self, 0x16);
}
PCREG(531070, fn531070);
