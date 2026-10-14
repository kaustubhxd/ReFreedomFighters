// batch1402.cpp - missions thread, batch 1402: CPlayerStats and CPlayerProfile leaves (campaign progress).
//
// CPlayerProfile (offsets from the code): +0x000 char level[] (4 characters kept, "C02A"; +2 is the level digit),
// +0x006 char saveName[0x80], +0x086 u32 (from the save-slot table), +0x08a char serial[0x16],
// +0x35a CPlayerStats, +0x4b8 CSaveMissions, +0xe18 CPlayerInventory.
// CPlayerStats: +0x008 char playerName[64], +0x048 char startPoint[5], +0x04d char lastSubZone[3],
// +0x050 s32 ControlSettingP0, +0x054/58/5c s32 MusicV/SpeechV/SfxV, +0x064..0x068 u8 Rumble0, InvertHorizontal0,
// InvertVertical0, AutoLevel0, WideScreen, +0x06e s32 Recruits, +0x072 u32 prisoners-following bits,
// +0x076 u32 uniqueBits[3][5], +0x0b2 u32 uniqueBitCount[3].
#include "missions.h"

extern "C" s32 THISCALL m_5b0b70(CSaveMissions *s, const char *name);              // batch 1400
extern "C" void THISCALL m_5b1150(CSaveMissions *s, const char *name, s32 v);      // batch 1401
extern "C" u32 THISCALL ext_5b0360(u8 *inv);                                      // CPlayerInventory::GetFFInventory
extern "C" void THISCALL ext_5ae940(u8 *prof, const char *level);                 // CPlayerProfile::SetupClues
extern "C" void THISCALL ext_5ae450(u8 *prof, u8 *buf);                           // CPlayerProfile::LoadProfileFromBuffer

#define PLAYERSTATS_CPP 0x6b022cu   // "..\\..\\freedomfighter\\FFBackground\\PlayerStats.cpp"

// ---------------------------------------------------------------- CPlayerStats
// 0x5acfa0 CPlayerStats::GetLastSubZone(): the 2-character sub-zone string at +0x4d.
extern "C" char *THISCALL m_5acfa0(u8 *st) { return (char *)(st + 0x4d); }
PCREG(5acfa0, m_5acfa0);

// 0x5acfb0 CPlayerStats::GetNoOfPrisonersFollowingHero(): set bits among bits 0..30 of +0x72.
static s32 THISCALL prisonersFollowing(u8 *st) {
  u32 b = *(u32 *)(st + 0x72);
  s32 n = 0;
  for (int i = 0; i < 31; i++)
    if (b & (1u << i)) n++;
  return n;
}
PCREG(5acfb0, prisonersFollowing);

// 0x5ad230 CPlayerStats::SetPlayerName(const char*): copied into the 64-byte name at +8. A name of 63 characters
// or more is logged ("m_pacPlayerName, is too small") and its first 64 bytes copied, with the terminator written at
// +0x48 (one past the buffer, over startPoint[0]).
static void THISCALL setPlayerName(u8 *st, const char *s) {
  s32 n = 0;
  while (s[n]) n++;
  if (n + 1 >= 0x40) {
    LOGF(PLAYERSTATS_CPP, 0x57, (const char *)0x6b02e8);
    s32 i;
    for (i = 0; i < 0x40; i++) st[8 + i] = s[i];
    st[8 + i] = 0;
    return;
  }
  s32 i;
  for (i = 0; i < n; i++) st[8 + i] = s[i];
  st[8 + i] = 0;
}
PCREG(5ad230, setPlayerName);

// 0x5ad2b0 CPlayerStats::SetStartPoint(char*): 4 characters to +0x48, terminated.
static void THISCALL setStartPoint(u8 *st, const char *s) {
  st[0x48] = s[0];
  st[0x49] = s[1];
  st[0x4a] = s[2];
  st[0x4b] = s[3];
  st[0x4c] = 0;
}
PCREG(5ad2b0, setStartPoint);

// 0x5ad210 CPlayerStats::SetLastSubZone(const char*) (no GameCube name; the setter of GetLastSubZone): 2 characters
// to +0x4d, terminated; a null pointer is ignored.
extern "C" void THISCALL m_5ad210(u8 *st, const char *s) {
  if (!s)
    return;
  st[0x4d] = s[0];
  st[0x4e] = s[1];
  st[0x4f] = 0;
}
PCREG(5ad210, m_5ad210);

// 0x5ad710 CPlayerStats::ClearUniqueBits() (no GameCube name): all 15 bit words and the 3 counts to 0.
extern "C" void THISCALL m_5ad710(u8 *st) {
  u32 *bits = (u32 *)(st + 0x76);
  u32 *cnt = (u32 *)(st + 0xb2);
  for (int t = 0; t < 3; t++) {
    cnt[t] = 0;
    for (int k = 0; k < 5; k++) bits[t * 5 + k] = 0;
  }
}
PCREG(5ad710, m_5ad710);

// 0x5ad2e0 CPlayerStats::SetVarsFromMainIni(): "Recruits" from the ini (engine slot 0x5c + atoi) into +0x6e.
typedef bool(THISCALL *iniGet)(void *self, const char *key, const char **out);
typedef s32 (*crtAtoi)(const char *);
static void THISCALL statsFromIni(u8 *st) {
  void *sys = G(void *, 0x70039c);
  const char *v;
  if (((iniGet)(*(void ***)sys)[0x5c / 4])(sys, (const char *)0x6b03e0, &v))
    *(s32 *)(st + 0x6e) = (*(crtAtoi *)0x6762d8)(v);
}
PCREG(5ad2e0, statsFromIni);

// Global (script) variables: manager slot 0x134 gives the variable store; its slot 0x88 reads an int, 0x90 a bool.
static u8 *globals() { return vcall<u8 *>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x134); }
static s32 globalInt(const char *name) {
  u8 *g = globals();
  s32 v = 0;
  vcall<u32, const char *, s32 *>(g, 0x88, name, &v);
  return v;
}
static u8 globalBool(const char *name) {
  u8 *g = globals();
  u8 v = 0;
  vcall<u32, const char *, u8 *>(g, 0x90, name, &v);
  return v;
}

// 0x5acdb0 CPlayerStats::GetGlobalControlVals(): controller setting, rumble, invert, auto-level, wide-screen and the
// three volumes from the global variables. Wide-screen is then overwritten by the display's own flag
// ([0x70039c] slot 0xbc -> slot 0xdc).
extern "C" void THISCALL m_5acdb0(u8 *st) {
  *(s32 *)(st + 0x50) = globalInt((const char *)0x6b0394);   // ControlSettingP0
  st[0x64] = globalBool((const char *)0x6b03a8);             // Rumble0
  st[0x65] = globalBool((const char *)0x6b03b0);             // InvertHorizontal0
  st[0x66] = globalBool((const char *)0x6b03c4);             // InvertVertical0
  st[0x67] = globalBool((const char *)0x6b03d4);             // AutoLevel0
  st[0x68] = globalBool((const char *)0x67d9dc);             // WideScreen
  u8 *d = vcall<u8 *>(G(u8 *, 0x70039c), 0xbc);
  st[0x68] = vcall<u8>(d, 0xdc);
  *(s32 *)(st + 0x54) = globalInt((const char *)0x6a8930);   // MusicV
  *(s32 *)(st + 0x58) = globalInt((const char *)0x6a8938);   // SpeechV
  *(s32 *)(st + 0x5c) = globalInt((const char *)0x6a8940);   // SfxV
}
PCREG(5acdb0, m_5acdb0);

// ---------------------------------------------------------------- CSaveMissions
// 0x5b10f0 CSaveMissions::ClearRecent() (no GameCube name): the 8 recent-change slots to -1.
extern "C" void THISCALL m_5b10f0(CSaveMissions *s) {
  for (int i = 0; i < 8; i++) s->unk598[i] = -1;
}
PCREG(5b10f0, m_5b10f0);

// ---------------------------------------------------------------- CPlayerProfile
static inline CSaveMissions *missions(u8 *prof) { return (CSaveMissions *)(prof + 0x4b8); }

// 0x5adda0 CPlayerProfile::FirstTimeInZone(): mission variable "FirstTimeInZone" != 0.
static u8 THISCALL firstTimeInZone(u8 *prof) { return m_5b0b70(missions(prof), (const char *)0x6b08c0) != 0; }
PCREG(5adda0, firstTimeInZone);

// 0x5addc0 CPlayerProfile::GetAddCharactersId(sCharactersToAdd&): clears the 4 dwords; in zone 2 (level digit '2'),
// C02B_Flag set gives [0] = 1 and C02A_Flag set gives [1] = 2.
static void THISCALL addCharactersId(u8 *prof, s32 *out) {
  out[0] = 0;
  out[1] = 0;
  out[2] = 0;
  out[3] = 0;
  if (prof[2] != '2')
    return;
  if (m_5b0b70(missions(prof), (const char *)0x6b045c))   // C02B_Flag
    out[0] = 1;
  if (m_5b0b70(missions(prof), (const char *)0x6b03f8))   // C02A_Flag
    out[1] = 2;
}
PCREG(5addc0, addCharactersId);

// 0x5ade30 CPlayerProfile::GetDeBriefingLocalizetPath(): "C0<n>RB/DeBriefing" for level digits 3..8, otherwise C02RB.
static u32 THISCALL debriefPath(u8 *prof) {
  switch (prof[2]) {
    case '3': return 0x6b0eb8;
    case '4': return 0x6b0ecc;
    case '5': return 0x6b0ee0;
    case '6': return 0x6b0ef4;
    case '7': return 0x6b0f08;
    case '8': return 0x6b0f1c;
    default: return 0x6b0ea4;
  }
}
PCREG(5ade30, debriefPath);

// 0x5ade90 CPlayerProfile::GetFFInventoryFromHero(): the inventory at +0xe18.
static u32 THISCALL ffInventory(u8 *prof) { return ext_5b0360(prof + 0xe18); }
PCREG(5ade90, ffInventory);

// 0x5adea0 CPlayerProfile::GetSaveName() (no GameCube name): the string at +6.
static char *THISCALL saveName(u8 *prof) { return (char *)(prof + 6); }
PCREG(5adea0, saveName);

// 0x5ae900 CPlayerProfile::SetSaveName(const char*) (no GameCube name): strcpy to +6.
static void THISCALL setSaveName(u8 *prof, const char *s) {
  char *d = (char *)(prof + 6);
  char ch;
  do {
    ch = *s++;
    *d++ = ch;
  } while (ch);
}
PCREG(5ae900, setSaveName);

// 0x5ae240 CPlayerProfile::InitSaveDeviceSerialNumberAfterLoad(): global variable store slot 0x6c(+0x8a,
// "SaveDeviceSerialNumber", 0x16).
static void THISCALL initSerial(u8 *prof) {
  u8 *g = globals();
  vcall<void, u8 *, const char *, u32>(g, 0x6c, prof + 0x8a, (const char *)0x6b09d8, 0x16);
}
PCREG(5ae240, initSerial);

// 0x5ae860 CPlayerProfile::SetLevel(const char*) (no GameCube name; ZFFLevelController::Load2 calls it with the level
// name): copies the name and keeps 4 characters. Entering a new zone (level digit differs from the stats' last
// sub-zone) sets FirstTimeInZone = 1 and clears the unique bits and the recent-mission slots; otherwise
// FirstTimeInZone = 0. A rebel-base level ("C02R...") sets up the clues; any other stores name+2 as last sub-zone.
static void THISCALL setLevel(u8 *prof, const char *name) {
  {
    const char *s = name;
    char *d = (char *)prof;
    char ch;
    do {
      ch = *s++;
      *d++ = ch;
    } while (ch);
  }
  prof[4] = 0;
  u8 *st = prof + 0x35a;
  if ((char)prof[2] != *m_5acfa0(st)) {
    m_5b1150(missions(prof), (const char *)0x6b08c0, 1);
    m_5ad710(st);
    m_5b10f0(missions(prof));
  } else {
    m_5b1150(missions(prof), (const char *)0x6b08c0, 0);
  }
  if (name[3] == 'R') {
    ext_5ae940(prof, name);
    return;
  }
  m_5ad210(st, name + 2);
}
PCREG(5ae860, setLevel);

// 0x56b930 (map: CPlayerProfile::SetFileName, low; it is a save-slot table method taking (CPlayerProfile*, slot)):
// the profile is loaded from the slot's 0x400-byte buffer at this+0x2100, its save name from this+slot*0x80, and
// profile+0x86 from the dword at this+0x2000+slot*4.
static void THISCALL slotToProfile(u8 *self, u8 *prof, s32 slot) {
  ext_5ae450(prof, self + 0x2100 + (slot << 10));
  setSaveName(prof, (const char *)(self + (slot << 7)));
  *(u32 *)(prof + 0x86) = *(u32 *)(self + 0x2000 + slot * 4);
}
PCREG(56b930, slotToProfile);
