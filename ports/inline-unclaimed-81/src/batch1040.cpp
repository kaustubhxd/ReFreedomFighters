// batch1040.cpp - area 81, batch 1040: 0x63f600, thiscall (this; one stack argument). Thunk: frame push/mov/pop, then a tail jump to 0x63ef00
// (real exe code, ext_63ef00). The stack is the caller's at the jump, so the callee sees the same arguments. Module-level asm; no stand-ins.
#include "ff.h"

extern "C" void ext_63ef00(void);
extern "C" void asm_63f600(void);

__asm__(
    ".text\n"
    ".globl asm_63f600\n"
    "asm_63f600:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  popl %ebp\n"
    "  jmp ext_63ef00\n");
PCREG(63f600, asm_63f600);
