// batch5740.cpp - unclaimed-57, band batch 40 (name GUESS): 0x5e0f80, thiscall, two stack args (a, b), ret 8, returns this.
// Calls 0x5e0e10(this, a, b) (the hero movement-base constructor family; run as original code, its own callees hooked the same way as in
// area 10 batch 6: operator new 0x41e290 is hooked in the spec). Then: vtable 0x6b7748; dword this+0x60c = 0; dword this+0x5d2 = 0;
// dword this+0x608 = 0; byte this+0x5ac = 0; dword this+0x5b1 = 0; dword this+0x5ad = 0; byte this+0x610 = 0.
#include "ff.h"

extern "C" u8 *THISCALL ext_5e0e10(u8 *self, u8 *a, u32 b);  // original code (new hooked in the spec)

static u8 *THISCALL unnamed5e0f80(u8 *self, u32 a, u32 b) {
  ext_5e0e10(self, (u8 *)(unsigned long)a, b);
  *(u32 *)self = 0x6b7748;
  *(u32 *)(self + 0x60c) = 0;
  *(u32 *)(self + 0x5d2) = 0;
  *(u32 *)(self + 0x608) = 0;
  self[0x5ac] = 0;
  *(u32 *)(self + 0x5b1) = 0;
  *(u32 *)(self + 0x5ad) = 0;
  self[0x610] = 0;
  return self;
}
PCREG(5e0f80, unnamed5e0f80);
