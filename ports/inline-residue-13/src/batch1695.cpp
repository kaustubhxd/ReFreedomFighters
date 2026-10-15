// batch1695.cpp - 0x467f80 (GUESS, residue 13 gap band, 2026-10-12). Single-allocation factory, thiscall, two stack arguments
// (a, b), ret 8; SEH frame not reproduced (batch 1673 wrapper). p = 0x45c4f0(0x1e2, this) (cdecl, hooked); null returns 0.
// Otherwise ZIKLNKOBJ::ZIKLNKOBJ(p, dv, a, b) (0x4654b0, hooked, ret 0xc), vtable 0x6860b0 at p, dword p+0x1d2 = 1, p+0x1d6 = 0,
// p+0x1da = 1.0f bits; returns p.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_45c4f0[], ext_4654b0[];
typedef u32(*AllocFn2)(u32 a, u32 b);
typedef u32(THISCALL *Ctor3)(void *self, u32 a, u32 b, u32 c);

extern "C" u32 factorySelf23 = 0;
extern "C" u32 factoryFin23 = 0;

extern "C" u32 factoryCore23(void *self, u32 a, u32 b, u32 dv) {
  u32 p = ((AllocFn2)(void *)ext_45c4f0)(0x1e2u, (u32)self);
  if (!p) return 0;
  ((Ctor3)(void *)ext_4654b0)((void *)p, dv, a, b);
  AT(u32, p, 0) = 0x6860b0u;
  AT(u32, p, 0x1d2) = 1;
  AT(u32, p, 0x1d6) = 0;
  AT(u32, p, 0x1da) = 0x3f800000u;
  return p;
}

__asm__(
    ".globl factoryWrapper23\n"
    "factoryWrapper23:\n"
    "  movl %ecx, factorySelf23\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %ecx\n"
    "  xorl %eax, %ecx\n"
    "  movl %ecx, factoryFin23\n"
    "  pushl %edx\n"
    "  pushl 12(%esp)\n"
    "  pushl 12(%esp)\n"
    "  pushl factorySelf23\n"
    "  call factoryCore23\n"
    "  addl $16, %esp\n"
    "  movl factoryFin23, %ecx\n"
    "  ret $8\n");
extern "C" void factoryWrapper23();
PCREG(467f80, factoryWrapper23);
