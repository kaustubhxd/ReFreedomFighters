// batch2475.cpp - decomp area 24, batch 2475.
#include "ff.h"

extern "C" void THISCALL ext_43de70(void *self);            // base destructor (recorder)
extern "C" void ext_4690b0(void *self, u32 state);           // ZRenderGC::SetState (cdecl)
extern "C" void ext_45c510(void *p);                          // ZGEOM::operator delete (cdecl)
extern "C" void THISCALL ext_4dcdf0(void *self, u32 prim);    // ZBaseGeom::SetPrim(unsigned int)

// 0x44c410 Z2DOBJ::~Z2DOBJ, thiscall, ret 4, eax = this.
static u8 *THISCALL z2dObjDtor(u8 *self, u32 flag) {
  *(u32 *)self = 0x67ff2cu;
  ext_43de70(self);
  if (flag & 1u) {
    if (flag & 4u)
      ext_4690b0(self, 0x19u);
    else
      ext_45c510(self);
  }
  return self;
}
PCREG(44c410, z2dObjDtor);

// 0x4495b0 ZLIGHT::MakeLightUnique(), thiscall, plain ret.
static void THISCALL lightMakeLightUnique(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  u8 *A = *(u8 **)(sys + 0x1aa3);
  void *B = *(void **)(A + 0x18);
  u8 *geom = *(u8 **)(self + 8);
  u8 r = vcall<u8>(B, 0x18, *(u32 *)(geom + 0x6c));
  if (r == 0) {
    geom = *(u8 **)(self + 8);
    u32 prim = vcall<u32>(B, 0x6c, *(u32 *)(geom + 0x6c), 0u);
    ext_4dcdf0(*(void **)(self + 8), prim);  // the exe reloads esi to the geometry before SetPrim
  }
}
PCREG(4495b0, lightMakeLightUnique);
