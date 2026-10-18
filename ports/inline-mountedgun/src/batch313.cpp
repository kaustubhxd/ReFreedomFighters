// batch313.cpp - mounted gun tree, batch 313: the tank's machine-gun script natives (ZTankIf, the script interface
// object; +0x1c is its ZTank). Names from the GC ZTankIf::addMethodDefinitions table, whose order matches the PC
// registration list at 0x522940 (InitTankPosDir, SetTargetMachineGun, SetTargetCannon, FireMachineGun, ...).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef void(THISCALL *vcallVU)(void *self, u32 a);

extern "C" u8 *THISCALL ext_5003d0(void *block, u32 i);   // parameter accessor (batch 1503)

// 0x51b0e0 ZTankIf::SetTargetMachineGun(OpaqueCallParameters_t&) (GC 801d5ff8 by list position); thiscall, ret 4.
// tank->slot 0x388(in 0) (ZTank vtable slot 226, which is ZTank::SetTargetMachineGun 0x5217c0).
static void THISCALL setTargetMachineGun(u8 *self, u8 *par) {
  u32 ref = *(u32 *)ext_5003d0(*(void **)(par + 4), 0);
  u8 *tank = *(u8 **)(self + 0x1c);
  ((vcallVU)VT(tank, 0x388))(tank, ref);
}
PCREG(51b0e0, setTargetMachineGun);

// 0x5227f0 ZTankIf::FireMachineGun(OpaqueCallParameters_t&) (GC 801d612c by list position); thiscall, ret 4 (taken by a
// tail jump into the callee): tank->slot 0x38c(in 0 != 0) (inferred: ZTank::FireMachineGun(bool), 0x520d50).
static void THISCALL fireMachineGun(u8 *self, u8 *par) {
  u32 v = *(u32 *)ext_5003d0(*(void **)(par + 4), 0);
  u8 *tank = *(u8 **)(self + 0x1c);
  ((vcallVU)VT(tank, 0x38c))(tank, v != 0);
}
PCREG(5227f0, fireMachineGun);

typedef void(THISCALL *vcallVUU)(void *self, u32 a, u32 b);

// 0x522850 ZTankIf::SetTargetCannon(OpaqueCallParameters_t&) (GC 801d6090 by list position); thiscall, ret 4:
// tank->slot 0x37c(param 0, 0).
static void THISCALL setTargetCannon(u8 *self, u8 *par) {
  u32 ref = *(u32 *)ext_5003d0(*(void **)(par + 4), 0);
  u8 *tank = *(u8 **)(self + 0x1c);
  ((vcallVUU)VT(tank, 0x37c))(tank, ref, 0);
}
PCREG(522850, setTargetCannon);

// 0x5227c0 ZTankIf::FireCannon(OpaqueCallParameters_t&) (GC 801d61d4 by list position); thiscall, ret 4 (tail jump):
// tank->slot 0x380(param 0 != 0).
static void THISCALL fireCannon(u8 *self, u8 *par) {
  u32 v = *(u32 *)ext_5003d0(*(void **)(par + 4), 0);
  u8 *tank = *(u8 **)(self + 0x1c);
  ((vcallVU)VT(tank, 0x380))(tank, v != 0);
}
PCREG(5227c0, fireCannon);

// 0x522910 ZTankIf::TurnToRef(OpaqueCallParameters_t&) (GC 801d6280 by list position); thiscall, ret 4:
// tank->slot 0x374(param 0) (inferred: turn the turret toward the referenced object).
static void THISCALL turnToRef(u8 *self, u8 *par) {
  u32 ref = *(u32 *)ext_5003d0(*(void **)(par + 4), 0);
  u8 *tank = *(u8 **)(self + 0x1c);
  ((vcallVU)VT(tank, 0x374))(tank, ref);
}
PCREG(522910, turnToRef);
