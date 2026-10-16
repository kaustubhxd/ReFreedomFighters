// batch1700.cpp - two gap-band functions (residue 13, 2026-10-12). SEH frames not reproduced.
// 0x477840 (GUESS): factory of batch 1673 with tag 0x77f and the ZActor constructor 0x476f50 (thiscall, three stack arguments,
// ret 0xc; hooked): b ? 0x45c4f0(0x77f, b) : 0x45c4b0(0x77f); non-null gets (a, this, dv) and returns the constructor's eax;
// else 0. Ret 8; wrapper of batch 1673.
// 0x47f760 (GUESS): destructor shape of batch 1699 (vtable 0x68af4c; manager slot 0x58(+0x18) and the result's slot 0x210(1)
// when +0x18 is set; 0x43de70 hooked) then the flag exits of batch 1693: bit 0 with bit 2 clear: 0x45c510(this); bit 2 set:
// 0x4690b0(this, 0x1c). Returns this. Ret 4; wrapper of batch 1693.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_45c4f0[], ext_45c4b0[], ext_476f50[], ext_43de70[], ext_45c510[], ext_4690b0[];
typedef u32(*AllocFn2)(u32 a, u32 b);
typedef u32(*AllocFn1)(u32 a);
typedef u32(THISCALL *Ctor3)(void *self, u32 a, u32 b, u32 c);
typedef void(THISCALL *Void0)(void *self);
typedef u32(THISCALL *Tail0)(void *self);
typedef void(*Cdecl1)(void *p);
typedef void(*Cdecl2)(void *p, u32 b);

extern "C" u32 factorySelf27 = 0;
extern "C" u32 factoryFin27 = 0;
extern "C" u32 dtorSelf28 = 0;
extern "C" u32 dtorFlags28 = 0;

extern "C" u32 factoryCore27(void *self, u32 a, u32 b, u32 dv) {
  u32 p = b ? ((AllocFn2)(void *)ext_45c4f0)(0x77fu, b) : ((AllocFn1)(void *)ext_45c4b0)(0x77fu);
  if (!p) return 0;
  return ((Ctor3)(void *)ext_476f50)((void *)p, a, (u32)self, dv);
}

extern "C" u32 dtorCore28(void *self, u32 flags) {
  AT(u32, self, 0) = 0x68af4cu;
  u32 d = AT(u32, self, 0x18);
  if (d) {
    u8 *mgr = AT(u8 *, AT(u8 *, 0x70039c, 0), 0x9b);
    u32 r = vcall<u32>(mgr, 0x58, d);
    if (r) vcall<void>((void *)r, 0x210, (u32)1);
  }
  ((Void0)(void *)ext_43de70)(self);
  if (flags & 1) {
    if (flags & 4) ((Cdecl2)(void *)ext_4690b0)(self, 0x1cu);
    else ((Cdecl1)(void *)ext_45c510)(self);
  }
  return (u32)self;
}

__asm__(
    ".globl factoryWrapper27\n"
    "factoryWrapper27:\n"
    "  movl %ecx, factorySelf27\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %ecx\n"
    "  xorl %eax, %ecx\n"
    "  movl %ecx, factoryFin27\n"
    "  pushl %edx\n"
    "  pushl 12(%esp)\n"
    "  pushl 12(%esp)\n"
    "  pushl factorySelf27\n"
    "  call factoryCore27\n"
    "  addl $16, %esp\n"
    "  movl factoryFin27, %ecx\n"
    "  ret $8\n"
    ".globl dtorWrapper28\n"
    "dtorWrapper28:\n"
    "  movl %ecx, dtorSelf28\n"
    "  movl 4(%esp), %eax\n"
    "  movl %eax, dtorFlags28\n"
    "  pushl dtorFlags28\n"
    "  pushl dtorSelf28\n"
    "  call dtorCore28\n"
    "  addl $8, %esp\n"
    "  ret $4\n");
extern "C" void factoryWrapper27();
extern "C" void dtorWrapper28();
PCREG(477840, factoryWrapper27);
PCREG(47f760, dtorWrapper28);
