// batch1039.cpp - area 81, batch 1039: 0x64ff00, thiscall (this), no stack arguments. Thunk: ecx = [this+0xbd], then tail-jumps to the vtable slot
// 0x64 of that object (the object's own method). Module-level asm keeps it exact; the slot is a GUESS stub in the spec.
#include "ff.h"

extern "C" void asm_64ff00(void);

__asm__(
    ".text\n"
    ".globl asm_64ff00\n"
    "asm_64ff00:\n"
    "  movl 0xbd(%ecx), %ecx\n"
    "  movl (%ecx), %eax\n"
    "  jmp *0x64(%eax)\n");
PCREG(64ff00, asm_64ff00);
