// batch834.cpp - gap band functions calling through IAT slots (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

typedef void (STDCALL *iat1_t)(u32);

// 0x63450f: cdecl() - IAT[0x6760cc](0x7257d8); if [0x7257f4]: IAT[0x676070]([0x7257f4])
static void __attribute__((cdecl)) iatPair_63450f() {
  (*(iat1_t *)0x6760cc)(0x7257d8);
  u32 v = G(u32, 0x7257f4);
  if (v) (*(iat1_t *)0x676070)(v);
}
PCREG(63450f, iatPair_63450f);

