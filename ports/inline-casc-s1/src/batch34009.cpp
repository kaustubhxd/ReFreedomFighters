// batch34009.cpp - cascade escalation batch 34009: member vtable forwarders (some null-checked) and a pointer-chain tail jump, in assembly
// so the entry stack is untouched at the jump.
#include "ff.h"

extern "C" void thunk4f3230(void);
extern "C" void thunk5f2e90(void);
extern "C" void thunk64f850(void);
extern "C" void thunk4dbbd0(void);
extern "C" void thunk64fae0(void);
extern "C" void thunk5f1bc0(void);

asm(
    ".text\n"
    ".globl thunk4f3230\n"
    "thunk4f3230:\n"          // this = [this+0x6f]; slot 0x21c
    "  movl 0x6f(%ecx), %ecx\n"
    "  movl (%ecx), %eax\n"
    "  jmp *0x21c(%eax)\n"
    ".globl thunk5f2e90\n"
    "thunk5f2e90:\n"          // this = [this+0x15]; slot 0x50
    "  movl 0x15(%ecx), %ecx\n"
    "  movl (%ecx), %eax\n"
    "  jmp *0x50(%eax)\n"
    ".globl thunk64f850\n"
    "thunk64f850:\n"          // this = [this+0xbd]; slot 0x4c
    "  movl 0xbd(%ecx), %ecx\n"
    "  movl (%ecx), %eax\n"
    "  jmp *0x4c(%eax)\n"
    ".globl thunk4dbbd0\n"
    "thunk4dbbd0:\n"          // this = [this+0x54]; when non-null, slot 0x1c
    "  movl 0x54(%ecx), %ecx\n"
    "  testl %ecx, %ecx\n"
    "  je 1f\n"
    "  movl (%ecx), %eax\n"
    "  jmp *0x1c(%eax)\n"
    "1:\n"
    "  ret\n"
    ".globl thunk64fae0\n"
    "thunk64fae0:\n"          // this = [this+0xbd]; when non-null, slot 0xc
    "  movl 0xbd(%ecx), %ecx\n"
    "  testl %ecx, %ecx\n"
    "  je 1f\n"
    "  movl (%ecx), %eax\n"
    "  jmp *0xc(%eax)\n"
    "1:\n"
    "  ret\n"
    ".globl thunk5f1bc0\n"
    "thunk5f1bc0:\n"          // this = [[this+0xc]+4]; tail-jump to 0x5fbac0
    "  movl 0xc(%ecx), %ecx\n"
    "  movl 4(%ecx), %ecx\n"
    "  jmp ext_5fbac0\n");
PCREG(4f3230, thunk4f3230);
PCREG(5f2e90, thunk5f2e90);
PCREG(64f850, thunk64f850);
PCREG(4dbbd0, thunk4dbbd0);
PCREG(64fae0, thunk64fae0);
PCREG(5f1bc0, thunk5f1bc0);
