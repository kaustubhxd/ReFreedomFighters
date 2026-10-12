// batch239.cpp - area 59, docs/20-unclaimed-59.md (coordinator loop: larger functions). Recursive cell traversal:
// this = node (ecx); stack args S, A, B, C (ret 0x10). S->[+0x2c] is a depth counter incremented on entry and decremented
// on exit. Items of 16 bytes at S->[+0x10] are tested against the box S[0x50], S[0x54], S[0x58]; a callback S->[+4] is
// called (ecx = item, edx = S) when the test passes. Then the entries of 6 bytes at S->[+0xc] (from word node[+2] * 6, to the
// one with bit 0x8000) recurse with a child centre (A, B, C) +/- half. Name GUESS.
#include "ff.h"

typedef void(FASTCALL *Callback)(u8 *item, u8 *state);

// 0x4e3ae0, thiscall(node) with stack args (S, A, B, C) ret 0x10.
static void THISCALL cellTraverse_4e3ae0(u8 *node, u8 *S, s32 A, s32 B, s32 C) {
  *(u32 *)(S + 0x2c) += 1;
  u32 cnt = ((u32)*(u16 *)node >> 3) & 0xfffu;
  if (cnt) {
    u8 *item = *(u8 **)(S + 0x10) + (u32)*(u16 *)(node + 4) * 16;
    while (cnt != 0) {
      s32 box0 = *(s32 *)(S + 0x50);
      s32 box1 = *(s32 *)(S + 0x54);
      s32 box2 = *(s32 *)(S + 0x58);
      bool skip = box0 < (s32)*(u16 *)(item + 4) || box0 > (s32)*(u16 *)(item + 0xa) ||
                  box1 < (s32)*(u16 *)(item + 6) || box1 > (s32)*(u16 *)(item + 0xc) ||
                  box2 < (s32)*(u16 *)(item + 8) || box2 > (s32)*(u16 *)(item + 0xe);
      if (!skip) {
        Callback fn = (Callback)*(u32 *)(S + 4);
        fn(item, S);
      }
      item += 0x10;
      cnt -= 1;
    }
  }
  u32 w = *(u16 *)(node + 2);
  if (w == 0) {
    *(u32 *)(S + 0x2c) -= 1;
    return;
  }
  u8 *ent = *(u8 **)(S + 0xc) + 6 * w;
  if (ent == nullptr) {   // test ebx, ebx; je (the entry base plus 6 * w is zero)
    *(u32 *)(S + 0x2c) -= 1;
    return;
  }
  s32 size = (s32)(0x10000u >> (*(u32 *)(S + 0x2c) & 31));
  s32 half = size >> 1;
  for (;;) {
    u32 e = *(u16 *)ent & 7u;
    s32 xv = ((e & 1) ? half : -half) + A;
    s32 yv = ((e & 2) ? half : -half) + B;
    s32 zv = ((e & 4) ? half : -half) + C;
    s32 b0 = *(s32 *)(S + 0x50), b1 = *(s32 *)(S + 0x54), b2 = *(s32 *)(S + 0x58);
    bool inside = !(b0 >= xv + size || b0 < xv - size || b1 >= yv + size || b1 < yv - size ||
                    b2 >= zv + size || b2 < zv - size);
    if (inside) cellTraverse_4e3ae0(ent, S, xv, yv, zv);
    u32 wc = *(u16 *)ent;
    ent += 6;
    if (wc & 0x8000u) break;
  }
  *(u32 *)(S + 0x2c) -= 1;
}
PCREG(4e3ae0, cellTraverse_4e3ae0);
