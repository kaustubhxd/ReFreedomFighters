// batch34095.cpp - escalation batch 34095: event filters 0x62d110 / 0x62d8f0 / 0x62db10 / 0x62dee0, lookup 0x658dc0, bit table test 0x624650, range chain 0x5ffe20.
#include "ff.h"

static s32 filter(u32 *a, u32 id, u32 X, s32 R) {
  if (id == 0xf) return 0;
  if (id == 0x1b) { a[0] = X; return R; }
  if (a[3] == 0 && id == 0x1c) return 0x34;
  a[0] = 0x51f230;
  return -1;
}
// cdecl(a, id) event filters: id 0xf returns 0; id 0x1b stores the handler and returns the code; id 0x1c with [a+0xc] zero returns 0x34; otherwise stores 0x51f230 and returns -1.
static s32 fn62d110(u32 *a, u32 id) { return filter(a, id, 0x62d160, 5); }
static s32 fn62d8f0(u32 *a, u32 id) { return filter(a, id, 0x62d940, 0xc); }
static s32 fn62db10(u32 *a, u32 id) { return filter(a, id, 0x62db60, 0xc); }
static s32 fn62dee0(u32 *a, u32 id) { return filter(a, id, 0x62cf90, 0x10); }
PCREG(62d110, fn62d110);
PCREG(62d8f0, fn62d8f0);
PCREG(62db10, fn62db10);
PCREG(62dee0, fn62dee0);

// 0x658dc0, thiscall(a) ret 4: n = byte [this+0x3d]; tbl = [this+0x40]; the value dword at tbl+8i of the first of the n 8-byte entries whose key dword (tbl+8i+4) equals a; 0 when none.
static u32 THISCALL fn658dc0(u8 *self, u32 a) {
  u32 n = self[0x3d];
  u32 *tbl = *(u32 **)(self + 0x40);
  for (u32 i = 0; i < n; i++)
    if (tbl[2 * i + 1] == a) return tbl[2 * i];
  return 0;
}
PCREG(658dc0, fn658dc0);

// 0x624650, cdecl(a, p), returns the masked bit: i = (p[1] & 3) + 4 * byte[0x6bfc20 + 16 * (p[0] & 0xf) + ((p[1] >> 2) & 0xf)]; j = 2 * i + ((p[2] >> 5) & 1); returns dword[0x6bf720 + 4j] & (1 << (p[2] & 0x1f)).
static u32 fn624650(u32 a, const u8 *p) {
  (void)a;
  u32 t = G(u8, 0x6bfc20 + 16 * (p[0] & 0xf) + ((p[1] >> 2) & 0xf));
  u32 i = (p[1] & 3) + t * 4;
  u32 j = 2 * i + ((p[2] >> 5) & 1);
  return G(u32, 0x6bf720 + 4 * j) & (1u << (p[2] & 0x1f));
}
PCREG(624650, fn624650);

// 0x5ffe20, thiscall(a) ret 4: walks the chain this, [this+0x9c], ...: a node with a non-zero count [n+0x12e] and start [n+0x12a] <= a < start + count (unsigned) returns [n+0x132] + 28 * (a - start); 0 at the end of the chain.
static u32 THISCALL fn5ffe20(u8 *self, u32 a) {
  u8 *n = self;
  for (;;) {
    u32 cnt = *(u32 *)(n + 0x12e);
    if (cnt != 0) {
      u32 start = *(u32 *)(n + 0x12a);
      if (a >= start && a < start + cnt) return *(u32 *)(n + 0x132) + 28 * (a - start);
    }
    n = *(u8 **)(n + 0x9c);
    if (!n) return 0;
  }
}
PCREG(5ffe20, fn5ffe20);
