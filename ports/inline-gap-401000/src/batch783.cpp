// batch783.cpp - gap band batch 783 (docs/20-gap-band-401000.md): 0x4205a0, thiscall (this), void. Assembly transcription: the slot 0x2c
// call uses the ecx the previous callee left (the exe does not reset it).
#include "ff.h"

extern "C" void fn4205a0(void);

asm(
    ".text\n"
    ".globl fn4205a0\n"
    "fn4205a0:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  pushl %edi\n"
    "  cmpl $0, 0x22c2(%esi)\n"
    "  movb $1, 0x60(%esi)\n"
    "  je 1f\n"
    "  movl 0x700390, %ecx\n"
    "  pushl $0x8f1\n"
    "  pushl $0x677fb4\n"
    "  movl (%ecx), %eax\n"
    "  call *0x20(%eax)\n"
    "  subl $0x80, %esp\n"
    "  addl $0x2242, %esi\n"
    "  movl %esp, %edi\n"
    "  movl $0x20, %ecx\n"
    "  rep movsl\n"
    "  movl (%eax), %edx\n"
    "  pushl $0x678450\n"
    "  pushl %eax\n"
    "  call *0x2c(%edx)\n"
    "  addl $0x88, %esp\n"
    "1:\n"
    "  popl %edi\n"
    "  popl %esi\n"
    "  ret\n");

PCREG(4205a0, fn4205a0);
