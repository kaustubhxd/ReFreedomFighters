// batch315.cpp - 0x52a1e0 (area 43, 2026-10-12). thiscall (this = ECX), no stack arguments, ret 0.
// Body: stores 500.0f at this+0x29, -500.0f at this+0x2d and 0 at this+0x31 (unaligned dwords).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static void THISCALL setBounds500(u8 *self) {
  U32(self, 0x29) = 0x43fa0000u;
  U32(self, 0x2d) = 0xc3fa0000u;
  U32(self, 0x31) = 0u;
}
PCREG(52a1e0, setBounds500);
