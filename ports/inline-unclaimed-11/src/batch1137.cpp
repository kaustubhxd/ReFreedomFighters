// batch1137.cpp - unclaimed-11 batch 38 (gap band): 0x5b7eb0, GUESS (one object arg, ret 4).
#include "ff.h"

typedef void(THISCALL *oneArg)(void *self, u32 v);

static void THISCALL guessFourArgCalls(u8 *self, u8 *arg) {
  ((oneArg)(*(void ***)arg)[0x64 / 4])(arg, *(u32 *)(self + 0));
  ((oneArg)(*(void ***)arg)[0x4c / 4])(arg, *(u32 *)(self + 4));
  ((oneArg)(*(void ***)arg)[0x4c / 4])(arg, *(u32 *)(self + 8));
  ((oneArg)(*(void ***)arg)[0x64 / 4])(arg, *(u32 *)(self + 0xc));
}
PCREG(5b7eb0, guessFourArgCalls);
