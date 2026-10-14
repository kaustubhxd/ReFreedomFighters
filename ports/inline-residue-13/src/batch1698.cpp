// batch1698.cpp - 0x47fce0 (GUESS, residue 13 gap band, 2026-10-12). Constructor shape as batch 1659: ZSTDOBJ::ZSTDOBJ
// (0x43de40, hooked; thiscall, three stack arguments, ret 0xc) with the three arguments in order; then vtable 0x68b364 at +0,
// float 100.0 at +0x1c, float 1.0 at +0x20, float 0.5 at +0x24, dword 8 at +0x18 and dword 0 at +0x8c. Returns this (ret 0xc).
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_43de40[];
typedef void(THISCALL *Ctor3)(void *self, u32 a, u32 b, u32 c);

u32 THISCALL GUESS_47fce0(u8 *self, u32 a, u32 b, u32 c) {
  ((Ctor3)(void *)ext_43de40)(self, a, b, c);
  AT(u32, self, 0) = 0x68b364u;
  AT(u32, self, 0x1c) = 0x42c80000u;
  AT(u32, self, 0x24) = 0x3f000000u;
  AT(u32, self, 0x20) = 0x3f800000u;
  AT(u32, self, 0x8c) = 0;
  AT(u32, self, 0x18) = 8;
  return (u32)self;
}
PCREG(47fce0, GUESS_47fce0);
