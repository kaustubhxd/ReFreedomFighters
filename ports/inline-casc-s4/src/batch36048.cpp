// batch36048.cpp - cascade s4 batch 36048: 0x4f60e0, 0x4f7f20, 0x502e30 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v5o_t)(void *, u32, u32, u32, u32, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u8 *(THISCALL *v5ro_t)(void *, u32, u32, u32, u32, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef u32(THISCALL *v5r_t)(void *, u32, u32, u32, u32, u32);
typedef void (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void THISCALL ext_4dc630(void *self, u32 a, u32 b);   // ret 8

// 0x4f60e0, thiscall(m, str, c) ret 0xc returns eax (this = d): b = sys[0x9b]->slot 0x58(d[0x7c]); b == 0 -> 0. s = m->slot 0x298(0x69a65c, 0x43484f42, c, 0, 1); s == 0 -> 0.
// s->slot 0x154(); 0x4dc630(s[8], 0x800000, 0); s->slot 0x27c(b); s->slot 0x248(d[0x80]); s->slot 0x284(str[0] == '%' ? str + 1 : str); s->slot 0x158(); return s.
static u8 *THISCALL fn4f60e0(u8 *d, u8 *m, u8 *str, u32 c) {
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *b = (*(v1o_t **)tab)[0x58 / 4](tab, rd(d + 0x7c));
  if (!b) return 0;
  u8 *s = (*(v5ro_t **)m)[0x298 / 4](m, 0x69a65cu, 0x43484f42u, c, 0, 1);
  if (!s) return s;
  (*(v0_t **)s)[0x154 / 4](s);
  ext_4dc630(*(u8 **)(s + 8), 0x800000u, 0);
  (*(v1_t **)s)[0x27c / 4](s, (u32)b);
  (*(v1_t **)s)[0x248 / 4](s, rd(d + 0x80));
  if (str[0] == 0x25) {
    (*(v1_t **)s)[0x284 / 4](s, (u32)(str + 1));
    (*(v0_t **)s)[0x158 / 4](s);
    return s;
  }
  (*(v1_t **)s)[0x284 / 4](s, (u32)str);
  (*(v0_t **)s)[0x158 / 4](s);
  return s;
}
PCREG(4f60e0, fn4f60e0);

extern "C" u32 THISCALL ext_4fa230(void *self, void *s);   // ret 4

// 0x4f7f20, thiscall(s) ret 4 returns al (this = d): 0x4fa230(d, s) false -> 0. Stream slots on s: 0x48 -> d + 0x8f, 0x93, 0x97; 0x50 -> d + 0x9b, 0x9f, 0xa3; 0x48 -> d + 0xa7; 0x40 -> d + 0xab, 0xaf; 0x70 -> d + 0xb3; 0x50 -> d + 0xcf; return 1.
static u8 THISCALL fn4f7f20(u8 *d, u8 *s) {
  if (!(u8)ext_4fa230(d, s)) return 0;
  void **vt = *(void ***)s;
  ((v1_t)vt[0x48 / 4])(s, (u32)(d + 0x8f));
  ((v1_t)(*(void ***)s)[0x48 / 4])(s, (u32)(d + 0x93));
  ((v1_t)(*(void ***)s)[0x48 / 4])(s, (u32)(d + 0x97));
  ((v1_t)(*(void ***)s)[0x50 / 4])(s, (u32)(d + 0x9b));
  ((v1_t)(*(void ***)s)[0x50 / 4])(s, (u32)(d + 0x9f));
  ((v1_t)(*(void ***)s)[0x50 / 4])(s, (u32)(d + 0xa3));
  ((v1_t)(*(void ***)s)[0x48 / 4])(s, (u32)(d + 0xa7));
  ((v1_t)(*(void ***)s)[0x40 / 4])(s, (u32)(d + 0xab));
  ((v1_t)(*(void ***)s)[0x40 / 4])(s, (u32)(d + 0xaf));
  ((v1_t)(*(void ***)s)[0x70 / 4])(s, (u32)(d + 0xb3));
  ((v1_t)(*(void ***)s)[0x50 / 4])(s, (u32)(d + 0xcf));
  return 1;
}
PCREG(4f7f20, fn4f7f20);

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 i);   // ret 4
typedef void(THISCALL *v2_t)(void *, u32, u32);

// 0x502e30, thiscall(p) ret 4 (this = s): r = 0x5003d0(p[4], 1); type r[4]: 3 -> id = r[0]; 4 -> id = (*r)->slot 0x34(); else logger(0x69c8e0, 0x111) prints (cdecl 3 args) 0x69c6b0, 0x69c9b0, assert hook (int3 when none), id = 0.
// n = *0x5003d0(p[4], 2); q = 0x5003d0(p[4], 0); ax = (u16)tab->slot 0x114(id, 0, 0x69ca10, 0xc2, &n); s[0xc]->slot 0x12c(*q, ax).
static void THISCALL fn502e30(u8 *s, u8 *p) {
  u8 *r = ext_5003d0(*(u8 **)(p + 4), 1);
  u32 id;
  u32 t = r[4];
  if (t == 3) {
    id = rd(r);
  } else if (t == 4) {
    u8 *o = *(u8 **)r;
    id = (*(v0r_t **)o)[0x34 / 4](o);
  } else {
    u8 *db = G(u8 *, 0x700390);
    u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x69c8e0u, 0x111u);
    void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
    ((void (*)(u8 *, u32, u32))fn)(lo, 0x69c6b0u, 0x69c9b0u);
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
    id = 0;
  }
  u32 n = rd(ext_5003d0(*(u8 **)(p + 4), 2));
  u8 *q = ext_5003d0(*(u8 **)(p + 4), 0);
  u8 *w = *(u8 **)(s + 0xc);
  void **vt = *(void ***)w;
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 ax = (u16)(*(v5r_t **)tab)[0x114 / 4](tab, id, 0, 0x69ca10u, 0xc2u, (u32)&n);
  w = *(u8 **)(s + 0xc);
  ((v2_t)vt[0x12c / 4])(w, rd(q), ax);
}
PCREG(502e30, fn502e30);
