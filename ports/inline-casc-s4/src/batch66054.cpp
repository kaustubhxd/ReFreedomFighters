// batch66054.cpp - cascade s4 batch 66054: 0x5c8e00 (tier F row).
#include "ff.h"

typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u32 THISCALL ext_4dc110(void *self);              // plain ret: name pointer
extern "C" u32 FASTCALL ext_4cc850(u32 name, u32 pattern);   // fastcall wildcard match, 0 = match
extern "C" void THISCALL ext_4db860(void *self, u32 a);      // ret 4
extern "C" u8 *THISCALL ext_4db520(void *self);              // plain ret: next sibling

static u8 *tab() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x5c8e00, thiscall() plain ret (this = t): o = tab->slot 0x58(t[0x68]); h = o->slot 0xb1 (0x2c4)(tab[0xadc], 0x4d414755); h->slot 0xbc (0x2f0)(0, t[0x44], 1); t[0x70] = tab->slot 0x4c(h).
// For each child c of t[0x44] (first t[0x44][0x54], next 0x4db520) while the flags of c[0x54][0xc][0x23] (0x200002 without c[0x54]) lack 0x100000: 0x4cc850(0x4dc110(c), 0x6b4a3c) == 0 -> 0x4db860(c, 1).
// p = t[0x44]->slot 0x97 (0x25c)(0x68886c, 0) or t[0x44]; t[0x74] = tab->slot 0x4c(p); same with 0x688860 into t[0x78].
static void THISCALL fn5c8e00(u8 *t) {
  u8 *tb = tab();
  u8 *o = (*(v1o_t **)tb)[0x58 / 4](tb, rd(t + 0x68));
  tb = tab();
  u32 key = rd(tb + 0xadc);
  u8 *h = (*(v2o_t **)o)[0x2c4 / 4](o, key, 0x4d414755u);
  (*(v3_t **)h)[0x2f0 / 4](h, 0, rd(t + 0x44), 1);
  tb = tab();
  wr(t + 0x70, (u32)(*(v1o_t **)tb)[0x4c / 4](tb, (u32)h));
  u8 *c = *(u8 **)(*(u8 **)(t + 0x44) + 0x54);
  while (c) {
    u8 *w = *(u8 **)(c + 0x54);
    u32 flags = w ? rd(*(u8 **)(w + 0xc) + 0x23) : 0x200002;
    if (flags & 0x100000) break;
    u32 name = ext_4dc110(c);
    if (ext_4cc850(name, 0x6b4a3c) == 0) ext_4db860(c, 1);
    c = ext_4db520(c);
  }
  u8 *p0 = *(u8 **)(t + 0x44);
  u8 *p = (*(v2o_t **)p0)[0x25c / 4](p0, 0x68886cu, 0);
  if (!p) p = *(u8 **)(t + 0x44);
  tb = tab();
  wr(t + 0x74, (u32)(*(v1o_t **)tb)[0x4c / 4](tb, (u32)p));
  p0 = *(u8 **)(t + 0x44);
  p = (*(v2o_t **)p0)[0x25c / 4](p0, 0x688860u, 0);
  if (!p) p = *(u8 **)(t + 0x44);
  tb = tab();
  wr(t + 0x78, (u32)(*(v1o_t **)tb)[0x4c / 4](tb, (u32)p));
}
PCREG(5c8e00, fn5c8e00);
