// batch6370.cpp - unclaimed-63 batch 70: 0x5bd9e0 CCheckInsideByType::Save(ZSaveGame*) (core list name), thiscall, one stack argument s,
//   ret 4, returns true (al = 1). this[+4] &= ~0x40; s->vtbl[+0x44](dword this[+0x6c]); s->vtbl[+0x44](dword this[+0x70]);
//   s->vtbl[+0x10](&this[+0x48], 0x24) (two arguments); s->vtbl[+0x40](word this[+0x75]); s->vtbl[+0x40](word this[+0x77]);
//   s->vtbl[+0x3c](dword this[+0x79]); s->vtbl[+0x60](byte this[+0x74]).
#include "ff.h"

typedef void(THISCALL * u1_fn)(void *, u32);
typedef void(THISCALL * u2_fn)(void *, u32, u32);

// 0x5bd9e0.
static u8 THISCALL unnamed5bd9e0(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  u32 vs = *(u32 *)s;
  ((u1_fn)(*(u32 *)(vs + 0x44)))((void *)s, *(u32 *)(self + 0x6c));
  ((u1_fn)(*(u32 *)(vs + 0x44)))((void *)s, *(u32 *)(self + 0x70));
  ((u2_fn)(*(u32 *)(vs + 0x10)))((void *)s, (u32)(self + 0x48), 0x24u);
  ((u1_fn)(*(u32 *)(vs + 0x40)))((void *)s, (u32)*(u16 *)(self + 0x75));
  ((u1_fn)(*(u32 *)(vs + 0x40)))((void *)s, (u32)*(u16 *)(self + 0x77));
  ((u1_fn)(*(u32 *)(vs + 0x3c)))((void *)s, *(u32 *)(self + 0x79));
  ((u1_fn)(*(u32 *)(vs + 0x60)))((void *)s, (u32)*(u8 *)(self + 0x74));
  return 1;
}
PCREG(5bd9e0, unnamed5bd9e0);
