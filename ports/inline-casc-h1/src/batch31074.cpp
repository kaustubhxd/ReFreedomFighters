// batch31074.cpp - tier B constructors/destructors, lookup thunks, vector push (asm, stack exact).
#include "ff.h"

extern "C" void ext_43de40(void);
extern "C" void ext_469870(void);
extern "C" void ext_5003d0(void);
extern "C" void ext_520f20(void);
extern "C" void ext_5a7530(void);
extern "C" void ext_5cc880(void);
extern "C" void ext_5ebd80(void);
extern "C" void ext_5f4630(void);
extern "C" void ext_634273(void);
extern "C" void ext_655a70(void);

asm(
    ".text\n"
    ".globl thunk656e20\n"
    "thunk656e20:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  movl $0x6c3e28, (%esi)\n"
    "  call ext_655a70\n"
    "  testb $1, 8(%esp)\n"
    "  je 1f\n"
    "  pushl $4\n"
    "  pushl %esi\n"
    "  call ext_634273\n"
    "  addl $8, %esp\n"
    "1:\n"
    "  movl %esi, %eax\n"
    "  popl %esi\n"
    "  ret $4\n"
    ".globl thunk4a7960\n"
    "thunk4a7960:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  call ext_469870\n"
    "  orl $0x20, 4(%esi)\n"
    "  movl %esi, %eax\n"
    "  movl $0, 0x44(%esi)\n"
    "  movl $0x690114, (%esi)\n"
    "  movl $0, 0x72(%esi)\n"
    "  movl $0, 0x76(%esi)\n"
    "  popl %esi\n"
    "  ret\n"
    ".globl thunk51e840\n"
    "thunk51e840:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  movl 8(%esp), %ecx\n"
    "  pushl $0\n"
    "  movl 4(%ecx), %ecx\n"
    "  call ext_5003d0\n"
    "  movl 0x18(%esi), %ecx\n"
    "  popl %esi\n"
    "  cmpl $0, (%eax)\n"
    "  movl (%ecx), %edx\n"
    "  setne %al\n"
    "  movzbl %al, %eax\n"
    "  movl %eax, 4(%esp)\n"
    "  jmp *0x39c(%edx)\n"
    ".globl thunk522820\n"
    "thunk522820:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  movl 8(%esp), %ecx\n"
    "  pushl $0\n"
    "  movl 4(%ecx), %ecx\n"
    "  call ext_5003d0\n"
    "  movl 0x1c(%esi), %ecx\n"
    "  cmpl $0, (%eax)\n"
    "  setne %al\n"
    "  movzbl %al, %eax\n"
    "  pushl %eax\n"
    "  call ext_520f20\n"
    "  popl %esi\n"
    "  ret $4\n"
    ".globl thunk5d0080\n"
    "thunk5d0080:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  pushl $0\n"
    "  movl 0xb54(%esi), %ecx\n"
    "  movl $0, 0xb1f(%esi)\n"
    "  movl $0, 0xb23(%esi)\n"
    "  movl $0, 0xb27(%esi)\n"
    "  movl $0, 0xb2b(%esi)\n"
    "  call ext_5cc880\n"
    "  movl 0xe18(%esi), %ecx\n"
    "  movl $0, 0xad5(%esi)\n"
    "  popl %esi\n"
    "  testl %ecx, %ecx\n"
    "  je 1f\n"
    "  pushl $0\n"
    "  call ext_5a7530\n"
    "1:\n"
    "  ret\n"
    ".globl thunk5f4600\n"
    "thunk5f4600:\n"
    "  movl 0x54(%ecx), %eax\n"
    "  cmpl 0x50(%ecx), %eax\n"
    "  pushl %esi\n"
    "  leal 0x4c(%ecx), %esi\n"
    "  jb 1f\n"
    "  movl %esi, %ecx\n"
    "  call ext_5f4630\n"
    "1:\n"
    "  movl 8(%esi), %edx\n"
    "  movl (%esi), %ecx\n"
    "  movl 8(%esp), %eax\n"
    "  movl %eax, (%ecx,%edx,4)\n"
    "  incl 8(%esi)\n"
    "  popl %esi\n"
    "  ret $4\n"
    ".globl thunk5a5f00\n"
    "thunk5a5f00:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  movl 0x47c(%esi), %ecx\n"
    "  cmpl $0xc, %ecx\n"
    "  je 1f\n"
    "  movl 0x440(%esi,%ecx,4), %eax\n"
    "  movb $1, 0x35(%eax)\n"
    "  movl 8(%esp), %eax\n"
    "  movl 0x440(%esi,%ecx,4), %ecx\n"
    "  movl 0x4b8(%esi,%eax,4), %eax\n"
    "  pushl (%eax)\n"
    "  call ext_5ebd80\n"
    "  incl 0x47c(%esi)\n"
    "1:\n"
    "  popl %esi\n"
    "  ret $4\n"
    ".globl thunk5d8840\n"
    "thunk5d8840:\n"
    "  pushl %esi\n"
    "  pushl 16(%esp)\n"
    "  movl %ecx, %esi\n"
    "  pushl 16(%esp)\n"
    "  pushl 16(%esp)\n"
    "  call ext_43de40\n"
    "  movl $0x6b5fc8, (%esi)\n"
    "  movl %esi, %eax\n"
    "  movl $0, 0x20(%esi)\n"
    "  movl $0, 0x44(%esi)\n"
    "  popl %esi\n"
    "  ret $0xc\n");

extern "C" void thunk656e20(void);
extern "C" void thunk4a7960(void);
extern "C" void thunk51e840(void);
extern "C" void thunk522820(void);
extern "C" void thunk5d0080(void);
extern "C" void thunk5f4600(void);
extern "C" void thunk5a5f00(void);
extern "C" void thunk5d8840(void);
PCREG(656e20, thunk656e20);
PCREG(4a7960, thunk4a7960);
PCREG(51e840, thunk51e840);
PCREG(522820, thunk522820);
PCREG(5d0080, thunk5d0080);
PCREG(5f4600, thunk5f4600);
PCREG(5a5f00, thunk5a5f00);
PCREG(5d8840, thunk5d8840);
