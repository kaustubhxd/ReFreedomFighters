// batch817.cpp - core gameplay batch 817 (docs/20-unclaimed-65.md, batch 817), three residue-01 entries (core-todo/residue-01.txt):
// 0x438790 (no args): decrements the dword at this+0x120c. 0x4fdd10 (no args): sets the byte at this+0x69 to 1.
// 0x51cad0 (no args): tail-jumps through slot 0x360 of the object's vtable (ecx = this kept, nothing popped), so it is assembly.
#include "ff.h"

extern "C" void fn51cad0(void);

static void THISCALL fn438790(u8 *self) { (*(u32 *)(self + 0x120c))--; }

static void THISCALL fn4fdd10(u8 *self) { *(u8 *)(self + 0x69) = 1; }

asm(
    ".text\n"
    ".globl fn51cad0\n"
    "fn51cad0:\n"
    "  movl (%ecx), %eax\n"
    "  jmp *0x360(%eax)\n");

PCREG(438790, fn438790);
PCREG(4fdd10, fn4fdd10);
PCREG(51cad0, fn51cad0);
