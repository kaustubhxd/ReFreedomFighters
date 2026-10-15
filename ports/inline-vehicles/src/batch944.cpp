// batch944.cpp - vehicles thread, batch 944: ZCar::CopyDataBlock (0x517630) and ZTank::CopyDataBlock (0x520ad0), both
// callee pops 4. The vehicle copy (0x515790, exe code run as is) comes first; then the reads of the car's
// +0x160c and +0x1610 (ZCar) or the tank's +0x25d5 and +0x25d9 (ZTank) through 0x4e11e0 / 0x4e12f0 / 0x4e12e0, and the
// block finish (0x4e1b30). Those reads and the finish are stood in by the spec.
#include "ff.h"

extern "C" void THISCALL ext_515790(void *self, void *dblk);       // ZVehicle::CopyDataBlock (exe)
extern "C" void THISCALL ext_4e11e0(void *dblk, u32 *out, u32 n);  // DBLK read (stood in)
extern "C" void THISCALL ext_4e12f0(void *dblk, u32 *out, u32 n);  // DBLK read (stood in)
extern "C" void THISCALL ext_4e12e0(void *dblk, u32 *out, u32 n);  // DBLK read (stood in)
extern "C" void THISCALL ext_4e1b30(void *dblk);                   // DBLK finish (stood in)

// 0x517630 ZCar::CopyDataBlock(DBLK*).
static void THISCALL carCopyDataBlock(u8 *s, void *dblk) {
  ext_515790(s, dblk);
  ext_4e11e0(dblk, (u32 *)(s + 0x160c), 1);
  ext_4e12f0(dblk, (u32 *)(s + 0x1610), 1);
  ext_4e1b30(dblk);
}
PCREG(517630, carCopyDataBlock);

// 0x520ad0 ZTank::CopyDataBlock(DBLK*).
static void THISCALL tankCopyDataBlock(u8 *s, void *dblk) {
  ext_515790(s, dblk);
  ext_4e12e0(dblk, (u32 *)(s + 0x25d5), 1);
  ext_4e12e0(dblk, (u32 *)(s + 0x25d9), 1);
  ext_4e1b30(dblk);
}
PCREG(520ad0, tankCopyDataBlock);
