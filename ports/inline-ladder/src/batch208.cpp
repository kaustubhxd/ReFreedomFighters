// batch208.cpp - hero action slot 0x3ec (inline-ladder thread, 2026-10-11): ZFFHERO::CreateLnkAction.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void *ext_41e290(u32 size);   // __builtin_new (operator new), cdecl
extern "C" void *THISCALL ext_4733d0(void *self, u32 id);   // ZLNKWHANDS::CreateLnkAction (the base class's switch)
extern "C" void *THISCALL ext_5df5f0(void *o, u32 id, void *hero, u32 anim);                        // ClimbSewer
extern "C" void *THISCALL ext_5df620(void *o, u32 id, void *hands, u32 hand, u32 anim);             // DropC4
extern "C" void *THISCALL ext_5df650(void *o, u32 id, void *hero, u32 a, u32 b, u32 flag);          // FFCommand
extern "C" void *THISCALL ext_5df690(void *o, u32 id, void *hero, u32 hand, u32 anim);              // GetBack
extern "C" void *THISCALL ext_5df6c0(void *o, u32 id, void *hero, u32 hand);                        // PickupItem
extern "C" void *THISCALL ext_5df6f0(void *o, u32 id, void *hero, u32 hand, u32 anim);              // PutBack
extern "C" void *THISCALL ext_5df720(void *o, u32 id, void *hero, u32 anim);                        // SwingBat
extern "C" void *THISCALL ext_5df750(void *o, u32 id, void *hero, u32 a, u32 b);                    // Throw (batch 12)
extern "C" void *THISCALL ext_5df790(void *o, u32 id, void *hands, u32 hand, u32 anim);             // UseHealth
extern "C" void *THISCALL ext_5df7c0(void *o, u32 id, void *hero, void *anims);                     // UseKnife

static inline u32 hand(u8 *self) { return vcall<u32>(self, 0x4f8); }   // slot 0x4f8: the hand holding the item (GetHand)

// 0x590820, ZFFHERO::CreateLnkAction(unsigned id) [GameCube reference, high], vtable slot 0x3ec (index 251), thiscall, ret 4,
// returns the new action or 0. A jump table on id - 4 (0..0x19). Each case calls operator new and, when that gives
// memory, the action's constructor (RTTI-named, batch 206) with fields of the hero as animations:
//   4 PickupItem (0x14 bytes; the hand), 0x11 Throw (0x22; +0x780, +0x784), 0x12 SwingBat (0x10; +0x788),
//   0x13 DropC4 (0x14; hand, +0x738), 0x14/0x15/0x16 UseHealth small/medium/large (0x18; hand, +0x734 for all three),
//   0x17 PutBack (0x14; hand, +0x72c), 0x18 GetBack (0x14; hand, +0x730), 0x19 UseKnife (0x10; &+0x77c, the knife
//   animation set), 0x1a/0x1b/0x1c FFCommand (0x15; (+0x76c, +0x760, 1), (+0x770, +0x764, 0), (+0x774, +0x768, 0)),
//   0x1d ClimbSewer (0x10; +0x778). Any other id goes to ZLNKWHANDS::CreateLnkAction (0x4733d0).
// The exe wraps each `new` in an SEH frame (constructor-throws cleanup); there is nothing to port in it.
static void *THISCALL createLnkAction(u8 *self, u32 id) {
  void *p;
  switch (id) {
  case 4: {
    p = ext_41e290(0x14);
    if (!p) return 0;
    u32 h = hand(self);
    return ext_5df6c0(p, 4, self, h);
  }
  case 0x11:
    p = ext_41e290(0x22);
    if (!p) return 0;
    return ext_5df750(p, 0x11, self, U32(self, 0x780), U32(self, 0x784));
  case 0x12:
    p = ext_41e290(0x10);
    if (!p) return 0;
    return ext_5df720(p, 0x12, self, U32(self, 0x788));
  case 0x13: {
    p = ext_41e290(0x14);
    if (!p) return 0;
    u32 anim = U32(self, 0x738);
    u32 h = hand(self);
    return ext_5df620(p, 0x13, self, h, anim);
  }
  case 0x14:
  case 0x15:
  case 0x16: {
    p = ext_41e290(0x18);
    if (!p) return 0;
    u32 anim = U32(self, 0x734);
    u32 h = hand(self);
    return ext_5df790(p, id, self, h, anim);
  }
  case 0x17: {
    p = ext_41e290(0x14);
    if (!p) return 0;
    u32 anim = U32(self, 0x72c);
    u32 h = hand(self);
    return ext_5df6f0(p, 0x17, self, h, anim);
  }
  case 0x18: {
    p = ext_41e290(0x14);
    if (!p) return 0;
    u32 anim = U32(self, 0x730);
    u32 h = hand(self);
    return ext_5df690(p, 0x18, self, h, anim);
  }
  case 0x19:
    p = ext_41e290(0x10);
    if (!p) return 0;
    return ext_5df7c0(p, 0x19, self, self + 0x77c);
  case 0x1a:
    p = ext_41e290(0x15);
    if (!p) return 0;
    return ext_5df650(p, 0x1a, self, U32(self, 0x76c), U32(self, 0x760), 1);
  case 0x1b:
    p = ext_41e290(0x15);
    if (!p) return 0;
    return ext_5df650(p, 0x1b, self, U32(self, 0x770), U32(self, 0x764), 0);
  case 0x1c:
    p = ext_41e290(0x15);
    if (!p) return 0;
    return ext_5df650(p, 0x1c, self, U32(self, 0x774), U32(self, 0x768), 0);
  case 0x1d:
    p = ext_41e290(0x10);
    if (!p) return 0;
    return ext_5df5f0(p, 0x1d, self, U32(self, 0x778));
  default:
    return ext_4733d0(self, id);
  }
}
PCREG(590820, createLnkAction);
