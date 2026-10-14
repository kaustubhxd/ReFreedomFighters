// batch36018.cpp - cascade s4 batch 36018: 0x63fdd0, 0x425c60, 0x42feb0, 0x46cb70, 0x4584f0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u8(THISCALL *v1b_t)(void *, u32);
typedef u32(THISCALL *v1u_t)(void *, u32);
typedef u8 *(THISCALL *v0o_t)(void *);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void *memset_634d10(void *, int, u32) asm("ext_634d10");

// 0x63fdd0, thiscall(a, b) ret 8 (this = E): n = bit length of b (1 for 0 and 1); E[0x3404] = n - 8; entries of 12 bytes at E+0x400: first word = i + 1 (last entry 0xffff), E[0x3400] = 0;
// E[0x3408] = b >> (E[0x3404] & 31); memset(E, 0, 0x400); take entry h = u16 E[0x3402] (0xffff -> null): its next = u16 entry[0], E[0x3400]++, E[0x3402] = next;
// entry[0] = a, entry[4] = b - a, bucket = a >> (E[0x3404] & 31): entry[8] = E[bucket*4], E[bucket*4] = entry.
static void THISCALL fn63fdd0(u8 *E, u32 a, u32 b) {
  u32 n = 1;
  for (u32 t = b >> 1; t; t >>= 1) n++;
  wr(E + 0x3404, n - 8);
  u8 *base = E + 0x400;
  wr(base + 0x3000, 0);
  u8 *p = base;
  for (u32 i = 0; i < 0x3ff; i++) {
    *(u16 *)p = (u16)(i + 1);
    p += 12;
  }
  *(u16 *)p = 0xffff;
  u32 cl = rd(E + 0x3404) & 0xff;
  wr(E + 0x3408, b >> (cl & 31));
  memset_634d10(E, 0, 0x400);
  u32 h = *(u16 *)(base + 0x3002);
  u8 *ent;
  if (h == 0xffff) {
    ent = 0;
  } else {
    ent = base + h * 12;
    u16 nx = *(u16 *)ent;
    (*(u16 *)(base + 0x3000))++;
    *(u16 *)(base + 0x3002) = nx;
  }
  wr(ent, a);
  wr(ent + 4, b - a);
  cl = rd(E + 0x3404) & 0xff;
  u32 bk = a >> (cl & 31);
  wr(ent + 8, rd(E + bk * 4));
  wr(E + bk * 4, (u32)ent);
}
PCREG(63fdd0, fn63fdd0);

extern "C" void ext_42abee(char *buf, const char *fmt, void *ap);  // cdecl vsprintf-like

// 0x425c60, cdecl(unused, fmt, ...): buf[0x400] = vsprintf(fmt, ap); ensures a trailing "\n" (the two bytes at 0x676c04); eng = [0x70039c]: when eng and eng->slot 0x1b0() non-null:
// y = eng->slot 0x1b0(); y->slot 4 cdecl (y, buf).
static void fn425c60(u32 unused, const char *fmt, ...) {
  (void)unused;
  char buf[0x400];
  __builtin_va_list ap;
  __builtin_va_start(ap, fmt);
  ext_42abee(buf, fmt, ap);
  __builtin_va_end(ap);
  u32 len = 0;
  while (buf[len]) len++;
  if (len == 0 || buf[len - 1] != 0x0a) {
    buf[len] = (char)G(u8, 0x676c04);
    buf[len + 1] = (char)G(u8, 0x676c05);
  }
  u8 *eng = G(u8 *, 0x70039c);
  if (!eng) return;
  if (!(*(v0o_t **)eng)[0x1b0 / 4](eng)) return;
  u8 *y = (*(v0o_t **)G(u8 *, 0x70039c))[0x1b0 / 4](G(u8 *, 0x70039c));
  void **vt2 = *(void ***)y;
  void *fn = *(void **)((u8 *)vt2 + 4);
  __asm__ volatile("pushl %[b]\n\tpushl %[o]\n\tcall *%[f]\n\taddl $8, %%esp"
                   : "+c"(vt2) : [b] "r"(buf), [o] "r"(y), [f] "r"(fn) : "eax", "edx", "memory", "cc");
}
PCREG(425c60, fn425c60);

// 0x42feb0, fastcall(a, b, c, d) ret 8: compares the byte ranges [a, b) and [c, d) like memcmp over the shorter one (unsigned bytes, -1 / 1 at the first difference),
// ties broken by length: shorter range -> -1, longer -> 1, equal -> 0. (lengths are signed; negative lengths are not exercised.)
static s32 FASTCALL fn42feb0(const u8 *a, const u8 *b, const u8 *c, const u8 *d) {
  s32 l1 = (s32)(b - a);
  s32 l2 = (s32)(d - c);
  s32 m = l2 < l1 ? l2 : l1;
  for (s32 i = 0; i < m; i++) {
    if (a[i] != c[i]) return a[i] < c[i] ? -1 : 1;
  }
  if (l1 < l2) return -1;
  return l1 > l2 ? 1 : 0;
}
PCREG(42feb0, fn42feb0);

extern "C" void THISCALL ext_43f8c0(void *self, void *s);  // ret 4 (tail jump into slot 0x48)

// 0x46cb70, thiscall(s) ret 4 (this = E): 0x43f8c0(E, s); s->slot 0x1e0(0x1007d3): copies dwords +0x5c, +0x60, +0x64, +0x68, +0x6c, +0x78 from s to E.
// s->slot 0x1e0(0x1007d9) and p = s[0x7c]: p->slot 0x4c(&loc); r = p->slot 0x5c(&loc); while loc != 0: E[0x7c]->slot 4(r); r = s[0x7c]->slot 0x5c(&loc).
static void THISCALL fn46cb70(u8 *E, u8 *s) {
  u32 loc[3];
  ext_43f8c0(E, s);
  if ((*(v1b_t **)s)[0x1e0 / 4](s, 0x1007d3u)) {
    static const u8 offs[6] = {0x5c, 0x60, 0x64, 0x68, 0x6c, 0x78};
    for (int i = 0; i < 6; i++) wr(E + offs[i], rd(s + offs[i]));
  }
  if (!(*(v1b_t **)s)[0x1e0 / 4](s, 0x1007d9u)) return;
  u8 *p = *(u8 **)(s + 0x7c);
  if (!p) return;
  (*(v1_t **)p)[0x4c / 4](p, (u32)loc);
  p = *(u8 **)(s + 0x7c);
  u32 r = (*(v1u_t **)p)[0x5c / 4](p, (u32)loc);
  if (loc[0] == 0) return;
  do {
    u8 *q = *(u8 **)(E + 0x7c);
    (*(v1_t **)q)[4 / 4](q, r);
    p = *(u8 **)(s + 0x7c);
    r = (*(v1u_t **)p)[0x5c / 4](p, (u32)loc);
  } while (loc[0] != 0);
}
PCREG(46cb70, fn46cb70);

extern "C" void THISCALL ext_451d00(void *self, void *s);              // ret 4
extern "C" void THISCALL ext_4e12e0(void *self, u32 *out, u32 n);      // ret 8
extern "C" u8 THISCALL ext_4e1600(void *self);                         // plain ret
extern "C" void THISCALL ext_4e1b30(void *self);                       // plain ret
extern "C" void THISCALL ext_4587d0(void *self);                       // plain ret

// 0x4584f0, thiscall(s) ret 4 (this = E): 0x451d00(E, s); 0x4e12e0(s, E+0x48, 1); o = [[0x70039c]+0x9b]->slot 0x58(E[0x48]); o and o->slot 0x1e0(0x2000e2): o->slot 0xbc(1), else E[0x48] = 0.
// 0x4e1600(s) == 3: 0x4e12e0(s, &v, 1); 0x4e12e0(s, E+0x44, 1); E[0x44] |= v << 24; else E[0x44] = 0xa0a0a0a0. 0x4e1b30(s); E[0x48] non-zero: 0x4587d0(E).
static void THISCALL fn4584f0(u8 *E, u8 *s) {
  u32 v = 0;
  ext_451d00(E, s);
  u32 *p48 = (u32 *)(E + 0x48);
  ext_4e12e0(s, p48, 1);
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = (*(u8 *(THISCALL **)(void *, u32))(*(u8 **)tab + 0x58))(tab, *p48);
  bool ok = false;
  if (o && (*(v1b_t **)o)[0x1e0 / 4](o, 0x2000e2u)) {
    (*(v1_t **)o)[0xbc / 4](o, 1);
    ok = true;
  }
  if (!ok) *p48 = 0;
  if (ext_4e1600(s) == 3) {
    ext_4e12e0(s, &v, 1);
    u32 *p44 = (u32 *)(E + 0x44);
    ext_4e12e0(s, p44, 1);
    *p44 |= v << 24;
  } else {
    wr(E + 0x44, 0xa0a0a0a0);
  }
  ext_4e1b30(s);
  if (rd(E + 0x48)) ext_4587d0(E);
}
PCREG(4584f0, fn4584f0);
