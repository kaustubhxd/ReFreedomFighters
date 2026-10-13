// batch1404.cpp - missions thread, batch 1404: ZFFLevelController save/load and two debug helpers.
//
// More controller fields (from Save/Load): +0x004 flags (bit 0x40 cleared on save and load), +0x0dd dword (saved
// through ZSaveGame slot 0x44), +0x103b u8, +0x103e u8 (blocks the autosave flag in Load2), +0x1050 object (saved as
// a reference), +0x1064 embedded object with a vtable (Load2 calls its slots 0 and 4), +0x463/+0x467/+0x46b the
// unique-id counters (types 0, 1, 2; saved in the order 1, 0, 2).
// ZSaveGame slots: 0x10 write bytes(ptr, n), 0x3c write int, 0x44 write (+0xdd), 0x60 write bool, 0x64 write object.
// ZLoadGame slots: 0x18 read bytes(ptr, n), 0x40 read int(&), 0x48 read (&), 0x68 read bool(&).
#include "missions.h"

extern "C" void THISCALL ext_5ae5a0(u8 *prof, u8 *buf, u32 readControls);   // CPlayerProfile::SaveProfileToBuffer
extern "C" u8 THISCALL ext_5ae450(u8 *prof, u8 *buf);                       // CPlayerProfile::LoadProfileFromBuffer
extern "C" void THISCALL ext_59c0d0(u8 *lc);                                // ZFFLevelController::MakeSceneName
extern "C" void THISCALL ext_5ae860(u8 *prof, const char *level);           // CPlayerProfile::SetLevel
extern "C" void THISCALL ext_5ae240(u8 *prof);   // CPlayerProfile::InitSaveDeviceSerialNumberAfterLoad
extern "C" u32 THISCALL ext_478400(u8 *actor);   // dump an actor's AI (behaviour tree debug print)
extern "C" void THISCALL ext_5ae900(u8 *prof, const char *s);               // CPlayerProfile::SetSaveName
extern "C" char *THISCALL ext_5adea0(u8 *prof);                             // CPlayerProfile::GetSaveName

#define LEVELCONTROLLER_CPP 0x6adc28u   // "..\\..\\freedomfighter\\FFBackground\\LevelController.cpp"
static inline u8 *mgr() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x59c530 ZFFLevelController::Save(ZSaveGame*): level name (5 bytes), +0x103b, the +0x1050 object, the three
// unique-id counters, the profile's 0x400-byte save image (control settings refreshed), its save name (0x80 bytes)
// and +0xdd. Returns true.
static u8 THISCALL lcSave(u8 *lc, u8 *sg) {
  *(u32 *)(lc + 4) &= ~0x40u;
  vcall<void, u8 *, u32>(sg, 0x10, lc + 0x48, 5);
  vcall<void, u32>(sg, 0x60, (u32)lc[0x103b]);
  vcall<void, u32>(sg, 0x64, *(u32 *)(lc + 0x1050));
  vcall<void, u32>(sg, 0x3c, *(u32 *)(lc + 0x467));
  vcall<void, u32>(sg, 0x3c, *(u32 *)(lc + 0x463));
  vcall<void, u32>(sg, 0x3c, *(u32 *)(lc + 0x46b));
  u8 img[0x400];
  ext_5ae5a0(lc + 0x57, img, 1);
  vcall<void, u8 *, u32>(sg, 0x10, img, 0x400);
  vcall<void, char *, u32>(sg, 0x10, ext_5adea0(lc + 0x57), 0x80);
  vcall<void, u32>(sg, 0x44, *(u32 *)(lc + 0xdd));
  return 1;
}
PCREG(59c530, lcSave);

// 0x59bfa0 ZFFLevelController::Load(ZLoadGame*): the mirror of Save; the saved object reference is resolved through
// the manager's slot 0x58.
static u8 THISCALL lcLoad(u8 *lc, u8 *lg) {
  *(u32 *)(lc + 4) &= ~0x40u;
  vcall<void, u8 *, u32>(lg, 0x18, lc + 0x48, 5);
  vcall<void, u8 *>(lg, 0x68, lc + 0x103b);
  u32 ref, c1, c0, c2;
  vcall<void, u32 *>(lg, 0x40, &ref);
  *(u32 *)(lc + 0x1050) = vcall<u32, u32>(mgr(), 0x58, ref);
  vcall<void, u32 *>(lg, 0x40, &c1);
  vcall<void, u32 *>(lg, 0x40, &c0);
  vcall<void, u32 *>(lg, 0x40, &c2);
  *(u32 *)(lc + 0x467) = c1;
  *(u32 *)(lc + 0x463) = c0;
  *(u32 *)(lc + 0x46b) = c2;
  u8 img[0x400];
  vcall<void, u8 *, u32>(lg, 0x18, img, 0x400);
  ext_5ae450(lc + 0x57, img);
  char name[0x80];
  vcall<void, char *, u32>(lg, 0x18, name, 0x80);
  ext_5ae900(lc + 0x57, name);
  u32 dd;
  vcall<void, u32 *>(lg, 0x48, &dd);
  *(u32 *)(lc + 0xdd) = dd;
  return 1;
}
PCREG(59bfa0, lcLoad);

// 0x59bf00 ZFFLevelController::Load2(): after a load. Rebuilds the scene name, re-enters the level in the profile,
// engine object [sys+0x190f] slot 0x1b4(1), the embedded +0x1064 object slots 0 and 4(profile), clears the global
// "SaveGameOnThisLevel" (store slot 0x5c(name, 1, 2)), restores the save-device serial, and for levels whose third
// character is '4'..'6' (C04-C06) with +0x103e clear sets byte +0xab8 of the object at [0x7003b8].
static void THISCALL lcLoad2(u8 *lc) {
  ext_59c0d0(lc);
  u8 *prof = lc + 0x57;
  ext_5ae860(prof, (const char *)(lc + 0x48));
  vcall<void, u32>(*(u8 **)(G(u8 *, 0x70039c) + 0x190f), 0x1b4, 1);
  vcall<void>(lc + 0x1064, 0);
  vcall<void, u8 *>(lc + 0x1064, 4, prof);
  u8 *g = vcall<u8 *>(mgr(), 0x134);
  vcall<void, const char *, u32, u32>(g, 0x5c, (const char *)0x6a66ec, 1, 2);
  ext_5ae240(prof);
  if (!lc[0x103e] && (u8)(lc[0x4a] - 0x34) <= 2)
    G(u8 *, 0x7003b8)[0xab8] = 1;
}
PCREG(59bf00, lcLoad2);

// 0x59b0a0 ZFFLevelController::DisableTestMenu(): finds the object named "TestMenu" (registry slot 0x88, manager
// slot 0x58); if it has a window (slot 0x318(3)), that window's slot 0x31c(0, 4), then the menu's slot 0x28.
static void THISCALL disableTestMenu(u8 *lc) {
  (void)lc;
  u8 *reg = vcall<u8 *>(mgr(), 0x138);
  u32 h = 0;
  vcall<u32, const char *, u32 *>(reg, 0x88, (const char *)0x6ade3c, &h);
  u8 *m = vcall<u8 *, u32>(mgr(), 0x58, h);
  if (!m)
    return;
  u8 *w = vcall<u8 *, u32>(m, 0x318, 3);
  if (!w)
    return;
  vcall<void, u32, u32>(w, 0x31c, 0, 4);
  vcall<void>(m, 0x28);
}
PCREG(59b0a0, disableTestMenu);

// 0x59b120 ZFFLevelController::DumpAI(unsigned int id): the "TrackLinkObjects" list (manager +0xadc, slot 0x25c)
// maps the id to a handle (list +0x18, slot 0x30); an actor (slot 0x1e0(0x2007d0)) gets its AI dumped, anything
// else logs "Cannot dump AI for non-actors".
static u32 THISCALL dumpAI(u8 *lc, u32 id) {
  (void)lc;
  u8 *tl = vcall<u8 *, const char *, u32>(*(u8 **)(mgr() + 0xadc), 0x25c, (const char *)0x685f44, 0);
  u8 *lst = *(u8 **)(tl + 0x18);
  u32 h = vcall<u32, u32>(lst, 0x30, id);
  u8 *a = vcall<u8 *, u32>(mgr(), 0x58, h);
  if (a && vcall<u8, u32>(a, 0x1e0, 0x2007d0))
    return ext_478400(a);
  LOGF(LEVELCONTROLLER_CPP, 0x35a, (const char *)0x6add50);
  return 0;
}
PCREG(59b120, dumpAI);
