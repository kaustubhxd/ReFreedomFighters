// batch1693.cpp - 0x461020 (GUESS, residue 13 gap band, 2026-10-12). ZLNKOBJ destructor, thiscall, one stack argument (flags),
// ret 4; SEH frame not reproduced. Sets the vtable 0x6854e0; calls ZLNKOBJ::CloseObjMatBone (0x461f00, hooked; no arguments);
// releases the objects at +0x72, +0x76 (each when set), +0x5c (when set and different from +0x72) and +0x60 (when set and
// different from +0x76) with their slot 0 (argument 1); calls the ZGEOM destructor chain 0x43de70 (hooked; no arguments);
// then flags bit 0: bit 2 clear calls 0x45c510(this) (cdecl, hooked); bit 2 set calls 0x4690b0(this, 0x136) (cdecl, hooked).
// Returns this. GUESS: names and the slot number.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_461f00[], ext_43de70[], ext_45c510[], ext_4690b0[];
typedef void(THISCALL *Void0)(void *self);
typedef void(*Cdecl1)(void *p);
typedef void(*Cdecl2)(void *p, u32 b);

extern "C" u32 dtorSelf21 = 0;
extern "C" u32 dtorFlags21 = 0;

extern "C" u32 dtorCore21(void *self, u32 flags) {
  AT(u32, self, 0) = 0x6854e0u;
  ((Void0)(void *)ext_461f00)(self);
  u32 v72 = AT(u32, self, 0x72);
  if (v72) vcall<void>((void *)v72, 0, (u32)1);
  u32 v76 = AT(u32, self, 0x76);
  if (v76) vcall<void>((void *)v76, 0, (u32)1);
  u32 v5c = AT(u32, self, 0x5c);
  if (v5c && v5c != AT(u32, self, 0x72)) vcall<void>((void *)v5c, 0, (u32)1);
  u32 v60 = AT(u32, self, 0x60);
  if (v60 && v60 != AT(u32, self, 0x76)) vcall<void>((void *)v60, 0, (u32)1);
  ((Void0)(void *)ext_43de70)(self);
  if (flags & 1) {
    if (flags & 4) ((Cdecl2)(void *)ext_4690b0)(self, 0x136u);
    else ((Cdecl1)(void *)ext_45c510)(self);
  }
  return (u32)self;
}

__asm__(
    ".globl dtorWrapper21\n"
    "dtorWrapper21:\n"
    "  movl %ecx, dtorSelf21\n"
    "  movl 4(%esp), %eax\n"
    "  movl %eax, dtorFlags21\n"
    "  pushl dtorFlags21\n"
    "  pushl dtorSelf21\n"
    "  call dtorCore21\n"
    "  addl $8, %esp\n"
    "  ret $4\n");
extern "C" void dtorWrapper21();
PCREG(461020, dtorWrapper21);
