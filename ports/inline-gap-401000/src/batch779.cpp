// batch779.cpp - gap band batch 779 (docs/20-gap-band-401000.md): 0x41fe80, thiscall, tail jump to 0x42bae0 (assembly).
#include "ff.h"

extern "C" void fn41fe80(void);

asm(
    ".text\n"
    ".globl fn41fe80\n"
    "fn41fe80:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  leal 0x1e0b(%esi), %ecx\n"
    "  call ext_4cbec0\n"
    "  leal 0x1d71(%esi), %ecx\n"
    "  call ext_4cbec0\n"
    "  leal 0x1cf1(%esi), %ecx\n"
    "  call ext_4cbec0\n"
    "  leal 0x1c71(%esi), %ecx\n"
    "  call ext_4cbec0\n"
    "  leal 0x1bf1(%esi), %ecx\n"
    "  call ext_4cbec0\n"
    "  leal 0x1b71(%esi), %ecx\n"
    "  call ext_4cbec0\n"
    "  movl %esi, %ecx\n"
    "  popl %esi\n"
    "  jmp ext_42bae0\n");

PCREG(41fe80, fn41fe80);
