// batch1602.cpp - unclaimed-16 batch 2 (docs/20-unclaimed-16.md): CAction::SetPriority and SetType, the three
// ZActor path-notify functions (OnPathCanceled, OnPathCanceledLockedDoor, OnPathError) and ZActor::GetMoveFlags.
// Names are from the GC name map (naming only, GUESS where the map is low confidence); the bodies are from the PC bytes.
#include "ff.h"

// Calls slot 0x128 of obj's vtable as a thiscall with three stack arguments (the exe pushes them in this order).
typedef void(THISCALL *Fn3)(void *, u32, u32, u32);
static void callSlot128(void *obj, u32 a, u32 b, u32 c) {
  u32 *vt = *(u32 **)obj;
  ((Fn3)vt[0x128 / 4])(obj, a, b, c);
}

// 0x4a1d80, CAction::SetPriority(int) (medium): stores the argument at this+0x52; if the byte at this+0x63 is nonzero,
// calls slot 0x128 of the object at this+0x44 with (the word at 0x7002c8, 1, that object).
static void THISCALL actionSetPriority(u8 *self, u32 a1) {
  u8 flag = self[0x63];
  *(u32 *)(self + 0x52) = a1;
  if (flag) {
    u8 *sub = *(u8 **)(self + 0x44);
    callSlot128(sub, *(u16 *)0x7002c8, 1, (u32)sub);
  }
}
PCREG(4a1d80, actionSetPriority);

// 0x4a1db0, CAction::SetType(EActionType) (high): same as SetPriority, but the argument goes to this+0x48.
static void THISCALL actionSetType(u8 *self, u32 a1) {
  u8 flag = self[0x63];
  *(u32 *)(self + 0x48) = a1;
  if (flag) {
    u8 *sub = *(u8 **)(self + 0x44);
    callSlot128(sub, *(u16 *)0x7002c8, 1, (u32)sub);
  }
}
PCREG(4a1db0, actionSetType);

// 0x479810, ZActor::OnPathCanceled(ZActor::PATH_CANCEL_REASONS) (high): calls this's slot 0x128 with
// (the word at 0x6ffa2c, the argument, 0), then clears the dword at this+0x6ba and the byte at this+0x6be.
static void THISCALL actorOnPathCanceled(u8 *self, u32 a1) {
  callSlot128(self, *(u16 *)0x6ffa2c, a1, 0);
  *(u32 *)(self + 0x6ba) = 0;
  self[0x6be] = 0;
}
PCREG(479810, actorOnPathCanceled);

// 0x479850, ZActor::OnPathCanceledLockedDoor(unsigned int) (high): as OnPathCanceled, with the word at 0x6ffa30.
static void THISCALL actorOnPathCanceledLockedDoor(u8 *self, u32 a1) {
  callSlot128(self, *(u16 *)0x6ffa30, a1, 0);
  *(u32 *)(self + 0x6ba) = 0;
  self[0x6be] = 0;
}
PCREG(479850, actorOnPathCanceledLockedDoor);

// 0x479890, ZActor::OnPathError(ZActor::PATH_ERRORS) (high): as OnPathCanceled, with the word at 0x6ffa34.
static void THISCALL actorOnPathError(u8 *self, u32 a1) {
  callSlot128(self, *(u16 *)0x6ffa34, a1, 0);
  *(u32 *)(self + 0x6ba) = 0;
  self[0x6be] = 0;
}
PCREG(479890, actorOnPathError);

// 0x478c90, ZActor::GetMoveFlags(unsigned int) const (low): a jump table on (arg - 1) for 1..19. Arguments 6 to 10
// return 0x40c; every other value returns 0x400 (the table at 0x478cb8 sends 1..5 and 11..19 and the default there).
static u32 THISCALL actorGetMoveFlags(u8 *self, u32 a1) {
  (void)self;
  if (a1 >= 6 && a1 <= 10)
    return 0x40c;
  return 0x400;
}
PCREG(478c90, actorGetMoveFlags);
