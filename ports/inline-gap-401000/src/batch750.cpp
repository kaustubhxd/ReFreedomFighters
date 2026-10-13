// batch750.cpp - gap band 0x401000-0x421000, batch 750 (docs/20-gap-band-401000.md): 0x41d200, a CRT-style tail call through the
// function pointer in global 0x6fd1a0 (after a cdecl call to 0x41e010). Written in assembly: a C body gets a stack adjustment before the
// call, and the tail jump must leave the entry stack exactly as it was.
#include "ff.h"

extern "C" void tail41d200(void);

asm(
    ".text\n"
    ".globl tail41d200\n"
    "tail41d200:\n"
    "  pushl $0x677004\n"
    "  call ext_41e010\n"
    "  addl $4, %esp\n"
    "  movl 0x6fd1a0, %eax\n"
    "  testl %eax, %eax\n"
    "  je 1f\n"
    "  jmp *%eax\n"
    "1:\n"
    "  xorl %eax, %eax\n"
    "  ret\n");

PCREG(41d200, tail41d200);
