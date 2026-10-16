// batch1058.cpp - unclaimed-04 batch 58 (docs/20-unclaimed-04.md): 0x66b0f6, 0x66b4b1, 0x66d3f0 (residue 3).
// cdecl, no arguments, plain ret. GUESS: wrappers calling helper 0x634d1c.
#include "ff.h"

extern "C" void ext_634d1c(void);  // helper, hooked by address (GUESS)

// 0x66b0f6. Cdecl, plain ret.
static void unk66b0f6(void) {
  ext_634d1c();
}
PCREG(66b0f6, unk66b0f6);

// 0x66b4b1. Cdecl, plain ret.
static void unk66b4b1(void) {
  ext_634d1c();
}
PCREG(66b4b1, unk66b4b1);

// 0x66d3f0. Cdecl, plain ret.
static void unk66d3f0(void) {
  ext_634d1c();
}
PCREG(66d3f0, unk66d3f0);
