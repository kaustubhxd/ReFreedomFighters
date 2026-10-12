// batch608.cpp - unclaimed-06 claim 8 (docs/20-unclaimed-06.md): CExplode::CopyData(ZEventBase*). Thiscall, one argument,
// ret 4. Names are from the GC name map (naming only). The callee 0x5833e0 is original code (called with two zero arguments).
#include "ff.h"

extern "C" void THISCALL ext_5833e0(u8 *self, u32 a0, u32 a1);   // original code, ecx = this, two arguments

// 0x582690, CExplode::CopyData(ZEventBase*) (high): copies eight fields from src to this (dword at +0x51, +0x55, +0x59, +0x4a;
// word at +0x48, +0x4e; byte at +0x5d, +0x50). Then reads v = [[[this+0x44]+8]+0x3c]; if bit 10 of v is clear and the
// byte at this+0x5d is nonzero, it calls ext_5833e0(this, 0, 0).
static void THISCALL explodeCopyData(u8 *self, u8 *src) {
  *(u32 *)(self + 0x51) = *(u32 *)(src + 0x51);
  *(u32 *)(self + 0x55) = *(u32 *)(src + 0x55);
  *(u32 *)(self + 0x59) = *(u32 *)(src + 0x59);
  self[0x5d] = src[0x5d];
  *(u16 *)(self + 0x48) = *(u16 *)(src + 0x48);
  *(u32 *)(self + 0x4a) = *(u32 *)(src + 0x4a);
  *(u16 *)(self + 0x4e) = *(u16 *)(src + 0x4e);
  self[0x50] = src[0x50];
  u8 *p = *(u8 **)(self + 0x44);
  u8 *q = *(u8 **)(p + 8);
  u32 v = *(u32 *)(q + 0x3c);
  if (!((v >> 10) & 1) && self[0x5d] != 0) {
    ext_5833e0(self, 0, 0);
  }
}
PCREG(582690, explodeCopyData);
