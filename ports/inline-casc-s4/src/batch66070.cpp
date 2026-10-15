// batch66070.cpp - cascade s4 batch 66070: 0x4f0690 (tier F row).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1r_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// 0x4f0690, thiscall(s) ret 4 (this = t): s->slot 0x10 (0x40)(t + 0x2e) reads a count n. n == 0: t[0x2a] = t[0x3a] = t[0x36] = 0. Otherwise A = sys[0x1aa3][0x18]->slot 0xb (0x2c)(n); t[0x2a] = A; s->slot 6 (0x18)(A, n * 40);
// s->slot 0x10(t + 0x32) reads m; B = pool->slot 0xe (0x38)(m) -> t[0x3a]; for i < m: s->slot 6(B + 8 * i, 8); B[8 * i + 4] = A + B[8 * i + 4] * 40; C = pool->slot 0xd (0x34)(m) -> t[0x36]; s->slot 6(C, m * 4).
// Finally t[0x91] = 0; t->slot 0x8a (0x228)().
static void THISCALL fn4f0690(u8 *t, u8 *s) {
  (*(v1_t **)s)[0x40 / 4](s, (u32)(t + 0x2e));
  u32 n = rd(t + 0x2e);
  if (n) {
    u8 *pool = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x18);
    u32 a = (*(v1r_t **)pool)[0x2c / 4](pool, n);
    wr(t + 0x2a, a);
    (*(v2_t **)s)[0x18 / 4](s, a, n * 40);
    (*(v1_t **)s)[0x40 / 4](s, (u32)(t + 0x32));
    pool = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x18);
    u32 b = (*(v1r_t **)pool)[0x38 / 4](pool, rd(t + 0x32));
    wr(t + 0x3a, b);
    for (u32 i = 0; i < rd(t + 0x32); i++) {
      (*(v2_t **)s)[0x18 / 4](s, rd(t + 0x3a) + i * 8, 8);
      u8 *bb = *(u8 **)(t + 0x3a);
      wr(bb + i * 8 + 4, rd(t + 0x2a) + rd(bb + i * 8 + 4) * 40);
    }
    pool = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x18);
    u32 c = (*(v1r_t **)pool)[0x34 / 4](pool, rd(t + 0x32));
    wr(t + 0x36, c);
    (*(v2_t **)s)[0x18 / 4](s, c, rd(t + 0x32) * 4);
  } else {
    wr(t + 0x2a, 0);
    wr(t + 0x3a, 0);
    wr(t + 0x36, 0);
  }
  t[0x91] = 0;
  (*(v0_t **)t)[0x228 / 4](t);
}
PCREG(4f0690, fn4f0690);
