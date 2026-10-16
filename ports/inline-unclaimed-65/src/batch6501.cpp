// batch6501.cpp - unclaimed-65: batch 1 (docs/20-unclaimed-65.md, claim 1). Thiscall with one stack flag argument (ret 4).
// Callees are original code (ext_); the harness replaces them with logging stubs.
#include "ff.h"

// thiscall, no arguments
extern "C" void THISCALL ext_43de70(u8 *self);
extern "C" void THISCALL ext_480fd0(u8 *self);
extern "C" void THISCALL ext_4878d0(u8 *self);
// cdecl
extern "C" void ext_45c510(u8 *self);
extern "C" void ext_4690b0(u8 *self, u32 size);
extern "C" void ext_634273(void *p, u32 size);

// 0x573760, ZMapHelper::~ZMapHelper() (residue 18 name): base destructor; when bit 0 of the flag is set, a bit-2 flag selects
// 0x4690b0(this, 0x2c) and otherwise 0x45c510(this). Returns this.
static u8 *THISCALL mapHelperDtor(u8 *self, u32 flags) {
  ext_43de70(self);
  if ((u8)flags & 1) {
    if ((u8)flags & 4)
      ext_4690b0(self, 0x2c);
    else
      ext_45c510(self);
  }
  return self;
}
PCREG(573760, mapHelperDtor);

// 0x5e1390, ZFFHeroMovementCloseCombat::~ZFFHeroMovementCloseCombat() (residue 17): vtable := 0x6b7748; member destructors at
// +0x523, +0x4ab, +0x3eb, +0x3d3; base destructor; operator delete of 0x611 bytes when bit 0 of the flag is set. Returns this.
static u8 *THISCALL closeCombatDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x6b7748;
  ext_480fd0(self + 0x523);
  ext_480fd0(self + 0x4ab);
  ext_480fd0(self + 0x3eb);
  ext_480fd0(self + 0x3d3);
  ext_4878d0(self);
  if ((u8)flags & 1) ext_634273(self, 0x611);
  return self;
}
PCREG(5e1390, closeCombatDtor);
