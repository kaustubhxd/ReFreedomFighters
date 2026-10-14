// batch34006.cpp - cascade escalation batch 34006: a conditional vtable tail jump (assembly) and three thiscall setters (ret 4).
#include "ff.h"

extern "C" void thunk47fb90(void);

asm(
    ".text\n"
    ".globl thunk47fb90\n"
    "thunk47fb90:\n"          // when [this+4] != 0, tail-jump to slot 0x14 of this's vtable; else plain ret
    "  cmpl $0, 4(%ecx)\n"
    "  je 1f\n"
    "  movl (%ecx), %eax\n"
    "  jmp *0x14(%eax)\n"
    "1:\n"
    "  ret\n");
PCREG(47fb90, thunk47fb90);

// thiscall(v) ret 4 setters.
static void THISCALL fn446780(u8 *self, u32 v) { *(u32 *)(self + 0x6c) = v; }
PCREG(446780, fn446780);
static void THISCALL fn4682d0(u8 *self, u32 v) { *(u32 *)(self + 0x1d6) = v; }
PCREG(4682d0, fn4682d0);
static void THISCALL fn470c80(u8 *self, u32 v) { *(u32 *)(self + 0x64) = v; }
PCREG(470c80, fn470c80);
