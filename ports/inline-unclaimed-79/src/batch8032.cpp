#include "ff.h"
// batch8032.cpp - residue 18 unported list (docs/20-unclaimed-79.md). Names GUESS (no GC name). Helpers stubbed in spec.

extern "C" void THISCALL ext_469870(u8 *self);     // helper, no args
extern "C" void THISCALL ext_564460(u8 *self);     // helper, no args
extern "C" void THISCALL ext_42bae0(u8 *self);     // helper, no args
extern "C" void ext_634273(u8 *p, u32 n);          // cdecl heap free wrapper

// 0x529ca0 (GUESS): thiscall (ret 4), float argument a. m = this+0x44 * a; this+0x28 = this+8 - m; this+0x2c = this+8 + m.
static void THISCALL f_529ca0(u8 *self, float a) {
  float m = *(float *)(self + 0x44) * a;
  *(float *)(self + 0x28) = *(float *)(self + 0x8) - m;
  *(float *)(self + 0x2c) = m + *(float *)(self + 0x8);
}
PCREG(529ca0, f_529ca0);

// 0x4bb160 (GUESS): thiscall, no args. Calls helper 0x469870, sets this+4 |= 0x20, the word at +0x4c = 0, the dword at +0x44 = 0,
// vtable 0x692c38, the dword at +0x48 = 0. Returns this.
static u8 *THISCALL f_4bb160(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 0x4) |= 0x20u;
  *(u16 *)(self + 0x4c) = 0;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x692c38u;
  *(u32 *)(self + 0x48) = 0;
  return self;
}
PCREG(4bb160, f_4bb160);

// 0x57baa0 (GUESS): thiscall, no args. Calls helper 0x564460, vtable 0x6aa368, the dword at +0x180 = 0x6aa474, the byte at +0x86 = 1.
// Returns this.
static u8 *THISCALL f_57baa0(u8 *self) {
  ext_564460(self);
  *(u32 *)self = 0x6aa368u;
  *(u32 *)(self + 0x180) = 0x6aa474u;
  *(u8 *)(self + 0x86) = 1;
  return self;
}
PCREG(57baa0, f_57baa0);

// 0x42bf60 (GUESS): thiscall (ret 4), argument a. Calls helper 0x42bae0; if bit 0 of a is set calls 0x634273(this, 0x1b71). Returns this.
static u8 *THISCALL f_42bf60(u8 *self, u32 a) {
  ext_42bae0(self);
  if ((a & 1) != 0) ext_634273(self, 0x1b71u);
  return self;
}
PCREG(42bf60, f_42bf60);
