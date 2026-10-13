// batch1048.cpp - area 81, batch 1048: 0x5738c0, one stack argument a, ret 4 (ecx not used on entry). Reads the global object at 0x70039c, takes the
// object at its unaligned field +0x9b, calls that object's vtable slot 0x58 (no arguments), then calls the result's slot 0x254 with a and returns its
// eax. Module-level asm keeps the push-before-load order exact; both slots are GUESS stubs in the spec.
#include "ff.h"

extern "C" void asm_5738c0(void);

__asm__(
    ".text\n"
    ".globl asm_5738c0\n"
    "asm_5738c0:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  movl 0x70039c, %eax\n"
    "  pushl 8(%ebp)\n"
    "  movl 0x9b(%eax), %ecx\n"
    "  movl (%ecx), %eax\n"
    "  call *0x58(%eax)\n"
    "  movl %eax, %ecx\n"
    "  movl (%eax), %edx\n"
    "  call *0x254(%edx)\n"
    "  popl %ebp\n"
    "  ret $4\n");
PCREG(5738c0, asm_5738c0);
