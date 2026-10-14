// batch1667.cpp - 0x476390 (GUESS, residue 13 gap band, 2026-10-12). ret 4 (one argument: obj). Clears bit 0x40 of
// this+4, calls ZEventBase::GetInput (0x6352f0, hooked; thiscall, one argument: a stack dword) on this, then reads a
// float into +0x48, a word into +0x4c and a dword into +0x4e from the same stack reader (DBREAD operators 0x4e5e80,
// 0x4e5e40, 0x4e5e60, hooked). Then obj's slot 0x58(this+0x52) and 0x68(this+0x56). Returns 1 with the low byte set
// on the last call's eax (the same pattern as batches 1661/1662). GUESS: the names.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_6352f0[], ext_4e5e80[], ext_4e5e40[], ext_4e5e60[];
typedef void(THISCALL *GetInputFn)(void *self, u32 *out);
typedef float(THISCALL *FloatOp)(void *reader);
typedef u32(THISCALL *U32Op)(void *reader);

u32 THISCALL GUESS_476390(u8 *self, u8 *obj) {
  u32 reader = 0;
  AT(u32, self, 4) &= 0xffffffbfu;
  ((GetInputFn)(void *)ext_6352f0)(self, &reader);
  AT(float, self, 0x48) = ((FloatOp)(void *)ext_4e5e80)(&reader);
  AT(u16, self, 0x4c) = (u16)((U32Op)(void *)ext_4e5e40)(&reader);
  AT(u32, self, 0x4e) = ((U32Op)(void *)ext_4e5e60)(&reader);
  vcall<void>(obj, 0x58, (u32)(self + 0x52));
  u32 last = vcall<u32>(obj, 0x68, (u32)(self + 0x56));
  return (last & 0xffffff00u) | 1u;
}
PCREG(476390, GUESS_476390);
