// batch31132.cpp - Sonnet h1: tier B stack-struct thunks (asm, stack exact).
#include "ff.h"

extern "C" void ext_42b390(void);
extern "C" void ext_6028b0(void);
extern "C" void ext_602a60(void);

asm(
    ".text\n"
    ".globl thunk5f16c0\n"
    "thunk5f16c0:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  pushl %esi\n"
    "  pushl 0x1c(%ebp)\n"
    "  movl %ecx, %esi\n"
    "  leal 0x1f(%ebp), %eax\n"
    "  pushl 0x18(%ebp)\n"
    "  pushl 0x14(%ebp)\n"
    "  pushl 0x10(%ebp)\n"
    "  pushl 0xc(%ebp)\n"
    "  subl $0xc, %esp\n"
    "  movl %esp, %ecx\n"
    "  pushl %eax\n"
    "  pushl 8(%ebp)\n"
    "  call ext_42b390\n"
    "  movl 0xc(%esi), %eax\n"
    "  movl 4(%eax), %ecx\n"
    "  movl (%ecx), %ecx\n"
    "  call ext_602a60\n"
    "  popl %esi\n"
    "  popl %ebp\n"
    "  ret $0x18\n"
    ".globl thunk5f1680\n"
    "thunk5f1680:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  pushl %esi\n"
    "  pushl 0x24(%ebp)\n"
    "  movl %ecx, %esi\n"
    "  leal 0x27(%ebp), %eax\n"
    "  pushl 0x20(%ebp)\n"
    "  pushl 0x1c(%ebp)\n"
    "  pushl 0x18(%ebp)\n"
    "  pushl 0x14(%ebp)\n"
    "  pushl 0x10(%ebp)\n"
    "  pushl 0xc(%ebp)\n"
    "  subl $0xc, %esp\n"
    "  movl %esp, %ecx\n"
    "  pushl %eax\n"
    "  pushl 8(%ebp)\n"
    "  call ext_42b390\n"
    "  movl 0xc(%esi), %eax\n"
    "  movl 4(%eax), %ecx\n"
    "  movl (%ecx), %ecx\n"
    "  call ext_6028b0\n"
    "  popl %esi\n"
    "  popl %ebp\n"
    "  ret $0x20\n");

extern "C" void thunk5f16c0(void);
extern "C" void thunk5f1680(void);
PCREG(5f16c0, thunk5f16c0);
PCREG(5f1680, thunk5f1680);
