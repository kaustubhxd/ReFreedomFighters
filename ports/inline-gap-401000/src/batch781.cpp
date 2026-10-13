// batch781.cpp - gap band batch 781 (docs/20-gap-band-401000.md): 0x4050a0, cdecl (x), returns st0. Assembly transcription (x87).
#include "ff.h"

extern "C" void fn4050a0(void);
extern "C" void ext_634e06(void);

asm(
    ".text\n"
    ".globl fn4050a0\n"
    "fn4050a0:\n"
    "  subl $8, %esp\n"
    "  movl 0xc(%esp), %ecx\n"
    "  movl %ecx, %eax\n"
    "  andl $0x1fffff, %eax\n"
    "  movl %eax, 0xc(%esp)\n"
    "  movl %ecx, %eax\n"
    "  fildl 0xc(%esp)\n"
    "  sarl $0x15, %eax\n"
    "  andl $0x3ff, %eax\n"
    "  fstpl (%esp)\n"
    "  testl $0x80000000, %ecx\n"
    "  je 1f\n"
    "  fldl (%esp)\n"
    "  fchs\n"
    "  fstpl (%esp)\n"
    "1:\n"
    "  movl 4(%esp), %ecx\n"
    "  movl (%esp), %edx\n"
    "  addl $0xfffffcec, %eax\n"
    "  pushl %eax\n"
    "  pushl %ecx\n"
    "  pushl %edx\n"
    "  call ext_634e06\n"
    "  addl $0x14, %esp\n"
    "  ret\n");

PCREG(4050a0, fn4050a0);
