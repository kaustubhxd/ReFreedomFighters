// batch36059.cpp - cascade s4 batch 36059: 0x55c0c0, 0x600860 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef void (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 i);          // ret 4
extern "C" u32 THISCALL ext_5a2890(void *self, u32 a, u32 b);   // ret 8
extern "C" void THISCALL ext_5002f0(void *self, u32 a);         // ret 4

// 0x55c0c0, thiscall(p) ret 4 (this = s): r = 0x5003d0(p[4], 0); type r[4]: 3 -> id = r[0]; 4 -> id = (*r)->slot 0x34(); else logger(0x69c8e0, 0x111) prints (cdecl 3 args) 0x69c6b0, 0x69c9b0, assert hook (int3 when none), id = 0.
// v = *0x5003d0(p[4], 1); v < 0 (signed): logger(0x6a5eb0, 0x632) prints 0x6a600c, return. x = 0x5a2890(s[0x1c], id, v); 0x5002f0(0x5003d0(p[8], 0), x).
static void THISCALL fn55c0c0(u8 *s, u8 *p) {
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
  s32 v = (s32)rd(ext_5003d0(*(u8 **)(p + 4), 1));
  if (v < 0) {
    u8 *db = G(u8 *, 0x700390);
    u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x6a5eb0u, 0x632u);
    void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
    ((void (*)(u8 *, u32))fn)(lo, 0x6a600cu);
    return;
  }
  u32 x = ext_5a2890(*(u8 **)(s + 0x1c), id, (u32)v);
  u8 *y = ext_5003d0(*(u8 **)(p + 8), 0);
  ext_5002f0(y, x);
}
PCREG(55c0c0, fn55c0c0);

extern "C" u32 THISCALL ext_5fa220(void *self, u32 v);   // ret 4

// 0x600860, thiscall(a, b, c) ret 0xc (this = s): s[0x9c] -> self(s[0x9c], a, b, c). Then for the tables at s[0x84] + s[0x98] and s[0x80] + s[0x98] (each: count n at +0, entries of 6 bytes from +4 whose first dword is a pointer P):
// a->slot 0x2c(0x5fa220(c, *(u32 *)(P + b[0x9e]))) per entry.
static void THISCALL fn600860(u8 *s, u8 *a, u8 *b, u8 *c) {
  if (rd(s + 0x9c)) fn600860(*(u8 **)(s + 0x9c), a, b, c);
  u8 *base = *(u8 **)(s + 0x84) + rd(s + 0x98);
  u32 n = rd(base);
  u32 off = 0;
  if (n) {
    do {
      u8 *P = *(u8 **)(base + off + 4);
      u32 v = rd(P + rd(b + 0x9e));
      u32 k = ext_5fa220(c, v);
      (*(v1_t **)a)[0x2c / 4](a, k);
      off += 6;
      n--;
    } while (n);
  }
  u8 *base2 = *(u8 **)(s + 0x80) + rd(s + 0x98);
  u32 n2 = rd(base2);
  u32 off2 = 0;
  if (n2) {
    do {
      u8 *P = *(u8 **)(base2 + off2 + 4);
      u32 v = rd(P + rd(b + 0x9e));
      u32 k = ext_5fa220(c, v);
      (*(v1_t **)a)[0x2c / 4](a, k);
      off2 += 6;
      n2--;
    } while (n2);
  }
}
PCREG(600860, fn600860);
