// batch1146.cpp - unclaimed-11 batch 47 (slice 10): 0x5f3160, GUESS (one byte arg, ret 4).
#include "ff.h"

typedef void(THISCALL *growFn)(void *self);

static void THISCALL guessPushDword(u8 *self, u32 byteArg) {
  u32 cur = *(u32 *)(self + 8);
  if (cur + 4 > *(u32 *)(self + 0xc)) {
    void *grow = G(void *, 0x7003b0);
    if (grow) ((growFn)grow)(self);
  }
  u32 *dst = *(u32 **)(self + 8);
  *dst = byteArg & 0xff;
  *(u32 *)(self + 8) += 4;
}
PCREG(5f3160, guessPushDword);
