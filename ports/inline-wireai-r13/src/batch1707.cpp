// batch1707.cpp - two unported functions in the area-13 band (2026-10-12, standing assignment). GUESS names.
// 0x4632d0 (ret 4, one argument dst): src = (this+0x6c)'s vslot 0x58(this); copies 0x24 bytes from src to dst with the exe's
// mcpy (0x4de420, fastcall: ecx = dst, edx = src; run as exe code).
// 0x4c5750 (ret 4, one argument obj): clears bit 0x40 of this+4; r = obj's vslot 0x60(byte this+0x52); returns (r with low byte 1).
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_4de420[];
typedef void(FASTCALL *McpyFn)(void *dst, const void *src);

void THISCALL GUESS_4632d0(u8 *self, u8 *dst) {
  u8 *o = AT(u8 *, self, 0x6c);
  u32 src = vcall<u32>(o, 0x58, (u32)self);   // the callee takes one stack argument (self, pushed first)
  ((McpyFn)(void *)ext_4de420)(dst, (const void *)src);
}
PCREG(4632d0, GUESS_4632d0);

u32 THISCALL GUESS_4c5750(u8 *self, u8 *obj) {
  AT(u32, self, 4) &= 0xffffffbfu;
  u32 r = vcall<u32>(obj, 0x60, (u32)AT(u8, self, 0x52));
  return (r & 0xffffff00u) | 1u;
}
PCREG(4c5750, GUESS_4c5750);
