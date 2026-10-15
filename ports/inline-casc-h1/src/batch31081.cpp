// batch31081.cpp - Sonnet h1: tier C vtable and global-object call thunks (asm, stack exact).
#include "ff.h"

extern "C" void ext_42ad20(void);
extern "C" void ext_465fd0(void);
extern "C" void ext_504880(void);
extern "C" void ext_5672c0(void);

asm(
    ".text\n"
    ".globl thunk4d1e10\n"
    "thunk4d1e10:\n"
    "  movl (%ecx), %eax\n"
    "  pushl 4(%esp)\n"
    "  call *0x3c(%eax)\n"
    "  movl (%eax), %eax\n"
    "  ret $4\n"
    ".globl thunk551080\n"
    "thunk551080:\n"
    "  movl 4(%esp), %ecx\n"
    "  pushl 8(%esp)\n"
    "  movl (%ecx), %eax\n"
    "  call *0x18(%eax)\n"
    "  ret $0xc\n"
    ".globl thunk656760\n"
    "thunk656760:\n"
    "  movl (%ecx), %eax\n"
    "  pushl 4(%esp)\n"
    "  call *0xc(%eax)\n"
    "  movzwl 2(%eax), %eax\n"
    "  ret $4\n"
    ".globl thunk607910\n"
    "thunk607910:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  call ext_504880\n"
    "  movl (%esi), %eax\n"
    "  movl %esi, %ecx\n"
    "  pushl $1\n"
    "  call *0x9c(%eax)\n"
    "  popl %esi\n"
    "  ret\n"
    ".globl thunk466d90\n"
    "thunk466d90:\n"
    "  movl 0x70039c, %eax\n"
    "  pushl $0\n"
    "  pushl $0x685f44\n"
    "  movl 0x9b(%eax), %eax\n"
    "  movl 0xadc(%eax), %ecx\n"
    "  movl (%ecx), %eax\n"
    "  call *0x25c(%eax)\n"
    "  movl 0x7003b8, %ecx\n"
    "  movl %eax, 0x4ac(%ecx)\n"
    "  ret\n"
    ".globl thunk472fd0\n"
    "thunk472fd0:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  call ext_465fd0\n"
    "  movl (%esi), %eax\n"
    "  movl %esi, %ecx\n"
    "  pushl $0x689770\n"
    "  call *0x104(%eax)\n"
    "  movl %eax, 0x2e3(%esi)\n"
    "  popl %esi\n"
    "  ret\n"
    ".globl thunk4d1dd0\n"
    "thunk4d1dd0:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  pushl $0\n"
    "  movl (%esi), %eax\n"
    "  call *0x10(%eax)\n"
    "  movl 0xc(%esi), %eax\n"
    "  popl %esi\n"
    "  movl 4(%eax), %eax\n"
    "  andl $0x3fffffff, %eax\n"
    "  ret\n"
    ".globl thunk566ee0\n"
    "thunk566ee0:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  pushl 0x198(%esi)\n"
    "  call ext_5672c0\n"
    "  movl (%esi), %eax\n"
    "  movl %esi, %ecx\n"
    "  pushl $0\n"
    "  call *0xd0(%eax)\n"
    "  popl %esi\n"
    "  ret\n"
    ".globl thunk425150\n"
    "thunk425150:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  movl 0x28(%esi), %ecx\n"
    "  testl %ecx, %ecx\n"
    "  je 1f\n"
    "  movl (%ecx), %eax\n"
    "  pushl $1\n"
    "  call *(%eax)\n"
    "1:\n"
    "  movl %esi, %ecx\n"
    "  popl %esi\n"
    "  jmp ext_42ad20\n"
    ".globl thunk467f60\n"
    "thunk467f60:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  movl (%esi), %eax\n"
    "  call *0x408(%eax)\n"
    "  movl (%esi), %eax\n"
    "  movl %esi, %ecx\n"
    "  call *0x404(%eax)\n"
    "  movl (%esi), %eax\n"
    "  movl %esi, %ecx\n"
    "  popl %esi\n"
    "  jmp *0x40c(%eax)\n"
    ".globl thunk470bf0\n"
    "thunk470bf0:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  movl (%esi), %eax\n"
    "  call *0x350(%eax)\n"
    "  pushl 0xd5(%esi)\n"
    "  movl %eax, %ecx\n"
    "  movl (%eax), %edx\n"
    "  call *0x358(%edx)\n"
    "  movl %eax, 0xd5(%esi)\n"
    "  popl %esi\n"
    "  ret\n"
    ".globl thunk51d0d0\n"
    "thunk51d0d0:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  movl 0x499(%esi), %eax\n"
    "  testl %eax, %eax\n"
    "  jne 1f\n"
    "  movl (%esi), %eax\n"
    "  pushl 0x491(%esi)\n"
    "  call *0x2e8(%eax)\n"
    "  movl %eax, 0x499(%esi)\n"
    "1:\n"
    "  popl %esi\n"
    "  ret\n"
    ".globl thunk5c2c80\n"
    "thunk5c2c80:\n"
    "  movl 0x70039c, %eax\n"
    "  movl 0x9b(%eax), %ecx\n"
    "  movl (%ecx), %eax\n"
    "  call *0x134(%eax)\n"
    "  pushl $2\n"
    "  pushl $0\n"
    "  pushl $0x6b3d60\n"
    "  movl (%eax), %edx\n"
    "  movl %eax, %ecx\n"
    "  call *0x5c(%edx)\n"
    "  ret\n");

extern "C" void thunk4d1e10(void);
extern "C" void thunk551080(void);
extern "C" void thunk656760(void);
extern "C" void thunk607910(void);
extern "C" void thunk466d90(void);
extern "C" void thunk472fd0(void);
extern "C" void thunk4d1dd0(void);
extern "C" void thunk566ee0(void);
extern "C" void thunk425150(void);
extern "C" void thunk467f60(void);
extern "C" void thunk470bf0(void);
extern "C" void thunk51d0d0(void);
extern "C" void thunk5c2c80(void);
PCREG(4d1e10, thunk4d1e10);
PCREG(551080, thunk551080);
PCREG(656760, thunk656760);
PCREG(607910, thunk607910);
PCREG(466d90, thunk466d90);
PCREG(472fd0, thunk472fd0);
PCREG(4d1dd0, thunk4d1dd0);
PCREG(566ee0, thunk566ee0);
PCREG(425150, thunk425150);
PCREG(467f60, thunk467f60);
PCREG(470bf0, thunk470bf0);
PCREG(51d0d0, thunk51d0d0);
PCREG(5c2c80, thunk5c2c80);
