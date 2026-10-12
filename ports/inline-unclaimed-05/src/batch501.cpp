// batch501.cpp - unclaimed-05 batch 1 (docs/20-unclaimed-05.md). Every function is thiscall; the bodies are from the
// PC bytes of Freedom.Exe.orig. Names are from the GC name map (naming only, never committed); a GUESS is marked.
#include "ff.h"

// ZCollisionBase::GetCollisionPack() (medium): returns the dword at this+0x1ad in EAX (no ret arguments).
static u32 THISCALL collGetCollisionPack(u8 *self) {
  return *(u32 *)(self + 0x1ad);
}
PCREG(4ecb30, collGetCollisionPack);

// ZCollisionBase::IsCollisionBoxLocked() const (medium): returns the byte at this+0xa9 in AL.
static u8 THISCALL collIsCollisionBoxLocked(const u8 *self) {
  return self[0xa9];
}
PCREG(4edca0, collIsCollisionBoxLocked);

// ZCollisionBox::Unlock() (medium): clears the byte at this+0xa5.
static void THISCALL collBoxUnlock(u8 *self) {
  self[0xa5] = 0;
}
PCREG(4eb340, collBoxUnlock);

// ZCollisionBase::UnlockCollisionBox(ZCollisionBox*) (medium, GUESS on the meaning): the original ignores its one stack
// argument. It calls the box unlock on the sub-object at this+4 (ecx = this+4, then call 0x4eb340) and returns, ret 4.
static void THISCALL collUnlockCollisionBox(u8 *self, u32 box) {
  (void)box;
  collBoxUnlock(self + 4);
}
PCREG(4ede70, collUnlockCollisionBox);

// ZOctree::GetOrigin(float*) const (medium): copies the three dwords at this+4, +8, +0xc to out[0..2] (integer moves,
// no float operation, so NaN payloads survive).
static void THISCALL octreeGetOrigin(const u8 *self, u32 *out) {
  out[0] = *(const u32 *)(self + 0x4);
  out[1] = *(const u32 *)(self + 0x8);
  out[2] = *(const u32 *)(self + 0xc);
}
PCREG(4e3340, octreeGetOrigin);

// ZOctree::SetOrigin(float*) (medium): copies the three dwords of the argument to this+4, +8, +0xc.
static void THISCALL octreeSetOrigin(u8 *self, const u32 *in) {
  *(u32 *)(self + 0x4) = in[0];
  *(u32 *)(self + 0x8) = in[1];
  *(u32 *)(self + 0xc) = in[2];
}
PCREG(4e3360, octreeSetOrigin);

// ZActionChamberItem::Name() (high): returns the address of a string constant in the exe's data (no object read).
static const char *THISCALL actionChamberItemName(u8 *self) {
  (void)self;
  return (const char *)0x68cdb0;
}
PCREG(486e10, actionChamberItemName);

// ZActionPushButton::Name() (high): returns the exe string at 0x68cd24.
static const char *THISCALL actionPushButtonName(u8 *self) {
  (void)self;
  return (const char *)0x68cd24;
}
PCREG(486e50, actionPushButtonName);

// ZActionReloadItem::Name() (high): returns the exe string at 0x68cd74.
static const char *THISCALL actionReloadItemName(u8 *self) {
  (void)self;
  return (const char *)0x68cd74;
}
PCREG(486e70, actionReloadItemName);

// ZHeliIf::getTypeName() (medium): returns the exe string at 0x69faac.
static const char *THISCALL heliIfTypeName(u8 *self) {
  (void)self;
  return (const char *)0x69faac;
}
PCREG(51f240, heliIfTypeName);

// ZTankIf::getTypeName() (medium): returns the exe string at 0x6a073c.
static const char *THISCALL tankIfTypeName(u8 *self) {
  (void)self;
  return (const char *)0x6a073c;
}
PCREG(522ce0, tankIfTypeName);

// ZMatPosAnim::SetRotMat(float*) (medium): the original calls 0x4de420 with ecx = this+0x93, edx = the argument.
// That callee copies 0x24 bytes (two 16-byte moves and one dword) from the argument to ecx. Same bytes here.
static void THISCALL matPosAnimSetRotMat(u8 *self, const u8 *m) {
  for (u32 i = 0; i < 0x24; ++i) self[0x93 + i] = m[i];
}
PCREG(4a5fc0, matPosAnimSetRotMat);
