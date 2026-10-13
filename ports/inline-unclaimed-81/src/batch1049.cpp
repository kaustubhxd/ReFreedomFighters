// batch1049.cpp - area 81, batch 1049: 0x65f540, thiscall (this; five stack arguments a..e), ret 0x14. Forwards to its own vtable slot 0x28 with
// (a, b, c, d, e, 1) and returns that call's eax. Module-level asm keeps the frame and push order exact; the slot is a GUESS stub in the spec.
#include "ff.h"

extern "C" void asm_65f540(void);

__asm__(
    ".text\n"
    ".globl asm_65f540\n"
    "asm_65f540:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  movl (%ecx), %eax\n"
    "  pushl $1\n"
    "  pushl 0x18(%ebp)\n"
    "  pushl 0x14(%ebp)\n"
    "  pushl 0x10(%ebp)\n"
    "  pushl 0xc(%ebp)\n"
    "  pushl 8(%ebp)\n"
    "  call *0x28(%eax)\n"
    "  popl %ebp\n"
    "  ret $0x14\n");
PCREG(65f540, asm_65f540);
