// batch608.cpp - band 0x421000-0x441000, batch 608: five small methods/functions.
//   0x4234b0 ZSysInterfaceGC::RemoveDll(ZDllBase *): stdcall, ret 4, returns bool (al).
//   0x42aac0 ZSysInterfaceGC::SetEngineData(ZEngineDataBase *): thiscall, ret 4.
//   0x435d90 ZSysInput::IsConnected(int i, int y): thiscall, ret 8, returns bool (al).
//   0x434ce0 ZSysInput-side ExistsInZip(const char *name): thiscall, ret 4, returns bool (al).
//   0x43da90 ZHapticsBase::StopEffects(): thiscall, no arguments.
// Virtual calls: RemoveDll uses the object's slot 0 (one argument, 1: scalar-delete flag); SetEngineData the old engine's
// slot 0x94 (one argument, 1); IsConnected the device's slot 0x44 (one argument, y); ExistsInZip this's slot 0x130 (name,
// returns a value) then slot 0x70 (that value); StopEffects the effect's slots 0x48 and 0x4c (one argument, 0).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vOne)(void *self, u32 a);                         // one argument

// 0x4234b0 RemoveDll(p): stdcall, ret 4
static bool STDCALL removeDll(u8 *p) {
  if (!p)
    return false;
  *(u32 *)(p + 8) = 0;
  ((vOne)VT(p, 0))(p, 1);
  return true;
}
PCREG(4234b0, removeDll);

// 0x42aac0 SetEngineData(d): thiscall, ret 4
static void THISCALL setEngineData(u8 *self, u8 *d) {
  u8 *old = *(u8 **)(self + 0x9b);
  if (old)
    ((vOne)VT(old, 0x94))(old, 1);
  *(u8 **)(self + 0x9b) = d;
}
PCREG(42aac0, setEngineData);

// 0x435d90 IsConnected(i, y): thiscall, ret 8
static bool THISCALL isConnected(u8 *self, u32 i, u32 y) {
  if (i >= *(u32 *)(self + 0x60))
    return false;
  u8 *d = *(u8 **)(self + 0x20 + i * 4);
  if (!d)
    return false;
  ((vOne)VT(d, 0x44))(d, y);
  return true;
}
PCREG(435d90, isConnected);

// 0x434ce0 ExistsInZip(name): thiscall, ret 4
static bool THISCALL existsInZip(u8 *self, u32 name) {
  u32 a = ((vOne)VT(self, 0x130))(self, name);
  return ((vOne)VT(self, 0x70))(self, a) != 0;
}
PCREG(434ce0, existsInZip);

// 0x43da90 StopEffects(): thiscall, no arguments
static void THISCALL stopEffects(u8 *self) {
  u8 *o = *(u8 **)(self + 4);
  ((vOne)VT(o, 0x48))(o, 0);
  o = *(u8 **)(self + 4);
  ((vOne)VT(o, 0x4c))(o, 0);
  *(u32 *)(self + 0x80) = 0;
}
PCREG(43da90, stopEffects);
