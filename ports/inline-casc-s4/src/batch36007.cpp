// batch36007.cpp - cascade s4 batch 36007: 0x63f950, 0x64f6a0 (tier F rows).
#include "ff.h"

typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef void(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v0r_t)(void *);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// 0x63f950, thiscall(p) ret 4 (this = E): E[0xc]--; b = E->slot 0x2c(p); p[5] &= 0xfd; p[0..1] = u16 b[2]; b[0]--; b[2..3] = (p - b - 0x10) >> 6 (arithmetic).
// b[0] == 0: when E[8] == b: E[8] = (b[8] == b ? 0 : b[8]); unlink b (b[8][0xc] = b[0xc], b[0xc][8] = b[8]); E->slot 0x34(b).
// b[0] != 0 and b != E[8]: unlink b and relink it as the new head (E[8]) of the circular list.
static void THISCALL fn63f950(u8 *E, u8 *p) {
  wr(E + 0xc, rd(E + 0xc) - 1);
  u8 *b = (*(v1o_t **)E)[0x2c / 4](E, (u32)p);
  p[5] &= 0xfd;
  u16 cx = *(u16 *)(b + 2);
  b[0]--;
  *(u16 *)p = cx;
  s32 idx = ((s32)((u32)p - (u32)b) - 0x10) >> 6;
  *(u16 *)(b + 2) = (u16)idx;
  if (b[0] == 0) {
    if (*(u8 **)(E + 8) == b) {
      u8 *n = *(u8 **)(b + 8);
      if (n == b) n = 0;
      *(u8 **)(E + 8) = n;
    }
    u8 *n1 = *(u8 **)(b + 8);
    wr(n1 + 0xc, rd(b + 0xc));
    u8 *n2 = *(u8 **)(b + 0xc);
    wr(n2 + 8, rd(b + 8));
    (*(v1_t **)E)[0x34 / 4](E, (u32)b);
    return;
  }
  if (b == *(u8 **)(E + 8)) return;
  u8 *n1 = *(u8 **)(b + 8);
  wr(n1 + 0xc, rd(b + 0xc));
  u8 *n2 = *(u8 **)(b + 0xc);
  wr(n2 + 8, rd(b + 8));
  u8 *head = *(u8 **)(E + 8);
  wr(b + 8, (u32)head);
  u8 *tail = *(u8 **)(head + 0xc);
  wr(b + 0xc, (u32)tail);
  wr(tail + 8, (u32)b);
  wr(head + 0xc, (u32)b);
  wr(E + 8, (u32)b);
}
PCREG(63f950, fn63f950);

extern "C" void THISCALL ext_648e50(void *self, u32 a);   // ret 4
extern "C" void THISCALL ext_64dde0(void *self, u32 *a);  // ret 4

// 0x64f6a0, thiscall(a) ret 4 (this = E): r = E->slot 0xa4(0); r != 0: 0x648e50(r, a), return. Else with h = *([0x70039c] + 0x190f) (unaligned):
// s = h->slot 0xd8(), v = h->slot 0xdc(); rec = {0, 0, s, v}; q = E->slot 0xa0(0); 0x64dde0(q, &rec); 0x648e50(q, a).
static void THISCALL fn64f6a0(u8 *E, u32 a) {
  u8 *r = (*(v1o_t **)E)[0xa4 / 4](E, 0);
  if (r) {
    ext_648e50(r, a);
    return;
  }
  u8 *h = *(u8 **)(G(u8 *, 0x70039c) + 0x190f);
  u32 s = (*(v0r_t **)h)[0xd8 / 4](h);
  h = *(u8 **)(G(u8 *, 0x70039c) + 0x190f);
  u32 v = (*(v0r_t **)h)[0xdc / 4](h);
  u32 rec[4] = {0, 0, s, v};
  u8 *q = (*(v1o_t **)E)[0xa0 / 4](E, 0);
  ext_64dde0(q, rec);
  ext_648e50(q, a);
}
PCREG(64f6a0, fn64f6a0);
