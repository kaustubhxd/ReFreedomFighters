// batch36053.cpp - cascade s4 batch 36053: 0x4b48c0, 0x4c61c0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef u32(THISCALL *v4r_t)(void *, u32, u32, u32, u32);
typedef u8 *(THISCALL *v4o_t)(void *, u32, u32, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u8 *THISCALL ext_4db520(void *self);   // plain ret: next sibling

// 0x4b48c0, stdcall(p) ret 4 returns eax: p == 0 or !(u8)p->slot 0x1e0(0x100001) -> 0. Walk n = p[0x54], n = 0x4db520(n): x = n[0x54]; flags = x ? x[0xc][0x23] : 0x200002; flags & 0x100000 -> return 0 (also when n == 0).
// x: (u8)x->slot 0x1e0(0x200027) -> return x; (u8)x->slot 0x1e0(0x200006) -> logger(0x691edc, 0x2a0) prints (cdecl 3 args) 0x6920d8, p[4].
static u32 STDCALL fn4b48c0(u8 *p) {
  if (!p) return 0;
  if (!(u8)(*(v1r_t **)p)[0x1e0 / 4](p, 0x100001u)) return 0;
  u8 *n = *(u8 **)(p + 0x54);
  for (;;) {
    if (!n) return 0;
    u8 *x = *(u8 **)(n + 0x54);
    u32 flags = x ? rd(*(u8 **)(x + 0xc) + 0x23) : 0x200002;
    if (flags & 0x100000) return 0;
    if (x) {
      if ((u8)(*(v1r_t **)x)[0x1e0 / 4](x, 0x200027u)) return (u32)x;
      if ((u8)(*(v1r_t **)x)[0x1e0 / 4](x, 0x200006u)) {
        u8 *db = G(u8 *, 0x700390);
        u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x691edcu, 0x2a0u);
        void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
        ((void (*)(u8 *, u32, u32))fn)(lo, 0x6920d8u, rd(p + 4));
      }
    }
    n = ext_4db520(n);
  }
}
PCREG(4b48c0, fn4b48c0);

extern "C" void THISCALL ext_4db500(void *self, u32 *out);   // ret 4: out = {self[0x24], self[0x28], self[0x2c]}

// 0x4c61c0, thiscall() plain ret (this = s): s[0x48] = (u16)tab->slot 0x114(0x694cec, 0, 0x694ad8, 0x3a0); o = sys[0x9b][0xadc]->slot 0x25c(0x68d404, 0); o == 0: o = mgr->slot 0x294(0x68d404, 0x67f610, 0, 1).
// 0x4db500(s[0x44][8], &v); s[0x44]->slot 0x70(&v); o->slot 0x218(s[0x44]); t = tab->slot 0x58(s[0x4a]); t -> t->slot 0xbc(1); s[0x44]->slot 0xbc(1).
static void THISCALL fn4c61c0(u8 *s) {
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 ax = (u16)(*(v4r_t **)tab)[0x114 / 4](tab, 0x694cecu, 0, 0x694ad8u, 0x3a0u);
  *(u16 *)(s + 0x48) = (u16)ax;
  u8 *mgr = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xadc);
  u8 *o = (*(v2o_t **)mgr)[0x25c / 4](mgr, 0x68d404u, 0);
  if (!o) {
    mgr = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xadc);
    o = (*(v4o_t **)mgr)[0x294 / 4](mgr, 0x68d404u, 0x67f610u, (u32)o, 1);
  }
  u32 v[3];
  ext_4db500(*(u8 **)(*(u8 **)(s + 0x44) + 8), v);
  u8 *w = *(u8 **)(s + 0x44);
  (*(v1_t **)w)[0x70 / 4](w, (u32)v);
  (*(v1_t **)o)[0x218 / 4](o, rd(s + 0x44));
  tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *t = (*(v1o_t **)tab)[0x58 / 4](tab, rd(s + 0x4a));
  if (t) (*(v1_t **)t)[0xbc / 4](t, 1);
  w = *(u8 **)(s + 0x44);
  (*(v1_t **)w)[0xbc / 4](w, 1);
}
PCREG(4c61c0, fn4c61c0);
