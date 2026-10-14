// batch1142.cpp - unclaimed-11 batch 43 (slice 10): 0x566ee0, GUESS (no args).
#include "ff.h"

extern "C" void THISCALL ext_5672c0(void *self, u32 a);   // stubbed in the harness (one argument)

typedef void(THISCALL *voidArg)(void *self, u32 a);

static void THISCALL guessCallThenVirtual(u8 *self) {
  ext_5672c0(self, *(u32 *)(self + 0x198));
  ((voidArg)(*(void ***)self)[0xd0 / 4])(self, 0);
}
PCREG(566ee0, guessCallThenVirtual);
