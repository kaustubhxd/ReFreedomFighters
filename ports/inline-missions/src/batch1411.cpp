// batch1411.cpp - missions thread, batch 1411: ZFFLevelController::Init, run when a level's controller is created.
#include "missions.h"

extern "C" void THISCALL m_5b12d0(CSaveMissions *s);   // CSaveMissions::SetVarsFromMainIni (batch 1400)
extern "C" void THISCALL ext_5ad2e0(u8 *st);           // CPlayerStats::SetVarsFromMainIni (batch 1402)
extern "C" void THISCALL ext_59ca50(u8 *lc, const char *level);   // ZFFLevelController::SetDefaultCharisma (1401)
extern "C" char *THISCALL m_5acfa0(u8 *st);            // CPlayerStats::GetLastSubZone (batch 1402)
extern "C" void THISCALL ext_5ae860(u8 *prof, const char *level);   // CPlayerProfile::SetLevel (batch 1402)
extern "C" u8 THISCALL ext_5ae270(u8 *prof, u32 flag);              // CPlayerProfile::Load(bool)
extern "C" void THISCALL ext_5ae710(u8 *prof, u32 flag);            // CPlayerProfile::SaveRaw(bool)

static inline u8 *sysi() { return G(u8 *, 0x70039c); }
static inline u8 *mgr() { return *(u8 **)(sysi() + 0x9b); }
static inline u8 *globals() { return vcall<u8 *>(mgr(), 0x134); }

// 0x59bd00 ZFFLevelController::Init().
//  - The window coordinator at +0x1064: slot 0, slot 4(profile), and on the menu slot 0x48.
//  - Registers itself under the name "LevelController" (registry slot 0x60(name, manager slot 0x4c(+0x44), 0x10)),
//    so scripts, flak and other objects can find it; [sys+0x190f] slot 0x1b4(1).
//  - Menu or multiplayer: [0x7003a0]+0x79 = 0 and stop.
//  - Otherwise [0x7003a0]+0x79 = 1 and the profile is loaded (CPlayerProfile::Load(false), result in +0x103d).
//    A loaded profile takes ini overrides for mission variables and Recruits, the level's default charisma, sets
//    the globals AutoSaveDisabled and ProfileInMem and is saved raw (false).
//  - +0x4d gets the stats' last-sub-zone pointer, the profile enters this level (SetLevel), and it is saved raw (true).
static void THISCALL lcInit(u8 *lc) {
  u8 *wc = lc + 0x1064;
  vcall<void>(wc, 0);
  vcall<void, u8 *>(wc, 4, lc + 0x57);
  if (lc[0x103c])
    vcall<void>(wc, 0x48);
  u8 *reg = vcall<u8 *>(mgr(), 0x138);
  u32 t = vcall<u32, u32, u32>(mgr(), 0x4c, *(u32 *)(lc + 0x44), 0x10);   // manager slot 0x4c(sender, 0x10) -> handle
  vcall<void, const char *, u32>(reg, 0x60, (const char *)0x6a5c48, t);   // registry slot 0x60(name, handle): LevelController
  vcall<void, u32>(*(u8 **)(sysi() + 0x190f), 0x1b4, 1);
  if (lc[0x103f] || lc[0x103c]) {
    G(u8 *, 0x7003a0)[0x79] = 0;
    return;
  }
  G(u8 *, 0x7003a0)[0x79] = 1;
  u8 ok = ext_5ae270(lc + 0x57, 0);
  lc[0x103d] = ok;
  if (ok) {
    m_5b12d0((CSaveMissions *)(lc + 0x50f));
    ext_5ad2e0(lc + 0x3b1);
    ext_59ca50(lc, (const char *)(lc + 0x48));
    vcall<void, const char *, u32, u32>(globals(), 0x68, (const char *)0x6a66d8, 1, 0);   // AutoSaveDisabled
    vcall<void, const char *, u32, u32>(globals(), 0x5c, (const char *)0x6a777c, 1, 2);   // ProfileInMem
    ext_5ae710(lc + 0x57, 0);
  }
  *(char **)(lc + 0x4d) = m_5acfa0(lc + 0x3b1);
  ext_5ae860(lc + 0x57, (const char *)(lc + 0x48));
  if (!lc[0x103d]) {
    typedef void(THISCALL * emptyFn)(u8 *);
    emptyFn f = (emptyFn)0x4690b0;   // an empty method (folded "ret")
    asm("" : "+r"(f));              // an indirect call: the linker here has no absolute-call relocation
    f(lc + 0x3b1);
  }
  ext_5ae710(lc + 0x57, 1);
}
PCREG(59bd00, lcInit);
