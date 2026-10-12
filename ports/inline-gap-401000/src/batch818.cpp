// batch818.cpp - core gameplay batch 818 (docs/20-unclaimed-65.md, batch 818): 0x46f510, a thiscall with no arguments. It keeps ecx in esi,
// calls 0x45f3a0 with ecx = this (no arguments; the callee pops nothing), restores ecx and TAIL-JUMPS to 0x46f240. Both callees are other
// claims, hooked by address in the spec (GUESS). Assembly, so the stack and the tail jump match the exe.
#include "ff.h"

extern "C" void fn46f510(void);
extern "C" void ext_45f3a0(void);   // thiscall, no arguments (hooked in the spec)
extern "C" void ext_46f240(void);   // tail target (hooked in the spec)

asm(
    ".text\n"
    ".globl fn46f510\n"
    "fn46f510:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  call ext_45f3a0\n"
    "  movl %esi, %ecx\n"
    "  popl %esi\n"
    "  jmp ext_46f240\n");

PCREG(46f510, fn46f510);
