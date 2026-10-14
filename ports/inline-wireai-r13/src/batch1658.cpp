// batch1658.cpp - 0x47fd30 (GUESS, residue 13 gap band, 2026-10-12). Stores vtable 0x68b364 at +0; when the pointer at
// +0x8c is set, frees its +4 block (size 0x44) and then the +0x8c block (size 8), both cdecl __builtin_delete 0x634273;
// then tail-jumps to 0x43de70 with this. 0x43de70 stores vtable 0x67c3a4 and jumps to 0x45c3e0 (ZGEOM destructor body,
// ret with no immediate, so no stack arguments). The checker hooks 0x45c3e0 by address; 0x43de70 runs as exe code.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_634273[], ext_43de70[];
typedef void(*BuiltinDelete)(void *p, u32 size);
typedef u32(THISCALL *Tail0)(void *self);

u32 THISCALL GUESS_47fd30(u8 *self) {
  u8 *p = AT(u8 *, self, 0x8c);
  AT(u32, self, 0) = 0x68b364u;
  if (p) {
    ((BuiltinDelete)(void *)ext_634273)((void *)AT(u32, p, 4), 0x44);
    ((BuiltinDelete)(void *)ext_634273)((void *)AT(u32, self, 0x8c), 8);
  }
  return ((Tail0)(void *)ext_43de70)(self);
}
PCREG(47fd30, GUESS_47fd30);
