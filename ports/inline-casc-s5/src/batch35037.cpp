// batch35037.cpp - cascade s5 batch 35037: 0x4b5620 (GUESS look up the n-th entry of a list and resolve it through the engine table).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, void *);
typedef u32(THISCALL *g1p_t)(void *, void *);
typedef u32(THISCALL *g1_t)(void *, u32);

// 0x4b5620, thiscall(n) ret 4. L = [[this+0x44]+0x18] (reloaded before every use); 0 when null. L slot 0x4c(&it); e = L slot 0x5c(&it); the iteration ends (result 0) when it[0] is zero; the n-th
// e (starting at 0) is resolved with the engine table ([engine+0x9b]) slot 0x58(e) and returned.
static u32 THISCALL fn4b5620(u8 *self, u32 n) {
  u32 it[3];
  u32 i = 0;
  u8 *L = *(u8 **)(*(u8 **)(self + 0x44) + 0x18);
  if (!L) return 0;
  (*(v1_t **)L)[0x4c / 4](L, it);
  L = *(u8 **)(*(u8 **)(self + 0x44) + 0x18);
  u32 e = (*(g1p_t **)L)[0x5c / 4](L, it);
  if (it[0] == 0) return 0;
  for (;;) {
    u32 k = i++;
    if (k == n) {
      u8 *eng = G(u8 *, 0x70039c);
      u8 *tab = *(u8 **)(eng + 0x9b);
      return (*(g1_t **)tab)[0x58 / 4](tab, e);
    }
    L = *(u8 **)(*(u8 **)(self + 0x44) + 0x18);
    e = (*(g1p_t **)L)[0x5c / 4](L, it);
    if (it[0] == 0) return 0;
  }
}
PCREG(4b5620, fn4b5620);
