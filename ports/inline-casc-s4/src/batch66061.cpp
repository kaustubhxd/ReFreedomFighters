// batch66061.cpp - cascade s4 batch 66061: 0x502fe0 (tier F row).
#include "ff.h"

typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef u32(THISCALL *v5r_t)(void *, u32, u32, u32, u32, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 i);   // ret 4

// 0x502fe0, thiscall(p) ret 4 (this = t): a = **0x5003d0(p[4], 0); r = 0x5003d0(p[4], 1): tag r[4] == 3 -> id = r[0]; 4 -> id = (*r)->slot 0x34(); else log (0x111, 0x69c8e0: 0x69c6b0, 0x69c9b0), assert hook (int3 when none), id = 0.
// v[0..2] = **0x5003d0(p[4], 2 / 3 / 4); vt = *t[0xc]; h = (u16) sys[0x9b]->slot 0x45 (0x114)(id, 0, 0x69ca10, 0xe4, v); t[0xc]->(vt slot 0x4b (0x12c))(a, h).
static void THISCALL fn502fe0(u8 *t, u8 *p) {
  u32 v[3];
  u32 a = rd(ext_5003d0(*(u8 **)(p + 4), 0));
  u8 *r = ext_5003d0(*(u8 **)(p + 4), 1);
  u32 id;
  u32 tag = r[4];
  if (tag == 3) {
    id = rd(r);
  } else if (tag == 4) {
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
  v[0] = rd(ext_5003d0(*(u8 **)(p + 4), 2));
  v[1] = rd(ext_5003d0(*(u8 **)(p + 4), 3));
  v[2] = rd(ext_5003d0(*(u8 **)(p + 4), 4));
  void **vt = **(void ****)(t + 0xc);
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 hh = (u16)(*(v5r_t **)tab)[0x114 / 4](tab, id, 0, 0x69ca10u, 0xe4u, (u32)v);
  u8 *w = *(u8 **)(t + 0xc);
  ((v2_t)vt[0x12c / 4])(w, a, hh);
}
PCREG(502fe0, fn502fe0);
