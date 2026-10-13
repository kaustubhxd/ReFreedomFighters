// batch761.cpp - gap band batch 761 (docs/20-gap-band-401000.md): 0x40ba30, cdecl, a clamp of an x87 value to [0, 0x3ff]. File-scope
// assembly transcription of the exe instructions: st0 stays live across the call to 0x634dfa (exe code).
#include "ff.h"

extern "C" void fn40ba30(void);

asm(
    ".text\n"
    ".globl fn40ba30\n"
    "fn40ba30:\n"
    "  movl 4(%esp), %eax\n"
    "  flds (%eax)\n"
    "  fmuls 0x6be0f4\n"
    "  fadds 0x6be0f0\n"
    "  call ext_634dfa\n"
    "  cmpl $0x3ff, %eax\n"
    "  jle 1f\n"
    "  movl $0x3ff, %eax\n"
    "  ret\n"
    "1:\n"
    "  xorl %ecx, %ecx\n"
    "  testl %eax, %eax\n"
    "  setl %cl\n"
    "  decl %ecx\n"
    "  andl %ecx, %eax\n"
    "  ret\n");

PCREG(40ba30, fn40ba30);
