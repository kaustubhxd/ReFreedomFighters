// batch31072.cpp - tier B destructors, constructors, lookup thunks (asm, stack exact).
#include "ff.h"

extern "C" void ext_43e920(void);
extern "C" void ext_441a60(void);
extern "C" void ext_469870(void);
extern "C" void ext_5003d0(void);
extern "C" void ext_634273(void);

asm(
    ".text\n"
    ".globl thunk5493f0\n"
    "thunk5493f0:\n"
    "  testb $1, 4(%esp)\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  movl $0x6a3298, (%esi)\n"
    "  je 1f\n"
    "  pushl $0x2326\n"
    "  pushl %esi\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "1:\n"
    "  movl %esi, %eax\n"
    "  popl %esi\n"
    "  ret $4\n"
    ".globl thunk5ab4c0\n"
    "thunk5ab4c0:\n"
    "  testb $1, 4(%esp)\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  movl $0x6b01dc, (%esi)\n"
    "  je 1f\n"
    "  pushl $4\n"
    "  pushl %esi\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "1:\n"
    "  movl %esi, %eax\n"
    "  popl %esi\n"
    "  ret $4\n"
    ".globl thunk5b7580\n"
    "thunk5b7580:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  call ext_469870\n"
    "  orl $0x20, 4(%esi)\n"
    "  movl %esi, %eax\n"
    "  movl $0, 0x44(%esi)\n"
    "  movl $0x6b2304, (%esi)\n"
    "  popl %esi\n"
    "  ret\n"
    ".globl thunk5bc4b0\n"
    "thunk5bc4b0:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  call ext_469870\n"
    "  orl $0x20, 4(%esi)\n"
    "  movl %esi, %eax\n"
    "  movl $0, 0x44(%esi)\n"
    "  movl $0x6b2f30, (%esi)\n"
    "  popl %esi\n"
    "  ret\n"
    ".globl thunk5c7ac0\n"
    "thunk5c7ac0:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  call ext_469870\n"
    "  orl $0x20, 4(%esi)\n"
    "  movl %esi, %eax\n"
    "  movl $0, 0x44(%esi)\n"
    "  movl $0x6b47b0, (%esi)\n"
    "  popl %esi\n"
    "  ret\n"
    ".globl thunk55c8e0\n"
    "thunk55c8e0:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  movl 8(%esp), %ecx\n"
    "  pushl $0\n"
    "  movl 4(%ecx), %ecx\n"
    "  call ext_5003d0\n"
    "  cmpl $0, (%eax)\n"
    "  movl 0x1c(%esi), %eax\n"
    "  setne %dl\n"
    "  movb %dl, 0x929(%eax)\n"
    "  popl %esi\n"
    "  ret $4\n"
    ".globl thunk55c7a0\n"
    "thunk55c7a0:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  movl 8(%esp), %ecx\n"
    "  pushl $0\n"
    "  movl 4(%ecx), %ecx\n"
    "  call ext_5003d0\n"
    "  movl 0x1c(%esi), %ecx\n"
    "  popl %esi\n"
    "  movzwl (%eax), %eax\n"
    "  movl (%ecx), %edx\n"
    "  movl %eax, 4(%esp)\n"
    "  jmp *0x6ac(%edx)\n"
    ".globl thunk4ea280\n"
    "thunk4ea280:\n"
    "  pushl %edi\n"
    "  movl %ecx, %edi\n"
    "  movl 12(%esp), %edx\n"
    "  movl 8(%esp), %ecx\n"
    "  leal 0x3c(%edi), %eax\n"
    "  pushl %eax\n"
    "  call ext_43e920\n"
    "  movl 8(%esp), %ecx\n"
    "  leal 0x18(%edi), %edx\n"
    "  call ext_441a60\n"
    "  popl %edi\n"
    "  ret $8\n");

extern "C" void thunk5493f0(void);
extern "C" void thunk5ab4c0(void);
extern "C" void thunk5b7580(void);
extern "C" void thunk5bc4b0(void);
extern "C" void thunk5c7ac0(void);
extern "C" void thunk55c8e0(void);
extern "C" void thunk55c7a0(void);
extern "C" void thunk4ea280(void);
PCREG(5493f0, thunk5493f0);
PCREG(5ab4c0, thunk5ab4c0);
PCREG(5b7580, thunk5b7580);
PCREG(5bc4b0, thunk5bc4b0);
PCREG(5c7ac0, thunk5c7ac0);
PCREG(55c8e0, thunk55c8e0);
PCREG(55c7a0, thunk55c7a0);
PCREG(4ea280, thunk4ea280);
