// batch1055.cpp - area 81, batch 1055: 0x4b0a00, thiscall with complex conditions.
// Compares argument to field at this+0x51, loads from global, calls vtable slot 0xc4, clears byte if successful.
#include "ff.h"

extern "C" void asm_4b0a00(void);

__asm__(
    ".text\n"
    ".globl asm_4b0a00\n"
    "asm_4b0a00:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  movw 0x8(%ebp), %ax\n"
    "  cmpw 0x51(%ecx), %ax\n"
    "  jne asm_4b0a00_end\n"
    "  movl $0x70039c, %eax\n"
    "  movl (%eax), %eax\n"
    "  movl 0x1a9f(%eax), %ecx\n"
    "  testl %ecx, %ecx\n"
    "  je asm_4b0a00_end\n"
    "  movl (%ecx), %eax\n"
    "  call *0xc4(%eax)\n"
    "  testl %eax, %eax\n"
    "  je asm_4b0a00_end\n"
    "  movb $0, 0x1209(%eax)\n"
    "asm_4b0a00_end:\n"
    "  xorl %eax, %eax\n"
    "  popl %ebp\n"
    "  ret $8\n");

PCREG(4b0a00, asm_4b0a00);
