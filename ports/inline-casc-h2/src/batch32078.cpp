// batch32078.cpp - cascade h2 (Sonnet): 0x4d14a0 (new list node holding a byte copy, linked after a node or at the tail of an owner).
#include "ff.h"

extern "C" u8 *ext_41e290(u32 n);                          // alloc, cdecl
extern "C" void ext_634d22(void *dst, const void *src, u32 n);  // memcpy-style, cdecl

// 0x4d14a0, thiscall(src, n, owner, after) ret 0x10, returns this: [this+0xc] = alloc(n) filled from src; [this+0x10] = n; [this] = owner.
// Node links: +4 prev, +8 next?? (as the exe uses them): after != 0: [this+4] = after[4], [this+8] = after, the old after[4] (when set) gets [+8] = this,
// else owner[0x18] = this; after[4] = this. after == 0: [this+4] = owner[0x1c], [this+8] = 0; when owner[0x1c] set its [+8] = this, else owner[0x18] = this; owner[0x1c] = this.
static u8 *THISCALL fn4d14a0(u8 *self, const u8 *src, u32 n, u8 *owner, u8 *after) {
  u8 *buf = ext_41e290(n);
  *(u8 **)(self + 0xc) = buf;
  ext_634d22(buf, src, n);
  *(u32 *)(self + 0x10) = n;
  *(u8 **)self = owner;
  if (after) {
    u8 *p = *(u8 **)(after + 4);
    *(u8 **)(self + 4) = p;
    *(u8 **)(self + 8) = after;
    if (p) {
      *(u8 **)(p + 8) = self;
      *(u8 **)(after + 4) = self;
    } else {
      *(u8 **)(owner + 0x18) = self;
      *(u8 **)(after + 4) = self;
    }
    return self;
  }
  u8 *t = *(u8 **)(owner + 0x1c);
  *(u8 **)(self + 4) = t;
  *(u32 *)(self + 8) = 0;
  t = *(u8 **)(owner + 0x1c);
  if (t) {
    *(u8 **)(t + 8) = self;
    *(u8 **)(owner + 0x1c) = self;
  } else {
    *(u8 **)(owner + 0x18) = self;
    *(u8 **)(owner + 0x1c) = self;
  }
  return self;
}
PCREG(4d14a0, fn4d14a0);
