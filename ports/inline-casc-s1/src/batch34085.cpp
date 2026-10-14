// batch34085.cpp - escalation batch 34085: 0x6238e0 (bounded word copy), 0x5fb210 (tree successor), 0x638ea0 (bit mask setup), 0x57f820 (constructor), 0x5ec5f0 (set vector), 0x61bac0 (string table lookup).
#include "ff.h"

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x6238e0, cdecl(a, psrc, srcend, pdst, dstend): copies 16-bit words from *psrc towards srcend into *pdst up to dstend, advancing both cursors. When the source is longer than the room (dstend - *pdst & ~1) and the byte
// before srcend has the form 0xd8..0xdf (high surrogate half), srcend is pulled back by 2.
static void fn6238e0(u32 a, u8 **psrc, u8 *srcend, u8 **pdst, u8 *dstend) {
  (void)a;
  u8 *end = srcend;
  s32 room = (s32)((u32)dstend - (u32)*pdst) & ~1;
  s32 have = (s32)(end - *psrc);
  if (have > room && (end[-1] & 0xf8) == 0xd8) end -= 2;
  if (*psrc == end) return;
  for (;;) {
    u8 *d = *pdst;
    if (d == dstend) return;
    u8 *s = *psrc;
    d[0] = s[0];
    d[1] = s[1];
    *pdst += 2;
    *psrc += 2;
    if (*psrc == end) return;
  }
}
PCREG(6238e0, fn6238e0);

// 0x5fb210, thiscall(out) ret 8 (two stack dwords, the second unused), returns out: tree iterator successor with fields parent +1, left +5, right +9 (unaligned). *out = [this]; moves [this] to the next node: the leftmost of the
// right subtree, or else up the parents while the node is a right child.
static u32 THISCALL fn5fb210(u8 *self, u32 *out, u32 unused) {
  (void)unused;
  u8 *n = *(u8 **)self;
  *out = (u32)n;
  u8 *r = (u8 *)rd32(n + 9);
  if (r) {
    *(u8 **)self = r;
    while (rd32(r + 5) != 0) {
      r = (u8 *)rd32(r + 5);
      *(u8 **)self = r;
    }
    return (u32)out;
  }
  u8 *p = (u8 *)rd32(n + 1);
  if (n == (u8 *)rd32(p + 9)) {
    u8 *c;
    do {
      c = p;
      *(u8 **)self = p;
      p = (u8 *)rd32(p + 1);
    } while (c == (u8 *)rd32(p + 9));
  }
  u8 *cur = *(u8 **)self;
  if ((u8 *)rd32(cur + 9) != p) *(u8 **)self = p;
  return (u32)out;
}
PCREG(5fb210, fn5fb210);

// 0x638ea0, thiscall(a, b, c) ret 0xc, returns the last bit value: stores a, b, c at +0, +4, +8, clears +0xc..+0x20, then for k = 1, 2, 4, ... (while a bit was placed in the last round) ORs the next bit into +0xc / +0x10 / +0x14
// for every limit (a, b, c) that k is below (unsigned).
static u32 THISCALL fn638ea0(u32 *self, u32 a, u32 b, u32 c) {
  u32 k = 1, bit = 1, mark;
  self[2] = c;
  self[0] = a;
  self[1] = b;
  self[3] = 0; self[4] = 0; self[5] = 0; self[6] = 0; self[7] = 0; self[8] = 0;
  do {
    mark = 0;
    if (k < a) { self[3] |= bit; bit += bit; mark = bit; }
    if (k < b) { self[4] |= bit; bit += bit; mark = bit; }
    if (k < c) { self[5] |= bit; bit += bit; mark = bit; }
    k += k;
  } while (mark != 0);
  return bit;
}
PCREG(638ea0, fn638ea0);

// 0x57f820, thiscall, plain ret, returns this: sets a record of five-dword groups (K = 0x6aaec8 for the first five dwords, then four zero dwords and a zero byte, repeated at +0x29, +0x52 and +0x7b, with the last group
// followed by 0x20 at +0xa4 and 0x19 at +0xa8); all fields unaligned.
static u32 THISCALL fn57f820(u8 *self) {
  static const u16 K[] = {0x00, 0x04, 0x08, 0x0c, 0x10, 0x29, 0x2d, 0x31, 0x35, 0x39, 0x52, 0x56, 0x5a, 0x5e, 0x62, 0x7b, 0x7f, 0x83, 0x87, 0x8b};
  static const u16 Z[] = {0x14, 0x18, 0x1c, 0x20, 0x3d, 0x41, 0x45, 0x49, 0x66, 0x6a, 0x6e, 0x72, 0x8f, 0x93, 0x97, 0x9b};
  static const u16 B[] = {0x28, 0x51, 0x7a, 0xa3};
  for (unsigned i = 0; i < sizeof K / sizeof K[0]; i++) wr32(self + K[i], 0x6aaec8);
  for (unsigned i = 0; i < sizeof Z / sizeof Z[0]; i++) wr32(self + Z[i], 0);
  for (unsigned i = 0; i < sizeof B / sizeof B[0]; i++) self[B[i]] = 0;
  wr32(self + 0xa4, 0x20);
  wr32(self + 0xa8, 0x19);
  return (u32)self;
}
PCREG(57f820, fn57f820);

// 0x5ec5f0, thiscall(p, idx) ret 8: with idx == -1 sets the first three dwords of every 0x28-byte entry (count: unaligned dword [this+0x3e], re-read each round) of the array [[this+0x3a]+4] to p[0..2]; otherwise only entry idx
// (stride 5*8 bytes).
static void THISCALL fn5ec5f0(u8 *self, u32 *p, s32 idx) {
  if (idx == -1) {
    u32 i = 0;
    if (rd32(self + 0x3e) == 0) return;
    do {
      u8 *arr = (u8 *)rd32(*(u8 **)(self + 0x3a) + 4);
      u32 off = i * 0x28;
      i++;
      *(u32 *)(arr + off) = p[0];
      *(u32 *)(arr + off + 4) = p[1];
      *(u32 *)(arr + off + 8) = p[2];
    } while (i < rd32(self + 0x3e));
  } else {
    u8 *arr = (u8 *)rd32(*(u8 **)(self + 0x3a) + 4);
    u32 off = (u32)idx * 40;
    *(u32 *)(arr + off) = p[0];
    *(u32 *)(arr + off + 4) = p[1];
    *(u32 *)(arr + off + 8) = p[2];
  }
}
PCREG(5ec5f0, fn5ec5f0);

// 0x61bac0, stdcall(table, key) ret 8: table of (name pointer, value) pairs ending with a null name; returns the value of the first pair whose name equals key (strcmp), else 0.
static u32 STDCALL fn61bac0(u32 *table, const u8 *key) {
  for (u32 i = 0; table[i] != 0; i += 2) {
    const u8 *a = (const u8 *)table[i];
    const u8 *b = key;
    while (*a == *b && *a) { a++; b++; }
    if (*a == *b) return table[i + 1];
  }
  return 0;
}
PCREG(61bac0, fn61bac0);
