// u69_90.cpp - area 69, gameplay-core residue-8. 0x506e80 (thiscall, one stack arg, ret 4). Naked asm: the exe's instructions copied one for one,
// so ECX, EAX and the stack match. Calls: G=[0x700390] vt[0x20](0x69cff0, 0x290) -> X; this[+0x18] vt[0x20]() -> Y; X vt[0x2c](Y[+4] or 0x67c8e8,
// 0x69d188, X) (cdecl, caller pops 0xc); then the global function pointer [0x7003b0] is called. If that pointer is 0 the exe reaches an int3 at
// 0x506ecf, so the port keeps the same byte there.
#include "ff.h"

extern "C" void opcall506e80(void);
__asm__(
    ".text\n"
    ".globl opcall506e80\n"
    "opcall506e80:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  movl 0x700390, %ecx\n"
    "  pushl %edi\n"
    "  pushl $0x290\n"
    "  pushl $0x69cff0\n"
    "  movl (%ecx), %eax\n"
    "  call *0x20(%eax)\n"
    "  movl 0x18(%esi), %ecx\n"
    "  movl %eax, %edi\n"
    "  movl (%ecx), %edx\n"
    "  call *0x20(%edx)\n"
    "  movl $0x67c8e8, %edx\n"
    "  movl 4(%eax), %ecx\n"
    "  testl %ecx, %ecx\n"
    "  movl (%edi), %eax\n"
    "  cmovne %ecx, %edx\n"
    "  pushl %edx\n"
    "  pushl $0x69d188\n"
    "  pushl %edi\n"
    "  call *0x2c(%eax)\n"
    "  movl 0x7003b0, %eax\n"
    "  addl $0xc, %esp\n"
    "  popl %edi\n"
    "  popl %esi\n"
    "  testl %eax, %eax\n"
    "  je 1f\n"
    "  call *%eax\n"
    "  ret $4\n"
    "1:\n"
    "  int3\n");
PCREG(506e80, opcall506e80);
