// batch1660.cpp - 0x476200 (GUESS, residue 13 gap band, 2026-10-12). A DBREAD reader, ret 4 (one stack argument: the
// reader). Reads, from the reader's operators (thiscall, no arguments): a float into +0x48, a word into +0x4c, a dword
// into +0x4e, then a second dword whose non-zero test is stored as a byte at +0x56. The operators 0x4e5e80 (float),
// 0x4e5e40 (word), 0x4e5e60 (dword) are called as exe code, hooked in the checker.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_4e5e80[], ext_4e5e40[], ext_4e5e60[];
typedef float(THISCALL *FloatOp)(void *reader);
typedef u32(THISCALL *U32Op)(void *reader);

void THISCALL GUESS_476200(u8 *self, u8 *reader) {
  float f = ((FloatOp)(void *)ext_4e5e80)(reader);
  AT(float, self, 0x48) = f;
  u32 w = ((U32Op)(void *)ext_4e5e40)(reader);
  AT(u16, self, 0x4c) = (u16)w;
  u32 d = ((U32Op)(void *)ext_4e5e60)(reader);
  AT(u32, self, 0x4e) = d;
  u32 e = ((U32Op)(void *)ext_4e5e60)(reader);
  AT(u8, self, 0x56) = e != 0;
}
PCREG(476200, GUESS_476200);
