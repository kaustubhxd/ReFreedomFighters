// batch36067.cpp - cascade s4 batch 36067: 0x5d3520, 0x605010 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(THISCALL *v2r_t)(void *, u32, u32);
typedef void (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// 0x5d3520, thiscall() plain ret (this = s): for the names 0x685a0c / 0x6ac8a8 / 0x6ac8b4 / 0x6ac8c0: o = tab->slot 0x138(); id = 0; o->slot 0x88(name, &id); s[0x55 / 0x59 / 0x5d / 0x61] = tab->slot 0x58(id).
static void THISCALL fn5d3520(u8 *s) {
  static const u32 names[4] = {0x685a0c, 0x6ac8a8, 0x6ac8b4, 0x6ac8c0};
  static const u32 offs[4] = {0x55, 0x59, 0x5d, 0x61};
  for (int i = 0; i < 4; i++) {
    u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *o = (*(v0o_t **)tab)[0x138 / 4](tab);
    u32 id = 0;
    (*(v2_t **)o)[0x88 / 4](o, names[i], (u32)&id);
    tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    wr(s + offs[i], (u32)(*(v1o_t **)tab)[0x58 / 4](tab, id));
  }
}
PCREG(5d3520, fn5d3520);

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 i);   // ret 4

// 0x605010, thiscall(p) ret 4 (this = d): v = *0x5003d0(p[4], 0); reg = [0x724270]; r = reg->slot 6 (0x18)(d[0xc], v[0xc]); q = 0x5003d0(p[8], 0).
// r == 0: q[4] <= 1 (unsigned byte) -> q[0] = 1, q[4] = 1; else logger(0x69c8e0, 0xc4) prints (cdecl 3 args) 0x69c6b0, 0x69c938 and assert hook (int3 when none).
// r != 0: the same with q[0] = 0.
static void THISCALL fn605010(u8 *d, u8 *p) {
  u8 *v = *(u8 **)ext_5003d0(*(u8 **)(p + 4), 0);
  u8 *reg = G(u8 *, 0x724270);
  u32 r = (*(v2r_t **)reg)[0x18 / 4](reg, rd(d + 0xc), rd(v + 0xc));
  u8 *q = ext_5003d0(*(u8 **)(p + 8), 0);
  u32 val = r == 0 ? 1 : 0;
  if (q[4] <= 1) {
    wr(q, val);
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
PCREG(605010, fn605010);
