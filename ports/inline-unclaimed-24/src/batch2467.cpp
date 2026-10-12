// batch2467.cpp - decomp area 24, batch 2467 (gap band).
#include "ff.h"

extern "C" void THISCALL ext_43e990(void *self, u32 a0, u32 a1, u32 a2);  // ZGROUP base constructor, ret 12
extern "C" void THISCALL ext_43de40(void *self, u32 a0, u32 a1, u32 a2);  // ZSTDOBJ base constructor, ret 12
extern "C" void THISCALL ext_43de70(void *self);                            // base destructor (recorder)
extern "C" void ext_4690b0(void *self, u32 state);                          // ZRenderGC::SetState (cdecl)
extern "C" void ext_45c510(void *p);                                        // ZGEOM::operator delete (cdecl)

// 0x44e900 (GUESS), thiscall, ret 12, eax = this.
static u8 *THISCALL groupDerivedCtor44e900(u8 *self, u32 a0, u32 a1, u32 a2) {
  ext_43e990(self, a0, a1, a2);
  *(u32 *)self = 0x680ce4u;
  *(u32 *)(self + 0x5c) = 0;
  *(u32 *)(self + 0x60) = 0;
  *(u32 *)(self + 0x64) = 0;
  *(u32 *)(self + 0x68) = 0;
  *(u32 *)(self + 0x6c) = 0;
  *(u32 *)(self + 0x70) = 0;
  *(u32 *)(self + 0x74) = 0;
  *(u32 *)(self + 0x78) = 0;
  self[0x7c] = 0;
  return self;
}
PCREG(44e900, groupDerivedCtor44e900);

// 0x45a530 (GUESS), thiscall, ret 12, eax = this. 1.0f is 0x3f800000; the dword stores overlap as in the exe.
static u8 *THISCALL stdObjDerivedCtor45a530(u8 *self, u32 a0, u32 a1, u32 a2) {
  ext_43de40(self, a0, a1, a2);
  *(u32 *)self = 0x683bacu;
  *(u32 *)(self + 0x24) = 0;
  *(u32 *)(self + 0x28) = 0;
  *(u32 *)(self + 0x18) = 0x3f800000u;
  *(u32 *)(self + 0x1c) = 0x3f800000u;
  *(u32 *)(self + 0x20) = 0x3f800000u;
  *(u16 *)(self + 0x2c) = 0x100;
  *(u32 *)(self + 0x33) = 0;
  *(u32 *)(self + 0x2f) = 0xffffffu;
  self[0x2e] = 0;
  return self;
}
PCREG(45a530, stdObjDerivedCtor45a530);

// 0x45ae40 ~ZBoxPrimitive, thiscall, ret 4, eax = this.
static u8 *THISCALL boxPrimitiveDtor(u8 *self, u32 flag) {
  ext_43de70(self);
  if (flag & 1u) {
    if (flag & 4u)
      ext_4690b0(self, 0x24u);
    else
      ext_45c510(self);
  }
  return self;
}
PCREG(45ae40, boxPrimitiveDtor);
