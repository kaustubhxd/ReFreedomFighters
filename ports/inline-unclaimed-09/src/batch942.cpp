// batch942.cpp - area 56 residue 15 (docs/20-unclaimed-56.md, claim A1): two scalar deleting destructors.
// thiscall, one stack argument (the flags), ret 4, returns this in eax. The base destructors and the free are unverified
// callees (GUESS recording stubs in the spec).
#include "ff.h"

extern "C" void THISCALL ext_51aa60(u8 *self);            // base destructor of ZCarIf (stubbed)
extern "C" void THISCALL ext_506360(u8 *self);            // base destructor of ZFFActorIf (stubbed)
extern "C" void ext_634273(u8 *p, u32 n);                 // cdecl free (stubbed)

// 0x51b030, ZCarIf::~ZCarIf() (high): vtable 0x69f43c; base destructor; frees with size 0x20 when bit 0 of the flags is set.
static u8 *THISCALL carIfDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x69f43c;
  ext_51aa60(self);
  if (flags & 1) ext_634273(self, 0x20);
  return self;
}
PCREG(51b030, carIfDtor);

// 0x557b70, ZFFActorIf::~ZFFActorIf() (high): vtable 0x6a5e2c; base destructor; frees with size 0x20 when bit 0 is set.
static u8 *THISCALL ffActorIfDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x6a5e2c;
  ext_506360(self);
  if (flags & 1) ext_634273(self, 0x20);
  return self;
}
PCREG(557b70, ffActorIfDtor);
