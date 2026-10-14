// batch36071.cpp - cascade s4 batch 36071: 0x502f00, 0x498be0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef u32(THISCALL *v5r_t)(void *, u32, u32, u32, u32, u32);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 i);   // ret 4

// 0x502f00, thiscall(p) ret 4 (this = s): v = *0x5003d0(p[4], 0); r = 0x5003d0(p[4], 1); type r[4]: 3 -> id = r[0]; 4 -> id = (*r)->slot 0x34(); else logger(0x69c8e0, 0x111) prints (cdecl 3 args) 0x69c6b0, 0x69c9b0, assert hook (int3 when none), id = 0.
// loc = {*0x5003d0(p[4], 2), *0x5003d0(p[4], 3)}; ax = (u16)tab->slot 0x114(id, 0, 0x69ca10, 0xd5, loc); s[0xc]->slot 0x12c(v, ax).
static void THISCALL fn502f00(u8 *s, u8 *p) {
  u32 v = rd(ext_5003d0(*(u8 **)(p + 4), 0));
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
  u32 loc[2];
  loc[0] = rd(ext_5003d0(*(u8 **)(p + 4), 2));
  loc[1] = rd(ext_5003d0(*(u8 **)(p + 4), 3));
  u8 *w = *(u8 **)(s + 0xc);
  void **vt = *(void ***)w;
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 ax = (u16)(*(v5r_t **)tab)[0x114 / 4](tab, id, 0, 0x69ca10u, 0xd5u, (u32)loc);
  w = *(u8 **)(s + 0xc);
  ((v2_t)vt[0x12c / 4])(w, v, ax);
}
PCREG(502f00, fn502f00);

extern "C" void THISCALL ext_498f00(void *self, u8 *a, u8 *node);   // ret 8

// 0x498be0, thiscall(a) ret 4 (this = s): 0x498f00(s, a, [0x70039c][0x9b][0xadc][8]). For i < a[0xc]: bits = a[8][i]; bits != 0: for k in 0..7 (bit mask 1 << k): node = s[0x14][4] + i * 0x380 + k * 0x70; bit set and !(node[0x3c] & 0x4000000):
// follow node[0x50] to the last link and 0x498f00(s, a, last); bits = a[8][i] reloaded. Finally x = *a: x->slot 2 (8)(0xd); v = -1; x->slot 4 (0x10)(&v, 4).
static void THISCALL fn498be0(u8 *s, u8 *a) {
  u8 *tabX = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x9b) + 0xadc);
  ext_498f00(s, a, (u8 *)rd(tabX + 8));
  u32 off = 0;
  u32 i = 0;
  if (rd(a + 0xc) != 0) {
    do {
      u32 bits = (*(u8 **)(a + 8))[i];
      if (bits != 0) {
        u32 mask = 1;
        u8 *node = *(u8 **)(*(u8 **)(s + 0x14) + 4) + off;
        do {
          if ((bits & mask) && !(rd(node + 0x3c) & 0x4000000u)) {
            u8 *last = node;
            u8 *ch = *(u8 **)(node + 0x50);
            while (ch) {
              last = ch;
              ch = *(u8 **)(last + 0x50);
            }
            ext_498f00(s, a, last);
            bits = (*(u8 **)(a + 8))[i];
          }
          mask += mask;
          node += 0x70;
        } while (mask <= 0x80);
      }
      i++;
      off += 0x380;
    } while (i != rd(a + 0xc));
  }
  u8 *x = *(u8 **)a;
  (*(v1_t **)x)[8 / 4](x, 0xd);
  u32 v = 0xffffffffu;
  x = *(u8 **)a;
  (*(v2_t **)x)[0x10 / 4](x, (u32)&v, 4);
}
PCREG(498be0, fn498be0);
