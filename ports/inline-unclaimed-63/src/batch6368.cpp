// batch6368.cpp - unclaimed-63 batch 68: 0x4c36d0 ZWindControl::Save(ZSaveGame*) (name from the core list), thiscall, one stack argument s,
//   ret 4, returns true (al = 1). this[+4] &= ~0x40; s->vtbl[+0x6c](this[+0x48]); e1 = s->vtbl[+0x4c](float this[+0x4c]);
//   e1->vtbl[+0x4c](float this[+0x50]); e2 = s->vtbl[+0x4c](float this[+0x54]); e2->vtbl[+0x4c](float this[+0x5c]).
#include "ff.h"

typedef void(THISCALL * u1_fn)(void *, u32);
typedef u32(THISCALL * f1r_fn)(void *, float);
typedef void(THISCALL * f1_fn)(void *, float);

// 0x4c36d0.
static u8 THISCALL unnamed4c36d0(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  ((u1_fn)(*(u32 *)(*(u32 *)s + 0x6c)))((void *)s, *(u32 *)(self + 0x48));
  u32 e1 = ((f1r_fn)(*(u32 *)(*(u32 *)s + 0x4c)))((void *)s, *(float *)(self + 0x4c));
  ((f1_fn)(*(u32 *)(*(u32 *)e1 + 0x4c)))((void *)e1, *(float *)(self + 0x50));
  u32 e2 = ((f1r_fn)(*(u32 *)(*(u32 *)s + 0x4c)))((void *)s, *(float *)(self + 0x54));
  ((f1_fn)(*(u32 *)(*(u32 *)e2 + 0x4c)))((void *)e2, *(float *)(self + 0x5c));
  return 1;
}
PCREG(4c36d0, unnamed4c36d0);
