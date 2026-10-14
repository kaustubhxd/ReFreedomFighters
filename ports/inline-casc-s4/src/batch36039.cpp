// batch36039.cpp - cascade s4 batch 36039: 0x45e840, 0x474320, 0x495f10, 0x4f8320, 0x515f60 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef void (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void ext_634273(u32 a, u32 b);   // cdecl, 2 args

// 0x45e840, thiscall() plain ret (this = s): l = s[0x10][0x14]; when set: iterate (slot 0x4c(&it), v = slot 0x64(&it) until 0): ext_634273(v[0x10], 1); when [0x70038c]->slot 0xc0(v[0x14]) (low byte) and v[0x14]: v[0x14]->slot 0(1).
// Afterwards: [0x70038c]->slot 0xc0(s[0x10][0x14]) and the object set: its slot 0(1); s[0x10][0x14] = 0.
static void THISCALL fn45e840(u8 *s) {
  u8 *l = *(u8 **)(*(u8 **)(s + 0x10) + 0x14);
  if (!l) return;
  u32 it[3];
  (*(v1_t **)l)[0x4c / 4](l, (u32)it);
  u8 *l2 = *(u8 **)(*(u8 **)(s + 0x10) + 0x14);
  u8 *v = (*(v1o_t **)l2)[0x64 / 4](l2, (u32)it);
  while (v) {
    ext_634273(rd(v + 0x10), 1);
    u8 *g = G(u8 *, 0x70038c);
    if ((u8)(*(v1r_t **)g)[0xc0 / 4](g, rd(v + 0x14))) {
      u8 *o = *(u8 **)(v + 0x14);
      if (o) (*(v1_t **)o)[0](o, 1);
    }
    u8 *l3 = *(u8 **)(*(u8 **)(s + 0x10) + 0x14);
    v = (*(v1o_t **)l3)[0x64 / 4](l3, (u32)it);
  }
  u8 *g = G(u8 *, 0x70038c);
  u8 *q = *(u8 **)(*(u8 **)(s + 0x10) + 0x14);
  if ((u8)(*(v1r_t **)g)[0xc0 / 4](g, (u32)q)) {
    u8 *o = *(u8 **)(*(u8 **)(s + 0x10) + 0x14);
    if (o) (*(v1_t **)o)[0](o, 1);
  }
  wr(*(u8 **)(s + 0x10) + 0x14, 0);
}
PCREG(45e840, fn45e840);

typedef u32(THISCALL *v2r_t)(void *, u32, u32);

// 0x474320, thiscall(a) ret 4 returns eax (this = s): s[0x2e3] == 0 -> 0. w = a->slot 0x350(); w == 0: logger(0x68961c, 0x3c4) prints (cdecl) 0x6897a0, return 0. !(u8)w->slot 0x328() -> 0.
// y = s[0x2e3]->slot 0x98(w->slot 0x340(0), 0); y == 0 -> 0; z = sys[0x9b]->slot 0x58(y); z == 0 -> 0; return (u8)z->slot 0x1e0(0x1007d8) ? z : 0.
static u32 THISCALL fn474320(u8 *s, u8 *a) {
  if (rd(s + 0x2e3) == 0) return 0;
  u8 *w = (*(v0o_t **)a)[0x350 / 4](a);
  if (!w) {
    u8 *db = G(u8 *, 0x700390);
    u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x68961cu, 0x3c4u);
    void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
    ((void (*)(u8 *, u32))fn)(lo, 0x6897a0u);
    return 0;
  }
  if (!(u8)(*(v0r_t **)w)[0x328 / 4](w)) return 0;
  u32 x = (*(v1r_t **)w)[0x340 / 4](w, 0);
  u8 *q = *(u8 **)(s + 0x2e3);
  u32 y = (*(v2r_t **)q)[0x98 / 4](q, x, 0);
  if (y == 0) return 0;
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *z = (*(v1o_t **)tab)[0x58 / 4](tab, y);
  if (!z) return 0;
  if (!(u8)(*(v1r_t **)z)[0x1e0 / 4](z, 0x1007d8u)) return 0;
  return (u32)z;
}
PCREG(474320, fn474320);

extern "C" void THISCALL ext_4cbe20(void *b, u32 a, u32 c, u32 d);   // ret 0xc

// 0x495f10, thiscall(a, b, c, d) ret 0x10 returns esi (this = s): when s->slot 0x30() (low byte): logger(0x68e36c, 0xb7b) prints (cdecl, 3 args) 0x68e600, a.
// G8[0x6ffaa0] set: logger(0xb81) prints 0x68e638, a, assert hook (int3 when none). G8 = 1; b == 0 -> G8 = 0, return 0. c == 0 -> c = s->slot 0xc(). 0x4cbe20(b, a, c, d); G8 = 0; return c.
static u32 THISCALL fn495f10(u8 *s, u32 a, u8 *b, u32 c, u32 d) {
  if ((u8)(*(v0r_t **)s)[0x30 / 4](s)) {
    u8 *db = G(u8 *, 0x700390);
    u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x68e36cu, 0xb7bu);
    void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
    ((void (*)(u8 *, u32, u32))fn)(lo, 0x68e600u, a);
  }
  if (G(u8, 0x6ffaa0)) {
    u8 *db = G(u8 *, 0x700390);
    u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x68e36cu, 0xb81u);
    void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
    ((void (*)(u8 *, u32, u32))fn)(lo, 0x68e638u, a);
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  G(u8, 0x6ffaa0) = 1;
  if (!b) {
    G(u8, 0x6ffaa0) = 0;
    return 0;
  }
  if (!c) c = (*(v0r_t **)s)[0xc / 4](s);
  ext_4cbe20(b, a, c, d);
  G(u8, 0x6ffaa0) = 0;
  return c;
}
PCREG(495f10, fn495f10);

// 0x4f8320, thiscall(str) ret 4 (this = s, embedded list at s + 0xb3): iterate it (slot 0x4c(&it); e = slot 0x5c(&it) while it[0]): o = sys[0x9b]->slot 0x58(e);
// o && (u8)o->slot 0x1e0(0x20002d): str[0] == '%' -> o->slot 0x284(str + 1), else o->slot 0x288(0x677b5a, str); otherwise list->slot 0x44(&it) (remove the current entry).
static void THISCALL fn4f8320(u8 *s, u8 *str) {
  u8 *l = s + 0xb3;
  if (l == 0) return;
  u32 it[3];
  (*(v1_t **)l)[0x4c / 4](l, (u32)it);
  u32 e = (*(v1r_t **)l)[0x5c / 4](l, (u32)it);
  if (it[0] == 0) return;
  do {
    u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *o = (*(v1o_t **)tab)[0x58 / 4](tab, e);
    if (o && (u8)(*(v1r_t **)o)[0x1e0 / 4](o, 0x20002du)) {
      if (str[0] == 0x25) (*(v1_t **)o)[0x284 / 4](o, (u32)(str + 1));
      else (*(v2_t **)o)[0x288 / 4](o, 0x677b5au, (u32)str);
    } else {
      (*(v1_t **)l)[0x44 / 4](l, (u32)it);
    }
    e = (*(v1r_t **)l)[0x5c / 4](l, (u32)it);
  } while (it[0] != 0);
}
PCREG(4f8320, fn4f8320);

// 0x515f60, thiscall() plain ret (this = s): for each v of the list s[0xd6] (slot 0x4c / 0x5c with it): sys[0x9b][0xadc]->slot 0x220(v); then s[0xd6]->slot 0xc().
// Same for the list s[0xda] with slot 0x240.
static void THISCALL fn515f60(u8 *s) {
  u32 it[3];
  u8 *l = *(u8 **)(s + 0xd6);
  if (l) {
    (*(v1_t **)l)[0x4c / 4](l, (u32)it);
    u8 *l2 = *(u8 **)(s + 0xd6);
    u32 v = (*(v1r_t **)l2)[0x5c / 4](l2, (u32)it);
    if (it[0] != 0) {
      do {
        u8 *X = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xadc);
        (*(v1_t **)X)[0x220 / 4](X, v);
        u8 *l3 = *(u8 **)(s + 0xd6);
        v = (*(v1r_t **)l3)[0x5c / 4](l3, (u32)it);
      } while (it[0] != 0);
    }
  }
  u8 *l4 = *(u8 **)(s + 0xd6);
  (*(v0_t **)l4)[0xc / 4](l4);
  u8 *m = *(u8 **)(s + 0xda);
  if (m) {
    (*(v1_t **)m)[0x4c / 4](m, (u32)it);
    u8 *m2 = *(u8 **)(s + 0xda);
    u32 v = (*(v1r_t **)m2)[0x5c / 4](m2, (u32)it);
    if (it[0] != 0) {
      do {
        u8 *X = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xadc);
        (*(v1_t **)X)[0x240 / 4](X, v);
        u8 *m3 = *(u8 **)(s + 0xda);
        v = (*(v1r_t **)m3)[0x5c / 4](m3, (u32)it);
      } while (it[0] != 0);
    }
  }
  u8 *m4 = *(u8 **)(s + 0xda);
  (*(v0_t **)m4)[0xc / 4](m4);
}
PCREG(515f60, fn515f60);
