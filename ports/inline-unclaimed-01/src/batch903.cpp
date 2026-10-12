#include "ff.h"
// batch903.cpp - unclaimed-01 claim 2 (docs/20-unclaimed-01.md): ZActor setters and ZInputAction::SetActive.
// Names from the GC name map (naming only). Every function is thiscall with one argument (ret 4) except
// SetActorState, which returns the old value in eax.

// 0x47bfc0, ZActor::SetPathNotify(float) (high): float bits to this+0x6ba.
static void THISCALL actorSetPathNotify(u8 *self, u32 a1) {
  *(u32 *)(self + 0x6ba) = a1;
}
PCREG(47bfc0, actorSetPathNotify);

// 0x47bfe0, ZActor::SetPathNotifySyncToCycle(bool) (high): low byte of the argument to this+0x6be.
static void THISCALL actorSetPathNotifySyncToCycle(u8 *self, u32 a1) {
  self[0x6be] = (u8)a1;
}
PCREG(47bfe0, actorSetPathNotifySyncToCycle);

// 0x47c130, ZActor::SetStayInsidePath(bool) (high): low byte of the argument to this+0x6c4.
static void THISCALL actorSetStayInsidePath(u8 *self, u32 a1) {
  self[0x6c4] = (u8)a1;
}
PCREG(47c130, actorSetStayInsidePath);

// 0x47c140, ZActor::SetStopDistance(float) (high): float bits to this+0x6b2.
static void THISCALL actorSetStopDistance(u8 *self, u32 a1) {
  *(u32 *)(self + 0x6b2) = a1;
}
PCREG(47c140, actorSetStopDistance);

// 0x47bcc0, ZActor::SetActorState(ZActor::ACTORSTATE) (high): eax gets the old dword at this+0x65c, then the
// argument is stored there. The function is void in name; the caller can read the old state from eax.
static u32 THISCALL actorSetActorState(u8 *self, u32 a1) {
  u32 old = *(u32 *)(self + 0x65c);
  *(u32 *)(self + 0x65c) = a1;
  return old;
}
PCREG(47bcc0, actorSetActorState);

// 0x47bed0, ZActor::SetMoveSet(const ZActor::SMoveSet*) (high): index = the dword at the argument; stores the argument
// pointer at this + 0x49a + 4*index.
static void THISCALL actorSetMoveSet(u8 *self, u32 a1) {
  u32 index = *(u32 *)a1;
  *(u32 *)(self + 0x49a + index * 4u) = a1;
}
PCREG(47bed0, actorSetMoveSet);

// 0x43afd0, ZInputAction::SetActive(bool) (high): low byte of the argument to this+0x10.
static void THISCALL inputActionSetActive(u8 *self, u32 a1) {
  self[0x10] = (u8)a1;
}
PCREG(43afd0, inputActionSetActive);
