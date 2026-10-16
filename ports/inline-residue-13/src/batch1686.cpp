// batch1686.cpp - two factories with a fastcall branch (residue 13 gap band, 2026-10-12). Both: thiscall, two stack arguments
// (a, b), ret 8; SEH frame not reproduced (batch 1673 wrapper). b != 0: fastcall call into the factory of batch 1679 (ecx = b,
// edx = a, stack (self, dv)), and its eax is returned. b == 0: p = 0x45c4b0(tag) (cdecl, hooked); null returns 0; else
// ZItem::ZItem(p, a, self, dv) (0x469980, hooked, ret 0xc), then the vtable and the zero stores, returns p.
// 0x46ace0 (GUESS): branch call 0x469730 (tag 0x92); vtable 0x687cb0; dword +0x8e = 0.
// 0x46ad90 (GUESS): branch call 0x4697d0 (tag 0x94); vtable 0x687648; dword +0x8e = 0 and word +0x92 = 0.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_469730[], ext_4697d0[], ext_45c4b0[], ext_469980[];
typedef u32(__attribute__((fastcall)) *FactoryFC)(void *ecx, u32 edx, u32 a, u32 b);
typedef u32(*AllocFn1)(u32 a);
typedef u32(THISCALL *ZItemCtor)(void *self, u32 a, u32 b, u32 c);

extern "C" u32 factorySelf17 = 0;
extern "C" u32 factoryFin17 = 0;
extern "C" u32 factorySelf18 = 0;
extern "C" u32 factoryFin18 = 0;

extern "C" u32 factoryCore17(void *self, u32 a, u32 b, u32 dv) {
  if (b) return ((FactoryFC)(void *)ext_469730)((void *)b, a, (u32)self, dv);
  u32 p = ((AllocFn1)(void *)ext_45c4b0)(0x92u);
  if (!p) return 0;
  ((ZItemCtor)(void *)ext_469980)((void *)p, a, (u32)self, dv);
  AT(u32, p, 0) = 0x687cb0u;
  AT(u32, p, 0x8e) = 0;
  return p;
}

extern "C" u32 factoryCore18(void *self, u32 a, u32 b, u32 dv) {
  if (b) return ((FactoryFC)(void *)ext_4697d0)((void *)b, a, (u32)self, dv);
  u32 p = ((AllocFn1)(void *)ext_45c4b0)(0x94u);
  if (!p) return 0;
  ((ZItemCtor)(void *)ext_469980)((void *)p, a, (u32)self, dv);
  AT(u32, p, 0) = 0x687648u;
  AT(u32, p, 0x8e) = 0;
  AT(u16, p, 0x92) = 0;
  return p;
}

__asm__(
    ".globl factoryWrapper17\n"
    "factoryWrapper17:\n"
    "  movl %ecx, factorySelf17\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %ecx\n"
    "  xorl %eax, %ecx\n"
    "  movl %ecx, factoryFin17\n"
    "  pushl %edx\n"
    "  pushl 12(%esp)\n"
    "  pushl 12(%esp)\n"
    "  pushl factorySelf17\n"
    "  call factoryCore17\n"
    "  addl $16, %esp\n"
    "  movl factoryFin17, %ecx\n"
    "  ret $8\n"
    ".globl factoryWrapper18\n"
    "factoryWrapper18:\n"
    "  movl %ecx, factorySelf18\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %ecx\n"
    "  xorl %eax, %ecx\n"
    "  movl %ecx, factoryFin18\n"
    "  pushl %edx\n"
    "  pushl 12(%esp)\n"
    "  pushl 12(%esp)\n"
    "  pushl factorySelf18\n"
    "  call factoryCore18\n"
    "  addl $16, %esp\n"
    "  movl factoryFin18, %ecx\n"
    "  ret $8\n");
extern "C" void factoryWrapper17();
extern "C" void factoryWrapper18();
PCREG(46ace0, factoryWrapper17);
PCREG(46ad90, factoryWrapper18);
