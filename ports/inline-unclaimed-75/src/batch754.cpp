// batch754.cpp - unclaimed area 75 (docs/20-unclaimed-75.md), slice floor(addr/16) mod 20 == 13.
#include "ff.h"

extern "C" void THISCALL ext_478ea0(u8 *self, u32 a, u32 b);   // original, thiscall (ecx = a), two stack words, ret 8

typedef u32(THISCALL *VtThree)(u8 *, u32, u32, u32);   // vt[0x628]: this, then three stack words (2, 0, 0)
typedef u32(THISCALL *VtNoArg)(u8 *);

// 0x47bf10, thiscall(a, b) ret 8. If [this+0x695] != 0: this->vt[0x628](this, 2, 0, 0). Then [this+0x695] = a and
// [this+0x722] = 0, and 478ea0 with ecx = a and stack words (this+0x660, 0). Then [this+0x678] = 0x42c80000, byte
// [this+0x726] = 1, dword [this+0x732] = 0, byte [this+0x72f] = 0, byte [this+0x699] = 0, and byte [this+0x6fe] = 0 when
// the low byte of b is nonzero. Finally this->vt[0x5f4](this) and this->vt[0x5f8](this). Name GUESS.
static void THISCALL resetWithArg_47bf10(u8 *self, u32 a, u32 b) {
  if (*(u32 *)(self + 0x695) != 0) {
    VtThree f628 = (VtThree)(*(u32 *)(*(u32 *)self + 0x628));
    f628(self, 2u, 0u, 0u);
  }
  *(u32 *)(self + 0x695) = a;
  *(u32 *)(self + 0x722) = 0;
  ext_478ea0((u8 *)a, (u32)(self + 0x660), 0u);
  *(u32 *)(self + 0x678) = 0x42c80000u;
  self[0x726] = 1;
  *(u32 *)(self + 0x732) = 0;
  self[0x72f] = 0;
  self[0x699] = 0;
  if ((u8)b != 0) self[0x6fe] = 0;
  VtNoArg f5f4 = (VtNoArg)(*(u32 *)(*(u32 *)self + 0x5f4));
  f5f4(self);
  VtNoArg f5f8 = (VtNoArg)(*(u32 *)(*(u32 *)self + 0x5f8));
  f5f8(self);
}
PCREG(47bf10, resetWithArg_47bf10);
