// batch769.cpp - gap band batch 769 (docs/20-gap-band-401000.md): 0x403ea0, cdecl, void. File-scope assembly transcription of the exe
// instructions (56-step x87 loop; the constant c and the argument arg4 stay on the x87 stack and in memory as in the exe).
#include "ff.h"

extern "C" void fn403ea0(void);

asm(
    ".text\n"
    ".globl fn403ea0\n"
    "fn403ea0:\n"
    "  movl 0xc(%esp), %eax\n"
    "  movl 8(%esp), %ecx\n"
    "  flds 0x6be05c\n"
    "  movl 4(%esp), %edx\n"
    "  pushl %esi\n"
    "  fsubs 0x14(%esp)\n"
    "  subl %eax, %ecx\n"
    "  subl %eax, %edx\n"
    "  movl $0x38, %esi\n"
    "1:\n"
    "  fld %st(0)\n"
    "  fmuls (%ecx,%eax,1)\n"
    "  flds 0x14(%esp)\n"
    "  fmuls (%eax)\n"
    "  addl $4, %eax\n"
    "  decl %esi\n"
    "  faddp %st, %st(1)\n"
    "  fstps -4(%edx,%eax,1)\n"
    "  jne 1b\n"
    "  fstp %st(0)\n"
    "  popl %esi\n"
    "  ret\n");

PCREG(403ea0, fn403ea0);
