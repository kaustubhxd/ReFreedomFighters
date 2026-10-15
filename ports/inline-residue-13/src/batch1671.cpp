// batch1671.cpp - two accessor + ZItemState constructor functions (residue 13, 2026-10-12). Same shape as batch 1670:
// the SEH frame (fs:[0], frame 0x66c831) is not reproduced, and the epilogue leaves esi = [0x6f5630] ^ (entry esp - 4)
// and ecx = the entry ecx; the naked wrappers below do that and run the C core (cdecl).
// 0x46b2e0 (GUESS): p = (sys+0x9b)->+8 vslot 0x44(); when p is set: ZItemState::ZItemState(p) (0x469cc0, hooked), then the
// vtable 0x6865b4 is stored at p+0; returns p.
// 0x46b350 (GUESS): the same with vtable 0x686518.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_469cc0[];
typedef void(THISCALL *CtorNoArgs)(void *self);

static u32 GetAccessor() {
  u8 *mgr = AT(u8 *, AT(u8 *, 0x70039c, 0), 0x9b);
  u8 *o = AT(u8 *, mgr, 8);
  return vcall<u32>(o, 0x44);
}

extern "C" u32 accessorCore3(void *self) {
  u32 p = GetAccessor();
  if (p) {
    ((CtorNoArgs)(void *)ext_469cc0)((void *)p);
    AT(u32, p, 0) = 0x6865b4u;
  }
  return p;
}

extern "C" u32 accessorCore4(void *self) {
  u32 p = GetAccessor();
  if (p) {
    ((CtorNoArgs)(void *)ext_469cc0)((void *)p);
    AT(u32, p, 0) = 0x686518u;
  }
  return p;
}

__asm__(
    ".globl accessorWrapper3\n"
    "accessorWrapper3:\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %edx\n"
    "  xorl %eax, %edx\n"
    "  pushl %edx\n"
    "  pushl %ecx\n"
    "  pushl %ecx\n"
    "  call accessorCore3\n"
    "  addl $4, %esp\n"
    "  popl %ecx\n"
    "  popl %esi\n"
    "  ret\n"
    ".globl accessorWrapper4\n"
    "accessorWrapper4:\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %edx\n"
    "  xorl %eax, %edx\n"
    "  pushl %edx\n"
    "  pushl %ecx\n"
    "  pushl %ecx\n"
    "  call accessorCore4\n"
    "  addl $4, %esp\n"
    "  popl %ecx\n"
    "  popl %esi\n"
    "  ret\n");
extern "C" void accessorWrapper3();
extern "C" void accessorWrapper4();
PCREG(46b2e0, accessorWrapper3);
PCREG(46b350, accessorWrapper4);
