// batch938.cpp - vehicles thread, batch 938: ZCar::ClassInit() (0x5175a0), thiscall, no arguments.
// The vehicle class init (0x515630, stood in by the spec) runs first; then the car's engine sound id is looked up
// from the sound manager (+0x1a9f, slot 0x60 with the name 0x69e5ec, into +0x161d, when the manager exists); the
// transform is placed (slot 0x80); a script object comes from the render manager (slot 0x138) and gives an id through
// its slot 0x88 (name 0x681320, out pointer); the id is resolved to the object at +0x164a (slot 0x58).
#include "ff.h"

extern "C" void THISCALL ext_515630(void *self);  // ZVehicle::ClassInit (stood in)

static inline u8 *sysp() { return *(u8 **)0x70039c; }

// 0x5175a0 ZCar::ClassInit().
static void THISCALL carClassInit(u8 *s) {
  ext_515630(s);
  void *sm = *(void **)(sysp() + 0x1a9f);
  if (sm)
    *(u32 *)(s + 0x161d) = vcall<u32>(sm, 0x60, *(u32 *)(s + 0x12f), 0x69e5ecu);
  vcall<void>(s, 0x80, s + 0x6c, s + 0x60);
  void *rm = *(void **)(sysp() + 0x9b);
  void *o = vcall<void *>(rm, 0x138);
  u32 id = 0;
  vcall<void>(o, 0x88, 0x681320u, (u32)&id);
  *(u32 *)(s + 0x164a) = vcall<u32>(*(void **)(sysp() + 0x9b), 0x58, id);
}
PCREG(5175a0, carClassInit);
