// batch206.cpp - hero action slot tree (inline-ladder thread, 2026-10-11): the ZFFAction* constructors that
// ZFFHERO::CreateLnkAction (0x590820, vtable slot 0x3ec) calls. Class names are certain: each vtable address is the
// class's MSVC RTTI vtable (ffre.PC().vtables()), and the GC CreateLnkAction calls the same ten constructors in the
// same case order. ZFFActionThrow's constructor (0x5df750) is batch 12 (initFive) and is not repeated here.
// All are thiscall, return this. Field names are not known; offsets only.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

// 0x5df5f0 ZFFActionClimbSewer::ZFFActionClimbSewer(unsigned id, ZFFHERO *hero, AnimHeader *anim), ret 0xc.
static void *THISCALL ctorClimbSewer(u8 *o, u32 id, u32 hero, u32 anim) {
  U32(o, 4) = id;
  U32(o, 8) = hero;
  U32(o, 0xc) = anim;
  U32(o, 0) = 0x6b7478;
  return o;
}
PCREG(5df5f0, ctorClimbSewer);

// 0x5df620 ZFFActionDropC4::ZFFActionDropC4(unsigned id, ZLNKWHANDS *hands, ZIKHAND *hand, AnimHeader *anim), ret 0x10.
static void *THISCALL ctorDropC4(u8 *o, u32 id, u32 hands, u32 hand, u32 anim) {
  U32(o, 4) = id;
  U32(o, 8) = hands;
  U32(o, 0xc) = hand;
  U32(o, 0x10) = anim;
  U32(o, 0) = 0x6b7388;
  return o;
}
PCREG(5df620, ctorDropC4);

// 0x5df650 ZFFActionFFCommand::ZFFActionFFCommand(unsigned id, ZFFHERO *hero, AnimHeader *a, AnimHeader *b, bool flag),
// ret 0x14; the bool is the low byte of the fifth argument, stored at +0x14.
static void *THISCALL ctorFFCommand(u8 *o, u32 id, u32 hero, u32 a, u32 b, u32 flag) {
  U32(o, 4) = id;
  U32(o, 8) = hero;
  U32(o, 0xc) = a;
  U32(o, 0x10) = b;
  o[0x14] = (u8)flag;
  U32(o, 0) = 0x6b7450;
  return o;
}
PCREG(5df650, ctorFFCommand);

// 0x5df690 ZFFActionGetBack::ZFFActionGetBack(unsigned id, ZFFHERO *hero, ZIKHAND *hand, AnimHeader *anim), ret 0x10.
static void *THISCALL ctorGetBack(u8 *o, u32 id, u32 hero, u32 hand, u32 anim) {
  U32(o, 4) = id;
  U32(o, 8) = hero;
  U32(o, 0xc) = hand;
  U32(o, 0x10) = anim;
  U32(o, 0) = 0x6b7400;
  return o;
}
PCREG(5df690, ctorGetBack);

// 0x5df6c0 ZFFActionPickupItem::ZFFActionPickupItem(unsigned id, ZFFHERO *hero, ZIKHAND *hand), ret 0xc. +8 is zeroed;
// hero and hand go to +0xc and +0x10.
static void *THISCALL ctorPickupItem(u8 *o, u32 id, u32 hero, u32 hand) {
  U32(o, 4) = id;
  U32(o, 0xc) = hero;
  U32(o, 0x10) = hand;
  U32(o, 0) = 0x6b7310;
  U32(o, 8) = 0;
  return o;
}
PCREG(5df6c0, ctorPickupItem);

// 0x5df6f0 ZFFActionPutBack::ZFFActionPutBack(unsigned id, ZFFHERO *hero, ZIKHAND *hand, AnimHeader *anim), ret 0x10.
static void *THISCALL ctorPutBack(u8 *o, u32 id, u32 hero, u32 hand, u32 anim) {
  U32(o, 4) = id;
  U32(o, 8) = hero;
  U32(o, 0xc) = hand;
  U32(o, 0x10) = anim;
  U32(o, 0) = 0x6b73d8;
  return o;
}
PCREG(5df6f0, ctorPutBack);

// 0x5df720 ZFFActionSwingBat::ZFFActionSwingBat(unsigned id, ZFFHERO *hero, AnimHeader *anim), ret 0xc.
static void *THISCALL ctorSwingBat(u8 *o, u32 id, u32 hero, u32 anim) {
  U32(o, 4) = id;
  U32(o, 8) = hero;
  U32(o, 0xc) = anim;
  U32(o, 0) = 0x6b7360;
  return o;
}
PCREG(5df720, ctorSwingBat);

// 0x5df790 ZFFActionUseHealth::ZFFActionUseHealth(unsigned id, ZLNKWHANDS *hands, ZIKHAND *hand, AnimHeader *anim),
// ret 0x10. The id is stored twice, at +4 and +0x14.
static void *THISCALL ctorUseHealth(u8 *o, u32 id, u32 hands, u32 hand, u32 anim) {
  U32(o, 8) = hands;
  U32(o, 0xc) = hand;
  U32(o, 0x10) = anim;
  U32(o, 4) = id;
  U32(o, 0) = 0x6b73b0;
  U32(o, 0x14) = id;
  return o;
}
PCREG(5df790, ctorUseHealth);

// 0x5df7c0 ZFFActionUseKnife::ZFFActionUseKnife(unsigned id, ZFFHERO *hero, const SAnimations *anims), ret 0xc.
static void *THISCALL ctorUseKnife(u8 *o, u32 id, u32 hero, u32 anims) {
  U32(o, 4) = id;
  U32(o, 8) = hero;
  U32(o, 0xc) = anims;
  U32(o, 0) = 0x6b7428;
  return o;
}
PCREG(5df7c0, ctorUseKnife);
