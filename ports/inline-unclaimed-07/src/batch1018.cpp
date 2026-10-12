// batch1018.cpp - unclaimed-07 batch 18 (residue-07 list): ZVehicle::CheckActorInFront.
// Name from the GC name map (high). Body from the PC bytes. The vehicle helpers are original code (ext_ calls).
#include "ff.h"

// 0x4e0870: fastcall (ECX, EDX), returns a float in ST0 (original code, hooked in the spec).
extern "C" float FASTCALL ext_4e0870(u8 *a, u8 *b);
// 0x515270, 0x514f60, 0x514d80, 0x515100: thiscall, no arguments (original code, hooked in the spec).
extern "C" void THISCALL ext_515270(u8 *self);
extern "C" u32 THISCALL ext_514f60(u8 *self);
extern "C" u32 THISCALL ext_514d80(u8 *self);
extern "C" void THISCALL ext_515100(u8 *self);

// 0x514cf0, ZVehicle::CheckActorInFront() (high): the actor at this+0x2af. Returns false when there is no actor, when the
// actor's slot +0x438 is non-zero, or when bit 10 of ~([actor+8]+0x3c) is 0. Otherwise d = 0x4e0870(this+0x2b3, this+0x29b)
// (stored at this+0x2bf). When d is not greater than the constant at 0x69eb5c: 0x515270(this); when 0x514f60(this) is true or
// 0x514d80(this) is true, 0x515100(this). Returns true.
static bool THISCALL vehicleCheckActorInFront(u8 *self) {
  u8 *actor = *(u8 **)(self + 0x2af);
  if (!actor)
    return false;
  if ((u8)vcall<u32>(actor, 0x438))
    return false;
  u8 *o8 = *(u8 **)(*(u8 **)(self + 0x2af) + 8);
  u32 f = *(u32 *)(o8 + 0x3c);
  if (!((~(f >> 10)) & 1))
    return false;
  float d = ext_4e0870(self + 0x2b3, self + 0x29b);
  *(float *)(self + 0x2bf) = d;
  if (!(d > G(float, 0x69eb5c))) {
    ext_515270(self);
    if ((u8)ext_514f60(self)) {
      ext_515100(self);
    } else if ((u8)ext_514d80(self)) {
      ext_515100(self);
    }
  }
  return true;
}
PCREG(514cf0, vehicleCheckActorInFront);
