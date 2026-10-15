// batch1675.cpp - three factory variants of batch 1673 (residue 13 gap band, 2026-10-12). Each: b ? 0x45c4f0(tag, b) :
// 0x45c4b0(tag) (cdecl, hooked); a non-null result gets (a, this, dv) through its constructor (thiscall, three stack
// arguments, ret 0xc, hooked) and returns the constructor eax; else returns 0. SEH frame not reproduced; the wrapper
// leaves ecx = [0x6f5630] ^ (entry esp - 4) as in batch 1673. Tags: 0x7c (0x46aee0), 0xa4 (0x46af80), 0x80 (0x46b020).
#include "ff.h"

extern "C" char ext_45c4f0[], ext_45c4b0[], ext_469da0[], ext_469ea0[], ext_469f80[];
typedef u32(*AllocFn2)(u32 a, u32 b);
typedef u32(*AllocFn1)(u32 a);
typedef u32(THISCALL *Ctor3)(void *self, u32 a, u32 b, u32 c);

extern "C" u32 factorySelf8 = 0;
extern "C" u32 factoryFin8 = 0;
extern "C" u32 factoryCore8(void *self, u32 a, u32 b, u32 dv) {
  u32 p = b ? ((AllocFn2)(void *)ext_45c4f0)(0x7cu, b) : ((AllocFn1)(void *)ext_45c4b0)(0x7cu);
  if (!p) return 0;
  return ((Ctor3)(void *)(ext_469da0))((void *)p, a, (u32)self, dv);
}

extern "C" u32 factorySelf9 = 0;
extern "C" u32 factoryFin9 = 0;
extern "C" u32 factoryCore9(void *self, u32 a, u32 b, u32 dv) {
  u32 p = b ? ((AllocFn2)(void *)ext_45c4f0)(0xa4u, b) : ((AllocFn1)(void *)ext_45c4b0)(0xa4u);
  if (!p) return 0;
  return ((Ctor3)(void *)(ext_469ea0))((void *)p, a, (u32)self, dv);
}

extern "C" u32 factorySelf10 = 0;
extern "C" u32 factoryFin10 = 0;
extern "C" u32 factoryCore10(void *self, u32 a, u32 b, u32 dv) {
  u32 p = b ? ((AllocFn2)(void *)ext_45c4f0)(0x80u, b) : ((AllocFn1)(void *)ext_45c4b0)(0x80u);
  if (!p) return 0;
  return ((Ctor3)(void *)(ext_469f80))((void *)p, a, (u32)self, dv);
}

__asm__(
    ".globl factoryWrapper8\n"
    "factoryWrapper8:\n"
    "  movl %ecx, factorySelf8\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %ecx\n"
    "  xorl %eax, %ecx\n"
    "  movl %ecx, factoryFin8\n"
    "  pushl %edx\n"
    "  pushl 12(%esp)\n"
    "  pushl 12(%esp)\n"
    "  pushl factorySelf8\n"
    "  call factoryCore8\n"
    "  addl $16, %esp\n"
    "  movl factoryFin8, %ecx\n"
    "  ret $8\n"
    ".globl factoryWrapper9\n"
    "factoryWrapper9:\n"
    "  movl %ecx, factorySelf9\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %ecx\n"
    "  xorl %eax, %ecx\n"
    "  movl %ecx, factoryFin9\n"
    "  pushl %edx\n"
    "  pushl 12(%esp)\n"
    "  pushl 12(%esp)\n"
    "  pushl factorySelf9\n"
    "  call factoryCore9\n"
    "  addl $16, %esp\n"
    "  movl factoryFin9, %ecx\n"
    "  ret $8\n"
    ".globl factoryWrapper10\n"
    "factoryWrapper10:\n"
    "  movl %ecx, factorySelf10\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %ecx\n"
    "  xorl %eax, %ecx\n"
    "  movl %ecx, factoryFin10\n"
    "  pushl %edx\n"
    "  pushl 12(%esp)\n"
    "  pushl 12(%esp)\n"
    "  pushl factorySelf10\n"
    "  call factoryCore10\n"
    "  addl $16, %esp\n"
    "  movl factoryFin10, %ecx\n"
    "  ret $8\n"
);
extern "C" void factoryWrapper8(), factoryWrapper9(), factoryWrapper10();
PCREG(46aee0, factoryWrapper8);
PCREG(46af80, factoryWrapper9);
PCREG(46b020, factoryWrapper10);
