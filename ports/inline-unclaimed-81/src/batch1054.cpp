// batch1054.cpp - area 81, batch 1054: 0x661340, thiscall vtable init and conditional free.
// Sets vtable word 0x6c4a00, calls 0x4eb3d0, tests flag bit, optionally frees, returns this.
#include "ff.h"

extern "C" void ext_4eb3d0(void);  // real exe code or GUESS stub
extern "C" void asm_661340(void);

__asm__(
    ".text\n"
    ".globl asm_661340\n"
    "asm_661340:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  movl $0x6c4a00, (%esi)\n"
    "  call ext_4eb3d0\n"
    "  testb $1, 0x8(%ebp)\n"
    "  je asm_661340_end\n"
    "  pushl $0x21b1\n"
    "  pushl %esi\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "asm_661340_end:\n"
    "  movl %esi, %eax\n"
    "  popl %esi\n"
    "  popl %ebp\n"
    "  ret $4\n");

PCREG(661340, asm_661340);
