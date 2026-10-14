// batch1663.cpp - 0x4764b0 (GUESS, residue 13 gap band, 2026-10-12). Constructor shape: calls ZGROUP::ZGROUP (0x43e990,
// hooked; thiscall, three stack arguments, ret 0xc) with the three arguments in order, then stores vtable 0x689de4 at +0,
// zeroes the dwords at +0x5c, +0x60, +0x64, +0x68, +0x6c and the byte at +0x72, and returns this (ret 0xc).
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_43e990[];
typedef void(THISCALL *GroupCtor)(void *self, u32 a, u32 b, u32 c);

u32 THISCALL GUESS_4764b0(u8 *self, u32 a, u32 b, u32 c) {
  ((GroupCtor)(void *)ext_43e990)(self, a, b, c);
  AT(u32, self, 0) = 0x689de4u;
  AT(u32, self, 0x5c) = 0;
  AT(u32, self, 0x60) = 0;
  AT(u32, self, 0x64) = 0;
  AT(u32, self, 0x68) = 0;
  AT(u32, self, 0x6c) = 0;
  AT(u8, self, 0x72) = 0;
  return (u32)self;
}
PCREG(4764b0, GUESS_4764b0);
