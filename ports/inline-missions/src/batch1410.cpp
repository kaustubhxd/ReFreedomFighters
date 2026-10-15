// batch1410.cpp - missions thread, batch 1410: ZFFLevelController's per-frame update, start-up menu and demo toggle.
#include "missions.h"

extern "C" u8 *THISCALL m_589c20(u8 *gd, s8 player);   // ZFFGameData::GetGameOSD (batch 1406)
extern "C" u32 THISCALL m_59b6d0(u8 *lc);              // ZFFLevelController::GetSubZone (batch 1401)
extern "C" void THISCALL ext_5ae020(u8 *prof);         // CPlayerProfile::GiveHeroFFInventory
extern "C" void THISCALL ext_59ce00(u8 *lc);           // ZFFLevelController::StartupRebelBase (batch 1406)
extern "C" void THISCALL ext_597fc0(u8 *osd, u32 hint, u32 flag);   // ZGameOSD::HintMessage(EHINTMSG, bool)
extern "C" void THISCALL ext_59b120(u8 *lc, u32 id);   // ZFFLevelController::DumpAI (batch 1404)
extern "C" void THISCALL ext_58a680(u8 *item, float f);   // game-data list item update (debug path drawing)
extern "C" u32 THISCALL ext_490fa0(u8 *edb);           // ZEngineDataBase::GetStartupParam
struct CGameStats {
  u32 w[8];
};
extern "C" void THISCALL ext_5ab020(u8 *osd, CGameStats s);   // ZOnScreenDisplay::SetStats(CGameStats) by value

// CRT float -> integer (0x633910, float in XMM0, result EDX:EAX), as in inline-soundtimers/src/st.h.
extern "C" void ext_633910();
static inline u32 crt_ftoll_lo(float f) {
  u32 lo;
  asm volatile("call ext_633910"
               : "=a"(lo), "+Yz"(f)
               :
               : "ecx", "edx", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7", "memory", "cc");
  return lo;
}

#define LEVELCONTROLLER_CPP 0x6adc28u
static inline u8 *sysi() { return G(u8 *, 0x70039c); }
static inline u8 *mgr() { return *(u8 **)(sysi() + 0x9b); }
static u32 lookup(const char *name) {
  u8 *reg = vcall<u8 *>(mgr(), 0x138);
  u32 h = 0;
  vcall<u32, const char *, u32 *>(reg, 0x88, name, &h);
  return h;
}
static inline u8 *globals() { return vcall<u8 *>(mgr(), 0x134); }
static inline u16 msgId(const char *name, u32 line) {
  return vcall<u16, const char *, u32, const char *, u32>(mgr(), 0x114, name, 0, (const char *)LEVELCONTROLLER_CPP, line);
}
// Opens a menu window: through the event sender at +0x44 (slot 0x12c(target, msg, &data)), SetWindowStatus then
// Msg_OpenWindow, both with data 5.
static void openWindow(u8 *lc, u32 target, u32 line) {
  u32 data = 5;
  u8 *snd = *(u8 **)(lc + 0x44);
  u16 id = msgId((const char *)0x6a64e0, line);   // SetWindowStatus
  vcall<void, u32, u32, u32 *>(*(u8 **)(lc + 0x44), 0x12c, target, (u32)id, &data);
  (void)snd;
  id = msgId((const char *)0x6a6698, line + 1);    // Msg_OpenWindow
  vcall<void, u32, u32, u32 *>(*(u8 **)(lc + 0x44), 0x12c, target, (u32)id, &data);
}

// 0x59cc60 ZFFLevelController::StartupMenu(): registers the "DemoToggle"/"ToggleDemo" input with the input
// manager ([sys+0x1907]; handles at +0x132c7 and +0x132bb), decides demo mode (+0x1041 already set, or the global
// DemoMode) and opens DemoStart in demo mode, CreditsMenu when the start-up parameter is 6, otherwise rGameMenu.
extern "C" void THISCALL m_59cc60(u8 *lc) {
  u8 *in = *(u8 **)(sysi() + 0x1907);
  if (in)
    vcall<void, u32, const char *, u32>(in, 0xc, 0x6ed098, (const char *)0x6addb4, 0);
  in = *(u8 **)(sysi() + 0x1907);
  u8 *grp = vcall<u8 *, const char *>(in, 0x60, (const char *)0x6addb4);   // DemoToggle
  *(u8 **)(lc + 0x132c7) = grp;
  *(u32 *)(lc + 0x132bb) = vcall<u32, const char *>(grp, 0x14, (const char *)0x6ada20);   // ToggleDemo
  u8 demo;
  if (lc[0x1041]) {
    demo = 1;
  } else {
    u8 *g = globals();
    u8 v = 0;
    vcall<u32, const char *, u8 *>(g, 0x90, (const char *)0x6adda8, &v);   // DemoMode
    demo = v != 0;
  }
  lc[0x1041] = demo;
  u32 h;
  if (demo)
    h = lookup((const char *)0x6add9c);   // DemoStart
  else if (ext_490fa0(mgr()) == 6)
    h = lookup((const char *)0x6addc0);   // CreditsMenu
  else
    h = lookup((const char *)0x6a6c28);   // rGameMenu
  openWindow(lc, h, 0x51c);
}
PCREG(59cc60, m_59cc60);

// 0x59ce70 ZFFLevelController::ToggleDemoMode(): only on the menu (+0x103c) and unless +0x1044 is 3. Closes every
// window of "StartupZWindows" (count from its +0xcb part, slot 0x14; slot 0x300 once per window), flips demo mode;
// entering it opens DemoStart, leaving it clears DEMO2A/7A/9A and opens rGameMenu; the global DemoMode follows.
extern "C" void THISCALL m_59ce70(u8 *lc) {
  if (!lc[0x103c] || *(u32 *)(lc + 0x1044) == 3)
    return;
  u32 hw = lookup((const char *)0x6add8c);   // StartupZWindows
  u8 *w = vcall<u8 *, u32>(mgr(), 0x58, hw);
  if (!w)
    return;
  for (u32 n = vcall<u32>(w + 0xcb, 0x14); n; n--)
    vcall<void>(w, 0x300);
  u8 demo = lc[0x1041] == 0;
  lc[0x1041] = demo;
  u32 h;
  if (demo) {
    h = lookup((const char *)0x6add9c);
  } else {
    h = lookup((const char *)0x6a6c28);
    vcall<void, const char *, u32, u32>(globals(), 0x68, (const char *)0x6a757c, 0, 0);   // DEMO2A
    vcall<void, const char *, u32, u32>(globals(), 0x68, (const char *)0x6a776c, 0, 0);   // DEMO7A
    vcall<void, const char *, u32, u32>(globals(), 0x68, (const char *)0x6aa5ec, 0, 0);   // DEMO9A
  }
  vcall<void, const char *, u32, u32>(globals(), 0x68, (const char *)0x6adda8, (u32)lc[0x1041], 0);
  openWindow(lc, h, 0x462);
}
PCREG(59ce70, m_59ce70);

// 0x59cbc0 (no GameCube name; debug): with the float at +0x105c >= 0, every 0xf4-byte entry of the game data's list
// at +0xd91 (count +0xd8d) is updated with it (0x58a680, which draws AI paths); a value of exactly 0 is then reset
// to -1 (one-shot).
extern "C" void THISCALL m_59cbc0(u8 *lc) {
  if (!comiss_ge(*(float *)(lc + 0x105c), 0.0f))
    return;
  u8 *gd = G(u8 *, 0x7003b8);
  for (u8 *e = gd + 0xd91; e != gd + 0xd91 + *(u32 *)(gd + 0xd8d) * 0xf4; e += 0xf4)
    ext_58a680(e, *(float *)(lc + 0x105c));
  if (*(float *)(lc + 0x105c) == 0.0f)
    *(u32 *)(lc + 0x105c) = 0xbf800000u;
}
PCREG(59cbc0, m_59cbc0);

// 0x59b1c0 ZFFLevelController::FrameUpdate().
//  First frame (+0x103b): the menu starts its windows; a single-player level gives the hero the profile's
//  inventory and shows the sub-zone's stats on the OSD (CGameStats = CPlayerStats record, controller +0x46f + 32 *
//  sub-zone); rebel bases start up; C02R shows hint 0x25. Then the menu polls the ToggleDemo input, the debug path
//  display runs, the manager's slot 0xb8 runs, and a pending DumpAI request (+0x1060 >= 0) is served once.
static void THISCALL lcFrameUpdate(u8 *lc) {
  if (lc[0x103b]) {
    if (lc[0x103c]) {
      m_59cc60(lc);
    } else if (!lc[0x103f]) {
      ext_5ae020(lc + 0x57);
      if (!lc[0x103e]) {
        u8 *osd = m_589c20(G(u8 *, 0x7003b8), 0);
        u32 sz = m_59b6d0(lc);
        CGameStats s = *(CGameStats *)(lc + 0x46f + sz * 32);
        ext_5ab020(*(u8 **)(osd + 0x1d0f), s);
      }
    }
    if (lc[0x103e])
      ext_59ce00(lc);
    if (lc[0x4a] == '2' && lc[0x4b] == 'R') {
      u8 *osd = m_589c20(G(u8 *, 0x7003b8), 0);
      if (osd)
        ext_597fc0(osd, 0x25, 0);
    }
    lc[0x103b] = 0;
  }
  if (lc[0x103c] && *(u32 *)(lc + 0x132c7)) {
    u8 *in = *(u8 **)(sysi() + 0x1907);
    if (vcall<u8, u32, u32>(in, 0x2c, *(u32 *)(lc + 0x132bb), 0))
      m_59ce70(lc);
  }
  m_59cbc0(lc);
  vcall<void>(mgr(), 0xb8);
  float f = *(float *)(lc + 0x1060);
  if (comiss_ge(f, 0.0f)) {
    ext_59b120(lc, crt_ftoll_lo(f));
    *(u32 *)(lc + 0x1060) = 0xbf800000u;
  }
}
PCREG(59b1c0, lcFrameUpdate);
