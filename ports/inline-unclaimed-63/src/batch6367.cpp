// batch6367.cpp - unclaimed-63 batch 67: 0x5eb710 ZFFActorActionThrow::Save(ZSaveGame&) (core list name), thiscall, one stack argument s,
//   ret 4. s = the save object (its vtable): s->vtbl[+0x64](this[+8]); s->vtbl[+0x3c](this[+0xc] - db[+0x44]) with db = [[0x70039c]+0x9b];
//   s->vtbl[+0x4c](float this[+0x10]); s->vtbl[+0x60](byte this[+0x14]); s->vtbl[+0x68](&this[+0x15]). Each is thiscall, one argument.
#include "ff.h"

typedef void(THISCALL * u1_fn)(void *, u32);
typedef void(THISCALL * f1_fn)(void *, float);

// 0x5eb710.
static void THISCALL unnamed5eb710(u8 *self, u8 *s) {
  ((u1_fn)(*(u32 *)(*(u32 *)s + 0x64)))((void *)s, *(u32 *)(self + 8));
  u32 db = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  ((u1_fn)(*(u32 *)(*(u32 *)s + 0x3c)))((void *)s, *(u32 *)(self + 0xc) - *(u32 *)(db + 0x44));
  ((f1_fn)(*(u32 *)(*(u32 *)s + 0x4c)))((void *)s, *(float *)(self + 0x10));
  ((u1_fn)(*(u32 *)(*(u32 *)s + 0x60)))((void *)s, (u32)*(u8 *)(self + 0x14));
  ((u1_fn)(*(u32 *)(*(u32 *)s + 0x68)))((void *)s, (u32)(self + 0x15));
}
PCREG(5eb710, unnamed5eb710);
