// batch31070.cpp - Sonnet h1: tier B call-through thunks (asm, stack exact).
#include "ff.h"

extern "C" void ext_42ab26(void);
extern "C" void ext_445c50(void);
extern "C" void ext_45f3c0(void);
extern "C" void ext_4805a0(void);
extern "C" void ext_4973b0(void);
extern "C" void ext_4d24e0(void);
extern "C" void ext_4d2700(void);
extern "C" void ext_4e5e60(void);
extern "C" void ext_534190(void);
extern "C" void ext_628c80(void);

asm(
    ".text\n"
    ".globl thunk4d3a20\n"
    "thunk4d3a20:\n"
    "  pushl $0\n"
    "  leal 12(%esp), %eax\n"
    "  pushl %eax\n"
    "  pushl $2\n"
    "  pushl 16(%esp)\n"
    "  call ext_4d24e0\n"
    "  ret $8\n"
    ".globl thunk57c1d0\n"
    "thunk57c1d0:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  movl 8(%esp), %ecx\n"
    "  call ext_4e5e60\n"
    "  movl %eax, 0x180(%esi)\n"
    "  popl %esi\n"
    "  ret $4\n"
    ".globl thunk5d9180\n"
    "thunk5d9180:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  movl 8(%esp), %ecx\n"
    "  call ext_4e5e60\n"
    "  movl %eax, 0x54(%esi)\n"
    "  popl %esi\n"
    "  ret $4\n"
    ".globl thunk42ab49\n"
    "thunk42ab49:\n"
    "  leal 12(%esp), %eax\n"
    "  pushl %eax\n"
    "  pushl $0\n"
    "  pushl 16(%esp)\n"
    "  pushl 16(%esp)\n"
    "  call ext_42ab26\n"
    "  addl $0x10, %esp\n"
    "  ret\n"
    ".globl thunk497450\n"
    "thunk497450:\n"
    "  pushl 4(%esp)\n"
    "  call ext_4973b0\n"
    "  testl %eax, %eax\n"
    "  jne 1f\n"
    "  ret $4\n"
    "1:\n"
    "  movl 0x54(%eax), %eax\n"
    "  ret $4\n"
    ".globl thunk4d3b10\n"
    "thunk4d3b10:\n"
    "  pushl $0\n"
    "  leal 12(%esp), %eax\n"
    "  pushl %eax\n"
    "  pushl 20(%esp)\n"
    "  pushl $8\n"
    "  pushl 20(%esp)\n"
    "  call ext_4d2700\n"
    "  ret $0xc\n"
    ".globl thunk533d20\n"
    "thunk533d20:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  movl $0, (%esi)\n"
    "  movl $0, 4(%esi)\n"
    "  movl $0, 8(%esi)\n"
    "  movl $0, 0x1010(%esi)\n"
    "  movl $0, 0x100c(%esi)\n"
    "  call ext_534190\n"
    "  movl %esi, %eax\n"
    "  popl %esi\n"
    "  ret\n"
    ".globl thunk480620\n"
    "thunk480620:\n"
    "  pushl %esi\n"
    "  pushl 8(%esp)\n"
    "  movl %ecx, %esi\n"
    "  call ext_45f3c0\n"
    "  movl %esi, %ecx\n"
    "  call ext_4805a0\n"
    "  movb $1, %al\n"
    "  popl %esi\n"
    "  ret $4\n"
    ".globl thunk4d3d90\n"
    "thunk4d3d90:\n"
    "  movl 12(%esp), %eax\n"
    "  shll $2, %eax\n"
    "  pushl %eax\n"
    "  pushl 12(%esp)\n"
    "  pushl 24(%esp)\n"
    "  pushl $8\n"
    "  pushl 20(%esp)\n"
    "  call ext_4d2700\n"
    "  ret $0x10\n"
    ".globl thunk628eb0\n"
    "thunk628eb0:\n"
    "  pushl 16(%esp)\n"
    "  pushl 16(%esp)\n"
    "  pushl 16(%esp)\n"
    "  pushl $0\n"
    "  pushl 20(%esp)\n"
    "  pushl $0x6f4424\n"
    "  call ext_628c80\n"
    "  addl $0x18, %esp\n"
    "  ret\n"
    ".globl thunk536c40\n"
    "thunk536c40:\n"
    "  movl 4(%esp), %ecx\n"
    "  testl %ecx, %ecx\n"
    "  jne 1f\n"
    "  movl 0x70039c, %eax\n"
    "  movl 0x9b(%eax), %eax\n"
    "  movl 0xadc(%eax), %eax\n"
    "  ret $4\n"
    "1:\n"
    "  call ext_445c50\n"
    "  ret $4\n");

extern "C" void thunk4d3a20(void);
extern "C" void thunk57c1d0(void);
extern "C" void thunk5d9180(void);
extern "C" void thunk42ab49(void);
extern "C" void thunk497450(void);
extern "C" void thunk4d3b10(void);
extern "C" void thunk533d20(void);
extern "C" void thunk480620(void);
extern "C" void thunk4d3d90(void);
extern "C" void thunk628eb0(void);
extern "C" void thunk536c40(void);
PCREG(4d3a20, thunk4d3a20);
PCREG(57c1d0, thunk57c1d0);
PCREG(5d9180, thunk5d9180);
PCREG(42ab49, thunk42ab49);
PCREG(497450, thunk497450);
PCREG(4d3b10, thunk4d3b10);
PCREG(533d20, thunk533d20);
PCREG(480620, thunk480620);
PCREG(4d3d90, thunk4d3d90);
PCREG(628eb0, thunk628eb0);
PCREG(536c40, thunk536c40);
