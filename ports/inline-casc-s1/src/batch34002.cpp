// batch34002.cpp - cascade escalation batch 34002: thiscall virtual forwarders that tail-jump to a vtable slot of a member
// (field pointer or embedded subobject). Assembly, so the entry stack is untouched at the jump.
#include "ff.h"

extern "C" void thunk436160(void);
extern "C" void thunk4675d0(void);
extern "C" void thunk474450(void);
extern "C" void thunk474680(void);

asm(
    ".text\n"
    ".globl thunk436160\n"
    "thunk436160:\n"          // this = [this+0x65]; slot 0xc
    "  movl 0x65(%ecx), %ecx\n"
    "  movl (%ecx), %eax\n"
    "  jmp *0xc(%eax)\n"
    ".globl thunk4675d0\n"
    "thunk4675d0:\n"          // this = [this+0x1ce]; slot 0x10
    "  movl 0x1ce(%ecx), %ecx\n"
    "  movl (%ecx), %eax\n"
    "  jmp *0x10(%eax)\n"
    ".globl thunk474450\n"
    "thunk474450:\n"          // this += 0x2e7; slot 0x10
    "  addl $0x2e7, %ecx\n"
    "  movl (%ecx), %eax\n"
    "  jmp *0x10(%eax)\n"
    ".globl thunk474680\n"
    "thunk474680:\n"          // this += 0x34f; slot 0x14
    "  addl $0x34f, %ecx\n"
    "  movl (%ecx), %eax\n"
    "  jmp *0x14(%eax)\n");
PCREG(436160, thunk436160);
PCREG(4675d0, thunk4675d0);
PCREG(474450, thunk474450);
PCREG(474680, thunk474680);
