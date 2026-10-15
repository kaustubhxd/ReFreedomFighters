// batch1676.cpp - 0x46b160 (GUESS, residue 13 gap band, 2026-10-12). The factory template of batch 1673 with tag 0x115 and
// the constructor 0x46a290 (thiscall, three stack arguments, ret 0xc; itself a 607-byte constructor, not ported here, hooked
// by address in the checker). b ? 0x45c4f0(0x115, b) : 0x45c4b0(0x115) (cdecl, hooked); a non-null result gets
// (a, this, dv) through 0x46a290 and returns its eax; else 0. SEH frame not reproduced; the wrapper as batch 1673.
#include "ff.h"

extern "C" char ext_45c4f0[], ext_45c4b0[], ext_46a290[];
typedef u32(*AllocFn2)(u32 a, u32 b);
typedef u32(*AllocFn1)(u32 a);
typedef u32(THISCALL *Ctor3)(void *self, u32 a, u32 b, u32 c);

extern "C" u32 factorySelf11 = 0;
extern "C" u32 factoryFin11 = 0;

extern "C" u32 factoryCore11(void *self, u32 a, u32 b, u32 dv) {
  u32 p = b ? ((AllocFn2)(void *)ext_45c4f0)(0x115u, b) : ((AllocFn1)(void *)ext_45c4b0)(0x115u);
  if (!p) return 0;
  return ((Ctor3)(void *)ext_46a290)((void *)p, a, (u32)self, dv);
}

__asm__(
    ".globl factoryWrapper11\n"
    "factoryWrapper11:\n"
    "  movl %ecx, factorySelf11\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %ecx\n"
    "  xorl %eax, %ecx\n"
    "  movl %ecx, factoryFin11\n"
    "  pushl %edx\n"
    "  pushl 12(%esp)\n"
    "  pushl 12(%esp)\n"
    "  pushl factorySelf11\n"
    "  call factoryCore11\n"
    "  addl $16, %esp\n"
    "  movl factoryFin11, %ecx\n"
    "  ret $8\n");
extern "C" void factoryWrapper11();
PCREG(46b160, factoryWrapper11);
