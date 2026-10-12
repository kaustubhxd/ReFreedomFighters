// batch225.cpp - small leaves, slices 0/1. Names GUESS (0x50a640 dtor by its vtable shape). Callees stubbed in the harness.
#include "ff.h"

extern "C" void ext_634273(u8 *p, u32 n);                 // original release, cdecl (stubbed; stores its words)
extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 zero);             // original, thiscall, one stack word, ret 4 (stubbed)
extern "C" void THISCALL ext_5002f0(u8 *self, u32 word);      // original, thiscall, one stack word, ret 4: stores it in [self] (stubbed)

// 0x5ebf00, thiscall(): [this+0xa6] = 1 (byte).
static void THISCALL setFlagA6_5ebf00(u8 *self) { *(u8 *)(self + 0xa6) = 1; }
PCREG(5ebf00, setFlagA6_5ebf00);

// 0x50a640, thiscall(flags) (ret 4): [this] = vtable 0x69c968; if flags & 1: ext_634273(this, 0xc); returns this.
static u8 *THISCALL dtor_50a640(u8 *self, u32 flags) {
  *(u32 *)self = 0x69c968u;
  if (flags & 1) ext_634273(self, 0xc);
  return self;
}
PCREG(50a640, dtor_50a640);

// 0x55f640, thiscall(a) (ret 4): the exe pushes this->[0x18]->[0x684] and then 0; 0x5003d0 (ret 4) pops the 0 and returns
// r; 0x5002f0 (ret 4) then pops the pushed word and stores it into [r]. So: r = 0x5003d0(ecx = a->[8], 0); 0x5002f0(ecx = r, word).
static void THISCALL lookupStore_55f640(u8 *self, u8 *a) {
  u8 *e = *(u8 **)(self + 0x18);
  u8 *p = *(u8 **)(a + 8);
  u8 *r = ext_5003d0(p, 0);
  ext_5002f0(r, *(u32 *)(e + 0x684));
}
PCREG(55f640, lookupStore_55f640);
