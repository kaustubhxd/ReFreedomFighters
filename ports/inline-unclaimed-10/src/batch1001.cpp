// batch1001.cpp - unclaimed-10: ZActor leaf accessors (docs/20-unclaimed-10.md). Every function is thiscall, no
// stack arguments (ret). Names are from the GC name map (naming only); the bodies are from the PC bytes.
#include "ff.h"

// 0x478630, ZActor::EndDir() const (high): returns the address this+0x69a (lea eax,[ecx+0x69a]).
static u8 *THISCALL actorEndDir(u8 *self) { return self + 0x69a; }
PCREG(478630, actorEndDir);

// 0x4789e0, ZActor::GetActiveMoveSet() const (high): returns the dword at this+0x4ae.
static u32 THISCALL actorGetActiveMoveSet(u8 *self) { return *(u32 *)(self + 0x4ae); }
PCREG(4789e0, actorGetActiveMoveSet);

// 0x4789f0, ZActor::GetActorList() const (high): returns the dword at this+0x73a.
static u32 THISCALL actorGetActorList(u8 *self) { return *(u32 *)(self + 0x73a); }
PCREG(4789f0, actorGetActorList);

// 0x478a60, ZActor::GetActorState() const (high): returns the dword at this+0x65c.
static u32 THISCALL actorGetActorState(u8 *self) { return *(u32 *)(self + 0x65c); }
PCREG(478a60, actorGetActorState);

// 0x478b30, ZActor::GetAudibleRoomList() (high): returns the dword at this+0x5ca.
static u32 THISCALL actorGetAudibleRoomList(u8 *self) { return *(u32 *)(self + 0x5ca); }
PCREG(478b30, actorGetAudibleRoomList);

// 0x478b40, ZActor::GetCage() const (high): returns the dword at this+0x6bf.
static u32 THISCALL actorGetCage(u8 *self) { return *(u32 *)(self + 0x6bf); }
PCREG(478b40, actorGetCage);

// 0x478b50, ZActor::GetCurrentMoveType() const (high): returns the dword at this+0x650.
static u32 THISCALL actorGetCurrentMoveType(u8 *self) { return *(u32 *)(self + 0x650); }
PCREG(478b50, actorGetCurrentMoveType);

// 0x478b60, ZActor::GetCurrentRoom() const (high): returns the dword at this+0x736.
static u32 THISCALL actorGetCurrentRoom(u8 *self) { return *(u32 *)(self + 0x736); }
PCREG(478b60, actorGetCurrentRoom);

// 0x47c530, ZActor::TrackObjPos() const (high): returns the address this+0x660 (lea eax,[ecx+0x660]).
static u8 *THISCALL actorTrackObjPos(u8 *self) { return self + 0x660; }
PCREG(47c530, actorTrackObjPos);

// 0x479740, ZActor::NoCageCheck() (high): stores 1 in the byte at this+0x6c3.
static void THISCALL actorNoCageCheck(u8 *self) { self[0x6c3] = 1; }
PCREG(479740, actorNoCageCheck);

// Batch 2 (unclaimed-10): the Name() returns below are `mov eax, imm32; ret`, each returning the address of a
// string constant in the exe's data (GC name map, high confidence, class name as the string).

// 0x486e10, ZActionChamberItem::Name() (high): returns the constant address 0x68cdb0.
static u32 THISCALL actionChamberItemName(u8 *self) { (void)self; return 0x68cdb0; }
PCREG(486e10, actionChamberItemName);

// 0x486e50, ZActionPushButton::Name() (high): returns the constant address 0x68cd24.
static u32 THISCALL actionPushButtonName(u8 *self) { (void)self; return 0x68cd24; }
PCREG(486e50, actionPushButtonName);

// 0x486e70, ZActionReloadItem::Name() (high): returns the constant address 0x68cd74.
static u32 THISCALL actionReloadItemName(u8 *self) { (void)self; return 0x68cd74; }
PCREG(486e70, actionReloadItemName);

// Batch 3 (unclaimed-10): leaves with medium or low name confidence (GUESS on the class and name where marked).

// 0x4eb340, ZCollisionBox::Unlock() (medium): stores 0 in the byte at this+0xa5.
static void THISCALL collisionBoxUnlock(u8 *self) { self[0xa5] = 0; }
PCREG(4eb340, collisionBoxUnlock);

// 0x4ecb30, ZCollisionBase::GetCollisionPack() (medium): returns the dword at this+0x1ad.
static u32 THISCALL collisionBaseGetCollisionPack(u8 *self) { return *(u32 *)(self + 0x1ad); }
PCREG(4ecb30, collisionBaseGetCollisionPack);

// 0x4edca0, ZCollisionBase::IsCollisionBoxLocked() const (medium): returns the byte at this+0xa9 (in al).
static u8 THISCALL collisionBaseIsCollisionBoxLocked(u8 *self) { return self[0xa9]; }
PCREG(4edca0, collisionBaseIsCollisionBoxLocked);

// 0x4fc680, CMAINCAMERACONTROL::GetOldCam() (low, GUESS): returns the dword at this+0x74.
static u32 THISCALL cameraControlGetOldCam(u8 *self) { return *(u32 *)(self + 0x74); }
PCREG(4fc680, cameraControlGetOldCam);

// 0x4fdd10, CMAINCAMERACONTROL::ToggleFreeCam() (low, GUESS): stores 1 in the byte at this+0x69.
static void THISCALL cameraControlToggleFreeCam(u8 *self) { self[0x69] = 1; }
PCREG(4fdd10, cameraControlToggleFreeCam);

// 0x5095e0, ZActorIf::getTypeName() (low, GUESS): returns the constant address 0x69c75c.
static u32 THISCALL actorIfGetTypeName(u8 *self) { (void)self; return 0x69c75c; }
PCREG(5095e0, actorIfGetTypeName);

// Batch 4 (unclaimed-10): call-free leaves found by the leaf scan (docs/20-unclaimed-10.md, batch 4).

// 0x4edce0, ZCollisionBase::LoadUniqueSubStripInfo(char*, unsigned int) (medium, GUESS on the name): ret 8.
// Stores the second argument shifted right by 3 at this+0x194, the first argument at this+0x190, and 1 in the byte at +0x19c.
static void THISCALL collisionBaseLoadUniqueSubStripInfo(u8 *self, u32 a1, u32 a2) {
  *(u32 *)(self + 0x194) = a2 >> 3;
  *(u32 *)(self + 0x190) = a1;
  self[0x19c] = 1;
}
PCREG(4edce0, collisionBaseLoadUniqueSubStripInfo);

// 0x53e800, CRigidBody::CopyData(ZEventBase*) (medium): ret 4. Copies three fields from the source object (the argument)
// into this: the byte at +0x149, and the dwords at +0x145 and +0x141.
static void THISCALL rigidBodyCopyData(u8 *self, u8 *src) {
  self[0x149] = src[0x149];
  *(u32 *)(self + 0x145) = *(u32 *)(src + 0x145);
  *(u32 *)(self + 0x141) = *(u32 *)(src + 0x141);
}
PCREG(53e800, rigidBodyCopyData);
