// batch1136.cpp - unclaimed-11 batch 37 (gap band): 0x5b7710, GUESS (one object argument, ret 4, returns true).
#include "ff.h"

typedef void(THISCALL *voidArg)(void *self, u32 *p);
typedef u32(THISCALL *u32Arg)(void *self, u32 v);

static bool THISCALL guessTwoCallsAndRender(u8 *self, u8 *arg) {
  self[4] &= ~0x40;
  ((voidArg)(*(void ***)arg)[0x48 / 4])(arg, (u32 *)(self + 0x4c));
  ((voidArg)(*(void ***)arg)[0x40 / 4])(arg, (u32 *)(self + 0x48));
  void *rm = G(void *, 0x70039c);
  void *ro = *(void **)((u8 *)rm + 0x9b);
  *(u32 *)(self + 0x50) = ((u32Arg)(*(void ***)ro)[0x58 / 4])(ro, *(u32 *)(self + 0x48));
  return true;
}
PCREG(5b7710, guessTwoCallsAndRender);
