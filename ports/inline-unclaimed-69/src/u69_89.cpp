// u69_89.cpp - area 69, gameplay-core residue-8. 0x51b600 ZCarIf::opaqueCall(OpaqueCallParameters_t&) (stdcall, one stack arg, ret 4).
// Naked asm, the exe's instructions copied one for one, so EAX, ECX and the stack match. Index = word [arg+0x10]:
// if index < [0x701800], call table[index] with the argument pushed (the table entry is stdcall, its ret pops the argument);
// else store index - count back into the word. Both paths end at the shared epilogue 0x51ad90.
#include "ff.h"

extern "C" void ext_51ad90(void);   // shared epilogue of the exe (ret 4)
extern "C" void opaqueCall51b600(void);
__asm__(
    ".text\n"
    ".globl opaqueCall51b600\n"
    "opaqueCall51b600:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  movl 8(%ebp), %eax\n"
    "  pushl %esi\n"
    "  movzwl 0x10(%eax), %edx\n"
    "  movl %edx, %esi\n"
    "  cmpl 0x701800, %esi\n"
    "  jae 1f\n"
    "  pushl %eax\n"
    "  movl 0x701808(,%esi,4), %eax\n"
    "  call *%eax\n"
    "  popl %esi\n"
    "  popl %ebp\n"
    "  ret $4\n"
    "1:\n"
    "  subl 0x701800, %edx\n"
    "  movw %dx, 0x10(%eax)\n"
    "  popl %esi\n"
    "  movl %eax, 8(%ebp)\n"
    "  popl %ebp\n"
    "  jmp ext_51ad90\n");
PCREG(51b600, opaqueCall51b600);
