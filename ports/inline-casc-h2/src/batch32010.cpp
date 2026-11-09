// batch32010.cpp - h2 batch 32010: tier B field writes + external calls
#include "ff.h"

extern "C" void ext_634273(u32 p, u32 size);

// 0x4cd180 FIXED (strict): operator delete(p = [this+4], size = 8)
static void THISCALL fn4cd180(u8 *self) {
  *(u32 *)self = 0x695b78;
  u32 val = *(u32 *)(self + 4);
  ext_634273(val, 8);
}
PCREG(4cd180, fn4cd180);
