// batch36044.cpp - cascade s4 batch 36044: 0x4d8c30, 0x502ad0, 0x5b7ad0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef u32(THISCALL *v5r_t)(void *, u32, u32, u32, u32, u32);
typedef void (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u32 THISCALL ext_4cc1d0(void *a);   // mov eax, [ecx]; ret

// 0x4d8c30, thiscall(x) ret 4 (this = s): m = s[4]; o = m->slot 0x84(ext_4cc1d0(x->slot 4())); o == 0 -> return. l = o[4]: when set iterate (slot 0x4c(&it), e = slot 0x5c(&it) while it[0]): e == x -> l->slot 0x44(&it) (remove), stop.
// Then: o[4]->slot 0x14() nonzero -> return. o[4] (when set)->slot 0(1); m = s[4]; m->slot 0x90(ext_4cc1d0(x->slot 4())).
static void THISCALL fn4d8c30(u8 *s, u8 *x) {
  u8 *m = *(u8 **)(s + 4);
  void **mvt = *(void ***)m;
  u8 *a = (*(v0o_t **)x)[4 / 4](x);
  u32 k = ext_4cc1d0(a);
  u8 *o = ((v1o_t)mvt[0x84 / 4])(*(u8 **)(s + 4), k);
  if (!o) return;
  u8 *l = *(u8 **)(o + 4);
  if (l) {
    u32 it[3];
    (*(v1_t **)l)[0x4c / 4](l, (u32)it);
    l = *(u8 **)(o + 4);
    u8 *e = (*(v1o_t **)l)[0x5c / 4](l, (u32)it);
    if (it[0] != 0) {
      do {
        l = *(u8 **)(o + 4);
        if (e == x) {
          (*(v1_t **)l)[0x44 / 4](l, (u32)it);
          break;
        }
        e = (*(v1o_t **)l)[0x5c / 4](l, (u32)it);
      } while (it[0] != 0);
    }
  }
  l = *(u8 **)(o + 4);
  if ((*(v0r_t **)l)[0x14 / 4](l)) return;
  l = *(u8 **)(o + 4);
  if (l) (*(v1_t **)l)[0](l, 1);
  m = *(u8 **)(s + 4);
  void **mvt2 = *(void ***)m;
  u8 *a2 = (*(v0o_t **)x)[4 / 4](x);
  u32 k2 = ext_4cc1d0(a2);
  ((v1_t)mvt2[0x90 / 4])(*(u8 **)(s + 4), k2);
}
PCREG(4d8c30, fn4d8c30);

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 i);   // ret 4

// 0x502ad0, thiscall(p) ret 4 (this = s): a = *0x5003d0(p[4], 0); r = 0x5003d0(p[4], 1); type r[4]: 3 -> id = r[0]; 4 -> id = (*r)->slot 0x34(); else logger(0x69c8e0, 0x111) prints (cdecl 3 args) 0x69c6b0, 0x69c9b0, assert hook (int3 when none), id = 0.
// n = *0x5003d0(p[4], 2); ax = (u16)tab->slot 0x114(id, 0, 0x69ca10, 0x149, &n); s[0xc]->slot 0x134(a, ax).
static void THISCALL fn502ad0(u8 *s, u8 *p) {
  u32 a = rd(ext_5003d0(*(u8 **)(p + 4), 0));
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
  u8 *w = *(u8 **)(s + 0xc);
  void **vt = *(void ***)w;
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 ax = (u16)(*(v5r_t **)tab)[0x114 / 4](tab, id, 0, 0x69ca10u, 0x149u, (u32)&n);
  w = *(u8 **)(s + 0xc);
  ((v2_t)vt[0x134 / 4])(w, a, ax);
}
PCREG(502ad0, fn502ad0);

// 0x5b7ad0, thiscall() plain ret (this = d): o = sys[0x9b]->slot 0x58(d[0x4e]); o == 0 -> return. o->slot 0x1e0(0x800001a) (low byte): l = o[0x18]; none -> return; iterate l (slot 0x4c(&it), e = slot 0x5c(&it) while it[0]):
// x = sys[0x9b]->slot 0x58(e); x->slot 0x128((u16)d[0x52], 0, 0). Otherwise o->slot 0x128((u16)d[0x52], 0, 0).
static void THISCALL fn5b7ad0(u8 *d) {
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = (*(v1o_t **)tab)[0x58 / 4](tab, rd(d + 0x4e));
  if (!o) return;
  if ((u8)(*(v1r_t **)o)[0x1e0 / 4](o, 0x800001au)) {
    u8 *l = *(u8 **)(o + 0x18);
    if (!l) return;
    u32 it[3];
    (*(v1_t **)l)[0x4c / 4](l, (u32)it);
    l = *(u8 **)(o + 0x18);
    u32 e = (*(v1r_t **)l)[0x5c / 4](l, (u32)it);
    if (it[0] == 0) return;
    do {
      tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
      u8 *x = (*(v1o_t **)tab)[0x58 / 4](tab, e);
      (*(v3_t **)x)[0x128 / 4](x, *(u16 *)(d + 0x52), 0, 0);
      l = *(u8 **)(o + 0x18);
      e = (*(v1r_t **)l)[0x5c / 4](l, (u32)it);
    } while (it[0] != 0);
  } else {
    (*(v3_t **)o)[0x128 / 4](o, *(u16 *)(d + 0x52), 0, 0);
  }
}
PCREG(5b7ad0, fn5b7ad0);
