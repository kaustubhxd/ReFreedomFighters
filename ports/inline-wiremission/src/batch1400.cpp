// batch1400.cpp - missions thread, batch 1400: CSaveMissions, the campaign's mission-variable table.
//
// Layout (from the code below; size 0x960, PC build, 4-byte fields):
//   +0x000 vtable 0x6b11ec          +0x004 u32 (0 in the constructor)
//   +0x008 const char *name[116]    variable names, "C01A_..." style: the first 4 characters are the level,
//                                   the first 3 the zone (ZoneCompleted)
//   +0x1d8 const char *text[116]    third AddVar argument (objective text key)
//   +0x3a8 u32 [8]                  not touched here
//   +0x3c8 s32 value[116]           0 = not done / false
//   +0x598 s32 [8]                  set to -1 by the constructor
//   +0x5b8 s32 count
//   +0x5c0 s32 type[116]            EMissionType: 0 primary objective, 3 additional, 4 (skipped by
//                                   GetSubZoneMissionInfo), others secondary
//   +0x790 s32 icon[116]            ESubZoneMapIcon
#include "missions.h"

// 0x5b0990 CSaveMissions::CSaveMissions(), thiscall, returns this.
static CSaveMissions *THISCALL ctor(CSaveMissions *s) {
  s->f4 = 0;
  s->vtbl = (void *)0x6b11ecu;
  s->count = 0;
  for (int i = 0; i < 8; i++) s->unk598[i] = -1;
  return s;
}
PCREG(5b0990, ctor);

// 0x5b0a60 CSaveMissions::AddVar(EMissionType, const char*, const char*, ESubZoneMapIcon), thiscall.
// Appends a variable with value 0; when the table is full (116) it logs "not enough room" and drops it.
static void THISCALL addVar(CSaveMissions *s, s32 type, const char *name, const char *text, s32 icon) {
  if (s->count >= 0x74) {
    LOGF(SAVEMISSIONS_CPP, 0x72, (const char *)0x6b1340, name);
    return;
  }
  s->name[s->count] = name;
  s->value[s->count] = 0;
  s->type[s->count] = type;
  s->icon[s->count] = icon;
  s->text[s->count] = text;
  s->count++;
}
PCREG(5b0a60, addVar);

// 0x5b0a20 CSaveMissions::AddMission(...): AddVar, except type 3 (additional) which must use AddAdditional (logged).
static void THISCALL addMission(CSaveMissions *s, s32 type, const char *name, const char *text, s32 icon) {
  if (type == 3) {
    LOGF(SAVEMISSIONS_CPP, 0x5c, (const char *)0x6b12d8, name);
    return;
  }
  addVar(s, type, name, text, icon);
}
PCREG(5b0a20, addMission);

// 0x5b0a00 CSaveMissions::AddAdditional(const char*, ESubZoneMapIcon): AddVar(3, name, 0, icon).
static void THISCALL addAdditional(CSaveMissions *s, const char *name, s32 icon) {
  addVar(s, 3, name, 0, icon);
}
PCREG(5b0a00, addAdditional);

// 0x5b0b70 CSaveMissions::GetLevelVar(const char*): value of the first variable with that exact name, else 0.
extern "C" s32 THISCALL m_5b0b70(CSaveMissions *s, const char *name) {
  for (int i = 0; i < s->count; i++)
    if (same((const u8 *)name, (const u8 *)s->name[i]))
      return s->value[i];
  return 0;
}
PCREG(5b0b70, m_5b0b70);

// 0x5b0bf0 CSaveMissions::GetNumPrimaryObjectives(const char *level): primaries whose name starts with level[0..3].
static s32 THISCALL numPrimary(CSaveMissions *s, const char *level) {
  s32 n = 0;
  for (int i = 0; i < s->count; i++)
    if (s->type[i] == 0 && prefix(level, s->name[i], 4))
      n++;
  return n;
}
PCREG(5b0bf0, numPrimary);

// 0x5b0c50 CSaveMissions::GetNumPrimaryObjectivesCompleted(const char *level): the same, value != 0.
static s32 THISCALL numPrimaryDone(CSaveMissions *s, const char *level) {
  s32 n = 0;
  for (int i = 0; i < s->count; i++)
    if (s->type[i] == 0 && prefix(level, s->name[i], 4) && s->value[i] != 0)
      n++;
  return n;
}
PCREG(5b0c50, numPrimaryDone);

// 0x5b1000 CSaveMissions::LevelCompleted(const char *level): every primary of the level (4-char prefix) is non-zero.
extern "C" bool THISCALL m_5b1000(CSaveMissions *s, const char *level) {
  for (int i = 0; i < s->count; i++)
    if (s->type[i] == 0 && prefix(level, s->name[i], 4) && s->value[i] == 0)
      return false;
  return true;
}
PCREG(5b1000, m_5b1000);

// 0x5b1440 CSaveMissions::ZoneCompleted(const char *zone): the same with a 3-char prefix ("C01").
static bool THISCALL zoneCompleted(CSaveMissions *s, const char *zone) {
  for (int i = 0; i < s->count; i++)
    if (s->type[i] == 0 && prefix(zone, s->name[i], 3) && s->value[i] == 0)
      return false;
  return true;
}
PCREG(5b1440, zoneCompleted);

// 0x5b0af0 CSaveMissions::CompleteSecondaryTargets(const char *level): once the level's primaries are all done,
// every other non-additional variable of the level (types other than 3, primaries included) is set to 1.
static void THISCALL completeSecondary(CSaveMissions *s, const char *level) {
  if (!m_5b1000(s, level))
    return;
  for (int i = 0; i < s->count; i++)
    if (prefix(level, s->name[i], 4) && s->type[i] != 3)
      s->value[i] = 1;
}
PCREG(5b0af0, completeSecondary);

// sSubZoneMissionStatus (0x108 bytes): name[16], value[16], icon[16], type[16], count at +0x100, levelDone at +0x104.
struct SubZoneStatus {
  const char *name[16];
  s32 value[16];
  s32 icon[16];
  s32 type[16];
  s32 count;
  u8 done;
};

// 0x5b0f20 CSaveMissions::GetSubZoneMissionInfo(sSubZoneMissionStatus&, const char *level): copies every variable
// of the level except type 4 (no bound check on the 16 entries), then LevelCompleted into +0x104.
extern "C" void THISCALL m_5b0f20(CSaveMissions *s, SubZoneStatus *o, const char *level) {
  o->count = 0;
  for (int i = 0; i < s->count; i++) {
    if (!prefix(level, s->name[i], 4) || s->type[i] == 4)
      continue;
    o->name[o->count] = s->name[i];
    o->value[o->count] = s->value[i];
    o->icon[o->count] = s->icon[i];
    o->type[o->count] = s->type[i];
    o->count++;
  }
  o->done = m_5b1000(s, level);
}
PCREG(5b0f20, m_5b0f20);

// 0x5b12d0 CSaveMissions::SetVarsFromMainIni(): for each variable the engine (slot 0x5c of [0x70039c]) finds an
// ini value string for, value = atoi(string) (CRT import at 0x6762d8).
typedef bool(THISCALL *iniGet)(void *self, const char *key, const char **out);
typedef s32 (*crtAtoi)(const char *);
extern "C" void THISCALL m_5b12d0(CSaveMissions *s) {
  for (int i = 0; i < s->count; i++) {
    void *sys = G(void *, 0x70039c);
    const char *v;
    if (((iniGet)(*(void ***)sys)[0x5c / 4])(sys, s->name[i], &v))
      s->value[i] = (*(crtAtoi *)0x6762d8)(v);
  }
}
PCREG(5b12d0, m_5b12d0);
