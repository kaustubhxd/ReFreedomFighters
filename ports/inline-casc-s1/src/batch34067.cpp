// batch34067.cpp - escalation: 0x61bc70 tail forwarder (ecx = [esp+4] argument object, jump through its vtable slot 0x18, stack untouched).
#include "ff.h"

extern "C" void thunk61bc70(void);
asm(
    ".text\n"
    ".globl thunk61bc70\n"
    "thunk61bc70:\n"
    "  push %ebp\n"
    "  mov %esp, %ebp\n"
    "  mov 8(%ebp), %ecx\n"
    "  mov (%ecx), %eax\n"
    "  pop %ebp\n"
    "  jmp *0x18(%eax)\n");
PCREG(61bc70, thunk61bc70);
