// batch1143.cpp - unclaimed-11 batch 44 (slice 10): 0x6563a0, GUESS (two stack args, ret 8; `this` unused).
#include "ff.h"

typedef void *(THISCALL *ptrNoArg)(void *self);
typedef void(THISCALL *twoArgs)(void *self, u32 a, u32 b);

static void THISCALL guessSizedTwoLevel(u8 *self, u32 a1, u32 a2) {
  u32 n = ((a2 << 4) + a2) << 2;
  if (n == 0) return;
  void *rm = G(void *, 0x70039c);
  void *holder = *(void **)((u8 *)rm + 0x190f);
  void *x = ((ptrNoArg)(*(void ***)holder)[0x20 / 4])(holder);
  ((twoArgs)(*(void ***)x)[0x18 / 4])(x, a1, n);
}
PCREG(6563a0, guessSizedTwoLevel);
