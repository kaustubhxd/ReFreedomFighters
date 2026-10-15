// batch32075.cpp - cascade h2 (Sonnet): 0x4d0840 (split a free block and mark it used), 0x436b30 (init record with string copy).
#include "ff.h"

extern "C" void THISCALL ext_4cfc70(u8 *self, u8 *blk);              // thiscall ret 4
extern "C" void THISCALL ext_4d09b0(u8 *self, u8 *blk, u32 n);       // thiscall ret 8
extern "C" u8 *ext_41e290(u32 n);                                    // alloc, cdecl
extern "C" void THISCALL ext_439c20(u8 *self, u32 v);                // thiscall ret 4

static inline void w4(u8 *p, u32 v) {
  p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24;
}

// 0x4d0840, thiscall(blk, n) ret 8, returns the block used: m = [blk+8]; when m - n > 0x18 (unsigned) the block is split: [blk+8] = m-n-0x10,
// new block s = blk + (m-n) with [s+8] = -n, [s+0xc] = m-n-0x10, 0x4cfc70(this, blk); eax = n, edi = -n, [s+n+0x1c] = -n; else edi = -m and [blk+m+0x1c] = -m.
// Then [b+8] = edi; [this] += eax+0x10; byte [this+0x1e9] = 0; 0x4d09b0(this, b, eax); [b+4] = [this+0x821c].
static u8 *THISCALL fn4d0840(u8 *self, u8 *blk, u32 n) {
  u32 m = *(u32 *)(blk + 8);
  u32 ecx = m - n;
  u8 *b;
  u32 eax, edi;
  if (ecx > 0x18) {
    u32 nw = ecx - 0x10;
    u8 *s = blk + ecx;
    *(u32 *)(blk + 8) = nw;
    *(u32 *)(s + 8) = -n;
    *(u32 *)(s + 0xc) = nw;
    ext_4cfc70(self, blk);
    eax = n;
    edi = -n;
    *(u32 *)(s + eax + 0x1c) = edi;
    b = s;
  } else {
    eax = m;
    edi = -m;
    *(u32 *)(blk + eax + 0x1c) = edi;
    b = blk;
  }
  *(u32 *)(b + 8) = edi;
  *(u32 *)self += eax + 0x10;
  self[0x1e9] = 0;
  ext_4d09b0(self, b, eax);
  *(u32 *)(b + 4) = *(u32 *)(self + 0x821c);
  return b;
}
PCREG(4d0840, fn4d0840);

// 0x436b30, thiscall(a, p) ret 8, returns this: [0]=2; [8] = a ? a+4 : 0; [0x16]=[0xd]=[4]=[0x11]=0, byte [0x15]=0; when s = [p] is set, [4] = copy of s
// (strlen+1 bytes from 0x41e290); then 0x439c20(this, [p+0x10]).
static u8 *THISCALL fn436b30(u8 *self, u32 a, u32 *p) {
  *(u32 *)self = 2;
  w4(self + 0x16, 0);
  *(u32 *)(self + 8) = a ? a + 4 : 0;
  w4(self + 0xd, 0);
  *(u32 *)(self + 4) = 0;
  w4(self + 0x11, 0);
  self[0x15] = 0;
  const u8 *s = (const u8 *)p[0];
  if (s) {
    const u8 *e = s;
    while (*e++) {}
    u8 *d = ext_41e290((u32)(e - s));
    *(u8 **)(self + 4) = d;
    u8 c;
    do { c = *s++; *d++ = c; } while (c);
  }
  ext_439c20(self, p[4]);
  return self;
}
PCREG(436b30, fn436b30);
