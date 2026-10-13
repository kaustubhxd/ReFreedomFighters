// batch1415.cpp - missions thread, batch 1415: ZFFCareTaker_C02A (second level, the squad tutorial) construction,
// Init, Load2 and CopyEventDataBlock.
//
// C02A layout so far: +0x48..+0x62 cached message ids, +0x64 the hero ("ObjectHero"), +0x68..+0x80 seven handles
// from the event data, REFTAB32 lists at +0x84, +0x130, +0x1e8 and +0x2c6, handles +0x1dc +0x1e0 +0x1e4,
// +0x294 u16, +0x296 u32, +0x29a u32 (2), +0x29e u32, +0x2a2/+0x2a7 bytes, +0x2a8 u32, +0x2b4 u32, +0x2b8 count
// and +0x2bc bytes of a small flag array, +0x372/+0x376/+0x37b u32, +0x37a/+0x37f bytes.
#include "missions.h"

extern "C" void THISCALL ext_469870(u8 *ev);      // ZEventBase::ZEventBase()
extern "C" void THISCALL ext_4ccba0(u8 *tab);     // REFTAB32::REFTAB32()
extern "C" u32 THISCALL ext_4e5e60(u32 *db);      // DBREAD::operator unsigned int()
extern "C" void THISCALL ext_4e6330(u32 *db, u8 *tab);   // DBREAD::GetRefTab(REFTAB*)
#define CARETAKER_C02A_CPP 0x6b2ab4u

static inline u8 *sysi() { return G(u8 *, 0x70039c); }
static inline u8 *mgr() { return *(u8 **)(sysi() + 0x9b); }
static inline u16 msgId(const char *name, u32 line) {
  return vcall<u16, const char *, u32, const char *, u32>(mgr(), 0x114, name, 0, (const char *)CARETAKER_C02A_CPP, line);
}

// 0x5ba890 ZFFCareTaker_C02A::ZFFCareTaker_C02A(): ZEventBase base, vtable 0x6b2a30, four REFTAB32 lists, and the
// message ids EnterFuelStation, EnterBriefingRoom, VoiceOverAttack, VoiceOverFallBack, VoiceOverVantagePoint,
// VoiceOverMap, OpenedMap, HeroHasRecruits, Friendly_Attack, Friendly_Form, Friendly_Check, HideAllHints, HeroHasC4,
// LeftVantagePoint.
static u8 *THISCALL c02aCtor(u8 *ct) {
  ext_469870(ct);
  *(u32 *)(ct + 4) |= 0x20;
  *(u32 *)(ct + 0x44) = 0;
  *(u32 *)ct = 0x6b2a30;
  ext_4ccba0(ct + 0x84);
  ext_4ccba0(ct + 0x130);
  ext_4ccba0(ct + 0x1e8);
  *(u32 *)(ct + 0x29e) = 0;
  *(u32 *)(ct + 0x2a8) = 0;
  *(u32 *)(ct + 0x2b8) = 0;
  ext_4ccba0(ct + 0x2c6);
  *(u32 *)(ct + 0x376) = 0;
  *(u32 *)(ct + 0x37b) = 0;
  *(u16 *)(ct + 0x48) = msgId((const char *)0x6b2aec, 0x15);   // EnterFuelStation
  *(u16 *)(ct + 0x4a) = msgId((const char *)0x6b2b00, 0x16);   // EnterBriefingRoom
  *(u16 *)(ct + 0x294) = 0;
  *(u16 *)(ct + 0x4c) = msgId((const char *)0x6b2b14, 0x1a);   // VoiceOverAttack
  *(u16 *)(ct + 0x4e) = msgId((const char *)0x6b2b24, 0x1b);   // VoiceOverFallBack
  *(u16 *)(ct + 0x50) = msgId((const char *)0x6b2b38, 0x1c);   // VoiceOverVantagePoint
  *(u16 *)(ct + 0x52) = msgId((const char *)0x6b2b50, 0x1d);   // VoiceOverMap
  *(u16 *)(ct + 0x5e) = msgId((const char *)0x6b2b60, 0x1e);   // OpenedMap
  *(u16 *)(ct + 0x54) = msgId((const char *)0x6a56f4, 0x1f);   // HeroHasRecruits
  *(u16 *)(ct + 0x56) = msgId((const char *)0x6ad7e4, 0x20);   // Friendly_Attack
  *(u16 *)(ct + 0x58) = msgId((const char *)0x6ad7f4, 0x21);   // Friendly_Form
  *(u16 *)(ct + 0x5a) = msgId((const char *)0x6ad7d4, 0x22);   // Friendly_Check
  *(u16 *)(ct + 0x5c) = msgId((const char *)0x6b2b6c, 0x23);   // HideAllHints
  *(u16 *)(ct + 0x60) = msgId((const char *)0x6a5704, 0x24);   // HeroHasC4
  *(u16 *)(ct + 0x62) = msgId((const char *)0x6b2b7c, 0x25);   // LeftVantagePoint
  *(u32 *)(ct + 0x296) = 0;
  ct[0x2a2] = 0;
  ct[0x2a7] = 0;
  *(u32 *)(ct + 0x2b4) = 0;
  *(u32 *)(ct + 0x372) = 0;
  *(u32 *)(ct + 0x29a) = 2;
  ct[0x37a] = 0;
  ct[0x37f] = 0;
  return ct;
}
PCREG(5ba890, c02aCtor);

// 0x5bb7a0 ZFFCareTaker_C02A::Init(): appends ten 0 bytes to the flag array (+0x2bc, count +0x2b8; no bound check).
static void THISCALL c02aInit(u8 *ct) {
  for (int i = 0; i < 10; i++) {
    ct[0x2bc + *(u32 *)(ct + 0x2b8)] = 0;
    (*(u32 *)(ct + 0x2b8))++;
  }
}
PCREG(5bb7a0, c02aInit);

// 0x5bb870 ZFFCareTaker_C02A::Load2(): the hero ("ObjectHero") into +0x64.
static void THISCALL c02aLoad2(u8 *ct) {
  u8 *reg = vcall<u8 *>(mgr(), 0x138);
  u32 h = 0;
  vcall<u32, const char *, u32 *>(reg, 0x88, (const char *)0x6ac89c, &h);
  *(u32 *)(ct + 0x64) = vcall<u32, u32>(mgr(), 0x58, h);
}
PCREG(5bb870, c02aLoad2);

// 0x5bb0a0 ZFFCareTaker_C02A::CopyEventDataBlock(DBREAD&): handles +0x68..+0x80, lists +0x84 and +0x130, handle
// +0x1dc, list +0x2c6, handles +0x1e0 and +0x1e4, list +0x1e8 (raw handles; resolved later in Init2).
static void THISCALL c02aCopyEventDataBlock(u8 *ct, u32 *db) {
  for (int i = 0; i < 7; i++) *(u32 *)(ct + 0x68 + 4 * i) = ext_4e5e60(db);
  ext_4e6330(db, ct + 0x84);
  ext_4e6330(db, ct + 0x130);
  *(u32 *)(ct + 0x1dc) = ext_4e5e60(db);
  ext_4e6330(db, ct + 0x2c6);
  *(u32 *)(ct + 0x1e0) = ext_4e5e60(db);
  *(u32 *)(ct + 0x1e4) = ext_4e5e60(db);
  ext_4e6330(db, ct + 0x1e8);
}
PCREG(5bb0a0, c02aCopyEventDataBlock);
