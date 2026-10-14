// batch947.cpp - area 56 residue 15, claim A6: CCheckVisible::Save(ZSaveGame*) (0x4ab870). thiscall, one stack argument,
// ret 4, returns true. The save calls are GUESS recording stubs (unverified callees).
#include "ff.h"

typedef void(THISCALL *SaveArr)(u8 *self, u8 *p, u32 n);   // sv vt+0x10 (array, count)
typedef void(THISCALL *SaveU32)(u8 *self, u32 v);          // sv vt+0x3c (dword)
typedef void(THISCALL *SaveF)(u8 *self, float v);          // sv vt+0x4c (float)

static u32 slot(u8 *obj, u32 off) {
  return *(u32 *)(*(u32 *)obj + off);
}

// 0x4ab870, CCheckVisible::Save(ZSaveGame*) (high): clears bit 6 of this+4; saves two arrays (0x640 and 0x157c0 bytes), two
// dwords and one float; returns true.
static u8 THISCALL checkVisibleSave(u8 *self, u8 *sv) {
  *(u32 *)(self + 4) &= ~0x40u;
  ((SaveArr)slot(sv, 0x10))(sv, self + 0x54, 0x640);
  ((SaveArr)slot(sv, 0x10))(sv, self + 0x694, 0x157c0);
  ((SaveU32)slot(sv, 0x3c))(sv, *(u32 *)(self + 0x15e54));
  ((SaveU32)slot(sv, 0x3c))(sv, *(u32 *)(self + 0x15e58));
  ((SaveF)slot(sv, 0x4c))(sv, *(float *)(self + 0x15e78));
  return 1;
}
PCREG(4ab870, checkVisibleSave);
