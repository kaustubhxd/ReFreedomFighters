// batch31069.cpp - call-through thunks (asm, stack exact), tier B.
#include "ff.h"

extern "C" void ext_41e290(void);
extern "C" void ext_42abee(void);
extern "C" void ext_4419f0(void);
extern "C" void ext_4d96d0(void);
extern "C" void ext_4da1d0(void);
extern "C" void ext_4dc630(void);
extern "C" void ext_4e5e60(void);
extern "C" void ext_4e6330(void);
extern "C" void ext_5328b0(void);
extern "C" void ext_545c80(void);
extern "C" void ext_562440(void);
extern "C" void ext_57f420(void);
extern "C" void ext_5fa630(void);
extern "C" void ext_608330(void);
extern "C" void ext_60d610(void);
extern "C" void ext_610100(void);

asm(
    ".text\n"
    ".globl thunk57f400\n"
    "thunk57f400:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  call ext_562440\n"
    "  movl %esi, %ecx\n"
    "  popl %esi\n"
    "  jmp ext_57f420\n"
    ".globl thunk60ed60\n"
    "thunk60ed60:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  call ext_60d610\n"
    "  movl %esi, %ecx\n"
    "  popl %esi\n"
    "  jmp ext_608330\n"
    ".globl thunk4dd8f0\n"
    "thunk4dd8f0:\n"
    "  movl %ecx, %edx\n"
    "  movl 4(%esp), %ecx\n"
    "  call ext_4419f0\n"
    "  ret $4\n"
    ".globl thunk5f40a0\n"
    "thunk5f40a0:\n"
    "  call ext_5fa630\n"
    "  movl (%eax), %edx\n"
    "  movl %eax, %ecx\n"
    "  jmp *0x44(%edx)\n"
    ".globl thunk4c59f0\n"
    "thunk4c59f0:\n"
    "  leal 0x48(%ecx), %eax\n"
    "  movl 4(%esp), %ecx\n"
    "  pushl %eax\n"
    "  call ext_4e6330\n"
    "  ret $4\n"
    ".globl thunk569410\n"
    "thunk569410:\n"
    "  pushl 4(%esp)\n"
    "  call ext_610100\n"
    "  movl 4(%esp), %ecx\n"
    "  call ext_4e5e60\n"
    "  ret $4\n"
    ".globl thunk642120\n"
    "thunk642120:\n"
    "  pushl 4(%esp)\n"
    "  movl 0x17f(%ecx), %ecx\n"
    "  pushl 12(%esp)\n"
    "  call ext_545c80\n"
    "  ret $8\n"
    ".globl thunk45f3a0\n"
    "thunk45f3a0:\n"
    "  movl 8(%ecx), %ecx\n"
    "  testl $0x40040000, 0x3c(%ecx)\n"
    "  je 1f\n"
    "  cmpl $0, 0x68(%ecx)\n"
    "  je 1f\n"
    "  pushl $0\n"
    "  pushl $0x2000000\n"
    "  call ext_4dc630\n"
    "1:\n"
    "  ret\n"
    ".globl thunk4dae40\n"
    "thunk4dae40:\n"
    "  pushl %esi\n"
    "  pushl $0\n"
    "  movl %ecx, %esi\n"
    "  call ext_4da1d0\n"
    "  pushl $0\n"
    "  movl %esi, %ecx\n"
    "  call ext_4d96d0\n"
    "  popl %esi\n"
    "  ret\n"
    ".globl thunk533cc0\n"
    "thunk533cc0:\n"
    "  pushl $0x548e\n"
    "  call ext_41e290\n"
    "  addl $4, %esp\n"
    "  testl %eax, %eax\n"
    "  je 1f\n"
    "  movl %eax, %ecx\n"
    "  jmp ext_5328b0\n"
    "1:\n"
    "  xorl %eax, %eax\n"
    "  ret\n"
    ".globl thunk42f880\n"
    "thunk42f880:\n"
    "  leal 16(%esp), %eax\n"
    "  pushl %eax\n"
    "  pushl 16(%esp)\n"
    "  pushl 16(%esp)\n"
    "  call ext_42abee\n"
    "  addl $12, %esp\n"
    "  ret\n");

extern "C" void thunk57f400(void);
extern "C" void thunk60ed60(void);
extern "C" void thunk4dd8f0(void);
extern "C" void thunk5f40a0(void);
extern "C" void thunk4c59f0(void);
extern "C" void thunk569410(void);
extern "C" void thunk642120(void);
extern "C" void thunk45f3a0(void);
extern "C" void thunk4dae40(void);
extern "C" void thunk533cc0(void);
extern "C" void thunk42f880(void);
PCREG(57f400, thunk57f400);
PCREG(60ed60, thunk60ed60);
PCREG(4dd8f0, thunk4dd8f0);
PCREG(5f40a0, thunk5f40a0);
PCREG(4c59f0, thunk4c59f0);
PCREG(569410, thunk569410);
PCREG(642120, thunk642120);
PCREG(45f3a0, thunk45f3a0);
PCREG(4dae40, thunk4dae40);
PCREG(533cc0, thunk533cc0);
PCREG(42f880, thunk42f880);
