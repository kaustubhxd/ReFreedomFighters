// batch31071.cpp - Sonnet h1: tier B call-through thunks (asm, stack exact): getters, constructors/destructors with optional delete.
#include "ff.h"

extern "C" void ext_42acb5(void);
extern "C" void ext_4ccf60(void);
extern "C" void ext_4e5e40(void);
extern "C" void ext_4e5ea0(void);
extern "C" void ext_5003d0(void);
extern "C" void ext_52d080(void);
extern "C" void ext_5cfb10(void);
extern "C" void ext_5cfd90(void);
extern "C" void ext_62ef10(void);
extern "C" void ext_634273(void);
extern "C" void ext_634d82(void);

asm(
    ".text\n"
    ".globl thunk5c7c80\n"
    "thunk5c7c80:\n"
    "  pushl %edi\n"
    "  movl %ecx, %edi\n"
    "  movl 12(%esp), %ecx\n"
    "  call ext_4e5ea0\n"
    "  movl 12(%esp), %ecx\n"
    "  movl %eax, 0x48(%edi)\n"
    "  call ext_4e5e40\n"
    "  movw %ax, 0x4c(%edi)\n"
    "  popl %edi\n"
    "  ret $8\n"
    ".globl thunk62f120\n"
    "thunk62f120:\n"
    "  pushl 16(%esp)\n"
    "  pushl 16(%esp)\n"
    "  pushl $0\n"
    "  pushl $8\n"
    "  pushl $0xf\n"
    "  pushl $8\n"
    "  pushl 32(%esp)\n"
    "  pushl 32(%esp)\n"
    "  call ext_62ef10\n"
    "  ret $0x10\n"
    ".globl thunk42ac71\n"
    "thunk42ac71:\n"
    "  pushl 16(%esp)\n"
    "  pushl 16(%esp)\n"
    "  pushl 16(%esp)\n"
    "  pushl $-1\n"
    "  pushl 20(%esp)\n"
    "  call ext_42acb5\n"
    "  pushl 4(%eax)\n"
    "  pushl (%eax)\n"
    "  call ext_634d82\n"
    "  addl $0x1c, %esp\n"
    "  ret\n"
    ".globl thunk51ec40\n"
    "thunk51ec40:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  movl 8(%esp), %ecx\n"
    "  pushl $0\n"
    "  movl 4(%ecx), %ecx\n"
    "  call ext_5003d0\n"
    "  movl 0x18(%esi), %ecx\n"
    "  movl (%eax), %eax\n"
    "  movl %eax, 0x34a(%ecx)\n"
    "  popl %esi\n"
    "  ret $4\n"
    ".globl thunk5cfae0\n"
    "thunk5cfae0:\n"
    "  pushl %esi\n"
    "  pushl 8(%esp)\n"
    "  movl %ecx, %esi\n"
    "  call ext_5cfd90\n"
    "  testb %al, %al\n"
    "  jne 1f\n"
    "  pushl 8(%esp)\n"
    "  movl %esi, %ecx\n"
    "  call ext_5cfb10\n"
    "1:\n"
    "  popl %esi\n"
    "  ret $4\n"
    ".globl thunk485f00\n"
    "thunk485f00:\n"
    "  testb $1, 4(%esp)\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  movl $0x685294, (%esi)\n"
    "  je 1f\n"
    "  pushl $0x1c\n"
    "  pushl %esi\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "1:\n"
    "  movl %esi, %eax\n"
    "  popl %esi\n"
    "  ret $4\n"
    ".globl thunk4cd2d0\n"
    "thunk4cd2d0:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  call ext_4ccf60\n"
    "  testb $1, 8(%esp)\n"
    "  je 1f\n"
    "  pushl $0xac\n"
    "  pushl %esi\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "1:\n"
    "  movl %esi, %eax\n"
    "  popl %esi\n"
    "  ret $4\n"
    ".globl thunk52d190\n"
    "thunk52d190:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  call ext_52d080\n"
    "  testb $1, 8(%esp)\n"
    "  je 1f\n"
    "  pushl $0xd1e\n"
    "  pushl %esi\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "1:\n"
    "  movl %esi, %eax\n"
    "  popl %esi\n"
    "  ret $4\n");

extern "C" void thunk5c7c80(void);
extern "C" void thunk62f120(void);
extern "C" void thunk42ac71(void);
extern "C" void thunk51ec40(void);
extern "C" void thunk5cfae0(void);
extern "C" void thunk485f00(void);
extern "C" void thunk4cd2d0(void);
extern "C" void thunk52d190(void);
PCREG(5c7c80, thunk5c7c80);
PCREG(62f120, thunk62f120);
PCREG(42ac71, thunk42ac71);
PCREG(51ec40, thunk51ec40);
PCREG(5cfae0, thunk5cfae0);
PCREG(485f00, thunk485f00);
PCREG(4cd2d0, thunk4cd2d0);
PCREG(52d190, thunk52d190);
