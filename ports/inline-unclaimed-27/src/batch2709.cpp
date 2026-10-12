#include "ff.h"
// batch2709.cpp - residue-07 (core-todo) function 0x514cf0 (claimed by area 27 at this batch). Name from the GC name map.
// Callees are original code (bound by build.sh): 0x4e0870 is fastcall (two pointers, float in st0, ret 0); 0x514f60 and
// 0x514d80 return a byte (thiscall, ret 0); 0x515270 and 0x515100 are thiscall void, ret 0.
extern "C" float FASTCALL ext_4e0870(const float *a, const float *b);
extern "C" u8 THISCALL ext_514f60(u8 *self);
extern "C" u8 THISCALL ext_514d80(u8 *self);
extern "C" void THISCALL ext_515270(u8 *self);
extern "C" void THISCALL ext_515100(u8 *self);

// 0x514cf0, ZVehicle::CheckActorInFront() (high). Thiscall, ret 0, returns a bool in al.
// Returns 0 if the object at this+0x2af is missing, if its vtable slot +0x438 returns nonzero, or if bit 10 of the dword at
// (that object's +8)+0x3c is set. Otherwise stores the float from 0x4e0870(this+0x2b3, this+0x29b) at this+0x2bf and returns
// 1 when it exceeds 5000. Otherwise calls 0x515270, then 0x514f60; if that is nonzero, calls 0x515100; if not, calls 0x514d80
// and calls 0x515100 when it is nonzero. Returns 1 on every path that reaches the end.
static u8 THISCALL zVehicleCheckActorInFront(u8 *self) {
  typedef u8(THISCALL * slot438_fn)(u8 *);
  u8 *a = *(u8 **)(self + 0x2af);
  if (a == 0) return 0;
  if (((slot438_fn)(*(u32 *)(*(u32 *)a + 0x438)))(a)) return 0;

  u32 v = *(u32 *)(*(u8 **)(*(u8 **)(self + 0x2af) + 8) + 0x3c);
  if ((v >> 10) & 1u) return 0;

  float f = ext_4e0870((const float *)(self + 0x2b3), (const float *)(self + 0x29b));
  *(float *)(self + 0x2bf) = f;
  if (f > 5000.0f) return 1;

  ext_515270(self);
  if (ext_514f60(self)) {
    ext_515100(self);
    return 1;
  }
  if (ext_514d80(self)) ext_515100(self);
  return 1;
}
PCREG(514cf0, zVehicleCheckActorInFront);
