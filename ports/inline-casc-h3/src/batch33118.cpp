// batch33118.cpp - h3 (Sonnet) batch 33118: tier H float/SSE functions
#include "ff.h"

static inline u8 *P(u8 *p) { return *(u8 **)p; }
static inline float K(u8 *n) { return *(float *)(n + 4); }

// 0x4fdb70: thiscall no args: re-sorts a node in its doubly linked list (key float at +4, prev +8, next +0xc, owner +0x10; owner head +0x48, tail +0x4c, cursor +0x50): find the new predecessor and relink
static void THISCALL fn4fdb70(u8 *node) {
  u8 *esi = 0;
  u8 *prev = P(node + 8);
  if (prev && K(node) > K(prev)) esi = prev;
  u8 *next = P(node + 0xc);
  if (next && K(next) > K(node)) {
    u8 *owner = P(node + 0x10);
    esi = P(owner + 0x4c);
  }
  if (!esi) return;
  for (;;) {
    if (esi != node) {
      if (K(esi) >= K(node)) break;
    }
    esi = P(esi + 8);
    if (!esi) break;
  }
  if (esi == P(node + 8)) return;
  u8 *owner = P(node + 0x10);
  if (P(owner + 0x50) == node) *(u8 **)(owner + 0x50) = next;
  u8 *a = P(node + 8);
  u8 *b = P(node + 0xc);
  if (a) *(u8 **)(a + 0xc) = b;
  else *(u8 **)(P(node + 0x10) + 0x48) = b;
  u8 *c = P(node + 0xc);
  u8 *d = P(node + 8);
  if (c) *(u8 **)(c + 8) = d;
  else *(u8 **)(P(node + 0x10) + 0x4c) = d;
  *(u8 **)(node + 8) = esi;
  if (esi) {
    *(u8 **)(node + 0xc) = P(esi + 0xc);
    *(u8 **)(esi + 0xc) = node;
  } else {
    u8 *o2 = P(node + 0x10);
    *(u8 **)(node + 0xc) = P(o2 + 0x48);
    *(u8 **)(o2 + 0x48) = node;
  }
  u8 *e = P(node + 0xc);
  if (e) {
    *(u8 **)(e + 8) = node;
    return;
  }
  *(u8 **)(P(node + 0x10) + 0x4c) = node;
}
PCREG(4fdb70, fn4fdb70);
