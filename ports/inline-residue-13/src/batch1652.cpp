// batch1652.cpp - six ZActor getters (residue 13 gap-band pass, 2026-10-12). Each returns one dword of the actor:
// GetActiveMoveSet (+0x4ae), GetActorList (+0x73a), GetActorState (+0x65c), GetAudibleRoomList (+0x5ca),
// GetCurrentMoveType (+0x650), GetCurrentRoom (+0x736). Names from docs/20-unclaimed-06.md (high in the name map).
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

u32 THISCALL ZActor_GetActiveMoveSet(u8 *self) { return AT(u32, self, 0x4ae); }
PCREG(4789e0, ZActor_GetActiveMoveSet);

u32 THISCALL ZActor_GetActorList(u8 *self) { return AT(u32, self, 0x73a); }
PCREG(4789f0, ZActor_GetActorList);

u32 THISCALL ZActor_GetActorState(u8 *self) { return AT(u32, self, 0x65c); }
PCREG(478a60, ZActor_GetActorState);

u32 THISCALL ZActor_GetAudibleRoomList(u8 *self) { return AT(u32, self, 0x5ca); }
PCREG(478b30, ZActor_GetAudibleRoomList);

u32 THISCALL ZActor_GetCurrentMoveType(u8 *self) { return AT(u32, self, 0x650); }
PCREG(478b50, ZActor_GetCurrentMoveType);

u32 THISCALL ZActor_GetCurrentRoom(u8 *self) { return AT(u32, self, 0x736); }
PCREG(478b60, ZActor_GetCurrentRoom);
