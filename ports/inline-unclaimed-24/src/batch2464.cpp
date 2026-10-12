// batch2464.cpp - decomp area 24, batch 2464 (gap band).
#include "ff.h"

extern "C" void THISCALL ext_447690(void *self);   // base destructor (recorder)
extern "C" void THISCALL ext_447750(void *self);   // base destructor (recorder)
extern "C" void THISCALL ext_447810(void *self);   // base destructor (recorder)
extern "C" void ext_4690b0(void *self, u32 state); // ZRenderGC::SetState (cdecl)
extern "C" void ext_45c510(void *p);               // ZGEOM::operator delete (cdecl)

// Shared tail: flag bit 0 -> bit 2 ? SetState(self, 0x20) : operator delete(self).
static void releaseByFlag(u8 *self, u32 flag) {
  if (flag & 1u) {
    if (flag & 4u)
      ext_4690b0(self, 0x20u);
    else
      ext_45c510(self);
  }
}

// 0x447980 ~ZGateLightMaster, thiscall, ret 4, eax = this.
static u8 *THISCALL gateLightMasterDtor(u8 *self, u32 flag) {
  ext_447690(self);
  releaseByFlag(self, flag);
  return self;
}
PCREG(447980, gateLightMasterDtor);

// 0x4479c0 ~ZGateLightSpotMaster, thiscall, ret 4, eax = this.
static u8 *THISCALL gateLightSpotMasterDtor(u8 *self, u32 flag) {
  ext_447750(self);
  releaseByFlag(self, flag);
  return self;
}
PCREG(4479c0, gateLightSpotMasterDtor);

// 0x447a90 ~ZGateLightSquareSpotMaster, thiscall, ret 4, eax = this.
static u8 *THISCALL gateLightSquareSpotMasterDtor(u8 *self, u32 flag) {
  ext_447810(self);
  releaseByFlag(self, flag);
  return self;
}
PCREG(447a90, gateLightSquareSpotMasterDtor);
