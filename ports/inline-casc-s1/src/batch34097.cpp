// batch34097.cpp - escalation batch 34097: 0x6200d0 (CRLF to LF), 0x52d4a0 (record writer kind 2), 0x60f040 (matrix rows), 0x5de900 (append record), 0x620120 (collapse whitespace), 0x4e5360, 0x4e83f0.
#include "ff.h"

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static u32 rd16(u8 *p) { return p[0] | p[1] << 8; }
static void wr16(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; }

// 0x6200d0, cdecl(s), returns a pointer to the source terminator: rewrites "\r\n" and a lone '\r' to '\n' in place.
static u8 *fn6200d0(u8 *s) {
  u8 *r = s;
  if (!*r) return r;
  while (*r != 0xd) {
    r++;
    if (!*r) return r;
  }
  u8 *w = r;
  do {
    u8 d = *r;
    u8 *save = r;
    if (d == 0xd) {
      r++;
      *w = 0xa;
      if (*r != 0xa) r = save;
    } else {
      *w = d;
    }
    r++;
    w++;
  } while (*r);
  *w = 0;
  return r;
}
PCREG(6200d0, fn6200d0);

// 0x52d4a0, thiscall(a, b, c, d, e) ret 0x14, bool: k = [a+0x38] - e - 1 must equal [this+8]. Then o = [this+4]: byte [o+0xa] = 2, word [o] = word [b], byte [o+9] = k, words [o+2], [o+4], [o+6] = words c[0], c[2], c[4] (byte offsets 0, 4, 8).
static bool THISCALL fn52d4a0(u8 *self, u8 *a, u16 *b, u16 *c, u32 d, u32 e) {
  (void)d;
  u32 k = *(u32 *)(a + 0x38) - e - 1;
  if (k != *(u32 *)(self + 8)) return false;
  u8 *o = *(u8 **)(self + 4);
  o[0xa] = 2;
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
PCREG(52d4a0, fn52d4a0);

// 0x60f040, register ABI (ecx = dst, edx = src) plus stack s2, ret 4: dst as four rows of (x, y, z, w): row 0 = src[6..8], 0; row 1 = src[3..5], 0; row 2 = src[0..2], 0; row 3 = s2[0..2], 1.0f.
static void FASTCALL fn60f040(u32 *dst, u32 *src, u32 *s2) {
  dst[0] = src[6]; dst[1] = src[7]; dst[2] = src[8]; dst[3] = 0;
  dst[4] = src[3]; dst[5] = src[4]; dst[6] = src[5]; dst[7] = 0;
  dst[8] = src[0]; dst[9] = src[1]; dst[10] = src[2]; dst[11] = 0;
  dst[12] = s2[0]; dst[13] = s2[1]; dst[14] = s2[2]; dst[15] = 0x3f800000;
}
PCREG(60f040, fn60f040);

// 0x5de900, thiscall(p) ret 4, returns p[9]: n = [this]; entry e = this + 40*n: dwords e+4..e+0xc = p[0..2]; e+0x10 = p[3] (skipped when p+0xc is that very address); e+0x14..e+0x28 = p[4..9]; [this] += 1.
static u32 THISCALL fn5de900(u32 *self, u32 *p) {
  u32 n = self[0];
  u32 *e = self + 10 * n;
  e[1] = p[0];
  e[2] = p[1];
  e[3] = p[2];
  u32 *d = self + 4 + 10 * n;
  if (d != p + 3) *d = p[3];
  e[5] = p[4];
  e[6] = p[5];
  e[7] = p[6];
  e[8] = p[7];
  e[9] = p[8];
  u32 v = p[9];
  e[10] = v;
  self[0]++;
  return v;
}
PCREG(5de900, fn5de900);

// 0x620120, cdecl(s), returns the end pointer: collapses runs of '\n', '\r', ' ' to a single ' ' in place, drops leading ones and a trailing one, terminates the string.
static u8 *fn620120(u8 *s) {
  u8 *w = s;
  u8 *r = s;
  if (!*s) { *w = 0; return w; }
  do {
    u8 b = *r;
    if (b == 0xa || b == 0xd || b == 0x20) {
      if (w != s && w[-1] != 0x20) {
        *w = 0x20;
        w++;
      }
    } else {
      *w = b;
      w++;
    }
    r++;
  } while (*r);
  if (w != s && w[-1] == 0x20) w--;
  *w = 0;
  return w;
}
PCREG(620120, fn620120);

// 0x4e5360, thiscall(a) ret 4: c = [this+4]; v = [c+4] (the exe faults on a non-negative v); p = v has bit 0x40000000 ? c + 4*[c+0x10] + 0x14 : c + 0x10. 0 unless [p] > a (signed). Else off = (top two bits of [p+4] zero) ? 8 : [p+8];
// returns [p + off + 4a] + [this+0xc].
static u32 THISCALL fn4e5360(u8 *self, s32 a) {
  u8 *c = *(u8 **)(self + 4);
  s32 v = *(s32 *)(c + 4);
  u8 *p;
  if (v >= 0) {
    u32 r;
    asm volatile("xor %0, %0\n\tmov (%0), %0" : "=&r"(r));
    return r;
  }
  if (v & 0x40000000) p = c + *(u32 *)(c + 0x10) * 4 + 0x14;
  else p = c + 0x10;
  if (!(*(s32 *)p > a)) return 0;
  u32 top = *(u32 *)(p + 4) & 0xc0000000;
  u32 off = top == 0 ? 8 : *(u32 *)(p + 8);
  return *(u32 *)(p + off + 4 * a) + *(u32 *)(self + 0xc);
}
PCREG(4e5360, fn4e5360);

// 0x4e83f0, thiscall(a) ret 4: tree neighbour walk with sentinel s = [this+8]: [a+4] when it is not s; else [a+8] when it is not s; else climb the parents ([x] links) while the node's [+8] is s or the previous node, returning that [+8]
// (0 when the climb reaches s).
static u32 THISCALL fn4e83f0(u8 *self, u8 *a) {
  u32 s = *(u32 *)(self + 8);
  u32 t = *(u32 *)(a + 4);
  if (t != s) return t;
  t = *(u32 *)(a + 8);
  if (t != s) return t;
  u8 *c = *(u8 **)a;
  u8 *cur = a;
  if ((u32)c == s) return 0;
  for (;;) {
    u32 e = *(u32 *)(c + 8);
    if (e == s || e == (u32)cur) {
      cur = c;
      c = *(u8 **)cur;
      if ((u32)c == s) return 0;
      continue;
    }
    return *(u32 *)(*(u8 **)cur + 8);
  }
}
PCREG(4e83f0, fn4e83f0);
