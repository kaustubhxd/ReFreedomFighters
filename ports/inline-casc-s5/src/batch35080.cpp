// batch35080.cpp - cascade s5 batch 35080: 0x45e390 (GUESS forward a four-argument call to the object of every entry of a list).
#include "ff.h"

extern "C" u8 THISCALL ext_4da3a0(u32 self);   // plain ret, bool in AL
typedef void(THISCALL *v1p_t)(void *, void *);
typedef u32(THISCALL *g1p_t)(void *, void *);
typedef u8 *(THISCALL *e1_t)(void *, u32);
typedef void(THISCALL *v4_t)(void *, u32, u32, u32, u32);

// 0x45e390, thiscall(a, b, c, d) ret 0x10. Nothing unless 0x4da3a0([this+8]) is true and the list L = [[this+0x10]+8] exists. L slot 0x4c(&it); for each e returned by L slot 0x5c(&it) (L reloaded) while it[0] != 0:
// o = [0x70038c] slot 0xcc(e); o slot 0x18(a, b, c, d).
static void THISCALL fn45e390(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  u32 it[3];
  if (!ext_4da3a0(*(u32 *)(self + 8))) return;
  u8 *L = *(u8 **)(*(u8 **)(self + 0x10) + 8);
  if (!L) return;
  (*(v1p_t **)L)[0x4c / 4](L, it);
  L = *(u8 **)(*(u8 **)(self + 0x10) + 8);
  u32 e = (*(g1p_t **)L)[0x5c / 4](L, it);
  if (it[0] == 0) return;
  do {
    u8 *E = G(u8 *, 0x70038c);
    u8 *o = (*(e1_t **)E)[0xcc / 4](E, e);
    (*(v4_t **)o)[0x18 / 4](o, a, b, c, d);
    L = *(u8 **)(*(u8 **)(self + 0x10) + 8);
    e = (*(g1p_t **)L)[0x5c / 4](L, it);
  } while (it[0] != 0);
}
PCREG(45e390, fn45e390);
