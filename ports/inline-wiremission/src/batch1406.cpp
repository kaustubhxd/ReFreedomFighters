// batch1406.cpp - missions thread, batch 1406: end-of-level charisma and prisoner counts, rebel-base startup.
#include "missions.h"

extern "C" u8 THISCALL m_59d090(u8 *lc, u32 type);   // ZFFLevelController::UniqueBitAllBitsTrue (batch 1401)
extern "C" u32 THISCALL m_59b6d0(u8 *lc);            // ZFFLevelController::GetSubZone (batch 1401)
struct SubZoneStatus {
  const char *name[16];
  s32 value[16];
  s32 icon[16];
  s32 type[16];
  s32 count;
  u8 done;
};
extern "C" void THISCALL m_5b0f20(CSaveMissions *s, SubZoneStatus *o, const char *level);   // batch 1400
extern "C" s32 THISCALL ext_5acfb0(u8 *st);   // CPlayerStats::GetNoOfPrisonersFollowingHero (batch 1402)
extern "C" u8 THISCALL ext_59be70(u8 *lc);    // ZFFLevelController::LevelComplete (batch 1401)
extern "C" void THISCALL ext_596940(u8 *osd, u32 kind, float *amount, u32 flag, s32 n);   // ZGameOSD::CharismaAddExperience
extern "C" void THISCALL ext_485060(u8 *player, u32 massBits);                           // ZPlayer::SetMass(float)

// 0x589c20 ZFFGameData::GetGameOSD(char player): the on-screen display of that player (+0x2c2d table).
extern "C" u8 *THISCALL m_589c20(u8 *gd, s8 player) { return *(u8 **)(gd + 0x2c2d + (s32)player * 4); }
PCREG(589c20, m_589c20);

// 0x5ad6c0 CPlayerStats::UniqueBitCountTrue(EBitIDType, ESubZone) (no GameCube name): how many of the type's
// first count bits are set in the sub-zone's word (bit index taken mod 32, like the original's rotating mask).
extern "C" s32 THISCALL m_5ad6c0(u8 *st, u32 type, u32 sz) {
  u32 n = *(u32 *)(st + 0xb2 + type * 4);
  if (!n)
    return 0;
  u32 w = *((u32 *)(st + 0x76) + (sz + type * 5));
  s32 c = 0;
  for (u32 i = 0; i < n; i++)
    if (w & (1u << (i & 31))) c++;
  return c;
}
PCREG(5ad6c0, m_5ad6c0);

// 0x59d1b0 ZFFLevelController::UniqueBitCountTrue(EBitIDType) (no GameCube name): for the current sub-zone.
extern "C" s32 THISCALL m_59d1b0(u8 *lc, u32 type) { return m_5ad6c0(lc + 0x3b1, type, m_59b6d0(lc)); }
PCREG(59d1b0, m_59d1b0);

// 0x59b710 ZFFLevelController::GiveRemainingCharisma(). Level complete: player 0's OSD gets charisma experience 3
// for every secondary objective (type 1) of the level still at 0, and experience 1 if every prisoner was freed.
// Not complete: +0x41a = (prisoner total +0x467 is non-zero and equals the prisoners following the hero plus those
// freed).
static void THISCALL giveRemainingCharisma(u8 *lc) {
  if (ext_59be70(lc)) {
    s32 n = 0;
    m_59d1b0(lc, 1);
    u8 allFreed = m_59d090(lc, 1);
    m_59d1b0(lc, 0);
    SubZoneStatus st;
    m_5b0f20((CSaveMissions *)(lc + 0x50f), &st, (const char *)(lc + 0x48));
    for (s32 i = 0; i < st.count; i++)
      if (st.type[i] == 1 && st.value[i] == 0)
        n++;
    u8 *osd = m_589c20(G(u8 *, 0x7003b8), 0);
    if (!osd)
      return;
    float amount;   // uninitialised in the original; CharismaAddExperience writes it
    for (; n; n--)
      ext_596940(osd, 3, &amount, 0, -1);
    if (allFreed)
      ext_596940(osd, 1, &amount, 0, -1);
    return;
  }
  u32 total = *(u32 *)(lc + 0x467);
  u8 r = 0;
  if (total) {
    s32 following = ext_5acfb0(lc + 0x3b1);
    if (total == (u32)(following + m_59d1b0(lc, 1)))
      r = 1;
  }
  lc[0x41a] = r;
}
PCREG(59b710, giveRemainingCharisma);

// 0x59ce00 ZFFLevelController::StartupRebelBase(): the object named "HitmanGround" (the hero) gets mass 0.01.
static void THISCALL startupRebelBase(u8 *lc) {
  (void)lc;
  u8 *mgr = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *reg = vcall<u8 *>(mgr, 0x138);
  u32 h = 0;
  vcall<u32, const char *, u32 *>(reg, 0x88, (const char *)0x681320, &h);
  u8 *p = vcall<u8 *, u32>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x58, h);
  if (p)
    ext_485060(p, 0x3c23d70au);   // 0.01f
}
PCREG(59ce00, startupRebelBase);
