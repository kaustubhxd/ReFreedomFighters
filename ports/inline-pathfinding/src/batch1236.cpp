// batch1236.cpp - pathfinding tree: the find-path context constructors [map 0x52cea0 time-slice member ctor,
// 0x52cf60 CFindPath3Context_packed ctor, 0x52a300 CFindPathContext ctor]. Each one writes a pointer (the time-slice
// control) and clears a dword at +0x49 and a byte at +0x48 of the member; the packed context's default blocks are copied
// from the exe's read-only data (0x6a1568 .. 0x6a1582, 0x6a154c .. 0x6a1564). The writes overlap, so the order is the exe's.
// thiscall, ret 4 (arg: the time-slice control); each returns this.
#include "pf.h"

static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static void copyRd(u8 *dst, u32 src, u32 n) { __builtin_memcpy(dst, (const void *)src, n); }

// 0x52cea0: member ctor (ecx = this, arg = control).
static u8 *THISCALL sliceMemberCtor(u8 *self, u8 *ctl) {
  wr32u(self + 0x44, (u32)ctl);
  wr32u(self + 0x49, 0);
  self[0x48] = 0;
  return self;
}
PCREG(52cea0, sliceMemberCtor);

// 0x52cf60: CFindPath3Context_packed ctor (ecx = this, arg = control).
static u8 *THISCALL cfp3ContextCtor(u8 *self, u8 *ctl) {
  sliceMemberCtor(self, ctl);
  sliceMemberCtor(self + 0x51, ctl);
  copyRd(self + 0x51, 0x6a1568, 16);
  copyRd(self + 0x61, 0x6a1578, 8);
  copyRd(self + 0x69, 0x6a1580, 2);
  copyRd(self + 0x6b, 0x6a1582, 1);
  copyRd(self, 0x6a154c, 16);
  copyRd(self + 0x10, 0x6a155c, 8);
  copyRd(self + 0x18, 0x6a1564, 1);
  return self;
}
PCREG(52cf60, cfp3ContextCtor);

// 0x52a300: CFindPathContext ctor (ecx = this, arg = control). Members at +0 and +0x51 take the control, the packed
// context at +0xa2 is built by 0x52cf60, then the defaults are copied in.
static u8 *THISCALL findPathContextCtor(u8 *self, u8 *ctl) {
  sliceMemberCtor(self, ctl);
  sliceMemberCtor(self + 0x51, ctl);
  cfp3ContextCtor(self + 0xa2, ctl);
  copyRd(self + 0x51, 0x6a0efc, 16);
  copyRd(self + 0x61, 0x6a0f0c, 1);
  copyRd(self, 0x6a0f10, 16);
  copyRd(self + 0x10, 0x6a0f20, 8);
  copyRd(self + 0x18, 0x6a0f28, 1);
  return self;
}
PCREG(52a300, findPathContextCtor);
