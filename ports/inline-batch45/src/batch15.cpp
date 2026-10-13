// batch15.cpp - first-level functions, inline session batch 15 (Haiku, overnight).
#include "ff.h"

// 0x615500, thiscall (no stack args, returns a pointer or 0): like advanceSlot with 312-byte nodes, the marker
// 0xffff1201 and the vtable word 0x6bdabc. Name unknown.
static u32 THISCALL advanceSlot312(u8 *self) {
  u16 w = *(u16 *)(self + 2);
  if (w == 0xffff)
    return 0;
  u8 *node = self + (u32)w * 0x138u;
  *(u16 *)(self + 2) = *(u16 *)(node + 0x10);
  *(u32 *)(node + 0x14) = 0;
  *(u32 *)(node + 0x18) = 0xffff1201u;
  *(u32 *)(node + 0x1c) = 0;
  node[0x80] = 0;
  *(u32 *)(node + 0x84) = 0;
  *(u32 *)(node + 0x10) = 0x6bdabcu;
  self[0] += 1;
  return (u32)(node + 0x10);
}
PCREG(615500, advanceSlot312);

// 0x5eeb40, thiscall (ret 0x10): if the four stored dwords at +0x5a, +0x5e, +0x62 and +0x66 differ from the four
// arguments, stores the arguments there and sets the byte at +0x77 to 1. Name unknown.
static void THISCALL cacheFour(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  if (*(u32 *)(self + 0x5a) == a && *(u32 *)(self + 0x5e) == b && *(u32 *)(self + 0x62) == c &&
      *(u32 *)(self + 0x66) == d)
    return;
  *(u32 *)(self + 0x5a) = a;
  *(u32 *)(self + 0x5e) = b;
  *(u32 *)(self + 0x62) = c;
  *(u32 *)(self + 0x66) = d;
  self[0x77] = 1;
}
PCREG(5eeb40, cacheFour);

// 0x600ba0, thiscall (ret 4, returns AL): walks a list of nodes linked at +0x9c, starting at this. A node matches when
// its value at +0x4c is at most x and the span (+0x64 - +0x60 + value) is above x. Returns 1 on the first match, else 0.
// Name unknown.
static u8 THISCALL inSpan(u8 *self, u32 x) {
  u8 *node = self;
  for (;;) {
    u32 v = *(u32 *)(node + 0x4c);
    if (v <= x) {
      u32 end = *(u32 *)(node + 0x64) - *(u32 *)(node + 0x60) + v;
      if (end > x)
        return 1;
    }
    node = *(u8 **)(node + 0x9c);
    if (node == nullptr)
      return 0;
  }
}
PCREG(600ba0, inSpan);
