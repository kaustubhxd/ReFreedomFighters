// batch1673.cpp - 0x46ac40 (GUESS, residue 13 gap band, 2026-10-12). A factory: thiscall with two stack arguments (a at
// [ebp+8], b at [ebp+0xc]; ret 8) and the entry edx (dv) kept in esi. When b is non-zero it allocates with 0x45c4f0(0x8e, b)
// (cdecl, hooked); otherwise 0x45c4b0(0x8e) (cdecl, hooked). When the allocation is non-null it runs ZItem::ZItem (0x469980,
// hooked; thiscall, three stack arguments, ret 0xc) as (a, this, dv) on it and returns its eax; else returns 0.
// SEH frame (fs:[0], frame 0x66c831) is not reproduced. The exe's epilogue leaves ecx = [0x6f5630] ^ (entry esp - 4) and
// esi, edi restored; the naked wrapper below sets ecx that way and passes the entry ecx and edx through globals.
#include "ff.h"

extern "C" char ext_45c4f0[], ext_45c4b0[], ext_469980[];
typedef u32(*AllocFn2)(u32 a, u32 b);
typedef u32(*AllocFn1)(u32 a);
typedef u32(THISCALL *Ctor3)(void *self, u32 a, u32 b, u32 c);

extern "C" u32 factorySelfSave = 0;
extern "C" u32 factoryFinEcx = 0;

extern "C" u32 factoryCore6(void *self, u32 a, u32 b, u32 dv) {
  u32 p = b ? ((AllocFn2)(void *)ext_45c4f0)(0x8eu, b) : ((AllocFn1)(void *)ext_45c4b0)(0x8eu);
  if (!p) return 0;
  return ((Ctor3)(void *)ext_469980)((void *)p, a, (u32)self, dv);  // the exe returns the constructor's eax
}

__asm__(
    ".globl factoryWrapper6\n"
    "factoryWrapper6:\n"
    "  movl %ecx, factorySelfSave\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %ecx\n"
    "  xorl %eax, %ecx\n"
    "  movl %ecx, factoryFinEcx\n"
    "  pushl %edx\n"
    "  pushl 12(%esp)\n"
    "  pushl 12(%esp)\n"
    "  pushl factorySelfSave\n"
    "  call factoryCore6\n"
    "  addl $16, %esp\n"
    "  movl factoryFinEcx, %ecx\n"
    "  ret $8\n");
extern "C" void factoryWrapper6();
PCREG(46ac40, factoryWrapper6);
