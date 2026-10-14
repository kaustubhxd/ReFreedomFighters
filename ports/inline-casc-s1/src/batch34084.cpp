// batch34084.cpp - escalation batch 34084: 0x497610 (scaled index), 0x52d510 / 0x52d380 (record writers), 0x64b0b0 (flag refresh), 0x62df30 (event filter), 0x4e5de0 (bit-field read).
#include "ff.h"

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr16(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; }
static u32 rd16(u8 *p) { return p[0] | p[1] << 8; }

// 0x497610, thiscall(a) ret 4: 0 when [a+0x3c] has 0x8000000. Else d = a - [[this+0x14]+4] (signed); returns unaligned dword [this+0x5d] + 4 * (d / 112 - [this+0x28] / 112 (unsigned)).
static u32 THISCALL fn497610(u8 *self, u8 *a) {
  if (*(u32 *)(a + 0x3c) & 0x8000000) return 0;
  s32 d = (s32)((u32)a - *(u32 *)(*(u8 **)(self + 0x14) + 4));
  s32 q = d / 112;
  u32 u = *(u32 *)(self + 0x28) / 112;
  return rd32(self + 0x5d) + (u32)(q - (s32)u) * 4;
}
PCREG(497610, fn497610);

// 0x52d510, thiscall(a, b, c, d, e) ret 0x14, bool: k = [a+0x38] - e - 1 must equal [this+8]. Then o = [this+4]: byte [o+0xa] = 1, word [o] = word [b], byte [o+9] = k, words [o+2], [o+4], [o+6] = words c[0], c[2], c[4] (at byte offsets 0, 4, 8).
static bool THISCALL fn52d510(u8 *self, u8 *a, u16 *b, u16 *c, u32 d, u32 e) {
  (void)d;
  u32 k = *(u32 *)(a + 0x38) - e - 1;
  if (k != *(u32 *)(self + 8)) return false;
  u8 *o = *(u8 **)(self + 4);
  o[0xa] = 1;
  o = *(u8 **)(self + 4);
  wr16(o, b[0]);
  o = *(u8 **)(self + 4);
  o[9] = k;
  o = *(u8 **)(self + 4);
  wr16(o + 2, rd16((u8 *)c));
  o = *(u8 **)(self + 4);
  wr16(o + 4, rd16((u8 *)c + 4));
  o = *(u8 **)(self + 4);
  wr16(o + 6, rd16((u8 *)c + 8));
  return true;
}
PCREG(52d510, fn52d510);

// 0x52d380, thiscall(a, b, x2, d, x4, g, h) ret 0x1c, bool: k = [a+0x38] - g - 1 must equal [this+8] and [b] must be non-zero. Then o = [this+4]: byte [o+0xa] = 3, word [o] = low word of h, byte [o+9] = k, words [o+2], [o+4], [o+6] = words at d+0, d+4, d+8.
static bool THISCALL fn52d380(u8 *self, u8 *a, u32 *b, u32 x2, u8 *d, u32 x4, u32 g, u32 h) {
  (void)x2; (void)x4;
  u32 k = *(u32 *)(a + 0x38) - g - 1;
  if (k != *(u32 *)(self + 8)) return false;
  if (*b == 0) return false;
  u8 *o = *(u8 **)(self + 4);
  o[0xa] = 3;
  o = *(u8 **)(self + 4);
  wr16(o, h);
  o = *(u8 **)(self + 4);
  o[9] = k;
  o = *(u8 **)(self + 4);
  wr16(o + 2, rd16(d));
  o = *(u8 **)(self + 4);
  wr16(o + 4, rd16(d + 4));
  o = *(u8 **)(self + 4);
  wr16(o + 6, rd16(d + 8));
  return true;
}
PCREG(52d380, fn52d380);

// 0x64b0b0, thiscall, plain ret: [this+0x24] = 0; for each entry e of the unaligned dword array at this+0x101c5 (count: unaligned dword [this+0x101c1], re-read, compared with !=): i = word [e+0x12]; dword [this+8i+0x28] &= 0x87ffffff;
// y = [[e+0x14]+0x20]; bl = y ? byte [y+0x70] : 0; dword [this+8i+0x28] |= bl << 27.
static void THISCALL fn64b0b0(u8 *self) {
  *(u32 *)(self + 0x24) = 0;
  u8 *p = self + 0x101c5;
  if (p == self + 0x101c5 + rd32(self + 0x101c1) * 4) return;
  do {
    u8 *e = (u8 *)rd32(p);
    u32 i = rd16(e + 0x12);
    *(u32 *)(self + i * 8 + 0x28) &= 0x87ffffff;
    u8 *y = *(u8 **)(*(u8 **)(e + 0x14) + 0x20);
    u8 bl = y ? y[0x70] : 0;
    i = rd16(e + 0x12);
    p += 4;
    *(u32 *)(self + i * 8 + 0x28) |= (u32)bl << 27;
  } while (p != self + 0x101c5 + rd32(self + 0x101c1) * 4);
}
PCREG(64b0b0, fn64b0b0);

// 0x62df30, cdecl(a, id): id 0xf returns 0; 0x11 sets [a] = ([a+0xc] != 0 ? 0x62dc60 : 0x62dbb0) and returns 0x11; 0x1b sets [a] = 0x62cf90 and returns 0x10; else when [a+0xc] is zero and id is 0x1c returns 0x34; else [a] = 0x51f230, returns -1.
static s32 fn62df30(u32 *a, u32 id) {
  if (id == 0xf) return 0;
  if (id == 0x11) { a[0] = a[3] != 0 ? 0x62dc60 : 0x62dbb0; return 0x11; }
  if (id == 0x1b) { a[0] = 0x62cf90; return 0x10; }
  if (a[3] == 0 && id == 0x1c) return 0x34;
  a[0] = 0x51f230;
  return -1;
}
PCREG(62df30, fn62df30);

// 0x4e5de0, thiscall(a, b) ret 8: 0 when b is 0. Else p = [this+0x10] + a; w = signed byte [p]; off = (b-1)*w; reads the 24 bits at p + (off >> 3) + 1 (big endian), shifts left 8 and arithmetic-shifts right by (32 - (off & 7) - w) (count mod 32) and
// masks with (1 << (w mod 32)) - 1.
static u32 THISCALL fn4e5de0(u8 *self, u32 a, u32 b) {
  if (b == 0) return 0;
  u8 *p = *(u8 **)(self + 0x10) + a;
  s32 w = (s8)p[0];
  s32 off = (s32)(b - 1) * w;
  u32 bit = off & 7;
  u8 *q = p + (off >> 3);
  u32 v = ((u32)q[1] << 16) | ((u32)q[2] << 8) | q[3];
  u32 cnt = (u32)(0x20 - (s32)bit - w) & 31;
  s32 r = (s32)(v << 8) >> cnt;
  u32 mask = (1u << ((u32)w & 31)) - 1;
  return (u32)r & mask;
}
PCREG(4e5de0, fn4e5de0);
