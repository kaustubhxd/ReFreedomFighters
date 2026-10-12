// batch809.cpp - unclaimed-08 batch 9: CHitpointControl::~CHitpointControl() (player health), scalar deleting form.
// Slice: floor(addr/16) mod 20 = 7. Original: this+0x44 = 0, this+0x30 = 0, this[0] = 0x686874, then vtable +0x34 of the
// object at ZSysInterface+0x9b is called with this as its one argument. When flag bit 0 is set and bit 2 is clear, the
// function at *0x7003b0 is called (no argument; not reproduced here: the spec keeps bit 0 clear, a documented gap).
#include "ff.h"

// 0x5817b0, CHitpointControl::~CHitpointControl() (medium name; the body is from the PC bytes). Returns this.
static u8 *THISCALL hitpointControlDtor(u8 *self, u32 flags) {
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  u8 *sys = *(u8 **)0x70039c;
  u8 *child = *(u8 **)(sys + 0x9b);
  vcall<void>(child, 0x34, (void *)self);
  if (flags & 1) {
    if (!(flags & 4)) {
      void (*hook)() = *(void (**)())0x7003b0;
      if (hook) hook();   // original: a null hook traps (int3); the spec never sets it to null
    }
  }
  return self;
}
PCREG(5817b0, hitpointControlDtor);

// 0x5b9430, CFriendlyControl::~CFriendlyControl() (medium name). The PC body is identical to 0x5817b0 (the same stores,
// vtable 0x686874 and the +0x34 call on the engine db; its flag tail is the same too), so the same code serves both.
static u8 *THISCALL friendlyControlDtor(u8 *self, u32 flags) {
  return hitpointControlDtor(self, flags);
}
PCREG(5b9430, friendlyControlDtor);

// 0x4a61b0, ZRequireMatPosSpeed::~ZRequireMatPosSpeed() (medium name). Same template as 0x5817b0 (stores, vtable
// 0x686874, +0x34 call; the flag tail is the same too).
static u8 *THISCALL requireMatPosSpeedDtor(u8 *self, u32 flags) {
  return hitpointControlDtor(self, flags);
}
PCREG(4a61b0, requireMatPosSpeedDtor);

// 0x469670, ZWeaponTest::~ZWeaponTest() (medium name). Same template again.
static u8 *THISCALL weaponTestDtor(u8 *self, u32 flags) {
  return hitpointControlDtor(self, flags);
}
PCREG(469670, weaponTestDtor);
