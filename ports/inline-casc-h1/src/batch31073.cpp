// batch31073.cpp - tier B constructors/destructors and small call-through thunks (asm, stack exact).
#include "ff.h"

extern "C" void ext_43de70(void);
extern "C" void ext_469870(void);
extern "C" void ext_4e66a0(void);
extern "C" void ext_5ab130(void);
extern "C" void ext_5af040(void);
extern "C" void ext_5e9b70(void);
extern "C" void ext_605b90(void);
extern "C" void ext_634273(void);
extern "C" void ext_658020(void);

asm(
    ".text\n"
    ".globl thunk5d5c90\n"
    "thunk5d5c90:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  call ext_469870\n"
    "  orl $0x20, 4(%esi)\n"
    "  movl %esi, %eax\n"
    "  movl $0, 0x44(%esi)\n"
    "  movl $0x6b58c8, (%esi)\n"
    "  popl %esi\n"
    "  ret\n"
    ".globl thunk5dd5e0\n"
    "thunk5dd5e0:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  call ext_469870\n"
    "  orl $0x20, 4(%esi)\n"
    "  movl %esi, %eax\n"
    "  movl $0, 0x44(%esi)\n"
    "  movl $0x6b6e38, (%esi)\n"
    "  popl %esi\n"
    "  ret\n"
    ".globl thunk5df850\n"
    "thunk5df850:\n"
    "  testb $1, 4(%esp)\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  movl $0x685294, (%esi)\n"
    "  je 1f\n"
    "  pushl $0x14\n"
    "  pushl %esi\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "1:\n"
    "  movl %esi, %eax\n"
    "  popl %esi\n"
    "  ret $4\n"
    ".globl thunk5f9570\n"
    "thunk5f9570:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  pushl %edi\n"
    "  movl 8(%esi), %edi\n"
    "  leal 0x10(%esi), %ecx\n"
    "  subl 4(%esi), %edi\n"
    "  addl $5, %edi\n"
    "  call ext_605b90\n"
    "  leal 0x2c(%esi), %ecx\n"
    "  addl %eax, %edi\n"
    "  call ext_605b90\n"
    "  addl %edi, %eax\n"
    "  popl %edi\n"
    "  popl %esi\n"
    "  ret\n"
    ".globl thunk6580e0\n"
    "thunk6580e0:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  call ext_658020\n"
    "  testb $1, 8(%esp)\n"
    "  je 1f\n"
    "  pushl $0x11e7\n"
    "  pushl %esi\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "1:\n"
    "  movl %esi, %eax\n"
    "  popl %esi\n"
    "  ret $4\n"
    ".globl thunk47fd30\n"
    "thunk47fd30:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  movl 0x8c(%esi), %eax\n"
    "  movl $0x68b364, (%esi)\n"
    "  testl %eax, %eax\n"
    "  je 1f\n"
    "  pushl $0x44\n"
    "  pushl 4(%eax)\n"
    "  call ext_634273\n"
    "  pushl $8\n"
    "  pushl 0x8c(%esi)\n"
    "  call ext_634273\n"
    "  addl $0x10, %esp\n"
    "1:\n"
    "  movl %esi, %ecx\n"
    "  popl %esi\n"
    "  jmp ext_43de70\n"
    ".globl thunk534d30\n"
    "thunk534d30:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  movl $0x6a1a60, (%esi)\n"
    "  call ext_4e66a0\n"
    "  testb $1, 8(%esp)\n"
    "  je 1f\n"
    "  pushl $0xd\n"
    "  pushl %esi\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "1:\n"
    "  movl %esi, %eax\n"
    "  popl %esi\n"
    "  ret $4\n"
    ".globl thunk5aefc0\n"
    "thunk5aefc0:\n"
    "  pushl %esi\n"
    "  pushl 8(%esp)\n"
    "  movl %ecx, %esi\n"
    "  call ext_5af040\n"
    "  cmpl $8, %eax\n"
    "  je 1f\n"
    "  movl 0x20(%esi,%eax,4), %eax\n"
    "  popl %esi\n"
    "  ret $4\n"
    "1:\n"
    "  xorl %eax, %eax\n"
    "  popl %esi\n"
    "  ret $4\n"
    ".globl thunk5e9b40\n"
    "thunk5e9b40:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  movl 0x1d0f(%esi), %ecx\n"
    "  testl %ecx, %ecx\n"
    "  je 1f\n"
    "  cmpb $0, 0x3c6(%ecx)\n"
    "  je 1f\n"
    "  pushl 8(%esp)\n"
    "  call ext_5ab130\n"
    "  movl %esi, %ecx\n"
    "  call ext_5e9b70\n"
    "1:\n"
    "  popl %esi\n"
    "  ret $4\n");

extern "C" void thunk5d5c90(void);
extern "C" void thunk5dd5e0(void);
extern "C" void thunk5df850(void);
extern "C" void thunk5f9570(void);
extern "C" void thunk6580e0(void);
extern "C" void thunk47fd30(void);
extern "C" void thunk534d30(void);
extern "C" void thunk5aefc0(void);
extern "C" void thunk5e9b40(void);
PCREG(5d5c90, thunk5d5c90);
PCREG(5dd5e0, thunk5dd5e0);
PCREG(5df850, thunk5df850);
PCREG(5f9570, thunk5f9570);
PCREG(6580e0, thunk6580e0);
PCREG(47fd30, thunk47fd30);
PCREG(534d30, thunk534d30);
PCREG(5aefc0, thunk5aefc0);
PCREG(5e9b40, thunk5e9b40);
