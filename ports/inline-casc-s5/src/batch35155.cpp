// batch35155.cpp - cascade s5 batch 35155: 0x5c8f10 (GUESS look up or create a named resource and register it).
#include "ff.h"

typedef u32(THISCALL *l2_t)(void *, u32, u32);
typedef u32(THISCALL *l4_t)(void *, u32, u32, u32, u32);
typedef u8 *(THISCALL *g0_t)(void *);
typedef u32(THISCALL *k2_t)(void *, u32, u32);
typedef void(THISCALL *v1_t)(void *, u32);

// 0x5c8f10, thiscall, no args, no return value. m = engine[+0x9b][+0xadc]; this[0x7c] = m slot 0x25c(0x6b4a2c, 0). When it is zero: this[0x7c] = m slot 0x294(0x6b4a2c, 0x67f610, 0, 1) (m re-read);
// o = tab slot 0x138(); w = tab slot 0x4c(this[0x7c], 2); o slot 0x60(0x6b4a2c, w) (the vtable of o is read before the 0x4c call). Then this[0x7c] slot 0x218(this[0x44]); [0x7003b8][+0x2c29] = this[0x7c].
static void THISCALL fn5c8f10(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(eng + 0x9b);
  u8 *m = *(u8 **)(tab + 0xadc);
  u32 r = (*(l2_t **)m)[0x25c / 4](m, 0x6b4a2c, 0);
  *(u32 *)(self + 0x7c) = r;
  if (!r) {
    eng = G(u8 *, 0x70039c);
    tab = *(u8 **)(eng + 0x9b);
    m = *(u8 **)(tab + 0xadc);
    *(u32 *)(self + 0x7c) = (*(l4_t **)m)[0x294 / 4](m, 0x6b4a2c, 0x67f610, 0, 1);
    eng = G(u8 *, 0x70039c);
    tab = *(u8 **)(eng + 0x9b);
    u8 *o = (*(g0_t **)tab)[0x138 / 4](tab);
    eng = G(u8 *, 0x70039c);
    tab = *(u8 **)(eng + 0x9b);
    u32 *vt = *(u32 **)o;
    u32 w = (*(k2_t **)tab)[0x4c / 4](tab, *(u32 *)(self + 0x7c), 2);
    ((l2_t)vt[0x60 / 4])(o, 0x6b4a2c, w);
  }
  u8 *x = *(u8 **)(self + 0x7c);
  (*(v1_t **)x)[0x218 / 4](x, *(u32 *)(self + 0x44));
  u8 *g = G(u8 *, 0x7003b8);
  *(u32 *)(g + 0x2c29) = *(u32 *)(self + 0x7c);
}
PCREG(5c8f10, fn5c8f10);
