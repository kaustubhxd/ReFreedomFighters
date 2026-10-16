// batch1653.cpp - four direct jump thunks in the gap band (residue 13, 2026-10-12). Each is `push ebp; mov ebp,esp;
// pop ebp; jmp target`, so the port calls the target with the same this and the one stack argument (every target
// returns with ret 4, thiscall) and passes its eax through. Targets: 0x468310 -> ZItemState::ReadInput (0x4702b0),
// 0x471630 -> ZItemTemplate::SetStates (0x471540), 0x472440 -> ZIKLNKOBJ::BoneAnimCallBackToId (0x465850, GUESS name for
// the thunk), 0x4765d0 -> ZGEOM::Activate (0x45c680). The target addresses are hooked in the checker.
#include "ff.h"

extern "C" char ext_4702b0[], ext_471540[], ext_465850[], ext_45c680[];
typedef u32(THISCALL *Thunk1)(void *self, u32 arg);

u32 THISCALL ZItemState_CopyEventDataBlock(void *self, u32 arg) { return ((Thunk1)(void *)ext_4702b0)(self, arg); }
PCREG(468310, ZItemState_CopyEventDataBlock);

u32 THISCALL ZItemTemplateWeapon_SetStates(void *self, u32 arg) { return ((Thunk1)(void *)ext_471540)(self, arg); }
PCREG(471630, ZItemTemplateWeapon_SetStates);

u32 THISCALL GUESS_472440(void *self, u32 arg) { return ((Thunk1)(void *)ext_465850)(self, arg); }
PCREG(472440, GUESS_472440);

u32 THISCALL ZAllocMany_Activate(void *self, u32 arg) { return ((Thunk1)(void *)ext_45c680)(self, arg); }
PCREG(4765d0, ZAllocMany_Activate);
