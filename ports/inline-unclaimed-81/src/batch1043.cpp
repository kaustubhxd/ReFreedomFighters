// batch1043.cpp - area 81, batch 1043: 0x63f4c0, plain ret, no arguments. Pushes the string address 0x6c2608 and calls 0x42ab62 (a debug print, cdecl;
// hooked by a GUESS stub in the spec), pops the argument, then reads the assert hook at 0x7003b0: when set it tail-jumps to it, when null it hits int3.
// Module-level asm keeps the order of instructions exact; no stand-ins in the port itself.
#include "ff.h"

extern "C" void ext_42ab62(void);
extern "C" void asm_63f4c0(void);

__asm__(
    ".text\n"
    ".globl asm_63f4c0\n"
    "asm_63f4c0:\n"
    "  pushl $0x6c2608\n"
    "  call ext_42ab62\n"
    "  movl 0x7003b0, %eax\n"
    "  addl $4, %esp\n"
    "  testl %eax, %eax\n"
    "  je 1f\n"
    "  jmp *%eax\n"
    "1:\n"
    "  int3\n"
    "  ret\n");
PCREG(63f4c0, asm_63f4c0);
