// batch34005.cpp - cascade escalation batch 34005: thiscall tail jumps in assembly (entry stack untouched at the jump).
#include "ff.h"

extern "C" void thunk4cbe40(void);
extern "C" void thunk45faf0(void);
extern "C" void thunk463930(void);

asm(
    ".text\n"
    ".globl thunk4cbe40\n"
    "thunk4cbe40:\n"          // ecx = [this+0x18]; jump to the code pointer at [this+0x2f]
    "  movl %ecx, %eax\n"
    "  movl 0x18(%eax), %ecx\n"
    "  movl 0x2f(%eax), %eax\n"
    "  jmp *%eax\n"
    ".globl thunk45faf0\n"
    "thunk45faf0:\n"          // slot 0x128 of this's vtable (empty ebp frame)
    "  movl (%ecx), %eax\n"
    "  jmp *0x128(%eax)\n"
    ".globl thunk463930\n"
    "thunk463930:\n"          // slot 0x7c of this's vtable (empty ebp frame)
    "  movl (%ecx), %eax\n"
    "  jmp *0x7c(%eax)\n");
PCREG(4cbe40, thunk4cbe40);
PCREG(45faf0, thunk45faf0);
PCREG(463930, thunk463930);
