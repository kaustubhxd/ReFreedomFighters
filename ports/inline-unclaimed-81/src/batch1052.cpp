// batch1052.cpp - area 81, batch 1052: 0x651940, thiscall with one stack argument. Calls helper 0x651880,
// tests a flag in the argument, optionally calls 0x634273(this, 0x12a3) to free, returns this.
#include "ff.h"

extern "C" void ext_651880(void);  // real exe code or GUESS stub
extern "C" void asm_651940(void);

__asm__(
    ".text\n"
    ".globl asm_651940\n"
    "asm_651940:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  call ext_651880\n"
    "  testb $1, 0x8(%ebp)\n"
    "  je asm_651940_end\n"
    "  pushl $0x12a3\n"
    "  pushl %esi\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "asm_651940_end:\n"
    "  movl %esi, %eax\n"
    "  popl %esi\n"
    "  popl %ebp\n"
    "  ret $4\n");

PCREG(651940, asm_651940);
