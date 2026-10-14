// batch35032.cpp - cascade s5 batch 35032: 0x5d7b10 (GUESS read a setting pair and clamp a level to 100).
#include "ff.h"

typedef u8 *(THISCALL *g0_t)(void *);
typedef s32(THISCALL *gi_t)(void *);
typedef void(THISCALL *v2_t)(void *, u32, void *);
typedef void(THISCALL *v1_t)(void *, u32);

// 0x5d7b10, no arguments. t = engine table ([engine+0x9b]) slot 0x134(); local = 0; t slot 0x88(0x6a891c, &local); s = engine slot 0xbc(). When local != 0: query again (table slot 0x134(),
// local = 0, slot 0x88(0x6a8940, &local)) and s slot 0x80(min-style: local > 100 (unsigned) gives 100, else local). When local == 0: v = s slot 0x7c() (signed), v < 0 or v > 100 gives s slot 0x80(100).
static void fn5d7b10() {
  u32 local;
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *o = (*(g0_t **)tab)[0x134 / 4](tab);
  local = 0;
  (*(v2_t **)o)[0x88 / 4](o, 0x6a891c, &local);
  eng = G(u8 *, 0x70039c);
  u8 *s = (*(g0_t **)eng)[0xbc / 4](eng);
  if (local != 0) {
    eng = G(u8 *, 0x70039c);
    tab = *(u8 **)(eng + 0x9b);
    o = (*(g0_t **)tab)[0x134 / 4](tab);
    local = 0;
    (*(v2_t **)o)[0x88 / 4](o, 0x6a8940, &local);
    u32 v = local;
    if (v > 0x64) v = 0x64;
    (*(v1_t **)s)[0x80 / 4](s, v);
    return;
  }
  s32 r = (*(gi_t **)s)[0x7c / 4](s);
  if (r < 0 || r > 0x64) (*(v1_t **)s)[0x80 / 4](s, 0x64);
}
PCREG(5d7b10, fn5d7b10);
