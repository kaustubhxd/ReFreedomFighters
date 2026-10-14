// batch36014.cpp - cascade s4 batch 36014: 0x64d170, 0x432030, 0x459ab0, 0x461f00, 0x4c9660 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v1u_t)(void *, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void(THISCALL *v6_t)(void *, u32, u32, u32, u32, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u32 THISCALL ext_63f2d0(void *self, void *a);  // ret 4
extern "C" void THISCALL ext_63da80(void *self, void *a); // ret 4

// 0x64d170, thiscall(a, b) ret 8 (this = E), returns node: ebx = 0x63f2d0(E[0x1005d], a); i = u16 a[8][0x5a] & 0xfff; node = E[0x10071][i];
// null: node = E[0x10155]->slot 8(); node[0x20] = b; node[8] = ebx; E[0x10071][i] = node. Node bit 0 of byte [5] clear: node[8][0x43]++, 0x63da80(E[0x1005d], node),
// (E+0xc)->slot 8(&node). Finally node[0x10] = [0x70039c][0x3c], u16 node[0x1e] = 0, node[0x14] = node[0x18] = 0.
static u8 *THISCALL fn64d170(u8 *E, u8 *a, u32 b) {
  u8 *edi = *(u8 **)(a + 8);
  u32 ebx = ext_63f2d0(*(u8 **)(E + 0x1005d), a);
  u32 idx = *(u16 *)(edi + 0x5a) & 0xfffu;
  u8 *node = ((u8 **)rd(E + 0x10071))[idx];
  if (!node) {
    u8 *pool = *(u8 **)(E + 0x10155);
    node = (*(v0o_t **)pool)[8 / 4](pool);
    wr(node + 0x20, b);
    wr(node + 8, ebx);
    idx = *(u16 *)(edi + 0x5a) & 0xfffu;
    ((u8 **)rd(E + 0x10071))[idx] = node;
  }
  if (!(node[5] & 1)) {
    u8 *w = *(u8 **)(node + 8);
    w[0x43]++;
    ext_63da80(*(u8 **)(E + 0x1005d), node);
    u8 *sub = E + 0xc;
    (*(v1_t **)sub)[8 / 4](sub, (u32)&node);
  }
  wr(node + 0x10, rd(G(u8 *, 0x70039c) + 0x3c));
  *(u16 *)(node + 0x1e) = 0;
  wr(node + 0x14, 0);
  wr(node + 0x18, 0);
  return node;
}
PCREG(64d170, fn64d170);

// 0x432030, thiscall(a) ret 4 (this = E): v = E->slot 0x10(a); v >> 16: 0 -> 0x67a1a4, 1 -> 0x67a1b0, 2 -> 0x67a1b8. Else p = E->slot 0xc(v); S = *([0x70039c] + 0x190b);
// p in [S[8], S[8] + S[0xc]*12) -> 0x67a1a4; p in [S[0x18], S[0x18] + S[0x1c]*12) -> 0x67a1b0; p in [S[0x28], S[0x28] + S[0x2c]*12) -> 0x67a1b8; else 0x677a44.
static u32 THISCALL fn432030(u8 *E, u32 a) {
  u32 v = (*(v1u_t **)E)[0x10 / 4](E, a);
  u32 hi = v >> 16;
  if (hi == 0) return 0x67a1a4;
  if (hi == 1) return 0x67a1b0;
  if (hi == 2) return 0x67a1b8;
  u32 p = (*(v1u_t **)E)[0xc / 4](E, v);
  u8 *S = *(u8 **)(G(u8 *, 0x70039c) + 0x190b);
  u32 s8 = rd(S + 8);
  if (!(p < s8) && p < s8 + rd(S + 0xc) * 12) return 0x67a1a4;
  u32 s18 = rd(S + 0x18);
  if (!(p < s18) && p < s18 + rd(S + 0x1c) * 12) return 0x67a1b0;
  u32 s28 = rd(S + 0x28);
  if (p < s28) return 0x677a44;
  if (p < s28 + rd(S + 0x2c) * 12) return 0x67a1b8;
  return 0x677a44;
}
PCREG(432030, fn432030);

// 0x459ab0, thiscall(a, b) ret 8, returns 0 (this = E): when E[0x20] == [0x70039c][0x3c]: E[0x1c]++; else E[0x1c] = 0, E[0x20] = [0x70039c][0x3c].
// i = E[0x1c] < 4 and E[0x40] non-null: d = E + 0xd4 + i*0xa0; E->slot 0x80(buf34, buf10); d[0xc] = b[0x68]; d[8] = b[0x64]; a->slot 0x28(E[0x40], d, buf34, buf10, 0, 0).
static u8 THISCALL fn459ab0(u8 *E, u8 *a, u8 *b) {
  u32 buf34[9];
  u32 buf10[3];
  if (rd(E + 0x20) != rd(G(u8 *, 0x70039c) + 0x3c)) {
    wr(E + 0x1c, 0);
    wr(E + 0x20, rd(G(u8 *, 0x70039c) + 0x3c));
  } else {
    wr(E + 0x1c, rd(E + 0x1c) + 1);
  }
  u32 i = rd(E + 0x1c);
  if (i >= 4) return 0;
  u8 *d = E + 0xd4 + i * 0xa0;
  if (rd(E + 0x40) == 0) return 0;
  (*(v2_t **)E)[0x80 / 4](E, (u32)buf34, (u32)buf10);
  wr(d + 0xc, rd(b + 0x68));
  wr(d + 8, rd(b + 0x64));
  (*(v6_t **)a)[0x28 / 4](a, rd(E + 0x40), (u32)d, (u32)buf34, (u32)buf10, 0, 0);
  return 0;
}
PCREG(459ab0, fn459ab0);

extern "C" void ext_634273(void *p, u32 n);  // cdecl

// 0x461f00, thiscall(no args) (this = E): c = E[0x18]: non-null: c->slot 0x4c(&loc); each r = E[0x18]->slot 0x64(&loc) until null: r[0x70] non-null -> its slot 0(1), r[0x70] = 0;
// then c->slot 0(1) and E[0x18] = 0. Then E[0x1c] non-null -> 0x634273(E[0x1c], 0x18); E[0x6c] non-null -> slot 0x2c(1); E[0x6c] = E[0x1c] = 0.
static void THISCALL fn461f00(u8 *E) {
  u32 loc[3];
  u8 *c = *(u8 **)(E + 0x18);
  if (c) {
    (*(v1_t **)c)[0x4c / 4](c, (u32)loc);
    c = *(u8 **)(E + 0x18);
    u8 *r = (*(v1o_t **)c)[0x64 / 4](c, (u32)loc);
    while (r) {
      u8 *o = *(u8 **)(r + 0x70);
      if (o) {
        (*(v1_t **)o)[0](o, 1);
        wr(r + 0x70, 0);
      }
      c = *(u8 **)(E + 0x18);
      r = (*(v1o_t **)c)[0x64 / 4](c, (u32)loc);
    }
    c = *(u8 **)(E + 0x18);
    if (c) (*(v1_t **)c)[0](c, 1);
    wr(E + 0x18, 0);
  }
  u32 q = rd(E + 0x1c);
  if (q) ext_634273((void *)q, 0x18);
  u8 *o2 = *(u8 **)(E + 0x6c);
  if (o2) (*(v1_t **)o2)[0x2c / 4](o2, 1);
  wr(E + 0x6c, 0);
  wr(E + 0x1c, 0);
}
PCREG(461f00, fn461f00);

// 0x4c9660, thiscall(s) ret 4, returns 1 (this = E): E[4] &= ~0x40; s->slot 0x68(E+0x4c); slot 0x60(E[0x58]), (E[0x59]), (E[0x5a]) (bytes); slot 0x40(u16 E[0x48]), (u16 E[0x4a]);
// slot 0x54(E[0x5b] dword); slot 0x68(E+0x5f), (E+0x6b), (E+0x77).
static u8 THISCALL fn4c9660(u8 *E, u8 *s) {
  wr(E + 4, rd(E + 4) & 0xffffffbfu);
  (*(v1_t **)s)[0x68 / 4](s, (u32)(E + 0x4c));
  (*(v1_t **)s)[0x60 / 4](s, E[0x58]);
  (*(v1_t **)s)[0x60 / 4](s, E[0x59]);
  (*(v1_t **)s)[0x60 / 4](s, E[0x5a]);
  (*(v1_t **)s)[0x40 / 4](s, *(u16 *)(E + 0x48));
  (*(v1_t **)s)[0x40 / 4](s, *(u16 *)(E + 0x4a));
  (*(v1_t **)s)[0x54 / 4](s, rd(E + 0x5b));
  (*(v1_t **)s)[0x68 / 4](s, (u32)(E + 0x5f));
  (*(v1_t **)s)[0x68 / 4](s, (u32)(E + 0x6b));
  (*(v1_t **)s)[0x68 / 4](s, (u32)(E + 0x77));
  return 1;
}
PCREG(4c9660, fn4c9660);
