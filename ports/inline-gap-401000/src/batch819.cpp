// batch819.cpp - core gameplay batch 819 (docs/20-unclaimed-65.md, batch 819): two CopyEventDataBlock wrappers (core-todo/residue-01.txt).
// 0x582790 (CExplode::CopyEventDataBlock) and 0x5c5590 (CTargetObtained::CopyEventDataBlock) are thiscall with one argument (ret 4 in
// their targets) that set up an empty frame (push ebp; mov ebp, esp; pop ebp) and TAIL-JUMP to 0x584b40 and 0x5c56f0. The wrapper
// keeps the entry stack, so the jump is assembly. Both targets are other claims, hooked by address in the spec (GUESS).
#include "ff.h"

extern "C" void fn582790(void);
extern "C" void fn5c5590(void);
extern "C" void ext_584b40(void);   // tail target (hooked in the spec)
extern "C" void ext_5c56f0(void);   // tail target (hooked in the spec)

asm(
    ".text\n"
    ".globl fn582790\n"
    "fn582790:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  popl %ebp\n"
    "  jmp ext_584b40\n"
    ".globl fn5c5590\n"
    "fn5c5590:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  popl %ebp\n"
    "  jmp ext_5c56f0\n");

PCREG(582790, fn582790);
PCREG(5c5590, fn5c5590);
