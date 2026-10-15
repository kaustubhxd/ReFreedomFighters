// batch1701.cpp - two gap-band factories with the ZSTDOBJ constructor (residue 13, 2026-10-12). SEH frames not reproduced.
// 0x47f810 (GUESS): b ? 0x45c4f0(0x1c, b) : 0x45c4b0(0x1c) (cdecl, hooked); non-null gets ZSTDOBJ::ZSTDOBJ(p, a, this, dv)
// (0x43de40, hooked, ret 0xc), vtable 0x68af4c at p, dword p+0x18 = 0, returns p; else 0. Ret 8.
// 0x47fc30 (GUESS): 0x45c4f0(0x90, this) (cdecl, hooked); non-null gets ZSTDOBJ::ZSTDOBJ(p, dv, a, b), vtable 0x68b364 at p,
// float 100.0 / 1.0 / 0.5 at p+0x1c / p+0x20 / p+0x24, dword 0 at p+0x8c, 8 at p+0x18; returns p. Ret 8.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_45c4f0[], ext_45c4b0[], ext_43de40[];
typedef u32(*AllocFn2)(u32 a, u32 b);
typedef u32(*AllocFn1)(u32 a);
typedef void(THISCALL *Ctor3)(void *self, u32 a, u32 b, u32 c);

extern "C" u32 factorySelf29 = 0;
extern "C" u32 factoryFin29 = 0;
extern "C" u32 factorySelf30 = 0;
extern "C" u32 factoryFin30 = 0;

extern "C" u32 factoryCore29(void *self, u32 a, u32 b, u32 dv) {
  u32 p = b ? ((AllocFn2)(void *)ext_45c4f0)(0x1cu, b) : ((AllocFn1)(void *)ext_45c4b0)(0x1cu);
  if (!p) return 0;
  ((Ctor3)(void *)ext_43de40)((void *)p, a, (u32)self, dv);
  AT(u32, p, 0) = 0x68af4cu;
  AT(u32, p, 0x18) = 0;
  return p;
}

extern "C" u32 factoryCore30(void *self, u32 a, u32 b, u32 dv) {
  u32 p = ((AllocFn2)(void *)ext_45c4f0)(0x90u, (u32)self);
  if (!p) return 0;
  ((Ctor3)(void *)ext_43de40)((void *)p, dv, a, b);
  AT(u32, p, 0) = 0x68b364u;
  AT(u32, p, 0x1c) = 0x42c80000u;
  AT(u32, p, 0x24) = 0x3f000000u;
  AT(u32, p, 0x20) = 0x3f800000u;
  AT(u32, p, 0x8c) = 0;
  AT(u32, p, 0x18) = 8;
  return p;
}

__asm__(
    ".globl factoryWrapper29\n"
    "factoryWrapper29:\n"
    "  movl %ecx, factorySelf29\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %ecx\n"
    "  xorl %eax, %ecx\n"
    "  movl %ecx, factoryFin29\n"
    "  pushl %edx\n"
    "  pushl 12(%esp)\n"
    "  pushl 12(%esp)\n"
    "  pushl factorySelf29\n"
    "  call factoryCore29\n"
    "  addl $16, %esp\n"
    "  movl factoryFin29, %ecx\n"
    "  ret $8\n"
    ".globl factoryWrapper30\n"
    "factoryWrapper30:\n"
    "  movl %ecx, factorySelf30\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %ecx\n"
    "  xorl %eax, %ecx\n"
    "  movl %ecx, factoryFin30\n"
    "  pushl %edx\n"
    "  pushl 12(%esp)\n"
    "  pushl 12(%esp)\n"
    "  pushl factorySelf30\n"
    "  call factoryCore30\n"
    "  addl $16, %esp\n"
    "  movl factoryFin30, %ecx\n"
    "  ret $8\n");
extern "C" void factoryWrapper29();
extern "C" void factoryWrapper30();
PCREG(47f810, factoryWrapper29);
PCREG(47fc30, factoryWrapper30);
