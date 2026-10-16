// batch5780.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 80: 0x5c2d90 (GUESS name unnamed_5c2d90), thiscall, three stack arguments
// (a1, out, idx; ret 0xc), returns al. Order: 0x5c2ec0(this); 0x5c2f90(this); if a1 != 0: r = 0x5c2e10(this, a1); if r != 0: x = 0x5c2cb0(ECX = r);
// *idx = x (before the test); if x != -1: out[1] = dword this+14x+8; out[0] = dword this+0; 0x5c2f30(this); return 1. Otherwise out[1] = out[0] = 0; return 0.
// The five callees run as hooked stubs in the spec (0x5c2ec0, 0x5c2f90 and 0x5c2f30 are ported separately in this area).
#include "ff.h"

extern "C" void THISCALL ext_5c2ec0(u8 *self);  // original code (hooked in the spec)
extern "C" void THISCALL ext_5c2f90(u8 *self);  // original code (hooked in the spec)
extern "C" void THISCALL ext_5c2f30(u8 *self);  // original code (hooked in the spec)
extern "C" u32 THISCALL ext_5c2e10(u8 *self, u32 a);  // original code (hooked in the spec)
extern "C" s32 THISCALL ext_5c2cb0(u8 *self);  // original code (hooked in the spec)

// 0x5c2d90, thiscall, three stack arguments (GUESS name)
static u8 THISCALL unnamed5c2d90(u8 *self, u32 a1, u8 *out, s32 *idx) {
  ext_5c2ec0(self);
  ext_5c2f90(self);
  if (a1 != 0) {
    u32 r = ext_5c2e10(self, a1);
    if (r != 0) {
      s32 x = ext_5c2cb0((u8 *)(unsigned long)r);
      *idx = x;
      if (x != -1) {
        u32 off = (u32)x * 14u + 8u;
        *(u32 *)(out + 4) = *(u32 *)(self + off);
        *(u32 *)out = *(u32 *)self;
        ext_5c2f30(self);
        return 1;
      }
    }
  }
  *(u32 *)(out + 4) = 0;
  *(u32 *)out = 0;
  return 0;
}
PCREG(5c2d90, unnamed5c2d90);
