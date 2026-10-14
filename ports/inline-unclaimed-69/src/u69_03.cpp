// u69_03.cpp - area 69, group 3 (unclaimed-69 thread): two scalar deleting destructors. Base destructors and ZGEOM::operator
// delete are other areas' code (stubbed in the spec, labelled GUESS). 0x4690b0 is a 1-byte ret (MSVC CFG guard): original.
#include "ff.h"

extern "C" void THISCALL ext_43de70(void *self);      // base of ZBreath (stub in spec; other area)
extern "C" void THISCALL ext_465660(void *self);      // base of ZCTRLIKLNKOBJ (stub in spec; other area)
extern "C" void ext_45c510(void *p);                  // ZGEOM::operator delete(void*) (cdecl; stub in spec; other area)
extern "C" void ext_4690b0(void *self, u32 arg);      // 1-byte ret in the exe (cdecl guard); original code

// 0x44cb10, ZBreath::~ZBreath() (GC map high). Scalar deleting destructor: thiscall, one stack arg (flags, ret 4), returns
// this. vtable 0x6801a4, base destructor 0x43de70; when flags bit 0 is set: bit 2 set -> guard call (0x1348), else delete.
static u8 *THISCALL breathDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x6801a4u;
  ext_43de70(self);
  if ((u8)flags & 1) {
    if ((u8)flags & 4)
      ext_4690b0(self, 0x1348u);
    else
      ext_45c510(self);
  }
  return self;
}
PCREG(44cb10, breathDtor);

// 0x468090, ZCTRLIKLNKOBJ::~ZCTRLIKLNKOBJ() (GC map high). Same shape: vtable 0x6860b0, base 0x465660, guard arg 0x1e2.
static u8 *THISCALL ctrlIkLnkObjDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x6860b0u;
  ext_465660(self);
  if ((u8)flags & 1) {
    if ((u8)flags & 4)
      ext_4690b0(self, 0x1e2u);
    else
      ext_45c510(self);
  }
  return self;
}
PCREG(468090, ctrlIkLnkObjDtor);
