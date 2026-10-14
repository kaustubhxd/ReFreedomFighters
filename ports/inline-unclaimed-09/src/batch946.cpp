// batch946.cpp - area 56 residue 15, claim A5: ZRunParamAnim::CreateAnims(CHUNKFILE*) (0x4e6e70). thiscall, one stack argument,
// ret 4. The helper 0x4e6dc0 is unverified (GUESS recording stub in the spec).
#include "ff.h"

extern "C" void THISCALL ext_4e6dc0(u8 *self, u8 *f, u32 k);

// 0x4e6e70 (medium name): selects an offset from the chunk file (the value at +8 for the three flag patterns, 8 otherwise),
// copies two dwords from f+off into this+4 and this+8, then calls 0x4e6dc0 with 0x100001 and 0x100002.
static void THISCALL createAnims(u8 *self, u8 *f) {
  u32 a = *(u32 *)(f + 4) & 0xc0000000u;
  u32 off = (a == 0x40000000u || a == 0x80000000u || a == 0xc0000000u) ? *(u32 *)(f + 8) : 8u;
  *(u32 *)(self + 4) = *(u32 *)(f + off);
  *(u32 *)(self + 8) = *(u32 *)(f + off + 4);
  ext_4e6dc0(self, f, 0x100001);
  ext_4e6dc0(self, f, 0x100002);
}
PCREG(4e6e70, createAnims);
