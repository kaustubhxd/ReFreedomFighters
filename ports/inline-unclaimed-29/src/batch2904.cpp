// batch2904.cpp - unclaimed-29: batch 4 (docs/20-unclaimed-29.md, claim 4, slice 8). Thiscall. ZVehicleIf::collectOpaqueInfo's
// name is low confidence (GUESS).
#include "ff.h"

// 0x500a10, base-class destructor (thiscall, no arguments; original code here).
extern "C" void THISCALL ext_500a10(u8 *self);
// 0x634273, operator delete (cdecl).
extern "C" void ext_634273(void *p, u32 size);
// 0x51a790, ZMoveOnSplineIf::collectOpaqueInfo (thiscall, one stack argument; original code here).
extern "C" void THISCALL ext_51a790(u8 *self, u8 *buf);

typedef u32(THISCALL *NoArgFn)(u8 *self);
typedef void(THISCALL *OneArgFn)(u8 *self, u32 a);

// 0x519440, ZMoveOnSplineIf::~ZMoveOnSplineIf() (high): vtable := 0x69f224; base destructor; operator delete of 0x18 bytes when
// bit 0 of the flag is set; returns this.
static u8 *THISCALL moveOnSplineIfDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x69f224;
  ext_500a10(self);
  if ((u8)flags & 1) ext_634273(self, 0x18);
  return self;
}
PCREG(519440, moveOnSplineIfDtor);

// 0x51f200, ZVehicleIf::collectOpaqueInfo(OpaqueObjectSerialBuffer_t&) (low): calls 0x51a790 on this with the argument; then
// r = this's virtual slot +0x38 (no arguments); then the argument's virtual slot 0 with r.
static void THISCALL vehicleIfCollectOpaqueInfo(u8 *self, u8 *buf) {
  ext_51a790(self, buf);
  const u32 vtSelf = *(const u32 *)self;
  const u32 r = ((NoArgFn)(*(const u32 *)(vtSelf + 0x38)))(self);
  const u32 vtBuf = *(const u32 *)buf;
  ((OneArgFn)(*(const u32 *)vtBuf))(buf, r);
}
PCREG(51f200, vehicleIfCollectOpaqueInfo);
