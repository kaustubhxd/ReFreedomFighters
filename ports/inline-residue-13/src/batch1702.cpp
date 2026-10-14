// batch1702.cpp - 0x47fd70 (GUESS, residue 13 gap band, 2026-10-12). ZSTDOBJ-family destructor, thiscall, one stack argument
// (flags), ret 4; SEH-free. Sets the vtable 0x68b364; when +0x8c is set frees its +4 block (size 0x44) and the +0x8c block
// (size 8) (cdecl __builtin_delete 0x634273, hooked, logged); calls 0x43de70 (hooked; no arguments); flags bit 0: bit 2 clear
// calls 0x45c510(this) (cdecl, hooked); bit 2 set calls 0x4690b0(this, 0x90) (cdecl, hooked). Returns this.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_634273[], ext_43de70[], ext_45c510[], ext_4690b0[];
typedef void(*BuiltinDelete)(void *p, u32 size);
typedef void(THISCALL *Void0)(void *self);
typedef void(*Cdecl1)(void *p);
typedef void(*Cdecl2)(void *p, u32 b);

extern "C" u32 dtorSelf31 = 0;
extern "C" u32 dtorFlags31 = 0;

extern "C" u32 dtorCore31(void *self, u32 flags) {
  u32 p = AT(u32, self, 0x8c);
  AT(u32, self, 0) = 0x68b364u;
  if (p) {
    ((BuiltinDelete)(void *)ext_634273)((void *)AT(u32, p, 4), 0x44);
    ((BuiltinDelete)(void *)ext_634273)((void *)AT(u32, self, 0x8c), 8);
  }
  ((Void0)(void *)ext_43de70)(self);
  if (flags & 1) {
    if (flags & 4) ((Cdecl2)(void *)ext_4690b0)(self, 0x90u);
    else ((Cdecl1)(void *)ext_45c510)(self);
  }
  return (u32)self;
}

__asm__(
    ".globl dtorWrapper31\n"
    "dtorWrapper31:\n"
    "  movl %ecx, dtorSelf31\n"
    "  movl 4(%esp), %eax\n"
    "  movl %eax, dtorFlags31\n"
    "  pushl dtorFlags31\n"
    "  pushl dtorSelf31\n"
    "  call dtorCore31\n"
    "  addl $8, %esp\n"
    "  ret $4\n");
extern "C" void dtorWrapper31();
PCREG(47fd70, dtorWrapper31);
