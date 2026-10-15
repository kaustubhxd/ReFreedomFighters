// batch32077.cpp - cascade h2 (Sonnet): 0x425240 (import call to bool), five vtable-slot thunks (0x466f40, 0x467400, 0x4ce510, 0x566e30, 0x4cbdc0).
#include "ff.h"

typedef u32 (*imp0_t)();

// 0x425240, no args: (import at 0x67606c)() != 0.
static bool fn425240() {
  return G(imp0_t, 0x67606c)() != 0;
}
PCREG(425240, fn425240);

// 0x466f40 / 0x467400, thiscall no args: slot 0x2b4 of this with the constant 0x16 / 0xa.
static u32 THISCALL fn466f40(void *self) { return vcall<u32>(self, 0x2b4, 0x16u); }
PCREG(466f40, fn466f40);
static u32 THISCALL fn467400(void *self) { return vcall<u32>(self, 0x2b4, 0xau); }
PCREG(467400, fn467400);

// 0x4ce510: slot 8 of this with 0.  0x566e30: slot 0xd0 of this with 0.
static u32 THISCALL fn4ce510(void *self) { return vcall<u32>(self, 8, 0u); }
PCREG(4ce510, fn4ce510);
static u32 THISCALL fn566e30(void *self) { return vcall<u32>(self, 0xd0, 0u); }
PCREG(566e30, fn566e30);

// 0x4cbdc0: o = [this+0x44]; slot 0x3c of o with 1.
static u32 THISCALL fn4cbdc0(u8 *self) {
  void *o = *(void **)(self + 0x44);
  return vcall<u32>(o, 0x3c, 1u);
}
PCREG(4cbdc0, fn4cbdc0);
