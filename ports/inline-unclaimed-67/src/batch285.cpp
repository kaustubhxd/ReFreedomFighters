// batch285.cpp - unclaimed area 67, gap band: search by a word key over the node graph at [this]; result via out.
#include "ff.h"

static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }
static inline u16 rdh(u32 p, u32 off) { return *(u16 *)(unsigned long)(p + off); }

// 0x5ff0f0, thiscall, ret 8 (args out, keyptr). See docs/20-unclaimed-67.md batch 285.
static void THISCALL treeSearch5ff0(u8 *selfP, u32 out, u32 keyptr) {
  u32 a = rdw((u32)(unsigned long)selfP, 0);
  u32 cur = a;
  u32 p = rdw(a, 1);
  u16 kw = rdh(keyptr, 0);
  while (p != 0) {
    if (rdh(p, 0xd) < kw) {
      p = rdw(p, 9);
    } else {
      cur = p;
      p = rdw(p, 5);
    }
  }
  u32 res = a;
  if (cur != a && !(kw < rdh(cur, 0xd)))
    res = cur;
  *(u32 *)(unsigned long)out = res;
}
PCREG(5ff0f0, treeSearch5ff0);
