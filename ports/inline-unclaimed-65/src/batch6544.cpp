// batch6544.cpp - unclaimed-65: batch 44 (docs/20-unclaimed-65.md, claim 24): 0x4d2280, the constructor of the class of claim 23.
// Plain thiscall, no arguments, returns this. The SEH frame and the cookie are not reproduced (tagged in the doc).
#include "ff.h"

extern "C" u32 THISCALL ext_4ccba0(u8 *self);                 // plain, on the object at this+0x4008
extern "C" u32 THISCALL ext_4ccdd0(u8 *self, u32 a, u32 b, u32 c);  // thiscall, three arguments (ret 0xc)

// 0x4d2280, the constructor body.
static u8 *THISCALL classCtor4d2280(u8 *self) {
  *(u32 *)self = 0x696220;
  ext_4ccba0(self + 0x4008);
  ext_4ccdd0(self + 0x40b4, 0, 0x4000, 0x10);
  *(u32 *)(self + 0x4004) = (u32)(self + 4);
  return self;
}

PCREG(4d2280, classCtor4d2280);
