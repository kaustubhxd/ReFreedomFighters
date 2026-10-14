// batch34146.cpp - cascade tier E, batch 34146: 0x615650 (the same pool-block template as batch 34145 with element stride 0x30).
#include "ff.h"

// Shared body: b = this->slot0x30() (0 gives false); b[1] = byte [this+0x10]; n = this->slot0x28(); b[8] = b[0xc] = b; b[0] = 0; word b[2] = 0; free-list words: for i in 0 .. n-2 the word at b+0x10+i*stride is i+1
// (nothing when n == 1; the loop assumes n >= 1), then the word at b+0x10+(n-1)*stride is 0xffff. When a list head [this+8] exists b is linked in front of it through +8/+0xc; [this+8] = b. Returns true.
static u32 pool_block(u8 *self, u32 stride) {
  u8 *b = vcall<u8 *>(self, 0x30);
  if (!b) return 0;
  b[1] = self[0x10];
  u32 n = vcall<u32>(self, 0x28);
  *(u8 **)(b + 8) = b;
  *(u8 **)(b + 0xc) = b;
  b[0] = 0;
  *(u16 *)(b + 2) = 0;
  u8 *p = b + 0x10;
  u32 cnt = n - 1;
  if (cnt) {
    u32 i = 0;
    do {
      i++;
      *(u16 *)p = (u16)i;
      p += stride;
    } while (i != cnt);
  }
  *(u16 *)p = 0xffff;
  u8 *head = *(u8 **)(self + 8);
  if (head) {
    *(u8 **)(b + 8) = head;
    u8 *w = *(u8 **)(head + 0xc);
    *(u8 **)(b + 0xc) = w;
    *(u8 **)(w + 8) = b;
    *(u8 **)(head + 0xc) = b;
  }
  *(u8 **)(self + 8) = b;
  return 1;
}
static u32 THISCALL fn615650(u8 *self) { return pool_block(self, 0x30); }
PCREG(615650, fn615650);
