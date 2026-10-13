// batch775.cpp - gap band batch 775 (docs/20-gap-band-401000.md): 0x403f90, cdecl (pn, x, b, out), void. File-scope assembly
// transcription of the exe instructions: the x87 divide keeps its own rounding (a C float divide would round differently).
#include "ff.h"

extern "C" void fn403f90(void);

asm(
    ".text\n"
    ".globl fn403f90\n"
    "fn403f90:\n"
    "  movl 4(%esp), %eax\n"
    "  movl (%eax), %eax\n"
    "  testl %eax, %eax\n"
    "  jle 9f\n"
    "  movl 8(%esp), %ecx\n"
    "  movl 0x10(%esp), %edx\n"
    "  pushl %esi\n"
    "  movl 0x10(%esp), %esi\n"
    "  pushl %edi\n"
    "  subl %ecx, %esi\n"
    "  subl %ecx, %edx\n"
    "  movl %eax, %edi\n"
    "1:\n"
    "  flds (%ecx)\n"
    "  fcomps 0x6bdfd4\n"
    "  fnstsw %ax\n"
    "  testb $0x40, %ah\n"
    "  jne 2f\n"
    "  flds (%ecx)\n"
    "  fdivs (%esi,%ecx,1)\n"
    "  fstps (%edx,%ecx,1)\n"
    "  jmp 3f\n"
    "2:\n"
    "  movl $0, (%edx,%ecx,1)\n"
    "3:\n"
    "  addl $4, %ecx\n"
    "  decl %edi\n"
    "  jne 1b\n"
    "  popl %edi\n"
    "  popl %esi\n"
    "9:\n"
    "  ret\n");

PCREG(403f90, fn403f90);
