// batch36008.cpp - cascade s4 batch 36008: 0x4422e0, 0x469130, 0x482ac0, 0x49a3e0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u8(THISCALL *v1b_t)(void *, u32);
typedef u8(THISCALL *v0b_t)(void *);
typedef u32(THISCALL *v0r_t)(void *);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }
// flags word of a node's definition: n ? [[n+0xc]+0x23] : 0x200002
static inline u32 nodeFlags(u8 *n) { return n ? rd(*(u8 **)(n + 0xc) + 0x23) : 0x200002u; }

extern "C" u8 THISCALL ext_4db9a0(void *self, u32 a);  // ret 4
extern "C" void THISCALL ext_4d9ce0(void *self);       // plain ret

// 0x4422e0, thiscall(a) ret 4 (this = E): n = a[0x54]; when flags(n) has 0x100000: if 0x4db9a0(a, 0x100020): n->slot 0x310() returns; n->slot 0x30c() && a != E[8] returns;
// then for each child c = n[0x50], c[0x60], ...: E->slot 0x2f0(c). Then when a != E[8] and a[0x3c] has 0x40000 but not 0x400: 0x4d9ce0(a).
static void THISCALL fn4422e0(u8 *E, u8 *a) {
  u8 *n = *(u8 **)(a + 0x54);
  if (nodeFlags(n) & 0x100000) {
    if (ext_4db9a0(a, 0x100020)) {
      if ((*(v0b_t **)n)[0x310 / 4](n)) return;
      if ((*(v0b_t **)n)[0x30c / 4](n) && a != *(u8 **)(E + 8)) return;
    }
    for (u8 *c = *(u8 **)(n + 0x50); c; c = *(u8 **)(c + 0x60)) (*(v1_t **)E)[0x2f0 / 4](E, (u32)c);
  }
  if (a != *(u8 **)(E + 8)) {
    u32 f = rd(a + 0x3c);
    if (!(f & 0x400) && (f & 0x40000)) ext_4d9ce0(a);
  }
}
PCREG(4422e0, fn4422e0);

extern "C" u32 THISCALL ext_4e5e60(void *self);
extern "C" void *memset_634d10(void *, int, u32) asm("ext_634d10");
extern "C" void THISCALL ext_46d5f0(void *self);

// 0x469130, thiscall(a, b) ret 8 (this = E, a unused): o = *([0x70039c] + 0x1907); when o: o->slot 0xc(0x6e5d3c, 0x68875c, 0). x = 0x4e5e60(b); E[0x48] = x;
// t = [[0x70039c]+0x9b]->slot 0x58(x); E[0x1dc] = 0; for c = t[0x50]; c; c = c[0x60]: n = c[0x54]; stop unless flags(n) has 0x100000;
// when n->slot 0x1e0(0x1007d4): E[0x4c + 4*E[0x1dc]++] = n. Then E[0x370] = 0, memset(E+0x1e0, 0, 0x190), 0x46d5f0(E).
static void THISCALL fn469130(u8 *E, u32 a, u32 b) {
  (void)a;
  u8 *eng = G(u8 *, 0x70039c);
  u8 *o = *(u8 **)(eng + 0x1907);
  if (o) (*(v3_t **)o)[0xc / 4](o, 0x6e5d3cu, 0x68875cu, 0);
  u32 x = ext_4e5e60((void *)b);
  wr(E + 0x48, x);
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *t = (*(v1o_t **)tab)[0x58 / 4](tab, x);
  wr(E + 0x1dc, 0);
  for (u8 *c = *(u8 **)(t + 0x50); c; c = *(u8 **)(c + 0x60)) {
    u8 *n = *(u8 **)(c + 0x54);
    if (!(nodeFlags(n) & 0x100000)) break;
    if ((*(v1b_t **)n)[0x1e0 / 4](n, 0x1007d4u)) {
      u32 k = rd(E + 0x1dc);
      wr(E + 0x4c + 4 * k, (u32)n);
      wr(E + 0x1dc, rd(E + 0x1dc) + 1);
    }
  }
  wr(E + 0x370, 0);
  memset_634d10(E + 0x1e0, 0, 0x190);
  ext_46d5f0(E);
}
PCREG(469130, fn469130);

// 0x482ac0, thiscall(no args): for each of the u32 count [E+0x459] objects at E+0x45d (unaligned): o->slot 4(1) when non-null; memset(E+0x45d, 0, 0x80);
// then pairs E->slot 0x624(E->slot X()) for X = 0x63c, 0x62c, 0x630, 0x634, 0x638 (vtable re-read before each of the last four), then E->slot 0x644(2).
static void THISCALL fn482ac0(u8 *E) {
  if (rd(E + 0x459) != 0) {
    u32 i = 0;
    do {
      u8 *o = *(u8 **)(E + 0x45d + 4 * i);
      if (o) (*(v1_t **)o)[4 / 4](o, 1);
      i++;
    } while (i != rd(E + 0x459));
  }
  memset_634d10(E + 0x45d, 0, 0x80);
  static const u32 offs[5] = {0x63c, 0x62c, 0x630, 0x634, 0x638};
  for (int k = 0; k < 5; k++) {
    void **vt = *(void ***)E;
    u32 r = ((v0r_t)vt[offs[k] / 4])(E);
    ((v1_t)vt[0x624 / 4])(E, r);
  }
  (*(v1_t **)E)[0x644 / 4](E, 2);
}
PCREG(482ac0, fn482ac0);

extern "C" void STDCALL ext_4ce1c0(void *p, u32 n);  // ret 8
extern "C" void ext_634273(void *p, u32 n);          // cdecl

// 0x49a3e0, thiscall(no args): a = E[8]; when a: a->slot 0x4c(&loc); r = E[8]->slot 0x64(&loc); while r: e = r[4]; when e: if r[0x10][4] != 0: 0x4ce1c0(e-4, [e-4]) else 0x634273(e, 0);
// r = E[8]->slot 0x64(&loc). Then E[8]->slot 0(1) (delete) when non-null; c = E[4]; E[8] = E[0xc] = 0; when c: c->slot 0(1), E[4] = 0.
static void THISCALL fn49a3e0(u8 *E) {
  u32 loc[3];
  u8 *a = *(u8 **)(E + 8);
  if (a) {
    (*(v1_t **)a)[0x4c / 4](a, (u32)loc);
    a = *(u8 **)(E + 8);
    u8 *r = (*(v1o_t **)a)[0x64 / 4](a, (u32)loc);
    while (r) {
      u8 *e = *(u8 **)(r + 4);
      if (e) {
        u8 *r2 = *(u8 **)(r + 0x10);
        if (rd(r2 + 4) != 0) ext_4ce1c0(e - 4, rd(e - 4));
        else ext_634273(e, 0);
      }
      a = *(u8 **)(E + 8);
      r = (*(v1o_t **)a)[0x64 / 4](a, (u32)loc);
    }
    a = *(u8 **)(E + 8);
    if (a) (*(v1_t **)a)[0](a, 1);
  }
  u8 *c = *(u8 **)(E + 4);
  wr(E + 8, 0);
  wr(E + 0xc, 0);
  if (c) {
    (*(v1_t **)c)[0](c, 1);
    wr(E + 4, 0);
  }
}
PCREG(49a3e0, fn49a3e0);
