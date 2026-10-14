// batch1140.cpp - unclaimed-11 batch 41 (slice 10): 0x5646e0, GUESS (one unused stack arg, ret 4).
#include "ff.h"

typedef void(THISCALL *voidArg)(void *self, u32 a);

static void THISCALL guessConditionalVirtual(u8 *self, u32 unused) {
  if (*(u32 *)(self + 0xc82) == 0x20) ((voidArg)(*(void ***)self)[0xfc / 4])(self, 0);
}
PCREG(5646e0, guessConditionalVirtual);
