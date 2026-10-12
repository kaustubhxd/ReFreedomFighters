// batch614.cpp - unclaimed-06 claims 14 and 15 (docs/20-unclaimed-06.md): two destructors (medium names). Thiscall, one
// argument (flags), ret 4, both return this. All callees are stubbed in the harness (GUESS).
#include "ff.h"

extern "C" void THISCALL ext_480fd0(u8 *self);    // member destructor, stubbed (GUESS), ecx = member
extern "C" void THISCALL ext_4878d0(u8 *self);    // member destructor, stubbed (GUESS), ecx = this
extern "C" void THISCALL ext_43de70(u8 *self);    // base destructor, stubbed (GUESS), ecx = this
extern "C" void ext_45c510(void *p);              // cdecl delete helper, stubbed (GUESS)
extern "C" void ext_4690b0(void *p, u32 n);       // cdecl array delete helper, stubbed (GUESS)
extern "C" void ext_634273(void *p, u32 n);       // CRT operator delete, cdecl, stubbed (GUESS)

// 0x5e1690, ZFFHeroMovementRaiseFlag::~ZFFHeroMovementRaiseFlag() (high): stores the vtable 0x6b77b4 at this, calls the
// member destructor 0x480fd0 on this+0x523, this+0x4ab, this+0x3eb and this+0x3d3, calls 0x4878d0 on this, then if bit 0
// of the flags is set calls ext_634273(this, 0x5cd). Returns this.
static u8 *THISCALL raiseFlagDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x6b77b4;
  ext_480fd0(self + 0x523);
  ext_480fd0(self + 0x4ab);
  ext_480fd0(self + 0x3eb);
  ext_480fd0(self + 0x3d3);
  ext_4878d0(self);
  if ((u8)flags & 1) {
    ext_634273(self, 0x5cd);
  }
  return self;
}
PCREG(5e1690, raiseFlagDtor);

// 0x44e710, ZBOUND::~ZBOUND() (high): stores the vtable 0x680abc at this, calls the base destructor 0x43de70 on this, then if
// bit 0 of the flags is set: bit 2 set calls ext_4690b0(this, 0x18), bit 2 clear calls ext_45c510(this). Returns this.
static u8 *THISCALL zboundDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x680abc;
  ext_43de70(self);
  u8 f = (u8)flags;
  if (f & 1) {
    if (f & 4) {
      ext_4690b0(self, 0x18);
    } else {
      ext_45c510(self);
    }
  }
  return self;
}
PCREG(44e710, zboundDtor);
