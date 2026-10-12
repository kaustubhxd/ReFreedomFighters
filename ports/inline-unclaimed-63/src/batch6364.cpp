// batch6364.cpp - unclaimed-63 batch 64: 0x482480 ZPlayer::ClassInit2() (core list name), thiscall, no arguments, plain ret.
//   0x472fd0(this) (thiscall, plain ret; other area's code, stubbed). For i = 1 .. count, with count = this[+0x459] (unsigned; no loop if
//   count < 1): obj = this[+0x461 + 4*(i-1)]; if obj != 0: obj->vtbl[+0](obj) (thiscall, no arguments).
#include "ff.h"

extern "C" void THISCALL ext_472fd0(void *self);   // thiscall, plain ret, stubbed

typedef void(THISCALL * noarg_fn)(void *);

// 0x482480.
static void THISCALL unnamed482480(u8 *self) {
  ext_472fd0((void *)self);
  u32 n = *(u32 *)(self + 0x459);
  if (n < 1)
    return;
  u32 i = 1;
  do {
    u32 obj = *(u32 *)(self + 0x461 + 4 * (i - 1));
    if (obj != 0)
      ((noarg_fn)(*(u32 *)(*(u32 *)obj)))((void *)obj);
    i++;
  } while (i <= n);
}
PCREG(482480, unnamed482480);
