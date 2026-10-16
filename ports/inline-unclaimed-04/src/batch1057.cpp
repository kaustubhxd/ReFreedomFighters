// batch1057.cpp - unclaimed-04 batch 57 (docs/20-unclaimed-04.md): 0x6683f0, 0x66b0f0 (residue 3).
// cdecl, no arguments, plain ret. GUESS: wrappers calling the same helper.
#include "ff.h"

extern "C" void ext_634d1c(void);  // helper, hooked by address (GUESS)

// 0x6683f0. Cdecl, plain ret.
static void unk6683f0(void) {
  ext_634d1c();
}
PCREG(6683f0, unk6683f0);

// 0x66b0f0. Cdecl, plain ret.
static void unk66b0f0(void) {
  ext_634d1c();
}
PCREG(66b0f0, unk66b0f0);
