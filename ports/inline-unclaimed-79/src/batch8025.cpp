#include "ff.h"
// batch8025.cpp - unclaimed core row (docs/20-unclaimed-79.md). Name GUESS (no GC name). SEH frame not reproduced (fs:[0] writes not compared).

extern "C" void THISCALL ext_480980(u8 *self);   // stubbed in spec

// 0x4876e0 (GUESS): thiscall (ret 8). Constructor-like: vtable 0x68d018; fields a (+4) and b (+0x10); zeroes, calls 0x480980 on
// this+0x25, +0x3d, +0x55; clears the dwords at +0x21 and +0x1d; returns this.
static u8 *THISCALL f_4876e0(u8 *self, u32 a, u32 b) {
  *(u32 *)(self + 0x10) = b;
  *(u8 *)(self + 0x1c) = 1;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x14) = 0;
  *(u32 *)(self + 0x18) = 0;
  *(u32 *)(self + 0x4) = a;
  *(u32 *)(self + 0x8) = 0;
  *(u32 *)self = 0x68d018;
  *(u32 *)(self + 0x1d) = 0;
  ext_480980(self + 0x25);
  ext_480980(self + 0x3d);
  ext_480980(self + 0x55);
  *(u32 *)(self + 0x21) = 0;
  *(u32 *)(self + 0x1d) = 0;
  return self;
}
PCREG(4876e0, f_4876e0);
