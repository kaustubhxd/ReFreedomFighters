// batch36063.cpp - cascade s4 batch 36063: 0x5ffa20, 0x57ec10 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u32(THISCALL *v1r_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u32 THISCALL ext_5fa1e0(void *self, u32 v);   // ret 4

// 0x5ffa20, thiscall(a, b, c) ret 0xc (this = s): the reading counterpart of 0x600860. s[0x9c] -> self(s[0x9c], a, b, c). For the tables at s[0x84] + s[0x98], then s[0x80] + s[0x98] (count at +0, 6-byte entries from +4 whose first dword is a pointer P):
// a->slot 0x5c(&v); *(u32 *)(P + b[0x9e]) = 0x5fa1e0(c, v).
static void THISCALL fn5ffa20(u8 *s, u8 *a, u8 *b, u8 *c) {
  if (rd(s + 0x9c)) fn5ffa20(*(u8 **)(s + 0x9c), a, b, c);
  u8 *base = *(u8 **)(s + 0x84) + rd(s + 0x98);
  u32 n = rd(base);
  u32 off = 0;
  if (n) {
    do {
      u32 v = 0;
      (*(v1_t **)a)[0x5c / 4](a, (u32)&v);
      u32 r = ext_5fa1e0(c, v);
      u8 *P = *(u8 **)(base + off + 4);
      wr(P + rd(b + 0x9e), r);
      off += 6;
      n--;
    } while (n);
  }
  u8 *base2 = *(u8 **)(s + 0x80) + rd(s + 0x98);
  u32 n2 = rd(base2);
  u32 off2 = 0;
  if (n2) {
    do {
      u32 v = 0;
      (*(v1_t **)a)[0x5c / 4](a, (u32)&v);
      u32 r = ext_5fa1e0(c, v);
      u8 *P = *(u8 **)(base2 + off2 + 4);
      wr(P + rd(b + 0x9e), r);
      off2 += 6;
      n2--;
    } while (n2);
  }
}
PCREG(5ffa20, fn5ffa20);

extern "C" u32 THISCALL ext_563490(void *self, void *s);   // ret 4
extern "C" void THISCALL ext_57ebb0(void *self, void *s);  // ret 4

// 0x57ec10, thiscall(s) ret 4 returns al (this = d): 0x563490(d, s) false -> return (al of that). s->slot 0xf... (0x6c / 4)(d + 0x264); s->slot 0xf(0x3c)(tab->slot 0x4c(d[0x310])); again with d[0x314].
// Then iterate the list at d + 0x23c (slot 0x4c(&it), e = slot 0x5c(&it) while it[0]): 0x57ebb0([0x70038c]->slot 0xcc(e), s). return 1.
static u8 THISCALL fn57ec10(u8 *d, u8 *s) {
  if (!(u8)ext_563490(d, s)) return 0;
  void **svt = *(void ***)s;
  ((v1_t)svt[0x6c / 4])(s, (u32)(d + 0x264));
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 x = (u32)(*(v1o_t **)tab)[0x4c / 4](tab, rd(d + 0x310));
  ((v1_t)svt[0x3c / 4])(s, x);
  tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  void **svt2 = *(void ***)s;
  u32 y = (u32)(*(v1o_t **)tab)[0x4c / 4](tab, rd(d + 0x314));
  ((v1_t)svt2[0x3c / 4])(s, y);
  u8 *l = d + 0x23c;
  u32 it[3];
  (*(v1_t **)l)[0x4c / 4](l, (u32)it);
  u32 e = (*(v1r_t **)l)[0x5c / 4](l, (u32)it);
  if (it[0] != 0) {
    do {
      u8 *g = G(u8 *, 0x70038c);
      u8 *o = (*(v1o_t **)g)[0xcc / 4](g, e);
      ext_57ebb0(o, s);
      e = (*(v1r_t **)l)[0x5c / 4](l, (u32)it);
    } while (it[0] != 0);
  }
  return 1;
}
PCREG(57ec10, fn57ec10);
