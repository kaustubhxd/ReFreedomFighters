// batch6580.cpp - unclaimed-68 batch 58 (claim 59): 0x4c4e90, ZAnimSequence::ReadInput(DBREAD&) (residue name, medium).
// thiscall, one stack argument (the stream), ret 4. Reads from the stream in this order: three GetRefTab calls with this+0x4c, +0x50, +0x54;
// dword to +0x58; dword to +0x5c; word to +0x48; float to +0x60; dword v3; then +0x60 = (float)(+0x60 / 1.0f constant at 0x685270),
// and +0x64 = (v3 != 0).
#include "ff.h"

extern "C" void THISCALL ext_4e6330(u8 *stream, u32 refValue);   // DBREAD::GetRefTab, one stack argument, ret 4 (stubbed in the spec)
extern "C" u32 THISCALL ext_4e5e60(u8 *stream);                  // DBREAD::operator unsigned int, ret 0
extern "C" u16 THISCALL ext_4e5e40(u8 *stream);                  // DBREAD::operator unsigned short, ret 0
extern "C" float THISCALL ext_4e5e80(u8 *stream);                // DBREAD float operator, returns ST0, ret 0

static void THISCALL zanimSeqReadInput(u8 *self, u8 *stream) {
  ext_4e6330(stream, *(u32 *)(self + 0x4c));
  ext_4e6330(stream, *(u32 *)(self + 0x50));
  ext_4e6330(stream, *(u32 *)(self + 0x54));
  *(u32 *)(self + 0x58) = ext_4e5e60(stream);
  *(u32 *)(self + 0x5c) = ext_4e5e60(stream);
  *(u16 *)(self + 0x48) = ext_4e5e40(stream);
  *(float *)(self + 0x60) = ext_4e5e80(stream);
  u32 v3 = ext_4e5e60(stream);
  float q = *(float *)(self + 0x60) / G(float, 0x685270);
  *(u8 *)(self + 0x64) = (v3 != 0);
  *(float *)(self + 0x60) = q;
}
PCREG(4c4e90, zanimSeqReadInput);
