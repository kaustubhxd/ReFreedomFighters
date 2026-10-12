// batch1601.cpp - unclaimed-16: ZActor getters and ZFFActor combat-flag setters (docs/20-unclaimed-16.md).
// Every function is thiscall. Names are from the GC name map (naming only, GUESS where the map is low confidence);
// the bodies are from the PC bytes (decoders/tools/ffre.py disassembly).
#include "ff.h"

// 0x478630, ZActor::EndDir() const (high): returns the address this+0x69a (lea, no load).
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

// 0x478a60, ZActor::GetActorState() const (high): returns the dword at this+0x65c.
static u32 THISCALL actorGetActorState(u8 *self) {
  return *(u32 *)(self + 0x65c);
}
PCREG(478a60, actorGetActorState);

// 0x478b30, ZActor::GetAudibleRoomList() (high): returns the dword at this+0x5ca.
static u32 THISCALL actorGetAudibleRoomList(u8 *self) {
  return *(u32 *)(self + 0x5ca);
}
PCREG(478b30, actorGetAudibleRoomList);

// 0x478b40, ZActor::GetCage() const (high): returns the dword at this+0x6bf (unaligned).
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

// 0x479740, ZActor::NoCageCheck() (high): stores 1 in the byte at this+0x6c3. No arguments, void.
static void THISCALL actorNoCageCheck(u8 *self) {
  self[0x6c3] = 1;
}
PCREG(479740, actorNoCageCheck);

// 0x47c530, ZActor::TrackObjPos() const (high): returns the address this+0x660 (lea, no load).
static u32 THISCALL actorTrackObjPos(u8 *self) {
  return (u32)(self + 0x660);
}
PCREG(47c530, actorTrackObjPos);

// 0x59fce0, ZFFActor::GetAmmoFor(ZItemWeapon*) (high): ignores its argument and returns the constant 999.
static u32 THISCALL ffActorGetAmmoFor(u8 *self, u32 a1) {
  (void)self;
  (void)a1;
  return 999;
}
PCREG(59fce0, ffActorGetAmmoFor);

// 0x59fe70, ZFFActor::GetKnockedOut() const (high): returns the byte at this+0x929.
static u32 THISCALL ffActorGetKnockedOut(u8 *self) {
  return self[0x929];
}
PCREG(59fe70, ffActorGetKnockedOut);

// 0x5a2c30, ZFFActor::SetCloseCombatAttack(bool) (high): sets bit 1 of the dword at this+0x7a6 when the low byte
// of the argument is nonzero, otherwise clears it.
static void THISCALL ffActorSetCloseCombatAttack(u8 *self, u32 a1) {
  u32 *flags = (u32 *)(self + 0x7a6);
  if ((u8)a1)
    *flags |= 2;
  else
    *flags &= 0xfffffffd;
}
PCREG(5a2c30, ffActorSetCloseCombatAttack);

// 0x5a2c50, ZFFActor::SetCloseCombatEnable(bool) (high): bit 0 of the dword at this+0x7a6.
static void THISCALL ffActorSetCloseCombatEnable(u8 *self, u32 a1) {
  u32 *flags = (u32 *)(self + 0x7a6);
  if ((u8)a1)
    *flags |= 1;
  else
    *flags &= 0xfffffffe;
}
PCREG(5a2c50, ffActorSetCloseCombatEnable);

// 0x5a2c70, ZFFActor::SetCloseCombatEvade(bool) (high): bit 2 of the dword at this+0x7a6.
static void THISCALL ffActorSetCloseCombatEvade(u8 *self, u32 a1) {
  u32 *flags = (u32 *)(self + 0x7a6);
  if ((u8)a1)
    *flags |= 4;
  else
    *flags &= 0xfffffffb;
}
PCREG(5a2c70, ffActorSetCloseCombatEvade);
