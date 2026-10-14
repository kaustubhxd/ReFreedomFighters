// batch36029.cpp - cascade s4 batch 36029: 0x49c6d0, 0x4d2820, 0x4fa630, 0x5098b0, 0x59e690 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v0u_t)(void *);
typedef u32(THISCALL *v1u_t)(void *, u32);
typedef u32(THISCALL *v2u_t)(void *, u32, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32 (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// 0x49c6d0, fastcall(dst, x, n1, b, n2) ret 0xc, returns b + n2 (end of b): merges the sorted (unsigned) dword ranges x[0..n1) and b[0..n2) into dst: while both are non-empty the smaller head is taken from x unless x's head
// is strictly greater; then the rest of x, then the rest of b are copied.
static u32 *FASTCALL fn49c6d0(u32 *dst, u32 *x, u32 n1, u32 *b, u32 n2) {
  u32 *ex = x + n1;
  u32 *eb = b + n2;
  while (x != ex && b != eb) {
    if (*x > *b) *dst++ = *b++;
    else *dst++ = *x++;
  }
  while (x != ex) *dst++ = *x++;
  while (b != eb) *dst++ = *b++;
  return b;
}
PCREG(49c6d0, fn49c6d0);

extern "C" u8 *THISCALL ext_4d2b40(void *self, u32 a, u32 len);  // ret 8
extern "C" void THISCALL ext_4d29d0(void *self);                 // plain ret
extern "C" void *ext_634d22(void *dst, const void *src, u32 n);  // cdecl

// 0x4d2820, thiscall(p) ret 4 (this = E): len = p[0]; total = p[2] + 0x11 + len; r = 0x4d2b40(E, p + 0xc, len): r and r[0] == total -> r reused (no allocation); r non-null otherwise: r[4] = 0.
// New record: E[0xc] + total > E[4] -> 0x4d29d0(E), still too small: log (0x696418, 0x33b, 0x696530) and assert hook, return. Else r = E[8] + E[0xc]; E[0xc] += total; r[0] = total; r[4] = 1.
// Finally memcpy(r + 5, p, total - 5).
static void THISCALL fn4d2820(u8 *E, u8 *p) {
  u32 len = rd(p);
  u32 total = rd(p + 8) + 0x11 + len;
  u8 *r = ext_4d2b40(E, (u32)(p + 0xc), len);
  if (!(r && rd(r) == total)) {
    if (r) r[4] = 0;
    u32 used = rd(E + 0xc);
    if (used + total > rd(E + 4)) {
      ext_4d29d0(E);
      used = rd(E + 0xc);
      if (used + total > rd(E + 4)) {
        u8 *db = G(u8 *, 0x700390);
        u8 *o = (*(v2o_t **)db)[0x20 / 4](db, 0x696418u, 0x33bu);
        void *fn = *(void **)((u8 *)*(void ***)o + 0x2c);
        ((void (*)(u8 *, u32))fn)(o, 0x696530u);  // cdecl varargs print
        hook_t h = G(hook_t, 0x7003b0);
        if (!h) __asm__ volatile("int3");
        h();
        return;
      }
    }
    r = *(u8 **)(E + 8) + used;
    wr(E + 0xc, used + total);
    wr(r, total);
    r[4] = 1;
  }
  ext_634d22(r + 5, p, total - 5);
}
PCREG(4d2820, fn4d2820);

extern "C" u8 THISCALL ext_441790(void *self, void *s);  // ret 4

// 0x4fa630, thiscall(s) ret 4, returns bool (this = E): 0x441790(E, s) false -> 0. s->slot 0x3c: E[0x60], E[0x64]; slot 0x44: E[0x68]; slot 0x3c: E[0x6c], E[0x70], E[0x78], E[0x7c], E[0x80], E[0x84];
// slot 0x60(byte E[0x88]); slot 0x3c(E[0x74]); slot 0x44(E[0x8b] unaligned); returns 1.
static u8 THISCALL fn4fa630(u8 *E, u8 *s) {
  if (!ext_441790(E, s)) return 0;
  void **vt = *(void ***)s;
  ((v1_t)vt[0x3c / 4])(s, rd(E + 0x60));
  ((v1_t)vt[0x3c / 4])(s, rd(E + 0x64));
  ((v1_t)vt[0x44 / 4])(s, rd(E + 0x68));
  ((v1_t)vt[0x3c / 4])(s, rd(E + 0x6c));
  ((v1_t)vt[0x3c / 4])(s, rd(E + 0x70));
  ((v1_t)vt[0x3c / 4])(s, rd(E + 0x78));
  ((v1_t)vt[0x3c / 4])(s, rd(E + 0x7c));
  ((v1_t)vt[0x3c / 4])(s, rd(E + 0x80));
  ((v1_t)vt[0x3c / 4])(s, rd(E + 0x84));
  ((v1_t)vt[0x60 / 4])(s, E[0x88]);
  ((v1_t)vt[0x3c / 4])(s, rd(E + 0x74));
  ((v1_t)vt[0x44 / 4])(s, rd(E + 0x8b));
  return 1;
}
PCREG(4fa630, fn4fa630);

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 a);   // ret 4
extern "C" void THISCALL ext_5002f0(void *self, u32 a);  // ret 4

// 0x5098b0, thiscall(a) ret 4 (this = E): c = E[0xc]: null: log (0x69d214, 0x80, 0x69d244) and 0x5002f0(0x5003d0(a[8], 0), 0). n = c[0x18]->slot 0x14(): 0 -> 0x5002f0(..., 0).
// Otherwise r = [0x70039c]->slot 0x1bc(0x69d214, 0x8b); k = (s32)r % n; v = E[0xc][0x18]->slot 0x30(k); 0x5002f0(0x5003d0(a[8], 0), v).
static void THISCALL fn5098b0(u8 *E, u8 *a) {
  u8 *c = *(u8 **)(E + 0xc);
  if (!c) {
    u8 *db = G(u8 *, 0x700390);
    u8 *o = (*(v2o_t **)db)[0x20 / 4](db, 0x69d214u, 0x80u);
    void *fn = *(void **)((u8 *)*(void ***)o + 0x2c);
    ((void (*)(u8 *, u32))fn)(o, 0x69d244u);
    u8 *rec = ext_5003d0(*(u8 **)(a + 8), 0);
    ext_5002f0(rec, 0);
    return;
  }
  u8 *l = *(u8 **)(c + 0x18);
  s32 n = (s32)(*(v0u_t **)l)[0x14 / 4](l);
  if (n == 0) {
    u8 *rec = ext_5003d0(*(u8 **)(a + 8), 0);
    ext_5002f0(rec, 0);
    return;
  }
  u8 *eng = G(u8 *, 0x70039c);
  s32 r = (s32)(*(v2u_t **)eng)[0x1bc / 4](eng, 0x69d214u, 0x8bu);
  s32 k = r % n;
  c = *(u8 **)(E + 0xc);
  l = *(u8 **)(c + 0x18);
  u32 v = (*(v1u_t **)l)[0x30 / 4](l, (u32)k);
  u8 *rec = ext_5003d0(*(u8 **)(a + 8), 0);
  ext_5002f0(rec, v);
}
PCREG(5098b0, fn5098b0);

extern "C" void THISCALL ext_5a3690(void *self, u32 a, u32 b);  // ret 8

// 0x59e690, thiscall(a, b) ret 8 (this = E): entries of 16 bytes at E+0x7d2, count u32 at E+0x7ce. first = first entry with b < v < a (signed); from that position on, last = first entry with v >= a (or the end).
// first found: 0x5a3690(E + 0x7ce, index(first), index(last)).
static void THISCALL fn59e690(u8 *E, s32 a, s32 b) {
  u8 *base = E + 0x7ce;
  u8 *ent = E + 0x7d2;
  u8 *end = base + 4 + rd(base) * 16;
  u8 *first = 0;
  u8 *p = ent;
  if (p != end) {
    for (;;) {
      s32 v = *(s32 *)p;
      if (v > b && v < a) {
        first = p;
        break;
      }
      p += 0x10;
      if (p == end) break;
    }
  }
  u8 *last = end;
  if (p != end) {
    for (;;) {
      if (*(s32 *)p >= a) {
        last = p;
        break;
      }
      p += 0x10;
      if (p == end) break;
    }
  }
  if (first) ext_5a3690(base, (u32)(((s32)(first - base) - 4) >> 4), (u32)(((s32)(last - base) - 4) >> 4));
}
PCREG(59e690, fn59e690);
