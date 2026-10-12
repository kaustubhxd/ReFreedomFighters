// batch6373.cpp - unclaimed-63 batch 73: 0x517630 ZCar::CopyDataBlock(DBLK*) (core list name), thiscall, one stack argument s, ret 4.
//   0x515790(this, s) (ZVehicle::CopyDataBlock, verified in batch 72: the original code runs in the checker); 0x4e11e0(s; this+0x160c, 1)
//   (thiscall, two arguments, ret 8); 0x4e12f0(s; this+0x1610, 1) (thiscall, two arguments, ret 8); 0x4e1b30(s) (thiscall, plain ret).
#include "ff.h"

extern "C" void THISCALL ext_515790(void *self, u32 s);       // ZVehicle::CopyDataBlock (batch 72; original code here)
extern "C" void THISCALL ext_4e11e0(void *s, u32 p, u32 one); // thiscall, two arguments, ret 8, stubbed
extern "C" void THISCALL ext_4e12f0(void *s, u32 p, u32 one); // thiscall, two arguments, ret 8, stubbed
extern "C" void THISCALL ext_4e1b30(void *s);                 // thiscall, plain ret, stubbed

// 0x517630.
static void THISCALL unnamed517630(u8 *self, u32 s) {
  ext_515790((void *)self, s);
  ext_4e11e0((void *)s, (u32)(self + 0x160c), 1u);
  ext_4e12f0((void *)s, (u32)(self + 0x1610), 1u);
  ext_4e1b30((void *)s);
}
PCREG(517630, unnamed517630);
