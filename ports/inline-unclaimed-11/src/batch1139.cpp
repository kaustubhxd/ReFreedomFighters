// batch1139.cpp - unclaimed-11 batch 40 (slice 10): 0x656760, GUESS (one stack arg, ret 4, returns a zero-extended word).
#include "ff.h"

typedef void *(THISCALL *ptrArg)(void *self, u32 a);

static u32 THISCALL guessWordAtResult2(u8 *self, u32 arg) {
  u8 *p = (u8 *)((ptrArg)(*(void ***)self)[0xc / 4])(self, arg);
  return *(u16 *)(p + 2);
}
PCREG(656760, guessWordAtResult2);
