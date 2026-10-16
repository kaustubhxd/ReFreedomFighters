// batch1059.cpp - unclaimed-04 batch 59 (docs/20-unclaimed-04.md): 0x66b4bd, 0x66d3f6, 0x66d3fc, 0x66d674, 0x66d67a (residue 3).
// cdecl, no arguments, plain ret. GUESS: wrappers calling helper 0x634d1c.
#include "ff.h"

extern "C" void ext_634d1c(void);  // helper, hooked by address (GUESS)

// 0x66b4bd. Cdecl, plain ret.
static void unk66b4bd(void) {
  ext_634d1c();
}
PCREG(66b4bd, unk66b4bd);

// 0x66d3f6. Cdecl, plain ret.
static void unk66d3f6(void) {
  ext_634d1c();
}
PCREG(66d3f6, unk66d3f6);

// 0x66d3fc. Cdecl, plain ret.
static void unk66d3fc(void) {
  ext_634d1c();
}
PCREG(66d3fc, unk66d3fc);

// 0x66d674. Cdecl, plain ret.
static void unk66d674(void) {
  ext_634d1c();
}
PCREG(66d674, unk66d674);

// 0x66d67a. Cdecl, plain ret.
static void unk66d67a(void) {
  ext_634d1c();
}
PCREG(66d67a, unk66d67a);
