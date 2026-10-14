// batch35116.cpp - cascade s5 batch 35116: 0x5097b0 (GUESS enable or disable every listed table object according to a flag).
#include "ff.h"

extern "C" u32 *THISCALL ext_5003d0(u32 self, u32 a);   // thiscall, ret 4, returns a record whose first dword is the flag
typedef void(THISCALL *v1p_t)(void *, void *);
typedef u32(THISCALL *g1p_t)(void *, void *);
typedef u8 *(THISCALL *e1_t)(void *, u32);
typedef void(THISCALL *v0_t)(void *);

// 0x5097b0, thiscall(a) ret 4. flag = *0x5003d0([a+4], 0). L = [[this+0xc]+0x18] (re-read before each use; null: nothing). L slot 0x4c(&it); for each e from L slot 0x5c(&it) while it[0] != 0:
// o = [engine+0x9b] slot 0x58(e); when o is non-null: o slot 0x2c() (flag non-zero) or o slot 0x28() (flag zero).
static void THISCALL fn5097b0(u8 *self, u8 *a) {
  u32 it[3];
  u32 flag = *ext_5003d0(*(u32 *)(a + 4), 0);
  u8 *L = *(u8 **)(*(u8 **)(self + 0xc) + 0x18);
  if (!L) return;
  (*(v1p_t **)L)[0x4c / 4](L, it);
  L = *(u8 **)(*(u8 **)(self + 0xc) + 0x18);
  u32 e = (*(g1p_t **)L)[0x5c / 4](L, it);
  if (it[0] == 0) return;
  do {
    u8 *eng = G(u8 *, 0x70039c);
    u8 *tab = *(u8 **)(eng + 0x9b);
    u8 *o = (*(e1_t **)tab)[0x58 / 4](tab, e);
    if (o) {
      if (flag) (*(v0_t **)o)[0x2c / 4](o);
      else (*(v0_t **)o)[0x28 / 4](o);
    }
    L = *(u8 **)(*(u8 **)(self + 0xc) + 0x18);
    e = (*(g1p_t **)L)[0x5c / 4](L, it);
  } while (it[0] != 0);
}
PCREG(5097b0, fn5097b0);
