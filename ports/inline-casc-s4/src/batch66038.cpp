// batch66038.cpp - cascade s4 batch 66038: 0x4ce2d0 (tier F row).
#include "ff.h"

typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

static void logline(u32 line, u32 fmt, u32 a) {
  u8 *db = G(u8 *, 0x700390);
  u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x695b7cu, line);
  void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
  ((void (*)(u8 *, u32, u32))fn)(lo, fmt, a);
}

// 0x4ce2d0, thiscall(a) ret 4, returns al (this = t): t[0x18] set and sys[0x9b7] set -> assert hook (int3 when none). m = t[0x10]. a & ~m == 0 -> log (0x648, 0x695d38, a), return 0.
// t->slot 5 (0x14)(a) (al) == 0 -> log (0x64d, 0x695d5c, a), t->slot 6 (0x18)(a), return 0. Otherwise p = t[4] + (m & a) * 4: *p = ((*p >> t[0x14]) + 1) << t[0x14]; t[8]->slot 1 (4)((m & a) + 1); return 1.
static u8 THISCALL fn4ce2d0(u8 *t, u32 a) {
  if (t[0x18] && G(u8 *, 0x70039c)[0x9b7]) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  u32 m = rd(t + 0x10);
  if (!(a & ~m)) {
    logline(0x648, 0x695d38u, a);
    return 0;
  }
  if (!(u8)(*(v1r_t **)t)[0x14 / 4](t, a)) {
    logline(0x64d, 0x695d5cu, a);
    (*(v1_t **)t)[0x18 / 4](t, a);
    return 0;
  }
  u8 *p = *(u8 **)(t + 4) + (rd(t + 0x10) & a) * 4;
  u32 sh = rd(t + 0x14) & 31;
  wr(p, ((rd(p) >> sh) + 1) << sh);
  u8 *o = *(u8 **)(t + 8);
  (*(v1_t **)o)[4 / 4](o, (rd(t + 0x10) & a) + 1);
  return 1;
}
PCREG(4ce2d0, fn4ce2d0);
