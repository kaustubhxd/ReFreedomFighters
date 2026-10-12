// batch6359.cpp - unclaimed-63 batch 59: 0x5b1f40 ZKillBox::Load(ZLoadGame*) (core list name), thiscall, one stack argument L, ret 4,
//   returns true (al = 1). this[+4] &= ~0x40; L->vtbl[+0x40](&arg) (thiscall, the argument slot is passed by address, the callee may write
//   it); r = [[0x70039c]+0x9b]->vtbl[+0x58](arg) (thiscall, one argument); this[+0x4a] = r.
#include "ff.h"

typedef void(THISCALL * arg_fn)(void *, u32 *);
typedef u32(THISCALL * q_fn)(void *, u32);

// 0x5b1f40.
static u8 THISCALL unnamed5b1f40(u8 *self, u32 L) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  u32 arg = L;
  ((arg_fn)(*(u32 *)(*(u32 *)L + 0x40)))((void *)L, &arg);
  u32 db = *(u32 *)(G(u32, 0x70039c) + 0x9b);
  u32 r = ((q_fn)(*(u32 *)(*(u32 *)db + 0x58)))((void *)db, arg);
  *(u32 *)(self + 0x4a) = r;
  return 1;
}
PCREG(5b1f40, unnamed5b1f40);
