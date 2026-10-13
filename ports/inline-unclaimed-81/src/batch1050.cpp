// batch1050.cpp - area 81, batch 1050: 0x45b8c0, fastcall to stdcall converter. Loads a global double constant,
// multiplies a float from eax+0x48 by a constant, converts to double, calls 0x634db2 (pow-like),
// converts result back to float, stores at this+0x647c, and tail-jumps to 0x45c180.
#include "ff.h"

extern "C" void ext_45c180(void);   // real exe code (the tail target)
extern "C" double ext_634db2(double, double);  // real exe code or GUESS stub
extern "C" void asm_45b8c0(void);

__asm__(
    ".text\n"
    ".globl asm_45b8c0\n"
    "asm_45b8c0:\n"
    "  movl $0x70039c, %eax\n"
    "  movl (%eax), %eax\n"
    "  movsd 0x684ce8, %xmm0\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  movss 0x48(%eax), %xmm1\n"
    "  mulss 0x67885c, %xmm1\n"
    "  cvtps2pd %xmm1, %xmm1\n"
    "  call ext_634db2\n"
    "  cvtsd2ss %xmm0, %xmm0\n"
    "  movl %esi, %ecx\n"
    "  movss %xmm0, 0x647c(%esi)\n"
    "  popl %esi\n"
    "  jmp ext_45c180\n");

PCREG(45b8c0, asm_45b8c0);
