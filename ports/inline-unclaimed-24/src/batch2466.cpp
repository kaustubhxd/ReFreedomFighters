// batch2466.cpp - decomp area 24, batch 2466 (gap band).
#include "ff.h"

extern "C" void THISCALL ext_449d80(void *self);       // base destructor (recorder)
extern "C" void THISCALL ext_43de40(void *self, u32 a0, u32 a1, u32 a2);  // ZSTDOBJ base constructor, ret 12
extern "C" void ext_4690b0(void *self, u32 state);     // ZRenderGC::SetState (cdecl)
extern "C" void ext_45c510(void *p);                   // ZGEOM::operator delete (cdecl)

// 0x449e90 ZLIST::~ZLIST, thiscall, ret 4, eax = this.
static u8 *THISCALL listDtor(u8 *self, u32 flag) {
  ext_449d80(self);
  if (flag & 1u) {
    if (flag & 4u)
      ext_4690b0(self, 0x20u);
    else
      ext_45c510(self);
  }
  return self;
}
PCREG(449e90, listDtor);

// 0x44c8c0 (GUESS), thiscall, ret 12, eax = this.
static u8 *THISCALL stdObjDerivedCtor44c8c0(u8 *self, u32 a0, u32 a1, u32 a2) {
  ext_43de40(self, a0, a1, a2);
  *(u32 *)self = 0x6805dcu;
  *(u32 *)(self + 0x24) = 0;
  *(u32 *)(self + 0x38) = 0;
  *(u32 *)(self + 0x3c) = 0;
  *(u32 *)(self + 0x58) = 0;
  *(u32 *)(self + 0x5c) = 0;
  *(u32 *)(self + 0x78) = 0;
  *(u32 *)(self + 0x7c) = 0;
  *(u32 *)(self + 0x98) = 0;
  *(u32 *)(self + 0x9c) = 0;
  return self;
}
PCREG(44c8c0, stdObjDerivedCtor44c8c0);
