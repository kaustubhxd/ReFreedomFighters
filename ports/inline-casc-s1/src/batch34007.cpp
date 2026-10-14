// batch34007.cpp - cascade escalation batch 34007: 0x536260, thiscall: this = [this+0x52fa]; when non-null tail-jump to 0x53b100, else ret.
// Assembly, so the entry stack is untouched at the jump.
#include "ff.h"

extern "C" void thunk536260(void);

asm(
    ".text\n"
    ".globl thunk536260\n"
    "thunk536260:\n"
    "  movl 0x52fa(%ecx), %ecx\n"
    "  testl %ecx, %ecx\n"
    "  jne ext_53b100\n"
    "  ret\n");
PCREG(536260, thunk536260);
