// batch1697.cpp - 0x4680e0 (GUESS, residue 13 gap band, 2026-10-12). Factory, thiscall, two stack arguments (a, b), ret 8;
// SEH frame not reproduced (batch 1673 wrapper). b != 0: fastcall call into 0x467f80 (batch 1695, hooked) with ecx = b,
// edx = a and stack (self, dv); its eax is returned. b == 0: p = 0x45c4b0(0x1e2) (cdecl, hooked); null returns 0; else
// ZIKLNKOBJ::ZIKLNKOBJ(p, a, self, dv) (0x4654b0, hooked, ret 0xc), vtable 0x6860b0, p+0x1d2 = 1, p+0x1d6 = 0, p+0x1da = 1.0f,
// returns p.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_467f80[], ext_45c4b0[], ext_4654b0[];
typedef u32(__attribute__((fastcall)) *FactoryFC)(void *ecx, u32 edx, u32 a, u32 b);
typedef u32(*AllocFn1)(u32 a);
typedef u32(THISCALL *Ctor3)(void *self, u32 a, u32 b, u32 c);

extern "C" u32 factorySelf25 = 0;
extern "C" u32 factoryFin25 = 0;

extern "C" u32 factoryCore25(void *self, u32 a, u32 b, u32 dv) {
  if (b) return ((FactoryFC)(void *)ext_467f80)((void *)b, a, (u32)self, dv);
  u32 p = ((AllocFn1)(void *)ext_45c4b0)(0x1e2u);
  if (!p) return 0;
  ((Ctor3)(void *)ext_4654b0)((void *)p, a, (u32)self, dv);
  AT(u32, p, 0) = 0x6860b0u;
  AT(u32, p, 0x1d2) = 1;
  AT(u32, p, 0x1d6) = 0;
  AT(u32, p, 0x1da) = 0x3f800000u;
  return p;
}

__asm__(
    ".globl factoryWrapper25\n"
    "factoryWrapper25:\n"
    "  movl %ecx, factorySelf25\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %ecx\n"
    "  xorl %eax, %ecx\n"
    "  movl %ecx, factoryFin25\n"
    "  pushl %edx\n"
    "  pushl 12(%esp)\n"
    "  pushl 12(%esp)\n"
    "  pushl factorySelf25\n"
    "  call factoryCore25\n"
    "  addl $16, %esp\n"
    "  movl factoryFin25, %ecx\n"
    "  ret $8\n");
extern "C" void factoryWrapper25();
PCREG(4680e0, factoryWrapper25);
