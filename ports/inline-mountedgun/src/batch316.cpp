// batch316.cpp - mounted gun tree, batch 316: ZTankIf::InitTankPosDir (script native,  by list position).
// The wrapper passes param 0 != 0 to the tank's ZTank::InitTankPosDir(bool) (PC 0x520f20, vehicles thread batch 916),
// called directly with the tank as this. Only the wrapper is ported here; the callee runs as exe code.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *block, u32 i);                 // parameter accessor (batch 1503)
extern "C" void THISCALL ext_520f20(void *tank, u32 initial);           // ZTank::InitTankPosDir (vehicles batch 916)

// 0x522820 ZTankIf::InitTankPosDir(OpaqueCallParameters_t&), thiscall, ret 4.
static void THISCALL initTankPosDir(u8 *self, u8 *par) {
  u32 v = *(u32 *)ext_5003d0(*(void **)(par + 4), 0);
  ext_520f20(*(void **)(self + 0x1c), v != 0);
}
PCREG(522820, initTankPosDir);
