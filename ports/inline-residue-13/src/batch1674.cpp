// batch1674.cpp - 0x46ae40 (GUESS, residue 13 gap band, 2026-10-12). The factory of batch 1673 with tag 0x98 and the
// constructor 0x469b40 (thiscall, three stack arguments, ret 0xc): b ? 0x45c4f0(0x98, b) : 0x45c4b0(0x98) (both cdecl,
// hooked); a non-null result gets (a, this, dv) via the constructor and returns its eax; else returns 0. SEH frame not
// reproduced; the wrapper is the same as batch 1673's (ecx = [0x6f5630] ^ (entry esp - 4)).
#include "ff.h"

extern "C" char ext_45c4f0[], ext_45c4b0[], ext_469b40[];
typedef u32(*AllocFn2)(u32 a, u32 b);
typedef u32(*AllocFn1)(u32 a);
typedef u32(THISCALL *Ctor3)(void *self, u32 a, u32 b, u32 c);

extern "C" u32 factorySelfSave2 = 0;
extern "C" u32 factoryFinEcx2 = 0;

extern "C" u32 factoryCore7(void *self, u32 a, u32 b, u32 dv) {
  u32 p = b ? ((AllocFn2)(void *)ext_45c4f0)(0x98u, b) : ((AllocFn1)(void *)ext_45c4b0)(0x98u);
  if (!p) return 0;
  return ((Ctor3)(void *)ext_469b40)((void *)p, a, (u32)self, dv);
}

__asm__(
    ".globl factoryWrapper7\n"
    "factoryWrapper7:\n"
    "  movl %ecx, factorySelfSave2\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %ecx\n"
    "  xorl %eax, %ecx\n"
    "  movl %ecx, factoryFinEcx2\n"
    "  pushl %edx\n"
    "  pushl 12(%esp)\n"
    "  pushl 12(%esp)\n"
    "  pushl factorySelfSave2\n"
    "  call factoryCore7\n"
    "  addl $16, %esp\n"
    "  movl factoryFinEcx2, %ecx\n"
    "  ret $8\n");
extern "C" void factoryWrapper7();
PCREG(46ae40, factoryWrapper7);
