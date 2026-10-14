// batch34066.cpp - cascade escalation batch 34066 (queue items 0x466630, 0x54dce0, 0x474700): vtable tail jumps in assembly (the entry stack is untouched at the jump).
#include "ff.h"

extern "C" void thunk466630(void);
extern "C" void thunk54dce0(void);
extern "C" void thunk474700(void);

asm(
    ".text\n"
    ".globl thunk466630\n"
    "thunk466630:\n"          // tail-jump to slot 0x21c of this's vtable
    "  movl (%ecx), %eax\n"
    "  jmp *0x21c(%eax)\n"
    ".globl thunk54dce0\n"
    "thunk54dce0:\n"          // byte [0x713e19] = 0; [this+4] = 0; tail-jump to slot 0x18
    "  movb $0, 0x713e19\n"
    "  movl (%ecx), %eax\n"
    "  movl $0, 4(%ecx)\n"
    "  jmp *0x18(%eax)\n"
    ".globl thunk474700\n"
    "thunk474700:\n"          // tail-jump to slot 0x4f4 of this's vtable
    "  movl (%ecx), %eax\n"
    "  jmp *0x4f4(%eax)\n");
PCREG(466630, thunk466630);
PCREG(54dce0, thunk54dce0);
PCREG(474700, thunk474700);
