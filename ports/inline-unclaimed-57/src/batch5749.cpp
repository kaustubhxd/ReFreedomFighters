// batch5749.cpp - unclaimed-57, band batch 49 (name GUESS): 0x5c3000, thiscall, no args, ret. Stores first: byte this+0x125 = 0; byte
// this+0x114 = 1; dword this+0x11d, +0x121, +0x119, +0x115 = 0. Then this->vt[+0x68](0x10, 0) (thiscall, two args; stubbed). Then by the byte
// b = this+0xf4: b == 0: byte this+0x114 = 1 and 0x5c3560(this, 1, 1); b == 1: 0x5c3560(this, 0, 1) and byte this+0x114 = 0; b == 2: byte
// this+0x114 = 1, this+0x115 = float(dword engine+0x40) * (float 0x6785e4) (engine = dword 0x70039c), then this->vt[+0x64](0x10); other: nothing.
// 0x5c3560 is an unverified callee (hooked and logged in the spec; it pops 8).
#include "ff.h"

#define VT(o) (*(void ***)(o))
#define G(T, addr) (*(T *)(addr))

typedef void(THISCALL *Slot1)(u8 *self, u32 a);
typedef void(THISCALL *Slot2)(u8 *self, u32 a, u32 b);

extern "C" void THISCALL ext_5c3560(u8 *self, u32 a, u32 b);  // unverified, original code (hooked and logged in the spec)

static void THISCALL unnamed5c3000(u8 *self) {
  self[0x125] = 0;
  self[0x114] = 1;
  *(u32 *)(self + 0x11d) = 0;
  *(u32 *)(self + 0x121) = 0;
  *(u32 *)(self + 0x119) = 0;
  *(u32 *)(self + 0x115) = 0;
  ((Slot2)VT(self)[0x68 / 4])(self, 0x10, 0);
  u8 b = self[0xf4];
  if (b == 0) {
    self[0x114] = 1;
    ext_5c3560(self, 1, 1);
  } else if (b == 1) {
    ext_5c3560(self, 0, 1);
    self[0x114] = 0;
  } else if (b == 2) {
    self[0x114] = 1;
    u8 *engine = G(u8 *, 0x70039c);
    *(float *)(self + 0x115) = (float)(s32)*(u32 *)(engine + 0x40) * G(float, 0x6785e4);
    ((Slot1)VT(self)[0x64 / 4])(self, 0x10);
  }
}
PCREG(5c3000, unnamed5c3000);
