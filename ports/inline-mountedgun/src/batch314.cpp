// batch314.cpp - mounted gun tree, batch 314: the helicopter's gun script natives (ZHeliIf, +0x18 is its ZHeli).
// Names from the GC ZHeliIf::addMethodDefinitions table , whose order matches the PC list at 0x51ed20
// (entries 10 and 11: Fire, SetTarget). ZHeli::Fire(bool) and ZHeli::SetTarget(unsigned int) are vehicles-thread ports.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef void(THISCALL *vcallVU)(void *self, u32 a);

extern "C" u8 *THISCALL ext_5003d0(void *block, u32 i);   // parameter accessor (batch 1503)

// 0x51e840 ZHeliIf::Fire(OpaqueCallParameters_t&) ( by list position); thiscall, ret 4 (tail jump):
// heli->slot 0x39c(param 0 != 0).
static void THISCALL fire(u8 *self, u8 *par) {
  u32 v = *(u32 *)ext_5003d0(*(void **)(par + 4), 0);
  u8 *heli = *(u8 **)(self + 0x18);
  ((vcallVU)VT(heli, 0x39c))(heli, v != 0);
}
PCREG(51e840, fire);

// 0x51eb50 ZHeliIf::SetTarget(OpaqueCallParameters_t&) ( by list position); thiscall, ret 4:
// heli->slot 0x398(param 0).
static void THISCALL setTarget(u8 *self, u8 *par) {
  u32 ref = *(u32 *)ext_5003d0(*(void **)(par + 4), 0);
  u8 *heli = *(u8 **)(self + 0x18);
  ((vcallVU)VT(heli, 0x398))(heli, ref);
}
PCREG(51eb50, setTarget);
