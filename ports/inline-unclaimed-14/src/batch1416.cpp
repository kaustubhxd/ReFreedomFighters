// batch1416.cpp - unclaimed-14 batch 16 (residue 13): ZAnimSequence::ReadInput(DBREAD&).
#include "ff.h"

// DBREAD operators and GetRefTab (original addresses, replaced by stubs in the spec: serial_stubs-style).
extern "C" void THISCALL ext_4e6330(u8 *dbread, u32 reftab);   // GetRefTab(REFTAB*), 1 stack argument
extern "C" u32 THISCALL ext_4e5e60(u8 *dbread);                 // DBREAD::operator unsigned int()
extern "C" u32 THISCALL ext_4e5e40(u8 *dbread);                 // DBREAD::operator unsigned short() (low word of eax)
extern "C" float THISCALL ext_4e5e80(u8 *dbread);               // a float reader that returns in st0

// 0x4c4e90, ZAnimSequence::ReadInput(DBREAD&) (high): thiscall, one stack argument (ret 4).
//  GetRefTab(this+0x4c), GetRefTab(this+0x50), GetRefTab(this+0x54) (pushed in that order)
//  this+0x58 = u32(); this+0x5c = u32(); this+0x48 = (u16)u16(); this+0x60 = float(); then
//  r = u32(); this+0x60 = this+0x60 / 25.0; this+0x64 = (r != 0); (the float is stored back).
static void THISCALL animSequenceReadInput(u8 *self, u8 *dbread) {
  ext_4e6330(dbread, *(u32 *)(self + 0x4c));
  ext_4e6330(dbread, *(u32 *)(self + 0x50));
  ext_4e6330(dbread, *(u32 *)(self + 0x54));
  *(u32 *)(self + 0x58) = ext_4e5e60(dbread);
  *(u32 *)(self + 0x5c) = ext_4e5e60(dbread);
  *(u16 *)(self + 0x48) = (u16)ext_4e5e40(dbread);
  *(float *)(self + 0x60) = ext_4e5e80(dbread);
  u32 r = ext_4e5e60(dbread);
  float f = *(float *)(self + 0x60);
  f = f / G(float, 0x685270);
  *(u8 *)(self + 0x64) = (u8)(r != 0);
  *(float *)(self + 0x60) = f;
}
PCREG(4c4e90, animSequenceReadInput);
