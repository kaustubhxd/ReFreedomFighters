// batch1111.cpp - unclaimed-11 batch 12 (slice 10, full list): six trivial accessors (docs/20-unclaimed-11.md).
#include "ff.h"

// 0x453b20, ZGATE::IsOpen() (low): the byte at this+0x5a.
static u8 THISCALL gateIsOpen(u8 *self) { return self[0x5a]; }
PCREG(453b20, gateIsOpen);

// 0x463020, GUESS (name map: ZLNKOBJ::MoveToMatPos, body disagrees): the byte at this+0x70.
static u8 THISCALL guessByte70(u8 *self) { return self[0x70]; }
PCREG(463020, guessByte70);

// 0x43ed60, ZGROUP::AddSphere (low): returns 0 (five stack arguments; the callee pops them, ret 0x14).
static u32 THISCALL groupAddSphere(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) { return 0; }
PCREG(43ed60, groupAddSphere);

// 0x4b1720, ZActionMapPushSceneOnKeyStart::GetActionDefinitions() (low): the dword at 0x6e6734.
static u32 THISCALL pushSceneGetActionDefinitions(u8 *self) { return G(u32, 0x6e6734); }
PCREG(4b1720, pushSceneGetActionDefinitions);

// 0x4fb820, ZActionMapMainCameraControl::GetActionDefinitions() (low): the dword at 0x6e8d40.
static u32 THISCALL mainCameraGetActionDefinitions(u8 *self) { return G(u32, 0x6e8d40); }
PCREG(4fb820, mainCameraGetActionDefinitions);

// 0x511760, ZScriptSoundInterface_t::getTypeName() (low): the address 0x69c790.
static u32 THISCALL scriptSoundGetTypeName(u8 *self) { return 0x69c790; }
PCREG(511760, scriptSoundGetTypeName);
