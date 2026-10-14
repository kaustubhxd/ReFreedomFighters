// batch35146.cpp - cascade s5 batch 35146: 0x4f26d0 (GUESS walk a chain of objects, dispatching each to this until a done flag is set).
#include "ff.h"

typedef u32(THISCALL *g0_t)(void *, void *);
typedef void(THISCALL *v3_t)(void *, void *, u32, void *);
typedef u8 *(THISCALL *n0_t)(void *);
typedef u8(THISCALL *b1_t)(void *, u32);

// 0x4f26d0, thiscall(a, b) ret 8, returns al. b == 0 returns 0. Otherwise a[0x10] = 0; a[0] = engine table slot 0x4c(b); while a[0x10] == 0 and b != 0:
// this slot 0x130(b, 0x8000, a); b = b slot 0x20(); b = b slot 0x1e0(0x10002e) ? b : 0. Returns a[0x10].
static u8 THISCALL fn4f26d0(u8 *self, u8 *a, u8 *b) {
  if (!b) return 0;
  a[0x10] = 0;
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  *(u32 *)a = (*(g0_t **)tab)[0x4c / 4](tab, b);
  while (a[0x10] == 0 && b) {
    (*(v3_t **)self)[0x130 / 4](self, b, 0x8000, a);
    b = (*(n0_t **)b)[0x20 / 4](b);
    if (!(*(b1_t **)b)[0x1e0 / 4](b, 0x10002e)) b = 0;
  }
  return a[0x10];
}
PCREG(4f26d0, fn4f26d0);
