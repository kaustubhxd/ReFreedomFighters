// batch800.cpp - unclaimed-77 batch 800 (residue 4 rows 0x4b89c0 and 0x4c8dc0; docs/20-unclaimed-77.md).
// Both are `push ebp; mov ebp,esp; pop ebp; jmp <target>`: pure forwarders (ecx and the stack argument pass through). The targets
// 0x4b8a30 and 0x4c8e20 are thiscall with one stack argument (ret 4); they are stubbed (GUESS: argument count read from their `ret 4`).
#include "ff.h"

extern "C" u32 THISCALL ext_4b8a30(void *self, u32 a);
extern "C" u32 THISCALL ext_4c8e20(void *self, u32 a);

// 0x4b89c0, GUESS FUN_4b89c0: forwards to 0x4b8a30.
static u32 THISCALL guessFun4b89c0(void *self, u32 a) { return ext_4b8a30(self, a); }
PCREG(4b89c0, guessFun4b89c0);

// 0x4c8dc0, GUESS FUN_4c8dc0: forwards to 0x4c8e20.
static u32 THISCALL guessFun4c8dc0(void *self, u32 a) { return ext_4c8e20(self, a); }
PCREG(4c8dc0, guessFun4c8dc0);
