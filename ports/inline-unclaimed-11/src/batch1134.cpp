// batch1134.cpp - unclaimed-11 batch 35 (gap band): 0x5a5c60, GUESS (no args). The PC tail-jumps through vt[8].
#include "ff.h"

extern "C" void THISCALL ext_5ef050(void *obj, u32 arg);   // stubbed in the harness (one argument)

typedef void(THISCALL *voidFn)(void *self);

// 0x5a5c60, GUESS: 0x5ef050(obj, 1); then obj->vt[8]() (the PC's tail jump, so this returns that call's result).
static void THISCALL guessHelperThenVirtual(u8 *self) {
  void *obj = *(void **)(self + 0x62c);
  ext_5ef050(obj, 1);
  obj = *(void **)(self + 0x62c);
  ((voidFn)(*(void ***)obj)[8 / 4])(obj);
}
PCREG(5a5c60, guessHelperThenVirtual);
