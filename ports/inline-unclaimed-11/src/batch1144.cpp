// batch1144.cpp - unclaimed-11 batch 45 (slice 10): 0x656da0, GUESS (ecx unused; arg1 object, arg2 float bits; ret 8).
#include "ff.h"

extern "C" void *THISCALL ext_63eab0(void *y);   // stubbed in the harness (returns a pointer; no arguments)

typedef void *(THISCALL *ptrArg)(void *self, u32 v);

static void THISCALL guessStoreThroughHelper(void *unusedThis, u8 *obj, u32 vbits) {
  u16 word = *(u16 *)(obj + 0x5a);
  if (word == 0) return;
  void *rm = G(void *, 0x70039c);
  void *holder = *(void **)((u8 *)rm + 0x190f);
  void *y = ((ptrArg)(*(void ***)holder)[0x20 / 4])(holder, word);
  u8 *z = (u8 *)ext_63eab0(y);
  *(u32 *)(z + 0x48) = vbits;
}
PCREG(656da0, guessStoreThroughHelper);
