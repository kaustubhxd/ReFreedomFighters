// batch66011.cpp - cascade s4 batch 66011: 0x49f9b0 (tier F row).
#include "ff.h"

typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef void(THISCALL *v8_t)(void *, u32, u32, u32, u32, u32, u32, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }

// 0x49f9b0, fastcall(this = ecx, x = edx, a1, a2, a3, a4, a5, a6) ret 0x18: n = this->slot 0x40 (0x100)(0x6889cc), else this->slot 0x43 (0x10c)(0x6889cc, 0); n == 0 -> return.
// n->slot 0x17 (0x5c)(1, this, 0); g = [0x70038c]; g->slot 8 (0x20)(n) nonzero -> v = 0, else when g[8] is set and g[0xc] <= n < g[0x10] -> v = g[8](n) (thiscall),
// else (n[-4] == 0 -> g->slot 0x2b (0xac)(n)) v = n[-4]. n->slot 0x2c (0xb0)(x, a1, a2, a3, a4, a5, 0, a6); n->slot 0x17 (0x5c)(2, 0, 0); g->slot 0x33 (0xcc)(v).
static void FASTCALL fn49f9b0(u8 *self, u32 x, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
  u8 *n = (*(v1o_t **)self)[0x100 / 4](self, 0x6889cc);
  if (!n) {
    n = (*(v2o_t **)self)[0x10c / 4](self, 0x6889cc, 0);
    if (!n) return;
  }
  (*(v3_t **)n)[0x5c / 4](n, 1, (u32)self, 0);
  u8 *g = G(u8 *, 0x70038c);
  u32 v;
  if ((*(v1r_t **)g)[0x20 / 4](g, (u32)n)) {
    v = 0;
  } else {
    g = G(u8 *, 0x70038c);
    u32 fp = rd(g + 8);
    if (fp && !(rd(g + 0xc) > (u32)n) && (u32)n < rd(g + 0x10)) {
      v = ((v0r_t)fp)(n);
    } else {
      if (rd(n - 4) == 0) (*(v1_t **)g)[0xac / 4](g, (u32)n);
      v = rd(n - 4);
    }
  }
  (*(v8_t **)n)[0xb0 / 4](n, x, a1, a2, a3, a4, a5, 0, a6);
  (*(v3_t **)n)[0x5c / 4](n, 2, 0, 0);
  g = G(u8 *, 0x70038c);
  (*(v1_t **)g)[0xcc / 4](g, v);
}
PCREG(49f9b0, fn49f9b0);
