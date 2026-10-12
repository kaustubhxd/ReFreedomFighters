// batch6374.cpp - unclaimed-63 batch 74: 0x5eb680 ZFFActorActionCloseCombat::Save(ZSaveGame&) (name from area 05's table), thiscall,
//   one stack argument s, ret 4, no return value. s->vtbl[+0x64](this[+8]); s->vtbl[+0x64](this[+0xc]);
//   s->vtbl[+0x3c](this[+0x10] - db[+0x44]); s->vtbl[+0x3c](this[+0x14] - db[+0x44]) with db = [[0x70039c]+0x9b];
//   s->vtbl[+0x44](this[+0x18]); s->vtbl[+0x4c](float this[+0x1c]); s->vtbl[+0x60](byte this[+0x20]); s->vtbl[+0x10](&this[+0x21], 0x30).
#include "ff.h"

typedef void(THISCALL * u1_fn)(void *, u32);
typedef void(THISCALL * f1_fn)(void *, float);
typedef void(THISCALL * u2_fn)(void *, u32, u32);

// 0x5eb680.
static void THISCALL unnamed5eb680(u8 *self, u8 *s) {
  u32 vs = *(u32 *)s;
  ((u1_fn)(*(u32 *)(vs + 0x64)))((void *)s, *(u32 *)(self + 8));
  ((u1_fn)(*(u32 *)(vs + 0x64)))((void *)s, *(u32 *)(self + 0xc));
  u32 db = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  ((u1_fn)(*(u32 *)(vs + 0x3c)))((void *)s, *(u32 *)(self + 0x10) - *(u32 *)(db + 0x44));
  ((u1_fn)(*(u32 *)(vs + 0x3c)))((void *)s, *(u32 *)(self + 0x14) - *(u32 *)(db + 0x44));
  ((u1_fn)(*(u32 *)(vs + 0x44)))((void *)s, *(u32 *)(self + 0x18));
  ((f1_fn)(*(u32 *)(vs + 0x4c)))((void *)s, *(float *)(self + 0x1c));
  ((u1_fn)(*(u32 *)(vs + 0x60)))((void *)s, (u32)*(u8 *)(self + 0x20));
  ((u2_fn)(*(u32 *)(vs + 0x10)))((void *)s, (u32)(self + 0x21), 0x30u);
}
PCREG(5eb680, unnamed5eb680);
