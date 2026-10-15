// batch1684.cpp - 0x476400 (GUESS, residue 13 gap band, 2026-10-12). Thiscall, two stack arguments (a, b), ret 8. SEH
// frame not reproduced; the epilogue leaves ecx = [0x6f5630] ^ (entry esp - 4) and esi, edi restored (batch 1673 wrapper).
// p = 0x45c4f0(0x77, this) (cdecl, hooked); null returns 0. Otherwise ZGROUP::ZGROUP(p, dv, a, b) (0x43e990, hooked,
// ret 0xc), vtable 0x689de4 at p, dwords +0x5c, +0x60, +0x64, +0x68, +0x6c zeroed, byte +0x72 zeroed, returns p (the exe
// moves p into eax after the constructor).
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_45c4f0[], ext_43e990[];
typedef u32(*AllocFn2)(u32 a, u32 b);
typedef u32(THISCALL *GroupCtor)(void *self, u32 a, u32 b, u32 c);

extern "C" u32 factorySelf15 = 0;
extern "C" u32 factoryFin15 = 0;

extern "C" u32 factoryCore15(void *self, u32 a, u32 b, u32 dv) {
  u32 p = ((AllocFn2)(void *)ext_45c4f0)(0x77u, (u32)self);
  if (!p) return 0;
  ((GroupCtor)(void *)ext_43e990)((void *)p, dv, a, b);
  AT(u32, p, 0) = 0x689de4u;
  AT(u32, p, 0x5c) = 0;
  AT(u32, p, 0x60) = 0;
  AT(u32, p, 0x64) = 0;
  AT(u32, p, 0x68) = 0;
  AT(u32, p, 0x6c) = 0;
  AT(u8, p, 0x72) = 0;
  return p;
}

__asm__(
    ".globl factoryWrapper15\n"
    "factoryWrapper15:\n"
    "  movl %ecx, factorySelf15\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %ecx\n"
    "  xorl %eax, %ecx\n"
    "  movl %ecx, factoryFin15\n"
    "  pushl %edx\n"
    "  pushl 12(%esp)\n"
    "  pushl 12(%esp)\n"
    "  pushl factorySelf15\n"
    "  call factoryCore15\n"
    "  addl $16, %esp\n"
    "  movl factoryFin15, %ecx\n"
    "  ret $8\n");
extern "C" void factoryWrapper15();
PCREG(476400, factoryWrapper15);
