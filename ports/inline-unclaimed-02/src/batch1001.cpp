#include "ff.h"
// batch1001.cpp - unclaimed-02 batch 1 (docs/20-unclaimed-02.md). Names from the GC name map (naming only).

// 0x5dbe30, ZBombDamageList::Command(unsigned short, void*) (high). The command word is compared as 16 bits
// (ax) with the word at 0x714384; on a match the object pointer (this) is stored through the second argument.
// Returns 0 (xor eax, eax). Callee pops 8 bytes.
static u32 THISCALL bombDamageListCommand(u8 *self, u32 cmd, u32 arg) {
  if ((u16)cmd == G(u16, 0x714384))
    *(u8 **)arg = self;
  return 0;
}
PCREG(5dbe30, bombDamageListCommand);

// 0x5dc880, ZFFFlak::Command(unsigned short, void*) (high). Same compare as above, against the word at 0x714394.
// On a match the second argument is stored as a dword at this+0x58 (the value itself, not through a pointer).
// Returns 0. Callee pops 8 bytes.
static u32 THISCALL ffFlakCommand(u8 *self, u32 cmd, u32 arg) {
  if ((u16)cmd == G(u16, 0x714394))
    *(u32 *)(self + 0x58) = arg;
  return 0;
}
PCREG(5dc880, ffFlakCommand);
