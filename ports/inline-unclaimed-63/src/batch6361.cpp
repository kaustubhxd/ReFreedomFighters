// batch6361.cpp - unclaimed-63 batch 61: 0x5d3740 ZShakeCamera::Save(ZSaveGame*) (core list name), thiscall, one stack argument s,
//   ret 4, returns true (al = 1). this[+4] &= ~0x40; then four saves through s->vtbl[+0x64](value) (thiscall, one argument), with the
//   dwords at this+0x55, +0x59, +0x5d, +0x61 (unaligned reads of the object's own fields).
#include "ff.h"

typedef void(THISCALL * save_fn)(void *, u32);

// 0x5d3740.
static u8 THISCALL unnamed5d3740(u8 *self, u32 s) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  ((save_fn)(*(u32 *)(*(u32 *)s + 0x64)))((void *)s, *(u32 *)(self + 0x55));
  ((save_fn)(*(u32 *)(*(u32 *)s + 0x64)))((void *)s, *(u32 *)(self + 0x59));
  ((save_fn)(*(u32 *)(*(u32 *)s + 0x64)))((void *)s, *(u32 *)(self + 0x5d));
  ((save_fn)(*(u32 *)(*(u32 *)s + 0x64)))((void *)s, *(u32 *)(self + 0x61));
  return 1;
}
PCREG(5d3740, unnamed5d3740);
