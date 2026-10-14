// batch38000.cpp - cascade s8 batch 38000: 0x52e320 (octree cursor move by a 3-word delta).
#include "ff.h"

extern "C" void THISCALL ext_5308e0(u8 *tree, u32 *out, u8 *ptr, u32 idx);   // thiscall, ret 0xc

// 0x52e320, thiscall(const u16 *d) ret 4. this: [0]=tree, +0x16 node index, +0x18/+0x1a/+0x1c cursor x/y/z (u16).
// Tree: +0x54 node array (0x16-byte nodes, u16 +4 = first child, u16 +6+2*k = child k), +0x5a table of 12-byte entries (+4 child, +6 link),
// +0x2a, +0x72 = bit data. Descends from the current node by the bits where the cursor and cursor+d differ above bit 3, then
// advances the cursor and resolves the node through the link table / bit lookup.
static u16 THISCALL fn52e320(u8 *self, u16 *d) {
  u8 *tree = *(u8 **)self;
  u16 x = *(u16 *)(self + 0x18), y = *(u16 *)(self + 0x1a), z = *(u16 *)(self + 0x1c);
  u16 nx = (u16)(d[0] + x), ny = (u16)(d[1] + y), nz = (u16)(d[2] + z);
  u16 v = (u16)((((u16)(y ^ ny) | (u16)(x ^ nx)) >> 3) | (u16)(z ^ nz));
  if (v != 0) {
    u8 *nodes = *(u8 **)(tree + 0x54);
    u8 *tab = *(u8 **)(tree + 0x5a);
    u32 ebx = 0;
    u8 *n = nodes + (u32) * (u16 *)(tab + (u32) * (u16 *)(self + 0x16) * 12 + 4) * 0x16;
    nx = nx >> 3;
    ny = ny >> 2;
    nz = (u16)(nz << 2);
    u16 c = v >> 1;
    if (c) {
      do {
        n = nodes + (u32) * (u16 *)(n + 4) * 0x16;
        ebx++;
        c >>= 1;
      } while (c);
      do {
        u32 k = ((nx >> ebx) & 1) | ((ny >> ebx) & 2) | ((nz >> ebx) & 4);
        n = nodes + (u32) * (u16 *)(n + k * 2 + 6) * 0x16;
        ebx--;
      } while (ebx != 0);
    }
    u32 k = (nz & 4) | (ny & 2) | (nx & 1);
    *(u16 *)(self + 0x16) = *(u16 *)(n + k * 2 + 6);
  }
  *(u16 *)(self + 0x18) += d[0];
  *(u16 *)(self + 0x1a) += d[1];
  *(u16 *)(self + 0x1c) += d[2];
  u8 *tr = *(u8 **)self;
  u32 link = *(u16 *)(*(u8 **)(tr + 0x5a) + (u32) * (u16 *)(self + 0x16) * 12 + 6);
  if ((u16)link == 0) {
    *(u16 *)(self + 0x16) = 0;
    return 0;
  }
  u32 bit = (*(u16 *)(self + 0x18) & 7) + (*(u16 *)(self + 0x1a) & 7) * 8;
  u32 out;
  ext_5308e0(tr, &out, *(u8 **)(tr + 0x72) + (u32) * (u16 *)(tr + 0x2a) * link * 4, bit);
  if (out == 0) *(u16 *)(self + 0x16) = 0;
  return *(u16 *)(self + 0x16);
}
PCREG(52e320, fn52e320);
