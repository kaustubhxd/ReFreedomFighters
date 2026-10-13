// batch1407.cpp - missions thread, batch 1407: ZFFLevelController::SceneChange, which builds the next scene's loader
// path from the next-scene name at +0x51 and asks the scene manager to switch.
#include "missions.h"

extern "C" void THISCALL ext_5b02f0(u8 *inv);    // CPlayerInventory: clear mission items (inventory thread's area)
extern "C" u8 THISCALL ext_5ae680(u8 *prof);     // CPlayerProfile::Save()
typedef void *(*crtMemset)(void *, int, u32);
static inline u8 *sysi() { return G(u8 *, 0x70039c); }
static inline u8 *mgr() { return *(u8 **)(sysi() + 0x9b); }

static char *strend(char *s) {
  while (*s) s++;
  return s;
}
static void cat(char *buf, const char *s) {   // strcat, terminator included
  char *d = strend(buf);
  do {
    *d++ = *s;
  } while (*s++);
}

// A cheat flag that does not survive a scene change: display slot 0x60(name, 0) tests it, slot 0x64(name, 0) clears.
static void clearCheat(const char *name, u32 var) {
  u8 *d = vcall<u8 *>(sysi(), 0xbc);
  if (vcall<u8, const char *, u32>(d, 0x60, name, 0)) {
    G(u32, var) = 0;
    d = vcall<u8 *>(sysi(), 0xbc);
    vcall<void, const char *, u32>(d, 0x64, name, 0);
  }
}

// 0x59c620 ZFFLevelController::SceneChange().
//  - Clears the CompletedInvisible ([0x700324]) and CompletedGodMode ([0x6ffa60]) cheats.
//  - Leaving C08R (the last rebel base) without +0x1040: clears the inventory's mission items and saves the profile.
//  - Path: MENU -> "StartLoader"; KH04 -> "MultiPlayer\Demo_01\Loader"; other K.. -> "Multiplayer\Koth_<+0x53>\Loader";
//    M.. or R.. (cutscenes) -> "Cutscenes\MovieCuts\FF_<name>\Loader"; anything else ->
//    "Singleplayer\<name>[B]\Loader", B when +0x54 is 'R' (rebel bases live in C0nRB).
//  - sys slot 0xc(0,0,0,0), manager slot 0xa4, slot 0xa0(path), slot 0xb4(0).
static void THISCALL sceneChange(u8 *lc) {
  clearCheat((const char *)0x6a77e8, 0x700324);   // CompletedInvisible
  clearCheat((const char *)0x6a77d4, 0x6ffa60);   // CompletedGodMode
  if (same(lc + 0x48, (const u8 *)0x6a6e5c) && !lc[0x1040]) {   // C08R
    ext_5b02f0(lc + 0xe6f);
    ext_5ae680(lc + 0x57);
  }
  char buf[0x100];
  (*(crtMemset *)0x676260)(buf, 0, 0x100);
  const char *next = (const char *)(lc + 0x51);
  if (same((const u8 *)next, (const u8 *)0x6a7744)) {   // MENU
    cat(buf, (const char *)0x68d900);                  // StartLoader
  } else if (next[0] == 'K') {
    if (same((const u8 *)next, (const u8 *)0x6a8154)) {   // KH04
      cat(buf, (const char *)0x6adde8);                  // MultiPlayer\Demo_01\Loader
      goto push;
    }
    cat(buf, (const char *)0x6addcc);   // Multiplayer\Koth_
    cat(buf, (const char *)(lc + 0x53));
    cat(buf, (const char *)0x6adde0);   // \Loader
  } else if (next[0] == 'M' || next[0] == 'R') {
    cat(buf, (const char *)0x6ade04);   // Cutscenes\MovieCuts\FF_
    cat(buf, next);
    cat(buf, (const char *)0x6adde0);
  } else {
    cat(buf, (const char *)0x6ade1c);   // Singleplayer\ (trailing backslash)
    cat(buf, next);
    if (lc[0x54] == 'R')
      cat(buf, (const char *)0x67b184);   // B
    cat(buf, (const char *)0x6adde0);
  }
push:
  vcall<void, u32, u32, u32, u32>(sysi(), 0xc, 0, 0, 0, 0);
  vcall<void>(mgr(), 0xa4);
  vcall<void, char *>(mgr(), 0xa0, buf);
  vcall<void, u32>(mgr(), 0xb4, 0);
}
PCREG(59c620, sceneChange);
