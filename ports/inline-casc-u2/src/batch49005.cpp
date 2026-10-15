// batch49005.cpp - cascade u2 batch 49005: 0x55ad10 (take a vector from one table, transform it through a slot, store it into three flagged slots of another).
#include "ff.h"

extern "C" float *THISCALL ext_5003d0(void *tab, u32 idx);   // ret 4: slot pointer for an index
typedef void(THISCALL *v1_t)(void *, float *);
typedef void *(THISCALL *v2a_t)(void *, u32, u32);
typedef void (*log3_t)(void *, u32, u32);
typedef void (*hook_t)();

// the three-slot assert path shared by the stores: [0x700390] slot 0x20(file, line) gives a log object, its slot 0x2c prints, then the assert hook (int3 when null).
static void store_slot(void *tab, u32 idx, float v) {
  u8 *s = (u8 *)ext_5003d0(tab, idx);
  u8 st = s[4];
  if (st != 0 && st != 2) {
    void *lg = G(void *, 0x700390);
    void *lo = (*(v2a_t **)lg)[0x20 / 4](lg, 0x69c8e0, 0x104);
    (*(log3_t **)lo)[0x2c / 4](lo, 0x69c6b0, 0x69c938);
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    else h();
  }
  s[4] = 2;
  *(float *)s = v;
}

// 0x55ad10, thiscall(a) ret 4: a+4 is the source table (slots 2, 1, 0 give z, y, x), this+0x1c's slot 0x84 may rewrite the vector, then a+8 (dest table) slots 0, 1, 2 take x, y, z.
static void THISCALL fn55ad10(u8 *self, u8 *a) {
  float *z = ext_5003d0(*(void **)(a + 4), 2);
  float *y = ext_5003d0(*(void **)(a + 4), 1);
  float *x = ext_5003d0(*(void **)(a + 4), 0);
  float v[3] = {*x, *y, *z};
  void *o = *(void **)(self + 0x1c);
  (*(v1_t **)o)[0x84 / 4](o, v);
  float t = v[0];
  store_slot(*(void **)(a + 8), 0, t);
  t = v[1];
  store_slot(*(void **)(a + 8), 1, t);
  t = v[2];
  store_slot(*(void **)(a + 8), 2, t);
}
PCREG(55ad10, fn55ad10);
