// batch944.cpp - area 56 residue 15, claim A3: ZItemWeapon::~ZItemWeapon() (0x46aaf0). thiscall, one stack argument (flags),
// ret 4, returns this. Base and free are unverified callees (GUESS recording stubs in the spec).
#include "ff.h"

extern "C" void THISCALL ext_46a5e0(u8 *self);
extern "C" void ext_4690b0(u8 *p, u32 n);
extern "C" void ext_45c510(u8 *p);

// 0x46aaf0, ZItemWeapon::~ZItemWeapon() (high): base; flags bit 0: bit 2 selects the sized free (0x115), else 0x45c510.
static u8 *THISCALL itemWeaponDtor(u8 *self, u32 flags) {
  ext_46a5e0(self);
  if (flags & 1) {
    if (flags & 4) {
      ext_4690b0(self, 0x115);
    } else {
      ext_45c510(self);
    }
  }
  return self;
}
PCREG(46aaf0, itemWeaponDtor);
