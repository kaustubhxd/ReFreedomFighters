// batch1696.cpp - 0x4721e0 (GUESS, residue 13 gap band, 2026-10-12). The factory template of batch 1673 with tag 0x412 and the
// ZLNKWHANDS constructor 0x471b50 (thiscall, three stack arguments, ret 0xc; hooked). b ? 0x45c4f0(0x412, b) : 0x45c4b0(0x412)
// (cdecl, hooked); a non-null result gets (a, this, dv) through the constructor and returns the constructor's eax; else 0.
// SEH frame not reproduced; wrapper as batch 1673.
#include "ff.h"

extern "C" char ext_45c4f0[], ext_45c4b0[], ext_471b50[];
typedef u32(*AllocFn2)(u32 a, u32 b);
typedef u32(*AllocFn1)(u32 a);
typedef u32(THISCALL *Ctor3)(void *self, u32 a, u32 b, u32 c);

extern "C" u32 factorySelf24 = 0;
extern "C" u32 factoryFin24 = 0;

extern "C" u32 factoryCore24(void *self, u32 a, u32 b, u32 dv) {
  u32 p = b ? ((AllocFn2)(void *)ext_45c4f0)(0x412u, b) : ((AllocFn1)(void *)ext_45c4b0)(0x412u);
  if (!p) return 0;
  return ((Ctor3)(void *)ext_471b50)((void *)p, a, (u32)self, dv);
}

__asm__(
    ".globl factoryWrapper24\n"
    "factoryWrapper24:\n"
    "  movl %ecx, factorySelf24\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %ecx\n"
    "  xorl %eax, %ecx\n"
    "  movl %ecx, factoryFin24\n"
    "  pushl %edx\n"
    "  pushl 12(%esp)\n"
    "  pushl 12(%esp)\n"
    "  pushl factorySelf24\n"
    "  call factoryCore24\n"
    "  addl $16, %esp\n"
    "  movl factoryFin24, %ecx\n"
    "  ret $8\n");
extern "C" void factoryWrapper24();
PCREG(4721e0, factoryWrapper24);
