// batch36066.cpp - cascade s4 batch 36066: 0x50a940, 0x5359f0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef u32(THISCALL *v4r_t)(void *, u32, u32, u32, u32);
typedef void (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 i);   // ret 4

// 0x50a940, stdcall(p) ret 4: r = 0x5003d0(p[4], 0); type r[4]: 3 -> id = r[0]; 4 -> id = (*r)->slot 0x34(); else logger(0x69c8e0, 0x111) prints (cdecl 3 args) 0x69c6b0, 0x69c9b0, assert hook (int3 when none), id = 0.
// v = (u16)tab->slot 0x114(id, 0, 0x69d350, 0xdb); q = 0x5003d0(p[8], 0); q[4] <= 1 (unsigned byte): q[0] = v, q[4] = 1. Otherwise logger(0x69c8e0, 0xc4) prints 0x69c6b0, 0x69c938 and assert hook (int3 when none), return.
static void STDCALL fn50a940(u8 *p) {
  u8 *r = ext_5003d0(*(u8 **)(p + 4), 0);
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
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 v = (u16)(*(v4r_t **)tab)[0x114 / 4](tab, id, 0, 0x69d350u, 0xdbu);
  u8 *q = ext_5003d0(*(u8 **)(p + 8), 0);
  if (q[4] <= 1) {
    wr(q, v);
    q[4] = 1;
    return;
  }
  u8 *db = G(u8 *, 0x700390);
  u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x69c8e0u, 0xc4u);
  void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
  ((void (*)(u8 *, u32, u32))fn)(lo, 0x69c6b0u, 0x69c938u);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}
PCREG(50a940, fn50a940);

// 0x5359f0, thiscall(a, b) ret 8 returns al (this = d): list heads a[0x30], a[0x34] (0 = empty, 0x80000000 = end); nodes at d + 0x10a7 + k * 8 = {id, next}. Both empty -> 1. Head a[0x30]: 0x80000000 -> 0; walk: id -> tab->slot 0x58(id) == b -> 1; end of the list without a match -> 0.
// Otherwise head a[0x34]: 0 or 0x80000000 -> 1; walk: object == b -> 0; end -> 1.
static u8 THISCALL fn5359f0(u8 *d, u8 *a, u8 *b) {
  u32 first = rd(a + 0x30);
  if (first == 0 && rd(a + 0x34) == 0) return 1;
  u32 k;
  if (first != 0) {
    if (first == 0x80000000u) return 0;
    k = first;
    for (;;) {
      u8 *node = (k != 0 && k != 0x80000000u) ? d + 0x10a7 + k * 8 : 0;
      u32 id = rd(node);
      u32 next = rd(node + 4);
      u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
      u8 *o = (*(v1o_t **)tab)[0x58 / 4](tab, id);
      if (o == b) return 1;
      if (next == 0x80000000u) return 0;
      k = next;
    }
  }
  k = rd(a + 0x34);
  if (k == 0 || k == 0x80000000u) return 1;
  for (;;) {
    u8 *node = (k != 0 && k != 0x80000000u) ? d + 0x10a7 + k * 8 : 0;
    u32 id = rd(node);
    u32 next = rd(node + 4);
    u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *o = (*(v1o_t **)tab)[0x58 / 4](tab, id);
    if (o == b) return 0;
    if (next == 0x80000000u) return 1;
    k = next;
  }
}
PCREG(5359f0, fn5359f0);
