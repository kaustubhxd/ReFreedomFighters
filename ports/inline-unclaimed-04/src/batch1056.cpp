// batch1056.cpp - unclaimed-04 batch 56 (docs/20-unclaimed-04.md): 0x6650b4 (residue 3).
// cdecl, no arguments, plain ret. GUESS: wrapper calling a helper.
#include "ff.h"

extern "C" void ext_634d1c(void);  // helper, hooked by address (GUESS)

// 0x6650b4. Cdecl, plain ret.
static void unk6650b4(void) {
  ext_634d1c();
}

PCREG(6650b4, unk6650b4);
