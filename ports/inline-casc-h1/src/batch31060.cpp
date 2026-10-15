// batch31060.cpp - Sonnet h1: vtable/pointer-chasing tail-jump thunks. Assembly so the entry stack is untouched at the jump.
#include "ff.h"

extern "C" void ext_5fd120(void);

asm(
    ".text\n"
    ".globl thunk483de0\nthunk483de0:\n  movl (%ecx), %eax\n  jmp *0x59c(%eax)\n"
    ".globl thunk4234e0\nthunk4234e0:\n  addl $0x2191, %ecx\n  movl (%ecx), %eax\n  jmp *4(%eax)\n"
    ".globl thunk461970\nthunk461970:\n  movl (%ecx), %eax\n  jmp *0x23c(%eax)\n"
    ".globl thunk4f90b0\nthunk4f90b0:\n  movl (%ecx), %eax\n  jmp *0x374(%eax)\n"
    ".globl thunk5f23f0\nthunk5f23f0:\n  movl 0xc(%ecx), %ecx\n  movl 4(%ecx), %ecx\n  jmp ext_5fd120\n"
    ".globl thunk614ee0\nthunk614ee0:\n  movl 4(%ecx), %ecx\n  movl (%ecx), %eax\n  jmp *0xc(%eax)\n"
    ".globl thunk64fac0\nthunk64fac0:\n  movl 0xbd(%ecx), %ecx\n  movl (%ecx), %eax\n  jmp *0x2c(%eax)\n"
    ".globl thunk64fd60\nthunk64fd60:\n  movl 0xbd(%ecx), %ecx\n  movl (%ecx), %eax\n  jmp *0x48(%eax)\n");
extern "C" void thunk483de0(void);
extern "C" void thunk4234e0(void);
extern "C" void thunk461970(void);
extern "C" void thunk4f90b0(void);
extern "C" void thunk5f23f0(void);
extern "C" void thunk614ee0(void);
extern "C" void thunk64fac0(void);
extern "C" void thunk64fd60(void);
PCREG(483de0, thunk483de0);
PCREG(4234e0, thunk4234e0);
PCREG(461970, thunk461970);
PCREG(4f90b0, thunk4f90b0);
PCREG(5f23f0, thunk5f23f0);
PCREG(614ee0, thunk614ee0);
PCREG(64fac0, thunk64fac0);
PCREG(64fd60, thunk64fd60);
