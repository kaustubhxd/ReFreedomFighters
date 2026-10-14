// batch35152.cpp - cascade s5 batch 35152: 0x44a790 (GUESS forward a call to every live entry of a collection).
#include "ff.h"

typedef void(THISCALL *it0_t)(void *, u32 *);
typedef u32(THISCALL *itn_t)(void *, u32 *);
typedef u8 *(THISCALL *e1_t)(void *, u32);
typedef void(THISCALL *c3_t)(void *, u32, u32, u32);

// 0x44a790, thiscall(a, b) ret 8, no return value. c = [this+0x18] (null returns at once). it[3] on the stack: c slot 0x4c(it); x = c slot 0x5c(it); while it[0] != 0 (checked after each fetch): obj = engine table slot 0x58(x);
// when non-null obj slot 0x128(a, b, 0); x = c slot 0x5c(it).
static void THISCALL fn44a790(u8 *self, u32 a, u32 b) {
  u32 it[3];
  u8 *c = *(u8 **)(self + 0x18);
  if (!c) return;
  (*(it0_t **)c)[0x4c / 4](c, it);
  c = *(u8 **)(self + 0x18);
  u32 x = (*(itn_t **)c)[0x5c / 4](c, it);
  if (it[0] == 0) return;
  do {
    u8 *eng = G(u8 *, 0x70039c);
    u8 *tab = *(u8 **)(eng + 0x9b);
    u8 *o = (*(e1_t **)tab)[0x58 / 4](tab, x);
    if (o) (*(c3_t **)o)[0x128 / 4](o, a, b, 0);
    c = *(u8 **)(self + 0x18);
    x = (*(itn_t **)c)[0x5c / 4](c, it);
  } while (it[0] != 0);
}
PCREG(44a790, fn44a790);
