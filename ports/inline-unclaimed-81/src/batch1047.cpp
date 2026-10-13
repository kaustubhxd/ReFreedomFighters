// batch1047.cpp - area 81, batch 1047: 0x57c240, thiscall (this, no stack arguments), plain ret. Calls 0x5626c0 (thiscall, no arguments), then
// 0x563510 with the string address 0x6a6f98, then 0x563610 (the setter this+0x58 = argument; real exe code) with 0x6a6fa0. 0x5626c0 and 0x563510 are
// large and are GUESS stubs in the spec. Module-level asm keeps esi and the call order exact.
#include "ff.h"

extern "C" void ext_5626c0(void);
extern "C" void ext_563510(void);
extern "C" void ext_563610(void);
extern "C" void asm_57c240(void);

__asm__(
    ".text\n"
    ".globl asm_57c240\n"
    "asm_57c240:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  call ext_5626c0\n"
    "  pushl $0x6a6f98\n"
    "  movl %esi, %ecx\n"
    "  call ext_563510\n"
    "  pushl $0x6a6fa0\n"
    "  movl %esi, %ecx\n"
    "  call ext_563610\n"
    "  popl %esi\n"
    "  ret\n");
PCREG(57c240, asm_57c240);
