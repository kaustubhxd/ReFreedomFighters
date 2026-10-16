// batch937.cpp - vehicles thread, batch 937: ZCar::ClassInit2 (0x517540) and ZVehicle::ClassInit2 (0x515620).
// ZVehicle::ClassInit2 is a tail jump to 0x5124c0 (the ZMoveOnSpline class-init step, stood in by the spec).
// ZCar::ClassInit2 runs that step, sets up the undercarriage (0x5253b0, stood in), stores its result at +0x1614, places
// the transform through slot 0x80 and runs slot 0x36c with 1.
#include "ff.h"

extern "C" void THISCALL ext_5124c0(void *self);                                   // ZMoveOnSpline class init step (stood in)
extern "C" u8 THISCALL ext_5253b0(void *uc, void *grp, u32 type, float f, u32 zero, u32 flag);  // CUnderCarriageCar::Init

#define F(p, o) (*(float *)((u8 *)(p) + (o)))

// 0x515620 ZVehicle::ClassInit2(): tail jump to 0x5124c0.
static void THISCALL vehClassInit2(u8 *s) { ext_5124c0(s); }
PCREG(515620, vehClassInit2);

// 0x517540 ZCar::ClassInit2().
static void THISCALL carClassInit2(u8 *s) {
  ext_5124c0(s);
  s[0x1614] = ext_5253b0(s + 0x2d8, s, *(u32 *)(s + 0x160c), F(s, 0x1610), 0u, (u32)s[0x133]);
  vcall<void>(s, 0x80, s + 0x6c, s + 0x60);
  vcall<void>(s, 0x36c, 1u);
}
PCREG(517540, carClassInit2);
