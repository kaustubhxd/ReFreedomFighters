// batch5721.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 21: 0x6044c0 (GUESS, unnamed), no arguments, ret (cdecl, the caller
// pops nothing), returns eax = 0. If the assert hook (global 0x7003b0) is non-null, call it with no arguments first. The hook is a
// logging stub in the spec (the same pattern as batch 11, 0x4ced80 and 0x4d4f00).
#include "ff.h"

#define G(T, addr) (*(T *)(addr))

static u32 unnamed6044c0(void) {
  u32 hook = G(u32, 0x7003b0);
  if (hook) ((void (*)())hook)();
  return 0;
}
PCREG(6044c0, unnamed6044c0);
