// batch1005.cpp - unclaimed-07 batch 5 (docs/20-unclaimed-07.md, slice 6): ZMovementGuide::Save, the destructor
// ZCollisionBase and CEnemyFlag::Load2. Names from the GC name map (naming only, never committed).
#include "ff.h"

// 0x634273: the CRT free helper (cdecl; original code, not lifted here).
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);
// 0x4690b0: called with this+4 in ECX and no arguments (original code, not lifted here).
extern "C" void THISCALL ext_4690b0(u8 *self);

// 0x489d20, ZMovementGuide::Save(ZSaveGame*) (medium): save slot +0x4c with the float at this+0xc, then slot +0x64 with
// the dword at this+0x375. Returns true (al = 1; ret=None in the spec).
static bool THISCALL movementGuideSave(u8 *self, u8 *save) {
  float f = *(float *)(self + 0xc);
  vcall<void>(save, 0x4c, f);
  vcall<void>(save, 0x64, *(u32 *)(self + 0x375));
  return true;
}
PCREG(489d20, movementGuideSave);

// 0x4eb3e0, ~ZCollisionBase (medium): sets the vtable to 0x697738, calls 0x4690b0 with this+4 in ECX, and when bit 0 of
// the argument is set, calls the CRT free helper 0x634273 with (this, 0x21b1). Returns this.
static u32 THISCALL collisionBaseDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x697738u;
  ext_4690b0(self + 4);
  if (flags & 1)
    ext_634273(self, 0x21b1u);
  return (u32)self;
}
PCREG(4eb3e0, collisionBaseDtor);

// 0x5c1b20, CEnemyFlag::Load2() (high): sys = g_sys (0x70039c); a = sys+0x9b; b = a+0xadc. r = b slot +0x25c(0x685f44, 0).
// When r is non-null, the result of r slot +0x100(0x6a5cf0) is stored at this+0xec. Plain ret.
static void THISCALL enemyFlagLoad2(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  u8 *a = *(u8 **)(sys + 0x9b);
  void *b = *(void **)(a + 0xadc);
  u32 r = vcall<u32>(b, 0x25c, 0x685f44u, 0u);
  if (r)
    *(u32 *)(self + 0xec) = vcall<u32>((void *)r, 0x100, 0x6a5cf0u);
}
PCREG(5c1b20, enemyFlagLoad2);
