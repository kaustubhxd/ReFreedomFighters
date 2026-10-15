// batch1690.cpp - 0x461610 (GUESS, residue 13 gap band, 2026-10-12). The factory template of batch 1673 with tag 0x136 and
// the constructor ZLNKOBJ::ZLNKOBJ (0x460e40, thiscall, three stack arguments, ret 0xc; hooked). b ? 0x45c4f0(0x136, b) :
// 0x45c4b0(0x136) (cdecl, hooked); a non-null result gets (a, this, dv) through the constructor and the function returns the
// constructor's eax (nothing in between changes eax); else 0. SEH frame not reproduced; wrapper as batch 1673.
#include "ff.h"

extern "C" char ext_45c4f0[], ext_45c4b0[], ext_460e40[];
typedef u32(*AllocFn2)(u32 a, u32 b);
typedef u32(*AllocFn1)(u32 a);
typedef u32(THISCALL *Ctor3)(void *self, u32 a, u32 b, u32 c);

extern "C" u32 factorySelf20 = 0;
extern "C" u32 factoryFin20 = 0;

extern "C" u32 factoryCore20(void *self, u32 a, u32 b, u32 dv) {
  u32 p = b ? ((AllocFn2)(void *)ext_45c4f0)(0x136u, b) : ((AllocFn1)(void *)ext_45c4b0)(0x136u);
  if (!p) return 0;
  return ((Ctor3)(void *)ext_460e40)((void *)p, a, (u32)self, dv);
}

__asm__(
    ".globl factoryWrapper20\n"
    "factoryWrapper20:\n"
    "  movl %ecx, factorySelf20\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %ecx\n"
    "  xorl %eax, %ecx\n"
    "  movl %ecx, factoryFin20\n"
    "  pushl %edx\n"
    "  pushl 12(%esp)\n"
    "  pushl 12(%esp)\n"
    "  pushl factorySelf20\n"
    "  call factoryCore20\n"
    "  addl $16, %esp\n"
    "  movl factoryFin20, %ecx\n"
    "  ret $8\n");
extern "C" void factoryWrapper20();
PCREG(461610, factoryWrapper20);
