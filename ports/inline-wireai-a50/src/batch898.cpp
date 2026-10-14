// batch898.cpp - gap band slice: three byte-flag accessors with an engine-float test (thiscall, one stack arg = index, ret 4, al).
// Each reads the byte at this + 5*idx + off, keeps its result bit, clears its clear-bit if its test-bit is set, and then compares the
// float at the engine object (0x70039c) +0x9c7 with the constant at 0x6785d0: equal (ordered) returns 0, anything else the result bit.
// 0x420380 (FreeActionMap): off 0xf0b, result bit 4, test bit 3 (0x08), clear 0xef.
// 0x4203d0 (InitActionMap): off 0xf0b, result bit 5, test bit 2 (0x04), clear 0xdf.
// 0x420220 (CheckKeyTap):   off 0xa0b, result bit 4, test bit 3 (0x08), clear 0xef.
#include "ff.h"

#define F32(p, o) (*(float *)((u8 *)(p) + (o)))

static u8 FloatGate898(u8 *addr, u8 al, u8 cl) {
  float gf = F32(G(u8 *, 0x70039c), 0x9c7);
  float c = G(float, 0x6785d0);
  if (gf == c) return 0;
  return cl;
}

// 0x420380 (name map: ZSysInterfaceGC::FreeActionMap()).
static u8 THISCALL Free420380(u8 *self, u32 idx) {
  u8 *addr = self + 5 * idx + 0xf0b;
  u8 al = *addr;
  u8 cl = (al >> 4) & 1;
  if (al & 8) *addr = al & 0xef;
  return FloatGate898(addr, al, cl);
}
PCREG(420380, Free420380);

// 0x4203d0 (name map: ZSysInterfaceGC::InitActionMap()).
static u8 THISCALL Init4203d0(u8 *self, u32 idx) {
  u8 *addr = self + 5 * idx + 0xf0b;
  u8 al = *addr;
  u8 cl = (al >> 5) & 1;
  if (al & 4) *addr = al & 0xdf;
  return FloatGate898(addr, al, cl);
}
PCREG(4203d0, Init4203d0);

// 0x420220 (name map: ZSysInterfaceGC::CheckKeyTap(int)).
static u8 THISCALL KeyTap420220(u8 *self, u32 idx) {
  u8 *addr = self + 5 * idx + 0xa0b;
  u8 al = *addr;
  u8 cl = (al >> 4) & 1;
  if (al & 8) *addr = al & 0xef;
  return FloatGate898(addr, al, cl);
}
PCREG(420220, KeyTap420220);
