// batch66077.cpp - cascade s4 batch 66077: 0x590140 (tier F row).
#include "ff.h"

typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

static u8 *tab() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x590140, thiscall(a) ret 4 (this = t): A = tab->slot 0x58(a); X = t->slot 0x141 (0x504)(); B = tab->slot 0x58(t[0x842]). A == X -> return.
// X set: X->slot 0xb4 (0x2d0)(0, 0); X->slot 0xba (0x2e8)()->slot 0xc2 (0x308)() == 1 -> t->slot 0xf6 (0x3d8)(t->slot 0xfb (0x3ec)(0x17)), otherwise t->slot 0x117 (0x45c)(6, 0).
// t[0x83a] = tab->slot 0x4c(X). A == 0 -> return. A == B -> t->slot 0xf6(t->slot 0xfb(0x18)); else t->slot 0x117(8, a).
static void THISCALL fn590140(u8 *t, u32 a) {
  u8 *tb = tab();
  u8 *A = (*(v1o_t **)tb)[0x58 / 4](tb, a);
  u8 *X = (*(v0o_t **)t)[0x504 / 4](t);
  tb = tab();
  u8 *B = (*(v1o_t **)tb)[0x58 / 4](tb, rd(t + 0x842));
  if (A == X) return;
  if (X) {
    (*(v2_t **)X)[0x2d0 / 4](X, 0, 0);
    u8 *c = (*(v0o_t **)X)[0x2e8 / 4](X);
    u32 d = (*(v0r_t **)c)[0x308 / 4](c);
    if (d == 1) {
      u32 v = (*(v1r_t **)t)[0x3ec / 4](t, 0x17);
      (*(v1_t **)t)[0x3d8 / 4](t, v);
    } else {
      (*(v2_t **)t)[0x45c / 4](t, 6, 0);
    }
  }
  tb = tab();
  wr(t + 0x83a, (u32)(*(v1o_t **)tb)[0x4c / 4](tb, (u32)X));
  if (!A) return;
  if (A == B) {
    u32 v = (*(v1r_t **)t)[0x3ec / 4](t, 0x18);
    (*(v1_t **)t)[0x3d8 / 4](t, v);
    return;
  }
  (*(v2_t **)t)[0x45c / 4](t, 8, a);
}
PCREG(590140, fn590140);
