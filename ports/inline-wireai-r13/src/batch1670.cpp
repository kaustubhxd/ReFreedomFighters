// batch1670.cpp - two gap-band accessors with a constructor call (residue 13, 2026-10-12). Both exe functions install an
// SEH record (fs:[0], frame 0x66c831) and their epilogue pops the xor-cookie (cookie ^ frame ebp) into esi instead of the
// caller's esi (the same stray-pop shape as area 81's 0x4b9340): on return esi = [0x6f5630] ^ (entry esp - 4), and ecx is
// the entry ecx. The SEH frame is not reproduced; the naked wrappers below set esi and ecx the way the exe leaves them,
// and run the C core (cdecl) for the accessor and the constructor call.
// 0x46b200 (GUESS): obj = (sys+0x9b)->+8; p = obj's vslot 0x44(); when p is set, ZItemSpawn::ZItemSpawn (0x469c00, hooked;
// no arguments) runs on p; returns p.
// 0x46b270 (GUESS): the same accessor with ZItemState::ZItemState (0x469cc0, hooked).
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_469c00[], ext_469cc0[];
typedef void(THISCALL *CtorNoArgs)(void *self);

static u32 GetAccessor() {
  u8 *mgr = AT(u8 *, AT(u8 *, 0x70039c, 0), 0x9b);
  u8 *o = AT(u8 *, mgr, 8);
  return vcall<u32>(o, 0x44);
}

extern "C" u32 accessorCore1(void *self) {
  u32 p = GetAccessor();
  if (p) ((CtorNoArgs)(void *)ext_469c00)((void *)p);
  return p;
}

extern "C" u32 accessorCore2(void *self) {
  u32 p = GetAccessor();
  if (p) ((CtorNoArgs)(void *)ext_469cc0)((void *)p);
  return p;
}

// Wrapper: esi = cookie ^ (entry esp - 4), ecx restored to the entry value, eax = the core's pointer, plain ret.
__asm__(
    ".globl accessorWrapper1\n"
    "accessorWrapper1:\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %edx\n"
    "  xorl %eax, %edx\n"
    "  pushl %edx\n"
    "  pushl %ecx\n"
    "  pushl %ecx\n"
    "  call accessorCore1\n"
    "  addl $4, %esp\n"
    "  popl %ecx\n"
    "  popl %esi\n"
    "  ret\n"
    ".globl accessorWrapper2\n"
    "accessorWrapper2:\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %edx\n"
    "  xorl %eax, %edx\n"
    "  pushl %edx\n"
    "  pushl %ecx\n"
    "  pushl %ecx\n"
    "  call accessorCore2\n"
    "  addl $4, %esp\n"
    "  popl %ecx\n"
    "  popl %esi\n"
    "  ret\n");
extern "C" void accessorWrapper1();
extern "C" void accessorWrapper2();
PCREG(46b200, accessorWrapper1);
PCREG(46b270, accessorWrapper2);
