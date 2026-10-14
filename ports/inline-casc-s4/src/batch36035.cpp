// batch36035.cpp - cascade s4 batch 36035: 0x606120, 0x616000, 0x638d60, 0x639df0, 0x63f8a0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v1o2_t)(void *, u32);
typedef void (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void THISCALL ext_606940(void *self, const void *data, u32 len);   // ret 8

// 0x606120, thiscall(out) ret 4 (this = ctx): bits = the 8 bytes at ctx + 0x10; n = (ctx[0x10] >> 3) & 0x3f; pad = n < 0x38 ? 0x38 - n : 0x78 - n;
// 0x606940(ctx, 0x6efc30, pad); 0x606940(ctx, bits, 8); out[0..15] = ctx[0..15].
static void THISCALL fn606120(u8 *ctx, u8 *out) {
  u8 buf[8];
  for (int i = 0; i < 8; i++) buf[i] = ctx[0x10 + i];
  u32 n = (rd(ctx + 0x10) >> 3) & 0x3f;
  u32 pad = n < 0x38 ? 0x38 - n : 0x78 - n;
  ext_606940(ctx, (const void *)0x6efc30, pad);
  ext_606940(ctx, buf, 8);
  for (int i = 0; i < 16; i++) out[i] = ctx[i];
}
PCREG(606120, fn606120);

// 0x616000, thiscall(p) ret 4 (this = E): pool slot release like 0x63f6b0 (record 0x30) plus p[5] &= 0xfd.
static void THISCALL fn616000(u8 *E, u8 *p) {
  wr(E + 0xc, rd(E + 0xc) - 1);
  u8 *b = (*(v1o_t **)E)[0x2c / 4](E, (u32)p);
  p[5] &= 0xfd;
  u16 cx = *(u16 *)(b + 2);
  b[0]--;
  *(u16 *)p = cx;
  s32 d = (s32)((u32)p - (u32)b) - 0x10;
  *(u16 *)(b + 2) = (u16)(d / 0x30);
  if (b[0] == 0) {
    if (*(u8 **)(E + 8) == b) {
      u8 *n = *(u8 **)(b + 8);
      if (n == b) n = 0;
      *(u8 **)(E + 8) = n;
    }
    u8 *n1 = *(u8 **)(b + 8);
    wr(n1 + 0xc, rd(b + 0xc));
    u8 *n2 = *(u8 **)(b + 0xc);
    wr(n2 + 8, rd(b + 8));
    (*(v1_t **)E)[0x34 / 4](E, (u32)b);
    return;
  }
  if (b == *(u8 **)(E + 8)) return;
  u8 *n1 = *(u8 **)(b + 8);
  wr(n1 + 0xc, rd(b + 0xc));
  u8 *n2 = *(u8 **)(b + 0xc);
  wr(n2 + 8, rd(b + 8));
  u8 *head = *(u8 **)(E + 8);
  wr(b + 8, (u32)head);
  u8 *tail = *(u8 **)(head + 0xc);
  wr(b + 0xc, (u32)tail);
  wr(tail + 8, (u32)b);
  wr(head + 0xc, (u32)b);
  wr(E + 8, (u32)b);
}
PCREG(616000, fn616000);

// 0x63f8a0: identical to 0x616000 but the record size is 0x4c.
static void THISCALL fn63f8a0(u8 *E, u8 *p) {
  wr(E + 0xc, rd(E + 0xc) - 1);
  u8 *b = (*(v1o_t **)E)[0x2c / 4](E, (u32)p);
  p[5] &= 0xfd;
  u16 cx = *(u16 *)(b + 2);
  b[0]--;
  *(u16 *)p = cx;
  s32 d = (s32)((u32)p - (u32)b) - 0x10;
  *(u16 *)(b + 2) = (u16)(d / 0x4c);
  if (b[0] == 0) {
    if (*(u8 **)(E + 8) == b) {
      u8 *n = *(u8 **)(b + 8);
      if (n == b) n = 0;
      *(u8 **)(E + 8) = n;
    }
    u8 *n1 = *(u8 **)(b + 8);
    wr(n1 + 0xc, rd(b + 0xc));
    u8 *n2 = *(u8 **)(b + 0xc);
    wr(n2 + 8, rd(b + 8));
    (*(v1_t **)E)[0x34 / 4](E, (u32)b);
    return;
  }
  if (b == *(u8 **)(E + 8)) return;
  u8 *n1 = *(u8 **)(b + 8);
  wr(n1 + 0xc, rd(b + 0xc));
  u8 *n2 = *(u8 **)(b + 0xc);
  wr(n2 + 8, rd(b + 8));
  u8 *head = *(u8 **)(E + 8);
  wr(b + 8, (u32)head);
  u8 *tail = *(u8 **)(head + 0xc);
  wr(b + 0xc, (u32)tail);
  wr(tail + 8, (u32)b);
  wr(head + 0xc, (u32)b);
  wr(E + 8, (u32)b);
}
PCREG(63f8a0, fn63f8a0);

// 0x638d60, thiscall(dst, b, c, d, e, f, g) ret 0x1c (this = t): rec = t->slot 0x38(g); assert hook when rec[4] != d or rec[8] != e;
// row = rec[4] * c + b; for e rows (when e > 0): for k < d (when d > 0): dst[k] = ((u32 *)t[0x2d])[byte(rec[0x10] + row + k)]; dst += f bytes; row += rec[4].
static void THISCALL fn638d60(u8 *t, u32 *dst, s32 b, s32 c, s32 d, s32 e, u32 f, u32 g) {
  u8 *rec = (*(v1o2_t **)t)[0x38 / 4](t, g);
  hook_t h;
  if (rd(rec + 4) != (u32)d) {
    h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  if (rd(rec + 8) != (u32)e) {
    h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  s32 row = (s32)rd(rec + 4) * c + b;
  u8 *base = *(u8 **)(rec + 0x10);
  if (e > 0) {
    do {
      if (d > 0) {
        u32 *tab = *(u32 **)(t + 0x2d);
        for (s32 k = 0; k < d; k++) dst[k] = tab[base[row + k]];
      }
      dst = (u32 *)((u8 *)dst + f);
      row += (s32)rd(rec + 4);
      e--;
    } while (e != 0);
  }
}
PCREG(638d60, fn638d60);

static inline u32 shr(u32 v, u32 c) { return v >> (c & 31); }
static inline u32 shl(u32 v, u32 c) { return v << (c & 31); }

// 0x639df0, thiscall(v, inv) ret 8 (this = s): packs the channels of v: ch(i) = shl(shr(shl(shr(v & s[4 * i], s[0x10 + 4 * i]), s[0x20 + 4 * i]), s[0x50 + 4 * i]), s[0x40 + 4 * i]).
// The fourth channel (mask s[0xc], shifts 0x1c/0x2c/0x5c/0x4c): when the low byte of inv != 0: t = 0xff - shl(shr(v & s[0xc], s[0x1c]), s[0x2c]) before the last shr/shl pair. Returns the sum.
static u32 THISCALL fn639df0(u8 *s, u32 v, u32 inv) {
  u32 a = shl(shr(shl(shr(v & rd(s), rd(s + 0x10)), rd(s + 0x20)), rd(s + 0x50)), rd(s + 0x40));
  u32 b = shl(shr(shl(shr(v & rd(s + 4), rd(s + 0x14)), rd(s + 0x24)), rd(s + 0x54)), rd(s + 0x44));
  u32 c = shl(shr(shl(shr(v & rd(s + 8), rd(s + 0x18)), rd(s + 0x28)), rd(s + 0x58)), rd(s + 0x48));
  u32 t = shl(shr(v & rd(s + 0xc), rd(s + 0x1c)), rd(s + 0x2c));
  if ((u8)inv) t = 0xff - t;
  t = shl(shr(t, rd(s + 0x5c)), rd(s + 0x4c));
  return c + t + b + a;
}
PCREG(639df0, fn639df0);
