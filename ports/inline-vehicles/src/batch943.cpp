// batch943.cpp - vehicles thread, batch 943: ZVehicle::CopyDataBlock(DBLK*), 0x515790, callee pops 4.
// The base class copy (0x512850, stood in) runs first. The block's type (0x4e1600, exe code) decides: type 3 reads the
// flag into +0x21a (0x4e14a0, stood in), then the block is finished (0x4e1b30, stood in).
#include "ff.h"

extern "C" void THISCALL ext_512850(void *self, void *dblk);       // ZMoveOnSpline::CopyDataBlock (stood in)
extern "C" u32 THISCALL ext_4e1600(void *dblk);                    // DBLK type (exe, pure)
extern "C" void THISCALL ext_4e14a0(void *dblk, u8 *out, u32 n);   // DBLK read into out (stood in)
extern "C" void THISCALL ext_4e1b30(void *dblk);                   // DBLK finish (stood in)

// 0x515790 ZVehicle::CopyDataBlock(DBLK*).
static void THISCALL vehCopyDataBlock(u8 *s, void *dblk) {
  ext_512850(s, dblk);
  if ((u8)ext_4e1600(dblk) == 3)
    ext_4e14a0(dblk, s + 0x21a, 1);
  ext_4e1b30(dblk);
}
PCREG(515790, vehCopyDataBlock);
