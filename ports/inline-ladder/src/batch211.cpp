// batch211.cpp - base action set (inline-ladder thread, 2026-10-11): ZAction* constructors used by
// ZLNKWHANDS::CreateLnkAction (0x4733d0). Class names from the RTTI vtables (ffre.PC().vtables()). The other three
// constructors of the set were lifted earlier without names: 0x485d30 = ZActionGetItem (batch 12 "initFive"),
// 0x485ca0 = ZActionChamberItem (batch 22 "initRec9"), 0x485e30 = ZActionReloadItem (batch 22 "initRec10").
// All thiscall, return this.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

// 0x485d00 ZActionDropItem::ZActionDropItem(unsigned id, ZLNKWHANDS *hands, ZIKHAND *hand, AnimHeader *anim), ret 0x10.
static void *THISCALL ctorDropItem(u8 *o, u32 id, u32 hands, u32 hand, u32 anim) {
  U32(o, 4) = id;
  U32(o, 8) = hands;
  U32(o, 0xc) = hand;
  U32(o, 0x10) = anim;
  U32(o, 0) = 0x68cc90;
  return o;
}
PCREG(485d00, ctorDropItem);

// 0x485d70 ZActionPickupItem::ZActionPickupItem(unsigned id, ZLNKWHANDS *hands, ZIKHAND *hand, AnimHeader *anim),
// ret 0x10; +8 zeroed, the three pointers at +0xc..+0x14.
static void *THISCALL ctorPickupItemBase(u8 *o, u32 id, u32 hands, u32 hand, u32 anim) {
  U32(o, 4) = id;
  U32(o, 0xc) = hands;
  U32(o, 0x10) = hand;
  U32(o, 0x14) = anim;
  U32(o, 0) = 0x68cc54;
  U32(o, 8) = 0;
  return o;
}
PCREG(485d70, ctorPickupItemBase);

// 0x485db0 ZActionPushButton::ZActionPushButton(unsigned id, ZLNKWHANDS *hands, ZIKHAND *hand, AnimHeader *anim),
// ret 0x10; same layout as PickupItem with its own vtable.
static void *THISCALL ctorPushButton(u8 *o, u32 id, u32 hands, u32 hand, u32 anim) {
  U32(o, 4) = id;
  U32(o, 0xc) = hands;
  U32(o, 0x10) = hand;
  U32(o, 0x14) = anim;
  U32(o, 0) = 0x68cd00;
  U32(o, 8) = 0;
  return o;
}
PCREG(485db0, ctorPushButton);

// 0x485df0 ZActionPutItem::ZActionPutItem(unsigned id, ZLNKWHANDS *hands, ZIKHAND *hand, AnimHeader *a, AnimHeader *b),
// ret 0x14.
static void *THISCALL ctorPutItem(u8 *o, u32 id, u32 hands, u32 hand, u32 a, u32 b) {
  U32(o, 4) = id;
  U32(o, 8) = hands;
  U32(o, 0xc) = hand;
  U32(o, 0x10) = a;
  U32(o, 0x14) = b;
  U32(o, 0) = 0x68cc1c;
  return o;
}
PCREG(485df0, ctorPutItem);

// 0x485e90 ZActionSwapItems::ZActionSwapItems(unsigned id, ZLNKWHANDS *hands, ZIKHAND *from, ZIKHAND *to,
// AnimHeader *anim), ret 0x14.
static void *THISCALL ctorSwapItems(u8 *o, u32 id, u32 hands, u32 from, u32 to, u32 anim) {
  U32(o, 4) = id;
  U32(o, 8) = hands;
  U32(o, 0xc) = from;
  U32(o, 0x10) = to;
  U32(o, 0x14) = anim;
  U32(o, 0) = 0x68ccc8;
  return o;
}
PCREG(485e90, ctorSwapItems);
