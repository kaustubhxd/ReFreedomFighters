// batch1659.cpp - 0x47f6c0 (GUESS, residue 13 gap band, 2026-10-12). Constructor shape: calls ZSTDOBJ::ZSTDOBJ
// (0x43de40, hooked; thiscall, three stack arguments, ret 0xc) with the three arguments in order, then stores the
// vtable 0x68af4c at +0 and zeroes the dword at +0x18. Returns this (ret 0xc).
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_43de40[];
typedef void(THISCALL *Ctor3)(void *self, u32 a, u32 b, u32 c);

u32 THISCALL GUESS_47f6c0(u8 *self, u32 a, u32 b, u32 c) {
  ((Ctor3)(void *)ext_43de40)(self, a, b, c);
  AT(u32, self, 0) = 0x68af4cu;
  AT(u32, self, 0x18) = 0;
  return (u32)self;
}
PCREG(47f6c0, GUESS_47f6c0);
