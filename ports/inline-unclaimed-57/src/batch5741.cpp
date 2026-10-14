// batch5741.cpp - unclaimed-57, band batch 41 (name GUESS): 0x5de900, thiscall, one stack arg (rec), ret 4. A list of 40-byte records,
// count = dword this+0, E = this + 40*count. Writes E+4 = rec[0..4), E+8 = rec[4..8), E+0xc = rec[8..12). If rec+0xc is not E+0x10 (the
// address), E+0x10 = dword (rec+0xc). Then E+0x14 = rec[0x10], E+0x18 = rec[0x14], E+0x1c = rec[0x18], E+0x20 = rec[0x1c], E+0x24 = rec[0x20],
// E+0x28 = rec[0x24]; count = count + 1. No calls.
#include "ff.h"

static void THISCALL unnamed5de900(u8 *self, u8 *rec) {
  u32 n = *(u32 *)self;
  u8 *e = self + 40 * n;
  *(u32 *)(e + 4) = *(u32 *)(rec + 0);
  *(u32 *)(e + 8) = *(u32 *)(rec + 4);
  *(u32 *)(e + 0xc) = *(u32 *)(rec + 8);
  if (rec + 0xc != e + 0x10) *(u32 *)(e + 0x10) = *(u32 *)(rec + 0xc);
  *(u32 *)(e + 0x14) = *(u32 *)(rec + 0x10);
  *(u32 *)(e + 0x18) = *(u32 *)(rec + 0x14);
  *(u32 *)(e + 0x1c) = *(u32 *)(rec + 0x18);
  *(u32 *)(e + 0x20) = *(u32 *)(rec + 0x1c);
  *(u32 *)(e + 0x24) = *(u32 *)(rec + 0x20);
  *(u32 *)(e + 0x28) = *(u32 *)(rec + 0x24);
  *(u32 *)self = *(u32 *)self + 1;
}
PCREG(5de900, unnamed5de900);
