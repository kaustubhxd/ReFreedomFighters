// batch67531.cpp - cascade s6 batch 67531: 0x54e450.
#include "ff.h"

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(int *)((u8 *)(p) + (o)))
typedef void (*hook67531_t)();

// 0x54e450, thiscall() plain ret, returns al: one step of a ring-buffer reader. When slot 0xc (ready) says yes it asks the source at this[0x4b] (slot 0xc: (this, offset = this[0x47]*this[0x3b] +
// this[0x18], size = this[0x5f]*this[0x14], this[0x3b])) for data, stores this[0x5f] / this[4] in the source, advances the position this[0x43] by the (assert: non-negative) count and either
// wraps (this[0x57] set: this[0x43] = this[0x67] + this[0x33], flag +0x1d, leftover in this[0x14] / this[0x18]) or marks the current slot (+0x26 bit 1, leftover in this[0x5b]) before
// marking this[0x5f] consecutive slots filled (+0x1e = 1, +0x26 bit 2), wrapping the slot index at this[0x37] and setting +0x1c once everything is consumed.
static u32 THISCALL fn54e450(u8 *self) {
  self[0x5a] = 0;
  if (!(u8)vcall<u32>(self, 0xc)) return 0;
  u32 edx = D32(self, 0x5f) * D32(self, 0x14);
  u8 *src = *(u8 **)(self + 0x4b);
  u32 edi = D32(self, 0x3b);
  u32 ebx = D32(self, 0x47) * edi + D32(self, 0x18);
  int n = vcall<int>(src, 0xc, (u32)self, ebx, edx, edi);
  D32(*(u8 **)(self + 0x4b), 0x1bd) = D32(self, 0x5f);
  D32(*(u8 **)(self + 0x4b), 0x1c1) = D32(self, 4);
  if (n < 0) {
    hook67531_t h = *(hook67531_t *)0x7003b0;
    if (h) h(); else __asm__ volatile("int3");
  }
  D32(self, 0x43) += (u32)n;
  int pos = S32(self, 0x43);
  int e3 = S32(self, 0x33);
  int lim = S32(self, 0x3f);
  u32 v47 = D32(self, 0x47);
  D32(self, 0x18) = 0;
  D32(self, 0x14) = v47;
  if (!(lim > pos - e3)) {
    u32 left = (u32)lim - (u32)pos + (u32)e3 + (u32)n;
    if (self[0x57]) {
      D32(self, 0x43) = D32(self, 0x67) + (u32)e3;
      self[0x1d] = 1;
      D32(self, 0x14) = v47 - left;
      D32(self, 0x18) = left;
      return 1;
    }
    D32(self, 0x5b) = left;
    D32(self, 0x26 + D32(self, 0x3b) * 4) |= 1;
  }
  if (D32(self, 0x5f) != 0) {
    do {
      D32(self, 0x1e + D32(self, 0x3b) * 4) = 1;
      D32(self, 0x26 + D32(self, 0x3b) * 4) |= 2;
      D32(self, 0x5f)--;
      D32(self, 0x3b)++;
    } while (D32(self, 0x5f) != 0);
  }
  if (D32(self, 0x3b) == D32(self, 0x37)) D32(self, 0x3b) = 0;
  if (D32(self, 0x5f) == 0) self[0x1c] = 1;
  return 1;
}
PCREG(54e450, fn54e450);
