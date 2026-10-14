// batch34008.cpp - cascade escalation batch 34008: vtable tail jumps in assembly (empty ebp frames; entry stack untouched at the jump).
#include "ff.h"

extern "C" void thunk45d5b0(void);
extern "C" void thunk4d49b0(void);

asm(
    ".text\n"
    ".globl thunk45d5b0\n"
    "thunk45d5b0:\n"          // slot 0x48 of this's vtable
    "  movl (%ecx), %eax\n"
    "  jmp *0x48(%eax)\n"
    ".globl thunk4d49b0\n"
    "thunk4d49b0:\n"          // this += 0x10db; slot 4 of the subobject's vtable
    "  addl $0x10db, %ecx\n"
    "  movl (%ecx), %eax\n"
    "  jmp *4(%eax)\n");
PCREG(45d5b0, thunk45d5b0);
PCREG(4d49b0, thunk4d49b0);
