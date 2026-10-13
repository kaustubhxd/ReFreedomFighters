// batch1423.cpp - missions thread, batch 1423: ZFFCareTaker_C05A (the Tatarin/loudspeaker director): constructor,
// CopyEventDataBlock, Save and Load. FrameUpdate (0x5bce80), Command (0x5bcc10, 156 instructions) and the destructor
// (0x5bf6c0) are not in this batch.
//
// Layout: +0x44 event sender, +0x48, +0x4c, +0x50 handles (event data), +0x54 +0x58 +0x5a registered message ids
// (TatarinDead, CheckInsideEnter, HideInHouse), +0x5c, +0x5d, +0x5e bytes (saved), +0x5f dword (timer), +0x63, +0x67,
// +0x6b, +0x6f dwords (event data).
#include "missions.h"

extern "C" void THISCALL ext_469870(u8 *ev);   // ZEventBase::ZEventBase()
extern "C" u32 THISCALL ext_4e5e60(u32 *db);   // DBREAD::operator unsigned int()
#define CARETAKER_C05A_CPP 0x6b31f0u

static inline u8 *sysi() { return G(u8 *, 0x70039c); }
static inline u8 *mgr() { return *(u8 **)(sysi() + 0x9b); }
static inline u16 msgId(const char *name, u32 line) {
  return vcall<u16, const char *, u32, const char *, u32>(mgr(), 0x114, name, 0, (const char *)CARETAKER_C05A_CPP, line);
}

// 0x5bcab0 ZFFCareTaker_C05A::ZFFCareTaker_C05A(): event base, vtable 0x6b316c, the timer +0x5f cleared, the three
// message ids TatarinDead (+0x54), CheckInsideEnter (+0x58), HideInHouse (+0x5a); bytes +0x5c and +0x5e cleared.
static u8 *THISCALL c05aCtor(u8 *ct) {
  ext_469870(ct);
  *(u32 *)(ct + 4) |= 0x20;
  *(u32 *)(ct + 0x44) = 0;
  *(u32 *)ct = 0x6b316c;
  *(u32 *)(ct + 0x5f) = 0;
  *(u16 *)(ct + 0x54) = msgId((const char *)0x6a55b4, 0x14);   // TatarinDead
  *(u16 *)(ct + 0x58) = msgId((const char *)0x69c814, 0x15);   // CheckInsideEnter
  *(u16 *)(ct + 0x5a) = msgId((const char *)0x6a55a8, 0x16);   // HideInHouse
  ct[0x5c] = 0;
  ct[0x5e] = 0;
  *(u32 *)(ct + 0x5f) = 0;
  return ct;
}
PCREG(5bcab0, c05aCtor);

// 0x5bce20 ZFFCareTaker_C05A::CopyEventDataBlock(DBREAD&): seven dwords, in the order +0x48 +0x4c +0x50 +0x63 +0x67
// +0x6b +0x6f.
static void THISCALL c05aCopyEventDataBlock(u8 *ct, u32 *db) {
  *(u32 *)(ct + 0x48) = ext_4e5e60(db);
  *(u32 *)(ct + 0x4c) = ext_4e5e60(db);
  *(u32 *)(ct + 0x50) = ext_4e5e60(db);
  *(u32 *)(ct + 0x63) = ext_4e5e60(db);
  *(u32 *)(ct + 0x67) = ext_4e5e60(db);
  *(u32 *)(ct + 0x6b) = ext_4e5e60(db);
  *(u32 *)(ct + 0x6f) = ext_4e5e60(db);
}
PCREG(5bce20, c05aCopyEventDataBlock);

// 0x5bd020 ZFFCareTaker_C05A::Save(ZSaveGame*): clears the event flag (+4 bit 0x40), then bytes +0x5c +0x5d +0x5e
// (as u32 writes), then the timer +0x5f by value. Returns true.
static u8 THISCALL c05aSave(u8 *ct, u8 *sg) {
  *(u32 *)(ct + 4) &= ~0x40u;
  vcall<void, u32>(sg, 0x60, (u32)ct[0x5c]);
  vcall<void, u32>(sg, 0x60, (u32)ct[0x5d]);
  vcall<void, u32>(sg, 0x60, (u32)ct[0x5e]);
  vcall<void, u32>(sg, 0x54, *(u32 *)(ct + 0x5f));
  return 1;
}
PCREG(5bd020, c05aSave);

// 0x5bcfd0 ZFFCareTaker_C05A::Load(ZLoadGame*): the mirror of Save (bools through slot 0x68, the timer through 0x58).
// Returns true.
static u8 THISCALL c05aLoad(u8 *ct, u8 *lg) {
  *(u32 *)(ct + 4) &= ~0x40u;
  vcall<void, u8 *>(lg, 0x68, ct + 0x5c);
  vcall<void, u8 *>(lg, 0x68, ct + 0x5d);
  vcall<void, u8 *>(lg, 0x68, ct + 0x5e);
  vcall<void, u8 *>(lg, 0x58, ct + 0x5f);
  return 1;
}
PCREG(5bcfd0, c05aLoad);
