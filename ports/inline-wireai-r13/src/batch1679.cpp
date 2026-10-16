// batch1679.cpp - two single-allocation factories (residue 13 gap band, 2026-10-12). Both: thiscall, two stack arguments
// (a = [ebp+8], b = [ebp+0xc]), ret 8, SEH frame not reproduced; the epilogue leaves ecx = [0x6f5630] ^ (entry esp - 4), esi
// and edi restored (the naked wrapper is batch 1673's).
// 0x469730 (GUESS): p = 0x45c4f0(0x92, this) (cdecl, hooked). When p is set: ZItem::ZItem(p, dv, a, b) (0x469980, hooked,
// ret 0xc), vtable 0x687cb0 at p, dword +0x8e = 0; returns p. Else returns 0.
// 0x4697d0 (GUESS): the same with tag 0x94, ZItem::ZItem, vtable 0x687648, word +0x92 = 0 and dword +0x8e = 0; returns p.
// The alloc's second argument is the entry this (pushed as ecx); the ctor's first is dv (entry edx).
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_45c4f0[], ext_469980[];
typedef u32(*AllocFn2)(u32 a, u32 b);
typedef u32(THISCALL *Ctor3)(void *self, u32 a, u32 b, u32 c);

extern "C" u32 factorySelf13 = 0;
extern "C" u32 factoryFin13 = 0;
extern "C" u32 factorySelf14 = 0;
extern "C" u32 factoryFin14 = 0;

extern "C" u32 factoryCore13(void *self, u32 a, u32 b, u32 dv) {
  u32 p = ((AllocFn2)(void *)ext_45c4f0)(0x92u, (u32)self);
  if (!p) return 0;
  ((Ctor3)(void *)ext_469980)((void *)p, dv, a, b);
  AT(u32, p, 0) = 0x687cb0u;
  AT(u32, p, 0x8e) = 0;
  return p;
}

extern "C" u32 factoryCore14(void *self, u32 a, u32 b, u32 dv) {
  u32 p = ((AllocFn2)(void *)ext_45c4f0)(0x94u, (u32)self);
  if (!p) return 0;
  ((Ctor3)(void *)ext_469980)((void *)p, dv, a, b);
  AT(u32, p, 0) = 0x687648u;
  AT(u16, p, 0x92) = 0;
  AT(u32, p, 0x8e) = 0;
  return p;
}

__asm__(
    ".globl factoryWrapper13\n"
    "factoryWrapper13:\n"
    "  movl %ecx, factorySelf13\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %ecx\n"
    "  xorl %eax, %ecx\n"
    "  movl %ecx, factoryFin13\n"
    "  pushl %edx\n"
    "  pushl 12(%esp)\n"
    "  pushl 12(%esp)\n"
    "  pushl factorySelf13\n"
    "  call factoryCore13\n"
    "  addl $16, %esp\n"
    "  movl factoryFin13, %ecx\n"
    "  ret $8\n"
    ".globl factoryWrapper14\n"
    "factoryWrapper14:\n"
    "  movl %ecx, factorySelf14\n"
    "  leal -4(%esp), %eax\n"
    "  movl 0x6f5630, %ecx\n"
    "  xorl %eax, %ecx\n"
    "  movl %ecx, factoryFin14\n"
    "  pushl %edx\n"
    "  pushl 12(%esp)\n"
    "  pushl 12(%esp)\n"
    "  pushl factorySelf14\n"
    "  call factoryCore14\n"
    "  addl $16, %esp\n"
    "  movl factoryFin14, %ecx\n"
    "  ret $8\n");
extern "C" void factoryWrapper13();
extern "C" void factoryWrapper14();
PCREG(469730, factoryWrapper13);
PCREG(4697d0, factoryWrapper14);
