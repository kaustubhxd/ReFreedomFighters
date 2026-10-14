// batch1519.cpp - recruits thread, batch 1519: ZFFLevelController::LevelComplete, the bit-group count and all-bits
// helpers for the current level's group (UniqueBitAllBitsTrue, its count twin), and GiveRemainingCharisma.
#include "ff.h"

extern "C" u8 THISCALL ext_5b1000(u8 *missions, const char *name);            // CSaveMissions::LevelCompleted
extern "C" void THISCALL ext_5b0f20(u8 *missions, u8 *out, const char *name);  // CSaveMissions::GetSubZoneMissionInfo
extern "C" u8 THISCALL ext_5ad640(u8 *group, u32 k, u32 m);                    // AllBitsInGroup (batch 1517, GUESS)
extern "C" u32 THISCALL ext_5ad6c0(u8 *group, u32 k, u32 m);                   // CountBitsInGroup (batch 1517, GUESS)
extern "C" u32 THISCALL ext_5acfb0(u8 *stats);                                  // CPlayerStats::GetNoOfPrisonersFollowingHero
extern "C" u8 *THISCALL ext_589c20(u8 *game, u32 player);                      // ZFFGameData::GetGameOSD
extern "C" void THISCALL ext_596940(u8 *osd, u32 kind, float *pos, u32 show, s32 amount);  // CharismaAddExperience

static inline void *gameData() { return G(void *, 0x7003b8); }

// Same-string test as the original's byte loop (equal up to and including the NUL).
static bool sameString(const char *a, const char *b) {
  for (;; ++a, ++b) {
    if (*a != *b)
      return false;
    if (*a == 0)
      return true;
  }
}

// Group index of the current level: the character at +0x4b (signed) minus 'A'; 0..3 are the four groups, anything
// else uses group 4.
static u32 levelGroup(const u8 *self) {
  u32 g = (u32)((s32)(s8)self[0x4b] - 0x41);
  return g <= 3 ? g : 4;
}

// 0x59be70 ZFFLevelController::LevelComplete() const, thiscall, plain ret, AL. The level name at +0x48 is compared to
// "C01A" (equal -> 0) and then to "C00A" (equal -> 1); otherwise the result is CSaveMissions::LevelCompleted of the
// save record at +0x50f with that name.
static u8 THISCALL levelComplete(u8 *self) {
  const char *name = (const char *)(self + 0x48);
  if (sameString(name, "C01A"))
    return 0;
  if (sameString(name, "C00A"))
    return 1;
  return ext_5b1000(self + 0x50f, name);
}
PCREG(59be70, levelComplete);

// 0x59d1b0 (GUESS: CountGroupBits(bit)), thiscall, ret 4, returns the count of set bits of the current group's bit
// `bit` (the group object at +0x3b1). The count is not used by the caller under test except in GiveRemainingCharisma.
static u32 THISCALL levelGroupCount(u8 *self, u32 bit) {
  return ext_5ad6c0(self + 0x3b1, bit, levelGroup(self));
}
PCREG(59d1b0, levelGroupCount);

// 0x59d090 ZFFLevelController::UniqueBitAllBitsTrue(EBitIDType bit), thiscall, ret 4, AL. True when every bit of the
// current group's `bit` (bits of the group object at +0x3b1) is set. Group chosen by levelGroup().
static u8 THISCALL levelAllBitsTrue(u8 *self, u32 bit) {
  return ext_5ad640(self + 0x3b1, bit, levelGroup(self));
}
PCREG(59d090, levelAllBitsTrue);

extern "C" u8 THISCALL ext_59be70(u8 *self);
extern "C" u32 THISCALL ext_59d1b0(u8 *self, u32 bit);
extern "C" u8 THISCALL ext_59d090(u8 *self, u32 bit);

// 0x59b710 ZFFLevelController::GiveRemainingCharisma(), thiscall, plain ret.
//  - Level completed (LevelComplete): bl = AllBitsTrue(1). The save record's sub-zone info is collected (out struct,
//    names at +0x48, save record at +0x50f). s = number of collected entries with state 1 and flag 0. Then the
//    player-0 OSD gets s charisma awards of kind 3, and one of kind 1 when bl is set (show = 0, amount = default).
//    Nothing when player 0 has no OSD.
//  - Not completed: if +0x467 is 0, the flag +0x41a is 0; otherwise +0x41a = (+0x467 == prisoners following the
//    hero + CountGroupBits(1)).
// The first count call in the original has its result discarded and has no side effects, so it is not ported.
static void THISCALL giveRemainingCharisma(u8 *self) {
  if (ext_59be70(self)) {
    u8 bl = ext_59d090(self, 1);
    u8 out[0x110];
    ext_5b0f20(self + 0x50f, out, (const char *)(self + 0x48));
    u32 count = *(u32 *)(out + 0x100);
    u32 s = 0;
    for (u32 i = 0; i < count; ++i)
      if (*(u32 *)(out + 0xc0 + 4 * i) == 1 && *(u32 *)(out + 0x40 + 4 * i) == 0)
        ++s;
    u8 *osd = ext_589c20((u8 *)gameData(), 0);
    if (osd) {
      float pos[3];
      while (s != 0) {
        ext_596940(osd, 3, pos, 0, -1);
        --s;
      }
      if (bl)
        ext_596940(osd, 1, pos, 0, -1);
    }
    return;
  }
  u32 flag = *(u32 *)(self + 0x467);
  if (flag == 0) {
    self[0x41a] = 0;
    return;
  }
  u32 n = ext_5acfb0(self + 0x3b1);
  n += ext_59d1b0(self, 1);
  self[0x41a] = (flag == n) ? 1 : 0;
}
PCREG(59b710, giveRemainingCharisma);
