// batch213.cpp - hero action slots, next layer (inline-ladder thread, 2026-10-11): the ZIKLNKOBJ members that forward
// to the action dispatcher at +0x1ce, and ZActionDispatcher itself. Every ZActor-derived class shares these
// (vtable slots 240..247 of ZActor; RunLnkAction, slot 241, is batch 207).
// ZLnkAction interface as used here (slot byte offsets): 0 deleting destructor, 4 id, 8 Execute -> bool,
// 0xc CallBack -> bool, 0x10 Update -> bool, 0x14 Terminate. ZActionDispatcher (vtable 0x68b164, 12 bytes:
// +4 current action, +8 owner): 0 deleting destructor, 4 Execute(action), 8 Update, 0xc CallBack, 0x10 DropAction,
// 0x14 RemoveCurrentAction.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void *ext_41e290(u32 size);                    // __builtin_new, cdecl
extern "C" void *THISCALL ext_47fb10(void *o, void *owner); // ZActionDispatcher::ZActionDispatcher (below)
extern "C" void ext_634273(void *p, u32 size);            // __builtin_delete (sized), cdecl

static inline void *disp(u8 *self) { return (void *)U32(self, 0x1ce); }

// 0x466380 ZIKLNKOBJ::CreateActionDispatcher() [GameCube reference, medium; ZActor slot 240]: +0x1ce = new ZActionDispatcher(this)
// (12 bytes), or 0 when operator new fails. The exe's SEH frame only covers a throwing constructor.
static void THISCALL ikCreateActionDispatcher(u8 *self) {
  void *p = ext_41e290(0xc);
  U32(self, 0x1ce) = p ? (u32)ext_47fb10(p, self) : 0;
}
PCREG(466380, ikCreateActionDispatcher);

// 0x4675d0 ZIKLNKOBJ::RemoveCurrentLnkAction() [GameCube reference, medium; slot 242]: tail call to dispatcher slot 0x10.
static u32 THISCALL ikRemoveCurrentLnkAction(u8 *self) { return vcall<u32>(disp(self), 0x10); }
PCREG(4675d0, ikRemoveCurrentLnkAction);

// 0x467cf0 ZIKLNKOBJ::UpdateCurrentLnkAction() [GameCube reference, medium; slot 243]: tail call to dispatcher slot 8 (Update).
static u32 THISCALL ikUpdateCurrentLnkAction(u8 *self) { return vcall<u32>(disp(self), 8); }
PCREG(467cf0, ikUpdateCurrentLnkAction);

// 0x465a70 ZIKLNKOBJ::CallBackLnkActionTarget() [GameCube reference, medium; slot 244]: tail call to dispatcher slot 0xc.
static u32 THISCALL ikCallBackLnkActionTarget(u8 *self) { return vcall<u32>(disp(self), 0xc); }
PCREG(465a70, ikCallBackLnkActionTarget);

// 0x465a60 ZIKLNKOBJ::CallBackLnkActionBone(ZBoneAnim*, float, float, unsigned) [GameCube reference, medium; slot 245],
// ret 0x10, AL = 1. Calls dispatcher slot 0xc (CallBack) and ignores all four arguments.
static bool THISCALL ikCallBackLnkActionBone(u8 *self, u32, u32, u32, u32) {
  vcall<u32>(disp(self), 0xc);
  return true;
}
PCREG(465a60, ikCallBackLnkActionBone);

// 0x466400 ZIKLNKOBJ::CurrentLnkActionId() const [GameCube reference, medium; slot 247]: the current action's slot 4 (its id),
// or 0 when the dispatcher has no current action.
static u32 THISCALL ikCurrentLnkActionId(u8 *self) {
  void *a = (void *)U32(disp(self), 4);
  if (!a)
    return 0;
  return vcall<u32>(a, 4);
}
PCREG(466400, ikCurrentLnkActionId);

// 0x47fb10 ZActionDispatcher::ZActionDispatcher(ZIKLNKOBJ *owner) [GameCube reference, low (call-graph match)], ret 4.
static void *THISCALL adCtor(u8 *self, u32 owner) {
  U32(self, 8) = owner;
  U32(self, 0) = 0x68b164;
  U32(self, 4) = 0;
  return self;
}
PCREG(47fb10, adCtor);

// 0x47fb30 ZActionDispatcher scalar deleting destructor [GameCube reference, medium; slot 0], ret 4: deletes the current
// action (its slot 0 with 1) and frees 12 bytes when flags bit 0.
static void *THISCALL adDtor(u8 *self, u32 flags) {
  void *a = (void *)U32(self, 4);
  U32(self, 0) = 0x68b164;
  if (a)
    vcall<void>(a, 0, 1u);
  if (flags & 1)
    ext_634273(self, 0xc);
  return self;
}
PCREG(47fb30, adDtor);

// 0x47fb70 ZActionDispatcher::CallBack() [GameCube reference, medium; slot 3]: when there is a current action and its
// CallBack (slot 0xc) returns false, tail-calls own slot 0x14 (RemoveCurrentAction). Returns the last call's EAX.
static u32 THISCALL adCallBack(u8 *self) {
  void *a = (void *)U32(self, 4);
  if (!a)
    return (u32)a;
  u32 r = vcall<u32>(a, 0xc);
  if ((u8)r)
    return r;
  return vcall<u32>(self, 0x14);
}
PCREG(47fb70, adCallBack);

// 0x47fb90 ZActionDispatcher::DropAction() [GameCube reference, low; slot 4]: own slot 0x14 when there is a current action.
// (EAX is left as is when there is nothing to drop, so the result is not part of the contract.)
static void THISCALL adDropAction(u8 *self) {
  if (U32(self, 4) != 0)
    vcall<void>(self, 0x14);
}
PCREG(47fb90, adDropAction);

// 0x47fba0 ZActionDispatcher::Execute(ZLnkAction *a) [GameCube reference, medium; slot 1], ret 4, AL: current = a; if a's
// Execute (slot 8) fails, own slot 0x14 (RemoveCurrentAction) and false; else true.
static bool THISCALL adExecute(u8 *self, void *a) {
  U32(self, 4) = (u32)a;
  if ((u8)vcall<u32>(a, 8))
    return true;
  vcall<void>(self, 0x14);
  return false;
}
PCREG(47fba0, adExecute);

// 0x47fbe0 ZActionDispatcher::RemoveCurrentAction() [GameCube reference, medium; slot 5]: the current action's Terminate
// (slot 0x14), then delete it (slot 0 with 1; +4 is read again), current = 0. Nothing when there is none.
static void THISCALL adRemoveCurrentAction(u8 *self) {
  void *a = (void *)U32(self, 4);
  if (!a)
    return;
  vcall<void>(a, 0x14);
  a = (void *)U32(self, 4);
  if (a)
    vcall<void>(a, 0, 1u);
  U32(self, 4) = 0;
}
PCREG(47fbe0, adRemoveCurrentAction);

// 0x47fc10 ZActionDispatcher::Update() [GameCube reference, medium; slot 2]: as CallBack with the action's Update (slot 0x10).
static u32 THISCALL adUpdate(u8 *self) {
  void *a = (void *)U32(self, 4);
  if (!a)
    return (u32)a;
  u32 r = vcall<u32>(a, 0x10);
  if ((u8)r)
    return r;
  return vcall<u32>(self, 0x14);
}
PCREG(47fc10, adUpdate);
