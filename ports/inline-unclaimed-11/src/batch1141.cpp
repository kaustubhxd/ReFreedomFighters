// batch1141.cpp - unclaimed-11 batch 42 (slice 10): 0x64fe60, GUESS (free the pointer at +0x2c, then clear it).
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);

static void THISCALL guessFreeAndClear(u8 *self) {
  void *p = *(void **)(self + 0x2c);
  if (p) ext_634273(p, 1);
  *(u32 *)(self + 0x2c) = 0;
}
PCREG(64fe60, guessFreeAndClear);
