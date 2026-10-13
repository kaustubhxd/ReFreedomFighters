// batch355.cpp - decomp area 64 residue-3 pass (out/functions.jsonl, residue 3, under 0x661000, non-thunk): 0x634873, a constant getter.
#include "ff.h"

// 0x634873: thiscall-free getter (no stack words, no ecx use): returns the constant 0x814244. GUESS: a constant table entry.
static u32 THISCALL constant_634873(u8 *) { return 0x814244u; }
PCREG(634873, constant_634873);
