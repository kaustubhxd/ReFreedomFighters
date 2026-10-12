// batch2478.cpp - decomp area 24, batch 2478: four destructors (vtable, base, SetState or delete by the flag).
#include "ff.h"

extern "C" void THISCALL ext_43de70(void *self);    // base destructor (recorder)
extern "C" void THISCALL ext_43ea20(void *self);    // base destructor (recorder)
extern "C" void ext_4690b0(void *self, u32 state);  // ZRenderGC::SetState (cdecl)
extern "C" void ext_45c510(void *p);                // ZGEOM::operator delete (cdecl)

static void releaseByFlag(u8 *self, u32 flag, u32 state) {
  if (flag & 1u) {
    if (flag & 4u)
      ext_4690b0(self, state);
    else
      ext_45c510(self);
  }
}

// 0x454ac0 ~ZMaterialDesc, vtable 0x6823a4, base 0x43de70, SetState 0x4c.
static u8 *THISCALL materialDescDtor(u8 *self, u32 flag) {
  *(u32 *)self = 0x6823a4u;
  ext_43de70(self);
  releaseByFlag(self, flag, 0x4cu);
  return self;
}
PCREG(454ac0, materialDescDtor);

// 0x454630 ~ZInstance, vtable 0x6820b8, base 0x43ea20, SetState 0x60.
static u8 *THISCALL instanceDtor(u8 *self, u32 flag) {
  *(u32 *)self = 0x6820b8u;
  ext_43ea20(self);
  releaseByFlag(self, flag, 0x60u);
  return self;
}
PCREG(454630, instanceDtor);

// 0x454670 ~ZTemplate, vtable 0x681df0, base 0x43ea20, SetState 0x5c.
static u8 *THISCALL templateDtor(u8 *self, u32 flag) {
  *(u32 *)self = 0x681df0u;
  ext_43ea20(self);
  releaseByFlag(self, flag, 0x5cu);
  return self;
}
PCREG(454670, templateDtor);

// 0x44e980 ~ZBOXGATEGROUP, vtable 0x680ce4, base 0x43ea20, SetState 0x7d.
static u8 *THISCALL boxGateGroupDtor(u8 *self, u32 flag) {
  *(u32 *)self = 0x680ce4u;
  ext_43ea20(self);
  releaseByFlag(self, flag, 0x7du);
  return self;
}
PCREG(44e980, boxGateGroupDtor);
