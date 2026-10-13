// batch1028.cpp - area 81, batch 1028: 0x476dc0, thiscall(this; n as one stack argument), ret 4, returns this. Array constructor: allocates n*16, n*4 and
// n*4 bytes through the cdecl allocator 0x41e290 (GUESS, stood in) into this+0xc, +0x10 and +0x14 (saturated at 0xffffffff on overflow), then zeroes
// the n dwords of the second and third blocks. The exe's SSE block zeroing and its scalar tail cover the same range; the port zeroes it scalar-wise. No
// SEH frame; the security cookie is not reproduced (the function has none in this range).
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" void *__attribute__((cdecl)) ext_41e290(u32 size);   // GUESS allocator (stood in)

static u32 sizeSat(u32 n, u32 mul) {
  u64 p = (u64)n * mul;
  return p > 0xffffffffu ? 0xffffffffu : (u32)p;
}

// 0x476dc0 (thiscall: this; n).
static u8 *THISCALL arrayConstruct(u8 *self, u32 nArg) {
  D(self, 4) = 0;
  D(self, 8) = nArg;
  D(self, 0) = 0;
  D(self, 0xc) = 0;
  D(self, 0x10) = 0;
  if (nArg == 0)
    return self;
  u32 n = nArg;
  D(self, 0xc) = (u32)(u64)ext_41e290(sizeSat(n, 16));
  D(self, 0x10) = (u32)(u64)ext_41e290(sizeSat(n, 4));
  D(self, 0x14) = (u32)(u64)ext_41e290(sizeSat(n, 4));
  if ((int)n > 0) {
    u32 *a2 = (u32 *)(u64)D(self, 0x10);
    u32 *a3 = (u32 *)(u64)D(self, 0x14);
    for (u32 k = 0; k < n; ++k) {
      a2[k] = 0;
      a3[k] = 0;
    }
  }
  return self;
}
PCREG(476dc0, arrayConstruct);
