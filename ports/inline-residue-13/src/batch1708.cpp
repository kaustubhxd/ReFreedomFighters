// batch1708.cpp - four unported functions in the area-13 band (2026-10-12, standing assignment). GUESS names.
// 0x493110 (plain ret): if the byte at this+0xbc2 is zero: set it to 1, then tail-jump into 0x498700 (hooked; no arguments)
// with this+8 as this when that pointer is set.
// 0x4c59d0 (ret 4, one argument obj): clears bit 0x40 of this+4; r = obj's vslot 0x68(this+0x4c); returns (r with low byte 1).
// 0x4cbdd0 (ret 4, one argument obj): the same with vslot 0x50.
// 0x645c10 (ret 4, one argument dst): when the byte at this+0x266 is set, *dst (a byte) = the byte at this+0x267.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_498700[];
typedef void(THISCALL *Void0)(void *self);

void THISCALL GUESS_493110(u8 *self) {
  if (AT(u8, self, 0xbc2)) return;
  AT(u8, self, 0xbc2) = 1;
  u32 o = AT(u32, self, 8);
  if (o) ((Void0)(void *)ext_498700)((void *)o);
}
PCREG(493110, GUESS_493110);

u32 THISCALL GUESS_4c59d0(u8 *self, u8 *obj) {
  AT(u32, self, 4) &= 0xffffffbfu;
  u32 r = vcall<u32>(obj, 0x68, (u32)(self + 0x4c));
  return (r & 0xffffff00u) | 1u;
}
PCREG(4c59d0, GUESS_4c59d0);

u32 THISCALL GUESS_4cbdd0(u8 *self, u8 *obj) {
  AT(u32, self, 4) &= 0xffffffbfu;
  u32 r = vcall<u32>(obj, 0x50, (u32)(self + 0x4c));
  return (r & 0xffffff00u) | 1u;
}
PCREG(4cbdd0, GUESS_4cbdd0);

void THISCALL GUESS_645c10(u8 *self, u8 *dst) {
  if (AT(u8, self, 0x266)) *dst = AT(u8, self, 0x267);
}
PCREG(645c10, GUESS_645c10);
