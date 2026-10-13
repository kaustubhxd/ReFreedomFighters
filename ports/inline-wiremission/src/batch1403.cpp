// batch1403.cpp - missions thread, batch 1403: campaign save data. CPlayerStats and CPlayerProfile buffers, and the
// CBuffer helpers they use.
//
// The profile's 0x400-byte save image (version 2): [0x000,0x180) CPlayerStats, [0x180,0x200) CSaveMissions,
// [0x200,0x280) CPlayerInventory (+0xe18), [0x280,0x3ac) the object at +0xe84, dword version at +0x3f8.
// Version 1 gave the stats and the missions 0x100 bytes each.
// CPlayerStats save (version 2): version dword, name (64 bytes, zero padded), startPoint (4), dword +0x60,
// lastSubZone (2), bytes +0x67 +0x68, dwords +0x6a +0x6e, byte of +0x50, bytes +0x64 +0x65 +0x66, dwords +0x54 +0x58
// +0x5c +0x72, byte +0x69, the 15 unique-bit words, then 5 per-sub-zone records of 0x20 bytes at +0xbe (fields
// written in the order +0x1c +0x18 +0x14 +0x10 +4 +0 +8, float +0xc). Version 1 has no records.
#include "missions.h"

// 0x65e090 CBuffer::CBuffer() (the name map says ZFFInventoryBridge::ZFFInventoryBridge(), which has the same code:
// the linker folded them). Clears cap, pos and data; returns this.
extern "C" CBuffer *THISCALL m_65e090(CBuffer *b) {
  b->cap = 0;
  b->pos = 0;
  b->data = 0;
  return b;
}
PCREG(65e090, m_65e090);

// 0x5f0320 CBuffer::Set(data, capacity) (no GameCube name): new storage, position 0, error flag cleared.
extern "C" void THISCALL m_5f0320(CBuffer *b, u8 *data, u32 cap) {
  b->data = data;
  b->cap = cap;
  b->pos = 0;
  b->err = 0;
}
PCREG(5f0320, m_5f0320);

// 0x5f0220 CBuffer::Add(float) (no GameCube name): the float's 4 bytes like Add(unsigned int). Taken as its bits.
extern "C" u8 THISCALL m_5f0220(CBuffer *b, u32 bits) {
  if (b->pos + 4 > b->cap) {
    b->err = 1;
    return 0;
  }
  b->data[b->pos] = (u8)bits;
  b->pos++;
  b->data[b->pos] = (u8)(bits >> 8);
  b->pos++;
  b->data[b->pos] = (u8)(bits >> 16);
  b->pos++;
  b->data[b->pos] = (u8)(bits >> 24);
  b->pos++;
  return 1;
}
PCREG(5f0220, m_5f0220);

#define PLAYERSTATS_CPP 0x6b022cu
#define PLAYERPROFILE_CPP 0x6b0df8u
static inline u32 D(u8 *p, u32 off) { return *(u32 *)(p + off); }
static inline void addc(CBuffer *b, u8 v) { ext_5f0190(b, (s8)v); }

// 0x5ad020 CPlayerStats::PutDataIntoBuffer(CBuffer&) (vtable slot 0).
static u8 THISCALL statsPut(u8 *st, CBuffer *b) {
  *(u32 *)(st + 4) = 2;
  m_5f01c0(b, 2);
  const char *nm = (const char *)(st + 8);
  u32 n = 0;
  while (nm[n]) n++;
  for (u32 i = 0; i < n && i < 0x40; i++)
    addc(b, (u8)nm[i]);
  if (n < 0x40)
    for (u32 k = 0x40 - n; k; k--) addc(b, 0);
  for (u32 i = 0; i < 4; i++) addc(b, st[0x48 + i]);
  m_5f01c0(b, D(st, 0x60));
  addc(b, st[0x4d]);
  addc(b, st[0x4e]);
  addc(b, st[0x67]);
  addc(b, st[0x68]);
  m_5f01c0(b, D(st, 0x6a));
  m_5f01c0(b, D(st, 0x6e));
  addc(b, st[0x50]);
  addc(b, st[0x64]);
  addc(b, st[0x65]);
  addc(b, st[0x66]);
  m_5f01c0(b, D(st, 0x54));
  m_5f01c0(b, D(st, 0x58));
  m_5f01c0(b, D(st, 0x5c));
  m_5f01c0(b, D(st, 0x72));
  addc(b, st[0x69]);
  for (u32 i = 0; i < 15; i++) m_5f01c0(b, D(st, 0x76 + 4 * i));
  for (u32 k = 0; k < 5; k++) {
    u8 *r = st + 0xbe + 0x20 * k;
    m_5f01c0(b, D(r, 0x1c));
    m_5f01c0(b, D(r, 0x18));
    m_5f01c0(b, D(r, 0x14));
    m_5f01c0(b, D(r, 0x10));
    m_5f01c0(b, D(r, 4));
    m_5f01c0(b, D(r, 0));
    m_5f01c0(b, D(r, 8));
    m_5f0220(b, D(r, 0xc));
  }
  return b->err == 0;
}
PCREG(5ad020, statsPut);

// The common part of both versions of CPlayerStats::TakeDataOutOfBuffer. `t60` is the original's temporary for the
// +0x60 dword (version 1: a stack slot that holds `this`; version 2: an uninitialised slot, so the port only
// matches when that read succeeds), `t50` the byte temporary for +0x50 (the top byte of the CBuffer* argument).
static void statsTakeCommon(u8 *st, CBuffer *b, u32 t60, s8 t50) {
  for (u32 i = 0; i < 0x40; i++) m_5f02f0(b, (s8 *)(st + 8 + i));
  for (u32 i = 0; i < 4; i++) m_5f02f0(b, (s8 *)(st + 0x48 + i));
  st[0x4c] = 0;
  m_5f0280(b, (u8 *)&t60);
  *(u32 *)(st + 0x60) = t60;
  m_5f02f0(b, (s8 *)(st + 0x4d));
  m_5f02f0(b, (s8 *)(st + 0x4e));
  st[0x4f] = 0;
  m_5f02f0(b, (s8 *)(st + 0x67));
  m_5f02f0(b, (s8 *)(st + 0x68));
  m_5f0280(b, st + 0x6a);
  m_5f0280(b, st + 0x6e);
  m_5f02f0(b, &t50);
  *(s32 *)(st + 0x50) = t50;
  m_5f02f0(b, (s8 *)(st + 0x64));
  m_5f02f0(b, (s8 *)(st + 0x65));
  m_5f02f0(b, (s8 *)(st + 0x66));
  m_5f0280(b, st + 0x54);
  m_5f0280(b, st + 0x58);
  m_5f0280(b, st + 0x5c);
  m_5f0280(b, st + 0x72);
  m_5f02f0(b, (s8 *)(st + 0x69));
  for (u32 i = 0; i < 15; i++) m_5f0280(b, st + 0x76 + 4 * i);
}

// 0x5ad320 CPlayerStats::TakeDataOutOfBuffer(CBuffer&) (vtable slot 1): version 1 or 2 (see above); other versions
// are logged as unsupported. True when the buffer did not run out.
static u8 THISCALL statsTake(u8 *st, CBuffer *b) {
  m_5f0280(b, st + 4);
  s8 t50 = (s8)((u32)b >> 24);
  u32 v = *(u32 *)(st + 4);
  if (v == 1) {
    statsTakeCommon(st, b, (u32)st, t50);
  } else if (v == 2) {
    u32 t60 = 0xcccccccc;   // uninitialised in the original (see statsTakeCommon)
    statsTakeCommon(st, b, t60, t50);
    for (u32 k = 0; k < 5; k++) {
      u8 *r = st + 0xbe + 0x20 * k;
      m_5f0280(b, r + 0x1c);
      m_5f0280(b, r + 0x18);
      m_5f0280(b, r + 0x14);
      m_5f0280(b, r + 0x10);
      m_5f0280(b, r + 4);
      m_5f0280(b, r + 0);
      m_5f0280(b, r + 8);
      m_5f0280(b, r + 0xc);
    }
  } else {
    LOGF(PLAYERSTATS_CPP, 0x110, (const char *)0x6b0338);
  }
  return b->err == 0;
}
PCREG(5ad320, statsTake);

extern "C" void THISCALL m_5acdb0(u8 *st);   // CPlayerStats::GetGlobalControlVals (batch 1402)

// Each part saves through its vtable slot 0 (Put) and loads through slot 1 (Take).
static inline void part(u8 *obj, u32 slot, CBuffer *b) { vcall<u8, CBuffer *>(obj, slot, b); }

// 0x5ae5a0 CPlayerProfile::SaveProfileToBuffer(char *buf, bool readControls) (no GameCube name; the writer twin of
// LoadProfileFromBuffer): clears the 0x400 bytes, optionally refreshes the control settings from the globals, writes
// the four parts at their fixed offsets and stores version 2 at +0x3f8.
static void THISCALL profileSave(u8 *prof, u8 *buf, u32 readControls) {
  for (int i = 0; i < 0x100; i++) ((u32 *)buf)[i] = 0;
  if ((u8)readControls)
    m_5acdb0(prof + 0x35a);
  CBuffer b;
  m_65e090(&b);
  m_5f0320(&b, buf, 0x180);
  part(prof + 0x35a, 0, &b);
  m_5f0320(&b, buf + 0x180, 0x80);
  part(prof + 0x4b8, 0, &b);
  m_5f0320(&b, buf + 0x200, 0x80);
  part(prof + 0xe18, 0, &b);
  m_5f0320(&b, buf + 0x280, 0x12c);
  part(prof + 0xe84, 0, &b);
  *(u32 *)(buf + 0x3f8) = 2;
}
PCREG(5ae5a0, profileSave);

// 0x5ae450 CPlayerProfile::LoadProfileFromBuffer(char*): version at +0x3f8; 0 fails quietly, 1 and 2 load the four
// parts (the layouts differ only in the stats and missions sizes), then sets the global "ProfileInitialized"
// (store slot 0x68(name, 1, 0)); other versions are logged and fail.
static u8 THISCALL profileLoad(u8 *prof, u8 *buf) {
  CBuffer b;
  u32 v = *(u32 *)(buf + 0x3f8);
  m_65e090(&b);
  if (v == 0)
    return 0;
  if (v == 1) {
    m_5f0320(&b, buf, 0x100);
    part(prof + 0x35a, 4, &b);
    m_5f0320(&b, buf + 0x100, 0x100);
  } else if (v == 2) {
    m_5f0320(&b, buf, 0x180);
    part(prof + 0x35a, 4, &b);
    m_5f0320(&b, buf + 0x180, 0x80);
  } else {
    LOGF(PLAYERPROFILE_CPP, 0x1d0, (const char *)0x6b0e30);
    return 0;
  }
  part(prof + 0x4b8, 4, &b);
  m_5f0320(&b, buf + 0x200, 0x80);
  part(prof + 0xe18, 4, &b);
  m_5f0320(&b, buf + 0x280, 0x12c);
  part(prof + 0xe84, 4, &b);
  u8 *g = vcall<u8 *>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x134);
  vcall<void, const char *, u32, u32>(g, 0x68, (const char *)0x6a75b0, 1, 0);   // "ProfileInitialized"
  return 1;
}
PCREG(5ae450, profileLoad);
