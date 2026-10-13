// batch1051.cpp - area 81, batch 1051: 0x658240, thiscall cleanup. Saves this, calls 0x64fae0,
// loads pointer from this+0x1186, if non-null calls 0x634273(pointer, 4), zeroes this+0x1186, restores, returns.
#include "ff.h"

extern "C" void ext_64fae0(void);    // real exe code or GUESS stub
extern "C" void ext_634273(void*, int);  // free-like function (GUESS stub)
extern "C" void asm_658240(void);

__asm__(
    ".text\n"
    ".globl asm_658240\n"
    "asm_658240:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  call ext_64fae0\n"
    "  movl 0x1186(%esi), %eax\n"
    "  testl %eax, %eax\n"
    "  je asm_658240_end\n"
    "  pushl $4\n"
    "  pushl %eax\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "  movl $0, 0x1186(%esi)\n"
    "asm_658240_end:\n"
    "  popl %esi\n"
    "  ret\n");

PCREG(658240, asm_658240);
