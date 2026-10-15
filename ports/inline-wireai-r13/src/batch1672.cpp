// batch1672.cpp - 0x46b3c0 (GUESS, residue 13 gap band, 2026-10-12). Same accessor and wrapper shape as batches 1670 and
// 1671 (SEH frame not reproduced; the epilogue leaves esi = [0x6f5630] ^ (entry esp - 4), ecx restored). Core: p =
// (sys+0x9b)->+8 vslot 0x44(); when p is set: the constructor at 0x469870 (hooked; thiscall, no arguments, plain ret) runs on
// p, then p+4 |= 0x20, p+0x44 = 0, and the vtable 0x6867cc is stored at p+0. Returns p.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_469870[];
typedef void(THISCALL *CtorNoArgs)(void *self);

static u32 GetAccessor() {
  u8 *mgr = AT(u8 *, AT(u8 *, 0x70039c, 0), 0x9b);
  u8 *o = AT(u8 *, mgr, 8);
  return vcall<u32>(o, 0x44);
}

extern "C" u32 accessorCore5(void *self) {
  u32 p = GetAccessor();
  if (p) {
    ((CtorNoArgs)(void *)ext_469870)((void *)p);
    AT(u32, p, 4) |= 0x20u;
    AT(u32, p, 0x44) = 0;
    AT(u32, p, 0) = 0x6867ccu;
  }
  return p;
}

__asm__(
    ".globl accessorWrapper5\n"
    "accessorWrapper5:\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %edx\n"
    "  xorl %eax, %edx\n"
    "  pushl %edx\n"
    "  pushl %ecx\n"
    "  pushl %ecx\n"
    "  call accessorCore5\n"
    "  addl $4, %esp\n"
    "  popl %ecx\n"
    "  popl %esi\n"
    "  ret\n");
extern "C" void accessorWrapper5();
PCREG(46b3c0, accessorWrapper5);
