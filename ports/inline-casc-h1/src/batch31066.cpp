// batch31066.cpp - Sonnet h1: array index lookup, copy constructors, bit gather, list remove, lowercase, range lookup, UTF-16 byte-swap copy.
#include "ff.h"

// 0x589f70 thiscall ret 4: index of pointer p within the 0xf4-byte record array at this+0xd91 (count at +0xd8d), else -1.
THISCALL int fn589f70(u8 *self, u8 *p) {
  u8 *base = self + 0xd91;
  if (!p) return -1;
  u8 *end = self + 0xd91 + *(int *)(self + 0xd8d) * 0xf4;
  if (base == end) return -1;
  int i = 0;
  for (u8 *q = base; q != end; q += 0xf4, i++)
    if (q == p) return i;
  return -1;
}
PCREG(589f70, fn589f70);

// 0x4febf0 thiscall ret 4: copy constructor, vtable 0x68e948.
THISCALL u8 *fn4febf0(u8 *self, u8 *src) {
  *(u32 *)self = 0x68e948;
  *(u32 *)(self + 4) = *(u32 *)(src + 4);
  *(u32 *)(self + 8) = *(u32 *)(src + 8);
  *(u32 *)(self + 0xc) = *(u32 *)(src + 0xc);
  for (int i = 0; i < 0x45; i++) *(u32 *)(self + 0x10 + 4 * i) = *(u32 *)(src + 0x10 + 4 * i);
  for (int o = 0x124; o <= 0x138; o += 4) *(u32 *)(self + o) = *(u32 *)(src + o);
  return self;
}
PCREG(4febf0, fn4febf0);

// 0x5e9070 thiscall ret 4: copy count [0x48], that many 8-byte pairs from +0x4c, and the dword at +0x44c.
THISCALL void fn5e9070(u8 *self, u8 *src) {
  int n = *(int *)(src + 0x48);
  *(int *)(self + 0x48) = n;
  for (int i = 0; i < n; i++) {
    *(u32 *)(self + 0x4c + 8 * i) = *(u32 *)(src + 0x4c + 8 * i);
    *(u32 *)(self + 0x50 + 8 * i) = *(u32 *)(src + 0x50 + 8 * i);
  }
  *(u32 *)(self + 0x44c) = *(u32 *)(src + 0x44c);
}
PCREG(5e9070, fn5e9070);

// 0x5308e0 thiscall ret 0xc (out, buf, k): gather bit 'shift' of n successive dwords stepping down by 8 bytes into *out (MSB first).
THISCALL void fn5308e0(u8 *self, u32 *out, u32 *buf, int k) {
  *out = 0;
  int n = *(int *)(self + 0x48);
  int bitpos = n * 64 + (k - 0x40);
  u32 *p = buf + (bitpos >> 5);
  int shift = bitpos & 0x1f;
  for (int i = n - 1; i >= 0; i--) {
    int v = (int)*p;
    p -= 2;
    *out = (*out * 2) | (u32)((v >> shift) & 1);
  }
}
PCREG(5308e0, fn5308e0);

// 0x597e00 thiscall ret 4: remove arg from the list at this+0x1dae (count +0x1fae) by moving the last entry in; fix cursor at +0x1fb2.
THISCALL void fn597e00(u8 *self, u32 v) {
  u32 n = *(u32 *)(self + 0x1fae);
  u32 *list = (u32 *)(self + 0x1dae);
  for (u32 i = 0; i < n; i++) {
    if (list[i] == v) {
      *(u32 *)(self + 0x1fae) = n - 1;
      list[i] = list[n - 1];
      list[n - 1] = 0;
      u32 c = *(u32 *)(self + 0x1fae);
      if (*(u32 *)(self + 0x1fb2) == c) *(u32 *)(self + 0x1fb2) = c - 1;
      if (*(int *)(self + 0x1fb2) < 0) *(u32 *)(self + 0x1fb2) = 0;
      return;
    }
  }
}
PCREG(597e00, fn597e00);

// 0x4cc690 thiscall: lowercase A-Z in place in the C string *self.
THISCALL void fn4cc690(u8 **self) {
  u8 *s = *self;
  for (u32 i = 0; s[i]; i++)
    if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 0x20;
}
PCREG(4cc690, fn4cc690);

// 0x57d830 thiscall-style (value in ECX): values with high bits are returned unchanged; else find the 0x10-byte range entry
// (start [0], length [0xc]) of the table at global+0x190b that contains it and return v + (index << 16) - start; -1 when no table.
THISCALL u32 fn57d830(u32 v) {
  if (v & 0xffff0000) return v;
  u8 *p = *(u8 **)(*(u8 **)0x70039c + 0x190b);
  if (!p) return (u32)-1;
  for (u32 i = 0;; i++, p += 0x10) {
    int start = *(int *)p;
    if (start > (int)v) continue;
    if (*(int *)(p + 0xc) + start > (int)v) return v + ((i << 16) - start);
  }
}
PCREG(57d830, fn57d830);

// 0x623b80 cdecl (unused, u8 **src, u8 *srcEnd, u8 **dst, u8 *dstEnd): copy 16-bit units byte-swapped, not splitting a trailing surrogate.
extern "C" void fn623b80(u32, u8 **src, u8 *srcEnd, u8 **dst, u8 *dstEnd) {
  int room = (int)(dstEnd - *dst) & ~1;
  u8 *s0 = *src;
  if ((int)(srcEnd - s0) > room) {
    if ((srcEnd[-2] & 0xf8) == 0xd8) srcEnd -= 2;
  }
  if (s0 == srcEnd) return;
  while (*dst != dstEnd) {
    u8 *s = *src;
    *(u16 *)*dst = (u16)((s[0] << 8) | s[1]);
    *dst += 2;
    *src += 2;
    if (*src == srcEnd) break;
  }
}
PCREG(623b80, fn623b80);
