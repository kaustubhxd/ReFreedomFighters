// batch1046.cpp - area 81, batch 1046: 0x651580, thiscall (this; one stack argument as the target expects), ret 4. Loads the inner object at the
// unaligned field this+0xbd; when null it returns (ret 4), otherwise it tail-jumps to the inner object's vtable slot 0x54 with ecx = inner. Module-level
// asm keeps the frame and the tail jump exact; the slot is a GUESS stub in the spec.
#include "ff.h"

extern "C" void asm_651580(void);

__asm__(
    ".text\n"
    ".globl asm_651580\n"
    "asm_651580:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  movl 0xbd(%ecx), %ecx\n"
    "  testl %ecx, %ecx\n"
    "  je 1f\n"
    "  movl (%ecx), %eax\n"
    "  popl %ebp\n"
    "  jmp *0x54(%eax)\n"
    "1:\n"
    "  popl %ebp\n"
    "  ret $4\n");
PCREG(651580, asm_651580);
