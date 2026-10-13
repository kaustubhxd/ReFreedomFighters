// batch1405.cpp - missions thread, batch 1405: ZFFLevelController::MakeSceneName, which turns the loaded scene's
// path into the 4-character level name at +0x48 that every mission variable is keyed by.
#include "missions.h"

extern "C" int FASTCALL ext_4cc850(const char *s, const char *pat);   // striwcmp (wildcard, case-insensitive)

typedef bool(THISCALL *iniGet)(void *self, const char *key, const char **out);
typedef s32 (*crtAtoi)(const char *);
static inline u8 *mgr() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline void setGlobalFlag(const char *name) {
  u8 *g = vcall<u8 *>(mgr(), 0x134);
  vcall<void, const char *, u32, u32>(g, 0x68, name, 1, 0);
}
static inline void name4(u8 *lc, u32 addr) {   // a 4-character name constant, terminated
  *(u32 *)(lc + 0x48) = G(u32, addr);
  lc[0x4c] = 0;
}

// 0x59c0d0 ZFFLevelController::MakeSceneName(). Also called from CopyEventDataBlock and Load2.
//  1. sys+0x1b5d = 0. The ini key "Demo" (sys slot 0x5c) sets +0x1041 = atoi != 0 and +0x1044 = atoi.
//  2. The scene path is the string inline at +4 of the last entry of the manager's scene list (+0x1c; slot 0x54
//     starts an iterator, slot 0x74 steps it); with an empty list the Demo ini string is used (uninitialised in the
//     original when the key is missing as well). Matching starts 2 characters in (past the drive, "C:").
//  3. Wildcard matches (striwcmp): *_Test\HeroPlayground* -> C00A; *FF-Startup* -> MENU (+0x103c);
//     *FF-DEMO* sets the global DEMO2A and goes on; *DemoEndScreen* -> MENU (+0x103c, +0x1042).
//  4. Otherwise the first "C0"/"c0" with at least one character after the following one gives C0<digit><letter>,
//     letter upper-cased; letter R marks a rebel base (+0x103e) and C09R becomes C08R (+0x1040). In demo mode C07A
//     sets the global DEMO7A and C09A sets DEMO9A.
//  5. No "C0": the name becomes "NA"; a multiplayer map (*FF_MP*) sets +0x103f, sys+0x1b5d = 1 and the name
//     KH02 / KH03 / KH04 (King of the Hill) from *KOTH_02* / *KOTH_03* / anything else.
extern "C" void THISCALL m_59c0d0(u8 *lc) {
  G(u32, (u32)G(u8 *, 0x70039c) + 0x1b5d) = 0;
  const char *ini = 0;   // the original's local is uninitialised; the ini call is expected to write it
  {
    void *sys = G(void *, 0x70039c);
    if (((iniGet)(*(void ***)sys)[0x5c / 4])(sys, (const char *)0x6a663c, &ini)) {
      crtAtoi atoi_ = *(crtAtoi *)0x6762d8;
      lc[0x1041] = atoi_(ini) != 0;
      *(s32 *)(lc + 0x1044) = atoi_(ini);
    }
  }
  const char *path = ini;
  u8 *list = mgr() + 0x1c;
  if (list) {
    u32 it[3];
    vcall<void, u32 *>(list, 0x54, it);
    u8 *e = vcall<u8 *, u32 *>(mgr() + 0x1c, 0x74, it);
    if (e) {
      do {
        path = (const char *)(e + 4);
        e = vcall<u8 *, u32 *>(mgr() + 0x1c, 0x74, it);
      } while (e);
    }
  }
  const char *n = path + 2;
  if (ext_4cc850(n, (const char *)0x6adcb0) == 0) {   // *_Test\HeroPlayground*
    name4(lc, 0x6adcc8);                              // C00A
    return;
  }
  if (ext_4cc850(n, (const char *)0x6adcd0) == 0) {   // *FF-Startup*
    name4(lc, 0x6a7744);                              // MENU
    lc[0x103c] = 1;
    return;
  }
  if (ext_4cc850(n, (const char *)0x6adce0) == 0)     // *FF-DEMO*
    setGlobalFlag((const char *)0x6a757c);            // DEMO2A
  if (ext_4cc850(n, (const char *)0x6adcec) == 0) {   // *DemoEndScreen*
    name4(lc, 0x6a7744);
    lc[0x103c] = 1;
    lc[0x1042] = 1;
    return;
  }
  s32 len = 0;
  while (n[len]) len++;
  len -= 3;
  for (s32 i = 0; i < len; i++) {
    if ((n[i] == 'C' || n[i] == 'c') && n[i + 1] == '0') {
      lc[0x49] = '0';
      lc[0x48] = 'C';
      lc[0x4a] = n[i + 2];
      u8 ch = (u8)n[i + 3];
      lc[0x4b] = ch;
      lc[0x4c] = 0;
      if ((u8)(ch - 'a') <= 0x19)
        lc[0x4b] = ch - 0x20;
      if (lc[0x4b] == 'R') {
        lc[0x103e] = 1;
        if (lc[0x4a] == '9') {
          lc[0x4a] = '8';
          lc[0x1040] = 1;
        }
      }
      if (same(lc + 0x48, (const u8 *)0x6a7774) && lc[0x1041])   // C07A
        setGlobalFlag((const char *)0x6a776c);                  // DEMO7A
      if (same(lc + 0x48, (const u8 *)0x6a7818) && lc[0x1041])   // C09A
        setGlobalFlag((const char *)0x6aa5ec);                  // DEMO9A
      return;
    }
  }
  lc[0x48] = 'N';
  lc[0x49] = 'A';
  lc[0x4a] = 0;
  if (ext_4cc850(n, (const char *)0x6adcfc) != 0)   // *FF_MP*
    return;
  lc[0x4c] = 0;
  lc[0x103f] = 1;
  G(u32, (u32)G(u8 *, 0x70039c) + 0x1b5d) = 1;
  if (ext_4cc850(n, (const char *)0x6add04) == 0) {   // *KOTH_02*
    *(u32 *)(lc + 0x48) = G(u32, 0x6a814c);
    lc[0x4c] = G(u8, 0x6a8150);
  } else if (ext_4cc850(n, (const char *)0x6add10) == 0) {   // *KOTH_03*
    *(u32 *)(lc + 0x48) = G(u32, 0x6a8144);
    lc[0x4c] = G(u8, 0x6a8148);
  } else {
    *(u32 *)(lc + 0x48) = G(u32, 0x6a8154);   // KH04
    lc[0x4c] = G(u8, 0x6a8158);
  }
}
PCREG(59c0d0, m_59c0d0);

// 0x59b090 ZFFLevelController::CopyEventDataBlock(DBREAD&): just MakeSceneName.
static void THISCALL lcCopyEventDataBlock(u8 *lc, void *db) {
  (void)db;
  m_59c0d0(lc);
}
PCREG(59b090, lcCopyEventDataBlock);
