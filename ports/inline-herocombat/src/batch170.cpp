// batch170.cpp - unclaimed area 17 (docs/20-unclaimed-17.md), leaf thiscall getters and setters, all with plain ret.
#include "ff.h"

// getTypeName getters: each returns the address of a static string in the exe, from the same shape (mov eax, imm; ret).
// 0x5095e0 ZActorIf, 0x51a7c0 ZMoveOnSplineIf, 0x51ad80 ZVehicleIf, 0x51b5f0 ZCarIf, 0x55ec20 ZFFActorIf, 0x55f9f0
// ZFFHeroIf. Names from the map (high confidence on the class, the string address is not named).
static u32 THISCALL typeName_5095e0(u8 *) { return 0x69c75cu; }
PCREG(5095e0, typeName_5095e0);
static u32 THISCALL typeName_51a7c0(u8 *) { return 0x69f26cu; }
PCREG(51a7c0, typeName_51a7c0);
static u32 THISCALL typeName_51ad80(u8 *) { return 0x69f3acu; }
PCREG(51ad80, typeName_51ad80);
static u32 THISCALL typeName_51b5f0(u8 *) { return 0x69f484u; }
PCREG(51b5f0, typeName_51b5f0);
static u32 THISCALL typeName_55ec20(u8 *) { return 0x6a4b74u; }
PCREG(55ec20, typeName_55ec20);
static u32 THISCALL typeName_55f9f0(u8 *) { return 0x6a4b80u; }
PCREG(55f9f0, typeName_55f9f0);
