// batch1687.cpp - 0x476560 (GUESS, residue 13 gap band, 2026-10-12). Thiscall, one stack argument (flags), ret 4. Sets the
// vtable 0x689de4, frees the blocks at +0x64 and +0x68 (cdecl __builtin_delete 0x634273, size 4, hooked when set), calls
// 0x43ea20 (hooked; thiscall, no arguments) on this, then when flags bit 0 is set: bit 2 clear calls 0x45c510 (ZGEOM::operator
// delete, cdecl one argument, SEH-framed in the exe, hooked here); bit 2 set calls 0x4690b0(0x77, this) (cdecl two arguments,
// hooked). Returns this. SEH frame of the function itself not reproduced (only the exits matter here).
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_634273[], ext_43ea20[], ext_45c510[], ext_4690b0[];
typedef void(*BuiltinDelete)(void *p, u32 size);
typedef void(THISCALL *Void0)(void *self);
typedef void(*Cdecl1)(void *p);
typedef void(*Cdecl2)(void *p, u32 b);

extern "C" u32 dtorSelf19 = 0;
extern "C" u32 dtorFlags19 = 0;

extern "C" u32 dtorCore19(void *self, u32 flags) {
  AT(u32, self, 0) = 0x689de4u;
  u32 p64 = AT(u32, self, 0x64);
  if (p64) ((BuiltinDelete)(void *)ext_634273)((void *)p64, 4);
  u32 p68 = AT(u32, self, 0x68);
  if (p68) ((BuiltinDelete)(void *)ext_634273)((void *)p68, 4);
  ((Void0)(void *)ext_43ea20)(self);
  if (flags & 1) {
    if (flags & 4) ((Cdecl2)(void *)ext_4690b0)(self, 0x77u);
    else ((Cdecl1)(void *)ext_45c510)(self);
  }
  return (u32)self;
}

__asm__(
    ".globl dtorWrapper19\n"
    "dtorWrapper19:\n"
    "  movl %ecx, dtorSelf19\n"
    "  movl 4(%esp), %eax\n"
    "  movl %eax, dtorFlags19\n"
    "  pushl dtorFlags19\n"
    "  pushl dtorSelf19\n"
    "  call dtorCore19\n"
    "  addl $8, %esp\n"
    "  ret $4\n");
extern "C" void dtorWrapper19();
PCREG(476560, dtorWrapper19);
