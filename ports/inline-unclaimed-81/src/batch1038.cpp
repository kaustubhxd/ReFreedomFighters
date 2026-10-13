// batch1038.cpp - area 81, batch 1038: 0x4527c0, thiscall (this), no stack arguments. Thunk: stores the vtable word 0x6815d8 at this+0,
// then tail-jumps to 0x45c3e0 (real exe code, ext_45c3e0). Module-level asm keeps the store and the jump exact; no stand-ins.
#include "ff.h"

extern "C" void ext_45c3e0(void);   // real exe code (the tail target)
extern "C" void asm_4527c0(void);

__asm__(
    ".text\n"
    ".globl asm_4527c0\n"
    "asm_4527c0:\n"
    "  movl $0x6815d8, (%ecx)\n"
    "  jmp ext_45c3e0\n");
PCREG(4527c0, asm_4527c0);
