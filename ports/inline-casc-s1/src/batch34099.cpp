// batch34099.cpp - escalation batch 34099: 0x5ed3d0, 0x628c10, 0x54a0e0, 0x5b58a0, 0x628f30, 0x537270, 0x622270.
#include "ff.h"

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static u32 rd16(u8 *p) { return p[0] | p[1] << 8; }

// 0x5ed3d0, thiscall(a, b, c) ret 0xc: objects are taken from the pointer array [[this+0xcb], [this+0xcf]) (unaligned) when c == -1, else the single entry c. For each object: byte [this+0xa6] = 1 unless
// ([obj+8] == a and sign-extended word [obj+0xe] == b); then [obj+8] = a and word [obj+0xe] = low word of b.
static void THISCALL fn5ed3d0(u8 *self, u32 a, u32 b, s32 c) {
  if (c == -1) {
    u8 *p = (u8 *)rd32(self + 0xcb);
    if (p == (u8 *)rd32(self + 0xcf)) return;
    do {
      u8 *o = *(u8 **)p;
      if (!(*(u32 *)(o + 8) == a && (s32)(s16)rd16(o + 0xe) == (s32)b)) self[0xa6] = 1;
      p += 4;
      *(u32 *)(o + 8) = a;
      o[0xe] = b; o[0xf] = b >> 8;
    } while (p != (u8 *)rd32(self + 0xcf));
    return;
  }
  u8 *o = *(u8 **)((u8 *)rd32(self + 0xcb) + c * 4);
  if (!(*(u32 *)(o + 8) == a && (s32)(s16)rd16(o + 0xe) == (s32)b)) self[0xa6] = 1;
  *(u32 *)(o + 8) = a;
  o[0xe] = b; o[0xf] = b >> 8;
}
PCREG(5ed3d0, fn5ed3d0);

// 0x628c10, cdecl(s): 6 for a null s; else the index (0..5) of the first string of the exe table at 0x6f4440 equal to s ignoring ASCII case; -1 when none.
static s32 fn628c10(const u8 *s) {
  if (!s) return 6;
  for (s32 i = 0; i < 6; i++) {
    const u8 *t = G(const u8 *, 0x6f4440 + 4 * i);
    const u8 *a = s;
    for (;;) {
      u8 x = *a++;
      u8 y = *t++;
      if ((u8)(x - 0x61) <= 0x19) x += 0xe0;
      if ((u8)(y - 0x61) <= 0x19) y += 0xe0;
      if (x != y) break;
      if (x == 0) return i;
    }
  }
  return -1;
}
PCREG(628c10, fn628c10);

// 0x54a0e0, stdcall(dst, src) ret 8, returns [src+0x5c]: copies 22 dwords: dst 0..0x28 <- src 8..0x30, dst 0x38 <- src 0x34, dst 0x3c <- src 0x38, dst 0x4c..0x6c <- src 0x3c..0x5c.
static u32 STDCALL fn54a0e0(u32 *dst, u32 *src) {
  static const u8 to[] = {0x00, 0x04, 0x08, 0x0c, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x28, 0x38, 0x3c, 0x4c, 0x50, 0x54, 0x58, 0x5c, 0x60, 0x64, 0x68, 0x6c};
  static const u8 from[] = {0x08, 0x0c, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x28, 0x2c, 0x30, 0x34, 0x38, 0x3c, 0x40, 0x44, 0x48, 0x4c, 0x50, 0x54, 0x58, 0x5c};
  u32 v = 0;
  for (unsigned i = 0; i < sizeof to; i++) {
    v = *(u32 *)((u8 *)src + from[i]);
    *(u32 *)((u8 *)dst + to[i]) = v;
  }
  return v;
}
PCREG(54a0e0, fn54a0e0);

// 0x5b58a0, thiscall(out1, out2, flag, val) ret 0x10: *out1 = *out2 = 0; byte [this+2] = 0. flag set: byte [this] == 0: word [this] = 1, unaligned dword [this+5] = val; else when byte [this+1] == 0 and [this+9] + [this+5] < val:
// byte [this+1] = 1 and *out2 = 1. flag clear: when byte [this] != 0: byte [this+2] = 1, *out1 = 1 when [this+9] + [this+5] >= val, byte [this] = 0. Finally when byte [this+3] != 0: both outputs cleared and byte [this+3] = 0 unless byte [this+4] == byte [this].
static void THISCALL fn5b58a0(u8 *self, u8 *out1, u8 *out2, u32 flag, s32 val) {
  *out1 = 0;
  *out2 = 0;
  self[2] = 0;
  if ((u8)flag != 0) {
    if (self[0] == 0) {
      self[0] = 1; self[1] = 0;
      wr32(self + 5, val);
    } else if (self[1] == 0) {
      if ((s32)(rd32(self + 9) + rd32(self + 5)) < val) {
        self[1] = 1;
        *out2 = 1;
      }
    }
  } else if (self[0] != 0) {
    s32 s = (s32)(rd32(self + 9) + rd32(self + 5));
    self[2] = 1;
    if (!(s < val)) *out1 = 1;
    self[0] = 0;
  }
  if (self[3] != 0) {
    *out1 = 0;
    *out2 = 0;
    if (self[4] != self[0]) self[3] = 0;
  }
}
PCREG(5b58a0, fn5b58a0);

// 0x628f30, cdecl(a, p, end, out), returns 0 or 1: *out = 0xb. Matches the six bytes of a "X\0M\0L\0" style token (case-insensitive letters X, M, L at p[0], p[2], p[4], zero bytes at p[1], p[3], p[5]); returns 0 when matched,
// except an all-lowercase token ('x' 'm' 'l' without any capital) sets *out = 0xc and returns 1; every mismatch returns 1.
static u32 fn628f30(u32 a, const u8 *p, const u8 *end, u32 *out) {
  (void)a;
  s32 len = (s32)(end - p);
  u32 caps = 0;
  *out = 0xb;
  if (len != 6 || p[1] != 0) return 1;
  s32 c = (s8)p[0];
  if (c == 0x58) caps = 1;
  else if (c != 0x78) return 1;
  if (p[3] != 0) return 1;
  c = (s8)p[2];
  if (c == 0x4d) caps = 1;
  else if (c != 0x6d) return 1;
  if (p[5] != 0) return 1;
  c = (s8)p[4];
  if (c == 0x4c) return 0;
  if (c != 0x6c) return 1;
  if (caps) return 0;
  *out = 0xc;
  return 1;
}
PCREG(628f30, fn628f30);

// 0x537270, thiscall(a, b) ret 8: 0 when a or b is null or the unaligned base [this+0x5302] is null. h = base + [base]; n = [h+0x10]; entry pointers at base + [h+0x28], each entry = base + pointer: the value [entry+8] of the first entry
// whose pair ([entry+0xc], [entry+0x10]) equals (a, b) in either order; 0 when none.
static u32 THISCALL fn537270(u8 *self, u32 a, u32 b) {
  if (!a || !b) return 0;
  u8 *base = (u8 *)rd32(self + 0x5302);
  if (!base) return 0;
  u8 *h = base + *(u32 *)base;
  s32 n = *(s32 *)(h + 0x10);
  if (n <= 0) return 0;
  u32 *arr = (u32 *)(base + *(u32 *)(h + 0x28));
  for (s32 i = 0; i < n; i++) {
    u8 *e = base + arr[i];
    u32 x = *(u32 *)(e + 0xc), y = *(u32 *)(e + 0x10);
    if ((a == x && b == y) || (a == y && b == x)) return *(u32 *)(e + 8);
  }
  return 0;
}
PCREG(537270, fn537270);

// 0x622270, cdecl(a, p, end): XML entity name of length 2..4 -> character: "lt" 0x3c, "gt" 0x3e, "amp" 0x26, "apos" 0x27, "quot" 0x22; 0 otherwise.
static u32 fn622270(u32 a, const u8 *p, const u8 *end) {
  (void)a;
  s32 len = (s32)(end - p);
  if (len == 2) {
    if (p[1] != 't') return 0;
    if (p[0] == 'g') return 0x3e;
    if (p[0] == 'l') return 0x3c;
    return 0;
  }
  if (len == 3) {
    if (p[0] == 'a' && p[1] == 'm' && p[2] == 'p') return 0x26;
    return 0;
  }
  if (len == 4) {
    if (p[0] == 'a') {
      if (p[1] == 'p' && p[2] == 'o' && p[3] == 's') return 0x27;
      return 0;
    }
    if (p[0] == 'q' && p[1] == 'u' && p[2] == 'o' && p[3] == 't') return 0x22;
    return 0;
  }
  return 0;
}
PCREG(622270, fn622270);
