// batch1041.cpp - area 81, batch 1041: 0x63b500, thiscall (this; two stack arguments as the target expects). Thunk: frame push/mov/pop, ecx +=
// 0x8270, then a tail jump to 0x65e300 (real exe code, ext_65e300). Module-level asm; the target is a GUESS stub in the spec.
#include "ff.h"

extern "C" void ext_65e300(void);
extern "C" void asm_63b500(void);

__asm__(
    ".text\n"
    ".globl asm_63b500\n"
    "asm_63b500:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  addl $0x8270, %ecx\n"
    "  popl %ebp\n"
    "  jmp ext_65e300\n");
PCREG(63b500, asm_63b500);
