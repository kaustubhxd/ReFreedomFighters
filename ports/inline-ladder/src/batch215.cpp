// batch215.cpp - hero action bodies (inline-ladder thread, 2026-10-11): shared deleting destructors,
// ZFFActionFFCommand::Execute and ZFFActionPickupItem::Execute. Base ZLnkAction vtable 0x685294.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void ext_634273(void *p, u32 size);   // __builtin_delete (sized), cdecl

// Scalar deleting destructors: vtable back to the base ZLnkAction (0x685294), sized delete when flags bit 0, return this.
// 0x5df7f0 (16 bytes): ZFFActionSwingBat, ZFFActionUseKnife and ZFFActionClimbSewer share it (identical code folding).
static void *THISCALL dtor16(u8 *self, u32 flags) {
  U32(self, 0) = 0x685294;
  if (flags & 1)
    ext_634273(self, 0x10);
  return self;
}
PCREG(5df7f0, dtor16);
// 0x5df820 (0x15 bytes): ZFFActionFFCommand.
static void *THISCALL dtor15(u8 *self, u32 flags) {
  U32(self, 0) = 0x685294;
  if (flags & 1)
    ext_634273(self, 0x15);
  return self;
}
PCREG(5df820, dtor15);
// 0x485f30 (0x18 bytes): ZFFActionUseHealth and four ZAction* classes of the same size (folded).
static void *THISCALL dtor18(u8 *self, u32 flags) {
  U32(self, 0) = 0x685294;
  if (flags & 1)
    ext_634273(self, 0x18);
  return self;
}
PCREG(485f30, dtor18);

// 0x5e0250 ZFFActionFFCommand::Execute() [, medium; slot 2], thiscall, AL = 0 (the action ends at once).
// Fields: +8 hero, +0xc animation with a rifle, +0x10 animation otherwise, byte +0x14 flag (true for id 0x1a).
// Picks +0xc when the held item (hero slot 0x504) is a weapon (slot 0x1e0(0x1007d2)) whose kind (slot 0x330 of its slot
// 0x350 object) is 2..7, else +0x10; plays it with hero slot 0x228(anim, 1, 0.0, -1.0, 1.0); with the flag set, hero
// byte +0x94e = 1.
static bool THISCALL ffCommandExecute(u8 *self) {
  void *hero = (void *)U32(self, 8);
  void *w = vcall<void *>(hero, 0x504);
  u32 anim = U32(self, 0x10);
  if (w && (u8)vcall<u32>(w, 0x1e0, 0x1007d2u)) {
    void *t = vcall<void *>(w, 0x350);
    u32 k = vcall<u32>(t, 0x330);
    if (k - 2 <= 5)
      anim = U32(self, 0xc);
  }
  vcall<void>((void *)U32(self, 8), 0x228, anim, 1u, 0u, 0xbf800000u, 0x3f800000u);
  if (self[0x14])
    ((u8 *)U32(self, 8))[0x94e] = 1;
  return false;
}
PCREG(5e0250, ffCommandExecute);

// 0x5e0330 ZFFActionPickupItem::Execute() [, medium; slot 2], thiscall, AL = 0.
// +8 the item, +0xc the hero, +0x10 the hand. item slot 0x144("QRigidBody") (0x68ce24); when item slot
// 0x1e0(0x1007d8) is true: item slot 0x2d0(1, 0), then item slot 0x2f0(ref(hero), 0, 1) with ref = database slot 0x4c
// (GeomToRef); the item's vtable is read before the database call. Otherwise hand slot 8(hero, ref(item)).
static bool THISCALL pickupExecute(u8 *self) {
  vcall<void>((void *)U32(self, 8), 0x144, (const char *)0x68ce24);
  if ((u8)vcall<u32>((void *)U32(self, 8), 0x1e0, 0x1007d8u)) {
    vcall<void>((void *)U32(self, 8), 0x2d0, 1u, 0u);
    u8 **item = (u8 **)U32(self, 8);
    u8 *vt = *item;
    u32 ref = vcall<u32>((void *)U32(G(u32, 0x70039c), 0x9b), 0x4c, U32(self, 0xc));
    typedef void(THISCALL * fn)(void *, u32, u32, u32);
    (*(fn *)(vt + 0x2f0))((void *)U32(self, 8), ref, 0u, 1u);
    return false;
  }
  u32 ref = vcall<u32>((void *)U32(G(u32, 0x70039c), 0x9b), 0x4c, U32(self, 8));
  vcall<void>((void *)U32(self, 0x10), 8, U32(self, 0xc), ref);
  return false;
}
PCREG(5e0330, pickupExecute);
