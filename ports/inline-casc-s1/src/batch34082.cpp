// batch34082.cpp - escalation batch 34082: event filters 0x62cf90 / 0x62d510, list reset 0x531220, prefix match 0x6228a0, mode switch 0x54e630, header check 0x627420.
#include "ff.h"

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static void wr16(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; }
static u32 rd16(u8 *p) { return p[0] | p[1] << 8; }

// 0x62cf90, cdecl(a, id): id 0xf returns 0; id 0x11 sets [a] = ([a+0xc] != 0 ? 0x62dc60 : 0x62dbb0) and returns 0; otherwise when [a+0xc] is zero and id is 0x1c returns 0x34; else [a] = 0x51f230, returns -1.
static s32 fn62cf90(u32 *a, u32 id) {
  if (id == 0xf) return 0;
  if (id == 0x11) {
    a[0] = a[3] != 0 ? 0x62dc60 : 0x62dbb0;
    return 0;
  }
  if (a[3] == 0 && id == 0x1c) return 0x34;
  a[0] = 0x51f230;
  return -1;
}
PCREG(62cf90, fn62cf90);

// 0x62d510, cdecl(a, id): id 0xf returns 0; id 0x12 or 0x29 sets [a] = 0x62d560 and returns 0x2e; otherwise when [a+0xc] is zero and id is 0x1c returns 0x34; else [a] = 0x51f230, returns -1.
static s32 fn62d510(u32 *a, u32 id) {
  if (id == 0xf) return 0;
  if (id == 0x12 || id == 0x29) {
    a[0] = 0x62d560;
    return 0x2e;
  }
  if (a[3] == 0 && id == 0x1c) return 0x34;
  a[0] = 0x51f230;
  return -1;
}
PCREG(62d510, fn62d510);

// 0x531220, thiscall, plain ret: zeroes the words at p+2+0xc*i and p+0xa+0xc*i for i < word [this+0x58] where p = unaligned dword [this+0x5a]; then the word at q+2+0x16*i for i < word [this+0x52] where q = [this+0x54].
static void THISCALL fn531220(u8 *self) {
  u8 *p = (u8 *)rd32(self + 0x5a);
  u32 n = rd16(self + 0x58);
  for (u32 i = 0; i < n; i++) {
    wr16(p + 2 + 0xc * i, 0);
    wr16(p + 0xa + 0xc * i, 0);
  }
  u8 *q = (u8 *)rd32(self + 0x54);
  n = rd16(self + 0x52);
  for (u32 i = 0; i < n; i++) wr16(q + 2 + 0x16 * i, 0);
}
PCREG(531220, fn531220);

// 0x6228a0, cdecl(a, p, end, s), bool: s (zero-terminated) matches p byte for byte without p reaching end first, and p ends exactly at end.
static u32 fn6228a0(u32 a, u8 *p, u8 *end, u8 *s) {
  (void)a;
  u8 c = *s;
  u32 i = 0;
  if (c) {
    for (;;) {
      if (p == end) return 0;
      if (*p != c) return 0;
      c = s[i + 1];
      p++;
      i++;
      if (!c) break;
    }
  }
  return p == end;
}
PCREG(6228a0, fn6228a0);

// 0x54e630, thiscall(a) ret 4: word [this+0x1c] = 0x100. a == 1: i = dword [this+0x3b]; dword [this+0x26+4i] = 0; dword [this+0x5f] = 1; [this+8] = 1; byte [this+0x59] = 0. a == 2: while i < [this+0x37] (signed, re-read
// every time): dword [this+0x26+4i] = 0; then [this+0x5f] = [this+0x37]; [this+8] = 2; byte [this+0x59] = 0.
static void THISCALL fn54e630(u8 *self, u32 a) {
  wr16(self + 0x1c, 0x100);
  if (a == 1) {
    u32 i = rd32(self + 0x3b);
    wr32(self + i * 4 + 0x26, 0);
    wr32(self + 0x5f, 1);
    wr32(self + 8, 1);
    self[0x59] = 0;
  } else if (a == 2) {
    s32 i = 0;
    if ((s32)rd32(self + 0x37) > 0) {
      u8 *e = self + 0x26;
      do {
        wr32(e, 0);
        e += 4;
        i++;
      } while (i < (s32)rd32(self + 0x37));
    }
    wr32(self + 0x5f, rd32(self + 0x37));
    wr32(self + 8, 2);
    self[0x59] = 0;
  }
}
PCREG(54e630, fn54e630);

// 0x627420, cdecl(a, p, end, out): -1 when end - p < 12. Else compares six (0, byte) pairs at p against the exe table at 0x6be5b0; *out = the pointer where it stopped; returns 8 when all six pairs match, else 0.
static s32 fn627420(u32 a, u8 *p, u8 *end, u8 **out) {
  (void)a;
  if ((s32)(end - p) < 12) return -1;
  for (u32 i = 0; i < 6; i++) {
    if (p[0] != 0 || p[1] != G(u8, 0x6be5b0 + i)) {
      *out = p;
      return 0;
    }
    p += 2;
  }
  *out = p;
  return 8;
}
PCREG(627420, fn627420);
