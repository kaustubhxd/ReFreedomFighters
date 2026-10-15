// batch1678.cpp - 0x46b0c0 (GUESS, residue 13 gap band, 2026-10-12). The factory template of batch 1673 with tag 0x12b and
// the constructor 0x46a020 (ZItemTemplateWeapon::ZItemTemplateWeapon, thiscall, three stack arguments, ret 0xc; hooked).
// b ? 0x45c4f0(0x12b, b) : 0x45c4b0(0x12b) (cdecl, hooked); a non-null result gets (a, this, dv) through the constructor
// and returns its eax; else 0. SEH frame not reproduced; the wrapper is batch 1673's.
#include "ff.h"

extern "C" char ext_45c4f0[], ext_45c4b0[], ext_46a020[];
typedef u32(*AllocFn2)(u32 a, u32 b);
typedef u32(*AllocFn1)(u32 a);
typedef u32(THISCALL *Ctor3)(void *self, u32 a, u32 b, u32 c);

extern "C" u32 factorySelf12 = 0;
extern "C" u32 factoryFin12 = 0;

extern "C" u32 factoryCore12(void *self, u32 a, u32 b, u32 dv) {
  u32 p = b ? ((AllocFn2)(void *)ext_45c4f0)(0x12bu, b) : ((AllocFn1)(void *)ext_45c4b0)(0x12bu);
  if (!p) return 0;
  return ((Ctor3)(void *)ext_46a020)((void *)p, a, (u32)self, dv);
}

__asm__(
    ".globl factoryWrapper12\n"
    "factoryWrapper12:\n"
    "  movl %ecx, factorySelf12\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %ecx\n"
    "  xorl %eax, %ecx\n"
    "  movl %ecx, factoryFin12\n"
    "  pushl %edx\n"
    "  pushl 12(%esp)\n"
    "  pushl 12(%esp)\n"
    "  pushl factorySelf12\n"
    "  call factoryCore12\n"
    "  addl $16, %esp\n"
    "  movl factoryFin12, %ecx\n"
    "  ret $8\n");
extern "C" void factoryWrapper12();
PCREG(46b0c0, factoryWrapper12);
