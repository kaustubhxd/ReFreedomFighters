// batch2480.cpp - decomp area 24, batch 2480.
#include "ff.h"

extern "C" void THISCALL ext_43de70(void *self);               // base destructor (recorder)
extern "C" void THISCALL ext_43de40(void *self, u32 a0, u32 a1, u32 a2);  // ZSTDOBJ base constructor, ret 12
extern "C" void ext_4690b0(void *self, u32 state);              // ZRenderGC::SetState (cdecl)
extern "C" void ext_45c510(void *p);                            // ZGEOM::operator delete (cdecl)

static void releaseByFlag(u8 *self, u32 flag, u32 state) {
  if (flag & 1u) {
    if (flag & 4u)
      ext_4690b0(self, state);
    else
      ext_45c510(self);
  }
}

// 0x45b4e0 ~ZBloodSplatters, thiscall, ret 4, eax = this.
static u8 *THISCALL bloodSplattersDtor(u8 *self, u32 flag) {
  *(u32 *)self = 0x684358u;
  ext_43de70(self);
  releaseByFlag(self, flag, 0x650cu);
  return self;
}
PCREG(45b4e0, bloodSplattersDtor);

// 0x45b5d0 (GUESS destructor), thiscall, ret 4, eax = this.
static u8 *THISCALL unnamedDtor45b5d0(u8 *self, u32 flag) {
  *(u32 *)self = 0x684358u;
  ext_43de70(self);
  releaseByFlag(self, flag, 0x258u);
  return self;
}
PCREG(45b5d0, unnamedDtor45b5d0);

// 0x454980 (GUESS constructor), thiscall, ret 12, eax = this.
static u8 *THISCALL stdObjDerivedCtor454980(u8 *self, u32 a0, u32 a1, u32 a2) {
  ext_43de40(self, a0, a1, a2);
  *(u32 *)self = 0x6823a4u;
  *(u32 *)(self + 0x18) = 0;
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 0x20) = 0;
  *(u32 *)(self + 0x28) = 0;
  *(u32 *)(self + 0x34) = 0;
  *(u32 *)(self + 0x2c) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)(self + 0x24) = 0;
  *(u32 *)(self + 0x38) = 0;
  *(u32 *)(self + 0x3c) = 0;
  *(u32 *)(self + 0x40) = 0;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x48) = 0;
  return self;
}
PCREG(454980, stdObjDerivedCtor454980);
