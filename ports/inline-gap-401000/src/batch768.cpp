// batch768.cpp - gap band batch 768 (docs/20-gap-band-401000.md): 0x405bb0, cdecl, returns a float in st0. File-scope assembly
// transcription of the exe instructions (the x87 stack carries the accumulator).
#include "ff.h"

extern "C" void fn405bb0(void);

asm(
    ".text\n"
    ".globl fn405bb0\n"
    "fn405bb0:\n"
    "  movl 4(%esp), %edx\n"
    "  flds 0x6bdfd4\n"
    "  testl %edx, %edx\n"
    "  jle 2f\n"
    "  movl 0x10(%esp), %ecx\n"
    "  movl 8(%esp), %eax\n"
    "  pushl %esi\n"
    "  leal (,%ecx,4), %esi\n"
    "  movl 0x10(%esp), %ecx\n"
    "1:\n"
    "  flds (%eax)\n"
    "  fsubs (%ecx)\n"
    "  addl $4, %eax\n"
    "  addl %esi, %ecx\n"
    "  decl %edx\n"
    "  fld %st(0)\n"
    "  fmul %st(1), %st\n"
    "  faddp %st, %st(2)\n"
    "  fstp %st(0)\n"
    "  jne 1b\n"
    "  popl %esi\n"
    "2:\n"
    "  ret\n");

PCREG(405bb0, fn405bb0);
