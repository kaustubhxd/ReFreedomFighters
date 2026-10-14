// batch37055.cpp - cascade s6 batch 37055: 0x63e310.
#include "ff.h"

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))

// 0x63e310, thiscall(off, size) ret 8: returns the free range [off, off+size) to a binned free list. this: bins of node pointers at +0 (index off >> [this+0x3404]), 12-byte nodes
// {start, size, next} from the pool at +0x400 (used count u16 +0x3400, free-list head index u16 +0x3402, the free nodes chain through their first u16). The free block ending at off
// (searched in its bin, then the first non-empty lower bin) and the one starting at off+size (its bin) are merged with the range; with neither a new node is taken from the pool.
static void THISCALL fn63e310(u8 *self, u32 off, u32 size) {
  u32 shift = D32(self, 0x3404);
  u32 bin = off >> shift;
  u32 *pbin = (u32 *)(self + bin * 4);
  u32 *pred = (u32 *)*pbin;
  while (pred) {
    if (pred[1] + pred[0] == off) goto havePred;
    pred = (u32 *)pred[2];
  }
  {
    s32 k = (s32)bin - 1;
    if (k >= 0) {
      while (D32(self, k * 4) == 0) {
        k--;
        if (k < 0) break;
      }
    }
    pred = (u32 *)D32(self, (u32)k * 4);
    while (pred) {
      if (pred[1] + pred[0] == off) break;
      pred = (u32 *)pred[2];
    }
  }
havePred:
  u32 end = size + off;
  u32 *link = (u32 *)(self + (end >> shift) * 4);
  u32 *succ = (u32 *)*link;
  while (succ) {
    if (succ[0] == end) break;
    link = succ + 2;
    succ = (u32 *)*link;
  }
  if (pred) {
    pred[1] += size;
    if (succ) {
      pred[1] += succ[1];
      *link = succ[2];
      u8 *poolb = self + 0x400;
      U16(poolb, 0x3000) = (u16)(U16(poolb, 0x3000) + 0xffff);
      U16(succ, 0) = U16(poolb, 0x3002);
      s32 diff = (s32)((u8 *)succ - poolb);
      s32 idx = diff / 12;
      U16(poolb, 0x3002) = (u16)idx;
    }
    return;
  }
  if (succ) {
    succ[0] -= size;
    succ[1] += size;
    *link = succ[2];
    succ[2] = *pbin;
    *pbin = (u32)succ;
    return;
  }
  u32 head = U16(self, 0x3402);
  u32 *node;
  if (head == 0xffff) {
    node = 0;
  } else {
    u32 e = head * 3 + 0x100;
    u16 nxt = *(u16 *)(self + e * 4);
    U16(self, 0x3400) = (u16)(U16(self, 0x3400) + 1);
    node = (u32 *)(self + e * 4);
    U16(self, 0x3402) = nxt;
  }
  node[0] = off;
  node[1] = size;
  u32 b2 = off >> D32(self, 0x3404);
  node[2] = D32(self, b2 * 4);
  D32(self, b2 * 4) = (u32)node;
}
PCREG(63e310, fn63e310);
