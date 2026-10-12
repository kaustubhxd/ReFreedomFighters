#include "ff.h"
// batch8028.cpp - unclaimed core row, parked then resumed (docs/20-unclaimed-79.md). Name GUESS (no GC name). Helper stubbed.

extern "C" void THISCALL ext_462640(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4);   // stubbed in spec

// 0x483300 (GUESS): thiscall (ret 0x10), arguments a1..a4.
static void THISCALL f_483300(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4) {
  u8 L[0x60];
  u8 *E = L + 0x50;
  ext_462640(self, a1, a2, a3, a4);
  if (*(u8 *)(self + 0x601) == 0) return;
  vcall<void, u32, u32>(self, 0x59c, (u32)(unsigned long)(E - 0x4c), (u32)(unsigned long)(E - 0x28));
  u32 v20 = *(u32 *)(E - 0x20);
  u64 q28 = *(u64 *)(E - 0x28);
  *(u32 *)(E - 0x14) = v20;
  *(u32 *)(E - 0x8) = v20;
  *(u64 *)(E - 0x1c) = q28;
  *(u64 *)(E - 0x10) = q28;
  vcall<void, u32, u32>((u8 *)(unsigned long)a2, 0x94, (u32)(unsigned long)(E - 0x4c), (u32)(unsigned long)(E - 0x28));
  vcall<void, u32, u32, u32>((u8 *)(unsigned long)a1, 0x88, (u32)(unsigned long)(E - 0x4c), (u32)(unsigned long)(E - 0x28), (u32)(unsigned long)(self + 0x439));
  *(float *)(E - 0x18) = *(float *)(E - 0x18) - *(float *)(self + 0x43d);
  *(float *)(E - 0xc) = *(float *)(E - 0xc) - *(float *)(self + 0x451);
  vcall<void, u32>((u8 *)(unsigned long)a2, 0x8c, (u32)(unsigned long)(E - 0x1c));
  vcall<void, u32>((u8 *)(unsigned long)a2, 0x8c, (u32)(unsigned long)(E - 0x10));
  vcall<void, u32, u32, u32>((u8 *)(unsigned long)a1, 0x90, (u32)(unsigned long)(E - 0x1c), (u32)(unsigned long)(E - 0x10), 0x2du);
}
PCREG(483300, f_483300);
