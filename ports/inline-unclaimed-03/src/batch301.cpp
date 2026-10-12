// batch301.cpp - unclaimed-03 batch 1 (docs/20-unclaimed-03.md): ZActor leaf getters (all 2 instructions).
// Names are from the GC name map (naming only); the bodies are from the PC bytes.
#include "ff.h"

// 0x478630, ZActor::EndDir() const (high): returns the address of this+0x69a (lea, no load).
static u32 THISCALL actorEndDir(u8 *self) {
  return (u32)(self + 0x69a);
}
PCREG(478630, actorEndDir);

// 0x4789e0, ZActor::GetActiveMoveSet() const (high): returns the dword at this+0x4ae.
static u32 THISCALL actorGetActiveMoveSet(u8 *self) {
  return *(u32 *)(self + 0x4ae);
}
PCREG(4789e0, actorGetActiveMoveSet);

// 0x4789f0, ZActor::GetActorList() const (high): returns the dword at this+0x73a.
static u32 THISCALL actorGetActorList(u8 *self) {
  return *(u32 *)(self + 0x73a);
}
PCREG(4789f0, actorGetActorList);

// 0x478a60, ZActor::GetActorState() const (high): returns the dword at this+0x65c (the field SetActorState stores).
static u32 THISCALL actorGetActorState(u8 *self) {
  return *(u32 *)(self + 0x65c);
}
PCREG(478a60, actorGetActorState);

// 0x478b30, ZActor::GetAudibleRoomList() (high): returns the dword at this+0x5ca.
static u32 THISCALL actorGetAudibleRoomList(u8 *self) {
  return *(u32 *)(self + 0x5ca);
}
PCREG(478b30, actorGetAudibleRoomList);

// 0x478b40, ZActor::GetCage() const (high): returns the dword at this+0x6bf (the field SetCage writes).
static u32 THISCALL actorGetCage(u8 *self) {
  return *(u32 *)(self + 0x6bf);
}
PCREG(478b40, actorGetCage);

// 0x478b50, ZActor::GetCurrentMoveType() const (high): returns the dword at this+0x650.
static u32 THISCALL actorGetCurrentMoveType(u8 *self) {
  return *(u32 *)(self + 0x650);
}
PCREG(478b50, actorGetCurrentMoveType);

// 0x478b60, ZActor::GetCurrentRoom() const (high): returns the dword at this+0x736.
static u32 THISCALL actorGetCurrentRoom(u8 *self) {
  return *(u32 *)(self + 0x736);
}
PCREG(478b60, actorGetCurrentRoom);

// 0x479740, ZActor::NoCageCheck() (high): stores 1 in the byte at this+0x6c3. No return value.
static void THISCALL actorNoCageCheck(u8 *self) {
  self[0x6c3] = 1;
}
PCREG(479740, actorNoCageCheck);

// 0x47c530, ZActor::TrackObjPos() const (high): returns the address of this+0x660 (lea, no load).
static u32 THISCALL actorTrackObjPos(u8 *self) {
  return (u32)(self + 0x660);
}
PCREG(47c530, actorTrackObjPos);
