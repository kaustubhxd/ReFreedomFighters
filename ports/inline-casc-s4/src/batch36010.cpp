// batch36010.cpp - cascade s4 batch 36010: 0x501f80, 0x5270f0, 0x62de00, 0x64d5f0, 0x6590e0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v1u_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef u32(THISCALL *v4r_t)(void *, u32, u32, u32, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32 (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 a);  // ret 4

// 0x501f80, thiscall(a) ret 4 (this = E): rec = 0x5003d0(a[4], 1); by rec byte [4]: 3 -> id = rec[0]; 4 -> id = o->slot 0x34() with o = rec[0]; else log
// (db slot 0x20(0x69c8e0, 0x111), o->slot 0x2c(o, 0x69c6b0, 0x69c9b0) cdecl), assert hook (int3 when null), id = 0.
// h = ([0x70039c]+0x9b)->slot 0x114(id, 0, 0x69ca10, 0x238); E[0xc]->slot 0x12c(0x5003d0(a[4], 0)[0], (u16)h, 0).
static void THISCALL fn501f80(u8 *E, u8 *a) {
  u8 *rec = ext_5003d0(*(u8 **)(a + 4), 1);
  u32 id;
  u32 t = rec[4];
  if (t == 3) {
    id = rd(rec);
  } else if (t == 4) {
    u8 *o = *(u8 **)rec;
    id = (*(v0r_t **)o)[0x34 / 4](o);
  } else {
    u8 *db = G(u8 *, 0x700390);
    u8 *o = (*(v2o_t **)db)[0x20 / 4](db, 0x69c8e0u, 0x111u);
    void **vt2 = *(void ***)o;
    void *fn = *(void **)((u8 *)vt2 + 0x2c);
    __asm__ volatile("pushl %[b]\n\tpushl %[a]\n\tpushl %[o]\n\tcall *%[f]\n\taddl $12, %%esp"
                     : "+c"(vt2)
                     : [b] "i"(0x69c9b0), [a] "i"(0x69c6b0), [o] "r"(o), [f] "r"(fn)
                     : "eax", "edx", "memory", "cc");
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
    id = 0;
  }
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 r = (*(v4r_t **)tab)[0x114 / 4](tab, id, 0, 0x69ca10u, 0x238u);
  u8 *rec2 = ext_5003d0(*(u8 **)(a + 4), 0);
  u8 *w = *(u8 **)(E + 0xc);
  (*(v3_t **)w)[0x12c / 4](w, rd(rec2), (u32)(u16)r, 0);
}
PCREG(501f80, fn501f80);

// 0x5270f0, thiscall(s) ret 4, returns 1 (this = E): stream s: slot 0x50 -> E+4, +8, +0xc, +0x10, +0x14; slot 0x68 -> +0x18; slot 0x18(E+0x19, 4); slot 0x50 -> +0x1d, +0x21, +0x25.
static u8 THISCALL fn5270f0(u8 *E, u8 *s) {
  static const u8 idx[] = {4, 8, 0xc, 0x10, 0x14};
  for (u32 i = 0; i < 5; i++) (*(v1_t **)s)[0x50 / 4](s, (u32)(E + idx[i]));
  (*(v1_t **)s)[0x68 / 4](s, (u32)(E + 0x18));
  (*(v2o_t **)s)[0x18 / 4](s, (u32)(E + 0x19), 4);
  (*(v1_t **)s)[0x50 / 4](s, (u32)(E + 0x1d));
  (*(v1_t **)s)[0x50 / 4](s, (u32)(E + 0x21));
  (*(v1_t **)s)[0x50 / 4](s, (u32)(E + 0x25));
  return 1;
}
PCREG(5270f0, fn5270f0);

typedef u32 (*cb_t)(u32, u32, u32, u32);

// 0x62de00, cdecl(out, code, b, c, obj): code 0xf returns 0. code 0x12: obj[0x1c](obj, b, c, 0x6c0208) nonzero -> out[0] = 0x62dee0, return 0;
// else obj[0x1c](obj, b, c, 0x6c01f4) nonzero -> out[0] = 0x62de90, return 0. Then out[0xc] == 0 && code == 0x1c returns 0x34; else out[0] = 0x51f230, return -1.
static u32 fn62de00(u8 *out, u32 code, u32 b, u32 c, u8 *obj) {
  if (code == 0xf) return 0;
  if (code == 0x12) {
    cb_t cb = *(cb_t *)(obj + 0x1c);
    if (cb((u32)obj, b, c, 0x6c0208u)) {
      wr(out, 0x62dee0);
      return 0;
    }
    cb = *(cb_t *)(obj + 0x1c);
    if (cb((u32)obj, b, c, 0x6c01f4u)) {
      wr(out, 0x62de90);
      return 0;
    }
  }
  if (rd(out + 0xc) == 0 && code == 0x1c) return code + 0x18;
  wr(out, 0x51f230);
  return 0xffffffffu;
}
PCREG(62de00, fn62de00);

extern "C" void THISCALL ext_63ef00(void *self, void *a);  // ret 4

// 0x64d5f0, thiscall(p) ret 4 (this = E): p[5] &= 0xfe; p[0] = [0x70039c][0x3c]; R = E[0x1005d] (unaligned) + 0x268: i = ((R[0] - R - 8) >> 2) (u16); *R[0] = p; R[0] += 4, wrapping to R+8 at R+0x8008;
// q = p[8]; p[6] = i; c = E[0x10071][(u16 q[0x10][8][6]) & 0xfff]; c[0xc]-- == 0 -> E->slot 0x50(c); q[9]-- == 0 -> E[0x1005d]->slot 0xa4(q); A = q[0x10]; u16 A[0xc]-- == 0 -> 0x63ef00(E[0x1005d], A).
static void THISCALL fn64d5f0(u8 *E, u8 *p) {
  p[5] &= 0xfe;
  wr(p, rd(G(u8 *, 0x70039c) + 0x3c));
  u8 *X = *(u8 **)(E + 0x1005d);
  u8 *R = X + 0x268;
  u8 *w = *(u8 **)R;
  u32 i = (u32)((s32)((u32)w - (u32)R - 8) >> 2);
  *(u8 **)w = p;
  wr(R, rd(R) + 4);
  if (rd(R) == (u32)R + 0x8008) wr(R, (u32)R + 8);
  u8 *q = *(u8 **)(p + 8);
  *(u16 *)(p + 6) = (u16)i;
  u8 *A = *(u8 **)(q + 0x10);
  u8 *B = *(u8 **)(A + 8);
  u32 idx = *(u16 *)(B + 6) & 0xfffu;
  u8 *c = *(u8 **)(*(u8 **)(E + 0x10071) + idx * 4);
  u32 n = rd(c + 0xc) - 1;
  wr(c + 0xc, n);
  if (n == 0) (*(v1_t **)E)[0x50 / 4](E, (u32)c);
  u8 *q2 = *(u8 **)(p + 8);
  q2[9]--;
  if (q2[9] == 0) {
    u8 *x = *(u8 **)(E + 0x1005d);
    (*(v1_t **)x)[0xa4 / 4](x, (u32)q2);
  }
  u8 *A2 = *(u8 **)(q2 + 0x10);
  *(u16 *)(A2 + 0xc) = (u16)(*(u16 *)(A2 + 0xc) - 1);
  if (*(u16 *)(A2 + 0xc) == 0) ext_63ef00(*(u8 **)(E + 0x1005d), A2);
}
PCREG(64d5f0, fn64d5f0);

// 0x6590e0, thiscall(no args): for i in 0..3 and k in 0..25: E[0x10*k + 4*i] = E[src[k]].
static void THISCALL fn6590e0(u8 *E) {
  static const u16 src[26] = {0x1a8, 0x1ac, 0x1b0, 0x1cc, 0x1d0, 0x1d4, 0x1c0, 0x1c4, 0x1c8, 0x1b4, 0x1b8, 0x1bc, 0x1d8,
                              0x1dc, 0x1e0, 0x1e4, 0x1e8, 0x1ec, 0x224, 0x228, 0x22c, 0x230, 0x208, 0x210, 0x214, 0x220};
  for (u32 i = 0; i < 4; i++)
    for (u32 k = 0; k < 26; k++) wr(E + 0x10 * k + 4 * i, rd(E + src[k]));
}
PCREG(6590e0, fn6590e0);
