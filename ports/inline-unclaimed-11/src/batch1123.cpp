// batch1123.cpp - unclaimed-11 batch 24 (gap band): 0x5a4590, CMPGameController::GetHeroStat(int) (low name).
#include "ff.h"

// 0x5a4590: for idx in 1..4 (idx - 1 as unsigned <= 3), returns this + 0x99 + 16*idx; otherwise 0.
static u8 *THISCALL cmpGetHeroStat(u8 *self, s32 idx) {
  if ((u32)(idx - 1) <= 3u) return self + 0x99 + (idx << 4);
  return nullptr;
}
PCREG(5a4590, cmpGetHeroStat);
