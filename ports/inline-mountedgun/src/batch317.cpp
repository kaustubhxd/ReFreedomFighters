// batch317.cpp - mounted gun tree, batch 317: ZTankIf::DriveToSplineVal (script native, GameCube reference by list position).
// Wrapper: param 0 (float) and param 1 (bool, != 0) go to ZTank::DriveToSplineVal(float, bool) at PC 0x520c50 (vehicles
// thread batch 916), called with the tank as this. Only the wrapper is ported; the callee runs as exe code.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *block, u32 i);                  // parameter accessor (batch 1503)
extern "C" void THISCALL ext_520c50(void *tank, float spline, u32 flag); // ZTank::DriveToSplineVal (vehicles batch 916)

// 0x5227b0 ZTankIf::DriveToSplineVal(OpaqueCallParameters_t&), thiscall, ret 4. The float is read from param 0 and the
// bool from param 1 (a dword != 0 gives 1), then the tank's DriveToSplineVal runs.
static void THISCALL driveToSplineVal(u8 *self, u8 *par) {
  u8 *flag = ext_5003d0(*(void **)(par + 4), 1);
  float v = *(float *)ext_5003d0(*(void **)(par + 4), 0);
  u32 b = *(u32 *)flag != 0;
  ext_520c50(*(void **)(self + 0x1c), v, b);
}
PCREG(522770, driveToSplineVal);
