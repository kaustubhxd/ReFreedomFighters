// batch36074.cpp - cascade s4 batch 36074: 0x50f3e0, 0x50fc20, 0x6474f0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef void (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u8 *THISCALL ext_5003d0(void *self, u32 i);   // ret 4

static u32 typed_id(u8 *r) {
  u32 t = r[4];
  if (t == 3) return rd(r);
  if (t == 4) {
    u8 *o = *(u8 **)r;
    return (*(v0r_t **)o)[0x34 / 4](o);
  }
  u8 *db = G(u8 *, 0x700390);
  u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x69c8e0u, 0x111u);
  void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
  ((void (*)(u8 *, u32, u32))fn)(lo, 0x69c6b0u, 0x69c9b0u);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
  return 0;
}

// 0x50f3e0 (same as 0x50a770 with the table slot 0x138), stdcall(p) ret 4: id = typed id of 0x5003d0(p[4], 0) (type 3 direct, 4 via slot 0x34, else log + assert, 0); o = tab->slot 0x4d (0x134)(); v = 0; o->slot 0x22 (0x88)(id, &v); q = 0x5003d0(p[8], 0);
// q[4] <= 1 (unsigned byte): q[0] = v, q[4] = 1. Otherwise logger(0x69c8e0, 0xc4) prints (cdecl 3 args) 0x69c6b0, 0x69c938 and assert hook (int3 when none).
static void STDCALL fn50f3e0(u8 *p) {
  u32 id = typed_id(ext_5003d0(*(u8 **)(p + 4), 0));
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = (*(v0o_t **)tab)[0x138 / 4](tab);
  u32 v = 0;
  (*(v2_t **)o)[0x88 / 4](o, id, (u32)&v);
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
PCREG(50f3e0, fn50f3e0);

// 0x50fc20 (same as 0x50ae00 with the table slot 0x138), stdcall(p) ret 4: o = tab->slot 0x4d (0x134)(); b = 0x5003d0(p[4], 1); id = typed id of 0x5003d0(p[4], 0) (as above); o->slot 0x17 (0x5c)(id, *b, 2).
static void STDCALL fn50fc20(u8 *p) {
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = (*(v0o_t **)tab)[0x138 / 4](tab);
  u8 *b = ext_5003d0(*(u8 **)(p + 4), 1);
  u32 id = typed_id(ext_5003d0(*(u8 **)(p + 4), 0));
  (*(v3_t **)o)[0x5c / 4](o, id, rd(b), 2);
}
PCREG(50fc20, fn50fc20);

extern "C" void FASTCALL ext_4df1e0(u8 *a, u8 *b);   // plain ret
extern "C" void FASTCALL ext_4de420(u8 *a, u8 *b);   // plain ret
extern "C" void FASTCALL ext_4de480(u8 *a, u8 *b);   // plain ret
extern "C" void FASTCALL ext_4419f0(u8 *a, u8 *b);   // plain ret
extern "C" void FASTCALL ext_441940(u8 *a, u8 *b);   // plain ret

// 0x6474f0, stdcall(A, idx, C, D) ret 0x10: walk the chain idx -> D[idx * 0x30 + 0xc] (until 0): for each idx: e = A + idx * 0x30, s = C + idx * 0x30; 0x4df1e0(e, s); e[0x24..0x2c] = s[0x24..0x2c]; push e on a local stack.
// Then 0x4de420(A, C) with A[0x24..0x2c] = C[0x24..0x2c], and the root A appended to the stack; for k = count down to 1: x = stack[k], y = stack[k - 1]: 0x4de480(y, x); 0x4419f0(y + 0x24, x); 0x441940(y + 0x24, x + 0x24).
static void STDCALL fn6474f0(u8 *A, u32 idx, u8 *C, u8 *D) {
  u8 *stack[97];
  u32 n = 0;
  for (;;) {
    u32 off = idx * 0x30;
    u8 *s = C + off;
    u8 *e = A + off;
    ext_4df1e0(e, s);
    wr(e + 0x24, rd(s + 0x24));
    wr(e + 0x28, rd(s + 0x28));
    wr(e + 0x2c, rd(s + 0x2c));
    stack[n] = e;
    n++;
    idx = rd(D + off + 0xc);
    if (idx == 0) break;
  }
  stack[n] = A;
  ext_4de420(A, C);
  wr(A + 0x24, rd(C + 0x24));
  wr(A + 0x28, rd(C + 0x28));
  wr(A + 0x2c, rd(C + 0x2c));
  u32 k = n;
  while (k != 0) {
    u8 *x = stack[k];
    k--;
    u8 *y = stack[k];
    ext_4de480(y, x);
    ext_4419f0(y + 0x24, x);
    ext_441940(y + 0x24, x + 0x24);
  }
}
PCREG(6474f0, fn6474f0);
