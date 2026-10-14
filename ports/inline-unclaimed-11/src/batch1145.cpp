// batch1145.cpp - unclaimed-11 batch 46 (slice 10): 0x4d4d60, GUESS (one byte arg, ret 4, returns this).
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);

static u8 *THISCALL guessFreePair(u8 *self, u32 flag) {
  void *p = *(void **)(self + 0xd);
  *(u32 *)self = 0x69666c;
  *(u32 *)(self + 0x11) = 0;
  ext_634273(p, 1);
  *(u32 *)self = 0x696634;
  if (flag & 1) ext_634273(self, 0x15);
  return self;
}
PCREG(4d4d60, guessFreePair);
