// batch900.cpp - vehicles thread, batch 900: setter leaves of ZCar, ZTank and ZHeli.
// Offsets are byte offsets into the PC objects (the PC build is /Zp1 packed, so many are odd).
#include "ff.h"

// 0x5186c0 ZCar::SetSkidPitch(int): the skid sound pitch goes to +0x1635.
static void THISCALL carSetSkidPitch(u8 *self, u32 pitch) { *(u32 *)(self + 0x1635) = pitch; }
PCREG(5186c0, carSetSkidPitch);

// 0x518730 ZCar::SetStationary(bool): +0x133 (ZMoveOnSpline stationary flag) and the car's own copy at +0x394.
static void THISCALL carSetStationary(u8 *self, u32 b) {
  self[0x133] = (u8)b;
  self[0x394] = (u8)b;
}
PCREG(518730, carSetStationary);

// 0x521760 ZTank::SetStationary(bool): +0x133 and the tank's copy at +0x24ca.
static void THISCALL tankSetStationary(u8 *self, u32 b) {
  self[0x133] = (u8)b;
  self[0x24ca] = (u8)b;
}
PCREG(521760, tankSetStationary);

// 0x520d30 ZTank::FireCannon(bool): the fire request is kept as a dword at +0x2620.
static void THISCALL tankFireCannon(u8 *self, u32 b) { *(u32 *)(self + 0x2620) = (u8)b; }
PCREG(520d30, tankFireCannon);

// 0x520d50 ZTank::FireMachineGun(bool): the request goes to +0x2614, but is cleared again unless the machine-gun
// target (+0x260c) passes slot 0x310 (ZMoveOnSpline::CanSee).
static void THISCALL tankFireMachineGun(u8 *self, u32 b) {
  *(u32 *)(self + 0x2614) = (u8)b;
  if (!vcall<u8>(self, 0x310, *(u32 *)(self + 0x260c)))
    *(u32 *)(self + 0x2614) = 0;
}
PCREG(520d50, tankFireMachineGun);

// 0x51c520 ZHeli::Fire(bool): the fire request is a dword at +0x469.
static void THISCALL heliFire(u8 *self, u32 b) { *(u32 *)(self + 0x469) = (u8)b; }
PCREG(51c520, heliFire);

// 0x51cef0 ZHeli::SetJetSoundParams(int, float): +0x4a5 and +0x4a9.
static void THISCALL heliSetJetSoundParams(u8 *self, u32 a, u32 f) {
  *(u32 *)(self + 0x4a5) = a;
  *(u32 *)(self + 0x4a9) = f;
}
PCREG(51cef0, heliSetJetSoundParams);

// 0x51d0d0 ZHeli::StartJetSound(): if no jet sound handle (+0x499), start sound set +0x491 via slot 0x2e8.
static void THISCALL heliStartJetSound(u8 *self) {
  if (*(u32 *)(self + 0x499) == 0)
    *(u32 *)(self + 0x499) = vcall<u32>(self, 0x2e8, *(u32 *)(self + 0x491));
}
PCREG(51d0d0, heliStartJetSound);

// 0x51d100 ZHeli::StopJetSound(): slot 0x2ec stops handle +0x499, which is then cleared.
static void THISCALL heliStopJetSound(u8 *self) {
  vcall<void>(self, 0x2ec, *(u32 *)(self + 0x499));
  *(u32 *)(self + 0x499) = 0;
}
PCREG(51d100, heliStopJetSound);

// 0x5184d0 ZCar::ReceiveImpact(float, const float[2]&): forwards to the undercarriage at +0x2d8.
extern "C" void THISCALL ext_525e20(void *uc, float f, const float *dir);
static void THISCALL carReceiveImpact(u8 *self, float f, const float *dir) { ext_525e20(self + 0x2d8, f, dir); }
PCREG(5184d0, carReceiveImpact);

// 0x5213d0 ZTank::ReceiveImpact(float, const float[2]&): forwards to the tank undercarriage at +0x2fd.
extern "C" void THISCALL ext_5289d0(void *uc, float f, const float *dir);
static void THISCALL tankReceiveImpact(u8 *self, float f, const float *dir) { ext_5289d0(self + 0x2fd, f, dir); }
PCREG(5213d0, tankReceiveImpact);
