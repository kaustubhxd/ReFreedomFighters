// batch1685.cpp - 0x4765e0 (GUESS, residue 13 gap band, 2026-10-12). Thiscall, two stack arguments (a, b), ret 8; SEH frame
// not reproduced (batch 1673 wrapper: ecx = [0x6f5630] ^ (entry esp - 4)). b != 0: calls 0x476400 (batch 1684) with ecx = b,
// edx = a, and stack arguments (self, dv) (fastcall-style: the callee pops its 8), and returns its eax. b == 0: p =
// 0x45c4b0(0x77) (cdecl, hooked); null returns 0; else ZGROUP::ZGROUP(p, a, self, dv) (0x43e990, hooked, ret 0xc), vtable
// 0x689de4, zeroed +0x5c..+0x6c, byte +0x72, returns p.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_476400[], ext_45c4b0[], ext_43e990[];
typedef u32(__attribute__((fastcall)) *Factory476400)(void *ecx, u32 edx, u32 a, u32 b);
typedef u32(*AllocFn1)(u32 a);
typedef u32(THISCALL *GroupCtor)(void *self, u32 a, u32 b, u32 c);

extern "C" u32 factorySelf16 = 0;
extern "C" u32 factoryFin16 = 0;

extern "C" u32 factoryCore16(void *self, u32 a, u32 b, u32 dv) {
  if (b) return ((Factory476400)(void *)ext_476400)((void *)b, a, (u32)self, dv);
  u32 p = ((AllocFn1)(void *)ext_45c4b0)(0x77u);
  if (!p) return 0;
  ((GroupCtor)(void *)ext_43e990)((void *)p, a, (u32)self, dv);
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
    ".globl factoryWrapper16\n"
    "factoryWrapper16:\n"
    "  movl %ecx, factorySelf16\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %ecx\n"
    "  xorl %eax, %ecx\n"
    "  movl %ecx, factoryFin16\n"
    "  pushl %edx\n"
    "  pushl 12(%esp)\n"
    "  pushl 12(%esp)\n"
    "  pushl factorySelf16\n"
    "  call factoryCore16\n"
    "  addl $16, %esp\n"
    "  movl factoryFin16, %ecx\n"
    "  ret $8\n");
extern "C" void factoryWrapper16();
PCREG(4765e0, factoryWrapper16);
