// batch1694.cpp - 0x4657b0 (GUESS, residue 13 gap band, 2026-10-12). The factory template of batch 1673 with tag 0x1d2 and the
// ZIKLNKOBJ constructor 0x4654b0 (thiscall, three stack arguments, ret 0xc; hooked). b ? 0x45c4f0(0x1d2, b) : 0x45c4b0(0x1d2)
// (cdecl, hooked); a non-null result gets (a, this, dv) through the constructor and returns the constructor's eax; else 0.
// SEH frame not reproduced; wrapper as batch 1673.
#include "ff.h"

extern "C" char ext_45c4f0[], ext_45c4b0[], ext_4654b0[];
typedef u32(*AllocFn2)(u32 a, u32 b);
typedef u32(*AllocFn1)(u32 a);
typedef u32(THISCALL *Ctor3)(void *self, u32 a, u32 b, u32 c);

extern "C" u32 factorySelf22 = 0;
extern "C" u32 factoryFin22 = 0;

extern "C" u32 factoryCore22(void *self, u32 a, u32 b, u32 dv) {
  u32 p = b ? ((AllocFn2)(void *)ext_45c4f0)(0x1d2u, b) : ((AllocFn1)(void *)ext_45c4b0)(0x1d2u);
  if (!p) return 0;
  return ((Ctor3)(void *)ext_4654b0)((void *)p, a, (u32)self, dv);
}

__asm__(
    ".globl factoryWrapper22\n"
    "factoryWrapper22:\n"
    "  movl %ecx, factorySelf22\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %ecx\n"
    "  xorl %eax, %ecx\n"
    "  movl %ecx, factoryFin22\n"
    "  pushl %edx\n"
    "  pushl 12(%esp)\n"
    "  pushl 12(%esp)\n"
    "  pushl factorySelf22\n"
    "  call factoryCore22\n"
    "  addl $16, %esp\n"
    "  movl factoryFin22, %ecx\n"
    "  ret $8\n");
extern "C" void factoryWrapper22();
PCREG(4657b0, factoryWrapper22);
