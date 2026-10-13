// batch1419.cpp - missions thread, batch 1419: ZFFCareTaker_C03A (the bridge: place the bomb, blow the bridge,
// stop the train).
//
// C03A fields: +0x48 the hero ("ObjectHero"), +0x4c bool, +0x4d float, +0x51 the bomb target, +0x55 the train,
// +0x59 the car to kill, +0x5d a dword (saved only).
#include "missions.h"

extern "C" u32 THISCALL ext_4e5e60(u32 *db);   // DBREAD::operator unsigned int()
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);   // PSVECSubtract (dst = a - b)
typedef double(VECTORCALL *libm1)(double);
#define CARETAKER_C03A_CPP 0x6b2cecu

static inline u8 *sysi() { return G(u8 *, 0x70039c); }
static inline u8 *mgr() { return *(u8 **)(sysi() + 0x9b); }
static inline u8 *byHandle(u32 h) { return vcall<u8 *, u32>(mgr(), 0x58, h); }
static inline u16 msgId(const char *name, u32 line) {
  return vcall<u16, const char *, u32, const char *, u32>(mgr(), 0x114, name, 0, (const char *)CARETAKER_C03A_CPP, line);
}
static inline void send(u8 *ct, u32 target, u32 msg) {
  vcall<void, u32, u32, u32>(*(u8 **)(ct + 0x44), 0x12c, target, msg, 0);
}
#define U32(o) (*(u32 *)(ct + (o)))
// Registers itself as "ObjectItemNotify" (registry slot 0x60(name, manager slot 0x4c(sender), 0x10)), so items
// report to it.
static void registerSelf(u8 *ct) {
  u8 *reg = vcall<u8 *>(mgr(), 0x138);
  u32 t = vcall<u32, u32, u32>(mgr(), 0x4c, U32(0x44), 0x10);   // manager slot 0x4c(sender, 0x10) -> handle
  vcall<void, const char *, u32>(reg, 0x60, (const char *)0x6b2cd8, t);   // registry slot 0x60(name, handle)
}
// Distance between two points as the original computes it: x87-free SSE squares, sum in the order y+x then +z,
// CRT sqrt on the double, rounded to float.
static float dist(const float *a, const float *b) {
  float d[3];
  ext_43e920(d, a, b);
  float s = d[1] * d[1] + d[0] * d[0];
  s = s + d[2] * d[2];
  return (float)(*(libm1 *)0x676330)((double)s);
}

// 0x5bbcb0 ZFFCareTaker_C03A::Command(unsigned short msg, void *data). data = {?, handle}. Returns 0.
//  MSG_EVENT_STARTED from the bomb (handle): within 1000 units of the target (+0x51), BOMB_WAS_PLACED is sent to the
//    target and "A bomb was placed correctly" logged; otherwise "placed too far away" is logged.
//  MSG_ITEMNOTIFY from an item: within 1000 units of the target, BLOW_BRIDGE to the target, CarKill to +0x59 and
//    TRAIN_STOP_NOW to the train (+0x55). Either way the item's geom gets slot 0x2f0(0, 0, 1) and slot 0x210(1).
static u32 THISCALL c03aCommand(u8 *ct, u32 msg, u32 *data) {
  u16 m = (u16)msg;
  float mat[9], p1[3], p2[3];
  if (m == msgId((const char *)0x6b2d24, 0x2d)) {   // MSG_EVENT_STARTED
    vcall<void, float *, float *>(byHandle(data[1]), 0x80, mat, p1);
    vcall<void, float *, float *>(byHandle(U32(0x51)), 0x80, mat, p2);
    if (comiss_gt(1000.0f, dist(p1, p2))) {
      send(ct, U32(0x51), msgId((const char *)0x6a4e0c, 0x42));   // BOMB_WAS_PLACED
      LOGF(CARETAKER_C03A_CPP, 0x43, (const char *)0x6b2d38);
    } else {
      LOGF(CARETAKER_C03A_CPP, 0x45, (const char *)0x6b2d68);
    }
  }
  if (m == msgId((const char *)0x6b2da8, 0x4b)) {   // MSG_ITEMNOTIFY
    u8 *item = byHandle(data[1]);
    vcall<void, float *, float *>(item, 0x80, mat, p2);
    vcall<void, float *, float *>(byHandle(U32(0x51)), 0x80, mat, p1);
    if (comiss_gt(1000.0f, dist(p2, p1))) {
      send(ct, U32(0x51), msgId((const char *)0x6b2db8, 0x67));   // BLOW_BRIDGE
      send(ct, U32(0x59), msgId((const char *)0x6a51e8, 0x6a));   // CarKill
      send(ct, U32(0x55), msgId((const char *)0x6b2dc4, 0x6d));   // TRAIN_STOP_NOW
    }
    u8 *g = vcall<u8 *>(item, 0x20);
    vcall<void, u32, u32, u32>(g, 0x2f0, 0, 0, 1);
    g = vcall<u8 *>(item, 0x20);
    if (g)
      vcall<void, u32>(g, 0x210, 1);
  }
  return 0;
}
PCREG(5bbcb0, c03aCommand);

// 0x5bbfe0 ZFFCareTaker_C03A::CopyEventDataBlock(DBREAD&): handles +0x51, +0x55, +0x59, registers "ObjectItemNotify",
// clears +0x4c.
static void THISCALL c03aCopyEventDataBlock(u8 *ct, u32 *db) {
  U32(0x51) = ext_4e5e60(db);
  U32(0x55) = ext_4e5e60(db);
  U32(0x59) = ext_4e5e60(db);
  registerSelf(ct);
  ct[0x4c] = 0;
}
PCREG(5bbfe0, c03aCopyEventDataBlock);

// 0x5bc050 ZFFCareTaker_C03A::Init2(): the hero ("ObjectHero") into +0x48.
static void THISCALL c03aInit2(u8 *ct) {
  u8 *reg = vcall<u8 *>(mgr(), 0x138);
  u32 h = 0;
  vcall<u32, const char *, u32 *>(reg, 0x88, (const char *)0x6ac89c, &h);
  U32(0x48) = vcall<u32, u32>(mgr(), 0x58, h);
}
PCREG(5bc050, c03aInit2);

// 0x5bc0a0 ZFFCareTaker_C03A::Load(ZLoadGame*): hero reference, +0x4c, +0x4d (float, slot 0x50), +0x51 +0x55 +0x5d
// +0x59, then registers itself again. Returns true.
static u8 THISCALL c03aLoad(u8 *ct, u8 *lg) {
  u32 ref = (u32)lg;   // the original reads into its argument slot
  *(u32 *)(ct + 4) &= ~0x40u;
  vcall<void, u32 *>(lg, 0x40, &ref);
  U32(0x48) = vcall<u32, u32>(mgr(), 0x58, ref);
  vcall<void, u8 *>(lg, 0x68, ct + 0x4c);
  vcall<void, u8 *>(lg, 0x50, ct + 0x4d);
  vcall<void, u8 *>(lg, 0x40, ct + 0x51);
  vcall<void, u8 *>(lg, 0x40, ct + 0x55);
  vcall<void, u8 *>(lg, 0x40, ct + 0x5d);
  vcall<void, u8 *>(lg, 0x40, ct + 0x59);
  registerSelf(ct);
  return 1;
}
PCREG(5bc0a0, c03aLoad);

// 0x5bc160 ZFFCareTaker_C03A::Save(ZSaveGame*): the mirror of Load (the float by value through slot 0x4c).
static u8 THISCALL c03aSave(u8 *ct, u8 *sg) {
  *(u32 *)(ct + 4) &= ~0x40u;
  vcall<void, u32>(sg, 0x64, U32(0x48));
  vcall<void, u32>(sg, 0x60, (u32)ct[0x4c]);
  vcall<void, u32>(sg, 0x4c, U32(0x4d));   // float bits
  vcall<void, u32>(sg, 0x3c, U32(0x51));
  vcall<void, u32>(sg, 0x3c, U32(0x55));
  vcall<void, u32>(sg, 0x3c, U32(0x5d));
  vcall<void, u32>(sg, 0x3c, U32(0x59));
  return 1;
}
PCREG(5bc160, c03aSave);

// 0x5bc4e0 ZFFCareTaker_C03A deleting destructor (also C03C's): the ZEventBase part inline (+0x44/+0x30 cleared,
// vtable 0x686874, manager slot 0x34), object size 0x61.
static u8 *THISCALL c03aDtor(u8 *ct, u32 flags) {
  U32(0x44) = 0;
  U32(0x30) = 0;
  U32(0) = 0x686874;
  vcall<void, u8 *>(mgr(), 0x34, ct);
  return deletingDtor(ct, flags, 0x61);
}
PCREG(5bc4e0, c03aDtor);
