// batch35136.cpp - cascade s5 batch 35136: 0x4444a0 (GUESS drain the pending-item list at +0xa8, handing every item to a helper, then destroy it).
#include "ff.h"

extern "C" void THISCALL ext_4dc1e0(u32 item, u8 *owner);   // thiscall, ret 4
typedef u32(THISCALL *g0_t)(void *);
typedef void(THISCALL *v1p_t)(void *, u32 *);
typedef u32(THISCALL *g1p_t)(void *, u32 *);
typedef void(THISCALL *v1_t)(void *, u32);

// 0x4444a0, thiscall, no arguments. L = [this+0xa8] (null: nothing). While L slot 0x14() is non-zero (checked first, then once per round): L slot 0x4c(&it) and e = L slot 0x5c(&it) (L re-read before each; a null L skips the item step);
// an item (it[0] != 0) goes to this slot 0x36c(e) and 0x4dc1e0(e, this). After the loop L (re-read) slot 0(1) when set and [this+0xa8] = 0.
static void THISCALL fn4444a0(u8 *self) {
  u32 it[3];
  u8 *L = *(u8 **)(self + 0xa8);
  if (!L) return;
  if ((*(g0_t **)L)[0x14 / 4](L)) {
    do {
      L = *(u8 **)(self + 0xa8);
      if (L) {
        (*(v1p_t **)L)[0x4c / 4](L, it);
        L = *(u8 **)(self + 0xa8);
        u32 e = (*(g1p_t **)L)[0x5c / 4](L, it);
        if (it[0] != 0) {
          (*(v1_t **)self)[0x36c / 4](self, e);
          ext_4dc1e0(e, self);
        }
      }
      L = *(u8 **)(self + 0xa8);
    } while ((*(g0_t **)L)[0x14 / 4](L));
  }
  L = *(u8 **)(self + 0xa8);
  if (L) (*(v1_t **)L)[0](L, 1);
  *(u32 *)(self + 0xa8) = 0;
}
PCREG(4444a0, fn4444a0);
