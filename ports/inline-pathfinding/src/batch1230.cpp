// batch1230.cpp - pathfinding tree: ZActor path-cancel and path-error notices. Each sends its message id (a u16 global)
// with the argument and 0 through the actor's vtable slot +0x128, then clears the notify interval (+0x6ba) and the
// sync flag (+0x6be). thiscall, ret 4.
#include "pf.h"

static void sendPathNotice(u8 *self, u16 msg, u32 arg) {
  vcall<void>(self, 0x128, (u32)msg, arg, (u32)0);
  *(u32 *)(self + 0x6ba) = 0;
  self[0x6be] = 0;
}

static void THISCALL actorOnPathCanceled(u8 *self, u32 reason) {        // 0x479810; msg global 0x6ffa2c
  sendPathNotice(self, G(u16, 0x6ffa2c), reason);
}
PCREG(479810, actorOnPathCanceled);

static void THISCALL actorOnPathCanceledLockedDoor(u8 *self, u32 door) {  // 0x479850; msg global 0x6ffa30
  sendPathNotice(self, G(u16, 0x6ffa30), door);
}
PCREG(479850, actorOnPathCanceledLockedDoor);

static void THISCALL actorOnPathError(u8 *self, u32 error) {            // 0x479890; msg global 0x6ffa34
  sendPathNotice(self, G(u16, 0x6ffa34), error);
}
PCREG(479890, actorOnPathError);
