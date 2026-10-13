// batch1401.cpp - missions thread, batch 1401: setting mission variables, their save data, the player profile and
// unique-bit (collectible) wrappers, and the small ZFFLevelController leaves.
//
// ZFFLevelController layout used here (PC, 1-byte packed, offsets from the code):
//   +0x048 char level[4..]  "C01A"; +0x4b is the sub-zone letter A..D
//   +0x051 char nextScene[] SetNextScene copies here
//   +0x057 CPlayerProfile   (its CSaveMissions at +0x4b8, i.e. controller +0x50f; its CPlayerStats at +0x35a,
//                           i.e. controller +0x3b1)
//   +0x41b s32 default charisma, +0x41f s32 (second SetDefaultCharisma value), +0x423 u32 prisoner bits left
//   +0x463 s32 uniqueIdCounter[type]
//   +0x1042 u8 demo / end-screen flag (PushEndScene)
#include "missions.h"

// ---------------------------------------------------------------- CBuffer (save-game byte buffer)
// CBuffer is declared in missions.h.

// 0x5f01c0 CBuffer::Add(unsigned int): four bytes, little end first; false and the error flag when full.
extern "C" u8 THISCALL m_5f01c0(CBuffer *b, u32 v) {
  if (b->pos + 4 > b->cap) {
    b->err = 1;
    return 0;
  }
  b->data[b->pos] = (u8)v;
  b->pos++;
  b->data[b->pos] = (u8)(v >> 8);
  b->pos++;
  b->data[b->pos] = (u8)(v >> 16);
  b->pos++;
  b->data[b->pos] = (u8)(v >> 24);
  b->pos++;
  return 1;
}
PCREG(5f01c0, m_5f01c0);

// 0x5f0280 CBuffer::Get(unsigned int*) (no GameCube name; the read twin of Add(unsigned int)).
extern "C" u8 THISCALL m_5f0280(CBuffer *b, u8 *out) {
  if (b->pos + 4 > b->cap) {
    b->err = 1;
    return 0;
  }
  out[0] = b->data[b->pos];
  b->pos++;
  out[1] = b->data[b->pos];
  b->pos++;
  out[2] = b->data[b->pos];
  b->pos++;
  out[3] = b->data[b->pos];
  b->pos++;
  return 1;
}
PCREG(5f0280, m_5f0280);

// 0x5f02f0 CBuffer::Get(char*).
extern "C" u8 THISCALL m_5f02f0(CBuffer *b, s8 *out) {
  if (b->pos + 1 > b->cap) {
    b->err = 1;
    return 0;
  }
  *out = (s8)b->data[b->pos];
  b->pos++;
  return 1;
}
PCREG(5f02f0, m_5f02f0);

// ---------------------------------------------------------------- CSaveMissions, continued
// 0x5b1150 CSaveMissions::SetLevelVar(const char*, int). The GameCube name map says AddResentMission(int), but the
// code takes two arguments and logs "CSaveMissions::SetLevelVar could not find variable"; AddResentMission is
// inlined in it: a primary or secondary variable whose value changes is queued in the 8 "resent" (recent) slots
// at +0x598 (first slot holding -1 gets its index; "not enough room for resent missions" when all are used).
extern "C" void THISCALL m_5b1150(CSaveMissions *s, const char *name, s32 v) {
  int i;
  for (i = 0; i < s->count; i++)
    if (same((const u8 *)name, (const u8 *)s->name[i]))
      break;
  if (i >= s->count) {
    LOGF(SAVEMISSIONS_CPP, 0xf4, (const char *)0x6b13c0, name);
    return;
  }
  if (s->value[i] == v)
    return;
  s->value[i] = v;
  if (s->type[i] == 3 || s->type[i] == 4)
    return;
  for (int k = 0; k < 8; k++)
    if (s->unk598[k] == -1) {
      s->unk598[k] = i;
      return;
    }
  LOGF(SAVEMISSIONS_CPP, 0x51, (const char *)0x6b1238, s->name[i]);
}
PCREG(5b1150, m_5b1150);

// 0x5b1070 CSaveMissions::PutDataIntoBuffer(CBuffer&): save version 2 (also stored at +4), then the low byte of
// each of the 116 values and of the 8 recent slots. True when the buffer did not overflow.
static u8 THISCALL putData(CSaveMissions *s, CBuffer *b) {
  s->f4 = 2;
  m_5f01c0(b, 2);
  for (int i = 0; i < 116; i++)
    ext_5f0190(b, (s8)s->value[i]);
  for (int i = 0; i < 8; i++)
    ext_5f0190(b, (s8)s->unk598[i]);
  return b->err == 0;
}
PCREG(5b1070, putData);

// 0x5b1330 CSaveMissions::TakeDataOutOfBuffer(CBuffer&): version (into +4) 1 = 116 signed bytes then 8 dwords,
// 2 = 116 + 8 signed bytes; anything else is logged as unsupported. A failed byte read leaves the previous byte
// (the original's temporary is the top byte of the CBuffer* argument slot, so that is its first value).
static u8 THISCALL takeData(CSaveMissions *s, CBuffer *b) {
  m_5f0280(b, (u8 *)&s->f4);
  s8 t = (s8)((u32)b >> 24);
  if (s->f4 == 1) {
    for (int i = 0; i < 116; i++) {
      m_5f02f0(b, &t);
      s->value[i] = t;
    }
    for (int i = 0; i < 8; i++)
      m_5f0280(b, (u8 *)&s->unk598[i]);
  } else if (s->f4 == 2) {
    for (int i = 0; i < 116; i++) {
      m_5f02f0(b, &t);
      s->value[i] = t;
    }
    for (int i = 0; i < 8; i++) {
      m_5f02f0(b, &t);
      s->unk598[i] = t;
    }
  } else {
    LOGF(SAVEMISSIONS_CPP, 0x1a3, (const char *)0x6b1460);
  }
  return b->err == 0;
}
PCREG(5b1330, takeData);

// ---------------------------------------------------------------- CPlayerProfile thunks (CSaveMissions at +0x4b8)
struct SubZoneStatus;
extern "C" void THISCALL m_5b0f20(CSaveMissions *s, SubZoneStatus *o, const char *level);   // batch 1400
extern "C" s32 THISCALL m_5b0b70(CSaveMissions *s, const char *name);              // batch 1400

// 0x5adeb0 CPlayerProfile::GetLevelVar(const char*).
extern "C" s32 THISCALL m_5adeb0(u8 *prof, const char *name) { return m_5b0b70((CSaveMissions *)(prof + 0x4b8), name); }
PCREG(5adeb0, m_5adeb0);

// 0x5adee0 CPlayerProfile::GetSubZoneMissionInfo(sSubZoneMissionStatus&, const char*).
static void THISCALL profSubZone(u8 *prof, void *o, const char *level) { m_5b0f20((CSaveMissions *)(prof + 0x4b8), (SubZoneStatus *)o, level); }
PCREG(5adee0, profSubZone);

// 0x5ae930 CPlayerProfile::SetLevelVar(char*, int). Named ZFFLevelController::SetLevelVar in the name map, but it
// sits among the CPlayerProfile functions and ZFFLevelController calls it with this = controller + 0x57.
extern "C" void THISCALL m_5ae930(u8 *prof, const char *name, s32 v) { m_5b1150((CSaveMissions *)(prof + 0x4b8), name, v); }
PCREG(5ae930, m_5ae930);

// ---------------------------------------------------------------- CPlayerStats unique bits
// bits[type * 5 + subZone] at +0x76 (u32 each), bit count per type at +0xb2.
static inline u32 *ubits(u8 *st, u32 type, u32 sz) { return (u32 *)(st + 0x76) + (sz + type * 5); }

// 0x5ad640 CPlayerStats::UniqueBitAllBitsTrue(EBitIDType, ESubZone) (no GameCube name; from the caller).
extern "C" u8 THISCALL m_5ad640(u8 *st, u32 type, u32 sz) {
  u32 n = *(u32 *)(st + 0xb2 + type * 4);
  for (u32 i = 0; i < n; i++)
    if (!(*ubits(st, type, sz) & (1u << (i & 31))))
      return 0;
  return 1;
}
PCREG(5ad640, m_5ad640);

// 0x5ad690 CPlayerStats::UniqueBitGetIDState(unsigned int bit, EBitIDType, ESubZone).
extern "C" u8 THISCALL m_5ad690(u8 *st, u32 bit, u32 type, u32 sz) {
  return (*ubits(st, type, sz) & (1u << (bit & 31))) != 0;
}
PCREG(5ad690, m_5ad690);

// 0x5ad740 CPlayerStats::UniqueBitSetIDState(unsigned int bit, EBitIDType, bool, ESubZone).
extern "C" void THISCALL m_5ad740(u8 *st, u32 bit, u32 type, u32 on, u32 sz) {
  u32 *w = ubits(st, type, sz);
  if ((u8)on)
    *w |= 1u << (bit & 31);
  else
    *w &= ~(1u << (bit & 31));
}
PCREG(5ad740, m_5ad740);

// ---------------------------------------------------------------- ZFFLevelController leaves
// 0x59b6d0 ZFFLevelController::GetSubZone(): level letter A..D -> 0..3, anything else 4.
extern "C" u32 THISCALL m_59b6d0(u8 *lc) {
  u32 k = (u32)((s32)(s8)lc[0x4b] - 0x41);
  return k <= 3 ? k : 4;
}
PCREG(59b6d0, m_59b6d0);

// 0x59b310 ZFFLevelController::GetLevelVar(const char*): the profile at +0x57.
static s32 THISCALL lcGetLevelVar(u8 *lc, const char *name) { return m_5adeb0(lc + 0x57, name); }
PCREG(59b310, lcGetLevelVar);

// 0x59cb60 ZFFLevelController::SetNextScene(const char*): strcpy to +0x51 (length first, then the bytes).
static void THISCALL setNextScene(u8 *lc, const char *s) {
  s32 n = 0;
  while (s[n]) n++;
  for (s32 i = 0; i < n; i++) lc[0x51 + i] = s[i];
  lc[0x51 + n] = 0;
}
PCREG(59cb60, setNextScene);

// 0x59d130 ZFFLevelController::UniqueBitGetID(EBitIDType): next id of that type (post-increment counter).
static u32 THISCALL ubGetID(u8 *lc, u32 type) {
  u32 *p = (u32 *)(lc + 0x463 + type * 4);
  return (*p)++;
}
PCREG(59d130, ubGetID);

// 0x59d150 ZFFLevelController::UniqueBitGetIDState(EBitIDType, unsigned int): the stats bit for this sub-zone.
static u8 THISCALL ubGetState(u8 *lc, u32 type, u32 bit) { return m_5ad690(lc + 0x3b1, bit, type, m_59b6d0(lc)); }
PCREG(59d150, ubGetState);

// 0x59d090 ZFFLevelController::UniqueBitAllBitsTrue(EBitIDType).
extern "C" u8 THISCALL m_59d090(u8 *lc, u32 type) { return m_5ad640(lc + 0x3b1, type, m_59b6d0(lc)); }
PCREG(59d090, m_59d090);

// 0x59d250 ZFFLevelController::UniqueBitSetIDState(EBitIDType, unsigned int, bool). Type 1 is the prisoners: setting
// one clears its bit in +0x423, and once all of them are set "<level>_PrisonersFreed" (template "XXXX_PrisonersFreed"
// at 0x6add78, 20 bytes, the level's 4 characters over XXXX) is set to 1 in the profile.
static void THISCALL ubSetState(u8 *lc, u32 type, u32 bit, u32 on) {
  m_5ad740(lc + 0x3b1, bit, type, on, m_59b6d0(lc));
  if (type != 1 || !(u8)on)
    return;
  *(u32 *)(lc + 0x423) &= ~(1u << (bit & 31));
  if (!m_59d090(lc, 1))
    return;
  char name[20];
  for (int i = 0; i < 20; i++) name[i] = ((const char *)0x6add78)[i];
  name[0] = lc[0x48];
  name[1] = lc[0x49];
  name[2] = lc[0x4a];
  name[3] = lc[0x4b];
  m_5ae930(lc + 0x57, name, 1);
}
PCREG(59d250, ubSetState);

// 0x59ca50 ZFFLevelController::SetDefaultCharisma(const char *level): by the level digit (level[2]):
// '1' 75/0, '2' 25/1, '3' 0/3, '4' 0/4, '5' 0/6, '6' and '7' 0/7, '8' 0/12, '9' 0/8, else 0/0, into +0x41b/+0x41f.
static void THISCALL setDefaultCharisma(u8 *lc, const char *level) {
  s32 a = 0, b = 0;
  switch (level[2]) {
    case '1': a = 0x4b; b = 0; break;
    case '2': a = 0x19; b = 1; break;
    case '3': b = 3; break;
    case '4': b = 4; break;
    case '5': b = 6; break;
    case '6': case '7': b = 7; break;
    case '8': b = 0xc; break;
    case '9': b = 8; break;
  }
  *(s32 *)(lc + 0x41b) = a;
  *(s32 *)(lc + 0x41f) = b;
}
PCREG(59ca50, setDefaultCharisma);

// 0x59b350 ZFFLevelController::GetSewerId(ZGEOM*): the last two characters of the geom's template name read as a
// decimal number ("...07" -> 7); no geom gives -2. Name: geom slot 0x20 -> object, its slot 0x20 -> template, name
// at template+4 or "<NONAME>".
extern "C" s32 THISCALL m_59b350(u8 *lc, u8 *geom) {
  (void)lc;
  if (!geom)
    return -2;
  u8 *o = vcall<u8 *>(geom, 0x20);
  u8 *t = vcall<u8 *>(o, 0x20);
  const char *nm = *(const char **)(t + 4);
  if (!nm)
    nm = (const char *)0x67c8e8u;
  s32 n = 0;
  while (nm[n]) n++;
  const char *e = nm + n;
  return (s32)(s8)e[-2] * 10 + (s32)(s8)e[-1] - 0x210;
}
PCREG(59b350, m_59b350);

// 0x59be70 ZFFLevelController::LevelComplete(): C01A never counts as complete, C00A always does, otherwise the
// profile's CSaveMissions::LevelCompleted for the level name.
static u8 THISCALL levelComplete(u8 *lc) {
  const u8 *nm = lc + 0x48;
  if (same(nm, (const u8 *)0x6a7808u))   // "C01A"
    return 0;
  if (same(nm, (const u8 *)0x6adcc8u))   // "C00A"
    return 1;
  return m_5b1000((CSaveMissions *)(lc + 0x50f), (const char *)nm);
}
PCREG(59be70, levelComplete);

// 0x59c420 ZFFLevelController::PushEndScene(): with +0x1042 set, the scene manager ([sys+0x9b]) slot 0xa8;
// otherwise sys slot 0xc(0, 0, 0, 0), manager slot 0xa4, then manager slot 0xa0("DemoEndScreen").
static void THISCALL pushEndScene(u8 *lc) {
  u8 *sys = G(u8 *, 0x70039c);
  if (lc[0x1042]) {
    vcall<void>(*(u8 **)(sys + 0x9b), 0xa8);
    return;
  }
  vcall<void, u32, u32, u32, u32>(sys, 0xc, 0, 0, 0, 0);
  vcall<void>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0xa4);
  vcall<void, const char *>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0xa0, (const char *)0x6ade2c);
}
PCREG(59c420, pushEndScene);

// ---------------------------------------------------------------- flags and flak
// 0x5c1650 CEnemyFlag::FlagPole() const: handle at +0x115 resolved by the manager's slot 0x58, else the pointer at
// +0x44.
static u32 THISCALL flagPole(u8 *f) {
  u32 h = *(u32 *)(f + 0x115);
  if (h)
    return vcall<u32, u32>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x58, h);
  return *(u32 *)(f + 0x44);
}
PCREG(5c1650, flagPole);

// 0x5dc7a0 ZFFFlak::CheckMissionVar(const char*): finds the "LevelController" object (manager slot 0x138 -> registry,
// registry slot 0x88(name, &handle), manager slot 0x58(handle)) and sends it the command "GETMISSIONVAR" (id from
// manager slot 0x114(name, 0, file, line)) through its slot 0x128(id, &block, 0), block = {result, varName}.
// No controller: logs "Flak is unconditionally on" and returns false; an empty name returns false.
static u8 THISCALL flakCheck(u8 *self, const char *var) {
  (void)self;
  u8 *mgr = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *reg = vcall<u8 *>(mgr, 0x138);
  u32 h = 0;
  vcall<u32, const char *, u32 *>(reg, 0x88, (const char *)0x6a5c48, &h);
  u8 *lc = vcall<u8 *, u32>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x58, h);
  if (!lc) {
    LOGF(0x6b6c28u, 0x3e, (const char *)0x6b6c58);
    return 0;
  }
  if (!var[0])
    return 0;
  struct {
    s32 result;
    const char *name;
  } blk;
  blk.name = var;
  u16 id = vcall<u16, const char *, u32, const char *, u32>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x114,
                                                             (const char *)0x6a5c68, 0, (const char *)0x6b6c28, 0x4b);
  vcall<void, u32, void *, u32>(lc, 0x128, (u32)id, &blk, 0);
  return blk.result != 0;
}
PCREG(5dc7a0, flakCheck);
