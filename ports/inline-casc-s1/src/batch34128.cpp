// batch34128.cpp - cascade tier E, batch 34128: 0x5f04a0 and 0x5f0540, siblings of 0x5f0380 (same engine query, other constants and helper).
#include "ff.h"

extern "C" u32 THISCALL ext_5f0e10(void *self, u32 a);
extern "C" u32 THISCALL ext_5f0f00(void *self, u32 a);

// 0x5f04a0, thiscall plain: t = [[0x70039c]+0x9b]; x = t->slot0x138(); x->slot0x88(0x6a5c48, &l4) (l4 pre-set to 0); w = t->slot0x114(0x6add1c, 0, 0x6b8240, 0x1b, &l8) (l8 pre-set to 0);
// [this+4]->slot0x12c(l4, (u16) w) using the vtable read before the second call; when l8 is non-zero ext_5f0e10(l8, [[this+4]+0x684]).
static void THISCALL fn5f04a0(u8 *self) {
  u32 l4 = 0, l8 = 0;
  u8 *t = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *x = vcall<u8 *>(t, 0x138);
  l4 = 0;
  vcall<void>(x, 0x88, 0x6a5c48u, (u32)&l4);
  u8 *vt = **(u8 ***)(self + 4);
  u32 v4 = *(volatile u32 *)&l4;
  t = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 w = (u16)vcall<u32>(t, 0x114, 0x6add1c, 0u, 0x6b8288u, 0x1du, (u32)&l8);
  typedef void (THISCALL *f2)(void *, u32, u32);
  (*(f2 *)(vt + 0x12c))(*(u8 **)(self + 4), v4, w);
  u32 h = *(volatile u32 *)&l8;
  if (h) ext_5f0f00((void *)h, *(u32 *)(*(u8 **)(self + 4) + 0x684));
}
PCREG(5f04a0, fn5f04a0);

// 0x5f0540, thiscall plain: t = [[0x70039c]+0x9b]; x = t->slot0x138(); x->slot0x88(0x6a5c48, &l4) (l4 pre-set to 0); w = t->slot0x114(0x6add1c, 0, 0x6b8240, 0x1b, &l8) (l8 pre-set to 0);
// [this+4]->slot0x12c(l4, (u16) w) using the vtable read before the second call; when l8 is non-zero ext_5f0e10(l8, [[this+4]+0x684]).
static void THISCALL fn5f0540(u8 *self) {
  u32 l4 = 0, l8 = 0;
  u8 *t = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *x = vcall<u8 *>(t, 0x138);
  l4 = 0;
  vcall<void>(x, 0x88, 0x6a5c48u, (u32)&l4);
  u8 *vt = **(u8 ***)(self + 4);
  u32 v4 = *(volatile u32 *)&l4;
  t = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 w = (u16)vcall<u32>(t, 0x114, 0x6add1c, 0u, 0x6b8288u, 0x24u, (u32)&l8);
  typedef void (THISCALL *f2)(void *, u32, u32);
  (*(f2 *)(vt + 0x12c))(*(u8 **)(self + 4), v4, w);
  u32 h = *(volatile u32 *)&l8;
  if (h) ext_5f0e10((void *)h, *(u32 *)(*(u8 **)(self + 4) + 0x684));
}
PCREG(5f0540, fn5f0540);
