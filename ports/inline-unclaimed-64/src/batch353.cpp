// batch353.cpp - decomp area 64 (docs/20-unclaimed-64.md): residue-18 pass (core-todo residue 18 is claimed out; this is from
// out/functions.jsonl). 0x5625a0 calls 0x562440 (ecx = self, no words), then 0x563510 (ecx = self, one word 0x6a6850).
#include "ff.h"

// Exe helpers, stubbed on both sides in the spec (GUESS): 0x562440 takes no words; 0x563510 takes one word.
extern "C" void THISCALL ext_562440(u8 *self);
extern "C" void THISCALL ext_563510(u8 *self, u32 word);

// 0x5625a0: thiscall (ecx = self, no stack words, plain ret). GUESS: a reset followed by a call with a fixed tag.
static void THISCALL resetTagged_5625a0(u8 *self) {
    ext_562440(self);
    ext_563510(self, 0x6a6850u);
}
PCREG(5625a0, resetTagged_5625a0);
