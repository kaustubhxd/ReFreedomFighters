// batch1425.cpp - missions thread, batch 1425: ZFFCareTaker_C05A::Command, the Tatarin kill (TatarinDead).
//
// Fields: +0x44 event sender, +0x48 and +0x4c object handles (a and b below), +0x54 TatarinDead id, +0x58
// CheckInsideEnter id, +0x5c "in the house" byte, +0x5e pending loudspeaker byte, +0x5f timer, +0x63 handle
// (CheckInsideEnter target), +0x6b handle (the Tatarin object for the charisma award).
#include "missions.h"

extern "C" void THISCALL ext_596940(u8 *osd, u32 kind, float *pos, u32 flag, s32 n);   // ZGameOSD::CharismaAddExperience
extern "C" u8 *THISCALL ext_589c20(u8 *gd, s8 player);                                 // ZFFGameData::GetGameOSD
extern "C" void THISCALL ext_59a580(u8 *osd, const char *text, u32 n, u32 type);     // ZGameOSD::MessageAdd
#define CARETAKER_C05A_CPP 0x6b31f0u

static inline u8 *sysi() { return G(u8 *, 0x70039c); }
static inline u8 *mgr() { return *(u8 **)(sysi() + 0x9b); }
static inline u8 *byHandle(u32 h) { return vcall<u8 *, u32>(mgr(), 0x58, h); }
static inline u32 lookup(const char *name) {
  u8 *reg = vcall<u8 *>(mgr(), 0x138);
  u32 h = 0;
  vcall<u32, const char *, u32 *>(reg, 0x88, name, &h);
  return h;
}
#define U32(o) (*(u32 *)(ct + (o)))

// 0x5bcc10 ZFFCareTaker_C05A::Command(unsigned short msg, void *data). Only TatarinDead (+0x54) while +0x5c is clear
// does anything (every path returns 0):
//  1. +0x5e = 1 (loudspeaker pending); +0x5f = now + 0x5000.
//  2. The hero ("HitmanGround" handle, kept) and the level controller ("LevelController" handle) are looked up.
//  3. TatarinDead (+0x54) is sent to the controller (three-word send).
//  4. a = object of +0x48, b = object of +0x4c. a's +0x18 object gets slot 0xc (no arguments). Then b's +0x18 list
//     is walked with slots 0x4c (start) and 0x5c (next); each item goes to slot 4 of a's +0x18 object.
//  5. +0x5c = 1; CheckInsideEnter (+0x58) to the handle at +0x63.
//  6. The Tatarin (object of +0x6b) gets its position from slot 0x84, raised by 100 on y, and the hero's OSD gets
//     CharismaAddExperience(6, that position, true, -1).
//  7. The OSD message text of "C05RB/TargetsCompleted/C05A_Tatarin" (the resource collection's slot 0 with an empty
//     default) is added with ZGameOSD::MessageAdd(text, -1, 0), on the OSD from GetGameOSD(0).
static u32 THISCALL c05aCommand(u8 *ct, u32 msg, void *data) {
  (void)data;
  if ((u16)msg != *(u16 *)(ct + 0x54) || ct[0x5c])
    return 0;
  ct[0x5e] = 1;
  U32(0x5f) = *(u32 *)(sysi() + 0x40) + 0x5000;
  u32 hHero = lookup((const char *)0x681320);   // HitmanGround
  u8 *hero = byHandle(hHero);
  u32 hCtl = lookup((const char *)0x6a5c48);    // LevelController
  vcall<void, u32, u32, u32>(*(u8 **)(ct + 0x44), 0x12c, hCtl, (u32)*(u16 *)(ct + 0x54), 0);   // TatarinDead
  u8 *a = byHandle(U32(0x48));
  u8 *b = byHandle(U32(0x4c));
  vcall<void>(*(u8 **)(a + 0x18), 0xc);   // a's +0x18 FIELD (data), slot 0xc of that object
  u8 *la = *(u8 **)(b + 0x18);
  if (la) {
    u32 it = 0;
    vcall<void, u32 *>(la, 0x4c, &it);
    u32 item = vcall<u32, u32 *>(la, 0x5c, &it);
    while (it) {
      vcall<void, u32>(*(u8 **)(a + 0x18), 4, item);
      item = vcall<u32, u32 *>(la, 0x5c, &it);
    }
  }
  ct[0x5c] = 1;
  vcall<void, u32, u32, u32>(*(u8 **)(ct + 0x44), 0x12c, U32(0x63), (u32)*(u16 *)(ct + 0x58), 0);   // CheckInsideEnter
  u8 *tat = byHandle(U32(0x6b));
  float pos[3];   // written in full by slot 0x84
  vcall<void, float *>(tat, 0x84, pos);
  volatile u32 hundredBits = 0x42c80000u;   // 100.0f, kept in an integer so the pilot linker sees no constant-pool data
  pos[1] = pos[1] + bitsf(hundredBits);
  ext_596940(*(u8 **)(hero + 0x852), 6, pos, 1, -1);
  u8 *rc = *(u8 **)(mgr() + 0xae4);
  const char *text = vcall<const char *, const char *, const char *>(rc, 0, (const char *)0x6b3228, (const char *)0x677b5a);
  u8 *osd = ext_589c20(G(u8 *, 0x7003b8), 0);
  ext_59a580(osd, text, 0xffffffffu, 0);   // ZGameOSD::MessageAdd(text, -1, 0)
  return 0;
}
PCREG(5bcc10, c05aCommand);
