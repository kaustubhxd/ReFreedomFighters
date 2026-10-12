// batch256.cpp - unclaimed area 25, residue-05 item 0x5c6610 (name from residue-05: ZFFSearchLightGroup::CopyEventDataBlock).
#include "ff.h"

extern "C" float THISCALL ext_4e5e80(u8 *blk);    // float result in st0, original code
extern "C" u32 THISCALL ext_4e5e60(u8 *blk);      // u32 result in eax, original code

// 0x5c6610, thiscall, ret 4 (one stack argument: blk). Copies three values out of the block helpers:
// this+0x71 = float(ext_4e5e80(blk)), this+0x4c = ext_4e5e60(blk), this+0x6d = float(ext_4e5e80(blk)).
static void THISCALL copyFromBlock(u8 *self, u8 *blk) {
  *(float *)(self + 0x71) = ext_4e5e80(blk);
  *(u32 *)(self + 0x4c) = ext_4e5e60(blk);
  *(float *)(self + 0x6d) = ext_4e5e80(blk);
}
PCREG(5c6610, copyFromBlock);
