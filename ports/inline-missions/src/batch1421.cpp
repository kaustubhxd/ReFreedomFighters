// batch1421.cpp - missions thread, batch 1421: ZFFCareTaker_C04B (the rebel-base director) Init, Init2 and the deleting
// destructor. Command (0x5bc6e0, 247 instructions) is not in this batch.
//
// Layout: +0x44 event sender, +0x48 hero handle ("ObjectHero", Init2), +0x4c word (cleared in Init2), +0x52 and +0x56
// dwords read from the event data by Init.
#include "missions.h"

extern "C" u32 THISCALL ext_4e5e60(u32 *db);   // DBREAD::operator unsigned int()
#define CARETAKER_C04B_CPP 0x6b2cd8u   // (string at 0x6b2cd8 is "ObjectItemNotify")

static inline u8 *sysi() { return G(u8 *, 0x70039c); }
static inline u8 *mgr() { return *(u8 **)(sysi() + 0x9b); }

// 0x5bc620 ZFFCareTaker_C04B::Init(ZGROUP*, DBREAD&): reads +0x56 then +0x52 from the data, then registers itself
// as "ObjectItemNotify" (manager slot 0x4c(sender, 0x10) -> handle, registry slot 0x60(name, handle)).
static void THISCALL c04bInit(u8 *ct, void *group, u32 *db) {
  (void)group;
  *(u32 *)(ct + 0x56) = ext_4e5e60(db);
  *(u32 *)(ct + 0x52) = ext_4e5e60(db);
  u8 *reg = vcall<u8 *>(mgr(), 0x138);
  u32 t = vcall<u32, u32, u32>(mgr(), 0x4c, *(u32 *)(ct + 0x44), 0x10);
  vcall<void, const char *, u32>(reg, 0x60, (const char *)CARETAKER_C04B_CPP, t);
}
PCREG(5bc620, c04bInit);

// 0x5bc680 ZFFCareTaker_C04B::Init2(): the hero ("ObjectHero") into +0x48, +0x4c cleared.
static void THISCALL c04bInit2(u8 *ct) {
  u8 *reg = vcall<u8 *>(mgr(), 0x138);
  u32 h = 0;
  vcall<u32, const char *, u32 *>(reg, 0x88, (const char *)0x6ac89c, &h);
  *(u32 *)(ct + 0x48) = vcall<u32, u32>(mgr(), 0x58, h);
  *(u16 *)(ct + 0x4c) = 0;
}
PCREG(5bc680, c04bInit2);

// 0x57fe70 ZFFCareTaker_C04B deleting destructor: the ZEventBase part (sender cleared, vtable 0x686874, manager slot
// 0x34 unregisters), then the free rule. Object size 0x5a (flag-4 path).
static u8 *THISCALL c04bDtor(u8 *ct, u32 flags) {
  *(u32 *)(ct + 0x44) = 0;
  *(u32 *)(ct + 0x30) = 0;
  *(u32 *)ct = 0x686874;
  vcall<void, u8 *>(mgr(), 0x34, ct);
  return deletingDtor(ct, flags, 0x5a);
}
PCREG(57fe70, c04bDtor);
