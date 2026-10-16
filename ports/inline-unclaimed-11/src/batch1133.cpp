// batch1133.cpp - unclaimed-11 batch 34 (gap band): 0x5ab2a0, GUESS (one stack arg, ret 4).
#include "ff.h"

extern "C" void THISCALL ext_5ac940(void *obj, u32 arg);   // dispatcher; stubbed in the harness (one argument)

// 0x5ab2a0, GUESS: obj = [this+0x648]; arg == 0 gives obj[8] = 0; otherwise 0x5ac940(obj, arg) and obj[8] = 1.
static void THISCALL guessFlagOnObject(u8 *self, u32 arg) {
  u8 *obj = *(u8 **)(self + 0x648);
  if (arg == 0) {
    obj[8] = 0;
    return;
  }
  ext_5ac940(obj, arg);
  obj[8] = 1;
}
PCREG(5ab2a0, guessFlagOnObject);
