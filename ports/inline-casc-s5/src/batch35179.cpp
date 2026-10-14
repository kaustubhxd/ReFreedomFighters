// batch35179.cpp - cascade s5 batch 35179: 0x61bf10 (GUESS advance a decoder window by n bytes and call its refill callback).
#include "ff.h"

typedef u32 (*cb1_t)(u8 *, u32, u32, u32 *);
typedef void (*cb2_t)(u8 *, u32, u32, u8 *);

// 0x61bf10, cdecl(s, n, flag), returns 1 or 0. a = s[0x18]; s[0x1c] += n; s[0x24] += n; b = s[0x1c]; p = flag ? 0 : &s[0x18]; s[0x120] = a; s[0x28] = b; r = s[0x110](s, a, b, p) (cdecl, callback pointer in the
// struct); s[0x114] = r. r == 0: when flag == 0 the callback pointer at [s[0x8c] + 0x34](s[0x8c], s[0x120], s[0x18], &s[0x224]) is called; returns 1. Otherwise s[0x11c] = s[0x118]; s[0x110] = 0x61f590; returns 0.
static u32 fn61bf10(u8 *s, u32 n, u32 flag) {
  u32 a = *(u32 *)(s + 0x18);
  *(u32 *)(s + 0x1c) += n;
  *(u32 *)(s + 0x24) += n;
  u32 b = *(u32 *)(s + 0x1c);
  u32 *p = flag == 0 ? (u32 *)(s + 0x18) : 0;
  *(u32 *)(s + 0x120) = a;
  cb1_t f = *(cb1_t *)(s + 0x110);
  *(u32 *)(s + 0x28) = b;
  u32 r = f(s, a, b, p);
  *(u32 *)(s + 0x114) = r;
  if (r == 0) {
    if (flag == 0) {
      u8 *o = *(u8 **)(s + 0x8c);
      (*(cb2_t *)(o + 0x34))(o, *(u32 *)(s + 0x120), *(u32 *)(s + 0x18), s + 0x224);
    }
    return 1;
  }
  *(u32 *)(s + 0x11c) = *(u32 *)(s + 0x118);
  *(u32 *)(s + 0x110) = 0x61f590;
  return 0;
}
PCREG(61bf10, fn61bf10);
