// u69_100.cpp - area 69, residue-8 (batch 100).
// 0x66d300: forwarder to 0x5fad10. Needs the target's ret check.
// This is a simple tail-jump thunk that probably adjusts ECX and jumps to another function.
#include "ff.h"

extern "C" void ext_5fad10(void *self);  // Target function (ret check needed, GUESS stub)

// 0x66d300: thiscall no args, tail-jumps to 0x5fad10 with same ECX
static void THISCALL forwarder66d300(u8 *self) {
  ext_5fad10(self);
}
PCREG(66d300, forwarder66d300);
