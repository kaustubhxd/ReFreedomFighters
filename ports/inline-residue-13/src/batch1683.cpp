// batch1683.cpp - 0x4766a0 (GUESS, residue 13 gap band, 2026-10-12). Accessor + constructor shape as batch 1672 (0x46b3c0):
// p = (sys+0x9b)->+8 vslot 0x44(); when p is set: the constructor 0x469870 (hooked, no arguments), p+4 |= 0x20, p+0x44 = 0,
// vtable 0x689d2c at p+0, and the dword at p+0x52 = 0. Returns p. SEH frame not reproduced; asm wrapper as batch 1670.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_469870[];
typedef void(THISCALL *CtorNoArgs)(void *self);

static u32 GetAccessor() {
  u8 *mgr = AT(u8 *, AT(u8 *, 0x70039c, 0), 0x9b);
  u8 *o = AT(u8 *, mgr, 8);
  return vcall<u32>(o, 0x44);
}

extern "C" u32 accessorCore9(void *self) {
  u32 p = GetAccessor();
  if (p) {
    ((CtorNoArgs)(void *)ext_469870)((void *)p);
    AT(u32, p, 4) |= 0x20u;
    AT(u32, p, 0x44) = 0;
    AT(u32, p, 0) = 0x689d2cu;
    AT(u32, p, 0x52) = 0;
  }
  return p;
}

__asm__(
    ".globl accessorWrapper9\n"
    "accessorWrapper9:\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %edx\n"
    "  xorl %eax, %edx\n"
    "  pushl %edx\n"
    "  pushl %ecx\n"
    "  pushl %ecx\n"
    "  call accessorCore9\n"
    "  addl $4, %esp\n"
    "  popl %ecx\n"
    "  popl %esi\n"
    "  ret\n");
extern "C" void accessorWrapper9();
PCREG(4766a0, accessorWrapper9);
