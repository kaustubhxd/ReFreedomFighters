// batch1135.cpp - unclaimed-11 batch 36 (gap band): 0x5a5c80, GUESS (three stack args, ret 0xc).
#include "ff.h"

extern "C" void THISCALL ext_5ef040(void *obj, u32 a3);   // original code: ecx = [obj+0xc], then jmp 0x5ac940(a3)

// 0x5a5c80, GUESS: ext_5ef040(this->obj, a3). a1 and a2 are not read.
static void THISCALL guessForwardThird(u8 *self, u32 a1, u32 a2, u32 a3) {
  void *obj = *(void **)(self + 0x62c);
  ext_5ef040(obj, a3);
}
PCREG(5a5c80, guessForwardThird);
