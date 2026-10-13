// batch805.cpp - core gameplay batch 805 (docs/20-unclaimed-65.md, batch 805): four small assembly transcriptions (the stack and ecx
// hand-off must match the exe exactly).
#include "ff.h"

extern "C" void tail577cf0(void);
extern "C" void tail577d50(void);
extern "C" void fn5dd3e0(void);
extern "C" void fn4a1de0(void);

asm(
    ".text\n"
    ".globl tail577cf0\n"
    "tail577cf0:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  call ext_573da0\n"
    "  movl %esi, %ecx\n"
    "  popl %esi\n"
    "  jmp ext_577d60\n"
    ".globl tail577d50\n"
    "tail577d50:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  call ext_573db0\n"
    "  movl %esi, %ecx\n"
    "  popl %esi\n"
    "  jmp ext_577d60\n"
    ".globl fn5dd3e0\n"
    "fn5dd3e0:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  pushl 0xc(%ebp)\n"
    "  call ext_5dd4b0\n"
    "  popl %ebp\n"
    "  ret $8\n"
    ".globl fn4a1de0\n"
    "fn4a1de0:\n"
    "  andl $-2, 0x5a(%ecx)\n"
    "  pushl %ecx\n"
    "  movb $1, %cl\n"
    "  call ext_4a0d40\n"
    "  movl %eax, %ecx\n"
    "  call ext_4a22f0\n"
    "  ret\n");

PCREG(577cf0, tail577cf0);
PCREG(577d50, tail577d50);
PCREG(5dd3e0, fn5dd3e0);
PCREG(4a1de0, fn4a1de0);
